/**************************************************************************
 * basf2 (Belle II Analysis Software Framework)                           *
 * Author: The Belle II Collaboration                                     *
 *                                                                        *
 * See git log for contributors and copyright holders.                    *
 * This file is licensed under LGPL-3.0, see LICENSE.md.                  *
 **************************************************************************/

#pragma once

#include <framework/core/Module.h>
#include <tracking/trackFindingCDC/gnntracking/gnntracking.h>
#include <framework/gearbox/Unit.h>
#include <framework/datastore/StoreArray.h>
#include <boost/algorithm/string.hpp>
#include <string>

namespace Belle2 {
  namespace TrackFindingCDC {
  /** The ParticleGun module.
   * Generate tracks with the particle gun and store them
   * into the MCParticle class.
   */
  class gnntrackingModule : public Module {
  public:
    /**
     * Constructor.
     * Sets the module parameters.
     */
    gnntrackingModule();

    /** Initializes the module. */
    void initialize() override;

    /** Method is called for each event. */
    void event() override;

    private:
    gnntracking m_gnntracking;

  };
 }

} // end namespace Belle2



