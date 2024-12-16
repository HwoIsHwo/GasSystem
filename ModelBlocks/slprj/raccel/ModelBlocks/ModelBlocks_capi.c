#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "ModelBlocks_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "ModelBlocks.h"
#include "ModelBlocks_capi.h"
#include "ModelBlocks_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"ModelBlocks/PEV-1" ) , TARGET_STRING ( "Поток газонапуска H" ) , 0 , 0 , 0 ,
0 , 0 } , { 1 , 0 , TARGET_STRING (
"ModelBlocks/PEV-1/is_active_c3_ModelBlocks" ) , TARGET_STRING (
"is_active_c3_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 2 , 2 , TARGET_STRING
( "ModelBlocks/PEV-3" ) , TARGET_STRING ( "Поток газонапуска H" ) , 0 , 0 , 0
, 0 , 1 } , { 3 , 0 , TARGET_STRING (
"ModelBlocks/PEV-3/is_active_c3_ModelBlocks" ) , TARGET_STRING (
"is_active_c3_ModelBlocks" ) , 0 , 1 , 0 , 0 , 1 } , { 4 , 3 , TARGET_STRING
( "ModelBlocks/Signal" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 ,
0 , TARGET_STRING ( "ModelBlocks/Signal/is_active_c12_ModelBlocks" ) ,
TARGET_STRING ( "is_active_c12_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 6 , 4
, TARGET_STRING ( "ModelBlocks/Насосы" ) , TARGET_STRING ( "" ) , 2 , 0 , 0 ,
0 , 0 } , { 7 , 0 , TARGET_STRING (
"ModelBlocks/Насосы/is_active_c2_ModelBlocks" ) , TARGET_STRING (
"is_active_c2_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 8 , 5 , TARGET_STRING
( "ModelBlocks/Объем плазмы" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 9 , 0 , TARGET_STRING ( "ModelBlocks/Объем плазмы/is_active_c1_ModelBlocks"
) , TARGET_STRING ( "is_active_c1_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 10
, 0 , TARGET_STRING ( "ModelBlocks/Рекомбинация/is_active_c6_ModelBlocks" ) ,
TARGET_STRING ( "is_active_c6_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 11 , 7
, TARGET_STRING ( "ModelBlocks/Синтез" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 12 , 0 , TARGET_STRING (
"ModelBlocks/Синтез/is_active_c8_ModelBlocks" ) , TARGET_STRING (
"is_active_c8_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 13 , 8 , TARGET_STRING
( "ModelBlocks/Сопротивление пламзы" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 14 , 8 , TARGET_STRING ( "ModelBlocks/Сопротивление пламзы" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"ModelBlocks/Сопротивление пламзы/is_active_c9_ModelBlocks" ) , TARGET_STRING
( "is_active_c9_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 16 , 9 ,
TARGET_STRING ( "ModelBlocks/Стенка" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 17 , 9 , TARGET_STRING ( "ModelBlocks/Стенка" ) , TARGET_STRING (
"" ) , 1 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"ModelBlocks/Стенка/is_active_c5_ModelBlocks" ) , TARGET_STRING (
"is_active_c5_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING
( "ModelBlocks/Центральный соленоид/is_active_c7_ModelBlocks" ) ,
TARGET_STRING ( "is_active_c7_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 20 ,
11 , TARGET_STRING ( "ModelBlocks/Энергия плазмы" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"ModelBlocks/Энергия плазмы/is_active_c10_ModelBlocks" ) , TARGET_STRING (
"is_active_c10_ModelBlocks" ) , 0 , 1 , 0 , 0 , 0 } , { 22 , 0 ,
TARGET_STRING ( "ModelBlocks/Derivative" ) , TARGET_STRING (
"Напряжение по обходу, В" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING
( "ModelBlocks/Pulse Generator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1
} , { 24 , 0 , TARGET_STRING ( "ModelBlocks/Pulse Generator1" ) ,
TARGET_STRING ( "Мощность доп нагрева, Вт" ) , 0 , 0 , 0 , 0 , 1 } , { 25 , 0
, TARGET_STRING ( "ModelBlocks/From Workspace" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING ( "ModelBlocks/2pi" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 27 , 0 , TARGET_STRING (
"ModelBlocks/Integrator6" ) , TARGET_STRING ( "Энергия плазмы, Дж" ) , 0 , 0
, 0 , 0 , 0 } , { 28 , 0 , TARGET_STRING ( "ModelBlocks/Integrator7" ) ,
TARGET_STRING ( "Ток плазмы, А" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 0 ,
TARGET_STRING ( "ModelBlocks/Divide" ) , TARGET_STRING (
"Электронная плотность, м-3" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 0 ,
TARGET_STRING ( "ModelBlocks/Divide2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 31 , 0 , TARGET_STRING ( "ModelBlocks/Divide3" ) , TARGET_STRING
( "Напряженность В/м" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"ModelBlocks/Saturation" ) , TARGET_STRING ( "Кол-во атомов H в ВК" ) , 0 , 0
, 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING ( "ModelBlocks/Saturation1" ) ,
TARGET_STRING ( "Кол-во H на стенке" ) , 0 , 0 , 0 , 0 , 0 } , { 34 , 0 ,
TARGET_STRING ( "ModelBlocks/Saturation2" ) , TARGET_STRING (
"Кол-во ионов H+ в ВК" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"ModelBlocks/Saturation3" ) , TARGET_STRING ( "Кол-во He на стенке" ) , 0 , 0
, 0 , 0 , 0 } , { 36 , 0 , TARGET_STRING ( "ModelBlocks/Saturation4" ) ,
TARGET_STRING ( "Кол-во атомов He в ВК" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 0 ,
TARGET_STRING ( "ModelBlocks/Saturation5" ) , TARGET_STRING (
"Кол-во ионов He+ в ВК" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
"ModelBlocks/Add" ) , TARGET_STRING ( "Изменение кол-ва H в ВК" ) , 0 , 0 , 0
, 0 , 0 } , { 39 , 0 , TARGET_STRING ( "ModelBlocks/Add1" ) , TARGET_STRING (
"Изменение кол-ва He в ВК" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING
( "ModelBlocks/Add3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 41 ,
0 , TARGET_STRING ( "ModelBlocks/Add4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 42 , 0 , TARGET_STRING ( "ModelBlocks/Sum7" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"ModelBlocks/Фильтр от шума в данных" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static
const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 44 , TARGET_STRING
( "ModelBlocks/Nw0" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 45 ,
TARGET_STRING ( "ModelBlocks/a" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 46 , TARGET_STRING ( "ModelBlocks/b" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 47 , TARGET_STRING ( "ModelBlocks/const2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 48 , TARGET_STRING ( "ModelBlocks/const3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"ModelBlocks/const4" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 50 ,
TARGET_STRING ( "ModelBlocks/t" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 51 , TARGET_STRING ( "ModelBlocks/t1" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 52 , TARGET_STRING ( "ModelBlocks/t2" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 53 , TARGET_STRING ( "ModelBlocks/t3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING ( "ModelBlocks/t4" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 55 , TARGET_STRING (
"ModelBlocks/t_rel_H" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 56 ,
TARGET_STRING ( "ModelBlocks/t_rel_He" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 57 , TARGET_STRING ( "ModelBlocks/t_ret_H" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING ( "ModelBlocks/t_ret_He" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING (
"ModelBlocks/Время включения, с1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 60 , TARGET_STRING ( "ModelBlocks/Время выключения, с1" ) , TARGET_STRING
( "Value" ) , 0 , 0 , 0 } , { 61 , TARGET_STRING (
"ModelBlocks/Кол-во витков" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
62 , TARGET_STRING ( "ModelBlocks/Магнитная индукция в камере, Тл" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"ModelBlocks/Начальное кол-во частиц" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 64 , TARGET_STRING ( "ModelBlocks/Начальное кол-во частиц1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"ModelBlocks/Начальное кол-во частиц2" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 66 , TARGET_STRING ( "ModelBlocks/Начальное кол-во частиц3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING (
"ModelBlocks/Объем вакуумной камеры, м3 " ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 68 , TARGET_STRING (
"ModelBlocks/Производительность насосов, л//с" ) , TARGET_STRING ( "Value" )
, 0 , 0 , 0 } , { 69 , TARGET_STRING (
"ModelBlocks/Радиус по внутренней стенке, м" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 70 , TARGET_STRING ( "ModelBlocks/Pulse Generator" ) ,
TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 71 , TARGET_STRING (
"ModelBlocks/Pulse Generator" ) , TARGET_STRING ( "Period" ) , 0 , 0 , 0 } ,
{ 72 , TARGET_STRING ( "ModelBlocks/Pulse Generator" ) , TARGET_STRING (
"PulseWidth" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
"ModelBlocks/Pulse Generator" ) , TARGET_STRING ( "PhaseDelay" ) , 0 , 0 , 0
} , { 74 , TARGET_STRING ( "ModelBlocks/Pulse Generator1" ) , TARGET_STRING (
"Amplitude" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
"ModelBlocks/Pulse Generator1" ) , TARGET_STRING ( "Period" ) , 0 , 0 , 0 } ,
{ 76 , TARGET_STRING ( "ModelBlocks/Pulse Generator1" ) , TARGET_STRING (
"PulseWidth" ) , 0 , 0 , 0 } , { 77 , TARGET_STRING (
"ModelBlocks/Pulse Generator1" ) , TARGET_STRING ( "PhaseDelay" ) , 0 , 0 , 0
} , { 78 , TARGET_STRING ( "ModelBlocks/From Workspace" ) , TARGET_STRING (
"Time0" ) , 0 , 1 , 0 } , { 79 , TARGET_STRING ( "ModelBlocks/From Workspace"
) , TARGET_STRING ( "Data0" ) , 0 , 1 , 0 } , { 80 , TARGET_STRING (
"ModelBlocks/2pi" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 81 ,
TARGET_STRING ( "ModelBlocks/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 }
, { 82 , TARGET_STRING ( "ModelBlocks/Gain1" ) , TARGET_STRING ( "Gain" ) , 0
, 0 , 0 } , { 83 , TARGET_STRING ( "ModelBlocks/H+e" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 84 , TARGET_STRING ( "ModelBlocks/He+2e" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING (
"ModelBlocks/Дж в эВ" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 86 ,
TARGET_STRING ( "ModelBlocks/Индуктивность соленоида" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING ( "ModelBlocks/эВ в Дж" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 88 , TARGET_STRING (
"ModelBlocks/эВ в акте синтеза" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 89 , TARGET_STRING ( "ModelBlocks/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
"ModelBlocks/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 ,
0 } , { 91 , TARGET_STRING ( "ModelBlocks/Integrator2" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 92 , TARGET_STRING (
"ModelBlocks/Integrator3" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 ,
0 } , { 93 , TARGET_STRING ( "ModelBlocks/Integrator4" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 94 , TARGET_STRING (
"ModelBlocks/Integrator5" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 ,
0 } , { 95 , TARGET_STRING ( "ModelBlocks/Integrator6" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 96 , TARGET_STRING (
"ModelBlocks/Integrator7" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 ,
0 } , { 97 , TARGET_STRING ( "ModelBlocks/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 98 , TARGET_STRING (
"ModelBlocks/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , {
99 , TARGET_STRING ( "ModelBlocks/Saturation1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 100 , TARGET_STRING (
"ModelBlocks/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } ,
{ 101 , TARGET_STRING ( "ModelBlocks/Saturation2" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 102 , TARGET_STRING (
"ModelBlocks/Saturation2" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } ,
{ 103 , TARGET_STRING ( "ModelBlocks/Saturation3" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 104 , TARGET_STRING (
"ModelBlocks/Saturation3" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } ,
{ 105 , TARGET_STRING ( "ModelBlocks/Saturation4" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 106 , TARGET_STRING (
"ModelBlocks/Saturation4" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } ,
{ 107 , TARGET_STRING ( "ModelBlocks/Saturation5" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 108 , TARGET_STRING (
"ModelBlocks/Saturation5" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } ,
{ 109 , TARGET_STRING ( "ModelBlocks/Фильтр от шума в данных" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 110 , TARGET_STRING (
"ModelBlocks/Фильтр от шума в данных" ) , TARGET_STRING ( "C" ) , 0 , 0 , 0 }
, { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . nhxbwiqqxh . kcv1sjzrqs , & rtDW
. nhxbwiqqxh . e5so2ragv5 , & rtB . bkxyvvvhnw . kcv1sjzrqs , & rtDW .
bkxyvvvhnw . e5so2ragv5 , & rtB . opshzz132t , & rtDW . nfdupoexm0 , & rtB .
iqpenfn13k , & rtDW . mgdeszmuvz , & rtB . n4xsjy10x5 , & rtDW . bzgcgpdc1e ,
& rtDW . mfsncmikpu , & rtB . o5ivrvpt4i , & rtDW . fxjzxzbic4 , & rtB .
g2gmkhvvpf , & rtB . hbki0olzy3 , & rtDW . j1dzofkudz , & rtB . e0xhmzlcin ,
& rtB . n3cilisbmi , & rtDW . aognmsxie1 , & rtDW . fnfs3bp4ve , & rtB .
p4usmoxscc , & rtDW . by3conhem2 , & rtB . gj2x4y30u0 , & rtB . ebcmbp3egx ,
& rtB . gnacy4jbt5 , & rtB . k2ddarsr20 , & rtB . jmuqskdwsd , & rtB .
kb3txhur04 , & rtB . mgkxgbqk3r , & rtB . bk1ddhubfb , & rtB . b1kdwl1n0j , &
rtB . kuz5c05gig , & rtB . lxqvqenuyn , & rtB . czr3hsf1dv , & rtB .
erpdgfw4zl , & rtB . bjy2h3s1ia , & rtB . bw3a0p2bqv , & rtB . dqfcv2fnp2 , &
rtB . kz2njgnd2w , & rtB . puoteh5fnw , & rtB . msytx2ws4j , & rtB .
n2nh4b5xu3 , & rtB . pg0ayhkbqw , & rtB . cy55nvp1xg , & rtP . Nw0_Value , &
rtP . a_Value , & rtP . b_Value , & rtP . const2_Value , & rtP . const3_Value
, & rtP . const4_Value , & rtP . t_Value , & rtP . t1_Value , & rtP .
t2_Value , & rtP . t3_Value , & rtP . t4_Value , & rtP . t_rel_H_Value , &
rtP . t_rel_He_Value , & rtP . t_ret_H_Value , & rtP . t_ret_He_Value , & rtP
. u_Value , & rtP . u_Value_nlnovbnqot , & rtP . _Value_bdgj11ovdx , & rtP .
_Value_mpqgwbiwjq , & rtP . _Value_kejneha0ij , & rtP . u_Value_eluh3xjtru ,
& rtP . u_Value_gns1yzfsxy , & rtP . u_Value_eistgp0o5q , & rtP .
u_Value_gopoj2vhwy , & rtP . _Value_e2uvx0wlqy , & rtP . _Value , & rtP .
PulseGenerator_Amp , & rtP . PulseGenerator_Period , & rtP .
PulseGenerator_Duty , & rtP . PulseGenerator_PhaseDelay , & rtP .
PulseGenerator1_Amp , & rtP . PulseGenerator1_Period , & rtP .
PulseGenerator1_Duty , & rtP . PulseGenerator1_PhaseDelay , & rtP .
FromWorkspace_Time0 [ 0 ] , & rtP . FromWorkspace_Data0 [ 0 ] , & rtP .
upi_Gain , & rtP . Gain_Gain , & rtP . Gain1_Gain , & rtP . He_Gain , & rtP .
He2e_Gain , & rtP . _Gain , & rtP . _Gain_depxowzhnq , & rtP .
_Gain_nxqewhxxfv , & rtP . _Gain_nxafe313lt , & rtP . Integrator_IC , & rtP .
Integrator1_IC , & rtP . Integrator2_IC , & rtP . Integrator3_IC , & rtP .
Integrator4_IC , & rtP . Integrator5_IC , & rtP . Integrator6_IC , & rtP .
Integrator7_IC , & rtP . Saturation_UpperSat , & rtP . Saturation_LowerSat ,
& rtP . Saturation1_UpperSat , & rtP . Saturation1_LowerSat , & rtP .
Saturation2_UpperSat , & rtP . Saturation2_LowerSat , & rtP .
Saturation3_UpperSat , & rtP . Saturation3_LowerSat , & rtP .
Saturation4_UpperSat , & rtP . Saturation4_LowerSat , & rtP .
Saturation5_UpperSat , & rtP . Saturation5_LowerSat , & rtP . _A , & rtP . _C
, } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 3062 , 1 } ; static const
real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0E-5 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 1 , ( uint8_T ) 0
} , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 44 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 67 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 3358527894U , 2108432981U , 2471921890U ,
784810643U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * ModelBlocks_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void ModelBlocks_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void ModelBlocks_host_InitializeDataMapInfo ( ModelBlocks_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
