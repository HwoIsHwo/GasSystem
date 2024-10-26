#ifndef RTW_HEADER_ModelBlocks_h_
#define RTW_HEADER_ModelBlocks_h_
#ifndef ModelBlocks_COMMON_INCLUDES_
#define ModelBlocks_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "ModelBlocks_types.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME ModelBlocks
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (39) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (9)   
#elif NCSTATES != 9
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T kcv1sjzrqs ; } mlbtf2u3uz ; typedef struct { int32_T
jpcdyxkjy2 ; uint8_T e5so2ragv5 ; boolean_T fbqqznr5oa ; } g45lzr4it5 ;
typedef struct { real_T lxqvqenuyn ; real_T erpdgfw4zl ; real_T ebcmbp3egx ;
real_T bw3a0p2bqv ; real_T dqfcv2fnp2 ; real_T kb3txhur04 ; real_T pg0ayhkbqw
; real_T cy55nvp1xg ; real_T b1kdwl1n0j ; real_T gj2x4y30u0 ; real_T
kuz5c05gig ; real_T mgkxgbqk3r ; real_T czr3hsf1dv ; real_T bjy2h3s1ia ;
real_T bk1ddhubfb ; real_T kz2njgnd2w ; real_T puoteh5fnw ; real_T msytx2ws4j
; real_T n2nh4b5xu3 ; real_T k2ddarsr20 ; real_T gnacy4jbt5 ; real_T
jmuqskdwsd ; real_T p4usmoxscc ; real_T e0xhmzlcin ; real_T n3cilisbmi ;
real_T g2gmkhvvpf ; real_T hbki0olzy3 ; real_T o5ivrvpt4i ; real_T n4xsjy10x5
; real_T iqpenfn13k ; real_T opshzz132t ; mlbtf2u3uz bkxyvvvhnw ; mlbtf2u3uz
nhxbwiqqxh ; } B ; typedef struct { real_T ghf3v2t5a5 ; real_T dalxnrrctb ;
real_T aii4nuv3cr ; real_T kn11hzopk2 ; struct { void * LoggedData ; }
jrr1gpxjwa ; struct { void * LoggedData ; } d2ly5sgqbg ; struct { void *
LoggedData ; } dyhaagb0f1 ; struct { void * LoggedData ; } pjn13zkw43 ;
struct { void * LoggedData ; } lhnesgo0rr ; struct { void * LoggedData ; }
l0v2lmdurx ; struct { void * LoggedData ; } khaxbrnp4c ; struct { void *
LoggedData ; } aoedl1chnj ; struct { void * LoggedData ; } ppfr1jtayn ;
struct { void * LoggedData ; } jyne2vwprn ; struct { void * LoggedData ; }
k2vt4eg1yr ; struct { void * LoggedData ; } pkhssrlvkc ; struct { void *
LoggedData ; } e2jdteivfk ; struct { void * LoggedData ; } ajslle3vuq ;
struct { void * LoggedData ; } meftqfa2me ; struct { void * LoggedData ; }
c2k4shtfkr ; struct { void * LoggedData ; } nixqem1yly ; struct { void *
LoggedData ; } djlywwspxn ; struct { void * LoggedData ; } dnma4qj2h1 ;
struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } i005uqvmwn
; int32_T cdqnmizait ; int32_T i0ud4jlj0b ; int32_T abvl1rsiow ; int32_T
k1g0sjlh1j ; int32_T oo4mwwihcw ; int32_T kyxa2csw3e ; int32_T pa3jvcal33 ;
int32_T apsja3htzl ; int32_T hflfdwfuge ; int32_T kaeolhtwlh ; int32_T
j0drszr332 ; struct { int_T PrevIndex ; } ni0boxuxv5 ; uint8_T by3conhem2 ;
uint8_T fnfs3bp4ve ; uint8_T aognmsxie1 ; uint8_T j1dzofkudz ; uint8_T
fxjzxzbic4 ; uint8_T mfsncmikpu ; uint8_T bzgcgpdc1e ; uint8_T mgdeszmuvz ;
uint8_T nfdupoexm0 ; boolean_T l4qmpx41bf ; boolean_T pkqn1m3bre ; boolean_T
fghwqmn2m1 ; boolean_T jibwdrcl4s ; boolean_T icnmxziast ; boolean_T
ke5oal2m3g ; boolean_T nscags0kzh ; boolean_T j51s0newvq ; boolean_T
m00rcvsa4y ; g45lzr4it5 bkxyvvvhnw ; g45lzr4it5 nhxbwiqqxh ; } DW ; typedef
struct { real_T c5u3y2tbf2 ; real_T j01qdckylg ; real_T bskccccubi ; real_T
n4bb02xnbv ; real_T ds4vjefdek ; real_T etgpe0ftqr ; real_T lav3igptia ;
real_T ooqn20c4q0 ; real_T ixwsxiop2t ; } X ; typedef struct { real_T
c5u3y2tbf2 ; real_T j01qdckylg ; real_T bskccccubi ; real_T n4bb02xnbv ;
real_T ds4vjefdek ; real_T etgpe0ftqr ; real_T lav3igptia ; real_T ooqn20c4q0
; real_T ixwsxiop2t ; } XDot ; typedef struct { boolean_T c5u3y2tbf2 ;
boolean_T j01qdckylg ; boolean_T bskccccubi ; boolean_T n4bb02xnbv ;
boolean_T ds4vjefdek ; boolean_T etgpe0ftqr ; boolean_T lav3igptia ;
boolean_T ooqn20c4q0 ; boolean_T ixwsxiop2t ; } XDis ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
Integrator_IC ; real_T Saturation_UpperSat ; real_T Saturation_LowerSat ;
real_T Integrator2_IC ; real_T Saturation2_UpperSat ; real_T
Saturation2_LowerSat ; real_T PulseGenerator_Amp ; real_T
PulseGenerator_Period ; real_T PulseGenerator_Duty ; real_T
PulseGenerator_PhaseDelay ; real_T Integrator4_IC ; real_T
Saturation4_UpperSat ; real_T Saturation4_LowerSat ; real_T Integrator5_IC ;
real_T Saturation5_UpperSat ; real_T Saturation5_LowerSat ; real_T
Integrator6_IC ; real_T _Gain ; real_T He_Gain ; real_T He2e_Gain ; real_T _A
; real_T _C ; real_T _Gain_depxowzhnq ; real_T Integrator7_IC ; real_T
Integrator1_IC ; real_T Saturation1_UpperSat ; real_T Saturation1_LowerSat ;
real_T Integrator3_IC ; real_T Saturation3_UpperSat ; real_T
Saturation3_LowerSat ; real_T Gain_Gain ; real_T Gain1_Gain ; real_T
FromWorkspace_Time0 [ 3062 ] ; real_T FromWorkspace_Data0 [ 3062 ] ; real_T
PulseGenerator1_Amp ; real_T PulseGenerator1_Period ; real_T
PulseGenerator1_Duty ; real_T PulseGenerator1_PhaseDelay ; real_T
_Gain_nxafe313lt ; real_T _Gain_nxqewhxxfv ; real_T _Value ; real_T upi_Gain
; real_T Nw0_Value ; real_T a_Value ; real_T b_Value ; real_T const2_Value ;
real_T const3_Value ; real_T const4_Value ; real_T t_Value ; real_T t1_Value
; real_T t2_Value ; real_T t3_Value ; real_T t4_Value ; real_T t_rel_H_Value
; real_T t_rel_He_Value ; real_T t_ret_H_Value ; real_T t_ret_He_Value ;
real_T u_Value ; real_T u_Value_nlnovbnqot ; real_T _Value_bdgj11ovdx ;
real_T _Value_mpqgwbiwjq ; real_T _Value_e2uvx0wlqy ; real_T
u_Value_gopoj2vhwy ; real_T _Value_kejneha0ij ; real_T u_Value_eluh3xjtru ;
real_T u_Value_gns1yzfsxy ; real_T u_Value_eistgp0o5q ; } ; extern const
char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW
rtDW ; extern P rtP ; extern mxArray * mr_ModelBlocks_GetDWork ( ) ; extern
void mr_ModelBlocks_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_ModelBlocks_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * ModelBlocks_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
