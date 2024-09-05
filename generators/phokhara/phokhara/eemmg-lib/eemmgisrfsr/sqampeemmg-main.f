! Valery Yundin 2011
!
! Process: 0 -> p1(e-) p2(e+) p3(mu-) p4(gamma) p5(mu+)
! contrubution of |ISRloop|*|FSRtree|^+
!
! OUTPUT:
! loop, tree
!
! INPUT:
! p1,p2,p3,p4,p5 particle momenta (all outgoing)
! mle2 - m_e^2 electrom mass squared
! mlm2 - m_mu^2 muon mass squared
! mu2  - mu_R^2 regularization scale
! eps 0 - finite part, 1 - pole
!
      subroutine eemmgsqampisrfsr(loop,tree,p1,p2,p3,p4,p5,mle2,mlm2,
     #mu2,eps)
      implicit none
      double complex loop,tree
      double precision p1(0:3),p2(0:3),p3(0:3),p4(0:3),p5(0:3)
      double precision mle2,mlm2,mu2,ren(0:2)
      integer eps

      double precision x0,x1
      double precision s12,s23,s34,s45,s15
      double precision s13,s24,s35,s14,s25
      double complex I5s,I4s,I123s
      double precision Rs,I0s

      double precision Z(557)

      include 'pjfry.f'

      double precision s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11

      double precision t1,t2,t5,t6,t8,t14,t16,t20,t26,t30,t43,t51,t54,t5
     #7,t59,t64,t66,t67,t74,t76,t84,t88,t92,t94,t103,t114,t116,t118,t123
     #,t127,t137,t144,t145,t150,t154,t158,t170,t182,t192,t203,t209,t215,
     #t225,t235,t250,t262,t270,t278,t286,t288,t293,t299,t306,t317,t327,t
     #338,t348,t356,t362,t373,t384,t387,t398,t402,t406,t420,t423,t437,t4
     #40,t441,t445,t449,t468,t476,t492,t496,t506,t516,t523,t527,t541,t56
     #4,t590,t609,t633,t645,t648,t649,t650,t651,t675,t682,t686,t691,t695
     #,t708,t734,t737,t768,t782,t802,t825,t837,t850,t863,t883,t908,t920,
     #t928,t947,t950,t955,t970,t997,t1000,t1012,t1025,t1033,t1054,t1068,
     #t1079,t1083,t1086,t1109,t1130,t1155,t1168,t1196,t1207,t1216,t1221,
     #t1227,t1231,t1252,t1257,t1261,t1264,t1306,t1338,t1345,t1366,t1394,
     #t1420,t1447,t1466,t1483,t1496,t1498,t1541,t1548
      double precision t1569,t1583,t1590,t1608,t1632,t1643,t1654,t1676,t
     #1696,t1703,t1725,t1748,t1751
      x0=p1(0)+p2(0)
      x1=dsqrt((p1(1)+p2(1))**2+(p1(2)+p2(2))**2+(p1(3)+p2(3))**2)
      s12=(x0+x1)*(x0-x1)

      x0=p1(0)+p3(0)
      x1=dsqrt((p1(1)+p3(1))**2+(p1(2)+p3(2))**2+(p1(3)+p3(3))**2)
      s13=(x0+x1)*(x0-x1)

      x0=p1(0)+p4(0)
      x1=dsqrt((p1(1)+p4(1))**2+(p1(2)+p4(2))**2+(p1(3)+p4(3))**2)
      s14=(x0+x1)*(x0-x1)

      x0=p1(0)+p5(0)
      x1=dsqrt((p1(1)+p5(1))**2+(p1(2)+p5(2))**2+(p1(3)+p5(3))**2)
      s15=(x0+x1)*(x0-x1)

      x0=p2(0)+p3(0)
      x1=dsqrt((p2(1)+p3(1))**2+(p2(2)+p3(2))**2+(p2(3)+p3(3))**2)
      s23=(x0+x1)*(x0-x1)

      x0=p2(0)+p4(0)
      x1=dsqrt((p2(1)+p4(1))**2+(p2(2)+p4(2))**2+(p2(3)+p4(3))**2)
      s24=(x0+x1)*(x0-x1)

      x0=p2(0)+p5(0)
      x1=dsqrt((p2(1)+p5(1))**2+(p2(2)+p5(2))**2+(p2(3)+p5(3))**2)
      s25=(x0+x1)*(x0-x1)

      x0=p3(0)+p4(0)
      x1=dsqrt((p3(1)+p4(1))**2+(p3(2)+p4(2))**2+(p3(3)+p4(3))**2)
      s34=(x0+x1)*(x0-x1)

      x0=p3(0)+p5(0)
      x1=dsqrt((p3(1)+p5(1))**2+(p3(2)+p5(2))**2+(p3(3)+p5(3))**2)
      s35=(x0+x1)*(x0-x1)

      x0=p4(0)+p5(0)
      x1=dsqrt((p4(1)+p5(1))**2+(p4(2)+p5(2))**2+(p4(3)+p5(3))**2)
      s45=(x0+x1)*(x0-x1)

      call Zinit1(s12,s23,s34,s45,s15,s13,s24,s35,s14,s25,mle2,mlm2,Z)
      call psetmusq(mu2)
      call pclearcache

      I5s=0
      s9=pd0i(1,0.D0,mle2,mle2,mle2,s24,s12,mle2,mle2,0.D0,0.D0,eps)
      s9=pd0i(1,0.D0,mle2,mle2,mle2,s14,s24,0.D0,0.D0,mle2,mle2,eps)
      t1=Z(21)*Z(4)
      t2=Z(8)*Z(7)
      t5=(-1+t2)*(Z(21)-Z(22))
      t6=pd0ijk(1,1,1,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps
     #)
      t14=Z(2)-Z(5)
      t16=pd0ijk(1,2,2,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t20=Z(35)**2
      t26=pd0ijk(2,2,2,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t30=pd0ijk(3,3,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t43=pd0ijk(2,3,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t51=pd0ijk(1,1,2,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t54=Z(29)*Z(21)*Z(2)
      t57=pd0ijk(1,1,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t59=Z(28)*Z(19)
      t64=pd0ijk(1,1,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t66=Z(22)*Z(8)
      t67=Z(7)**2
      t74=pd0ijk(1,3,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t76=Z(8)*t67
      t84=pd0ijk(0,0,1,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t88=Z(19)**2
      t92=pd0ijk(1,1,1,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,ep
     #s)
      t94=Z(33)*Z(32)
      t103=pd0ijk(1,2,2,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t114=pd0ijk(1,2,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t8=t1*t5
      t116=32*t8*t6+32*Z(4)*Z(35)*(Z(36)*Z(8)*Z(7)-Z(37))*t14*t16-32*Z(4
     #)*t20*(-Z(46)*Z(8)*Z(7)+Z(45))*t14*t26-32*t8*t30+32*(Z(21)*(-Z(54)
     #*Z(8)*Z(7)+Z(52))*Z(2)+Z(55)*Z(8)*Z(7)-Z(53))*Z(4)*t43+(32*Z(24)*Z
     #(19)*Z(2)-32*Z(23)*Z(5))*t51+(-32*Z(29)+32*t54)*t57+(32*t59*Z(2)-3
     #2*Z(27)*Z(5))*t64+((-32*t66*t67+32*Z(42))*Z(4)-32*t54)*t74+(128*Z(
     #5)*(-t76*Z(6)+Z(3))*Z(4)+128*Z(2)*Z(1))*t84+(32*Z(20)*Z(19)*Z(5)+3
     #2*t88*Z(2))*t92+(-32*Z(5)*(t94*t76-Z(34))*Z(4)-32*Z(31)*Z(30)*Z(2)
     #)*t103+(-32*Z(5)*(Z(39)*Z(8)*t67-Z(40))*Z(4)-64*Z(38)*Z(2))*t114
      t118=pd0ijk(2,3,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t123=Z(7)*Z(6)
      t127=pd0ijk(0,0,2,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t137=pd0ijk(1,1,2,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t144=Z(10)*Z(8)*t123-Z(9)
      t145=pd0ijk(0,0,1,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t150=pd0ijk(0,0,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t154=pd0ijk(2,2,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t158=Z(33)**2
      t170=pd0ijk(2,2,2,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t182=pd0ij(1,1,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t192=pd0ij(1,2,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t203=pd0ij(2,2,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t209=Z(8)*Z(32)
      t215=pd0ij(2,2,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t225=pd0ij(2,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t235=pd0ij(3,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t250=pd0ij(0,0,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t262=pd0ij(0,0,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t270=pd0ij(1,2,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t278=pd0ij(1,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t286=pd0ij(1,1,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t288=(-Z(21)*(-Z(68)*Z(8)+Z(67))*Z(2)+Z(69)/2-Z(70)*Z(8)/2)*t182+(
     #(-Z(75)+Z(77)*Z(8))*Z(2)+Z(5)*(-Z(8)*Z(76)+Z(74))/2)*t192+((Z(89)*
     #Z(8)-Z(87))*Z(2)-Z(5)*(-Z(88)+Z(8)*Z(90))/2)*Z(35)*t203+((Z(86)-Z(
     #83)*Z(33)*Z(8))*Z(2)+(t209*Z(84)-Z(85)/2)*Z(5))*t215+((Z(92)-Z(93)
     #*Z(8))*Z(2)+Z(5)*(Z(8)*Z(94)-Z(91))/2)*t225+(Z(21)*(Z(97)-Z(8)*Z(9
     #8))*Z(2)+Z(8)*Z(100)/2-Z(99)/2)*t235+((-2*Z(62)+8*Z(63)*Z(8)*Z(6))
     #*Z(2)-8*Z(5)*(Z(6)*Z(8)*Z(64)-Z(61)/8))*t250+((2*Z(57)-8*Z(60)*Z(8
     #)*Z(6))*Z(2)+Z(5)*(-Z(8)*Z(59)+Z(58)))*t262+(-Z(73)*Z(2)-Z(5)*(t2*
     #Z(71)-Z(72))/2)*t270+(-Z(80)*Z(2)-Z(5)*(t2*Z(78)-Z(79))/2)*t278+(Z
     #(5)*Z(65)/2+2*Z(66)*Z(19)*Z(2))*t286
      t293=pd0ij(1,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t299=pd0ij(2,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t306=pd0ij(3,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t317=pd0i(1,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t327=pd0i(2,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t338=pd0i(2,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t348=pd0i(3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t356=pd0i(1,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t362=pd0i(3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t373=pd0(0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,eps)
      t384=pd0(s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,eps)
      t387=(Z(81)*Z(2)-Z(5)*Z(82)/2)*t293+(Z(95)*Z(2)-Z(5)*Z(96)/2)*t299
     #-2*Z(19)*(-Z(102)*Z(5)/2+Z(101)*Z(2))*t306+((Z(107)-Z(108)*Z(8))*Z
     #(2)-Z(5)*(-Z(109)*Z(8)+Z(106))/2)*t317+((Z(115)-Z(117)*Z(8))*Z(2)-
     #Z(5)*(-Z(116)*Z(8)+Z(114))/2)*t327+((Z(113)*Z(8)-Z(111))*Z(2)+Z(5)
     #*(-2*Z(112)*Z(8)+Z(110))/2)*t338+((-Z(119)+Z(121)*Z(8))*Z(2)+Z(5)*
     #(-Z(120)*Z(8)+Z(118))/2)*t348+(Z(2)*Z(105)-Z(5)*(t2*Z(103)-Z(104))
     #/2)*t356+(Z(5)*Z(122)/2-Z(123)*Z(2))*t362+((Z(131)*Z(8)-Z(128))*Z(
     #2)-Z(5)*(-2*Z(8)*Z(130)+Z(129))/2)*t373-((-2*Z(8)*Z(127)+2*Z(125))
     #*Z(2)+Z(5)*(-2*Z(126)*Z(8)+Z(124)))*t384/2
      t398=pd0ijk(0,0,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t402=pd0ijk(1,2,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t406=pd0ijk(3,3,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t420=pd0ijk(0,0,2,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t423=pd0ijk(1,3,3,0.D0,mle2,mle2,s35,s14,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t437=pd0ijk(2,2,3,s35,mle2,mle2,0.D0,s24,s12,mle2,mle2,0.D0,mle2,e
     #ps)
      t440=-32*Z(56)*Z(19)*t14*t118-128*Z(4)*(-Z(16)*Z(8)*t123+Z(15))*t1
     #4*t127-32*Z(4)*(-Z(26)*Z(8)*Z(7)+Z(25))*(Z(21)*Z(2)-1)*t137+128*Z(
     #4)*t14*t144*t145-128*Z(1)*t14*t150+32*Z(51)*Z(35)*t14*t154-32*Z(32
     #)*((t158*Z(8)*Z(7)-Z(44))*Z(2)-Z(5)*(Z(33)*Z(8)*Z(7)*Z(32)-Z(43)))
     #*Z(4)*t170+16*(t288+t387)*Z(4)-128*(t144*Z(2)-Z(5)*(-Z(18)*Z(8)*Z(
     #7)+Z(17)))*Z(4)*t398+64*Z(41)*t14*t402-32*t88*t14*t406+128*((-Z(14
     #)*Z(8)*t123+Z(11))*Z(2)+Z(5)*(-Z(13)*Z(8)*Z(7)+Z(12))/2)*Z(4)*t420
     #-32*t59*t14*t423-32*((Z(49)*Z(33)*t2-Z(48))*Z(2)-Z(5)*(Z(50)*Z(32)
     #*t2-Z(47)))*Z(4)*t437
      I4s=t116+t440
      t441=Z(134)*Z(2)
      t445=Z(132)*Z(2)
      t449=pc0ij(0,0,s35,s12,0.D0,mle2,mle2,mle2,eps)
      t468=pc0i(2,s14,mle2,s35,mle2,0.D0,mle2,eps)
      t476=2*Z(150)
      t492=pc0ij(0,0,s14,mle2,s35,mle2,0.D0,mle2,eps)
      t496=Z(148)*Z(19)
      t506=pc0ij(2,2,s14,mle2,s35,mle2,0.D0,mle2,eps)
      t516=pc0ij(0,0,0.D0,s12,s35,mle2,mle2,mle2,eps)
      t523=Z(195)*Z(2)
      t527=pc0ij(1,2,0.D0,s12,s35,mle2,mle2,mle2,eps)
      t541=pc0i(1,mle2,mle2,s12,mle2,0.D0,mle2,eps)
      t564=pc0(s14,mle2,s35,mle2,0.D0,mle2,eps)
      t590=pc0ij(1,2,s14,mle2,s35,mle2,0.D0,mle2,eps)
      t609=pc0ij(1,2,0.D0,mle2,s24,mle2,mle2,0.D0,eps)
      t633=pc0ij(1,2,s35,mle2,s24,mle2,mle2,0.D0,eps)
      t645=pb0i(1,s24,0.D0,mle2,eps)
      t649=Z(8)*Z(4)
      t650=Z(182)-Z(183)
      t651=pc0ij(2,2,s35,s12,0.D0,mle2,mle2,mle2,eps)
      t675=pc0(0.D0,mle2,s14,mle2,mle2,0.D0,eps)
      t682=pc0ij(0,0,mle2,mle2,s12,mle2,0.D0,mle2,eps)
      t648=t649*t650
      s1=-32*Z(4)*((-t441-Z(5)*Z(135))*Z(8)+t445-Z(5)*Z(133))*t449-16*Z(
     #4)*(2*Z(206)*Z(201)*Z(6)*(Z(2)+Z(5))*Z(8)+(-Z(320)-Z(323)*Z(148)/2
     #)*Z(5)+Z(2)*(Z(321)-Z(322)*Z(148)/2))*t468-32*Z(4)*(((-Z(152)*Z(14
     #8)/2-Z(151))*Z(5)+Z(2)*(Z(153)*Z(148)-t476)/2)*Z(8)+(-Z(145)+Z(149
     #)*Z(148)/2)*Z(5)+Z(2)*(Z(146)-Z(148)*Z(147)/2))*t492+16*Z(4)*((Z(2
     #39)-Z(241)*Z(240)*t496)*Z(5)+Z(2)*(-Z(238)+Z(242)*Z(240)*t496))*t5
     #06-32*Z(4)*((-t441-2*Z(5)*Z(156))*Z(8)+t445+Z(5)*Z(155))*t516-16*Z
     #(4)*((Z(198)-2*Z(201)*Z(22))*Z(8)+t523+Z(5)*Z(214))*t527-16*Z(4)*(
     #(-Z(282)*Z(7)*Z(2)+Z(5)*Z(283)/2)*Z(8)-Z(5)*Z(280)/2+Z(281)*Z(2))*
     #t541
      s2=s1-16*Z(4)*(((Z(365)*Z(206)*Z(148)+Z(368))*Z(5)-Z(2)*(Z(366)*Z(
     #206)*Z(148)+Z(367)))*Z(8)+(-Z(364)/2-Z(370)*Z(148)/2)*Z(5)+(Z(363)
     #+Z(369)*Z(148)/2)*Z(2))*t564-8*Z(4)*(((-2*Z(206)*Z(46)*Z(35)-Z(212
     #))*Z(5)-2*Z(2)*Z(206)*(Z(46)*Z(35)+Z(207)/2))*Z(8)+(2*Z(208)+Z(211
     #)*Z(148))*Z(5)+Z(2)*(2*Z(209)+Z(210)*Z(148)))*t590+16*Z(4)*(((-Z(2
     #18)-Z(220))*Z(5)+Z(2)*(-Z(222)*Z(141)/2+Z(219)))*Z(8)+(Z(216)-Z(21
     #7))*Z(5)+(Z(215)-Z(221)*Z(141)/2)*Z(2))*t609
      t686=s2-16*Z(4)*(((t94*Z(7)+Z(204)/2)*Z(5)+Z(201)*(t94+Z(202)/2)*Z
     #(2))*Z(8)+(-Z(200)-Z(205)*Z(141)/2)*Z(5)-Z(2)*(2*Z(199)+Z(203)*Z(1
     #41))/2)*t633+8*Z(4)*((-2*Z(5)*Z(404)+Z(405)*Z(2))*Z(8)-Z(5)*Z(402)
     #+Z(403)*Z(2))*Z(141)*t645+16*t648*t651-16*Z(4)*(((Z(393)*Z(148)-Z(
     #392)/2)*Z(5)-(Z(394)*Z(148)/2+Z(389))*Z(2))*Z(8)+(Z(391)*Z(148)-Z(
     #388)/2)*Z(5)+Z(2)*(-Z(390)*Z(148)/2+Z(387)))*t675-128*Z(4)*(-Z(154
     #)/2+t2*Z(6))*Z(5)*t682
      t691=Z(7)*Z(2)
      t695=pc0i(2,0.D0,s12,s35,mle2,mle2,mle2,eps)
      t708=pc0(mle2,mle2,s12,mle2,0.D0,mle2,eps)
      t734=pc0ij(2,2,s35,mle2,s24,mle2,mle2,0.D0,eps)
      t737=pc0ij(1,1,0.D0,s12,s35,mle2,mle2,mle2,eps)
      t768=pc0ij(1,1,s14,mle2,s35,mle2,0.D0,mle2,eps)
      t782=pc0ij(1,1,s35,mle2,s24,mle2,mle2,0.D0,eps)
      t802=pc0ij(0,0,0.D0,mle2,s24,mle2,mle2,0.D0,eps)
      t825=pc0i(2,s35,mle2,s24,mle2,mle2,0.D0,eps)
      t837=pc0(0.D0,s12,s35,mle2,mle2,mle2,eps)
      t850=2*Z(21)
      t863=pb0i(1,0.D0,mle2,mle2,eps)
      t883=pc0ij(2,2,0.D0,mle2,s14,mle2,mle2,0.D0,eps)
      t908=pb0i(1,mle2,mle2,0.D0,eps)
      t920=2*Z(35)
      t928=pb0i(1,s14,0.D0,mle2,eps)
      t947=pb0i(1,s35,mle2,mle2,eps)
      t950=Z(201)*Z(6)
      t955=t950*Z(2)
      t970=pc0i(1,s35,mle2,s24,mle2,mle2,0.D0,eps)
      t997=pb0i(1,s14,mle2,0.D0,eps)
      s2=8*Z(4)*(-2*Z(5)*Z(329)+Z(330)*Z(2)+Z(328)*Z(8)*t691)*t695-16*Z(
     #4)*((-Z(373)*Z(2)+Z(5)*Z(374)/2)*Z(8)-Z(5)*Z(371)/2+Z(372)*Z(2))*t
     #708-16*Z(4)*(((-Z(167)*Z(33)*Z(32)-Z(235)/2)*Z(5)+Z(2)*(Z(232)*Z(3
     #3)*Z(32)+Z(236)/2))*Z(8)+(-Z(233)+Z(234)*Z(141)/2)*Z(5)+(Z(231)*Z(
     #32)-Z(237)*Z(141)/2)*Z(2))*t734+16*t648*t737
      s1=s2+((((-16*Z(180)*Z(46)*Z(35)-8*Z(178))*Z(5)+16*Z(2)*(Z(179)*Z(
     #46)*Z(35)+Z(177)/2))*Z(8)+8*Z(176)*Z(148)*Z(5)-8*Z(2)*(2*Z(174)+Z(
     #175)*Z(148)))*Z(4)-16*Z(35)*Z(5))*t768+16*Z(4)*((-Z(171)-Z(172)*Z(
     #141)*Z(45)*Z(19))*Z(5)+Z(2)*(Z(170)+Z(173)*Z(172)*Z(141)*Z(19)))*t
     #782-16*Z(4)*(((2*Z(159)-2*Z(161))*Z(5)+Z(2)*(Z(162)*Z(141)-t476))*
     #Z(8)+(-2*Z(157)+2*Z(158))*Z(5)+Z(2)*(2*Z(146)+Z(160)*Z(141)))*t802
     #+16*Z(4)*(((Z(319)*Z(141)/2-Z(315)/2)*Z(5)+(-Z(318)*Z(141)/2+Z(317
     #))*Z(2))*Z(8)+(-Z(312)/2+Z(316)*Z(141)/2)*Z(5)+(Z(313)-Z(314)*Z(14
     #1)/2)*Z(2))*t825
      s2=s1+8*Z(4)*((-4*Z(377)*Z(2)+4*Z(5)*Z(378))*Z(8)+Z(375)*Z(2)-Z(5)
     #*Z(376))*t837-8*Z(4)*(((2*Z(445)*Z(141)-2*Z(447)*Z(148))*Z(5)+(-Z(
     #444)*Z(141)+Z(446)*Z(148))*Z(2)-4*Z(22)-t850)*Z(8)+(2*Z(442)*Z(141
     #)+2*Z(206))*Z(5)-2+(Z(441)*Z(141)-Z(443)*Z(148))*Z(2))*t863+16*Z(4
     #)*(((Z(35)*Z(254)+Z(257))*Z(5)-Z(2)*(Z(259)*Z(148)+Z(260)*Z(46)))*
     #Z(8)+(-Z(256)+Z(35)*Z(253))*Z(5)+Z(2)*(Z(255)+Z(258)*Z(148)))*t883
      s3=s2+8*Z(4)*(((2*Z(428)*Z(148)-2*Z(431)*Z(141))*Z(5)+Z(2)*(-Z(429
     #)*Z(148)+Z(430)*Z(141)))*Z(8)+(2*Z(425)*Z(148)-2*Z(427)*Z(141))*Z(
     #5)+Z(2)*(-Z(424)*Z(148)+Z(426)*Z(141)))*t908-8*Z(4)*(((-2*Z(32)*Z(
     #35)+2*Z(423)*Z(148))*Z(5)-Z(422)*Z(148)*Z(2))*Z(8)+(-t920-Z(420)*Z
     #(148))*Z(5)+Z(421)*Z(148)*Z(2))*t928
      t1000=s3+16*Z(4)*(-Z(408)*(Z(201)*Z(141)+Z(206)*Z(148))*t14*Z(8)+(
     #-Z(410)*Z(141)-Z(411)*Z(148)-Z(406))*Z(5)+Z(2)*(Z(409)*Z(141)+Z(41
     #2)*Z(148)+Z(407)))*t947+16*Z(4)*(2*((t950/2+Z(265)/4)*Z(5)+t955)*Z
     #(206)*Z(8)+(-Z(268)/2+Z(270)*Z(141)/2)*Z(5)+(Z(269)+Z(271)*Z(141)/
     #2)*Z(2))*t970+16*Z(4)*((((-Z(419)*Z(46)/2+Z(418))*Z(148)+2*Z(22)*Z
     #(35))*Z(5)+Z(2)*(Z(46)*Z(21)-Z(417)*Z(148)))*Z(8)+((Z(414)+Z(416)/
     #2)*Z(148)+t920)*Z(5)-Z(2)*(Z(413)+Z(415)*Z(148)))*t997
      t1012=pc0i(1,s35,s12,0.D0,mle2,mle2,mle2,eps)
      t1025=pc0i(2,s35,s12,0.D0,mle2,mle2,mle2,eps)
      t1033=pc0ij(1,2,s35,s12,0.D0,mle2,mle2,mle2,eps)
      t1054=pc0(0.D0,mle2,s24,mle2,mle2,0.D0,eps)
      t1068=pc0i(2,mle2,mle2,s12,mle2,0.D0,mle2,eps)
      t1079=pc0i(1,0.D0,s12,s35,mle2,mle2,mle2,eps)
      t1083=Z(169)*Z(2)
      t1086=pc0ij(1,1,s35,s12,0.D0,mle2,mle2,mle2,eps)
      t1109=pc0ij(0,0,s35,mle2,s24,mle2,mle2,0.D0,eps)
      t1130=pc0i(2,0.D0,mle2,s24,mle2,mle2,0.D0,eps)
      t1155=pb0i(1,mle2,0.D0,mle2,eps)
      t1168=pc0(s35,s12,0.D0,mle2,mle2,mle2,eps)
      t1196=pb0i(1,s24,mle2,0.D0,eps)
      t1207=pc0i(1,s24,mle2,0.D0,mle2,0.D0,mle2,eps)
      t1216=2*Z(22)
      t1221=pc0ij(1,1,0.D0,mle2,s14,mle2,mle2,0.D0,eps)
      t1227=pc0ij(1,2,mle2,mle2,s12,mle2,0.D0,mle2,eps)
      s1=16*Z(4)*(-(t955+Z(5)*Z(265)/2)*Z(7)*Z(8)+Z(266)*Z(2)+Z(5)*Z(267
     #)/2)*t1012-16*Z(4)*((-Z(5)*Z(310)/2+Z(311)*Z(2))*Z(8)+Z(308)*Z(2)+
     #Z(5)*Z(309)/2)*t1025-16*Z(4)*((Z(197)+Z(198))*Z(8)+t523+Z(5)*Z(196
     #))*t1033-8*Z(4)*(((-2*Z(386)*Z(141)+2*Z(381))*Z(5)-Z(2)*(-Z(385)*Z
     #(141)+Z(383)))*Z(8)+(Z(380)-2*Z(382)*Z(141))*Z(5)+Z(2)*(Z(379)+Z(3
     #84)*Z(141)))*t1054+16*Z(4)*((Z(324)*Z(21)*t691-Z(5)*Z(327)/2)*Z(8)
     #+Z(5)*Z(325)/2-Z(326)*Z(2))*t1068+8*Z(4)*((-Z(5)*Z(286)+Z(287)*Z(2
     #))*Z(8)-Z(5)*Z(284)+Z(285)*Z(2))*t1079+16*Z(4)*(-Z(5)*Z(168)+t1083
     #)*t1086
      s2=s1-32*Z(4)*(((Z(143)*Z(141)/2+Z(138))*Z(5)+Z(2)*(Z(144)*Z(141)/
     #2+Z(137)))*Z(8)+(Z(136)-Z(142)*Z(141)/2)*Z(5)-(Z(139)+Z(141)*Z(140
     #)/2)*Z(2))*t1109+8*(((-2*Z(337)*Z(141)-Z(338))*Z(5)+Z(2)*(-Z(336)*
     #Z(141)+Z(335)))*Z(8)+(-Z(332)+2*Z(334)*Z(141))*Z(5)+Z(2)*(Z(331)+Z
     #(333)*Z(141)))*Z(4)*t1130+8*Z(4)*(((-Z(437)*Z(141)+Z(439)*Z(148)+2
     #*Z(433))*Z(5)+Z(2)*(Z(438)*Z(141)-Z(440)*Z(148)))*Z(8)+(-2*Z(253)-
     #Z(432)*Z(141)+Z(435)*Z(148))*Z(5)+Z(2)*(Z(434)*Z(141)-Z(436)*Z(148
     #)))*t1155
      t1231=s2+16*Z(4)*((2*Z(5)*Z(353)-2*Z(354)*Z(2))*Z(8)+Z(351)*Z(2)+Z
     #(5)*Z(352)/2)*t1168-16*Z(4)*((((-Z(396)*Z(32)/2+Z(401))*Z(141)+2*Z
     #(22)*Z(33))*Z(5)+Z(2)*(Z(32)*Z(21)+Z(400)*Z(141)))*Z(8)+((-Z(397)+
     #Z(398)/2)*Z(141)+2*Z(395))*Z(5)-Z(2)*(Z(32)+Z(399)*Z(141)))*t1196+
     #8*Z(4)*((-Z(263)*Z(2)-Z(5)*Z(264))*Z(8)+Z(5)*Z(261)+Z(262)*Z(2))*t
     #1207-8*Z(4)*((-2*Z(190)+2*Z(191)-2*Z(193)+Z(194)*Z(2))*Z(8)+t1216-
     #4*Z(21)-Z(192)*Z(2))*t1221+32*Z(5)*Z(4)*(Z(213)-t2*Z(39))*t1227
      t1252=pc0i(1,s14,mle2,s35,mle2,0.D0,mle2,eps)
      t1257=Z(141)**2
      t1261=Z(148)**2
      t1264=Z(466)/2
      t1306=pb0(mle2,mle2,0.D0,eps)
      t1338=pb0(s35,mle2,mle2,eps)
      t1345=Z(450)*Z(6)
      t1366=pb0(mle2,0.D0,mle2,eps)
      t1394=pb0(s14,mle2,0.D0,eps)
      t1420=pb0(0.D0,mle2,mle2,eps)
      t1447=pb0(s24,mle2,0.D0,eps)
      t1466=pb0(s14,0.D0,mle2,eps)
      t1483=pb0(s24,0.D0,mle2,eps)
      t1496=pb0(s12,mle2,mle2,eps)
      t1498=pa0(mle2,eps)
      t1541=pb0i(1,s12,mle2,mle2,eps)
      t1548=pc0ij(2,2,0.D0,s12,s35,mle2,mle2,mle2,eps)
      t1569=pc0ij(0,0,0.D0,mle2,s14,mle2,mle2,0.D0,eps)
      t1583=pc0ij(1,1,0.D0,mle2,s24,mle2,mle2,0.D0,eps)
      t1590=pc0ij(2,2,mle2,mle2,s12,mle2,0.D0,mle2,eps)
      t1608=pc0ij(1,2,0.D0,mle2,s14,mle2,mle2,0.D0,eps)
      t1632=pc0(s35,mle2,s24,mle2,mle2,0.D0,eps)
      t1643=pc0(s24,mle2,0.D0,mle2,0.D0,mle2,eps)
      t1654=pc0i(2,s24,mle2,0.D0,mle2,0.D0,mle2,eps)
      t1676=pc0i(1,0.D0,mle2,s14,mle2,mle2,0.D0,eps)
      t1696=pc0i(1,0.D0,mle2,s24,mle2,mle2,0.D0,eps)
      t1703=pc0ij(1,1,mle2,mle2,s12,mle2,0.D0,mle2,eps)
      t1725=pc0ij(2,2,0.D0,mle2,s24,mle2,mle2,0.D0,eps)
      t1748=pc0i(2,0.D0,mle2,s14,mle2,mle2,0.D0,eps)
      s4=-16*Z(4)*(((Z(279)*Z(148)/2-Z(274)/2)*Z(5)+Z(2)*(-Z(278)*Z(148)
     #/2+Z(276)))*Z(8)+(Z(272)/2+Z(277)*Z(148)/2)*Z(5)+Z(2)*(Z(273)-Z(27
     #5)*Z(148)/2))*t1252
      s6=16
      s8=Z(4)
      s11=(((-Z(497)*Z(141)-3*Z(504)*Z(499)*t1257+3*Z(506)*Z(499)*t1261+
     #t1264-Z(495)*Z(148))*Z(5)+3*Z(2)*(Z(505)*Z(499)*t1257-Z(498)*Z(141
     #)/6-Z(148)*(Z(148)*Z(507)*Z(499)-Z(496)/6)))*Z(8)+(Z(494)*Z(148)+Z
     #(492)*Z(141)+3*Z(500)*Z(499)*t1261+3*Z(502)*Z(499)*t1257+Z(490)/2)
     #*Z(5)+3*(Z(503)*Z(499)*t1257-Z(493)*Z(141)/6-(-Z(491)/6+Z(148)*Z(5
     #01)*Z(499))*Z(148))*Z(2))*t1306+(((Z(471)*Z(201)*Z(141)/2+Z(206)*(
     #2*Z(6)+Z(328)*Z(148))/2)*Z(5)-Z(2)*(Z(454)+Z(470)*Z(201)*Z(141)+Z(
     #472)*Z(206)*Z(148))/2)*Z(8)+(Z(473)*Z(141)/2-Z(469)*Z(148)/2-Z(467
     #))*Z(5)+Z(2)*(Z(474)*Z(141)+Z(468)*Z(148)+Z(185))/2)*t1338
      s10=s11+(((Z(514)*Z(141)/2+Z(517)*Z(148)/2+Z(513)/2)*Z(5)+Z(2)*(-8
     #*t1345+Z(515)*Z(148)+Z(516)*Z(141))/2)*Z(8)+(-Z(512)*Z(141)/2-Z(50
     #9)*Z(148)/2-Z(508)/2)*Z(5)-Z(2)*(Z(510)*Z(141)+Z(511)*Z(148)-8*Z(6
     #))/2)*t1366+(((-Z(478)*Z(148)/2+Z(482)*t1261-t1264)*Z(5)+Z(2)*(Z(4
     #79)*Z(148)-2*Z(483)*t1261+Z(454))/2)*Z(8)+(Z(481)*t1261-Z(476)*Z(1
     #48)/2+Z(475)/2)*Z(5)+Z(2)*(-2*Z(480)*t1261+Z(477)*Z(148)-Z(185))/2
     #)*t1394+(((-Z(521)*Z(141)/2+Z(524)*Z(148)/2)*Z(5)+Z(2)*(Z(522)*Z(1
     #41)-Z(525)*Z(148)-Z(454))/2)*Z(8)+(-Z(518)*Z(185)*Z(148)/2-Z(520)*
     #Z(141)/2)*Z(5)+1+(Z(519)*Z(148)/2+Z(523)*Z(141)/2-Z(451)/2)*Z(2))*
     #t1420
      s11=s10+((-Z(141)*(-Z(456)/2+Z(141)*Z(459))*Z(5)-Z(2)*(-Z(455)*Z(1
     #41)/2+Z(460)*t1257-Z(454)/2))*Z(8)+(-Z(453)/2+Z(141)*Z(458))*Z(141
     #)*Z(5)-1+(-Z(452)*Z(141)/2+Z(457)*t1257+Z(451)/2)*Z(2))*t1447+(((-
     #Z(488)*Z(148)+Z(487))*Z(5)-Z(2)*(-Z(489)*Z(148)+Z(466))/2)*Z(8)+(Z
     #(486)*Z(148)+Z(484))*Z(5)-Z(2)*(Z(461)+Z(485)*Z(148))/2)*t1466
      s9=s11+((-Z(464)*Z(141)*Z(5)+Z(2)*(Z(465)*Z(141)+Z(466))/2)*Z(8)-Z
     #(462)*Z(141)*Z(5)-Z(2)*(-Z(461)+Z(463)*Z(141))/2)*t1483+((4*t1345*
     #Z(2)-Z(5)*Z(449)/2)*Z(8)-4*Z(6)*Z(2)+Z(5)*Z(448)/2)*t1496-t1498*((
     #(-Z(538)*t1257+Z(541)*Z(141)+Z(148)*(-Z(535)+Z(148)*Z(539)))*Z(5)-
     #(Z(537)*t1257-Z(533)*Z(141)/2+(Z(536)/2+Z(148)*Z(540))*Z(148))*Z(2
     #))*Z(8)+(Z(532)*t1257-Z(528)*Z(141)+Z(148)*(Z(148)*Z(529)-Z(534)))
     #*Z(5)+Z(2)*(Z(531)*t1257+Z(527)*Z(141)/2-(Z(148)*Z(530)-Z(526)/2)*
     #Z(148)))
      s7=s8*s9
      s5=s6*s7
      s3=s4+s5
      s2=s3+(-16*Z(5)-16*t66*Z(4))*t1541+16*Z(4)*(t1083-2*Z(5)*Z(240)*Z(
     #244))*t1548
      s1=s2-32*Z(4)*(((-2*Z(167)*Z(6)-Z(165))*Z(5)+(Z(166)*Z(148)/2+Z(13
     #7))*Z(2))*Z(8)+(Z(45)+Z(163))*Z(5)-(Z(139)+Z(164)*Z(148)/2)*Z(2))*
     #t1569+8*Z(4)*((-2*Z(186)-2*Z(188)+2*Z(189)+Z(187)*Z(2))*Z(8)-t850+
     #t1216-2*Z(184)+Z(185)*Z(21)*Z(2))*t1583+32*Z(4)*(Z(243)*Z(5)-t66*Z
     #(7))*t1590+16*Z(4)*(((Z(226)+Z(229))*Z(5)-(Z(230)*Z(148)/2+Z(228))
     #*Z(2))*Z(8)-Z(5)*Z(224)+(Z(225)+Z(227)*Z(148)/2)*Z(2)+Z(223))*t160
     #8
      s2=s1-16*Z(4)*(((Z(358)*Z(201)*Z(141)-Z(361)/2)*Z(5)-Z(2)*(Z(357)*
     #Z(201)*Z(141)+Z(362)))*Z(8)+(Z(356)/2+Z(360)*Z(141)/2)*Z(5)+Z(2)*(
     #Z(355)+Z(359)*Z(141)/2))*t1632-8*Z(4)*((-Z(5)*Z(349)-Z(350)*Z(2))*
     #Z(8)+Z(347)*Z(2)+Z(5)*Z(348))*t1643+8*Z(4)*((Z(306)*Z(2)-Z(5)*Z(30
     #7))*Z(8)+Z(304)*Z(2)-Z(5)*Z(305))*t1654
      t1751=s2-16*Z(4)*(((-Z(302)*Z(148)-Z(298)/2)*Z(5)+Z(2)*(Z(303)*Z(1
     #48)/2+Z(299)))*Z(8)-Z(5)*Z(297)/2+(Z(296)-Z(301)*Z(148)/2)*Z(2)+Z(
     #300)*Z(148))*t1676-8*Z(4)*(((2*Z(293)*Z(141)+Z(295))*Z(5)-Z(2)*(Z(
     #294)*Z(141)+Z(292)))*Z(8)-Z(5)*Z(289)+(Z(288)+Z(291)*Z(141))*Z(2)+
     #2*Z(290)*Z(141))*t1696-32*Z(33)*Z(5)*Z(4)*(t209*Z(7)-Z(181))*t1703
     #+16*Z(4)*(((-Z(245)*Z(33)*Z(32)-Z(250))*Z(5)+Z(2)*(Z(247)*Z(32)-Z(
     #252)*Z(141)))*Z(8)+(-Z(248)+Z(249))*Z(5)+Z(2)*(-Z(251)*Z(141)+Z(24
     #6)*Z(32)))*t1725-16*Z(4)*(((-Z(346)*Z(148)-Z(344)/2)*Z(5)+(Z(345)*
     #Z(148)/2+Z(342))*Z(2))*Z(8)+(-Z(339)/2+Z(343)*Z(148))*Z(5)+(Z(340)
     #-Z(341)*Z(148)/2)*Z(2))*t1748
      I123s=t686+t1000+t1231+t1751
      Rs=8*Z(4)*(((-Z(553)+Z(554)*Z(8))*Z(2)-Z(5)*(Z(552)-Z(555)*Z(8)))*
     #t1257+((Z(545)-Z(546)*Z(8))*Z(2)-Z(5)*(Z(547)*Z(8)-Z(544)))*Z(141)
     #+(((Z(550)+Z(556)*Z(8))*Z(2)-Z(5)*(Z(557)*Z(8)+Z(549)))*Z(148)+(-Z
     #(543)-Z(551)*Z(8))*Z(2)+Z(5)*(Z(542)+Z(548)*Z(8)))*Z(148))
      I0s=8*Z(4)*(((-Z(531)+Z(537)*Z(8))*Z(2)-Z(5)*(Z(532)-Z(538)*Z(8)))
     #*Z(141)+((Z(530)+Z(540)*Z(8))*Z(2)-Z(5)*(Z(529)+Z(539)*Z(8)))*Z(14
     #8))

      if (eps.eq.0) then
      loop=I5s+I4s+I123s+Rs
      tree=I0s
      else
      loop=I5s+I4s+I123s
      tree=0
      endif

      ren(0)=(-4.D0-3.D0*dlog(mu2/mle2))
      ren(1)=-3.D0
      ren(2)=0.D0
      loop=loop+I0s*ren(abs(eps))

      end
