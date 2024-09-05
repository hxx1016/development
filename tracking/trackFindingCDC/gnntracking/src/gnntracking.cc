#include <tracking/trackFindingCDC/gnntracking/gnntracking.h>
#include <tracking/dataobjects/RecoTrack.h>
#include <memory>

using namespace Belle2;
using namespace TrackFindingCDC;
using namespace ROOT::Math;
void gnntracking::readAndPrintTXT(int par) {
    if (par==0){

    /// Refer to https://github.com/belle2/basf2/blob/main/tracking/tests/recoTrack.cc
    const std::string m_storeArrayNameOfRecoTracks = "recoTracksFromGNN";
    const std::string m_storeArrayNameOfPXDHits = "PXDsILike";
    const std::string m_storeArrayNameOfSVDHits = "WhatAboutSVD";
    const std::string m_storeArrayNameOfCDCHits = "CDCHitsAreCool";
    const std::string m_storeArrayNameOfBKLMHits = "KeepBKLMsAlive";
    const std::string m_storeArrayNameOfEKLMHits = "EKLMsAreImportant";
    const std::string m_storeArrayNameOfHitInformation = "ConnectingAll";


    DataStore::Instance().setInitializeActive(true);
    StoreArray<PXDCluster> pxdHits(m_storeArrayNameOfPXDHits);
    pxdHits.registerInDataStore();
    StoreArray<SVDCluster> svdHits(m_storeArrayNameOfSVDHits);
    svdHits.registerInDataStore();
    StoreArray<CDCHit> cdcHits(m_storeArrayNameOfCDCHits);
    cdcHits.registerInDataStore();
    StoreArray<RecoTrack> recoTracks(m_storeArrayNameOfRecoTracks);
    recoTracks.registerInDataStore();
    StoreArray<RecoHitInformation> recoHitInformations(m_storeArrayNameOfHitInformation);
    recoHitInformations.registerInDataStore();

    pxdHits.registerRelationTo(recoTracks);
    svdHits.registerRelationTo(recoTracks);
    cdcHits.registerRelationTo(recoTracks);
    recoHitInformations.registerRelationTo(pxdHits);
    recoHitInformations.registerRelationTo(svdHits);
    recoHitInformations.registerRelationTo(cdcHits);
    recoTracks.registerRelationTo(recoHitInformations);

    ROOT::Math::XYZVector seedPos(0, 1, 2);
    ROOT::Math::XYZVector seedMom(-1, -0.5, 1.123);
    int charge = 1;
    int pdg = 13;

    // "CDCHit(tdcCount, adcCount, superLayer, layer, wire)"
    cdcHits.appendNew(100, 100, 0, 0, 0);
    cdcHits.appendNew(100, 100, 1, 1, 0);
    cdcHits.appendNew(100, 100, 2, 0, 0);
    cdcHits.appendNew(100, 100, 3, 0, 0);
    cdcHits.appendNew(100, 100, 4, 0, 0);
    cdcHits.appendNew(100, 100, 5, 0, 0);
    cdcHits.appendNew(100, 100, 6, 0, 0);
    cdcHits.appendNew(100, 100, 8, 0, 0);
  
    RecoTrack *newRecoTrack = nullptr;
    newRecoTrack = recoTracks.appendNew(seedPos,seedMom, charge,m_storeArrayNameOfPXDHits, m_storeArrayNameOfSVDHits, 
                  m_storeArrayNameOfCDCHits,m_storeArrayNameOfBKLMHits, m_storeArrayNameOfEKLMHits, m_storeArrayNameOfHitInformation);

    newRecoTrack->addCDCHit(cdcHits[0], 0);
    newRecoTrack->addCDCHit(cdcHits[1], 1);
    newRecoTrack->addCDCHit(cdcHits[2], 2);
    newRecoTrack->addCDCHit(cdcHits[3], 3);
    newRecoTrack->addCDCHit(cdcHits[4], 4);
    newRecoTrack->addCDCHit(cdcHits[5], 5);
    newRecoTrack->addCDCHit(cdcHits[6], 6);
    newRecoTrack->addCDCHit(cdcHits[7], 7);


    /// check
    std::cout << " recoTracks isValid = " << recoTracks.isValid() << std::endl;
    std::cout << " recoTracks Entries = " << recoTracks.getEntries() << std::endl;
    std::cout << " newTrack hasCDCHits= " << recoTracks[0]->hasCDCHits() << " getNumberOfCDCHits = " << recoTracks[0]->getNumberOfCDCHits() << " getNumberOfTotalHits = " << recoTracks[0]->getNumberOfTotalHits() << std::endl; 
    std::cout << " newTrack hasCDCHits= " << newRecoTrack->hasCDCHits() << " getNumberOfCDCHits = " << newRecoTrack->getNumberOfCDCHits() << " getNumberOfTotalHits = " << newRecoTrack->getNumberOfTotalHits() << std::endl; 
    /// output is " recoTracks isValid = 1"
    /// output is " recoTracks Entries = 1"
    /// output is " newTrack hasCDCHits= 1 getNumberOfCDCHits = 8 getNumberOfTotalHits = 8 "
    /// output is " newTrack hasCDCHits= 1 getNumberOfCDCHits = 8 getNumberOfTotalHits = 8 "
    if (newRecoTrack) {
        std::cout << "RecoTrack successful!" << std::endl; // output is "RecoTrack successful!"
        std::cout << "seedpos: (" << seedPos.X() << ", " << seedPos.Y() << ", " << seedPos.Z() << ")" << std::endl;
        std::cout << "seedmom: (" << seedMom.X() << ", " << seedMom.Y() << ", " << seedMom.Z() << ")" << std::endl;
        std::cout << "charge: " << charge << std::endl;
	      std::cout << " newTrack Position(" << newRecoTrack->getPositionSeed().X() << ", " << newRecoTrack->getPositionSeed().Y() << ", " << newRecoTrack->getPositionSeed().Z() << ") , Mom(" << newRecoTrack->getMomentumSeed().X() << ", " << newRecoTrack->getMomentumSeed().Y() << ", " << newRecoTrack->getMomentumSeed().Z() << ") " << std::endl;
        std::cout << " newTrack hasCDCHits= " << recoTracks[0]->hasCDCHits() << " getNumberOfCDCHits = " << recoTracks[0]->getNumberOfCDCHits() << " getNumberOfTotalHits = " << recoTracks[0]->getNumberOfTotalHits() << std::endl; 
        /// output is " seedpos: (0, 1, 2) "
        /// output is " seedmom: (-1, -0.5, 1.123) "
        /// output is " charge: 1 "
        /// output is " newTrack Position(0, 1, 2) , Mom(-1, -0.5, 1.123) "
        /// output is " newTrack hasCDCHits= 1 getNumberOfCDCHits = 8 getNumberOfTotalHits = 8 "

        } else {
        std::cerr << "RecoTrack false!" << std::endl;
        return;
    }

    genfit::AbsTrackRep* trackRepresentation = nullptr;
    trackRepresentation = RecoTrackGenfitAccess::createOrReturnRKTrackRep(*newRecoTrack,pdg);

    /// check
    if (trackRepresentation) {
        std::cout << "RecoRep successful!" << std::endl; // output is "RecoRep successful!"
    } else {
        std::cerr << "RecoRep false!" << std::endl;
        return;
    }  
    
    /// Refer to https://github.com/belle2/basf2/blob/main/tracking/trackFitting/fitter/base/include/TrackFitter.h
    TrackFitter trackFitter(m_storeArrayNameOfPXDHits,m_storeArrayNameOfSVDHits,
            m_storeArrayNameOfCDCHits,m_storeArrayNameOfBKLMHits, m_storeArrayNameOfEKLMHits,true);

    /// Three different ways to build refer to tracking/trackFitting/fitter/base/src/TrackFitter.h
    /// All three methods produce the same error

    // bool fitSuccessful = trackFitter.fit(*newRecoTrack,trackRepresentation, true);
    // bool fitSuccessful = trackFitter.fit(*newRecoTrack,pdg, true);
    bool fitSuccessful = trackFitter.fit(*newRecoTrack,true);

    /// check
    if (fitSuccessful) {
        std::cout << "Track fitting successful!" << std::endl;
    } else {
        std::cout << "Track fitting failed!" << std::endl;}   // output is "Track fitting failed!"
    }

///##################################################################################################################################///	    
	    
    else if (par == 1) {
      /// read data
    std::string fixedfilePath = "/sdufs/home/huxx/gitLab/basf2/development/tracking/trackFindingCDC/gnntracking/example/genfit6.txt";
    std::ifstream file(fixedfilePath);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << fixedfilePath << std::endl;
        return;
    } else {
        std::cout << "打开文件成功！文件名是 " << fixedfilePath << std::endl;
    }
    /// txt file description
    /// In one case, a single track passes through the gnn to remove the noise, leaving hits information
    /// ####################################################################
    /// First line ：
    /// seedPos.X , seedPos.Y , seedPos.Z , seedMom.X , seedMom.Y , seedMom.Z
    /// Next line ：
    /// tdcCount, adcCount, iSuperLayer, iLayer, iWire, driftLength, driftLengthVariance, chargeDeposit, driftTime
    /// Especially , adcCount, driftLength, driftLengthVariance, chargeDeposit, driftTime, these messages start with 0
    /// ####################################################################
    std::string line;
    std::vector<Belle2::TrackFindingCDC::CDCWireHit> bestElement2;
    XYZVector seedPos(0.0, 0.0, 0.0);
    XYZVector seedMom(0.0, 0.0, 0.0);
    int charge = 1;
    int pdg = 13;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string item;
        std::vector<double> data;
        while (std::getline(ss, item, ',')) {
            data.push_back(std::stod(item));
        }
        if (data.size() == 9) {
            int tdcCount = data[0];
            int adcCount = data[1];
            int iSuperLayer = data[2];
            int iLayer = data[3];
            int iWire = data[4];
            int driftLength = data[5];
            int driftLengthVariance = data[6];
            int chargeDeposit = data[7];
            int driftTime = data[8];
            Belle2::CDCHit* cdchit = new Belle2::CDCHit(tdcCount, adcCount, iSuperLayer, iLayer, iWire);
            Belle2::TrackFindingCDC::CDCWireHit cdcWireHit(cdchit, driftLength, driftLengthVariance, chargeDeposit, driftTime);
            bestElement2.push_back(cdcWireHit);
        } else if (data.size() == 6) {
            seedPos.SetXYZ(data[0], data[1], data[2]);
            seedMom.SetXYZ(data[3], data[4], data[5]);
        } else {
            std::cout << "数据格式错误: " << line << std::endl;
        }
    }
    file.close();
    std::cout << "总共添加的CDCWireHits数目: " << bestElement2.size() << std::endl;

    Belle2::RecoTrack *newRecoTrack = new Belle2::RecoTrack(seedPos, seedMom, charge, "", "", "bestElement2", "", "", "");
    if (newRecoTrack) {
        std::cout << "RecoTrack创建成功！" << std::endl;
        std::cout << "种子位置: (" << seedPos.X() << ", " << seedPos.Y() << ", " << seedPos.Z() << ")" << std::endl;
        std::cout << "种子动量: (" << seedMom.X() << ", " << seedMom.Y() << ", " << seedMom.Z() << ")" << std::endl;
        std::cout << "电荷: " << charge << std::endl;
    } else {
        std::cerr << "RecoTrack创建失败！" << std::endl;
        return;
    }
    
    Belle2::RecoTrackGenfitAccess *recoTrackGenfitAccess = new Belle2::RecoTrackGenfitAccess();    
    genfit::AbsTrackRep* RecoRep = recoTrackGenfitAccess->createOrReturnRKTrackRep(*newRecoTrack,pdg);
    if (RecoRep) {
        std::cout << "RecoRep 创建成功！" << std::endl;
    } else {
        std::cerr << "RecoRep 创建失败！" << std::endl;
        return;
    }   

    TVector3 seedPos1(seedPos.X(), seedPos.Y(), seedPos.Z());
    TVector3 seedMom1(seedMom.X(), seedMom.Y(), seedMom.Z());

    genfit::MeasuredStateOnPlane state(RecoRep);
    if (!RecoRep) {
    std::cerr << "Error: RecoRep creation failed!" << std::endl;
    return;
    } else {
    std::cout << "RecoRep creation successful." << std::endl;
    }

    RecoRep->setPosMom(state, seedPos1, seedMom1);

    genfit::Track* genfitTrackPtr =nullptr;
    if (recoTrackGenfitAccess) {
          std::cout << "recoTrackGenfitAccess exist" << std::endl;
          genfit::Track& genfitTrack = recoTrackGenfitAccess->getGenfitTrack(*newRecoTrack);
          genfitTrackPtr  = &genfitTrack;
        } else {
          std::cout << "recoTrackGenfitAccess not exist" << std::endl;
        }
    if (genfitTrackPtr != nullptr) {
        std::cout << "genfitTrackPtr exist" << std::endl;
    } else {
        std::cout << "genfitTrackPtr not exist" << std::endl;
      }
    genfit::AbsKalmanFitter* fitter = new genfit::KalmanFitterRefTrack();   
    fitter->processTrackWithRep(genfitTrackPtr, RecoRep, false);
  }
}


