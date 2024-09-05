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

#include <tracking/trackFindingCDC/utilities/Relation.h>

namespace Belle2 {
  namespace TrackFindingCDC {
    class CDCFacet;

    /// Names of the variables to be generated
    constexpr
    static char const* const bendFacetRelationVarNames[] = {
      "delta_phi",
      "delta_phi_pull",
      "delta_phi_pull_per_r",
      "delta_curv",
      "delta_curv_pull",
      "delta_curv_pull_per_r",
    };

    /// Vehicle class to transport the variable names
    struct BendFacetRelationVarNames : public VarNames<Relation<const CDCFacet>> {

      /// Number of variables to be generated
      // we shouldn't use public member variables but we do want to rewrite all related code using setters/getters
      // at least tell cppcheck that everything is fine
      // cppcheck-suppress duplInheritedMember
      static const size_t nVars = size(bendFacetRelationVarNames);

      /// Getter for the name at the given index
      static constexpr char const* getName(int iName)
      {
        return bendFacetRelationVarNames[iName];
      }
    };

    /**
     *  Class to compute floating point variables from a facet relation
     *  which can be recorded as a flat TNtuple or serve as input to a MVA method
     */
    class BendFacetRelationVarSet : public VarSet<BendFacetRelationVarNames> {

    public:
      /// Generate and assign the contained variables
      bool extract(const Relation<const CDCFacet>* ptrFacetRelation) final;
    };
  }
}
