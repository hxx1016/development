/**************************************************************************
 * basf2 (Belle II Analysis Software Framework)                           *
 * Author: The Belle II Collaboration                                     *
 *                                                                        *
 * See git log for contributors and copyright holders.                    *
 * This file is licensed under LGPL-3.0, see LICENSE.md.                  *
 **************************************************************************/
#include <tracking/trackFitting/fitter/base/TrackFitter.h>

#include <tracking/dataobjects/RecoTrack.h>

#include <genfit/AbsTrackRep.h>
#include <genfit/FitStatus.h>
#include <genfit/AbsFitter.h>
#include <genfit/DAF.h>
#include <genfit/KalmanFitterInfo.h>

using namespace Belle2;

constexpr double TrackFitter::s_defaultDeltaPValue;
constexpr double TrackFitter::s_defaultProbCut;
constexpr unsigned int TrackFitter::s_defaultMaxFailedHits;

int TrackFitter::createCorrectPDGCodeForChargedStable(const Const::ChargedStable& particleType, const RecoTrack& recoTrack)
{
  int currentPdgCode = particleType.getPDGCode();

  const auto& pdgParticleCharge = particleType.getParticlePDG()->Charge();
  const auto& recoTrackCharge = recoTrack.getChargeSeed();

  // Copy from GenfitterModule
  B2ASSERT("Charge of candidate and PDG particle don't match.  (Code assumes |q| = 1).",
           fabs(pdgParticleCharge) == fabs(recoTrackCharge * 3.0));

  /*
  * Because the charged stable particles do describe a positive as well as a negative particle,
  * we have to correct the charge if needed.
  */
  if (std::signbit(pdgParticleCharge) != std::signbit(recoTrackCharge))
    currentPdgCode *= -1;

  return currentPdgCode;
}

bool TrackFitter::fit(RecoTrack& recoTrack, bool resortHits) const
{
  //std::cout<<recoTrack.getRepresentations().empty()<<std::endl;
  if (not recoTrack.getRepresentations().empty() and recoTrack.getCardinalRepresentation()) {
    return fit(recoTrack, recoTrack.getCardinalRepresentation(), resortHits);
  } else {
    return fit(recoTrack, Const::pion, resortHits);
  }
}

bool TrackFitter::fit(RecoTrack& recoTrack, const Const::ChargedStable& particleType, bool resortHits) const
{
  const int currentPdgCode = TrackFitter::createCorrectPDGCodeForChargedStable(particleType, recoTrack);
  genfit::AbsTrackRep* trackRepresentation = RecoTrackGenfitAccess::createOrReturnRKTrackRep(recoTrack,
                                             currentPdgCode);

  return fit(recoTrack, trackRepresentation, resortHits);
}

bool TrackFitter::fit(RecoTrack& recoTrack, const int pdgCode, bool resortHits) const
{
  genfit::AbsTrackRep* trackRepresentation = RecoTrackGenfitAccess::createOrReturnRKTrackRep(recoTrack,
                                             pdgCode);

  return fit(recoTrack, trackRepresentation, resortHits);
}

bool TrackFitter::fitWithoutCheck(RecoTrack& recoTrack, const genfit::AbsTrackRep& trackRepresentation, bool resortHits) const
{
  // Fit the track
  try {
    // Delete the old information to start from scratch
    recoTrack.deleteFittedInformationForRepresentation(&trackRepresentation);
    B2DEBUG(28, "resortHits is set to " << resortHits << " when fitting the tracks");
    m_fitter->processTrackWithRep(&RecoTrackGenfitAccess::getGenfitTrack(recoTrack), &trackRepresentation, resortHits);
  } catch (genfit::Exception& e) {
    B2WARNING(e.getExcString());
  }

  recoTrack.setDirtyFlag(false);

  // Do the hits synchronisation
  const std::vector<RecoHitInformation*>& relatedRecoHitInformation = recoTrack.getRecoHitInformations();

  for (RecoHitInformation* recoHitInformation : relatedRecoHitInformation) {
    const genfit::TrackPoint* trackPoint = recoTrack.getCreatedTrackPoint(recoHitInformation);
    if (trackPoint) {
      genfit::KalmanFitterInfo* kalmanFitterInfo = trackPoint->getKalmanFitterInfo(&trackRepresentation);
      if (not kalmanFitterInfo) {
        recoHitInformation->setFlag(RecoHitInformation::RecoHitFlag::c_dismissedByFit);
      } else {
        std::vector<double> weights = kalmanFitterInfo->getWeights();
        for (const double weight : weights) {
          if (weight < 1.e-9) {
            recoHitInformation->setFlag(RecoHitInformation::RecoHitFlag::c_dismissedByFit);
          }
        }
      }
    }
  }

  return recoTrack.wasFitSuccessful(&trackRepresentation);
}

