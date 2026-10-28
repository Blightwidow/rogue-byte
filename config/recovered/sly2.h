/* Sly 2: Band of Thieves (SCUS-97316): prototypes of the functions named from the Sly 1 decomp, demangled
 * from their GCC 2.95 names by demangle.py. Parameters come from the mangling; return types are guessed from
 * the Hungarian prefix (F flag, G float, ...) or left undefined4. Names come from code matching: unverified.
 * Structs are opaque: Sly 2 layouts differ from Sly 1. The parameter lists are Sly 1's: a function can keep its
 * role and name in Sly 2 but change its parameters (CalcCmAdjust looks like it takes an output VECTOR first). */

typedef unsigned int undefined4;
typedef int bool;
typedef int wchar_t;

typedef struct ACCMISS ACCMISS;
typedef struct ACSB ACSB;
typedef struct ACSC ACSC;
typedef struct ACT ACT;
typedef struct ACTADJ ACTADJ;
typedef struct ACTLA ACTLA;
typedef struct ACTSEG ACTSEG;
typedef struct ACVK ACVK;
typedef struct ALARM ALARM;
typedef struct ALO ALO;
typedef struct AMB AMB;
typedef struct ASEG ASEG;
typedef struct ASEGA ASEGA;
typedef struct ASEGBL ASEGBL;
typedef struct BASIC BASIC;
typedef struct BIFK BIFK;
typedef struct BL BL;
typedef struct BLIP BLIP;
typedef struct BLIPG BLIPG;
typedef struct BLIPOK BLIPOK;
typedef struct BLIPP BLIPP;
typedef struct BLIPV BLIPV;
typedef struct BLIPX BLIPX;
typedef struct BLOT BLOT;
typedef struct BLRUN BLRUN;
typedef struct BMP BMP;
typedef struct BOMB BOMB;
typedef struct BRK BRK;
typedef struct BSP BSP;
typedef struct BSPC BSPC;
typedef struct BTN BTN;
typedef struct BUBLET BUBLET;
typedef struct BUTTON BUTTON;
typedef struct BUTTONS BUTTONS;
typedef struct CBSP CBSP;
typedef struct CBinaryAsyncStream CBinaryAsyncStream;
typedef struct CBinaryInputStream CBinaryInputStream;
typedef struct CByteQueue CByteQueue;
typedef struct CFileLocation CFileLocation;
typedef struct CFont CFont;
typedef struct CFontBrx CFontBrx;
typedef struct CFrame CFrame;
typedef struct CG CG;
typedef struct CGV CGV;
typedef struct CGc CGc;
typedef struct CHKMGR CHKMGR;
typedef struct CIRCLER CIRCLER;
typedef struct CLOCK CLOCK;
typedef struct CLQ CLQ;
typedef struct CLUT CLUT;
typedef struct CM CM;
typedef struct CMethod CMethod;
typedef struct CMpeg CMpeg;
typedef struct CMpegAudio CMpegAudio;
typedef struct CNVO CNVO;
typedef struct COIN COIN;
typedef struct CPDEFI CPDEFI;
typedef struct CPLCY CPLCY;
typedef struct CPP CPP;
typedef struct CPTN CPTN;
typedef struct CPair CPair;
typedef struct CProg CProg;
typedef struct CQueueInput CQueueInput;
typedef struct CQueueInputMemory CQueueInputMemory;
typedef struct CQueueOutput CQueueOutput;
typedef struct CQueueOutputIop CQueueOutputIop;
typedef struct CQueueOutputIpu CQueueOutputIpu;
typedef struct CRFODB CRFODB;
typedef struct CRITSECT CRITSECT;
typedef struct CRV CRV;
typedef struct CRVL CRVL;
typedef struct CRef CRef;
typedef struct CRichText CRichText;
typedef struct CSidebag CSidebag;
typedef struct CSplotheap CSplotheap;
typedef struct CTextBox CTextBox;
typedef struct CTransition CTransition;
typedef struct DIALOG DIALOG;
typedef struct DIFFICULTY DIFFICULTY;
typedef struct DL DL;
typedef struct DLE DLE;
typedef struct DMAS DMAS;
typedef struct DROPLET DROPLET;
typedef struct DYSH DYSH;
typedef struct DZ DZ;
typedef struct DZG DZG;
typedef struct EDGE EDGE;
typedef struct EMITB EMITB;
typedef struct EMITDV EMITDV;
typedef struct EMITG EMITG;
typedef struct EMITGEN EMITGEN;
typedef struct EMITMESH EMITMESH;
typedef struct EMITO EMITO;
typedef struct EMITRIP EMITRIP;
typedef struct EMITTER EMITTER;
typedef struct EMITV EMITV;
typedef struct EMITVX EMITVX;
typedef struct ENSK ENSK;
typedef struct EXPL EXPL;
typedef struct EXPLO EXPLO;
typedef struct EXPLS EXPLS;
typedef struct EXPLSO EXPLSO;
typedef struct EYES EYES;
typedef struct EYESS EYESS;
typedef struct FGFN FGFN;
typedef struct FLYING FLYING;
typedef struct FRAGILE FRAGILE;
typedef struct FRM FRM;
typedef struct FTAK FTAK;
typedef struct FTND FTND;
typedef struct FX FX;
typedef struct GAME GAME;
typedef struct GEOM GEOM;
typedef struct GIFS GIFS;
typedef struct GLINT GLINT;
typedef struct GLOBSET GLOBSET;
typedef struct GSB GSB;
typedef struct HBSK HBSK;
typedef struct HFDK HFDK;
typedef struct HND HND;
typedef struct HSHAPE HSHAPE;
typedef struct JOY JOY;
typedef struct JOYK JOYK;
typedef struct JOYS JOYS;
typedef struct JSG JSG;
typedef struct JSGJK JSGJK;
typedef struct JSGLK JSGLK;
typedef struct JT JT;
typedef struct LASEN LASEN;
typedef struct LEAF LEAF;
typedef struct LIGHT LIGHT;
typedef struct LM LM;
typedef struct LO LO;
typedef struct LOOP LOOP;
typedef struct LSG LSG;
typedef struct MATCH MATCH;
typedef struct MATRIX3 MATRIX3;
typedef struct MATRIX4 MATRIX4;
typedef struct MEMCARD MEMCARD;
typedef struct MJR MJR;
typedef struct MQ MQ;
typedef struct MRSG MRSG;
typedef struct MSGID MSGID;
typedef struct OID OID;
typedef struct ONZ ONZ;
typedef struct ORBIT ORBIT;
typedef struct OSTRM OSTRM;
typedef struct OTYP OTYP;
typedef struct PATHZONE PATHZONE;
typedef struct PCK PCK;
typedef struct PINGPONG PINGPONG;
typedef struct PIPE PIPE;
typedef struct PO PO;
typedef struct PROXY PROXY;
typedef struct PRSEN PRSEN;
typedef struct PUFFC PUFFC;
typedef struct QW QW;
typedef struct REMIT REMIT;
typedef struct RGBA RGBA;
typedef struct RIP RIP;
typedef struct RIPG RIPG;
typedef struct RIPT RIPT;
typedef struct RO RO;
typedef struct ROB ROB;
typedef struct ROH ROH;
typedef struct ROV ROV;
typedef struct RSMG RSMG;
typedef struct RUMBLE RUMBLE;
typedef struct RUMK RUMK;
typedef struct RUMPAT RUMPAT;
typedef struct RUMS RUMS;
typedef struct RWAC RWAC;
typedef struct RWM RWM;
typedef struct SAA SAA;
typedef struct SAAF SAAF;
typedef struct SAVE SAVE;
typedef struct SBI SBI;
typedef struct SCROLLER SCROLLER;
typedef struct SEEK SEEK;
typedef struct SENSM SENSM;
typedef struct SFX SFX;
typedef struct SGG SGG;
typedef struct SHD SHD;
typedef struct SHRAPNEL SHRAPNEL;
typedef struct SHUFFLE SHUFFLE;
typedef struct SLOTHEAP SLOTHEAP;
typedef struct SM SM;
typedef struct SMA SMA;
typedef struct SMACK SMACK;
typedef struct SMARTGUARD SMARTGUARD;
typedef struct SMP SMP;
typedef struct SMPA SMPA;
typedef struct SO SO;
typedef struct SPIRE SPIRE;
typedef struct SPLMISS SPLMISS;
typedef struct STEP STEP;
typedef struct STEPGUARD STEPGUARD;
typedef struct STUCK STUCK;
typedef struct SURF SURF;
typedef struct SUV SUV;
typedef struct SW SW;
typedef struct TAGK TAGK;
typedef struct TANK TANK;
typedef struct TARGET TARGET;
typedef struct TEX TEX;
typedef struct TFT TFT;
typedef struct TIMER TIMER;
typedef struct TIMERS TIMERS;
typedef struct TN TN;
typedef struct TNFN TNFN;
typedef struct TNS TNS;
typedef struct UBG UBG;
typedef struct UFOK UFOK;
typedef struct UL UL;
typedef struct UPK UPK;
typedef struct VECTOR VECTOR;
typedef struct VIFS VIFS;
typedef struct VOLBTN VOLBTN;
typedef struct VU_FLOAT VU_FLOAT;
typedef struct VU_VECTOR VU_VECTOR;
typedef struct VU_VECTOR4 VU_VECTOR4;
typedef struct WATER WATER;
typedef struct WID WID;
typedef struct WR WR;
typedef struct WREK WREK;
typedef struct XA XA;
typedef struct XMG XMG;
typedef struct XP XP;
typedef struct XPK XPK;
typedef struct ZPK ZPK;
typedef struct ZPR ZPR;
typedef struct sceDmaChan sceDmaChan;
typedef struct sceIpuRGB32 sceIpuRGB32;
typedef struct sceMpeg sceMpeg;
typedef struct sceMpegCbData sceMpegCbData;
typedef struct sceMpegCbDataStr sceMpegCbDataStr;

