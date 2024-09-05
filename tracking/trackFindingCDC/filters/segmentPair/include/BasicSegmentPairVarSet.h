/**************************************************************************
 * basf2 (Belle II Analysis Software Framework)                           *
 * Author: The Belle II Collaboration                                     *
 *                                                                        *
 * See git log for contributors and copyright holders.                    *
 * This file is licensed under LGPL-3.0, see LICENSE.md.                  *
 **************************************************************************/
#pragma once

#include <tracking/trackFindingCDC/varsets/VarSet.h>
#include <tracking/trackFindingCDC/varsets/VarNames.h>

namespace Belle2 {
  namespace TrackFindingCDC {
    class CDCSegmentPair;

    /// Names of the variables to be generated
    constexpr
    static char const* const basicSegmentPairVarNames[] = {
      "axial_first",
      "axial_size",
      "stereo_size",
      "sl_id_pair",
    };

    /// Vehicle class to transport the variable names
    struct BasicSegmentPairVarNames : public VarNames<CDCSegmentPair> {

      /// Number of variables to be generated
      // we shouldn't use public member variables but we do want to rewrite all related code using setters/getters
      // at least tell cppcheck that everything is fine
      // cppcheck-suppress duplInheritedMember
      static const size_t nVars = size(basicSegmentPairVarNames);

      /// Getter for the name at the given index
      static constexpr char const* getName(int iName)
      {
        return basicSegmentPairVarNames[iName];
      }
    };

    /**
     *  Class to compute floating point variables from an axial stereo segment pair
     *  which can be recorded as a flat TNtuple or serve as input to a MVA method
     */
    class BasicSegmentPairVarSet : public VarSet<BasicSegmentPairVarNames> {

    public:
      /// Generate and assign the contained variables
      bool extract(const CDCSegmentPair* ptrSegmentPair) final;
    };
  }
}
