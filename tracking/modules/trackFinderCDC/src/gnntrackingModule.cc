/**************************************************************************
 * basf2 (Belle II Analysis Software Framework)                           *
 * Author: The Belle II Collaboration                                     *
 *                                                                        *
 * See git log for contributors and copyright holders.                    *
 * This file is licensed under LGPL-3.0, see LICENSE.md.                  *
 **************************************************************************/

#include <tracking/modules/trackFinderCDC/gnntrackingModule.h>

using namespace std;
using namespace Belle2;
using namespace TrackFindingCDC;
//Register the Module
REG_MODULE(gnntracking);
//Implementation
gnntrackingModule::gnntrackingModule() : Module() {
}
void gnntrackingModule::initialize() {
        Module::initialize();
  }
 
void gnntrackingModule::event() {
        Module::event();
        int par =1; //0:  ;1:   ;
	m_gnntracking.readAndPrintTXT(par);
  }