int FCanPuffcAttack(PUFFC * arg0); /* 0x114590 FCanPuffcAttack__FP5PUFFC */
void * PvAllocSlotheapClearImpl(SLOTHEAP * arg0); /* 0x116918 PvAllocSlotheapClearImpl__FP8SLOTHEAP */
/* REPAIRED for Sly 2: void * PvAllocGlobalImpl__Fi(int arg0, undefined4 in_a1) */
void * PvAllocGlobalImpl(int arg0); /* 0x116AB8 PvAllocGlobalImpl__Fi */
undefined4 EvaluateBezierPos(float arg0, float arg1, float arg2, VECTOR * arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6, VECTOR * arg7, VECTOR * arg8, VECTOR * arg9); /* 0x117120 EvaluateBezierPos__FfffP6VECTORN63 */
undefined4 InitGeom(GEOM * arg0); /* 0x1177F0 InitGeom__FP4GEOM */
undefined4 CBinaryInputStream_Align(CBinaryInputStream *this, int arg1); /* 0x117988 Align__18CBinaryInputStreami */
undefined4 CBinaryInputStream_Decompress(CBinaryInputStream *this); /* 0x1179F0 Decompress__18CBinaryInputStream */
undefined4 CBinaryInputStream_U8Read(CBinaryInputStream *this); /* 0x117BD0 U8Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_U16Read(CBinaryInputStream *this); /* 0x117C20 U16Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_U32Read(CBinaryInputStream *this); /* 0x117C80 U32Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_S8Read(CBinaryInputStream *this); /* 0x117D00 S8Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_S16Read(CBinaryInputStream *this); /* 0x117D50 S16Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_S32Read(CBinaryInputStream *this); /* 0x117DB8 S32Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_F32Read(CBinaryInputStream *this); /* 0x117E38 F32Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_ReadVector(CBinaryInputStream *this, VECTOR * arg1); /* 0x117EB0 ReadVector__18CBinaryInputStreamP6VECTOR */
undefined4 CBinaryInputStream_Unknown1(CBinaryInputStream *this); /* 0x118420 Unknown1__18CBinaryInputStream */
/* REPAIRED for Sly 2: void * PruneBsp__FP3BSPP6VECTORfPP3BSP(BSP * arg0, VECTOR * arg1, float arg2, BSP * * arg3, undefined4 in_a3, undefined4 in_t0) */
void * PruneBsp(BSP * arg0, VECTOR * arg1, float arg2, BSP * * arg3); /* 0x118A88 PruneBsp__FP3BSPP6VECTORfPP3BSP */
/* REPAIRED for Sly 2: void * PcgtPointInCbspQuick__FP4CBSPP6VECTOR(CBSP * arg0, VECTOR * arg1, undefined8 in_a2) */
void * PcgtPointInCbspQuick(CBSP * arg0, VECTOR * arg1); /* 0x118FB0 PcgtPointInCbspQuick__FP4CBSPP6VECTOR */
undefined4 CloneBspc(GEOM * arg0, BSPC * arg1, GEOM * arg2, BSPC * arg3); /* 0x1191E8 CloneBspc__FP4GEOMP4BSPCT0T1 */
undefined4 CroutDecomp(int arg0, float * arg1, float * arg2); /* 0x1195E0 CroutDecomp__FiPfT1 */
undefined4 CroutSolve(int arg0, float * arg1, float * arg2, float * arg3); /* 0x1198F8 CroutSolve__FiPfN21 */
undefined4 InitDl(DL * arg0, int arg1); /* 0x11A1F8 InitDl__FP2DLi */
undefined4 ClearDl(DL * arg0); /* 0x11A200 ClearDl__FP2DL */
undefined4 ClearDle(DLE * arg0); /* 0x11A210 ClearDle__FP3DLE */
int FIsDlEmpty(DL * arg0); /* 0x11A3B0 FIsDlEmpty__FP2DL */
int CPvDl(DL * arg0); /* 0x11A3C0 CPvDl__FP2DL */
undefined4 ClearDzgSolution(DZG * arg0); /* 0x11A6B8 ClearDzgSolution__FP3DZG */
undefined4 EnforceDzgDz(DZG * arg0, DZ * arg1); /* 0x11A770 EnforceDzgDz__FP3DZGP2DZ */
/* REPAIRED for Sly 2: undefined AddJsgContext__FP3JSG3OID(float * arg0, MATRIX4 * arg1) */
undefined4 AddJsgContext(JSG * arg0, OID arg1); /* 0x11B318 AddJsgContext__FP3JSG3OID */
undefined4 NormalizeRotateMatrix3(MATRIX3 * arg0); /* 0x11B3D0 NormalizeRotateMatrix3__FP7MATRIX3 */
undefined4 LoadRotateMatrixEuler(VECTOR * arg0, MATRIX3 * arg1); /* 0x11B628 LoadRotateMatrixEuler__FP6VECTORP7MATRIX3 */
undefined4 BuildOrthonormalMatrixY(VECTOR * arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x11B830 BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3 */
undefined4 TiltMatUpright(MATRIX3 * arg0, MATRIX3 * arg1, MATRIX3 * arg2); /* 0x11B938 TiltMatUpright__FP7MATRIX3N20 */
undefined4 DecomposeRotateMatrixPanTilt(MATRIX3 * arg0, float * arg1, float * arg2); /* 0x11BC88 DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1 */
undefined4 DecomposeRotateMatrixRad(MATRIX3 * arg0, float * arg1, VECTOR * arg2); /* 0x11BCF8 DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR */
/* SUSPECT in Sly 2: missing: reads in_a2_lo; unused: arg1 */
undefined4 op_multiply(const MATRIX4 * arg0, VU_FLOAT arg1); /* 0x11C128 __ml__FRC7MATRIX4G8VU_FLOAT */
undefined4 op_multiply_2(const MATRIX4 * arg0, VU_VECTOR4 arg1); /* 0x11C1A8 __ml__FRC7MATRIX4G10VU_VECTOR4 */
/* REPAIRED for Sly 2: int FInvertMatrix4__FP7MATRIX4T0(float * arg0, MATRIX4 * arg1) */
int FInvertMatrix4(MATRIX4 * arg0, MATRIX4 * arg1); /* 0x11C2F0 FInvertMatrix4__FP7MATRIX4T0 */
undefined4 BuildSimpleProjectionMatrix(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, MATRIX4 * arg6); /* 0x11C448 BuildSimpleProjectionMatrix__FffffffP7MATRIX4 */
/* REPAIRED for Sly 2: int FInvertMatrix__FiPfT1(int arg0, CFileLocation * arg1, float * arg2, undefined4 in_a3) */
int FInvertMatrix(int arg0, float * arg1, float * arg2); /* 0x11C500 FInvertMatrix__FiPfT1 */
undefined4 SetAloShadowShader(ALO * arg0, OID arg1); /* 0x11CDD8 SetAloShadowShader__FP3ALO3OID */
float RadNormalize(float arg0); /* 0x11CF60 RadNormalize__Ff */
float GLimitAbs(float arg0, float arg1); /* 0x11CFE0 GLimitAbs__Fff */
float GSmooth(float arg0, float arg1, float arg2, SMP * arg3, float * arg4); /* 0x11D018 GSmooth__FfffP3SMPPf */
/* REPAIRED for Sly 2: float GSmoothA__FffffP4SMPAPf(float arg0, float arg1, float arg2, float arg3, SMP * arg4, float * arg5) */
float GSmoothA(float arg0, float arg1, float arg2, float arg3, SMPA * arg4, float * arg5); /* 0x11D1C0 GSmoothA__FffffP4SMPAPf */
float RadSmooth(float arg0, float arg1, float arg2, SMP * arg3, float * arg4); /* 0x11D2D0 RadSmooth__FfffP3SMPPf */
/* REPAIRED for Sly 2: float RadSmoothA__FffffP4SMPAPf(float arg0, float arg1, float arg2, float arg3, SMP * arg4, float * arg5) */
float RadSmoothA(float arg0, float arg1, float arg2, float arg3, SMPA * arg4, float * arg5); /* 0x11D340 RadSmoothA__FffffP4SMPAPf */
int FFloatsNear(float arg0, float arg1, float arg2); /* 0x11D4D0 FFloatsNear__Ffff */
int CSolveQuadratic(float arg0, float arg1, float arg2, float * arg3); /* 0x11D508 CSolveQuadratic__FfffPf */
undefined4 PrescaleClq(CLQ * arg0, float arg1, float arg2, CLQ * arg3); /* 0x11D5B0 PrescaleClq__FP3CLQffT0 */
undefined4 CalculateSinCos(float arg0, float * arg1, float * arg2); /* 0x11D608 CalculateSinCos__FfPfT1 */
float GTrunc(double arg0); /* 0x11D740 GTrunc__Fd */
float GTrunc_2(float arg0); /* 0x11D7F0 GTrunc__Ff */
float GModPositive(float arg0, float arg1); /* 0x11D898 GModPositive__Fff */
undefined4 FitClq(float arg0, float arg1, float arg2, float arg3, CLQ * arg4); /* 0x11D8D8 FitClq__FffffP3CLQ */
int FCheckLm(LM * arg0, float arg1); /* 0x11D910 FCheckLm__FP2LMf */
float GLimitLm(LM * arg0, float arg1); /* 0x11D948 GLimitLm__FP2LMf */
undefined4 Force(void * arg0); /* 0x11D9D8 Force__FPv */
undefined4 MinimizeRange(float (*arg0)(void *, float), void * arg1, float arg2, float arg3, float arg4, float arg5, float * arg6, float * arg7); /* 0x11D9E0 MinimizeRange__FPFPvf_fPvffffPfT6 */
undefined4 ConvertHsvToRgb(VECTOR * arg0, VECTOR * arg1); /* 0x11DD90 ConvertHsvToRgb__FP6VECTORT0 */
undefined4 ConvertUserHsvToUserRgb(VECTOR * arg0, VECTOR * arg1); /* 0x11DFA0 ConvertUserHsvToUserRgb__FP6VECTORT0 */
undefined4 SetVectorCylind(VECTOR * arg0, float arg1, float arg2, float arg3); /* 0x11E1A0 SetVectorCylind__FP6VECTORfff */
undefined4 SetVectorSphere(VECTOR * arg0, float arg1, float arg2, float arg3); /* 0x11E208 SetVectorSphere__FP6VECTORfff */
/* REPAIRED for Sly 2: float SProjectVector__FP6VECTORT0(VECTOR * arg0, VECTOR * arg1, undefined8 in_a2, undefined8 in_a3) */
float SProjectVector(VECTOR * arg0, VECTOR * arg1); /* 0x11E290 SProjectVector__FP6VECTORT0 */
undefined4 GetNormalVectors(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x11E2D8 GetNormalVectors__FP6VECTORN30 */
float RadBetweenVectors(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x11E4B0 RadBetweenVectors__FP6VECTORN20 */
undefined4 FindClosestPointBetweenLines(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3, float * arg4, float * arg5, VECTOR * arg6); /* 0x11E630 FindClosestPointBetweenLines__FP6VECTORN30PfT4T0 */
/* REPAIRED for Sly 2: undefined FindClosestPointBetweenLineSegments__FP6VECTORN40PfT0(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3, float * arg4, float * arg5, VECTOR * arg6) */
undefined4 FindClosestPointBetweenLineSegments(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, VECTOR * arg6); /* 0x11E7C8 FindClosestPointBetweenLineSegments__FP6VECTORN40PfT0 */
undefined4 CalculateVectorPanTilt(VECTOR * arg0, float * arg1, float * arg2); /* 0x11E958 CalculateVectorPanTilt__FP6VECTORPfT1 */
undefined4 LimitVectorLength(VECTOR * arg0, float arg1, VECTOR * arg2); /* 0x11E9F8 LimitVectorLength__FP6VECTORfT0 */
undefined4 RefOpG(int arg0, CRef * arg1, CFrame * arg2); /* 0x1204E8 RefOpG__FiP4CRefP6CFrame */
undefined4 RefOpGE(int arg0, CRef * arg1, CFrame * arg2); /* 0x120518 RefOpGE__FiP4CRefP6CFrame */
undefined4 RefOpEqual(int arg0, CRef * arg1, CFrame * arg2); /* 0x1207F0 RefOpEqual__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined SubscribeLoStruct__FP2LOPFPv5MSGIDPv_vPv(CRef * arg0, void * arg1, void * arg2) */
undefined4 SubscribeLoStruct(LO * arg0, void (*arg1)(void *, MSGID, void *), void * arg2); /* 0x120BD0 SubscribeLoStruct__FP2LOPFPv5MSGIDPv_vPv */
/* REPAIRED for Sly 2: undefined RefOpList__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, TAGK arg2) */
undefined4 RefOpList(int arg0, CRef * arg1, CFrame * arg2); /* 0x120F80 RefOpList__FiP4CRefP6CFrame */
undefined4 RefUfo(CRef * arg0, UFOK arg1); /* 0x1224A8 RefUfo__FP4CRef4UFOK */
/* REPAIRED for Sly 2: undefined RefOpSqrt__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, UFOK arg2) */
undefined4 RefOpSqrt(int arg0, CRef * arg1, CFrame * arg2); /* 0x122530 RefOpSqrt__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined RefOpSin__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, UFOK arg2) */
undefined4 RefOpSin(int arg0, CRef * arg1, CFrame * arg2); /* 0x122560 RefOpSin__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined RefOpCos__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, UFOK arg2) */
undefined4 RefOpCos(int arg0, CRef * arg1, CFrame * arg2); /* 0x122590 RefOpCos__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined RefOpTan__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, UFOK arg2) */
undefined4 RefOpTan(int arg0, CRef * arg1, CFrame * arg2); /* 0x1225C0 RefOpTan__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined RefOpAsin__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, UFOK arg2) */
undefined4 RefOpAsin(int arg0, CRef * arg1, CFrame * arg2); /* 0x1225F0 RefOpAsin__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined RefOpAcos__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, UFOK arg2) */
undefined4 RefOpAcos(int arg0, CRef * arg1, CFrame * arg2); /* 0x122620 RefOpAcos__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined RefOpAtan__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, UFOK arg2) */
undefined4 RefOpAtan(int arg0, CRef * arg1, CFrame * arg2); /* 0x122650 RefOpAtan__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined RefOpRadNormalize__FiP4CRefP6CFrame(CRef * arg0, CRef * arg1, UFOK arg2) */
undefined4 RefOpRadNormalize(int arg0, CRef * arg1, CFrame * arg2); /* 0x122680 RefOpRadNormalize__FiP4CRefP6CFrame */
/* REPAIRED for Sly 2: undefined RefOpObjectOption__FiP4CRefP6CFrame4BIFK(CRef * arg0, CRef * arg1, CFrame * arg2, BIFK arg3) */
undefined4 RefOpObjectOption(int arg0, CRef * arg1, CFrame * arg2, BIFK arg3); /* 0x123EB0 RefOpObjectOption__FiP4CRefP6CFrame4BIFK */
/* REPAIRED for Sly 2: undefined RefEvalAssert__FP5CPairP6CFrame(CRef * arg0, CFrame * arg1) */
undefined4 RefEvalAssert(CPair * arg0, CFrame * arg1); /* 0x1265F0 RefEvalAssert__FP5CPairP6CFrame */
/* REPAIRED for Sly 2: undefined RefEvalIf__FP5CPairP6CFrame(CRef * arg0, CFrame * arg1) */
undefined4 RefEvalIf(CPair * arg0, CFrame * arg1); /* 0x126758 RefEvalIf__FP5CPairP6CFrame */
/* REPAIRED for Sly 2: undefined RefEvalOr__FP5CPairP6CFrame(CRef * arg0, CFrame * arg1) */
undefined4 RefEvalOr(CPair * arg0, CFrame * arg1); /* 0x126840 RefEvalOr__FP5CPairP6CFrame */
/* REPAIRED for Sly 2: undefined RefEvalAnd__FP5CPairP6CFrame(CRef * arg0, CFrame * arg1) */
undefined4 RefEvalAnd(CPair * arg0, CFrame * arg1); /* 0x126928 RefEvalAnd__FP5CPairP6CFrame */
/* REPAIRED for Sly 2: undefined RefEvalCond__FP5CPairP6CFrame(CRef * arg0, CFrame * arg1) */
undefined4 RefEvalCond(CPair * arg0, CFrame * arg1); /* 0x126A18 RefEvalCond__FP5CPairP6CFrame */
undefined4 RefEvalCase(CPair * arg0, CFrame * arg1); /* 0x126BA0 RefEvalCase__FP5CPairP6CFrame */
/* REPAIRED for Sly 2: undefined RefEvalWhile__FP5CPairP6CFrame(CRef * arg0, CFrame * arg1) */
undefined4 RefEvalWhile(CPair * arg0, CFrame * arg1); /* 0x126F78 RefEvalWhile__FP5CPairP6CFrame */
/* REPAIRED for Sly 2: undefined RefSetBinding__6CFrameUiP4CRef(CRef * this_, CFrame * arg1, uint arg2, undefined4 in_a3) */
undefined4 CFrame_RefSetBinding(CFrame *this, unsigned int arg1, CRef * arg2); /* 0x127CF0 RefSetBinding__6CFrameUiP4CRef */
int CFrame_FFindBinding(CFrame *this, unsigned int arg1, int arg2, CRef * arg3); /* 0x127D78 FFindBinding__6CFrameUiiP4CRef */
void * CFrame_PrefFindBinding(CFrame *this, unsigned int arg1, int arg2); /* 0x127DB8 PrefFindBinding__6CFrameUii */
undefined4 CRef_SetTag(CRef *this, TAGK arg1); /* 0x1291A8 SetTag__4CRef4TAGK */
undefined4 CRef_op_assign(CRef *this, const CRef * arg1); /* 0x129658 __as__4CRefRC4CRef */
undefined4 CRef_op_equal(CRef *this, const CRef * arg1); /* 0x129AC0 __eq__4CRefRC4CRef */
int CSidebag_FFindBinding(CSidebag *this, int arg1, CRef * arg2); /* 0x12AB28 FFindBinding__8CSidebagiP4CRef */
undefined4 StartupCatalog(void); /* 0x12AE18 StartupCatalog__Fv */
void * PacpNew(ACVK arg0); /* 0x12CB98 PacpNew__F4ACVK */
undefined4 ExplodeExploExplso(EXPLO * arg0, EXPLSO * arg1); /* 0x12CC60 ExplodeExploExplso__FP5EXPLOP6EXPLSO */
undefined4 LoadExploFromBrx(EXPLO * arg0, CBinaryInputStream * arg1); /* 0x12CCB8 LoadExploFromBrx__FP5EXPLOP18CBinaryInputStream */
undefined4 GetActlaRotationGoal(ACTLA * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x12D220 GetActlaRotationGoal__FP5ACTLAfP7MATRIX3P6VECTOR */
undefined4 GetActPositionGoal(ACT * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x12D4D8 GetActPositionGoal__FP3ACTfP6VECTORT2 */
/* REPAIRED for Sly 2: undefined DupAloRo__FP3ALOP2ROT1(ALO * arg0, VECTOR * arg1, VECTOR * arg2, float in_f12) */
undefined4 DupAloRo(ALO * arg0, RO * arg1, RO * arg2); /* 0x12E060 DupAloRo__FP3ALOP2ROT1 */
undefined4 InitAccmiss(ACCMISS * arg0); /* 0x12E600 InitAccmiss__FP7ACCMISS */
undefined4 CloneProxy(PROXY * arg0, PROXY * arg1); /* 0x12EC50 CloneProxy__FP5PROXYT0 */
undefined4 InitAseg(ASEG * arg0); /* 0x12F248 InitAseg__FP4ASEG */
undefined4 TFindAsegLabel(ASEG * arg0, OID arg1); /* 0x12F990 TFindAsegLabel__FP4ASEG3OID */
void * PasegaFindAseg(ASEG * arg0, ALO * arg1); /* 0x1304A8 PasegaFindAseg__FP4ASEGP3ALO */
undefined4 EnsureAseg(ASEG * arg0, ALO * arg1, SEEK arg2, float arg3, float arg4, int arg5, ASEGA * * arg6); /* 0x1304E0 EnsureAseg__FP4ASEGP3ALO4SEEKffiPP5ASEGA */
void * PasegaEnsureAseg(ASEG * arg0, ALO * arg1, SEEK arg2, float arg3, float arg4, int arg5); /* 0x130598 PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi */
undefined4 UpdateAsegaIeaCur(ASEGA * arg0); /* 0x130EB0 UpdateAsegaIeaCur__FP5ASEGA */
undefined4 SetAsegaPriority(ASEGA * arg0, int arg1); /* 0x131A40 SetAsegaPriority__FP5ASEGAi */
/* REPAIRED for Sly 2: void __18CBinaryAsyncStreamPv(CBinaryAsyncStream * this_, void * arg1, undefined4 in_a2) */
void CBinaryAsyncStream_constructor(CBinaryAsyncStream *this, void * arg1); /* 0x132570 __18CBinaryAsyncStreamPv */
/* REPAIRED for Sly 2: void _$_18CBinaryAsyncStream(CBinaryAsyncStream * this_, undefined4 in_a1) */
void CBinaryAsyncStream_destructor(CBinaryAsyncStream *this); /* 0x1325B8 _$_18CBinaryAsyncStream */
int CBinaryAsyncStream_FOpenSector(CBinaryAsyncStream *this, unsigned int arg1, unsigned int arg2); /* 0x132640 FOpenSector__18CBinaryAsyncStreamUiUi */
undefined4 CBinaryAsyncStream_Close(CBinaryAsyncStream *this); /* 0x132688 Close__18CBinaryAsyncStream */
undefined4 CBinaryAsyncStream_StartSpooling(CBinaryAsyncStream *this); /* 0x132710 StartSpooling__18CBinaryAsyncStream */
int CBinaryAsyncStream_FSpooling(CBinaryAsyncStream *this); /* 0x1327D0 FSpooling__18CBinaryAsyncStream */
int CBinaryAsyncStream_FSpoolingComplete(CBinaryAsyncStream *this); /* 0x1327E0 FSpoolingComplete__18CBinaryAsyncStream */
undefined4 CBinaryAsyncStream_FinishSpooling(CBinaryAsyncStream *this); /* 0x1328A8 FinishSpooling__18CBinaryAsyncStream */
undefined4 CBinaryAsyncStream_Spool(CBinaryAsyncStream *this); /* 0x132930 Spool__18CBinaryAsyncStream */
undefined4 CBinaryAsyncStream_Skip(CBinaryAsyncStream *this, int arg1); /* 0x132998 Skip__18CBinaryAsyncStreami */
undefined4 OnLoAdd(LO * arg0); /* 0x132B00 OnLoAdd__FP2LO */
undefined4 EnableLasen(LASEN * arg0, SENSM arg1); /* 0x133340 EnableLasen__FP5LASEN5SENSM */
undefined4 UpdateSwAaox(SW * arg0); /* 0x133E80 UpdateSwAaox__FP2SW */
undefined4 FillBlAmrsg(int arg0, int arg1, void * arg2, int arg3, int arg4, OID * arg5); /* 0x137FB8 FillBlAmrsg__FiiPviiP3OID */
/* REPAIRED for Sly 2: undefined CalculateBlendAmrsg__FiiPviiP4MRSGPf(int arg0, int arg1, void * arg2, int arg3, int arg4, MRSG * arg5, float * arg6, float in_f12) */
undefined4 CalculateBlendAmrsg(int arg0, int arg1, void * arg2, int arg3, int arg4, MRSG * arg5, float * arg6); /* 0x1380F0 CalculateBlendAmrsg__FiiPviiP4MRSGPf */
undefined4 ImrsgLookUp(float arg0, float arg1, int arg2, MRSG * arg3, float * arg4); /* 0x138370 ImrsgLookUp__FffiP4MRSGPf */
undefined4 EvaluateAcsb(ACSB * arg0, ALO * arg1, float arg2, int arg3, MATRIX3 * arg4); /* 0x138660 EvaluateAcsb__FP4ACSBP3ALOfiP7MATRIX3 */
/* REPAIRED for Sly 2: undefined BuildBlipAqwGifs__FiPP2QW(int arg0, QW * arg1) */
undefined4 BuildBlipAqwGifs(int arg0, QW * * arg1); /* 0x138F08 BuildBlipAqwGifs__FiPP2QW */
undefined4 StartupBlips(void); /* 0x138FC0 StartupBlips__Fv */
/* REPAIRED for Sly 2: void * PblipNew__FP5BLIPG(BLIPG * arg0, undefined4 in_a1) */
void * PblipNew(BLIPG * arg0); /* 0x138FF8 PblipNew__FP5BLIPG */
undefined4 RemoveBlip(BLIP * arg0); /* 0x139098 RemoveBlip__FP4BLIP */
undefined4 OnBlipgRemove(BLIPG * arg0); /* 0x139250 OnBlipgRemove__FP5BLIPG */
undefined4 PropagateBlipgShader(BLIPG * arg0); /* 0x139370 PropagateBlipgShader__FP5BLIPG */
undefined4 SetBlipgEmitb(BLIPG * arg0, EMITB * arg1); /* 0x1394C8 SetBlipgEmitb__FP5BLIPGP5EMITB */
undefined4 SubscribeBlipgObject(BLIPG * arg0, LO * arg1); /* 0x139900 SubscribeBlipgObject__FP5BLIPGP2LO */
undefined4 CblipeProjectBlipTransformAccel(MATRIX4 * arg0, VU_FLOAT arg1, BLIPP * arg2, BLIPV * arg3, BLIPX * arg4, int arg5, BLIPOK arg6, VECTOR * arg7, VECTOR * arg8); /* 0x139950 CblipeProjectBlipTransformAccel__FP7MATRIX4G8VU_FLOATP5BLIPPP5BLIPVP5BLIPXi6BLIPOKP6VECTORT7 */
/* REPAIRED for Sly 2: void * ProjectBlipgTransformAccel__FP5BLIPGf(BLIPG * arg0, float arg1, undefined4 in_a1, undefined4 in_a2, undefined4 in_a3, undefined4 in_t0, undefined4 in_t1, undefined4 in_t2, undefined4 in_t3) */
void * ProjectBlipgTransformAccel(BLIPG * arg0, float arg1); /* 0x139AB8 ProjectBlipgTransformAccel__FP5BLIPGf */
/* REPAIRED for Sly 2: void * ProjectBlipgTransform__FP5BLIPGfi(BLIPG * arg0, float arg1, int arg2, undefined4 in_a2, undefined4 in_a3, undefined4 in_t0, undefined4 in_t1, undefined4 in_t2, undefined4 in_t3) */
void * ProjectBlipgTransform(BLIPG * arg0, float arg1, int arg2); /* 0x139DC0 ProjectBlipgTransform__FP5BLIPGfi */
undefined4 SetLightDiffuse_Old(LIGHT * arg0, float arg1); /* 0x13AA70 SetLightDiffuse_Old__FP5LIGHTf */
undefined4 HandleBombMessage(BOMB * arg0, MSGID arg1, void * arg2); /* 0x13AAE8 HandleBombMessage__FP4BOMB5MSGIDPv */
undefined4 UpdateBomb(BOMB * arg0, float arg1); /* 0x13AB58 UpdateBomb__FP4BOMBf */
void * PrimeBomb(BOMB * arg0, float arg1); /* 0x13B5C8 PrimeBomb__FP4BOMBf */
undefined4 InitCrfodb(CRFODB * arg0); /* 0x13CEB8 InitCrfodb__FP6CRFODB */
void * PostCrfodbLoad(CRFODB * arg0); /* 0x13CEF8 PostCrfodbLoad__FP6CRFODB */
undefined4 CByteQueue_Init(CByteQueue *this, int arg1, void * arg2); /* 0x13D558 Init__10CByteQueueiPv */
undefined4 CByteQueue_Reset(CByteQueue *this); /* 0x13D580 Reset__10CByteQueue */
undefined4 CByteQueue_CbFill(CByteQueue *this, int arg1, CQueueInput * arg2); /* 0x13D5A0 CbFill__10CByteQueueiP11CQueueInput */
undefined4 CByteQueue_CbDrain(CByteQueue *this, int arg1, CQueueOutput * arg2); /* 0x13D6A8 CbDrain__10CByteQueueiP12CQueueOutput */
undefined4 CByteQueue_CbFill_2(CByteQueue *this, int arg1, unsigned char * arg2); /* 0x13D7D0 CbFill__10CByteQueueiPUc */
undefined4 CByteQueue_FreeDrain(CByteQueue *this, int arg1); /* 0x13D818 FreeDrain__10CByteQueuei */
undefined4 CQueueInputMemory_CbRead(CQueueInputMemory *this, int arg1, void * arg2); /* 0x13D850 CbRead__17CQueueInputMemoryiPv */
undefined4 LoadOptionsFromBrx(void * arg0, CBinaryInputStream * arg1); /* 0x13F810 LoadOptionsFromBrx__FPvP18CBinaryInputStream */
undefined4 InitLasen(LASEN * arg0); /* 0x144B28 InitLasen__FP5LASEN */
undefined4 RetractActseg(ACTSEG * arg0, int arg1); /* 0x147EE8 RetractActseg__FP6ACTSEGi */
undefined4 SetBtnButtons(BTN * arg0, BUTTONS arg1); /* 0x148A78 SetBtnButtons__FP3BTN7BUTTONS */
/* REPAIRED for Sly 2: undefined SetAlarmRsmg__FP5ALARMi3OIDN22(ALARM * arg0, OID arg1, OID arg2, OID arg3, OID arg4) */
undefined4 SetAlarmRsmg(ALARM * arg0, int arg1, OID arg2, OID arg3, OID arg4); /* 0x148B38 SetAlarmRsmg__FP5ALARMi3OIDN22 */
undefined4 LoadVolbtnFromBrx(VOLBTN * arg0, CBinaryInputStream * arg1); /* 0x149358 LoadVolbtnFromBrx__FP6VOLBTNP18CBinaryInputStream */
undefined4 CloneVolbtn(VOLBTN * arg0, VOLBTN * arg1); /* 0x1493F8 CloneVolbtn__FP6VOLBTNT0 */
undefined4 CpchzTokenizePath(char * arg0); /* 0x14B7F8 CpchzTokenizePath__FPc */
int FValidCdMmode(void); /* 0x14B9C0 FValidCdMmode__Fv */
undefined4 SetCdMmode(void); /* 0x14BA00 SetCdMmode__Fv */
undefined4 UpdateCd(void); /* 0x14BA38 UpdateCd__Fv */
undefined4 CdPath(char * arg0, char * arg1, int arg2); /* 0x14BBB0 CdPath__FPcT0i */
/* REPAIRED for Sly 2: undefined ReadCdDirect__FUiUiPv(uint arg0, uint arg1, void * arg2, undefined4 in_a3) */
undefined4 ReadCdDirect(unsigned int arg0, unsigned int arg1, void * arg2); /* 0x14BC78 ReadCdDirect__FUiUiPv */
int FCdCompleted(int arg0); /* 0x14BD30 FCdCompleted__Fi */
undefined4 CSplotheap_UnmarkAll(CSplotheap *this); /* 0x14BF18 UnmarkAll__10CSplotheap */
/* REPAIRED for Sly 2: undefined _MatchCodes__FP3JOYUs(JOY * arg0, ushort arg1, undefined4 in_a2) */
undefined4 _MatchCodes(JOY * arg0, unsigned short arg1); /* 0x14BF48 _MatchCodes__FP3JOYUs */
/* REPAIRED for Sly 2: undefined ClsgClipEdgeToObject__FP2SOP6VECTORT1iP3LSG(SO * arg0, VECTOR * arg1, VECTOR * arg2, VU_VECTOR arg3, int arg4, int in_t1) */
/* SUSPECT in Sly 2: missing: reads in_t1_lo; unused: arg3 */
undefined4 ClsgClipEdgeToObject(SO * arg0, VECTOR * arg1, VECTOR * arg2, int arg3, LSG * arg4); /* 0x14C6D8 ClsgClipEdgeToObject__FP2SOP6VECTORT1iP3LSG */
undefined4 ClsgClipEdgeToSphere(VECTOR * arg0, float arg1, VECTOR * arg2, VECTOR * arg3, int arg4, LSG * arg5); /* 0x14C748 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG */
void * PsoHitTestLineObjects(int arg0, VECTOR * arg1, VECTOR * arg2, int arg3, SO * * arg4, LSG * arg5); /* 0x14CC58 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG */
/* REPAIRED for Sly 2: undefined MarkClockTick__FP5CLOCK(CLOCK * arg0, undefined4 in_a1) */
undefined4 MarkClockTick(CLOCK * arg0); /* 0x14D0B8 MarkClockTick__FP5CLOCK */
undefined4 SetResetFlag(CM * arg0); /* 0x14D8C0 SetResetFlag__FP2CM */
undefined4 RecalcCmFrustrum(CM * arg0); /* 0x14DB70 RecalcCmFrustrum__FP2CM */
undefined4 CFontBrx_CopyTo(CFontBrx *this, CFontBrx * arg1); /* 0x14E168 CopyTo__8CFontBrxP8CFontBrx */
/* REPAIRED for Sly 2: undefined BuildCmFgfn__FP2CMfP4FGFN(CM * arg0, float arg1, float * arg2) */
undefined4 BuildCmFgfn(CM * arg0, float arg1, FGFN * arg2); /* 0x14E270 BuildCmFgfn__FP2CMfP4FGFN */
undefined4 SetCmPolicy(CM * arg0, CPP arg1, CPLCY * arg2, SO * arg3, void * arg4); /* 0x14E328 SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv */
undefined4 RevokeCmPolicy(CM * arg0, int arg1, CPP arg2, CPLCY * arg3, SO * arg4, void * arg5); /* 0x14E4C8 RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv */
/* REPAIRED for Sly 2: undefined CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(VECTOR * arg0, SO * arg1, CPDEFI * arg2, VECTOR * arg3) */
undefined4 CalcCmAdjust(CM * arg0, SO * arg1, CPDEFI * arg2, VECTOR * arg3); /* 0x14E698 CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR */
undefined4 SpringCm(float arg0, float arg1, float arg2, CM * arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6); /* 0x14E6D0 SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR */
/* REPAIRED for Sly 2: undefined AdjustCmCpdefi__FP2CMP2SOfP6CPDEFI(VECTOR * arg0, SO * arg1, float arg2, SO * arg3, undefined4 in_a3) */
/* SUSPECT in Sly 2: conflict: arg3 SO * -> CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR arg2 CPDEFI *; conflict: arg0 VECTOR * -> SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR arg3 CM *; conflict: arg0 VECTOR * -> SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR arg3 CM *; conflict: arg0 VECTOR * -> SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR arg3 CM *; conflict: arg0 VECTOR * -> SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR arg3 CM *; conflict: arg0 VECTOR * -> SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR arg3 CM *; conflict: arg0 VECTOR * -> SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR arg3 CM *; unused: arg2 */
undefined4 AdjustCmCpdefi(CM * arg0, SO * arg1, float arg2, CPDEFI * arg3); /* 0x14E768 AdjustCmCpdefi__FP2CMP2SOfP6CPDEFI */
/* REPAIRED for Sly 2: undefined ResetCmAdjust__FP2CMP2SOP6CPDEFI(VECTOR * arg0, SO * arg1, CPDEFI * arg2, undefined4 in_a3) */
undefined4 ResetCmAdjust(CM * arg0, SO * arg1, CPDEFI * arg2); /* 0x14E920 ResetCmAdjust__FP2CMP2SOP6CPDEFI */
/* REPAIRED for Sly 2: undefined GetCmCpdefi__FP2CMP2SOfP6CPDEFI(VECTOR * arg0, SO * arg1, float arg2, SO * arg3) */
undefined4 GetCmCpdefi(CM * arg0, SO * arg1, float arg2, CPDEFI * arg3); /* 0x14E968 GetCmCpdefi__FP2CMP2SOfP6CPDEFI */
undefined4 SetCmRgbaFog(CM * arg0, RGBA * arg1); /* 0x14F6F0 SetCmRgbaFog__FP2CMP4RGBA */
undefined4 SetCptn(CPTN * arg0, void * arg1); /* 0x14FD30 SetCptn__FP4CPTNPv */
undefined4 RevokeCptn(CPTN * arg0, void * arg1); /* 0x14FD38 RevokeCptn__FP4CPTNPv */
undefined4 RenderSmack(SMACK * arg0, CM * arg1); /* 0x151950 RenderSmack__FP5SMACKP2CM */
void * PchzFriendlyFromWid(WID arg0); /* 0x154158 PchzFriendlyFromWid__F3WID */
undefined4 OnDifficultyGameLoad(DIFFICULTY * arg0); /* 0x154A60 OnDifficultyGameLoad__FP10DIFFICULTY */
/* REPAIRED for Sly 2: int FUN_001dd9a0__Ff(float arg0, undefined4 in_a0) */
int FUN_001dd9a0(float arg0); /* 0x154D88 FUN_001dd9a0__Ff */
undefined4 ChangeSuck(float arg0, DIFFICULTY * arg1); /* 0x154DC8 ChangeSuck__FfP10DIFFICULTY */
/* REPAIRED for Sly 2: float SFromCrvlU__FP4CRVLf(CRVL * arg0, float arg1, undefined4 in_a1) */
float SFromCrvlU(CRVL * arg0, float arg1); /* 0x155228 SFromCrvlU__FP4CRVLf */
undefined4 SetLoSuckHideLimits(LO * arg0, LM * arg1); /* 0x156918 SetLoSuckHideLimits__FP2LOP2LM */
undefined4 StartupDma(void); /* 0x157200 StartupDma__Fv */
void DMAS_constructor(DMAS *this); /* 0x157278 __4DMAS */
undefined4 DMAS_Clear(DMAS *this); /* 0x1572B8 Clear__4DMAS */
undefined4 DMAS_Reset(DMAS *this); /* 0x1572D0 Reset__4DMAS */
undefined4 DMAS_AllocStack(DMAS *this, int arg1); /* 0x1572E0 AllocStack__4DMASi */
undefined4 DMAS_AllocStatic(DMAS *this, int arg1, QW * arg2); /* 0x157330 AllocStatic__4DMASiP2QW */
undefined4 DMAS_Detach(DMAS *this, int * arg1, QW * * arg2); /* 0x157348 Detach__4DMASPiPP2QW */
undefined4 DMAS_AddDmaCnt(DMAS *this); /* 0x1574B8 AddDmaCnt__4DMAS */
undefined4 DMAS_AddDmaRefs(DMAS *this, int arg1, QW * arg2); /* 0x157500 AddDmaRefs__4DMASiP2QW */
undefined4 DMAS_AddDmaCall(DMAS *this, QW * arg1); /* 0x157598 AddDmaCall__4DMASP2QW */
undefined4 DMAS_AddDmaRet(DMAS *this); /* 0x157620 AddDmaRet__4DMAS */
undefined4 DMAS_AddDmaBulk(DMAS *this, int arg1, QW * arg2); /* 0x157660 AddDmaBulk__4DMASiP2QW */
undefined4 DMAS_AddDmaEnd(DMAS *this); /* 0x1576B0 AddDmaEnd__4DMAS */
undefined4 DMAS_EndDmaCnt(DMAS *this); /* 0x1576F0 EndDmaCnt__4DMAS */
/* REPAIRED for Sly 2: undefined AppendDzgDz__FP3DZGP2DZ(DZG * arg0, DZ * arg1, undefined4 in_a2) */
undefined4 AppendDzgDz(DZG * arg0, DZ * arg1); /* 0x158668 AppendDzgDz__FP3DZGP2DZ */
undefined4 SolveDzg(DZG * arg0, int arg1, int arg2, XP * * arg3, int * arg4, SO * * * arg5); /* 0x158988 SolveDzg__FP3DZGiiPP2XPPiPPP2SO */
undefined4 SolveDzgFric(DZG * arg0, int arg1, int arg2, XP * * arg3, int * arg4, SO * * * arg5, float arg6); /* 0x158B20 SolveDzgFric__FP3DZGiiPP2XPPiPPP2SOf */
undefined4 InitEmitter(EMITTER * arg0); /* 0x1591B0 InitEmitter__FP7EMITTER */
undefined4 LoadEmitmeshFromBrx(EMITMESH * arg0, CBinaryInputStream * arg1); /* 0x159240 LoadEmitmeshFromBrx__FP8EMITMESHP18CBinaryInputStream */
void * PostEmitterLoad(EMITTER * arg0); /* 0x159500 PostEmitterLoad__FP7EMITTER */
undefined4 ModifyEmitterParticles(EMITTER * arg0); /* 0x159A20 ModifyEmitterParticles__FP7EMITTER */
undefined4 UpdateEmitter(EMITTER * arg0, float arg1); /* 0x159C80 UpdateEmitter__FP7EMITTERf */
void * PauseEmitter(EMITTER * arg0, float arg1); /* 0x15A138 PauseEmitter__FP7EMITTERf */
void * PauseEmitterIndefinite(EMITTER * arg0); /* 0x15A150 PauseEmitterIndefinite__FP7EMITTER */
undefined4 UnpauseEmitter(EMITTER * arg0); /* 0x15A160 UnpauseEmitter__FP7EMITTER */
int FPausedEmitter(EMITTER * arg0); /* 0x15A170 FPausedEmitter__FP7EMITTER */
undefined4 OnEmitterValuesChanged(EMITTER * arg0); /* 0x15A1C0 OnEmitterValuesChanged__FP7EMITTER */
undefined4 SetEmitterEnabled(EMITTER * arg0, int arg1); /* 0x15A240 SetEmitterEnabled__FP7EMITTERi */
undefined4 WakeSoWater(SO * arg0, WATER * arg1, float arg2, VECTOR * arg3, VECTOR * arg4, float arg5, float arg6); /* 0x15A2C0 WakeSoWater__FP2SOP5WATERfP6VECTORT3ff */
undefined4 ConvertEmitoPosVec(EMITO * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x15AD48 ConvertEmitoPosVec__FP5EMITOP6VECTORT1 */
undefined4 CalculateEmitvx(int arg0, LM * arg1, int arg2, EMITVX * arg3); /* 0x15AE38 CalculateEmitvx__FiP2LMiP6EMITVX */
/* REPAIRED for Sly 2: undefined ChooseEmitVelocity__FP6EMITVXffP2LMP6VECTORiT4(VECTOR * arg0, float arg1, float arg2, LM * arg3, VECTOR * arg4, int arg5, VECTOR * arg6) */
undefined4 ChooseEmitVelocity(EMITVX * arg0, float arg1, float arg2, LM * arg3, VECTOR * arg4, int arg5, VECTOR * arg6); /* 0x15AF08 ChooseEmitVelocity__FP6EMITVXffP2LMP6VECTORiT4 */
/* REPAIRED for Sly 2: undefined ChooseEmitvVelocityAge__FP5EMITVP6EMITVXP5EMITOiP6VECTORN24PfT7(LM * arg0, VECTOR * arg1, EMITO * arg2, int arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6, float * arg7, float * arg8) */
undefined4 ChooseEmitvVelocityAge(EMITV * arg0, EMITVX * arg1, EMITO * arg2, int arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6, float * arg7, float * arg8); /* 0x15B0C8 ChooseEmitvVelocityAge__FP5EMITVP6EMITVXP5EMITOiP6VECTORN24PfT7 */
undefined4 EmitRips(EMITB * arg0, EMITG * arg1, int arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, float * arg6); /* 0x15B1B0 EmitRips__FP5EMITBP5EMITGiP6VECTORT3PfT5 */
undefined4 EmitBlips(EMITB * arg0, EMITG * arg1, int arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, float * arg6, VECTOR * arg7, VECTOR * arg8); /* 0x15B428 EmitBlips__FP5EMITBP5EMITGiP6VECTORT3PfT5T3T3 */
/* REPAIRED for Sly 2: undefined OriginateParticles__FiP5EMITBP7EMITGEN(int arg0, EMITO * arg1, EMITGEN * arg2) */
undefined4 OriginateParticles(int arg0, EMITB * arg1, EMITGEN * arg2); /* 0x15B7E8 OriginateParticles__FiP5EMITBP7EMITGEN */
undefined4 OriginateSplineSinkParticles(int arg0, EMITB * arg1, EMITGEN * arg2, EMITGEN * arg3); /* 0x15B9F0 OriginateSplineSinkParticles__FiP5EMITBR7EMITGENT2 */
/* REPAIRED for Sly 2: undefined EmitParticles__FiP5EMITBP5EMITG(int arg0, CFileLocation * arg1, EMITG * arg2) */
/* SUSPECT in Sly 2: conflict: arg1 CFileLocation * -> OriginateParticles__FiP5EMITBP7EMITGEN arg1 EMITO *; conflict: arg1 CFileLocation * -> EmitRips__FP5EMITBP5EMITGiP6VECTORT3PfT5 arg0 EMITB *; conflict: arg1 CFileLocation * -> OriginateSplineSinkParticles__FiP5EMITBR7EMITGENT2 arg1 EMITB *; conflict: arg1 CFileLocation * -> EmitBlips__FP5EMITBP5EMITGiP6VECTORT3PfT5T3T3 arg0 EMITB * */
undefined4 EmitParticles(int arg0, EMITB * arg1, EMITG * arg2); /* 0x15BD20 EmitParticles__FiP5EMITBP5EMITG */
undefined4 EmitRipsSphere(VECTOR * arg0, VECTOR * arg1, int arg2, EMITRIP * arg3, EMITV * arg4, RIPG * * arg5, LO * arg6); /* 0x15BE28 EmitRipsSphere__FP6VECTORT0iP7EMITRIPP5EMITVPP4RIPGP2LO */
undefined4 SetEmitdvEmitb(EMITDV * arg0, EMITB * arg1); /* 0x15BF40 SetEmitdvEmitb__FP6EMITDVP5EMITB */
undefined4 ExplodeExplParams(EXPL * arg0, unsigned int arg1, ALO * arg2, VECTOR * arg3, VECTOR * arg4, float arg5, float arg6); /* 0x15C198 ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff */
undefined4 CollectSuvPrize(SUV * arg0, PCK arg1, ALO * arg2); /* 0x15C5C8 CollectSuvPrize__FP3SUV3PCKP3ALO */
/* REPAIRED for Sly 2: void * PsfxEnsureBomb__FP4BOMB4ENSK(SFX * * arg0, ENSK arg1) */
void * PsfxEnsureBomb(BOMB * arg0, ENSK arg1); /* 0x15C650 PsfxEnsureBomb__FP4BOMB4ENSK */
undefined4 FireExplsExplso(EXPLS * arg0, EXPLSO * arg1); /* 0x15C690 FireExplsExplso__FP5EXPLSP6EXPLSO */
undefined4 CFont_CleanupDraw(CFont *this, CTextBox * arg1, GIFS * arg2); /* 0x15F000 CleanupDraw__5CFontP8CTextBoxP4GIFS */
void * CFont_PushScaling(CFont *this, float arg1, float arg2); /* 0x15F078 PushScaling__5CFontff */
void * CFont_PopScaling(CFont *this); /* 0x15F0C0 PopScaling__5CFont */
undefined4 CFontBrx_DxFromCh(CFontBrx *this, char arg1); /* 0x15F0F0 DxFromCh__8CFontBrxc */
int CFontBrx_FEnsureLoaded(CFontBrx *this, GIFS * arg1); /* 0x15F148 FEnsureLoaded__8CFontBrxP4GIFS */
undefined4 CFontBrx_SetupDraw(CFontBrx *this, CTextBox * arg1, GIFS * arg2); /* 0x15F220 SetupDraw__8CFontBrxP8CTextBoxP4GIFS */
undefined4 CFontBrx_SwitchTex0(CFontBrx *this, GIFS * arg1); /* 0x15F3E8 SwitchTex0__8CFontBrxP4GIFS */
undefined4 CFontBrx_DxDrawCh(CFontBrx *this, char arg1, float arg2, float arg3, unsigned int arg4, GIFS * arg5); /* 0x15F480 DxDrawCh__8CFontBrxcffUiP4GIFS */
void * CFontBrx_PglyffFromCh(CFontBrx *this, char arg1); /* 0x15F8A8 PglyffFromCh__8CFontBrxc */
void CRichText_constructor(CRichText *this, char * arg1, CFont * arg2); /* 0x15F928 __9CRichTextPcP5CFont */
undefined4 CRichText_Reset(CRichText *this); /* 0x15F970 Reset__9CRichText */
undefined4 CRichText_SetBaseColor(CRichText *this, RGBA * arg1); /* 0x15F9A8 SetBaseColor__9CRichTextP4RGBA */
undefined4 CRichText_ChNext(CRichText *this); /* 0x15F9D0 ChNext__9CRichText */
undefined4 CRichText_ClineWrap(CRichText *this, float arg1); /* 0x15FD68 ClineWrap__9CRichTextf */
undefined4 CRichText_DxMaxLine(CRichText *this); /* 0x15FF40 DxMaxLine__9CRichText */
undefined4 CRichText_Draw(CRichText *this, CTextBox * arg1, CTextBox * arg2, GIFS * arg3); /* 0x15FFD0 Draw__9CRichTextP8CTextBoxT1P4GIFS */
undefined4 OpenFrame(void); /* 0x160828 OpenFrame__Fv */
undefined4 EnsureVu1Code(VIFS * arg0, void * arg1, void * arg2); /* 0x160918 EnsureVu1Code__FP4VIFSPvT1 */
undefined4 FinalizeFrameVifs(VIFS * arg0, int * arg1, QW * * arg2); /* 0x160940 FinalizeFrameVifs__FP4VIFSPiPP2QW */
undefined4 FinalizeFrameGifs(GIFS * arg0, int * arg1, QW * * arg2); /* 0x160A20 FinalizeFrameGifs__FP4GIFSPiPP2QW */
undefined4 CloseFrame(void); /* 0x160A98 CloseFrame__Fv */
undefined4 FrameRenderLoop(void * arg0); /* 0x160B70 FrameRenderLoop__FPv */
undefined4 RenderFrame(FRM * arg0, int arg1); /* 0x160C80 RenderFrame__FP3FRMi */
undefined4 ClearPendingFrame(FRM * arg0); /* 0x160CE0 ClearPendingFrame__FP3FRM */
undefined4 FlushFrames(int arg0); /* 0x160E68 FlushFrames__Fi */
undefined4 BlendPrevFrame(void); /* 0x160F98 BlendPrevFrame__Fv */
/* REPAIRED for Sly 2: void * PframeNew__Fv(undefined4 in_a0) */
void * PframeNew(void); /* 0x1613F8 PframeNew__Fv */
undefined4 InitPrsen(PRSEN * arg0); /* 0x1635A0 InitPrsen__FP5PRSEN */
void GIFS_constructor(GIFS *this); /* 0x166920 __4GIFS */
undefined4 GIFS_AddPrimEnd(GIFS *this); /* 0x166968 AddPrimEnd__4GIFS */
undefined4 GIFS_EndPrim(GIFS *this, int arg1); /* 0x1669E0 EndPrim__4GIFSi */
undefined4 GIFS_CheckReg(GIFS *this, int arg1, int arg2); /* 0x166A50 CheckReg__4GIFSii */
undefined4 GIFS_AddPrimBulk(GIFS *this, int arg1, int arg2, int arg3, unsigned long arg4, QW * * arg5); /* 0x166B10 AddPrimBulk__4GIFSiiiUlPP2QW */
undefined4 GIFS_AddPrimPack(GIFS *this, int arg1, int arg2, unsigned long arg3); /* 0x166BD8 AddPrimPack__4GIFSiiUl */
void * GIFS_PackRGBA(GIFS *this, unsigned int arg1); /* 0x166C70 PackRGBA__4GIFSUi */
void * GIFS_PackUV(GIFS *this, int arg1, int arg2); /* 0x166CE0 PackUV__4GIFSii */
void * GIFS_PackSTQ(GIFS *this, float arg1, float arg2, float arg3); /* 0x166D38 PackSTQ__4GIFSfff */
void * GIFS_PackXYZ(GIFS *this, int arg1, int arg2, int arg3); /* 0x166DA0 PackXYZ__4GIFSiii */
void * GIFS_PackXYZF(GIFS *this, int arg1, int arg2, int arg3, int arg4); /* 0x166E08 PackXYZF__4GIFSiiii */
void * GIFS_PackAD(GIFS *this, long arg1, long arg2); /* 0x166E90 PackAD__4GIFSll */
undefined4 GIFS_AddPrimList(GIFS *this, int arg1, unsigned long arg2); /* 0x166EF0 AddPrimList__4GIFSiUl */
undefined4 GIFS_ListRGBAQ(GIFS *this, unsigned int arg1, float arg2); /* 0x166F70 ListRGBAQ__4GIFSUif */
undefined4 GIFS_ListUV(GIFS *this, int arg1, int arg2); /* 0x166FE8 ListUV__4GIFSii */
undefined4 GIFS_ListXYZF(GIFS *this, int arg1, int arg2, int arg3, int arg4); /* 0x1670B8 ListXYZF__4GIFSiiii */
undefined4 GIFS_AddImage(GIFS *this, int arg1); /* 0x167150 AddImage__4GIFSi */
void CRef_constructor(CRef *this); /* 0x167310 __4CRef */
undefined4 BlendDisplayOnBufferMismatch(void); /* 0x16F2D0 BlendDisplayOnBufferMismatch__Fv */
undefined4 VBlankS_Interrupt(int arg0); /* 0x16F468 VBlankS_Interrupt__Fi */
undefined4 SyncVBlank(void); /* 0x16F560 SyncVBlank__Fv */
undefined4 SwapGsBuffers(void); /* 0x16F590 SwapGsBuffers__Fv */
undefined4 RestoreGsBuffers(void); /* 0x16F6B8 RestoreGsBuffers__Fv */
float GS_Interrupt(int arg0); /* 0x16F788 GS_Interrupt__Fi */
undefined4 ResetGs(void); /* 0x16F868 ResetGs__Fv */
undefined4 SendDmaSyncGsFinish(sceDmaChan * arg0, QW * arg1); /* 0x16F8B8 SendDmaSyncGsFinish__FP10sceDmaChanP2QW */
undefined4 BuildClearGifs(QW * arg0, RGBA arg1, int arg2); /* 0x16F960 BuildClearGifs__FP2QWG4RGBAi */
undefined4 StartupGs(void); /* 0x1700D0 StartupGs__Fv */
undefined4 BlastAqwGifsBothFrames(QW * arg0); /* 0x170278 BlastAqwGifsBothFrames__FP2QW */
undefined4 ClearFrameBuffers(void); /* 0x170348 ClearFrameBuffers__Fv */
undefined4 NLog2(unsigned int arg0); /* 0x1703C0 NLog2__FUi */
undefined4 InitZpr(ZPR * arg0, ZPK arg1, LO * arg2); /* 0x1703F8 InitZpr__FP3ZPR3ZPKP2LO */
undefined4 BuildImageGifs(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, GIFS * arg6); /* 0x170650 BuildImageGifs__FiiiiiiP4GIFS */
/* REPAIRED for Sly 2: undefined UploadBitmaps__FiP3GSB(GSB * arg0, GSB * arg1) */
undefined4 UploadBitmaps(int arg0, GSB * arg1); /* 0x170730 UploadBitmaps__FiP3GSB */
undefined4 AddJsgClimb(JSG * arg0, OID arg1, float arg2, int arg3); /* 0x170C90 AddJsgClimb__FP3JSG3OIDfi */
undefined4 SetJtPuppet(JT * arg0, ASEGA * arg1); /* 0x1715B8 SetJtPuppet__FP2JTP5ASEGA */
undefined4 InitHshape(HSHAPE * arg0); /* 0x178E98 InitHshape__FP6HSHAPE */
void * PresetPuffcAccel(PUFFC * arg0, float arg1); /* 0x17CB80 PresetPuffcAccel__FP5PUFFCf */
undefined4 SetLightHighlightColor(LIGHT * arg0, VECTOR * arg1); /* 0x17DD38 SetLightHighlightColor__FP5LIGHTP6VECTOR */
undefined4 UseStepguardDeathAnimation(STEPGUARD * arg0, int arg1, OID arg2); /* 0x1800A0 UseStepguardDeathAnimation__FP9STEPGUARDi3OID */
/* REPAIRED for Sly 2: undefined UntriggerDialog__FP6DIALOG(DIALOG * arg0, undefined4 in_a1) */
undefined4 UntriggerDialog(DIALOG * arg0); /* 0x1803A8 UntriggerDialog__FP6DIALOG */
undefined4 InitHbsk(HBSK * arg0); /* 0x183900 InitHbsk__FP4HBSK */
undefined4 OnHbskRemove(HBSK * arg0); /* 0x183998 OnHbskRemove__FP4HBSK */
undefined4 OnHbskAdd(HBSK * arg0); /* 0x1839D0 OnHbskAdd__FP4HBSK */
undefined4 CloneHbsk(HBSK * arg0, HBSK * arg1); /* 0x183A08 CloneHbsk__FP4HBSKT0 */
void * PresetHbskAccel(HBSK * arg0, float arg1); /* 0x183B00 PresetHbskAccel__FP4HBSKf */
/* REPAIRED for Sly 2: void _$_3CGc(CGc * this_, undefined4 in_a1) */
void CGc_destructor(CGc *this); /* 0x184950 _$_3CGc */
void * CBinaryInputStream_PumpCd(CBinaryInputStream *this); /* 0x1849A0 PumpCd__18CBinaryInputStream */
int CBinaryInputStream_FOpenSector(CBinaryInputStream *this, unsigned int arg1, unsigned int arg2); /* 0x184D98 FOpenSector__18CBinaryInputStreamUiUi */
undefined4 InitHnd(HND * arg0); /* 0x184F50 InitHnd__FP3HND */
undefined4 InitSpire(SPIRE * arg0); /* 0x185BF8 InitSpire__FP5SPIRE */
undefined4 CloneSpire(SPIRE * arg0, SPIRE * arg1); /* 0x185C98 CloneSpire__FP5SPIRET0 */
undefined4 StartupJoy(void); /* 0x187030 StartupJoy__Fv */
undefined4 AddGrfusr(int arg0); /* 0x187078 AddGrfusr__Fi */
undefined4 RemoveGrfusr(int arg0); /* 0x1870A0 RemoveGrfusr__Fi */
undefined4 UpdateGrfjoytFromGrfusr(void); /* 0x1870D0 UpdateGrfjoytFromGrfusr__Fv */
undefined4 UpdateJoy(JOY * arg0); /* 0x1871C0 UpdateJoy__FP3JOY */
undefined4 SetJoyJoys(JOY * arg0, JOYS arg1, JOYK arg2); /* 0x1875B8 SetJoyJoys__FP3JOY4JOYS4JOYK */
undefined4 GetJoyXYDeflection(JOY * arg0, unsigned char arg1, unsigned char arg2, float * arg3, float * arg4, float * arg5, unsigned char * arg6, unsigned char * arg7, int * arg8, LM * arg9); /* 0x187768 GetJoyXYDeflection__FP3JOYUcUcPfN23PUcT6PiP2LM */
int FReadJoy(JOY * arg0); /* 0x187998 FReadJoy__FP3JOY */
/* REPAIRED for Sly 2: undefined TriggerJoyRumbleRumk__FP3JOY4RUMKf(float arg0, float arg1, float arg2, undefined4 in_a0, undefined4 in_a1) */
undefined4 TriggerJoyRumbleRumk(JOY * arg0, RUMK arg1, float arg2); /* 0x187E28 TriggerJoyRumbleRumk__FP3JOY4RUMKf */
undefined4 RebuildJtXmg(JT * arg0, ALO * arg1, float arg2, ALO * arg3, ACTADJ * arg4, XMG * arg5); /* 0x189C40 RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG */
undefined4 UpdateJtStand(JT * arg0); /* 0x18A0C8 UpdateJtStand__FP2JT */
undefined4 EnsureAloSfx(ALO * arg0); /* 0x18ED70 EnsureAloSfx__FP3ALO */
/* REPAIRED for Sly 2: undefined ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(JT * arg0, int arg1, VECTOR * arg2, float arg3, float arg4, TARGET * * arg5, VECTOR * arg6, float in_f14) */
undefined4 ChooseJtAttackTarget(JT * arg0, int arg1, VECTOR * arg2, float arg3, float arg4, TARGET * * arg5, VECTOR * arg6); /* 0x18F2B0 ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2 */
undefined4 ChooseJtSweepTarget(JT * arg0, BL * arg1, ASEGBL * arg2); /* 0x18F560 ChooseJtSweepTarget__FP2JTP2BLP6ASEGBL */
undefined4 ChooseJtRushTarget(JT * arg0); /* 0x18F688 ChooseJtRushTarget__FP2JT */
undefined4 ChooseJtSmashTarget(JT * arg0); /* 0x18F740 ChooseJtSmashTarget__FP2JT */
undefined4 AnticipateJtForce(JT * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3, FX * arg4); /* 0x18F958 AnticipateJtForce__FP2JTP2SOP6VECTORT2P2FX */
undefined4 CalculateJtHangAccel(JT * arg0); /* 0x18FC60 CalculateJtHangAccel__FP2JT */
void * PresetJtAccelHang(JT * arg0); /* 0x1903B8 PresetJtAccelHang__FP2JT */
undefined4 UpdateJtActiveHang(JT * arg0, JOY * arg1); /* 0x190520 UpdateJtActiveHang__FP2JTP3JOY */
undefined4 GetJtHangHeading(JT * arg0, float * arg1); /* 0x190BE0 GetJtHangHeading__FP2JTPf */
undefined4 MatchJtXmgRail(JT * arg0, XMG * arg1, ACTADJ * arg2); /* 0x193C98 MatchJtXmgRail__FP2JTP3XMGP6ACTADJ */
undefined4 SetJtHfdk(JT * arg0, HFDK arg1); /* 0x1940B0 SetJtHfdk__FP2JT4HFDK */
undefined4 ResetJtDynamicTunnel(JT * arg0); /* 0x194118 ResetJtDynamicTunnel__FP2JT */
void * PresetJtAccelHide(JT * arg0); /* 0x194170 PresetJtAccelHide__FP2JT */
int FCheckJtSingleEdge(JT * arg0, SO * arg1, EDGE * arg2, VECTOR * arg3); /* 0x199408 FCheckJtSingleEdge__FP2JTP2SOP4EDGEP6VECTOR */
int FCheckJtEdgeNormal(JT * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x1997D8 FCheckJtEdgeNormal__FP2JTP6VECTORT1 */
/* SUSPECT in Sly 2: missing: reads in_a2_udw */
int FCheckJtEdgeGrab(JT * arg0, SO * arg1, VECTOR * arg2, XPK arg3, void * arg4, VECTOR * arg5); /* 0x1999D0 FCheckJtEdgeGrab__FP2JTP2SOP6VECTOR3XPKPvT2 */
/* SUSPECT in Sly 2: missing: reads in_a2 */
void * PxpFindJtBestEdge(JT * arg0, int * arg1, VECTOR * arg2); /* 0x199D48 PxpFindJtBestEdge__FP2JTPiP6VECTOR */
undefined4 MeasureJtJumpToTarget(JT * arg0, VECTOR * arg1, ALO * arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, float * arg6, VECTOR * arg7, VECTOR * arg8); /* 0x19A4A0 MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1 */
float GMeasureJumpRail(MJR * arg0, float arg1); /* 0x19AA58 GMeasureJumpRail__FP3MJRf */
undefined4 InitCnvo(CNVO * arg0); /* 0x19C9B8 InitCnvo__FP4CNVO */
void * PresetJtAccelPipe(JT * arg0); /* 0x19DF70 PresetJtAccelPipe__FP2JT */
/* REPAIRED for Sly 2: void __11CTransition(CTransition * this_, undefined8 in_a1) */
void CTransition_constructor(CTransition *this); /* 0x19F540 __11CTransition */
void * PostJtLoadZap(JT * arg0); /* 0x1A1098 PostJtLoadZap__FP2JT */
undefined4 UpdateUbgSgs(UBG * arg0); /* 0x1A1F68 UpdateUbgSgs__FP3UBG */
undefined4 FitLinearFunction(float arg0, float arg1, float arg2, float arg3, float * arg4, float * arg5); /* 0x1A3730 FitLinearFunction__FffffPfT4 */
undefined4 FitRecipFunction(float arg0, float arg1, float arg2, float arg3, float * arg4, float * arg5); /* 0x1A37D0 FitRecipFunction__FffffPfT4 */
undefined4 ConvertAngleStrength(float arg0, float arg1, float arg2, float arg3, float * arg4, float * arg5); /* 0x1A38A8 ConvertAngleStrength__FffffPfT4 */
int FInflictStepguardZap(STEPGUARD * arg0, XP * arg1, ZPR * arg2); /* 0x1A5BE8 FInflictStepguardZap__FP9STEPGUARDP2XPP3ZPR */
undefined4 CollectJtPrize(JT * arg0, PCK arg1, ALO * arg2); /* 0x1A61E0 CollectJtPrize__FP2JT3PCKP3ALO */
undefined4 AddBtnAseg(BTN * arg0, ALO * arg1, OID arg2); /* 0x1A6BC8 AddBtnAseg__FP3BTNP3ALO3OID */
int FDetectStepguard(STEPGUARD * arg0); /* 0x1A6EE8 FDetectStepguard__FP9STEPGUARD */
undefined4 FreeSwMqList(SW * arg0, MQ * arg1); /* 0x1A7E10 FreeSwMqList__FP2SWP2MQ */
undefined4 CategorizeAlsg(int arg0, LSG * arg1, int * arg2, int * arg3, LSG * * arg4, LSG * * arg5); /* 0x1A8410 CategorizeAlsg__FiP3LSGPiT2PP3LSGT4 */
undefined4 CplsgFindEdgePath(SURF * arg0, int arg1, int arg2, LSG * arg3, LSG * * arg4); /* 0x1A86B8 CplsgFindEdgePath__FP4SURFiiP3LSGPP3LSG */
undefined4 CsbiIntersectSphereBsp(VECTOR * arg0, float arg1, int arg2, BSP * arg3, BSP * arg4, GEOM * arg5, int arg6, SBI * arg7); /* 0x1A93C8 CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI */
int FUN_0018b910(int arg0); /* 0x1AAB48 FUN_0018b910__Fi */
int FUN_0018b930(int arg0); /* 0x1AAB68 FUN_0018b930__Fi */
undefined4 InitMemcard(MEMCARD * arg0); /* 0x1AAED8 InitMemcard__FP7MEMCARD */
undefined4 CreateMemcardThread(MEMCARD * arg0, int arg1, int arg2); /* 0x1AAF90 CreateMemcardThread__FP7MEMCARDii */
undefined4 SetMemcardThreadHighPrio(MEMCARD * arg0); /* 0x1AB040 SetMemcardThreadHighPrio__FP7MEMCARD */
int FMemcardThreadValid(MEMCARD * arg0); /* 0x1AB088 FMemcardThreadValid__FP7MEMCARD */
undefined4 UpdateSave(SAVE * arg0); /* 0x1AB1A0 UpdateSave__FP4SAVE */
undefined4 CompareSaves(SAVE * arg0, SAVE * arg1); /* 0x1AB398 CompareSaves__FP4SAVET0 */
undefined4 CheckForOutOfMemory(void); /* 0x1AE1C8 CheckForOutOfMemory__Fv */
void * PvAllocSwImpl(int arg0); /* 0x1AE1D0 PvAllocSwImpl__Fi */
void * PvAllocSwCopyImpl(int arg0, void * arg1); /* 0x1AE238 PvAllocSwCopyImpl__FiPv */
void * PvAllocSwClearImpl(int arg0); /* 0x1AE2A0 PvAllocSwClearImpl__Fi */
undefined4 FreeSw(void); /* 0x1AE300 FreeSw__Fv */
void * PvAllocStackImpl(int arg0); /* 0x1AE318 PvAllocStackImpl__Fi */
void * PvAllocStackClearImpl(int arg0); /* 0x1AE378 PvAllocStackClearImpl__Fi */
undefined4 InitStackImpl(void); /* 0x1AE3D8 InitStackImpl__Fv */
undefined4 FreeStackImpl(void); /* 0x1AE428 FreeStackImpl__Fv */
/* REPAIRED for Sly 2: void _$_4CRef(CRef * this_, undefined4 in_a1) */
void CRef_destructor(CRef *this); /* 0x1AE4A0 _$_4CRef */
undefined4 CopyAqw(void * arg0, void * arg1, int arg2); /* 0x1AE528 CopyAqw__FPvT0i */
undefined4 CopyAb(void * arg0, void * arg1, unsigned int arg2); /* 0x1AE5A0 CopyAb__FPvT0Ui */
undefined4 FreezeSmartguard(SMARTGUARD * arg0, int arg1); /* 0x1AE9A8 FreezeSmartguard__FP10SMARTGUARDi */
/* REPAIRED for Sly 2: undefined LoadAcscFromBrx__FP4ACSCP18CBinaryInputStream(SO * arg0, CBinaryInputStream * arg1, float in_f12) */
undefined4 LoadAcscFromBrx(ACSC * arg0, CBinaryInputStream * arg1); /* 0x1B10B0 LoadAcscFromBrx__FP4ACSCP18CBinaryInputStream */
undefined4 InitRov(ROV * arg0); /* 0x1B2070 InitRov__FP3ROV */
undefined4 FireSplmiss(SPLMISS * arg0, ALO * arg1, VECTOR * arg2); /* 0x1B2228 FireSplmiss__FP7SPLMISSP3ALOP6VECTOR */
undefined4 CQueueOutputIop_Reset(CQueueOutputIop *this); /* 0x1B2A80 Reset__15CQueueOutputIop */
int CQueueOutputIop_FAsyncDrain(CQueueOutputIop *this); /* 0x1B2FD0 FAsyncDrain__15CQueueOutputIop */
undefined4 CQueueOutputIpu_CbWrite(CQueueOutputIpu *this, int arg1, void * arg2); /* 0x1B2FD8 CbWrite__15CQueueOutputIpuiPv */
int CQueueOutputIpu_FAsyncDrain(CQueueOutputIpu *this); /* 0x1B3038 FAsyncDrain__15CQueueOutputIpu */
undefined4 CMpegAudio_Init(CMpegAudio *this); /* 0x1B3040 Init__10CMpegAudio */
undefined4 CMpegAudio_Reset(CMpegAudio *this); /* 0x1B3130 Reset__10CMpegAudio */
undefined4 CMpegAudio_Close(CMpegAudio *this); /* 0x1B3190 Close__10CMpegAudio */
int CMpegAudio_FAccept(CMpegAudio *this, int arg1, unsigned char * arg2); /* 0x1B31E0 FAccept__10CMpegAudioiPUc */
undefined4 CMpegAudio_Update(CMpegAudio *this); /* 0x1B32B8 Update__10CMpegAudio */
int FMpegAcceptVideo(sceMpeg * arg0, sceMpegCbDataStr * arg1, CMpeg * arg2); /* 0x1B3388 FMpegAcceptVideo__FP7sceMpegP16sceMpegCbDataStrP5CMpeg */
int FMpegAcceptAudio(sceMpeg * arg0, sceMpegCbDataStr * arg1, CMpeg * arg2); /* 0x1B33C8 FMpegAcceptAudio__FP7sceMpegP16sceMpegCbDataStrP5CMpeg */
int FMpegDecodeVideo(sceMpeg * arg0, sceMpegCbData * arg1, CMpeg * arg2); /* 0x1B33F0 FMpegDecodeVideo__FP7sceMpegP13sceMpegCbDataP5CMpeg */
undefined4 BuildMpegGifs(QW * arg0, sceIpuRGB32 * arg1, int arg2, int arg3, int arg4, int arg5, int arg6); /* 0x1B3510 BuildMpegGifs__FP2QWP11sceIpuRGB32iiiii */
/* REPAIRED for Sly 2: undefined Execute__5CMpeg(QW * this_, undefined4 in_a1, undefined4 in_a2) */
/* SUSPECT in Sly 2: conflict: this_ QW * -> Finish__5CMpeg arg0 CMpeg * */
undefined4 CMpeg_Execute(CMpeg *this); /* 0x1B3BD0 Execute__5CMpeg */
/* REPAIRED for Sly 2: undefined Update__5CMpeg(QW * this_) */
undefined4 CMpeg_Update(CMpeg *this); /* 0x1B4058 Update__5CMpeg */
undefined4 CMpeg_Finish(CMpeg *this); /* 0x1B4140 Finish__5CMpeg */
undefined4 CloneAseg(ASEG * arg0, LO * arg1); /* 0x1BC160 CloneAseg__FP4ASEGP2LO */
int FChooseRobRoc(ROB * arg0, ROH * arg1); /* 0x1BE1E8 FChooseRobRoc__FP3ROBP3ROH */
undefined4 IcgvFromPcgv(CG * arg0, CGV * arg1); /* 0x1BF970 IcgvFromPcgv__FP2CGP3CGV */
/* REPAIRED for Sly 2: undefined FindPathAStar__FP2CGP3CGVT1iPiPP3CGV(CG * arg0, CFileLocation * arg1, CGV * arg2, int arg3, int * arg4, CGV * * arg5) */
undefined4 FindPathAStar(CG * arg0, CGV * arg1, CGV * arg2, int arg3, int * arg4, CGV * * arg5); /* 0x1BF980 FindPathAStar__FP2CGP3CGVT1iPiPP3CGV */
undefined4 SimplifyApcgvNeighbor(CBSP * arg0, int * arg1, CGV * * arg2); /* 0x1BFC18 SimplifyApcgvNeighbor__FP4CBSPPiPP3CGV */
/* REPAIRED for Sly 2: undefined CposFindPath__FP2CGP6VECTORT1iT1(CBSP * arg0, VECTOR * arg1, VECTOR * arg2, int arg3, VECTOR * arg4) */
/* SUSPECT in Sly 2: conflict: arg0 CBSP * -> FindPathAStar__FP2CGP3CGVT1iPiPP3CGV arg0 CG * */
undefined4 CposFindPath(CG * arg0, VECTOR * arg1, VECTOR * arg2, int arg3, VECTOR * arg4); /* 0x1BFF28 CposFindPath__FP2CGP6VECTORT1iT1 */
undefined4 LoadPathzoneFromBrx(PATHZONE * arg0, CBinaryInputStream * arg1); /* 0x1C03C0 LoadPathzoneFromBrx__FP8PATHZONEP18CBinaryInputStream */
undefined4 HookupCg(CG * arg0); /* 0x1C0880 HookupCg__FP2CG */
undefined4 InitPipe(PIPE * arg0); /* 0x1C3390 InitPipe__FP4PIPE */
undefined4 GetJtPipeGoalMat(JT * arg0, PIPE * arg1, float arg2, MATRIX3 * arg3); /* 0x1C3500 GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3 */
/* REPAIRED for Sly 2: int FUN_001dccc0__FP18CBinaryInputStream(CBinaryInputStream * arg0, undefined4 in_a1) */
int FUN_001dccc0(CBinaryInputStream * arg0); /* 0x1C3DC8 FUN_001dccc0__FP18CBinaryInputStream */
undefined4 InitCoin(COIN * arg0); /* 0x1C7648 InitCoin__FP4COIN */
void CProg_constructor(CProg *this, RGBA * arg1, RGBA * arg2, RGBA * arg3, RGBA * arg4); /* 0x1C8CC0 __5CProgP4RGBAN31 */
undefined4 CProg_Begin(CProg *this); /* 0x1C8D20 Begin__5CProg */
undefined4 CProg_SetRemain(CProg *this, int arg1); /* 0x1C8D40 SetRemain__5CProgi */
undefined4 CProg_End(CProg *this); /* 0x1C8DB8 End__5CProg */
undefined4 CProg_Draw(CProg *this); /* 0x1C8DD8 Draw__5CProg */
int FUN_0018b600(void); /* 0x1C9098 FUN_0018b600__Fv */
/* REPAIRED for Sly 2: undefined FillScreenRect__FiiiiffffP4GIFS(int arg0, GIFS * arg1, int arg2, int arg3, float arg4, float arg5, float arg6, float arg7, GIFS * arg8) */
undefined4 FillScreenRect(int arg0, int arg1, int arg2, int arg3, float arg4, float arg5, float arg6, float arg7, GIFS * arg8); /* 0x1CD5F0 FillScreenRect__FiiiiffffP4GIFS */
undefined4 OnGameLoad(GAME * arg0); /* 0x1CD998 OnGameLoad__FP4GAME */
undefined4 SetRipgEmitb(RIPG * arg0, EMITB * arg1); /* 0x1CDE70 SetRipgEmitb__FP4RIPGP5EMITB */
undefined4 BounceRipgRips(RIPG * arg0); /* 0x1CE2E8 BounceRipgRips__FP4RIPG */
undefined4 RenderRipgSelf(RIPG * arg0, CM * arg1, RO * arg2); /* 0x1CE608 RenderRipgSelf__FP4RIPGP2CMP2RO */
undefined4 InitRip(RIP * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1CE920 InitRip__FP3RIPP6VECTORfP2SO */
undefined4 RemoveLightFromSw(LIGHT * arg0); /* 0x1CE980 RemoveLightFromSw__FP5LIGHT */
undefined4 AddRipRef(RIP * arg0); /* 0x1CE9C0 AddRipRef__FP3RIP */
/* REPAIRED for Sly 2: undefined TouchRip__FP3RIPi(LIGHT * arg0, int arg1) */
undefined4 TouchRip(RIP * arg0, int arg1); /* 0x1CEA88 TouchRip__FP3RIPi */
undefined4 ForceRipFade(RIP * arg0, float arg1); /* 0x1CEAA8 ForceRipFade__FP3RIPf */
int FBounceRip(RIP * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1CEB08 FBounceRip__FP3RIPP2SOP6VECTORT2 */
int FIsZeroV(VECTOR * arg0); /* 0x1CEFC8 FIsZeroV__FP6VECTOR */
int FIsZeroW(VECTOR * arg0); /* 0x1CF010 FIsZeroW__FP6VECTOR */
int FIsZeroDv(VECTOR * arg0); /* 0x1CF058 FIsZeroDv__FP6VECTOR */
void * ProjectRipTransform(RIP * arg0, float arg1); /* 0x1CF0A0 ProjectRipTransform__FP3RIPf */
/* REPAIRED for Sly 2: undefined UpdateRip__FP3RIPf(LIGHT * arg0, float arg1) */
undefined4 UpdateRip(RIP * arg0, float arg1); /* 0x1CF268 UpdateRip__FP3RIPf */
int FRenderRipPosMat(RIP * arg0, CM * arg1, VECTOR * arg2, MATRIX3 * arg3); /* 0x1CF338 FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3 */
undefined4 RenderFlying(FLYING * arg0, CM * arg1); /* 0x1CF618 RenderFlying__FP6FLYINGP2CM */
undefined4 CreateStuck(RIP * arg0, ALO * arg1, SO * arg2, VECTOR * arg3, VECTOR * arg4, STUCK * * arg5); /* 0x1CF6B0 CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK */
/* REPAIRED for Sly 2: int FBounceFlying__FP6FLYINGP2SOP6VECTORT2(LIGHT * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3) */
/* SUSPECT in Sly 2: conflict: arg0 LIGHT * -> CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK arg0 RIP * */
int FBounceFlying(FLYING * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1CF968 FBounceFlying__FP6FLYINGP2SOP6VECTORT2 */
/* REPAIRED for Sly 2: undefined UpdateStuck__FP5STUCKf(LIGHT * arg0, float arg1) */
undefined4 UpdateStuck(STUCK * arg0, float arg1); /* 0x1CFA20 UpdateStuck__FP5STUCKf */
undefined4 RenderStuck(STUCK * arg0, CM * arg1); /* 0x1CFA40 RenderStuck__FP5STUCKP2CM */
void * PostShrapnelEmit(SHRAPNEL * arg0, EMITB * arg1); /* 0x1CFAB8 PostShrapnelEmit__FP8SHRAPNELP5EMITB */
/* REPAIRED for Sly 2: undefined RenderOrbit__FP5ORBITP2CM(ORBIT * arg0, CM * arg1, undefined4 in_a2, undefined4 in_a3) */
undefined4 RenderOrbit(ORBIT * arg0, CM * arg1); /* 0x1CFC88 RenderOrbit__FP5ORBITP2CM */
undefined4 InitMatch(MATCH * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1CFCD8 InitMatch__FP5MATCHP6VECTORfP2SO */
undefined4 LaunchMatch(MATCH * arg0); /* 0x1CFD30 LaunchMatch__FP5MATCH */
void * ProjectMatchTransform(MATCH * arg0, float arg1); /* 0x1CFE88 ProjectMatchTransform__FP5MATCHf */
/* REPAIRED for Sly 2: undefined UpdateMatch__FP5MATCHf(LIGHT * arg0, float arg1) */
/* SUSPECT in Sly 2: conflict: arg0 LIGHT * -> LaunchMatch__FP5MATCH arg0 MATCH *; unused: arg1 */
undefined4 UpdateMatch(MATCH * arg0, float arg1); /* 0x1D0038 UpdateMatch__FP5MATCHf */
undefined4 RenderMatch(MATCH * arg0, CM * arg1); /* 0x1D00D0 RenderMatch__FP5MATCHP2CM */
undefined4 InitGlint(GLINT * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1D0108 InitGlint__FP5GLINTP6VECTORfP2SO */
/* REPAIRED for Sly 2: undefined RenderGlint__FP5GLINTP2CM(LIGHT * arg0, CM * arg1) */
undefined4 RenderGlint(GLINT * arg0, CM * arg1); /* 0x1D0190 RenderGlint__FP5GLINTP2CM */
undefined4 InitSmack(SMACK * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1D04E8 InitSmack__FP5SMACKP6VECTORfP2SO */
void * ProjectSmackTransform(SMACK * arg0, float arg1); /* 0x1D05A0 ProjectSmackTransform__FP5SMACKf */
void * PostLeafEmit(LEAF * arg0, EMITB * arg1); /* 0x1D08D8 PostLeafEmit__FP4LEAFP5EMITB */
void * ProjectLeafTransform(LEAF * arg0, float arg1); /* 0x1D09A0 ProjectLeafTransform__FP4LEAFf */
/* REPAIRED for Sly 2: int FBounceLeaf__FP4LEAFP2SOP6VECTORT2(LIGHT * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3) */
/* SUSPECT in Sly 2: conflict: arg0 LIGHT * -> CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK arg0 RIP * */
int FBounceLeaf(LEAF * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1D0BF8 FBounceLeaf__FP4LEAFP2SOP6VECTORT2 */
undefined4 InitDroplet(DROPLET * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1D0CA8 InitDroplet__FP7DROPLETP6VECTORfP2SO */
/* REPAIRED for Sly 2: undefined TouchDroplet__FP7DROPLETi(LIGHT * arg0, int arg1) */
undefined4 TouchDroplet(DROPLET * arg0, int arg1); /* 0x1D0D28 TouchDroplet__FP7DROPLETi */
undefined4 InitBublet(BUBLET * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1D0E48 InitBublet__FP6BUBLETP6VECTORfP2SO */
void * ProjectBubletTransform(BUBLET * arg0, float arg1); /* 0x1D0EB8 ProjectBubletTransform__FP6BUBLETf */
/* REPAIRED for Sly 2: undefined TouchBublet__FP6BUBLETi(LIGHT * arg0, int arg1) */
undefined4 TouchBublet(BUBLET * arg0, int arg1); /* 0x1D10E8 TouchBublet__FP6BUBLETi */
void * PostRemitEmit(REMIT * arg0, EMITB * arg1); /* 0x1D1108 PostRemitEmit__FP5REMITP5EMITB */
/* REPAIRED for Sly 2: undefined UpdateRemit__FP5REMITf(LIGHT * arg0, float arg1) */
undefined4 UpdateRemit(REMIT * arg0, float arg1); /* 0x1D1160 UpdateRemit__FP5REMITf */
undefined4 InitRumble(RUMBLE * arg0, int arg1, int arg2); /* 0x1D5150 InitRumble__FP6RUMBLEii */
undefined4 UpdateRumble(RUMBLE * arg0); /* 0x1D51B8 UpdateRumble__FP6RUMBLE */
/* REPAIRED for Sly 2: undefined TriggerRumbleRumk__FP6RUMBLE4RUMKf(float arg0, RUMBLE * arg1, float arg2, undefined4 in_a1) */
undefined4 TriggerRumbleRumk(RUMBLE * arg0, RUMK arg1, float arg2); /* 0x1D5310 TriggerRumbleRumk__FP6RUMBLE4RUMKf */
undefined4 TriggerRumbleRumpat(RUMBLE * arg0, RUMPAT * arg1, float arg2); /* 0x1D5340 TriggerRumbleRumpat__FP6RUMBLEP6RUMPATf */
undefined4 SetRumbleRums(RUMBLE * arg0, RUMS arg1); /* 0x1D53C0 SetRumbleRums__FP6RUMBLE4RUMS */
undefined4 StopRumbleActuators(RUMBLE * arg0); /* 0x1D5468 StopRumbleActuators__FP6RUMBLE */
undefined4 RumbleUnknown1(void); /* 0x1D5498 RumbleUnknown1__Fv */
int FCalculateMuzzleVelocity(VECTOR * arg0, VECTOR * arg1, float arg2, VECTOR * arg3, SO * arg4); /* 0x1D6848 FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO */
undefined4 MatchStepguardAnimationPhase(STEPGUARD * arg0, OID arg1, OID arg2, OID arg3, OID arg4); /* 0x1D7748 MatchStepguardAnimationPhase__FP9STEPGUARD3OIDN31 */
undefined4 DeletePair(CPair * arg0); /* 0x1D8C10 DeletePair__FP5CPair */
/* REPAIRED for Sly 2: undefined StartupJmt__Fv(undefined4 in_a0) */
undefined4 StartupJmt(void); /* 0x1D93D8 StartupJmt__Fv */
undefined4 ShutdownSplice(void); /* 0x1D9520 ShutdownSplice__Fv */
undefined4 CGc_UpdateRecyclable(CGc *this); /* 0x1D9820 UpdateRecyclable__3CGc */
/* REPAIRED for Sly 2: undefined RetryGame__Fv(undefined4 in_a0) */
undefined4 RetryGame(void); /* 0x1DA770 RetryGame__Fv */
/* REPAIRED for Sly 2: undefined StartGame__Fv(undefined4 in_a0) */
undefined4 StartGame(void); /* 0x1DAA08 StartGame__Fv */
undefined4 EnsureSggAlarm(SGG * arg0, ALARM * arg1); /* 0x1E0020 EnsureSggAlarm__FP3SGGP5ALARM */
undefined4 AddJsgLabel(JSG * arg0, OID arg1); /* 0x1E02E0 AddJsgLabel__FP3JSG3OID */
undefined4 AddJsgJump(JSG * arg0, OID arg1, JSGJK arg2, JSGLK arg3, int arg4); /* 0x1E03E0 AddJsgJump__FP3JSG3OID5JSGJK5JSGLKi */
undefined4 AddJsgAttack(JSG * arg0, OID arg1, FTAK arg2, int arg3); /* 0x1E0480 AddJsgAttack__FP3JSG3OID4FTAKi */
undefined4 CRef_SetS32(CRef *this, int arg1); /* 0x1E0760 SetS32__4CRefi */
/* REPAIRED for Sly 2: undefined SetSymid__4CRefUi(CRef * this_, uint arg1, undefined4 in_a2, undefined4 in_a3, undefined4 in_t0) */
undefined4 CRef_SetSymid(CRef *this, unsigned int arg1); /* 0x1E0940 SetSymid__4CRefUi */
undefined4 CRef_SetBifk(CRef *this, BIFK arg1); /* 0x1E0990 SetBifk__4CRef4BIFK */
/* REPAIRED for Sly 2: undefined SetPair__4CRefP5CPair(CRef * this_, CPair * arg1, undefined4 in_a2, undefined4 in_a3) */
undefined4 CRef_SetPair(CRef *this, CPair * arg1); /* 0x1E09D0 SetPair__4CRefP5CPair */
/* REPAIRED for Sly 2: undefined SetMethod__4CRefP7CMethod(CRef * this_, CMethod * arg1, undefined4 in_a2) */
undefined4 CRef_SetMethod(CRef *this, CMethod * arg1); /* 0x1E0AA0 SetMethod__4CRefP7CMethod */
undefined4 FindCrvClosestPointOnLineSegmentFromU(CRV * arg0, VECTOR * arg1, VECTOR * arg2, float arg3, VECTOR * arg4, VECTOR * arg5, float * arg6, float * arg7); /* 0x1E6DB8 FindCrvClosestPointOnLineSegmentFromU__FP3CRVP6VECTORT1fT1T1PfT6 */
undefined4 SetEmitterRipt(EMITTER * arg0, RIPT arg1); /* 0x1E79F0 SetEmitterRipt__FP7EMITTER4RIPT */
undefined4 CFontBrx_LoadFromBrx(CFontBrx *this, CBinaryInputStream * arg1); /* 0x1EAF50 LoadFromBrx__8CFontBrxP18CBinaryInputStream */
undefined4 LoadTexFromBrx(CBinaryInputStream * arg0, TEX * arg1); /* 0x1EB1A8 LoadTexFromBrx__FP18CBinaryInputStreamP3TEX */
undefined4 FillShaders(int arg0); /* 0x1EB960 FillShaders__Fi */
void * PshdFindShader(OID arg0); /* 0x1EC820 PshdFindShader__F3OID */
undefined4 UpdateGlobset(GLOBSET * arg0, ALO * arg1, float arg2); /* 0x1EC968 UpdateGlobset__FP7GLOBSETP3ALOf */
undefined4 BuildClutTex2(CLUT * arg0, int arg1); /* 0x1EC9D0 BuildClutTex2__FP4CLUTi */
undefined4 BuildClutGifs(CLUT * arg0, int arg1, GIFS * arg2); /* 0x1ECAB0 BuildClutGifs__FP4CLUTiP4GIFS */
undefined4 BuildBmpTex0(BMP * arg0, int arg1); /* 0x1ECB18 BuildBmpTex0__FP3BMPi */
undefined4 BuildBmpGifs(BMP * arg0, int arg1, GIFS * arg2); /* 0x1ECBF0 BuildBmpGifs__FP3BMPiP4GIFS */
int FBuildUploadBitmapGifs(int arg0, GSB * arg1, GIFS * arg2); /* 0x1ECC28 FBuildUploadBitmapGifs__FiP3GSBP4GIFS */
/* REPAIRED for Sly 2: void * PqwVifsBitmapUpload__Fi(int arg0, undefined4 in_a1) */
void * PqwVifsBitmapUpload(int arg0); /* 0x1ECE58 PqwVifsBitmapUpload__Fi */
int FUpdatableSaa(SAA * arg0); /* 0x1EDA20 FUpdatableSaa__FP3SAA */
undefined4 UCompleteSaa(SAA * arg0); /* 0x1EDA58 UCompleteSaa__FP3SAA */
undefined4 InitLoop(LOOP * arg0, SAAF * arg1); /* 0x1EDB98 InitLoop__FP4LOOPP4SAAF */
undefined4 UpdateLoop(LOOP * arg0, float arg1); /* 0x1EDC40 UpdateLoop__FP4LOOPf */
undefined4 UCompleteLoop(LOOP * arg0); /* 0x1EDD30 UCompleteLoop__FP4LOOP */
undefined4 InitPingpong(PINGPONG * arg0, SAAF * arg1); /* 0x1EDD60 InitPingpong__FP8PINGPONGP4SAAF */
undefined4 UpdatePingpong(PINGPONG * arg0, float arg1); /* 0x1EDE10 UpdatePingpong__FP8PINGPONGf */
undefined4 UCompletePingpong(PINGPONG * arg0); /* 0x1EDF28 UCompletePingpong__FP8PINGPONG */
undefined4 CloneActseg(ACTSEG * arg0, ACTSEG * arg1); /* 0x1EDFA0 CloneActseg__FP6ACTSEGT0 */
undefined4 UpdateShuffle(SHUFFLE * arg0, float arg1); /* 0x1EDFE0 UpdateShuffle__FP7SHUFFLEf */
undefined4 InitEyes(EYES * arg0, SAAF * arg1); /* 0x1EE090 InitEyes__FP4EYESP4SAAF */
undefined4 SetEyesEyess(EYES * arg0, EYESS arg1); /* 0x1EE100 SetEyesEyess__FP4EYES5EYESS */
undefined4 UpdateEyes(EYES * arg0, float arg1); /* 0x1EE228 UpdateEyes__FP4EYESf */
undefined4 SetEyesClosed(EYES * arg0, float arg1); /* 0x1EE3B0 SetEyesClosed__FP4EYESf */
void * PsaiFromEyesShd(EYES * arg0, SHD * arg1); /* 0x1EE420 PsaiFromEyesShd__FP4EYESP3SHD */
undefined4 InitScroller(SCROLLER * arg0, SAAF * arg1); /* 0x1EE480 InitScroller__FP8SCROLLERP4SAAF */
undefined4 UpdateScroller(SCROLLER * arg0, float arg1); /* 0x1EE4E0 UpdateScroller__FP8SCROLLERf */
undefined4 UCompleteScroller(SCROLLER * arg0); /* 0x1EE5B8 UCompleteScroller__FP8SCROLLER */
undefined4 SetScrollerMasterSpeeds(SCROLLER * arg0, float arg1, float arg2); /* 0x1EE678 SetScrollerMasterSpeeds__FP8SCROLLERff */
undefined4 InitCircler(CIRCLER * arg0, SAAF * arg1); /* 0x1EE688 InitCircler__FP7CIRCLERP4SAAF */
undefined4 UpdateCircler(CIRCLER * arg0, float arg1); /* 0x1EE6D8 UpdateCircler__FP7CIRCLERf */
undefined4 UCompleteCircler(CIRCLER * arg0); /* 0x1EE768 UCompleteCircler__FP7CIRCLER */
undefined4 LoadSmFromBrx(SM * arg0, CBinaryInputStream * arg1); /* 0x1EFAC0 LoadSmFromBrx__FP2SMP18CBinaryInputStream */
void * PsmaFindSm(SM * arg0, ALO * arg1); /* 0x1F03C8 PsmaFindSm__FP2SMP3ALO */
undefined4 IsmsFindSmOptional(SM * arg0, OID arg1); /* 0x1F0400 IsmsFindSmOptional__FP2SM3OID */
undefined4 IsmsFindSmRequired(SM * arg0, OID arg1); /* 0x1F0438 IsmsFindSmRequired__FP2SM3OID */
undefined4 SetSmaGoal(SMA * arg0, OID arg1); /* 0x1F0660 SetSmaGoal__FP3SMA3OID */
undefined4 SetSoMass(SO * arg0, float arg1); /* 0x1F35C8 SetSoMass__FP2SOf */
undefined4 AdjustSoMomint(SO * arg0, float arg1); /* 0x1F35F8 AdjustSoMomint__FP2SOf */
undefined4 GetSoCpdefi(SO * arg0, float arg1, CPDEFI * arg2); /* 0x1F58F0 GetSoCpdefi__FP2SOfP6CPDEFI */
undefined4 AccelSoTowardMatSmooth(SO * arg0, float arg1, MATRIX3 * arg2, SMP * arg3); /* 0x1F59A0 AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP */
undefined4 AccelSoTowardMatSpring(SO * arg0, MATRIX3 * arg1, CLQ * arg2, VECTOR * arg3, CLQ * arg4, float arg5); /* 0x1F5C30 AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f */
/* REPAIRED for Sly 2: undefined EnsureSoLvo__FP2SO(SO * arg0, undefined4 in_a1) */
undefined4 EnsureSoLvo(SO * arg0); /* 0x1F6C08 EnsureSoLvo__FP2SO */
void * PostSmLoad(SM * arg0); /* 0x1F8740 PostSmLoad__FP2SM */
undefined4 NewSfx(SFX * * arg0); /* 0x1FAF70 NewSfx__FPP3SFX */
undefined4 StopSound(AMB * arg0, int arg1); /* 0x1FBE80 StopSound__FP3AMBi */
/* REPAIRED for Sly 2: void * PauseVag__Fv(undefined4 in_a0) */
void * PauseVag(void); /* 0x1FBEE0 PauseVag__Fv */
/* REPAIRED for Sly 2: undefined ContinueVag__Fv(undefined4 in_a0) */
undefined4 ContinueVag(void); /* 0x1FBF00 ContinueVag__Fv */
undefined4 MarkClockTickRealOnly(CLOCK * arg0); /* 0x1FE3F8 MarkClockTickRealOnly__FP5CLOCK */
undefined4 SetLightDynamic(LIGHT * arg0, int arg1); /* 0x1FE9C8 SetLightDynamic__FP5LIGHTi */
undefined4 InitButton(BUTTON * arg0); /* 0x1FF3B8 InitButton__FP6BUTTON */
void * PeopidFind(BASIC * arg0, int arg1); /* 0x1FFCF8 PeopidFind__FP5BASICi */
/* REPAIRED for Sly 2: undefined RefSetOption__FP5BASICiP4CRef(BASIC * arg0, BASIC * arg1, int arg2) */
undefined4 RefSetOption(BASIC * arg0, int arg1, CRef * arg2); /* 0x200C28 RefSetOption__FP5BASICiP4CRef */
undefined4 RefAddOption(BASIC * arg0, int arg1, CRef * arg2); /* 0x200CA8 RefAddOption__FP5BASICiP4CRef */
/* REPAIRED for Sly 2: undefined RefEnsureOption__FP5BASICiP4CRef(BASIC * arg0, int arg1, int arg2) */
undefined4 RefEnsureOption(BASIC * arg0, int arg1, CRef * arg2); /* 0x200D10 RefEnsureOption__FP5BASICiP4CRef */
/* REPAIRED for Sly 2: undefined RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(int arg0, CRef * arg1, OTYP * arg2, void * * arg3, undefined4 in_t0) */
undefined4 RefSetPvsFromSplice(int arg0, CRef * arg1, OTYP * arg2, void * * arg3); /* 0x201110 RefSetPvsFromSplice__FiP4CRefP4OTYPPPv */
/* REPAIRED for Sly 2: undefined RefSetArgsFromSplice__FiP4CRefP4OTYPe(int arg0, CRef * arg1, OTYP * arg2, undefined4 in_a3, undefined4 in_t0, undefined4 in_t1, undefined4 in_t2, undefined4 in_t3, ...) */
undefined4 RefSetArgsFromSplice(int arg0, CRef * arg1, OTYP * arg2, ...); /* 0x201360 RefSetArgsFromSplice__FiP4CRefP4OTYPe */
/* REPAIRED for Sly 2: undefined LoadSprBuf__Fie(int arg0, undefined4 in_a1, undefined4 in_a2, undefined4 in_a3, undefined4 in_t0, undefined4 in_t1, undefined4 in_t2, undefined4 in_t3, ...) */
undefined4 LoadSprBuf(int arg0, ...); /* 0x201620 LoadSprBuf__Fie */
/* REPAIRED for Sly 2: undefined SaveSprBuf__FPve(void * arg0, undefined4 in_a1, undefined4 in_a2, undefined4 in_a3, undefined4 in_t0, undefined4 in_t1, undefined4 in_t2, undefined4 in_t3, ...) */
undefined4 SaveSprBuf(void * arg0, ...); /* 0x2017A0 SaveSprBuf__FPve */
undefined4 OnStepguardAdd(STEPGUARD * arg0); /* 0x203638 OnStepguardAdd__FP9STEPGUARD */
void * PaloGetActlaTarget(ACTLA * arg0); /* 0x203758 PaloGetActlaTarget__FP5ACTLA */
undefined4 UpdateStepPhys(STEP * arg0); /* 0x203E08 UpdateStepPhys__FP4STEP */
undefined4 SgasGetStepguard(STEPGUARD * arg0); /* 0x204248 SgasGetStepguard__FP9STEPGUARD */
undefined4 FixStepAngularVelocity(STEP * arg0); /* 0x204CA8 FixStepAngularVelocity__FP4STEP */
undefined4 SetStepSpinRatio(STEP * arg0, float arg1); /* 0x204D48 SetStepSpinRatio__FP4STEPf */
undefined4 SetStepGravityRatio(STEP * arg0, float arg1); /* 0x204DA8 SetStepGravityRatio__FP4STEPf */
undefined4 GetRwacPan(RWAC * arg0, float * arg1); /* 0x20A690 GetRwacPan__FP4RWACPf */
void * PostStepLoadRun(STEP * arg0, BLRUN * arg1, ASEGBL * * arg2); /* 0x20B868 PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL */
void OSTRM_constructor(OSTRM *this, int arg1); /* 0x20D5D0 __5OSTRMi */
void OSTRM_constructor_2(OSTRM *this, void * arg1, int arg2); /* 0x20D5F0 __5OSTRMPvi */
/* REPAIRED for Sly 2: void _$_5OSTRM(OSTRM * this_, undefined4 in_a1) */
void OSTRM_destructor(OSTRM *this); /* 0x20D618 _$_5OSTRM */
undefined4 OSTRM_CbWrite(OSTRM *this, void * arg1, int arg2); /* 0x20D660 CbWrite__5OSTRMPvi */
undefined4 OSTRM_Flush(OSTRM *this); /* 0x20D798 Flush__5OSTRM */
undefined4 SaveChkmgrCheckpoint(CHKMGR * arg0, OID arg1, OID arg2); /* 0x20DF80 SaveChkmgrCheckpoint__FP6CHKMGR3OIDT1 */
undefined4 IncrementSwHandsOff(SW * arg0); /* 0x20F0C0 IncrementSwHandsOff__FP2SW */
undefined4 DecrementSwHandsOff(SW * arg0); /* 0x20F0F0 DecrementSwHandsOff__FP2SW */
int FAddRsmg(RSMG * arg0, int arg1, int * arg2, int arg3, OID arg4, OID arg5, OID arg6); /* 0x20FEC0 FAddRsmg__FP4RSMGiPii3OIDN24 */
undefined4 SwitchToPo(PO * arg0); /* 0x210B70 SwitchToPo__FP2PO */
undefined4 SetTimerTimers(TIMER * arg0, TIMERS arg1); /* 0x212A50 SetTimerTimers__FP5TIMER6TIMERS */
undefined4 CRichText_Trim(CRichText *this, int arg1); /* 0x215E80 Trim__9CRichTexti */
undefined4 InitFragile(FRAGILE * arg0); /* 0x21BB88 InitFragile__FP7FRAGILE */
undefined4 CchParsePchzInt(char * arg0, int * arg1); /* 0x21D638 CchParsePchzInt__FPcPi */
undefined4 CchParsePchzTft(char * arg0, TFT * arg1, char * * arg2); /* 0x21D6B0 CchParsePchzTft__FPcP3TFTPPc */
undefined4 WriteTftPchz(TFT * arg0, OSTRM * arg1, char * arg2); /* 0x21D9F0 WriteTftPchz__FP3TFTP5OSTRMPc */
int FNegTftUl(TFT * arg0, UL * arg1); /* 0x21DB38 FNegTftUl__FP3TFTP2UL */
undefined4 UnRadixFromChConversion(char arg0); /* 0x21DC18 UnRadixFromChConversion__Fc */
undefined4 CchAchFromUl(char * arg0, int arg1, unsigned long arg2, unsigned int arg3); /* 0x21DC70 CchAchFromUl__FPciUlUi */
undefined4 WriteTftUl(TFT * arg0, OSTRM * arg1, unsigned long arg2); /* 0x21DD40 WriteTftUl__FP3TFTP5OSTRMUl */
undefined4 ExpFirstFromG(double arg0); /* 0x21E048 ExpFirstFromG__Fd */
undefined4 ChDigitFromG(double arg0, int arg1, int arg2); /* 0x21E0D8 ChDigitFromG__Fdii */
undefined4 CchAchFromDouble(char * arg0, int arg1, TFT * arg2, double arg3); /* 0x21E1B0 CchAchFromDouble__FPciP3TFTd */
undefined4 WriteTftDouble(TFT * arg0, OSTRM * arg1, double arg2); /* 0x21E4B8 WriteTftDouble__FP3TFTP5OSTRMd */
/* REPAIRED for Sly 2: undefined WriteTft__FP3TFTP5OSTRMPPcPci(TFT * arg0, OSTRM * arg1, char * * arg2, char * arg3, int arg4, undefined4 in_t1, undefined4 in_t2) */
undefined4 WriteTft(TFT * arg0, OSTRM * arg1, char * * arg2, char * arg3, int arg4); /* 0x21E718 WriteTft__FP3TFTP5OSTRMPPcPci */
/* REPAIRED for Sly 2: undefined CchOstrmPrintf__FP5OSTRMPcT1(OSTRM * arg0, char * arg1, char * arg2, undefined4 in_a3, undefined4 in_t0, undefined4 in_t1, undefined4 in_t2) */
undefined4 CchOstrmPrintf(OSTRM * arg0, char * arg1, char * arg2); /* 0x21EAC8 CchOstrmPrintf__FP5OSTRMPcT1 */
undefined4 UpperizePchz(char * arg0); /* 0x21EE30 UpperizePchz__FPc */
undefined4 ClearRwmAimConstraints(RWM * arg0); /* 0x21EFD0 ClearRwmAimConstraints__FP3RWM */
undefined4 InitCritSect(CRITSECT * arg0); /* 0x21F028 InitCritSect__FP8CRITSECT */
undefined4 EnterCritSect(CRITSECT * arg0); /* 0x21F060 EnterCritSect__FP8CRITSECT */
undefined4 LeaveCritSect(CRITSECT * arg0); /* 0x21F0C0 LeaveCritSect__FP8CRITSECT */
undefined4 StartupThread(void); /* 0x21F100 StartupThread__Fv */
undefined4 UpdateStepXfWorld(STEP * arg0); /* 0x220D40 UpdateStepXfWorld__FP4STEP */
/* REPAIRED for Sly 2: undefined GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(TNFN * arg0, CPDEFI * arg1, VECTOR * arg2, float arg3, undefined4 in_a3) */
undefined4 GetTnfnNose(TNFN * arg0, CPDEFI * arg1, VECTOR * arg2, TN * arg3); /* 0x220DD8 GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN */
undefined4 InitTn(TN * arg0); /* 0x220ED0 InitTn__FP2TN */
void * PostTnLoad(TN * arg0); /* 0x220F88 PostTnLoad__FP2TN */
undefined4 RenderTnSelf(TN * arg0, CM * arg1, RO * arg2); /* 0x221140 RenderTnSelf__FP2TNP2CMP2RO */
undefined4 SetTnTns(TN * arg0, TNS arg1); /* 0x221178 SetTnTns__FP2TN3TNS */
int FUN_001e2840(TN * arg0, TNS arg1); /* 0x221268 FUN_001e2840__FP2TN3TNS */
undefined4 UpdateTn(TN * arg0, float arg1); /* 0x221388 UpdateTn__FP2TNf */
undefined4 FreezeTn(TN * arg0, int arg1); /* 0x2213D8 FreezeTn__FP2TNi */
undefined4 CalculateTnPos(TN * arg0, VECTOR * arg1, float arg2, float arg3, CLQ * arg4, LM * arg5, FTND arg6, VECTOR * arg7); /* 0x2215C0 CalculateTnPos__FP2TNP6VECTORffP3CLQP2LM4FTNDT1 */
/* REPAIRED for Sly 2: undefined ActivateCptn__FP4CPTNPv(CPTN * arg0, void * arg1, undefined4 in_a2, undefined4 in_a3) */
undefined4 ActivateCptn(CPTN * arg0, void * arg1); /* 0x221A18 ActivateCptn__FP4CPTNPv */
/* REPAIRED for Sly 2: undefined UpdateCptn__FP4CPTNP6CPDEFIP3JOYf(CPTN * arg0, CPDEFI * arg1, JOY * arg2, float arg3, undefined4 in_a3) */
undefined4 UpdateCptn(CPTN * arg0, CPDEFI * arg1, JOY * arg2, float arg3); /* 0x221DD8 UpdateCptn__FP4CPTNP6CPDEFIP3JOYf */
undefined4 HideBlot(BLOT * arg0); /* 0x224190 HideBlot__FP4BLOT */
undefined4 InitDysh(DYSH * arg0); /* 0x2252E0 InitDysh__FP4DYSH */
undefined4 OnTankActive(TANK * arg0, int arg1, PO * arg2); /* 0x225A68 OnTankActive__FP4TANKiP2PO */
void VIFS_constructor(VIFS *this); /* 0x226C10 __4VIFS */
undefined4 VIFS_Align(VIFS *this, int arg1); /* 0x226C58 Align__4VIFSi */
undefined4 VIFS_AddVifBaseOffset(VIFS *this, int arg1, int arg2); /* 0x226CA8 AddVifBaseOffset__4VIFSii */
undefined4 VIFS_AddVifMscal(VIFS *this, void * arg1); /* 0x226CE0 AddVifMscal__4VIFSPv */
undefined4 VIFS_AddVifFlush(VIFS *this); /* 0x226D10 AddVifFlush__4VIFS */
undefined4 VIFS_AddVifFlusha(VIFS *this); /* 0x226D28 AddVifFlusha__4VIFS */
undefined4 VIFS_AddVifStcycl(VIFS *this, int arg1, int arg2); /* 0x226D40 AddVifStcycl__4VIFSii */
undefined4 VIFS_AddVifStrow(VIFS *this, QW * arg1); /* 0x226D68 AddVifStrow__4VIFSP2QW */
undefined4 VIFS_AddVifStmask(VIFS *this, unsigned int arg1); /* 0x226DD0 AddVifStmask__4VIFSUi */
undefined4 VIFS_UnpackHelper(VIFS *this, UPK arg1, int arg2, int arg3, int * arg4, unsigned int * * arg5); /* 0x226E88 UnpackHelper__4VIFS3UPKiiPiPPUi */
/* SUSPECT in Sly 2: missing: reads in_a3_lo */
undefined4 VIFS_AddVifUnpack(VIFS *this, UPK arg1, int arg2, void * arg3, int arg4); /* 0x226F28 AddVifUnpack__4VIFS3UPKiPvi */
undefined4 VIFS_AddVifUnpackRefs(VIFS *this, UPK arg1, int arg2, void * arg3, int arg4, void * * * arg5); /* 0x227010 AddVifUnpackRefs__4VIFS3UPKiPviPPPv */
undefined4 VIFS_AddVifDirect(VIFS *this, int arg1, QW * arg2, int arg3); /* 0x2270C8 AddVifDirect__4VIFSiP2QWi */
undefined4 VIFS_AddVifDirectRefs(VIFS *this, int arg1, QW * arg2, int arg3); /* 0x227148 AddVifDirectRefs__4VIFSiP2QWi */
undefined4 VIFS_AddVifGifs(VIFS *this, GIFS * arg1); /* 0x2271C8 AddVifGifs__4VIFSP4GIFS */
undefined4 AddBrkTouchObject(BRK * arg0, OID arg1); /* 0x228958 AddBrkTouchObject__FP3BRK3OID */
undefined4 LoadScaleMatrixVector(VECTOR * arg0, MATRIX3 * arg1, VECTOR * arg2, MATRIX4 * arg3); /* 0x228C18 LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4 */
undefined4 UpdateSwXaList(SW * arg0, XA * * arg1); /* 0x228D20 UpdateSwXaList__FP2SWPP2XA */
undefined4 FreeSwXaList(SW * arg0, XA * arg1); /* 0x2296C0 FreeSwXaList__FP2SWP2XA */
undefined4 AddSoXa(SO * arg0, XA * arg1); /* 0x229710 AddSoXa__FP2SOP2XA */
undefined4 RemoveSoXa(SO * arg0, XA * arg1); /* 0x229738 RemoveSoXa__FP2SOP2XA */
undefined4 UpdateWrStateVectors(WR * arg0); /* 0x22B7D8 UpdateWrStateVectors__FP2WR */
undefined4 UNoise(int arg0); /* 0x22BE08 UNoise__Fi */
undefined4 UNoise_2(float arg0, float arg1, float arg2); /* 0x22BE60 UNoise__Ffff */
undefined4 UBias(float arg0, float arg1); /* 0x22BF40 UBias__Fff */
float GFromOnz(ONZ * arg0); /* 0x22BF70 GFromOnz__FP3ONZ */
undefined4 UpdateWrMatrixes(WR * arg0); /* 0x22C028 UpdateWrMatrixes__FP2WR */
undefined4 AddWrCircleWarp(WR * arg0); /* 0x22C3B0 AddWrCircleWarp__FP2WR */
undefined4 AddWrBendWarp(WR * arg0); /* 0x22C430 AddWrBendWarp__FP2WR */
void * PwreGetWrCur(WR * arg0, ENSK arg1, WREK arg2); /* 0x22C4A0 PwreGetWrCur__FP2WR4ENSK4WREK */
void * PwreGetWrCircle(WR * arg0, ENSK arg1); /* 0x22C4D8 PwreGetWrCircle__FP2WR4ENSK */
void * PwreGetWrBend(WR * arg0, ENSK arg1); /* 0x22C4F8 PwreGetWrBend__FP2WR4ENSK */
undefined4 SetWrWavelength(WR * arg0, float arg1); /* 0x22C518 SetWrWavelength__FP2WRf */
undefined4 GetWrWavelength(WR * arg0, float * arg1); /* 0x22C570 GetWrWavelength__FP2WRPf */
undefined4 AddOnzOnze(ONZ * arg0, float arg1, float arg2, float arg3, float arg4); /* 0x22C5B8 AddOnzOnze__FP3ONZffff */
undefined4 ConvertDeulToW(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x22CAD0 ConvertDeulToW__FP6VECTORN20 */
undefined4 LoadLoFromBrx(LO * arg0, CBinaryInputStream * arg1); /* 0x231170 LoadLoFromBrx__FP2LOP18CBinaryInputStream */
undefined4 snd_GotReturns(void); /* 0x231E90 snd_GotReturns__Fv */
undefined4 snd_SendIOPCommandNoWait(int arg0, int arg1, char * arg2, void (*arg3)(int, unsigned long), unsigned long arg4); /* 0x232838 snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl */
undefined4 snd_PostMessage(void); /* 0x232BB8 snd_PostMessage__Fv */
undefined4 snd_SendCurrentBatch(void); /* 0x232BF8 snd_SendCurrentBatch__Fv */
undefined4 __main(void); /* 0x23B7D8 __main__Fv */
void VU_FLOAT_constructor(VU_FLOAT *this, float arg1); /* 0x256CE8 __8VU_FLOATf */
void VU_VECTOR_constructor(VU_VECTOR *this, const VECTOR * arg1); /* 0x256D08 __9VU_VECTORRC6VECTOR */
/* SUSPECT in Sly 2: missing: reads in_a1_hi,in_a1_lo,in_a1_udw; unused: arg1 */
undefined4 VECTOR_op_assign(VECTOR *this, VU_VECTOR arg1); /* 0x256D18 __as__6VECTORG9VU_VECTOR */
/* SUSPECT in Sly 2: missing: reads in_a1_lo,in_a0_lo; unused: arg0,arg1 */
undefined4 op_multiply_3(VU_FLOAT arg0, VU_VECTOR arg1); /* 0x256D28 __ml__FG8VU_FLOATG9VU_VECTOR */
/* REPAIRED for Sly 2: void _$_18CBinaryInputStream(CBinaryInputStream * this_, undefined4 in_a1) */
void CBinaryInputStream_destructor(CBinaryInputStream *this); /* 0x2572E0 _$_18CBinaryInputStream */
undefined4 CFileLocation_Clear(CFileLocation *this); /* 0x258248 Clear__13CFileLocation */
/* SUSPECT in Sly 2: missing: reads in_a1_lo,in_a0_lo,in_a3_lo,in_a2_lo; unused: arg0,arg1,arg2,arg3 */
undefined4 VecCombo(VU_FLOAT arg0, VU_VECTOR arg1, VU_FLOAT arg2, VU_VECTOR arg3); /* 0x258480 VecCombo__FG8VU_FLOATG9VU_VECTORT0T1 */
undefined4 CloneEmitter(EMITTER * arg0, EMITTER * arg1); /* 0x258620 CloneEmitter__FP7EMITTERT0 */
undefined4 UpdateSuvXfWorld(SUV * arg0); /* 0x2590B8 UpdateSuvXfWorld__FP3SUV */
