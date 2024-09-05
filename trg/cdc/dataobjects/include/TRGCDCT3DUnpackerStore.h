/**************************************************************************
 * basf2 (Belle II Analysis Software Framework)                           *
 * Author: The Belle II Collaboration                                     *
 *                                                                        *
 * See git log for contributors and copyright holders.                    *
 * This file is licensed under LGPL-3.0, see LICENSE.md.                  *
 **************************************************************************/
//-----------------------------------------------------------
// $Id$
//-----------------------------------------------------------
// Filename : TRGCDCT3DUnpackerStore.h
// Section  :
// Owner    :
// Email    :
//-----------------------------------------------------------
// Description : A dataobject for TRGCDCT3DUnpacker.
//-----------------------------------------------------------
// $Log$
//-----------------------------------------------------------
#ifndef TRGCDCT3DUNPACKERSTORE_H
#define TRGCDCT3DUNPACKERSTORE_H

#include <TObject.h>

namespace Belle2 {

  //! Example Detector
  class TRGCDCT3DUnpackerStore : public TObject {
  public:

    /**m_t3d_2doldtrk leaf*/
    int m_t3d_2doldtrk;
    /**m_t3dtrk0_evtTime_delay leaf*/
    int m_t3dtrk0_evtTime_delay;
    /**m_t3dtrk0_evtTimeValid_delay leaf*/
    int m_t3dtrk0_evtTimeValid_delay;
    /**m_t3dtrk0_charge leaf*/
    int m_t3dtrk0_charge;
    /**m_t3dtrk0_rho leaf*/
    int m_t3dtrk0_rho;
    /**m_t3dtrk0_phi0 leaf*/
    int m_t3dtrk0_phi0;
    /**m_t3dtrk0ts0_id leaf*/
    int m_t3dtrk0ts0_id;
    /**m_t3dtrk0ts0_lr leaf*/
    int m_t3dtrk0ts0_lr;
    /**m_t3dtrk0ts0_rt leaf*/
    int m_t3dtrk0ts0_rt;
    /**m_t3dtrk0ts1_id leaf*/
    int m_t3dtrk0ts1_id;
    /**m_t3dtrk0ts1_lr leaf*/
    int m_t3dtrk0ts1_lr;
    /**m_t3dtrk0ts1_rt leaf*/
    int m_t3dtrk0ts1_rt;
    /**m_t3dtrk0ts2_id leaf*/
    int m_t3dtrk0ts2_id;
    /**m_t3dtrk0ts2_lr leaf*/
    int m_t3dtrk0ts2_lr;
    /**m_t3dtrk0ts2_rt leaf*/
    int m_t3dtrk0ts2_rt;
    /**m_t3dtrk0ts3_id leaf*/
    int m_t3dtrk0ts3_id;
    /**m_t3dtrk0ts3_lr leaf*/
    int m_t3dtrk0ts3_lr;
    /**m_t3dtrk0ts3_rt leaf*/
    int m_t3dtrk0ts3_rt;
    /**m_t3dtrk1_evtTime_delay leaf*/
    int m_t3dtrk1_evtTime_delay;
    /**m_t3dtrk1_evtTimeValid_delay leaf*/
    int m_t3dtrk1_evtTimeValid_delay;
    /**m_t3dtrk1_charge leaf*/
    int m_t3dtrk1_charge;
    /**m_t3dtrk1_rho leaf*/
    int m_t3dtrk1_rho;
    /**m_t3dtrk1_phi0 leaf*/
    int m_t3dtrk1_phi0;
    /**m_t3dtrk1ts0_id leaf*/
    int m_t3dtrk1ts0_id;
    /**m_t3dtrk1ts0_lr leaf*/
    int m_t3dtrk1ts0_lr;
    /**m_t3dtrk1ts0_rt leaf*/
    int m_t3dtrk1ts0_rt;
    /**m_t3dtrk1ts1_id leaf*/
    int m_t3dtrk1ts1_id;
    /**m_t3dtrk1ts1_lr leaf*/
    int m_t3dtrk1ts1_lr;
    /**m_t3dtrk1ts1_rt leaf*/
    int m_t3dtrk1ts1_rt;
    /**m_t3dtrk1ts2_id leaf*/
    int m_t3dtrk1ts2_id;
    /**m_t3dtrk1ts2_lr leaf*/
    int m_t3dtrk1ts2_lr;
    /**m_t3dtrk1ts2_rt leaf*/
    int m_t3dtrk1ts2_rt;
    /**m_t3dtrk1ts3_id leaf*/
    int m_t3dtrk1ts3_id;
    /**m_t3dtrk1ts3_lr leaf*/
    int m_t3dtrk1ts3_lr;
    /**m_t3dtrk1ts3_rt leaf*/
    int m_t3dtrk1ts3_rt;
    /**m_t3d_phase leaf*/
    int m_t3d_phase;
    /**m_t3d_validTS leaf*/
    int m_t3d_validTS;
    /**m_t3d_2dfnf leaf*/
    int m_t3d_2dfnf;
    /**m_t3dtrk0_z0_s leaf*/
    int m_t3dtrk0_z0_s;
    /**m_t3dtrk0_cot_s leaf*/
    int m_t3dtrk0_cot_s;
    /**m_t3dtrk0_zchisq leaf*/
    int m_t3dtrk0_zchisq;
    /**m_t3dtrk1_z0_s leaf*/
    int m_t3dtrk1_z0_s;
    /**m_t3dtrk1_cot_s leaf*/
    int m_t3dtrk1_cot_s;
    /**m_t3dtrk1_zchisq leaf*/
    int m_t3dtrk1_zchisq;
    /**m_t3dtrk2_z0_s leaf*/
    int m_t3dtrk2_z0_s;
    /**m_t3dtrk2_cot_s leaf*/
    int m_t3dtrk2_cot_s;
    /**m_t3dtrk2_zchisq leaf*/
    int m_t3dtrk2_zchisq;
    /**m_t3dtrk3_z0_s leaf*/
    int m_t3dtrk3_z0_s;
    /**m_t3dtrk3_cot_s leaf*/
    int m_t3dtrk3_cot_s;
    /**m_t3dtrk3_zchisq leaf*/
    int m_t3dtrk3_zchisq;
    /**m_t3dtrk_rd_req leaf*/
    int m_t3dtrk_rd_req;
    /**m_tsf1_cc leaf*/
    int m_tsf1_cc;
    /**m_tsf1ts0_id leaf*/
    int m_tsf1ts0_id;
    /**m_tsf1ts0_rt leaf*/
    int m_tsf1ts0_rt;
    /**m_tsf1ts0_lr leaf*/
    int m_tsf1ts0_lr;
    /**m_tsf1ts0_pr leaf*/
    int m_tsf1ts0_pr;
    /**m_tsf1ts1_id leaf*/
    int m_tsf1ts1_id;
    /**m_tsf1ts1_rt leaf*/
    int m_tsf1ts1_rt;
    /**m_tsf1ts1_lr leaf*/
    int m_tsf1ts1_lr;
    /**m_tsf1ts1_pr leaf*/
    int m_tsf1ts1_pr;
    /**m_tsf1ts2_id leaf*/
    int m_tsf1ts2_id;
    /**m_tsf1ts2_rt leaf*/
    int m_tsf1ts2_rt;
    /**m_tsf1ts2_lr leaf*/
    int m_tsf1ts2_lr;
    /**m_tsf1ts2_pr leaf*/
    int m_tsf1ts2_pr;
    /**m_tsf1ts3_id leaf*/
    int m_tsf1ts3_id;
    /**m_tsf1ts3_rt leaf*/
    int m_tsf1ts3_rt;
    /**m_tsf1ts3_lr leaf*/
    int m_tsf1ts3_lr;
    /**m_tsf1ts3_pr leaf*/
    int m_tsf1ts3_pr;
    /**m_tsf1ts4_id leaf*/
    int m_tsf1ts4_id;
    /**m_tsf1ts4_rt leaf*/
    int m_tsf1ts4_rt;
    /**m_tsf1ts4_lr leaf*/
    int m_tsf1ts4_lr;
    /**m_tsf1ts4_pr leaf*/
    int m_tsf1ts4_pr;
    /**m_tsf1ts5_id leaf*/
    int m_tsf1ts5_id;
    /**m_tsf1ts5_rt leaf*/
    int m_tsf1ts5_rt;
    /**m_tsf1ts5_lr leaf*/
    int m_tsf1ts5_lr;
    /**m_tsf1ts5_pr leaf*/
    int m_tsf1ts5_pr;
    /**m_tsf1ts6_id leaf*/
    int m_tsf1ts6_id;
    /**m_tsf1ts6_rt leaf*/
    int m_tsf1ts6_rt;
    /**m_tsf1ts6_lr leaf*/
    int m_tsf1ts6_lr;
    /**m_tsf1ts6_pr leaf*/
    int m_tsf1ts6_pr;
    /**m_tsf1ts7_id leaf*/
    int m_tsf1ts7_id;
    /**m_tsf1ts7_rt leaf*/
    int m_tsf1ts7_rt;
    /**m_tsf1ts7_lr leaf*/
    int m_tsf1ts7_lr;
    /**m_tsf1ts7_pr leaf*/
    int m_tsf1ts7_pr;
    /**m_tsf1ts8_id leaf*/
    int m_tsf1ts8_id;
    /**m_tsf1ts8_rt leaf*/
    int m_tsf1ts8_rt;
    /**m_tsf1ts8_lr leaf*/
    int m_tsf1ts8_lr;
    /**m_tsf1ts8_pr leaf*/
    int m_tsf1ts8_pr;
    /**m_tsf1ts9_id leaf*/
    int m_tsf1ts9_id;
    /**m_tsf1ts9_rt leaf*/
    int m_tsf1ts9_rt;
    /**m_tsf1ts9_lr leaf*/
    int m_tsf1ts9_lr;
    /**m_tsf1ts9_pr leaf*/
    int m_tsf1ts9_pr;
    /**m_tsf1ts10_id leaf*/
    int m_tsf1ts10_id;
    /**m_tsf1ts10_rt leaf*/
    int m_tsf1ts10_rt;
    /**m_tsf1ts10_lr leaf*/
    int m_tsf1ts10_lr;
    /**m_tsf1ts10_pr leaf*/
    int m_tsf1ts10_pr;
    /**m_tsf1ts11_id leaf*/
    int m_tsf1ts11_id;
    /**m_tsf1ts11_rt leaf*/
    int m_tsf1ts11_rt;
    /**m_tsf1ts11_lr leaf*/
    int m_tsf1ts11_lr;
    /**m_tsf1ts11_pr leaf*/
    int m_tsf1ts11_pr;
    /**m_tsf1ts12_id leaf*/
    int m_tsf1ts12_id;
    /**m_tsf1ts12_rt leaf*/
    int m_tsf1ts12_rt;
    /**m_tsf1ts12_lr leaf*/
    int m_tsf1ts12_lr;
    /**m_tsf1ts12_pr leaf*/
    int m_tsf1ts12_pr;
    /**m_tsf1ts13_id leaf*/
    int m_tsf1ts13_id;
    /**m_tsf1ts13_rt leaf*/
    int m_tsf1ts13_rt;
    /**m_tsf1ts13_lr leaf*/
    int m_tsf1ts13_lr;
    /**m_tsf1ts13_pr leaf*/
    int m_tsf1ts13_pr;
    /**m_tsf1ts14_id leaf*/
    int m_tsf1ts14_id;
    /**m_tsf1ts14_rt leaf*/
    int m_tsf1ts14_rt;
    /**m_tsf1ts14_lr leaf*/
    int m_tsf1ts14_lr;
    /**m_tsf1ts14_pr leaf*/
    int m_tsf1ts14_pr;
    /**m_tsf3_cc leaf*/
    int m_tsf3_cc;
    /**m_tsf3ts0_id leaf*/
    int m_tsf3ts0_id;
    /**m_tsf3ts0_rt leaf*/
    int m_tsf3ts0_rt;
    /**m_tsf3ts0_lr leaf*/
    int m_tsf3ts0_lr;
    /**m_tsf3ts0_pr leaf*/
    int m_tsf3ts0_pr;
    /**m_tsf3ts1_id leaf*/
    int m_tsf3ts1_id;
    /**m_tsf3ts1_rt leaf*/
    int m_tsf3ts1_rt;
    /**m_tsf3ts1_lr leaf*/
    int m_tsf3ts1_lr;
    /**m_tsf3ts1_pr leaf*/
    int m_tsf3ts1_pr;
    /**m_tsf3ts2_id leaf*/
    int m_tsf3ts2_id;
    /**m_tsf3ts2_rt leaf*/
    int m_tsf3ts2_rt;
    /**m_tsf3ts2_lr leaf*/
    int m_tsf3ts2_lr;
    /**m_tsf3ts2_pr leaf*/
    int m_tsf3ts2_pr;
    /**m_tsf3ts3_id leaf*/
    int m_tsf3ts3_id;
    /**m_tsf3ts3_rt leaf*/
    int m_tsf3ts3_rt;
    /**m_tsf3ts3_lr leaf*/
    int m_tsf3ts3_lr;
    /**m_tsf3ts3_pr leaf*/
    int m_tsf3ts3_pr;
    /**m_tsf3ts4_id leaf*/
    int m_tsf3ts4_id;
    /**m_tsf3ts4_rt leaf*/
    int m_tsf3ts4_rt;
    /**m_tsf3ts4_lr leaf*/
    int m_tsf3ts4_lr;
    /**m_tsf3ts4_pr leaf*/
    int m_tsf3ts4_pr;
    /**m_tsf3ts5_id leaf*/
    int m_tsf3ts5_id;
    /**m_tsf3ts5_rt leaf*/
    int m_tsf3ts5_rt;
    /**m_tsf3ts5_lr leaf*/
    int m_tsf3ts5_lr;
    /**m_tsf3ts5_pr leaf*/
    int m_tsf3ts5_pr;
    /**m_tsf3ts6_id leaf*/
    int m_tsf3ts6_id;
    /**m_tsf3ts6_rt leaf*/
    int m_tsf3ts6_rt;
    /**m_tsf3ts6_lr leaf*/
    int m_tsf3ts6_lr;
    /**m_tsf3ts6_pr leaf*/
    int m_tsf3ts6_pr;
    /**m_tsf3ts7_id leaf*/
    int m_tsf3ts7_id;
    /**m_tsf3ts7_rt leaf*/
    int m_tsf3ts7_rt;
    /**m_tsf3ts7_lr leaf*/
    int m_tsf3ts7_lr;
    /**m_tsf3ts7_pr leaf*/
    int m_tsf3ts7_pr;
    /**m_tsf3ts8_id leaf*/
    int m_tsf3ts8_id;
    /**m_tsf3ts8_rt leaf*/
    int m_tsf3ts8_rt;
    /**m_tsf3ts8_lr leaf*/
    int m_tsf3ts8_lr;
    /**m_tsf3ts8_pr leaf*/
    int m_tsf3ts8_pr;
    /**m_tsf3ts9_id leaf*/
    int m_tsf3ts9_id;
    /**m_tsf3ts9_rt leaf*/
    int m_tsf3ts9_rt;
    /**m_tsf3ts9_lr leaf*/
    int m_tsf3ts9_lr;
    /**m_tsf3ts9_pr leaf*/
    int m_tsf3ts9_pr;
    /**m_tsf3ts10_id leaf*/
    int m_tsf3ts10_id;
    /**m_tsf3ts10_rt leaf*/
    int m_tsf3ts10_rt;
    /**m_tsf3ts10_lr leaf*/
    int m_tsf3ts10_lr;
    /**m_tsf3ts10_pr leaf*/
    int m_tsf3ts10_pr;
    /**m_tsf3ts11_id leaf*/
    int m_tsf3ts11_id;
    /**m_tsf3ts11_rt leaf*/
    int m_tsf3ts11_rt;
    /**m_tsf3ts11_lr leaf*/
    int m_tsf3ts11_lr;
    /**m_tsf3ts11_pr leaf*/
    int m_tsf3ts11_pr;
    /**m_tsf3ts12_id leaf*/
    int m_tsf3ts12_id;
    /**m_tsf3ts12_rt leaf*/
    int m_tsf3ts12_rt;
    /**m_tsf3ts12_lr leaf*/
    int m_tsf3ts12_lr;
    /**m_tsf3ts12_pr leaf*/
    int m_tsf3ts12_pr;
    /**m_tsf3ts13_id leaf*/
    int m_tsf3ts13_id;
    /**m_tsf3ts13_rt leaf*/
    int m_tsf3ts13_rt;
    /**m_tsf3ts13_lr leaf*/
    int m_tsf3ts13_lr;
    /**m_tsf3ts13_pr leaf*/
    int m_tsf3ts13_pr;
    /**m_tsf3ts14_id leaf*/
    int m_tsf3ts14_id;
    /**m_tsf3ts14_rt leaf*/
    int m_tsf3ts14_rt;
    /**m_tsf3ts14_lr leaf*/
    int m_tsf3ts14_lr;
    /**m_tsf3ts14_pr leaf*/
    int m_tsf3ts14_pr;
    /**m_tsf5_cc leaf*/
    int m_tsf5_cc;
    /**m_tsf5ts0_id leaf*/
    int m_tsf5ts0_id;
    /**m_tsf5ts0_rt leaf*/
    int m_tsf5ts0_rt;
    /**m_tsf5ts0_lr leaf*/
    int m_tsf5ts0_lr;
    /**m_tsf5ts0_pr leaf*/
    int m_tsf5ts0_pr;
    /**m_tsf5ts1_id leaf*/
    int m_tsf5ts1_id;
    /**m_tsf5ts1_rt leaf*/
    int m_tsf5ts1_rt;
    /**m_tsf5ts1_lr leaf*/
    int m_tsf5ts1_lr;
    /**m_tsf5ts1_pr leaf*/
    int m_tsf5ts1_pr;
    /**m_tsf5ts2_id leaf*/
    int m_tsf5ts2_id;
    /**m_tsf5ts2_rt leaf*/
    int m_tsf5ts2_rt;
    /**m_tsf5ts2_lr leaf*/
    int m_tsf5ts2_lr;
    /**m_tsf5ts2_pr leaf*/
    int m_tsf5ts2_pr;
    /**m_tsf5ts3_id leaf*/
    int m_tsf5ts3_id;
    /**m_tsf5ts3_rt leaf*/
    int m_tsf5ts3_rt;
    /**m_tsf5ts3_lr leaf*/
    int m_tsf5ts3_lr;
    /**m_tsf5ts3_pr leaf*/
    int m_tsf5ts3_pr;
    /**m_tsf5ts4_id leaf*/
    int m_tsf5ts4_id;
    /**m_tsf5ts4_rt leaf*/
    int m_tsf5ts4_rt;
    /**m_tsf5ts4_lr leaf*/
    int m_tsf5ts4_lr;
    /**m_tsf5ts4_pr leaf*/
    int m_tsf5ts4_pr;
    /**m_tsf5ts5_id leaf*/
    int m_tsf5ts5_id;
    /**m_tsf5ts5_rt leaf*/
    int m_tsf5ts5_rt;
    /**m_tsf5ts5_lr leaf*/
    int m_tsf5ts5_lr;
    /**m_tsf5ts5_pr leaf*/
    int m_tsf5ts5_pr;
    /**m_tsf5ts6_id leaf*/
    int m_tsf5ts6_id;
    /**m_tsf5ts6_rt leaf*/
    int m_tsf5ts6_rt;
    /**m_tsf5ts6_lr leaf*/
    int m_tsf5ts6_lr;
    /**m_tsf5ts6_pr leaf*/
    int m_tsf5ts6_pr;
    /**m_tsf5ts7_id leaf*/
    int m_tsf5ts7_id;
    /**m_tsf5ts7_rt leaf*/
    int m_tsf5ts7_rt;
    /**m_tsf5ts7_lr leaf*/
    int m_tsf5ts7_lr;
    /**m_tsf5ts7_pr leaf*/
    int m_tsf5ts7_pr;
    /**m_tsf5ts8_id leaf*/
    int m_tsf5ts8_id;
    /**m_tsf5ts8_rt leaf*/
    int m_tsf5ts8_rt;
    /**m_tsf5ts8_lr leaf*/
    int m_tsf5ts8_lr;
    /**m_tsf5ts8_pr leaf*/
    int m_tsf5ts8_pr;
    /**m_tsf5ts9_id leaf*/
    int m_tsf5ts9_id;
    /**m_tsf5ts9_rt leaf*/
    int m_tsf5ts9_rt;
    /**m_tsf5ts9_lr leaf*/
    int m_tsf5ts9_lr;
    /**m_tsf5ts9_pr leaf*/
    int m_tsf5ts9_pr;
    /**m_tsf5ts10_id leaf*/
    int m_tsf5ts10_id;
    /**m_tsf5ts10_rt leaf*/
    int m_tsf5ts10_rt;
    /**m_tsf5ts10_lr leaf*/
    int m_tsf5ts10_lr;
    /**m_tsf5ts10_pr leaf*/
    int m_tsf5ts10_pr;
    /**m_tsf5ts11_id leaf*/
    int m_tsf5ts11_id;
    /**m_tsf5ts11_rt leaf*/
    int m_tsf5ts11_rt;
    /**m_tsf5ts11_lr leaf*/
    int m_tsf5ts11_lr;
    /**m_tsf5ts11_pr leaf*/
    int m_tsf5ts11_pr;
    /**m_tsf5ts12_id leaf*/
    int m_tsf5ts12_id;
    /**m_tsf5ts12_rt leaf*/
    int m_tsf5ts12_rt;
    /**m_tsf5ts12_lr leaf*/
    int m_tsf5ts12_lr;
    /**m_tsf5ts12_pr leaf*/
    int m_tsf5ts12_pr;
    /**m_tsf5ts13_id leaf*/
    int m_tsf5ts13_id;
    /**m_tsf5ts13_rt leaf*/
    int m_tsf5ts13_rt;
    /**m_tsf5ts13_lr leaf*/
    int m_tsf5ts13_lr;
    /**m_tsf5ts13_pr leaf*/
    int m_tsf5ts13_pr;
    /**m_tsf5ts14_id leaf*/
    int m_tsf5ts14_id;
    /**m_tsf5ts14_rt leaf*/
    int m_tsf5ts14_rt;
    /**m_tsf5ts14_lr leaf*/
    int m_tsf5ts14_lr;
    /**m_tsf5ts14_pr leaf*/
    int m_tsf5ts14_pr;
    /**m_tsf7_cc leaf*/
    int m_tsf7_cc;
    /**m_tsf7ts0_id leaf*/
    int m_tsf7ts0_id;
    /**m_tsf7ts0_rt leaf*/
    int m_tsf7ts0_rt;
    /**m_tsf7ts0_lr leaf*/
    int m_tsf7ts0_lr;
    /**m_tsf7ts0_pr leaf*/
    int m_tsf7ts0_pr;
    /**m_tsf7ts1_id leaf*/
    int m_tsf7ts1_id;
    /**m_tsf7ts1_rt leaf*/
    int m_tsf7ts1_rt;
    /**m_tsf7ts1_lr leaf*/
    int m_tsf7ts1_lr;
    /**m_tsf7ts1_pr leaf*/
    int m_tsf7ts1_pr;
    /**m_tsf7ts2_id leaf*/
    int m_tsf7ts2_id;
    /**m_tsf7ts2_rt leaf*/
    int m_tsf7ts2_rt;
    /**m_tsf7ts2_lr leaf*/
    int m_tsf7ts2_lr;
    /**m_tsf7ts2_pr leaf*/
    int m_tsf7ts2_pr;
    /**m_tsf7ts3_id leaf*/
    int m_tsf7ts3_id;
    /**m_tsf7ts3_rt leaf*/
    int m_tsf7ts3_rt;
    /**m_tsf7ts3_lr leaf*/
    int m_tsf7ts3_lr;
    /**m_tsf7ts3_pr leaf*/
    int m_tsf7ts3_pr;
    /**m_tsf7ts4_id leaf*/
    int m_tsf7ts4_id;
    /**m_tsf7ts4_rt leaf*/
    int m_tsf7ts4_rt;
    /**m_tsf7ts4_lr leaf*/
    int m_tsf7ts4_lr;
    /**m_tsf7ts4_pr leaf*/
    int m_tsf7ts4_pr;
    /**m_tsf7ts5_id leaf*/
    int m_tsf7ts5_id;
    /**m_tsf7ts5_rt leaf*/
    int m_tsf7ts5_rt;
    /**m_tsf7ts5_lr leaf*/
    int m_tsf7ts5_lr;
    /**m_tsf7ts5_pr leaf*/
    int m_tsf7ts5_pr;
    /**m_tsf7ts6_id leaf*/
    int m_tsf7ts6_id;
    /**m_tsf7ts6_rt leaf*/
    int m_tsf7ts6_rt;
    /**m_tsf7ts6_lr leaf*/
    int m_tsf7ts6_lr;
    /**m_tsf7ts6_pr leaf*/
    int m_tsf7ts6_pr;
    /**m_tsf7ts7_id leaf*/
    int m_tsf7ts7_id;
    /**m_tsf7ts7_rt leaf*/
    int m_tsf7ts7_rt;
    /**m_tsf7ts7_lr leaf*/
    int m_tsf7ts7_lr;
    /**m_tsf7ts7_pr leaf*/
    int m_tsf7ts7_pr;
    /**m_tsf7ts8_id leaf*/
    int m_tsf7ts8_id;
    /**m_tsf7ts8_rt leaf*/
    int m_tsf7ts8_rt;
    /**m_tsf7ts8_lr leaf*/
    int m_tsf7ts8_lr;
    /**m_tsf7ts8_pr leaf*/
    int m_tsf7ts8_pr;
    /**m_tsf7ts9_id leaf*/
    int m_tsf7ts9_id;
    /**m_tsf7ts9_rt leaf*/
    int m_tsf7ts9_rt;
    /**m_tsf7ts9_lr leaf*/
    int m_tsf7ts9_lr;
    /**m_tsf7ts9_pr leaf*/
    int m_tsf7ts9_pr;
    /**m_tsf7ts10_id leaf*/
    int m_tsf7ts10_id;
    /**m_tsf7ts10_rt leaf*/
    int m_tsf7ts10_rt;
    /**m_tsf7ts10_lr leaf*/
    int m_tsf7ts10_lr;
    /**m_tsf7ts10_pr leaf*/
    int m_tsf7ts10_pr;
    /**m_tsf7ts11_id leaf*/
    int m_tsf7ts11_id;
    /**m_tsf7ts11_rt leaf*/
    int m_tsf7ts11_rt;
    /**m_tsf7ts11_lr leaf*/
    int m_tsf7ts11_lr;
    /**m_tsf7ts11_pr leaf*/
    int m_tsf7ts11_pr;
    /**m_tsf7ts12_id leaf*/
    int m_tsf7ts12_id;
    /**m_tsf7ts12_rt leaf*/
    int m_tsf7ts12_rt;
    /**m_tsf7ts12_lr leaf*/
    int m_tsf7ts12_lr;
    /**m_tsf7ts12_pr leaf*/
    int m_tsf7ts12_pr;
    /**m_tsf7ts13_id leaf*/
    int m_tsf7ts13_id;
    /**m_tsf7ts13_rt leaf*/
    int m_tsf7ts13_rt;
    /**m_tsf7ts13_lr leaf*/
    int m_tsf7ts13_lr;
    /**m_tsf7ts13_pr leaf*/
    int m_tsf7ts13_pr;
    /**m_tsf7ts14_id leaf*/
    int m_tsf7ts14_id;
    /**m_tsf7ts14_rt leaf*/
    int m_tsf7ts14_rt;
    /**m_tsf7ts14_lr leaf*/
    int m_tsf7ts14_lr;
    /**m_tsf7ts14_pr leaf*/
    int m_tsf7ts14_pr;
    /**m_t2d_cc leaf*/
    int m_t2d_cc;
    /**m_t2d_fnf leaf*/
    int m_t2d_fnf;
    /**m_t2d0_charge leaf*/
    int m_t2d0_charge;
    /**m_t2d0_rho_s leaf*/
    int m_t2d0_rho_s;
    /**m_t2d0_phi leaf*/
    int m_t2d0_phi;
    /**m_t2d0ts0_id leaf*/
    int m_t2d0ts0_id;
    /**m_t2d0ts0_rt leaf*/
    int m_t2d0ts0_rt;
    /**m_t2d0ts0_lr leaf*/
    int m_t2d0ts0_lr;
    /**m_t2d0ts0_pr leaf*/
    int m_t2d0ts0_pr;
    /**m_t2d0ts2_id leaf*/
    int m_t2d0ts2_id;
    /**m_t2d0ts2_rt leaf*/
    int m_t2d0ts2_rt;
    /**m_t2d0ts2_lr leaf*/
    int m_t2d0ts2_lr;
    /**m_t2d0ts2_pr leaf*/
    int m_t2d0ts2_pr;
    /**m_t2d0ts4_id leaf*/
    int m_t2d0ts4_id;
    /**m_t2d0ts4_rt leaf*/
    int m_t2d0ts4_rt;
    /**m_t2d0ts4_lr leaf*/
    int m_t2d0ts4_lr;
    /**m_t2d0ts4_pr leaf*/
    int m_t2d0ts4_pr;
    /**m_t2d0ts6_id leaf*/
    int m_t2d0ts6_id;
    /**m_t2d0ts6_rt leaf*/
    int m_t2d0ts6_rt;
    /**m_t2d0ts6_lr leaf*/
    int m_t2d0ts6_lr;
    /**m_t2d0ts6_pr leaf*/
    int m_t2d0ts6_pr;
    /**m_t2d0ts8_id leaf*/
    int m_t2d0ts8_id;
    /**m_t2d0ts8_rt leaf*/
    int m_t2d0ts8_rt;
    /**m_t2d0ts8_lr leaf*/
    int m_t2d0ts8_lr;
    /**m_t2d0ts8_pr leaf*/
    int m_t2d0ts8_pr;
    /**m_t2d1_charge leaf*/
    int m_t2d1_charge;
    /**m_t2d1_rho_s leaf*/
    int m_t2d1_rho_s;
    /**m_t2d1_phi leaf*/
    int m_t2d1_phi;
    /**m_t2d1ts0_id leaf*/
    int m_t2d1ts0_id;
    /**m_t2d1ts0_rt leaf*/
    int m_t2d1ts0_rt;
    /**m_t2d1ts0_lr leaf*/
    int m_t2d1ts0_lr;
    /**m_t2d1ts0_pr leaf*/
    int m_t2d1ts0_pr;
    /**m_t2d1ts2_id leaf*/
    int m_t2d1ts2_id;
    /**m_t2d1ts2_rt leaf*/
    int m_t2d1ts2_rt;
    /**m_t2d1ts2_lr leaf*/
    int m_t2d1ts2_lr;
    /**m_t2d1ts2_pr leaf*/
    int m_t2d1ts2_pr;
    /**m_t2d1ts4_id leaf*/
    int m_t2d1ts4_id;
    /**m_t2d1ts4_rt leaf*/
    int m_t2d1ts4_rt;
    /**m_t2d1ts4_lr leaf*/
    int m_t2d1ts4_lr;
    /**m_t2d1ts4_pr leaf*/
    int m_t2d1ts4_pr;
    /**m_t2d1ts6_id leaf*/
    int m_t2d1ts6_id;
    /**m_t2d1ts6_rt leaf*/
    int m_t2d1ts6_rt;
    /**m_t2d1ts6_lr leaf*/
    int m_t2d1ts6_lr;
    /**m_t2d1ts6_pr leaf*/
    int m_t2d1ts6_pr;
    /**m_t2d1ts8_id leaf*/
    int m_t2d1ts8_id;
    /**m_t2d1ts8_rt leaf*/
    int m_t2d1ts8_rt;
    /**m_t2d1ts8_lr leaf*/
    int m_t2d1ts8_lr;
    /**m_t2d1ts8_pr leaf*/
    int m_t2d1ts8_pr;
    /**m_t2d2_charge leaf*/
    int m_t2d2_charge;
    /**m_t2d2_rho_s leaf*/
    int m_t2d2_rho_s;
    /**m_t2d2_phi leaf*/
    int m_t2d2_phi;
    /**m_t2d2ts0_id leaf*/
    int m_t2d2ts0_id;
    /**m_t2d2ts0_rt leaf*/
    int m_t2d2ts0_rt;
    /**m_t2d2ts0_lr leaf*/
    int m_t2d2ts0_lr;
    /**m_t2d2ts0_pr leaf*/
    int m_t2d2ts0_pr;
    /**m_t2d2ts2_id leaf*/
    int m_t2d2ts2_id;
    /**m_t2d2ts2_rt leaf*/
    int m_t2d2ts2_rt;
    /**m_t2d2ts2_lr leaf*/
    int m_t2d2ts2_lr;
    /**m_t2d2ts2_pr leaf*/
    int m_t2d2ts2_pr;
    /**m_t2d2ts4_id leaf*/
    int m_t2d2ts4_id;
    /**m_t2d2ts4_rt leaf*/
    int m_t2d2ts4_rt;
    /**m_t2d2ts4_lr leaf*/
    int m_t2d2ts4_lr;
    /**m_t2d2ts4_pr leaf*/
    int m_t2d2ts4_pr;
    /**m_t2d2ts6_id leaf*/
    int m_t2d2ts6_id;
    /**m_t2d2ts6_rt leaf*/
    int m_t2d2ts6_rt;
    /**m_t2d2ts6_lr leaf*/
    int m_t2d2ts6_lr;
    /**m_t2d2ts6_pr leaf*/
    int m_t2d2ts6_pr;
    /**m_t2d2ts8_id leaf*/
    int m_t2d2ts8_id;
    /**m_t2d2ts8_rt leaf*/
    int m_t2d2ts8_rt;
    /**m_t2d2ts8_lr leaf*/
    int m_t2d2ts8_lr;
    /**m_t2d2ts8_pr leaf*/
    int m_t2d2ts8_pr;
    /**m_t2d3_charge leaf*/
    int m_t2d3_charge;
    /**m_t2d3_rho_s leaf*/
    int m_t2d3_rho_s;
    /**m_t2d3_phi leaf*/
    int m_t2d3_phi;
    /**m_t2d3ts0_id leaf*/
    int m_t2d3ts0_id;
    /**m_t2d3ts0_rt leaf*/
    int m_t2d3ts0_rt;
    /**m_t2d3ts0_lr leaf*/
    int m_t2d3ts0_lr;
    /**m_t2d3ts0_pr leaf*/
    int m_t2d3ts0_pr;
    /**m_t2d3ts2_id leaf*/
    int m_t2d3ts2_id;
    /**m_t2d3ts2_rt leaf*/
    int m_t2d3ts2_rt;
    /**m_t2d3ts2_lr leaf*/
    int m_t2d3ts2_lr;
    /**m_t2d3ts2_pr leaf*/
    int m_t2d3ts2_pr;
    /**m_t2d3ts4_id leaf*/
    int m_t2d3ts4_id;
    /**m_t2d3ts4_rt leaf*/
    int m_t2d3ts4_rt;
    /**m_t2d3ts4_lr leaf*/
    int m_t2d3ts4_lr;
    /**m_t2d3ts4_pr leaf*/
    int m_t2d3ts4_pr;
    /**m_t2d3ts6_id leaf*/
    int m_t2d3ts6_id;
    /**m_t2d3ts6_rt leaf*/
    int m_t2d3ts6_rt;
    /**m_t2d3ts6_lr leaf*/
    int m_t2d3ts6_lr;
    /**m_t2d3ts6_pr leaf*/
    int m_t2d3ts6_pr;
    /**m_t2d3ts8_id leaf*/
    int m_t2d3ts8_id;
    /**m_t2d3ts8_rt leaf*/
    int m_t2d3ts8_rt;
    /**m_t2d3ts8_lr leaf*/
    int m_t2d3ts8_lr;
    /**m_t2d3ts8_pr leaf*/
    int m_t2d3ts8_pr;
    /**m_etf_in leaf*/
    int m_etf_thresh;
    /**m_etf_in leaf*/
    int m_etf_cc;
    /**m_etf_in leaf*/
    int m_etf_t0;
    /**m_etf_in leaf*/
    int m_etf_valid;

    /**m_t2dfittertrk0_rho leaf*/
    int m_t2dfittertrk0_rho;
    /**m_t2dfittertrk0_phi0 leaf*/
    int m_t2dfittertrk0_phi0;
    /**m_t2dfittertrk1_rho leaf*/
    int m_t2dfittertrk1_rho;
    /**m_t2dfittertrk1_phi0 leaf*/
    int m_t2dfittertrk1_phi0;
    /**m_t2dfittertrk2_rho leaf*/
    int m_t2dfittertrk2_rho;
    /**m_t2dfittertrk2_phi0 leaf*/
    int m_t2dfittertrk2_phi0;
    /**m_t2dfittertrk3_rho leaf*/
    int m_t2dfittertrk3_rho;
    /**m_t2dfittertrk3_phi0 leaf*/
    int m_t2dfittertrk3_phi0;

    /**extra leafs*/
    int m_firmid;
    /**extra leafs*/
    int m_firmver;
    /**extra leafs*/
    int m_evt;
    /**extra leafs*/
    int m_clk;
    /** the class title*/
    ClassDef(TRGCDCT3DUnpackerStore, 3);

  };

} // end namespace Belle2

#endif
