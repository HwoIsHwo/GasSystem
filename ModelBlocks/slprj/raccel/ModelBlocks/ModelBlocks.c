#include "ModelBlocks.h"
#include "rtwtypes.h"
#include "ModelBlocks_private.h"
#include "mwmathutil.h"
#include "rt_logging_mmi.h"
#include "ModelBlocks_capi.h"
#include "ModelBlocks_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.9 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define nxea3iumdw (-1)
#define ldkzgoyymj (-1)
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void mvuhcn552l ( g45lzr4it5 * localDW ) { localDW -> jpcdyxkjy2
= nxea3iumdw ; localDW -> e5so2ragv5 = 0U ; } void cijyqbaw1y ( real_T
d3z0oeys2o , mlbtf2u3uz * localB , g45lzr4it5 * localDW ) { real_T Gase ;
int32_T high_i ; int32_T low_i ; int32_T low_ip1 ; int32_T mid_i ; static
const real_T b [ 43 ] = { 20.0 , 32.0 , 35.0 , 40.0 , 44.8 , 48.2 , 50.0 ,
52.2 , 54.8 , 56.5 , 57.5 , 60.0 , 61.7 , 62.8 , 63.9 , 65.0 , 66.1 , 67.5 ,
70.0 , 71.0 , 72.0 , 74.0 , 75.0 , 76.5 , 78.0 , 80.0 , 82.0 , 83.0 , 85.0 ,
87.0 , 88.0 , 90.0 , 90.8 , 91.8 , 93.0 , 94.5 , 96.2 , 97.2 , 98.0 , 98.2 ,
98.5 , 98.8 , 99.0 } ; static const int16_T c [ 43 ] = { 0 , 18 , 28 , 42 ,
62 , 80 , 100 , 123 , 154 , 180 , 200 , 232 , 259 , 280 , 300 , 323 , 346 ,
360 , 400 , 433 , 450 , 478 , 500 , 538 , 552 , 580 , 600 , 635 , 668 , 700 ,
729 , 750 , 770 , 800 , 839 , 870 , 900 , 930 , 958 , 988 , 1000 , 1050 ,
1100 } ; int32_T exitg1 ; localDW -> jpcdyxkjy2 = nxea3iumdw ; if (
d3z0oeys2o >= 20.0 ) { high_i = 0 ; do { exitg1 = 0 ; if ( high_i < 43 ) { if
( muDoubleScalarIsNaN ( b [ high_i ] ) ) { exitg1 = 1 ; } else { high_i ++ ;
} } else { Gase = ( rtNaN ) ; if ( ! ( d3z0oeys2o > 99.0 ) ) { low_i = 0 ;
low_ip1 = 2 ; while ( high_i > low_ip1 ) { mid_i = ( ( low_i + high_i ) + 1 )
>> 1 ; if ( d3z0oeys2o >= b [ mid_i - 1 ] ) { low_i = mid_i - 1 ; low_ip1 =
mid_i + 1 ; } else { high_i = mid_i ; } } Gase = ( d3z0oeys2o - b [ low_i ] )
/ ( b [ low_i + 1 ] - b [ low_i ] ) ; if ( Gase == 0.0 ) { Gase = c [ low_i ]
; } else if ( Gase == 1.0 ) { Gase = c [ low_i + 1 ] ; } else if ( c [ low_i
+ 1 ] == c [ low_i ] ) { Gase = c [ low_i ] ; } else { Gase = ( 1.0 - Gase )
* ( real_T ) c [ low_i ] + ( real_T ) c [ low_i + 1 ] * Gase ; } } exitg1 = 1
; } } while ( exitg1 == 0 ) ; } else { Gase = 0.0 ; } localB -> kcv1sjzrqs =
Gase * 0.0980665 * 6.02E+23 / 149580.0 ; } void MdlInitialize ( void ) { rtX
. c5u3y2tbf2 = rtP . Integrator_IC ; rtX . j01qdckylg = rtP . Integrator2_IC
; rtX . bskccccubi = rtP . Integrator4_IC ; rtX . n4bb02xnbv = rtP .
Integrator5_IC ; rtX . ds4vjefdek = rtP . Integrator6_IC ; rtX . etgpe0ftqr =
0.0 ; rtDW . ghf3v2t5a5 = ( rtInf ) ; rtDW . aii4nuv3cr = ( rtInf ) ; rtX .
lav3igptia = rtP . Integrator7_IC ; rtX . ooqn20c4q0 = rtP . Integrator1_IC ;
rtX . ixwsxiop2t = rtP . Integrator3_IC ; rtDW . j0drszr332 = ldkzgoyymj ;
rtDW . nfdupoexm0 = 0U ; rtDW . hflfdwfuge = ldkzgoyymj ; rtDW . bzgcgpdc1e =
0U ; rtDW . kaeolhtwlh = ldkzgoyymj ; rtDW . mgdeszmuvz = 0U ; rtDW .
pa3jvcal33 = ldkzgoyymj ; rtDW . fxjzxzbic4 = 0U ; rtDW . kyxa2csw3e =
ldkzgoyymj ; rtDW . j1dzofkudz = 0U ; rtDW . oo4mwwihcw = ldkzgoyymj ; rtDW .
aognmsxie1 = 0U ; mvuhcn552l ( & rtDW . bkxyvvvhnw ) ; mvuhcn552l ( & rtDW .
nhxbwiqqxh ) ; rtDW . k1g0sjlh1j = ldkzgoyymj ; rtDW . fnfs3bp4ve = 0U ; rtDW
. apsja3htzl = ldkzgoyymj ; rtDW . mfsncmikpu = 0U ; rtDW . abvl1rsiow =
ldkzgoyymj ; rtDW . by3conhem2 = 0U ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtDW . cdqnmizait = 0 ; { FWksInfo * fromwksInfo ; if ( ( fromwksInfo = (
FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL ) ) {
ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "I_CS" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWorkspace_Data0 ; fromwksInfo -> nDataPoints = 3062 ;
fromwksInfo -> time = ( double * ) rtP . FromWorkspace_Time0 ; rtDW .
i005uqvmwn . TimePtr = fromwksInfo -> time ; rtDW . i005uqvmwn . DataPtr =
fromwksInfo -> data ; rtDW . i005uqvmwn . RSimInfoPtr = fromwksInfo ; } rtDW
. ni0boxuxv5 . PrevIndex = 0 ; } rtDW . i0ud4jlj0b = - 199999 ; MdlInitialize
( ) ; } void MdlOutputs ( int_T tid ) { real_T W1 ; real_T gg1odg1tl1 ;
real_T hat3l35r5z ; real_T l ; real_T nH ; real_T nHe ; real_T ne ; real_T ve
; real_T * lastU ; W1 = rtX . c5u3y2tbf2 + rtP . _Value_kejneha0ij ; if ( W1
> rtP . Saturation_UpperSat ) { rtB . lxqvqenuyn = rtP . Saturation_UpperSat
; } else if ( W1 < rtP . Saturation_LowerSat ) { rtB . lxqvqenuyn = rtP .
Saturation_LowerSat ; } else { rtB . lxqvqenuyn = W1 ; } if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { } W1 = rtX . j01qdckylg + rtP . u_Value_eistgp0o5q ; if (
W1 > rtP . Saturation2_UpperSat ) { rtB . erpdgfw4zl = rtP .
Saturation2_UpperSat ; } else if ( W1 < rtP . Saturation2_LowerSat ) { rtB .
erpdgfw4zl = rtP . Saturation2_LowerSat ; } else { rtB . erpdgfw4zl = W1 ; }
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ebcmbp3egx = ( rtDW . cdqnmizait
< rtP . PulseGenerator_Duty ) && ( rtDW . cdqnmizait >= 0 ) ? rtP .
PulseGenerator_Amp : 0.0 ; if ( rtDW . cdqnmizait >= rtP .
PulseGenerator_Period - 1.0 ) { rtDW . cdqnmizait = 0 ; } else { rtDW .
cdqnmizait ++ ; } } gg1odg1tl1 = ssGetT ( rtS ) ; rtDW . j0drszr332 =
ldkzgoyymj ; if ( gg1odg1tl1 < 2.1 ) { rtB . opshzz132t = 0.0 ; } else if (
gg1odg1tl1 < 2.3 ) { rtB . opshzz132t = 48.0 ; } else if ( gg1odg1tl1 < 2.5 )
{ rtB . opshzz132t = 50.0 ; } else if ( gg1odg1tl1 < 3.0 ) { rtB . opshzz132t
= 45.0 ; } else { rtB . opshzz132t = 0.0 ; } if ( ssIsSampleHit ( rtS , 1 , 0
) ) { } W1 = rtX . bskccccubi + rtP . u_Value_eluh3xjtru ; if ( W1 > rtP .
Saturation4_UpperSat ) { rtB . bw3a0p2bqv = rtP . Saturation4_UpperSat ; }
else if ( W1 < rtP . Saturation4_LowerSat ) { rtB . bw3a0p2bqv = rtP .
Saturation4_LowerSat ; } else { rtB . bw3a0p2bqv = W1 ; } W1 = rtX .
n4bb02xnbv + rtP . u_Value_gns1yzfsxy ; if ( W1 > rtP . Saturation5_UpperSat
) { rtB . dqfcv2fnp2 = rtP . Saturation5_UpperSat ; } else if ( W1 < rtP .
Saturation5_LowerSat ) { rtB . dqfcv2fnp2 = rtP . Saturation5_LowerSat ; }
else { rtB . dqfcv2fnp2 = W1 ; } rtB . kb3txhur04 = rtX . ds4vjefdek ; rtB .
pg0ayhkbqw = rtP . _Gain * rtB . kb3txhur04 / ( rtP . He_Gain * rtB .
erpdgfw4zl ) / ( rtP . He2e_Gain * rtB . dqfcv2fnp2 ) + rtP . t3_Value ; rtDW
. hflfdwfuge = ldkzgoyymj ; rtB . n4xsjy10x5 = ( rtB . erpdgfw4zl + rtB .
dqfcv2fnp2 ) * 1.3806E-23 * ( rtB . pg0ayhkbqw * 11640.0 ) / rtP . t4_Value /
( rtP . _Value_mpqgwbiwjq * rtP . _Value_mpqgwbiwjq * 0.4 * 1.0E+6 ) ;
gg1odg1tl1 = ssGetT ( rtS ) ; rtDW . kaeolhtwlh = ldkzgoyymj ; W1 = ( rtP .
u_Value_gopoj2vhwy - rtB . n4xsjy10x5 ) * 1000.0 / rtP . _Value_e2uvx0wlqy ;
if ( ( gg1odg1tl1 > rtP . u_Value ) && ( gg1odg1tl1 < rtP .
u_Value_nlnovbnqot ) ) { gg1odg1tl1 = rtB . lxqvqenuyn / W1 ; hat3l35r5z =
rtB . bw3a0p2bqv / W1 ; } else { gg1odg1tl1 = 0.0 ; hat3l35r5z = 0.0 ; } rtB
. iqpenfn13k = W1 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . cy55nvp1xg
= 0.0 ; rtB . cy55nvp1xg += rtP . _C * rtX . etgpe0ftqr ; rtB . b1kdwl1n0j =
rtP . _Gain_depxowzhnq * rtB . cy55nvp1xg / rtP . _Value_bdgj11ovdx ; if ( (
rtDW . ghf3v2t5a5 >= ssGetT ( rtS ) ) && ( rtDW . aii4nuv3cr >= ssGetT ( rtS
) ) ) { rtB . gj2x4y30u0 = 0.0 ; } else { W1 = rtDW . ghf3v2t5a5 ; lastU = &
rtDW . dalxnrrctb ; if ( rtDW . ghf3v2t5a5 < rtDW . aii4nuv3cr ) { if ( rtDW
. aii4nuv3cr < ssGetT ( rtS ) ) { W1 = rtDW . aii4nuv3cr ; lastU = & rtDW .
kn11hzopk2 ; } } else if ( rtDW . ghf3v2t5a5 >= ssGetT ( rtS ) ) { W1 = rtDW
. aii4nuv3cr ; lastU = & rtDW . kn11hzopk2 ; } rtB . gj2x4y30u0 = ( rtB .
b1kdwl1n0j - * lastU ) / ( ssGetT ( rtS ) - W1 ) ; } rtB . kuz5c05gig = rtB .
gj2x4y30u0 / rtB . jmuqskdwsd ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtDW
. pa3jvcal33 = ldkzgoyymj ; W1 = rtB . pg0ayhkbqw / 1000.0 ; rtB . o5ivrvpt4i
= 0.0002 / W1 * muDoubleScalarExp ( - 46.0 / muDoubleScalarSqrt ( W1 ) ) *
1.0E-28 * ( rtP . const2_Value * rtB . erpdgfw4zl ) * ( rtP . const3_Value *
rtB . erpdgfw4zl ) * ( ( muDoubleScalarSqrt ( rtB . pg0ayhkbqw * 1.6022E-19 *
2.0 / 3.3436E-27 ) + muDoubleScalarSqrt ( rtB . pg0ayhkbqw * 1.6022E-19 * 2.0
/ 5.0072E-27 ) ) / 2.0 ) / rtB . n4xsjy10x5 ; if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { } rtB . mgkxgbqk3r = rtX . lav3igptia ; rtDW . kyxa2csw3e =
ldkzgoyymj ; l = 6.2831853071795862 * rtP . const4_Value ; W1 = 0.024 /
muDoubleScalarPower ( rtB . pg0ayhkbqw / 1000.0 , 1.5 ) * 1.0E-6 / 1.0E+6 * l
* l / rtB . n4xsjy10x5 ; rtB . g2gmkhvvpf = ( rtB . gj2x4y30u0 - W1 * rtB .
mgkxgbqk3r ) / rtP . t2_Value ; rtB . hbki0olzy3 = W1 ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { } W1 = rtX . ooqn20c4q0 + rtP . Nw0_Value ; if ( W1 > rtP .
Saturation1_UpperSat ) { rtB . czr3hsf1dv = rtP . Saturation1_UpperSat ; }
else if ( W1 < rtP . Saturation1_LowerSat ) { rtB . czr3hsf1dv = rtP .
Saturation1_LowerSat ; } else { rtB . czr3hsf1dv = W1 ; } if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { } if ( rtX . ixwsxiop2t > rtP . Saturation3_UpperSat ) {
rtB . bjy2h3s1ia = rtP . Saturation3_UpperSat ; } else if ( rtX . ixwsxiop2t
< rtP . Saturation3_LowerSat ) { rtB . bjy2h3s1ia = rtP .
Saturation3_LowerSat ; } else { rtB . bjy2h3s1ia = rtX . ixwsxiop2t ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . bk1ddhubfb = ( rtP . Gain_Gain *
rtB . dqfcv2fnp2 + rtB . erpdgfw4zl ) / rtB . n4xsjy10x5 ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { } rtDW . oo4mwwihcw = ldkzgoyymj ; rtB . e0xhmzlcin = rtB
. lxqvqenuyn / rtP . t_ret_H_Value - rtB . czr3hsf1dv / rtP . t_rel_H_Value ;
rtB . n3cilisbmi = rtB . bw3a0p2bqv / rtP . t_ret_He_Value - rtB . bjy2h3s1ia
/ rtP . t_rel_He_Value ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { cijyqbaw1y (
rtB . ebcmbp3egx , & rtB . bkxyvvvhnw , & rtDW . bkxyvvvhnw ) ; } cijyqbaw1y
( rtB . opshzz132t , & rtB . nhxbwiqqxh , & rtDW . nhxbwiqqxh ) ; rtDW .
k1g0sjlh1j = ldkzgoyymj ; ve = muDoubleScalarAbs ( rtB . kuz5c05gig ) ; l =
rtP . a_Value / ( ( ( ( rtB . lxqvqenuyn + rtB . bw3a0p2bqv ) + rtB .
erpdgfw4zl ) + rtB . dqfcv2fnp2 ) / rtP . u_Value_gopoj2vhwy ) ; W1 = ve * l
; if ( W1 > 0.0 ) { W1 = 2900.0 / W1 * muDoubleScalarExp ( - 15.0 /
muDoubleScalarSqrt ( W1 ) ) * 1.0E-19 ; nH = rtB . lxqvqenuyn / rtP .
u_Value_gopoj2vhwy ; nHe = rtB . bw3a0p2bqv / rtP . u_Value_gopoj2vhwy ; ne =
( rtB . erpdgfw4zl + rtB . dqfcv2fnp2 ) / rtP . u_Value_gopoj2vhwy ; ve =
muDoubleScalarSqrt ( 1.6022E-19 * ve * l * 2.0 / 9.1094E-31 ) ; } else { W1 =
0.0 ; nH = 0.0 ; nHe = 0.0 ; ne = 0.0 ; ve = 0.0 ; } l = nH * ne * ve * W1 *
rtP . u_Value_gopoj2vhwy ; W1 = nHe * ne * ve * W1 * rtP . b_Value * rtP .
u_Value_gopoj2vhwy ; rtDW . apsja3htzl = ldkzgoyymj ; nHe = rtB . erpdgfw4zl
/ rtP . u_Value_gopoj2vhwy * rtP . t1_Value * ( 2.0 * rtB . dqfcv2fnp2 + rtB
. erpdgfw4zl ) ; ne = rtB . dqfcv2fnp2 / rtP . u_Value_gopoj2vhwy * rtP .
t1_Value * ( 2.0 * rtB . dqfcv2fnp2 + rtB . erpdgfw4zl ) ; rtB . kz2njgnd2w =
( ( ( ( rtB . bkxyvvvhnw . kcv1sjzrqs + rtB . nhxbwiqqxh . kcv1sjzrqs ) -
gg1odg1tl1 ) - rtB . e0xhmzlcin ) - l ) + nHe ; rtB . puoteh5fnw = ( ( ne -
hat3l35r5z ) - rtB . n3cilisbmi ) - W1 ; rtB . msytx2ws4j = ( l - nHe ) - rtP
. Gain1_Gain * rtB . o5ivrvpt4i ; rtB . n2nh4b5xu3 = ( W1 - ne ) + rtB .
o5ivrvpt4i ; { real_T * pDataValues = ( real_T * ) rtDW . i005uqvmwn .
DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . i005uqvmwn . TimePtr ;
int_T currTimeIndex = rtDW . ni0boxuxv5 . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; if ( t > pTimeValues [ 3061 ] ) { rtB .
k2ddarsr20 = 0.0 ; } else { int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . i005uqvmwn . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . ni0boxuxv5 . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { rtB . k2ddarsr20 =
pDataValues [ currTimeIndex ] ; } else { rtB . k2ddarsr20 = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; rtB . k2ddarsr20 = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB
. gnacy4jbt5 = ( rtDW . i0ud4jlj0b < rtP . PulseGenerator1_Duty ) && ( rtDW .
i0ud4jlj0b >= 0 ) ? rtP . PulseGenerator1_Amp : 0.0 ; if ( rtDW . i0ud4jlj0b
>= rtP . PulseGenerator1_Period - 1.0 ) { rtDW . i0ud4jlj0b = 0 ; } else {
rtDW . i0ud4jlj0b ++ ; } } rtDW . abvl1rsiow = ldkzgoyymj ; rtB . p4usmoxscc
= ( ( rtP . _Gain_nxafe313lt * rtB . o5ivrvpt4i * rtP . _Gain_nxqewhxxfv +
rtB . gnacy4jbt5 ) + rtB . mgkxgbqk3r * rtB . mgkxgbqk3r * rtB . hbki0olzy3 )
- rtB . kb3txhur04 / rtP . t_Value ; UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { rtB . jmuqskdwsd = rtP . upi_Gain * rtP .
_Value ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T *
lastU ; if ( rtDW . ghf3v2t5a5 == ( rtInf ) ) { rtDW . ghf3v2t5a5 = ssGetT (
rtS ) ; lastU = & rtDW . dalxnrrctb ; } else if ( rtDW . aii4nuv3cr == (
rtInf ) ) { rtDW . aii4nuv3cr = ssGetT ( rtS ) ; lastU = & rtDW . kn11hzopk2
; } else if ( rtDW . ghf3v2t5a5 < rtDW . aii4nuv3cr ) { rtDW . ghf3v2t5a5 =
ssGetT ( rtS ) ; lastU = & rtDW . dalxnrrctb ; } else { rtDW . aii4nuv3cr =
ssGetT ( rtS ) ; lastU = & rtDW . kn11hzopk2 ; } * lastU = rtB . b1kdwl1n0j ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> c5u3y2tbf2 = rtB .
kz2njgnd2w ; _rtXdot -> j01qdckylg = rtB . msytx2ws4j ; _rtXdot -> bskccccubi
= rtB . puoteh5fnw ; _rtXdot -> n4bb02xnbv = rtB . n2nh4b5xu3 ; _rtXdot ->
ds4vjefdek = rtB . p4usmoxscc ; _rtXdot -> etgpe0ftqr = rtP . _A * rtX .
etgpe0ftqr ; _rtXdot -> etgpe0ftqr += rtB . k2ddarsr20 ; _rtXdot ->
lav3igptia = rtB . g2gmkhvvpf ; _rtXdot -> ooqn20c4q0 = rtB . e0xhmzlcin ;
_rtXdot -> ixwsxiop2t = rtB . n3cilisbmi ; } void MdlProjection ( void ) { }
void MdlTerminate ( void ) { rt_FREE ( rtDW . i005uqvmwn . RSimInfoPtr ) ; }
static void mr_ModelBlocks_cacheDataAsMxArray ( mxArray * destArray , mwIndex
i , int j , const void * srcData , size_t numBytes ) ; static void
mr_ModelBlocks_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_ModelBlocks_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_ModelBlocks_restoreDataFromMxArray ( void * destData , const mxArray
* srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_ModelBlocks_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_ModelBlocks_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int
j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_ModelBlocks_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_ModelBlocks_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_ModelBlocks_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static
void mr_ModelBlocks_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
{ uint8_T * varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber (
destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes
] , ( const uint8_T * ) srcData , numBytes ) ; } static void
mr_ModelBlocks_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_ModelBlocks_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_ModelBlocks_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray
, mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_ModelBlocks_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_ModelBlocks_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_ModelBlocks_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_ModelBlocks_GetDWork ( ) { static const char_T *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW
= mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_ModelBlocks_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB )
, sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 40 ] = {
"rtDW.ghf3v2t5a5" , "rtDW.dalxnrrctb" , "rtDW.aii4nuv3cr" , "rtDW.kn11hzopk2"
, "rtDW.cdqnmizait" , "rtDW.i0ud4jlj0b" , "rtDW.abvl1rsiow" ,
"rtDW.k1g0sjlh1j" , "rtDW.oo4mwwihcw" , "rtDW.kyxa2csw3e" , "rtDW.pa3jvcal33"
, "rtDW.apsja3htzl" , "rtDW.hflfdwfuge" , "rtDW.kaeolhtwlh" ,
"rtDW.j0drszr332" , "rtDW.ni0boxuxv5" , "rtDW.by3conhem2" , "rtDW.fnfs3bp4ve"
, "rtDW.aognmsxie1" , "rtDW.j1dzofkudz" , "rtDW.fxjzxzbic4" ,
"rtDW.mfsncmikpu" , "rtDW.bzgcgpdc1e" , "rtDW.mgdeszmuvz" , "rtDW.nfdupoexm0"
, "rtDW.l4qmpx41bf" , "rtDW.pkqn1m3bre" , "rtDW.fghwqmn2m1" ,
"rtDW.jibwdrcl4s" , "rtDW.icnmxziast" , "rtDW.ke5oal2m3g" , "rtDW.nscags0kzh"
, "rtDW.j51s0newvq" , "rtDW.m00rcvsa4y" , "rtDW.bkxyvvvhnw.jpcdyxkjy2" ,
"rtDW.bkxyvvvhnw.e5so2ragv5" , "rtDW.bkxyvvvhnw.fbqqznr5oa" ,
"rtDW.nhxbwiqqxh.jpcdyxkjy2" , "rtDW.nhxbwiqqxh.e5so2ragv5" ,
"rtDW.nhxbwiqqxh.fbqqznr5oa" , } ; mxArray * rtdwData = mxCreateStructMatrix
( 1 , 1 , 40 , rtdwDataFieldNames ) ; mr_ModelBlocks_cacheDataAsMxArray (
rtdwData , 0 , 0 , ( const void * ) & ( rtDW . ghf3v2t5a5 ) , sizeof ( rtDW .
ghf3v2t5a5 ) ) ; mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 1 , (
const void * ) & ( rtDW . dalxnrrctb ) , sizeof ( rtDW . dalxnrrctb ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . aii4nuv3cr ) , sizeof ( rtDW . aii4nuv3cr ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . kn11hzopk2 ) , sizeof ( rtDW . kn11hzopk2 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . cdqnmizait ) , sizeof ( rtDW . cdqnmizait ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . i0ud4jlj0b ) , sizeof ( rtDW . i0ud4jlj0b ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . abvl1rsiow ) , sizeof ( rtDW . abvl1rsiow ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . k1g0sjlh1j ) , sizeof ( rtDW . k1g0sjlh1j ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . oo4mwwihcw ) , sizeof ( rtDW . oo4mwwihcw ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . kyxa2csw3e ) , sizeof ( rtDW . kyxa2csw3e ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & (
rtDW . pa3jvcal33 ) , sizeof ( rtDW . pa3jvcal33 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & (
rtDW . apsja3htzl ) , sizeof ( rtDW . apsja3htzl ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & (
rtDW . hflfdwfuge ) , sizeof ( rtDW . hflfdwfuge ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & (
rtDW . kaeolhtwlh ) , sizeof ( rtDW . kaeolhtwlh ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & (
rtDW . j0drszr332 ) , sizeof ( rtDW . j0drszr332 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & (
rtDW . ni0boxuxv5 ) , sizeof ( rtDW . ni0boxuxv5 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & (
rtDW . by3conhem2 ) , sizeof ( rtDW . by3conhem2 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & (
rtDW . fnfs3bp4ve ) , sizeof ( rtDW . fnfs3bp4ve ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & (
rtDW . aognmsxie1 ) , sizeof ( rtDW . aognmsxie1 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & (
rtDW . j1dzofkudz ) , sizeof ( rtDW . j1dzofkudz ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & (
rtDW . fxjzxzbic4 ) , sizeof ( rtDW . fxjzxzbic4 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & (
rtDW . mfsncmikpu ) , sizeof ( rtDW . mfsncmikpu ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & (
rtDW . bzgcgpdc1e ) , sizeof ( rtDW . bzgcgpdc1e ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & (
rtDW . mgdeszmuvz ) , sizeof ( rtDW . mgdeszmuvz ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & (
rtDW . nfdupoexm0 ) , sizeof ( rtDW . nfdupoexm0 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & (
rtDW . l4qmpx41bf ) , sizeof ( rtDW . l4qmpx41bf ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & (
rtDW . pkqn1m3bre ) , sizeof ( rtDW . pkqn1m3bre ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & (
rtDW . fghwqmn2m1 ) , sizeof ( rtDW . fghwqmn2m1 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) & (
rtDW . jibwdrcl4s ) , sizeof ( rtDW . jibwdrcl4s ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) & (
rtDW . icnmxziast ) , sizeof ( rtDW . icnmxziast ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) & (
rtDW . ke5oal2m3g ) , sizeof ( rtDW . ke5oal2m3g ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) & (
rtDW . nscags0kzh ) , sizeof ( rtDW . nscags0kzh ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) & (
rtDW . j51s0newvq ) , sizeof ( rtDW . j51s0newvq ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) & (
rtDW . m00rcvsa4y ) , sizeof ( rtDW . m00rcvsa4y ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) & (
rtDW . bkxyvvvhnw . jpcdyxkjy2 ) , sizeof ( rtDW . bkxyvvvhnw . jpcdyxkjy2 )
) ; mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * )
& ( rtDW . bkxyvvvhnw . e5so2ragv5 ) , sizeof ( rtDW . bkxyvvvhnw .
e5so2ragv5 ) ) ; mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 36 , (
const void * ) & ( rtDW . bkxyvvvhnw . fbqqznr5oa ) , sizeof ( rtDW .
bkxyvvvhnw . fbqqznr5oa ) ) ; mr_ModelBlocks_cacheDataAsMxArray ( rtdwData ,
0 , 37 , ( const void * ) & ( rtDW . nhxbwiqqxh . jpcdyxkjy2 ) , sizeof (
rtDW . nhxbwiqqxh . jpcdyxkjy2 ) ) ; mr_ModelBlocks_cacheDataAsMxArray (
rtdwData , 0 , 38 , ( const void * ) & ( rtDW . nhxbwiqqxh . e5so2ragv5 ) ,
sizeof ( rtDW . nhxbwiqqxh . e5so2ragv5 ) ) ;
mr_ModelBlocks_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void * ) & (
rtDW . nhxbwiqqxh . fbqqznr5oa ) , sizeof ( rtDW . nhxbwiqqxh . fbqqznr5oa )
) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_ModelBlocks_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 ,
sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0
, 1 ) ; mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ghf3v2t5a5 ) , rtdwData , 0 , 0 , sizeof ( rtDW . ghf3v2t5a5 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . dalxnrrctb ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . dalxnrrctb ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . aii4nuv3cr ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . aii4nuv3cr ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . kn11hzopk2 ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . kn11hzopk2 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . cdqnmizait ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . cdqnmizait ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . i0ud4jlj0b ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . i0ud4jlj0b ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . abvl1rsiow ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . abvl1rsiow ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . k1g0sjlh1j ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . k1g0sjlh1j ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . oo4mwwihcw ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . oo4mwwihcw ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . kyxa2csw3e ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . kyxa2csw3e ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . pa3jvcal33 ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . pa3jvcal33 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . apsja3htzl ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . apsja3htzl ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . hflfdwfuge ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . hflfdwfuge ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . kaeolhtwlh ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . kaeolhtwlh ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . j0drszr332 ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . j0drszr332 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . ni0boxuxv5 ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . ni0boxuxv5 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . by3conhem2 ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . by3conhem2 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . fnfs3bp4ve ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . fnfs3bp4ve ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . aognmsxie1 ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . aognmsxie1 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . j1dzofkudz ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . j1dzofkudz ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . fxjzxzbic4 ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . fxjzxzbic4 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . mfsncmikpu ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . mfsncmikpu ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . bzgcgpdc1e ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . bzgcgpdc1e ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . mgdeszmuvz ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . mgdeszmuvz ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . nfdupoexm0 ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . nfdupoexm0 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . l4qmpx41bf ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . l4qmpx41bf ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . pkqn1m3bre ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . pkqn1m3bre ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . fghwqmn2m1 ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . fghwqmn2m1 ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . jibwdrcl4s ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . jibwdrcl4s ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . icnmxziast ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . icnmxziast ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . ke5oal2m3g ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . ke5oal2m3g ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . nscags0kzh ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . nscags0kzh ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . j51s0newvq ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . j51s0newvq ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . m00rcvsa4y ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . m00rcvsa4y ) ) ;
mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . bkxyvvvhnw .
jpcdyxkjy2 ) , rtdwData , 0 , 34 , sizeof ( rtDW . bkxyvvvhnw . jpcdyxkjy2 )
) ; mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW . bkxyvvvhnw
. e5so2ragv5 ) , rtdwData , 0 , 35 , sizeof ( rtDW . bkxyvvvhnw . e5so2ragv5
) ) ; mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bkxyvvvhnw . fbqqznr5oa ) , rtdwData , 0 , 36 , sizeof ( rtDW . bkxyvvvhnw .
fbqqznr5oa ) ) ; mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & ( rtDW
. nhxbwiqqxh . jpcdyxkjy2 ) , rtdwData , 0 , 37 , sizeof ( rtDW . nhxbwiqqxh
. jpcdyxkjy2 ) ) ; mr_ModelBlocks_restoreDataFromMxArray ( ( void * ) & (
rtDW . nhxbwiqqxh . e5so2ragv5 ) , rtdwData , 0 , 38 , sizeof ( rtDW .
nhxbwiqqxh . e5so2ragv5 ) ) ; mr_ModelBlocks_restoreDataFromMxArray ( ( void
* ) & ( rtDW . nhxbwiqqxh . fbqqznr5oa ) , rtdwData , 0 , 39 , sizeof ( rtDW
. nhxbwiqqxh . fbqqznr5oa ) ) ; } } mxArray *
mr_ModelBlocks_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 10 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 10 ] = { "Scope" , "Scope" , "Scope" , "Scope" , "Scope"
, "Scope" , "Scope" , "Scope" , "Scope" , "Scope" , } ; static const char_T *
blockPath [ 10 ] = { "ModelBlocks/Scope" , "ModelBlocks/Scope1" ,
"ModelBlocks/Scope10" , "ModelBlocks/Scope11" , "ModelBlocks/Scope12" ,
"ModelBlocks/Scope13" , "ModelBlocks/Scope14" , "ModelBlocks/Scope15" ,
"ModelBlocks/Scope16" , "ModelBlocks/Scope17" , } ; static const int reason [
10 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ;
subs [ 0 ] < 10 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ; offset =
mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data , offset ,
mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } } return data
; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 9 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 115 ) ; ssSetNumBlockIO ( rtS , 39 ) ;
ssSetNumBlockParams ( rtS , 6189 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 1.0E-5 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3358527894U ) ;
ssSetChecksumVal ( rtS , 1 , 2108432981U ) ; ssSetChecksumVal ( rtS , 2 ,
2471921890U ) ; ssSetChecksumVal ( rtS , 3 , 784810643U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { real_T * x
= ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void
* ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } ModelBlocks_InitializeDataMapInfo
( ) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS
) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"ModelBlocks" ) ; ssSetPath ( rtS , "ModelBlocks" ) ; ssSetTStart ( rtS , 0.0
) ; ssSetTFinal ( rtS , 6.0000000000000009 ) ; ssSetStepSize ( rtS , 1.0E-5 )
; ssSetFixedStepSize ( rtS , 1.0E-5 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }
; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = {
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = {
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "ModelBlocks/Integrator" , "ModelBlocks/Integrator2" ,
"ModelBlocks/Integrator4" , "ModelBlocks/Integrator5" ,
"ModelBlocks/Integrator6" ,
 "ModelBlocks/&#x424;&#x438;&#x43B;&#x44C;&#x442;&#x440; &#x43E;&#x442; &#x448;&#x443;&#x43C;&#x430; &#x432; &#x434;&#x430;&#x43D;&#x43D;&#x44B;&#x445;"
, "ModelBlocks/Integrator7" , "ModelBlocks/Integrator1" ,
"ModelBlocks/Integrator3" } ; static const char_T * rt_LoggedStateNames [ ] =
{ "" , "" , "" , "" , "" , "" , "" , "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 } ;
static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 9 , rt_LoggedStateWidths
, rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 9 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . c5u3y2tbf2 ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . j01qdckylg ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . bskccccubi ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . n4bb02xnbv ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . ds4vjefdek ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . etgpe0ftqr ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . lav3igptia ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . ooqn20c4q0 ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . ixwsxiop2t ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 9 ] ;
static ssNonContDerivSigInfo nonContDerivSigInfo [ 2 ] = { { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . gnacy4jbt5 ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . bkxyvvvhnw . kcv1sjzrqs ) , ( NULL ) } } ;
ssSetNumNonContDerivSigInfos ( rtS , 2 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode3" ) ; ssSetVariableStepSolver ( rtS , 0 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelUpdate ( rtS , MdlUpdate )
; ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetTNextTid ( rtS ,
INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; } ssSetChecksumVal ( rtS , 0 , 3358527894U ) ;
ssSetChecksumVal ( rtS , 1 , 2108432981U ) ; ssSetChecksumVal ( rtS , 2 ,
2471921890U ) ; ssSetChecksumVal ( rtS , 3 , 784810643U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 12 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = &
rtAlwaysEnabled ; systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_ModelBlocks_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_ModelBlocks_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_ModelBlocks_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
