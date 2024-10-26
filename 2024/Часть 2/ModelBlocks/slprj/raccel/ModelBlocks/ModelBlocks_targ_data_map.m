    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 67;
            section.data(67)  = dumData; %prealloc

                    ;% rtP.Integrator_IC
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Saturation_UpperSat
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Saturation_LowerSat
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Integrator2_IC
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Saturation2_UpperSat
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Saturation2_LowerSat
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.PulseGenerator_Amp
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.PulseGenerator_Period
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.PulseGenerator_Duty
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.PulseGenerator_PhaseDelay
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Integrator4_IC
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Saturation4_UpperSat
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.Saturation4_LowerSat
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Integrator5_IC
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.Saturation5_UpperSat
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.Saturation5_LowerSat
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.Integrator6_IC
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP._Gain
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.He_Gain
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.He2e_Gain
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP._A
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP._C
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP._Gain_depxowzhnq
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.Integrator7_IC
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.Integrator1_IC
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.Saturation1_UpperSat
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.Saturation1_LowerSat
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 26;

                    ;% rtP.Integrator3_IC
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 27;

                    ;% rtP.Saturation3_UpperSat
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 28;

                    ;% rtP.Saturation3_LowerSat
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 29;

                    ;% rtP.Gain_Gain
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 30;

                    ;% rtP.Gain1_Gain
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 31;

                    ;% rtP.FromWorkspace_Time0
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 32;

                    ;% rtP.FromWorkspace_Data0
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 3094;

                    ;% rtP.PulseGenerator1_Amp
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 6156;

                    ;% rtP.PulseGenerator1_Period
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 6157;

                    ;% rtP.PulseGenerator1_Duty
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 6158;

                    ;% rtP.PulseGenerator1_PhaseDelay
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 6159;

                    ;% rtP._Gain_nxafe313lt
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 6160;

                    ;% rtP._Gain_nxqewhxxfv
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 6161;

                    ;% rtP._Value
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 6162;

                    ;% rtP.upi_Gain
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 6163;

                    ;% rtP.Nw0_Value
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 6164;

                    ;% rtP.a_Value
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 6165;

                    ;% rtP.b_Value
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 6166;

                    ;% rtP.const2_Value
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 6167;

                    ;% rtP.const3_Value
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 6168;

                    ;% rtP.const4_Value
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 6169;

                    ;% rtP.t_Value
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 6170;

                    ;% rtP.t1_Value
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 6171;

                    ;% rtP.t2_Value
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 6172;

                    ;% rtP.t3_Value
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 6173;

                    ;% rtP.t4_Value
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 6174;

                    ;% rtP.t_rel_H_Value
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 6175;

                    ;% rtP.t_rel_He_Value
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 6176;

                    ;% rtP.t_ret_H_Value
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 6177;

                    ;% rtP.t_ret_He_Value
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 6178;

                    ;% rtP.u_Value
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 6179;

                    ;% rtP.u_Value_nlnovbnqot
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 6180;

                    ;% rtP._Value_bdgj11ovdx
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 6181;

                    ;% rtP._Value_mpqgwbiwjq
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 6182;

                    ;% rtP._Value_e2uvx0wlqy
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 6183;

                    ;% rtP.u_Value_gopoj2vhwy
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 6184;

                    ;% rtP._Value_kejneha0ij
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 6185;

                    ;% rtP.u_Value_eluh3xjtru
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 6186;

                    ;% rtP.u_Value_gns1yzfsxy
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 6187;

                    ;% rtP.u_Value_eistgp0o5q
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 6188;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 31;
            section.data(31)  = dumData; %prealloc

                    ;% rtB.lxqvqenuyn
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.erpdgfw4zl
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.ebcmbp3egx
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.bw3a0p2bqv
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.dqfcv2fnp2
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.kb3txhur04
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% rtB.pg0ayhkbqw
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% rtB.cy55nvp1xg
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% rtB.b1kdwl1n0j
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% rtB.gj2x4y30u0
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

                    ;% rtB.kuz5c05gig
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 10;

                    ;% rtB.mgkxgbqk3r
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 11;

                    ;% rtB.czr3hsf1dv
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 12;

                    ;% rtB.bjy2h3s1ia
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 13;

                    ;% rtB.bk1ddhubfb
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 14;

                    ;% rtB.kz2njgnd2w
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 15;

                    ;% rtB.puoteh5fnw
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 16;

                    ;% rtB.msytx2ws4j
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 17;

                    ;% rtB.n2nh4b5xu3
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 18;

                    ;% rtB.k2ddarsr20
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 19;

                    ;% rtB.gnacy4jbt5
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 20;

                    ;% rtB.jmuqskdwsd
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 21;

                    ;% rtB.p4usmoxscc
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 22;

                    ;% rtB.e0xhmzlcin
                    section.data(24).logicalSrcIdx = 25;
                    section.data(24).dtTransOffset = 23;

                    ;% rtB.n3cilisbmi
                    section.data(25).logicalSrcIdx = 26;
                    section.data(25).dtTransOffset = 24;

                    ;% rtB.g2gmkhvvpf
                    section.data(26).logicalSrcIdx = 27;
                    section.data(26).dtTransOffset = 25;

                    ;% rtB.hbki0olzy3
                    section.data(27).logicalSrcIdx = 28;
                    section.data(27).dtTransOffset = 26;

                    ;% rtB.o5ivrvpt4i
                    section.data(28).logicalSrcIdx = 29;
                    section.data(28).dtTransOffset = 27;

                    ;% rtB.n4xsjy10x5
                    section.data(29).logicalSrcIdx = 32;
                    section.data(29).dtTransOffset = 28;

                    ;% rtB.iqpenfn13k
                    section.data(30).logicalSrcIdx = 35;
                    section.data(30).dtTransOffset = 29;

                    ;% rtB.opshzz132t
                    section.data(31).logicalSrcIdx = 36;
                    section.data(31).dtTransOffset = 30;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.bkxyvvvhnw.kcv1sjzrqs
                    section.data(1).logicalSrcIdx = 37;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.nhxbwiqqxh.kcv1sjzrqs
                    section.data(1).logicalSrcIdx = 38;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 12;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.ghf3v2t5a5
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.dalxnrrctb
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.aii4nuv3cr
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.kn11hzopk2
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% rtDW.jrr1gpxjwa.LoggedData
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.d2ly5sgqbg.LoggedData
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.dyhaagb0f1.LoggedData
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.pjn13zkw43.LoggedData
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.lhnesgo0rr.LoggedData
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.l0v2lmdurx.LoggedData
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.khaxbrnp4c.LoggedData
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.aoedl1chnj.LoggedData
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.ppfr1jtayn.LoggedData
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.jyne2vwprn.LoggedData
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.k2vt4eg1yr.LoggedData
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.pkhssrlvkc.LoggedData
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.e2jdteivfk.LoggedData
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.ajslle3vuq.LoggedData
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.meftqfa2me.LoggedData
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.c2k4shtfkr.LoggedData
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.nixqem1yly.LoggedData
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.djlywwspxn.LoggedData
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 17;

                    ;% rtDW.dnma4qj2h1.LoggedData
                    section.data(19).logicalSrcIdx = 22;
                    section.data(19).dtTransOffset = 18;

                    ;% rtDW.i005uqvmwn.TimePtr
                    section.data(20).logicalSrcIdx = 23;
                    section.data(20).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% rtDW.cdqnmizait
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.i0ud4jlj0b
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.abvl1rsiow
                    section.data(3).logicalSrcIdx = 26;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.k1g0sjlh1j
                    section.data(4).logicalSrcIdx = 27;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.oo4mwwihcw
                    section.data(5).logicalSrcIdx = 28;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.kyxa2csw3e
                    section.data(6).logicalSrcIdx = 29;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.pa3jvcal33
                    section.data(7).logicalSrcIdx = 30;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.apsja3htzl
                    section.data(8).logicalSrcIdx = 31;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.hflfdwfuge
                    section.data(9).logicalSrcIdx = 32;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.kaeolhtwlh
                    section.data(10).logicalSrcIdx = 33;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.j0drszr332
                    section.data(11).logicalSrcIdx = 34;
                    section.data(11).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ni0boxuxv5.PrevIndex
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtDW.by3conhem2
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.fnfs3bp4ve
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.aognmsxie1
                    section.data(3).logicalSrcIdx = 38;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.j1dzofkudz
                    section.data(4).logicalSrcIdx = 39;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.fxjzxzbic4
                    section.data(5).logicalSrcIdx = 40;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.mfsncmikpu
                    section.data(6).logicalSrcIdx = 41;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.bzgcgpdc1e
                    section.data(7).logicalSrcIdx = 42;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.mgdeszmuvz
                    section.data(8).logicalSrcIdx = 43;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.nfdupoexm0
                    section.data(9).logicalSrcIdx = 44;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% rtDW.l4qmpx41bf
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.pkqn1m3bre
                    section.data(2).logicalSrcIdx = 46;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.fghwqmn2m1
                    section.data(3).logicalSrcIdx = 47;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.jibwdrcl4s
                    section.data(4).logicalSrcIdx = 48;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.icnmxziast
                    section.data(5).logicalSrcIdx = 49;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.ke5oal2m3g
                    section.data(6).logicalSrcIdx = 50;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.nscags0kzh
                    section.data(7).logicalSrcIdx = 51;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.j51s0newvq
                    section.data(8).logicalSrcIdx = 52;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.m00rcvsa4y
                    section.data(9).logicalSrcIdx = 53;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.bkxyvvvhnw.jpcdyxkjy2
                    section.data(1).logicalSrcIdx = 54;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.bkxyvvvhnw.e5so2ragv5
                    section.data(1).logicalSrcIdx = 55;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.bkxyvvvhnw.fbqqznr5oa
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.nhxbwiqqxh.jpcdyxkjy2
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.nhxbwiqqxh.e5so2ragv5
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.nhxbwiqqxh.fbqqznr5oa
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3358527894;
    targMap.checksum1 = 2108432981;
    targMap.checksum2 = 2471921890;
    targMap.checksum3 = 784810643;

