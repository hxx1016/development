/**************************************************************************
 * basf2 (Belle II Analysis Software Framework)                           *
 * Author: The Belle II Collaboration                                     *
 *                                                                        *
 * See git log for contributors and copyright holders.                    *
 * This file is licensed under LGPL-3.0, see LICENSE.md.                  *
 **************************************************************************/
#pragma once
#include <framework/datastore/StoreArray.h>
#include <framework/datastore/RelationsObject.h>
#include <framework/core/FrameworkExceptions.h>
#include <framework/geometry/VectorUtil.h>
#include <genfit/Track.h>

#include <genfit/AbsTrackRep.h>
#include <genfit/RKTrackRep.h>
#include <genfit/AbsMeasurement.h>
#include <genfit/MeasuredStateOnPlane.h>
#include <genfit/TrackPoint.h>
#include <genfit/Exception.h>
#include <genfit/FieldManager.h>
#include <genfit/TGeoMaterialInterface.h>
#include <genfit/MaterialEffects.h>
#include <genfit/KalmanFitter.h>
#include <genfit/KalmanFitterRefTrack.h>
#include <genfit/StateOnPlane.h>
#include <genfit/DAF.h>
#include <genfit/AbsKalmanFitter.h>
#include <genfit/KalmanFitterInfo.h>
#include <tracking/dataobjects/RecoHitInformation.h>
#include <optional>
#include <cdc/geometry/CDCGeometryPar.h>
#include <tracking/trackFindingCDC/testFixtures/TrackFindingCDCTestWithTopology.h>

#include <tracking/trackFindingCDC/topology/CDCWireTopology.h>
#include <tracking/trackFindingCDC/topology/CDCGeometryLoader.h>

#include <Math/Vector3D.h>
#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream> 
#include <string>
#include <cdc/dataobjects/CDCHit.h>
#include <cdc/dataobjects/WireID.h>
#include <tracking/trackFindingCDC/eventdata/hits/CDCWireHit.h>
#include <tracking/trackFitting/fitter/base/TrackFitter.h>
#include <tracking/ckf/cdc/findlets/CDCCKFResultStorer.h>
#include <tracking/ckf/general/utilities/SearchDirection.h>
#include <tracking/trackFindingCDC/utilities/StringManipulation.h>
#include <framework/core/ModuleParamList.h>

#include <framework/geometry/VectorUtil.h>

#include <framework/utilities/TestHelpers.h>
#include <framework/gearbox/Const.h>
#include <genfit/WireTrackCandHit.h>

#include <tracking/trackFitting/measurementCreator/adder/MeasurementAdder.h>
#include <tracking/modules/genfitUtilities/SetupGenfitExtrapolationModule.h>
#include <tracking/gfbfield/GFGeant4Field.h>
#include <tracking/modules/genfitUtilities/Geant4MaterialInterface.h>
#include <geometry/GeometryManager.h>

#include <genfit/FieldManager.h>
#include <genfit/MaterialEffects.h>
#include <genfit/TGeoMaterialInterface.h>
#include <genfit/IO.h>

#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/concepts.hpp>

#include <TGeoManager.h>
#include <tracking/v0Finding/fitter/V0Fitter.h>

#include <framework/gearbox/Const.h>

#include <genfit/ConstField.h>

#include <utility>

#include <gtest/gtest.h>



#include <genfit/ConstField.h>
#include <genfit/Exception.h>
#include <genfit/FieldManager.h>
#include <genfit/KalmanFitterRefTrack.h>
#include <genfit/StateOnPlane.h>
#include <genfit/Track.h>
#include <genfit/TrackPoint.h>
#include <genfit/MaterialEffects.h>
#include <genfit/RKTrackRep.h>
#include <genfit/TGeoMaterialInterface.h>
#include <genfit/EventDisplay.h>
#include <genfit/HelixTrackModel.h>
#include <genfit/MeasurementCreator.h>
#include <TDatabasePDG.h>
#include <TEveManager.h>
#include <TGeoManager.h>
#include <TRandom.h>
#include <TVector3.h>
#include <vector>
#include "TDatabasePDG.h"
#include <TMath.h>




#include <genfit/PlanarMeasurement.h>



using namespace std;
namespace Belle2 {
  namespace TrackFindingCDC {
    class gnntracking {
    public:
        gnntracking(){ 
      }
        void readAndPrintTXT(int par);
    
    
        //MeasurementAdder m_measurementAdder;
      };
  }
}