bool TrackFitter::fit(RecoTrack& recoTrack, genfit::AbsTrackRep* trackRepresentation, bool resortHits) const
{
 
  //std::cout << " recoTracks isValid = " << recoTrack.isValid() << std::endl;
  //std::cout << " recoTracks Entries = " << recoTrack.getEntries() << std::endl;
  std::cout << " recoTracks Entries = " << recoTrack.getNumberOfTotalHits() << std::endl;
  B2ASSERT("No fitter was loaded! Have you reset the fitter to an invalid one?", m_fitter);

  const bool measurementAdderNeedsTrackRefit = m_measurementAdder.addMeasurements(recoTrack);
  std::cout<<"getNumPoints"<<RecoTrackGenfitAccess::getGenfitTrack(recoTrack).getNumPoints()<<std::endl;
  if (RecoTrackGenfitAccess::getGenfitTrack(recoTrack).getNumPoints() == 0) {
    B2WARNING("No track points (measurements) were added to this reco track. Have you used an invalid measurement adder?");
    return false;
  }

  const std::vector<genfit::AbsTrackRep*>& trackRepresentations = recoTrack.getRepresentations();
  if (std::find(trackRepresentations.begin(), trackRepresentations.end(), trackRepresentation) == trackRepresentations.end()) {
    B2FATAL("The TrackRepresentation provided is not part of the Reco Track.");
  }
  std::cout<<__func__<<"\t"<<__LINE__<<std::endl;
  if (not recoTrack.getDirtyFlag() and not m_skipDirtyCheck and not measurementAdderNeedsTrackRefit
      and recoTrack.hasTrackFitStatus(trackRepresentation) and recoTrack.getTrackFitStatus(trackRepresentation)->isFitted()) {
  std::cout<<__func__<<"\t"<<__LINE__<<std::endl;
    B2DEBUG(100, "Hit content did not change, track representation is already present and you used only default parameters." <<
            "I will not fit the track again. If you still want to do so, set the dirty flag of the track.");
    return recoTrack.wasFitSuccessful(trackRepresentation);
  }

  std::cout<<__func__<<"\t"<<__LINE__<<std::endl;
  const auto previousSetting = gErrorIgnoreLevel; // Save current log level
  std::cout<<__func__<<"\t"<<__LINE__<<std::endl;
  gErrorIgnoreLevel = m_gErrorIgnoreLevel; // Set the log level defined in the TrackFitter
  auto fitWithoutCheckResult = fitWithoutCheck(recoTrack, *trackRepresentation, resortHits);
  std::cout<<__func__<<"\t"<<__LINE__<<std::endl;
  gErrorIgnoreLevel = previousSetting; // Restore previous setting
  std::cout<<__func__<<"\t"<<__LINE__<<std::endl;
  return fitWithoutCheckResult;
}

void TrackFitter::resetFitterToDefaultSettings()
{
  if (!m_DAFparameters.isValid())
    B2FATAL("DAF parameters are not available.");
  genfit::DAF* dafFitter = new genfit::DAF(m_DAFparameters->getAnnealingScheme(),
                                           m_DAFparameters->getMinimumIterations(),
                                           m_DAFparameters->getMaximumIterations(),
                                           m_DAFparameters->getMinimumIterationsForPVal(),
                                           true,
                                           m_DAFparameters->getDeltaPValue(),
                                           m_DAFparameters->getDeltaWeight(),
                                           m_DAFparameters->getProbabilityCut());
  dafFitter->setMaxFailedHits(m_DAFparameters->getMaximumFailedHits());
  m_fitter.reset(dafFitter);
  m_skipDirtyCheck = false;
}

void TrackFitter::resetFitter(const std::shared_ptr<genfit::AbsFitter>& fitter)
{
  m_fitter = fitter;
  m_skipDirtyCheck = true;
}
