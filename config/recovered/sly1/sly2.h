/* Sly 2: Band of Thieves (SCUS-97316): prototypes of the functions named from the Sly 1 decomp, demangled
 * from their GCC 2.95 names by demangle.py. Parameters come from the mangling; return types are guessed from
 * the Hungarian prefix (F flag, G float, ...) or left undefined4. Names come from code matching: unverified.
 * Structs are opaque: Sly 2 layouts differ from Sly 1. The parameter lists are Sly 1's: a function can keep its
 * role and name in Sly 2 but change its parameters (CalcCmAdjust looks like it takes an output VECTOR first). */

typedef unsigned int undefined4;
typedef int bool;
typedef int wchar_t;

typedef struct ACCMISS ACCMISS;
typedef struct ACG ACG;
typedef struct ACGB ACGB;
typedef struct ACGBLP ACGBLP;
typedef struct ACGBLT ACGBLT;
typedef struct ACGBW ACGBW;
typedef struct ACGK ACGK;
typedef struct ACGL ACGL;
typedef struct ACK ACK;
typedef struct ACP ACP;
typedef struct ACPB ACPB;
typedef struct ACPBL ACPBL;
typedef struct ACPC ACPC;
typedef struct ACR ACR;
typedef struct ACRB ACRB;
typedef struct ACRBL ACRBL;
typedef struct ACRC ACRC;
typedef struct ACS ACS;
typedef struct ACSB ACSB;
typedef struct ACSC ACSC;
typedef struct ACT ACT;
typedef struct ACTADD ACTADD;
typedef struct ACTADJ ACTADJ;
typedef struct ACTBANK ACTBANK;
typedef struct ACTLA ACTLA;
typedef struct ACTREF ACTREF;
typedef struct ACTSEG ACTSEG;
typedef struct ACTVAL ACTVAL;
typedef struct ACVK ACVK;
typedef struct ALARM ALARM;
typedef struct ALARMS ALARMS;
typedef struct ALBRK ALBRK;
typedef struct ALO ALO;
typedef struct ALTK ALTK;
typedef struct AMB AMB;
typedef struct ASEG ASEG;
typedef struct ASEGA ASEGA;
typedef struct ASEGBL ASEGBL;
typedef struct ASH ASH;
typedef struct ATTRACT ATTRACT;
typedef struct BARRIER BARRIER;
typedef struct BASIC BASIC;
typedef struct BEI BEI;
typedef struct BIFK BIFK;
typedef struct BINOC BINOC;
typedef struct BL BL;
typedef struct BLIP BLIP;
typedef struct BLIPG BLIPG;
typedef struct BLIPOK BLIPOK;
typedef struct BLIPP BLIPP;
typedef struct BLIPV BLIPV;
typedef struct BLIPX BLIPX;
typedef struct BLOT BLOT;
typedef struct BLOTK BLOTK;
typedef struct BLOTS BLOTS;
typedef struct BLRUN BLRUN;
typedef struct BLSS BLSS;
typedef struct BMP BMP;
typedef struct BOMB BOMB;
typedef struct BREAK BREAK;
typedef struct BRK BRK;
typedef struct BRKP BRKP;
typedef struct BRKPS BRKPS;
typedef struct BSP BSP;
typedef struct BSPC BSPC;
typedef struct BTN BTN;
typedef struct BTNP BTNP;
typedef struct BUBLET BUBLET;
typedef struct BULLET BULLET;
typedef struct BURST BURST;
typedef struct BUTTON BUTTON;
typedef struct BUTTONS BUTTONS;
typedef struct CAMERA CAMERA;
typedef struct CAMSEN CAMSEN;
typedef struct CBSP CBSP;
typedef struct CBinaryAsyncStream CBinaryAsyncStream;
typedef struct CBinaryInputStream CBinaryInputStream;
typedef struct CByteQueue CByteQueue;
typedef struct CFileLocation CFileLocation;
typedef struct CFont CFont;
typedef struct CFontBrx CFontBrx;
typedef struct CFrame CFrame;
typedef struct CG CG;
typedef struct CGT CGT;
typedef struct CGV CGV;
typedef struct CGc CGc;
typedef struct CHARM CHARM;
typedef struct CHKMGR CHKMGR;
typedef struct CHKPNT CHKPNT;
typedef struct CHN CHN;
typedef struct CID CID;
typedef struct CIRCLER CIRCLER;
typedef struct CLOCK CLOCK;
typedef struct CLQ CLQ;
typedef struct CLUE CLUE;
typedef struct CLUT CLUT;
typedef struct CM CM;
typedef struct CMK CMK;
typedef struct CMPK CMPK;
typedef struct CMethod CMethod;
typedef struct CMpeg CMpeg;
typedef struct CMpegAudio CMpegAudio;
typedef struct CNSTR CNSTR;
typedef struct CNVO CNVO;
typedef struct CODE CODE;
typedef struct COIN COIN;
typedef struct CONSTR CONSTR;
typedef struct CPDEFI CPDEFI;
typedef struct CPLCY CPLCY;
typedef struct CPLOOK CPLOOK;
typedef struct CPMAN CPMAN;
typedef struct CPMT CPMT;
typedef struct CPP CPP;
typedef struct CPTN CPTN;
typedef struct CPair CPair;
typedef struct CProc CProc;
typedef struct CProg CProg;
typedef struct CQueueInput CQueueInput;
typedef struct CQueueInputFile CQueueInputFile;
typedef struct CQueueInputMemory CQueueInputMemory;
typedef struct CQueueOutput CQueueOutput;
typedef struct CQueueOutputIop CQueueOutputIop;
typedef struct CQueueOutputIpu CQueueOutputIpu;
typedef struct CRBRAIN CRBRAIN;
typedef struct CREDIT CREDIT;
typedef struct CRFOD CRFOD;
typedef struct CRFODB CRFODB;
typedef struct CRFODK CRFODK;
typedef struct CRITSECT CRITSECT;
typedef struct CRUSHERCTR CRUSHERCTR;
typedef struct CRV CRV;
typedef struct CRVC CRVC;
typedef struct CRVK CRVK;
typedef struct CRVL CRVL;
typedef struct CRVMC CRVMC;
typedef struct CRVMS CRVMS;
typedef struct CRef CRef;
typedef struct CRichText CRichText;
typedef struct CSDTS CSDTS;
typedef struct CSidebag CSidebag;
typedef struct CSplotheap CSplotheap;
typedef struct CT CT;
typedef struct CTK CTK;
typedef struct CTR CTR;
typedef struct CTextBox CTextBox;
typedef struct CTextEdge CTextEdge;
typedef struct CTransition CTransition;
typedef struct CVarb CVarb;
typedef struct DABLET DABLET;
typedef struct DART DART;
typedef struct DARTGUN DARTGUN;
typedef struct DARTS DARTS;
typedef struct DE DE;
typedef struct DEBRIS DEBRIS;
typedef struct DIALOG DIALOG;
typedef struct DIALOGS DIALOGS;
typedef struct DIAPI DIAPI;
typedef struct DIFFICULTY DIFFICULTY;
typedef struct DL DL;
typedef struct DLE DLE;
typedef struct DMAS DMAS;
typedef struct DPRIZE DPRIZE;
typedef struct DPRIZES DPRIZES;
typedef struct DROPLET DROPLET;
typedef struct DYSH DYSH;
typedef struct DZ DZ;
typedef struct DZG DZG;
typedef struct EA EA;
typedef struct EDGE EDGE;
typedef struct EGK EGK;
typedef struct EMITB EMITB;
typedef struct EMITBLIP EMITBLIP;
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
typedef struct EOPID EOPID;
typedef struct EXC EXC;
typedef struct EXIT EXIT;
typedef struct EXITS EXITS;
typedef struct EXPL EXPL;
typedef struct EXPLG EXPLG;
typedef struct EXPLO EXPLO;
typedef struct EXPLS EXPLS;
typedef struct EXPLSO EXPLSO;
typedef struct EYES EYES;
typedef struct EYESS EYESS;
typedef struct FADER FADER;
typedef struct FGFN FGFN;
typedef struct FIREBALL FIREBALL;
typedef struct FK FK;
typedef struct FLAKE FLAKE;
typedef struct FLAME FLAME;
typedef struct FLASH FLASH;
typedef struct FLY FLY;
typedef struct FLYING FLYING;
typedef struct FLYS FLYS;
typedef struct FRAGILE FRAGILE;
typedef struct FRM FRM;
typedef struct FRZG FRZG;
typedef struct FSP FSP;
typedef struct FTAK FTAK;
typedef struct FTND FTND;
typedef struct FTRANS FTRANS;
typedef struct FX FX;
typedef struct GAME GAME;
typedef struct GAMEWORLD GAMEWORLD;
typedef struct GEOM GEOM;
typedef struct GIFS GIFS;
typedef struct GLBS GLBS;
typedef struct GLINT GLINT;
typedef struct GLOB GLOB;
typedef struct GLOBI GLOBI;
typedef struct GLOBSET GLOBSET;
typedef struct GOADK GOADK;
typedef struct GOMER GOMER;
typedef struct GRFVAULT GRFVAULT;
typedef struct GS GS;
typedef struct GSB GSB;
typedef struct HBSK HBSK;
typedef struct HBSKS HBSKS;
typedef struct HFDK HFDK;
typedef struct HND HND;
typedef struct HOLOGRAM HOLOGRAM;
typedef struct HP HP;
typedef struct HPNT HPNT;
typedef struct HSHAPE HSHAPE;
typedef struct IASH IASH;
typedef struct IKH IKH;
typedef struct JH JH;
typedef struct JLO JLO;
typedef struct JLOC JLOC;
typedef struct JLOS JLOS;
typedef struct JLOVOL JLOVOL;
typedef struct JMT JMT;
typedef struct JOY JOY;
typedef struct JOYID JOYID;
typedef struct JOYK JOYK;
typedef struct JOYS JOYS;
typedef struct JSG JSG;
typedef struct JSGE JSGE;
typedef struct JSGEK JSGEK;
typedef struct JSGJK JSGJK;
typedef struct JSGLK JSGLK;
typedef struct JT JT;
typedef struct JTBS JTBS;
typedef struct JTCS JTCS;
typedef struct JTHK JTHK;
typedef struct JTPDK JTPDK;
typedef struct JTS JTS;
typedef struct JV JV;
typedef struct KEY KEY;
typedef struct KEYHOLE KEYHOLE;
typedef struct KVB KVB;
typedef struct LANDING LANDING;
typedef struct LASEN LASEN;
typedef struct LBEAM LBEAM;
typedef struct LEAF LEAF;
typedef struct LETTERBOX LETTERBOX;
typedef struct LGN LGN;
typedef struct LGNR LGNR;
typedef struct LGNS LGNS;
typedef struct LIFETKN LIFETKN;
typedef struct LIGHT LIGHT;
typedef struct LIGHTK LIGHTK;
typedef struct LIKH LIKH;
typedef struct LM LM;
typedef struct LO LO;
typedef struct LOCK LOCK;
typedef struct LOCKG LOCKG;
typedef struct LOGO LOGO;
typedef struct LOOKER LOOKER;
typedef struct LOOKK LOOKK;
typedef struct LOOP LOOP;
typedef struct LS LS;
typedef struct LSG LSG;
typedef struct LevelLoadData LevelLoadData;
typedef struct MAA MAA;
typedef struct MATCH MATCH;
typedef struct MATRIX3 MATRIX3;
typedef struct MATRIX4 MATRIX4;
typedef struct MBG MBG;
typedef struct MEMCARD MEMCARD;
typedef struct MISSILE MISSILE;
typedef struct MJH MJH;
typedef struct MJR MJR;
typedef struct MQ MQ;
typedef struct MRG MRG;
typedef struct MRKV MRKV;
typedef struct MRSG MRSG;
typedef struct MS MS;
typedef struct MSGID MSGID;
typedef struct MTLK MTLK;
typedef struct MURRAY MURRAY;
typedef struct MUSID MUSID;
typedef struct MVGK MVGK;
typedef struct NOTE NOTE;
typedef struct OID OID;
typedef struct ONZ ONZ;
typedef struct OPTID OPTID;
typedef struct ORBIT ORBIT;
typedef struct OSTRM OSTRM;
typedef struct OTYP OTYP;
typedef struct OVR OVR;
typedef struct OXA OXA;
typedef struct PATHZONE PATHZONE;
typedef struct PCK PCK;
typedef struct PHASE PHASE;
typedef struct PINGPONG PINGPONG;
typedef struct PIPE PIPE;
typedef struct PNT PNT;
typedef struct PO PO;
typedef struct POSAD POSAD;
typedef struct PRK PRK;
typedef struct PROMPT PROMPT;
typedef struct PROXY PROXY;
typedef struct PRP PRP;
typedef struct PRSEN PRSEN;
typedef struct PUFF PUFF;
typedef struct PUFFB PUFFB;
typedef struct PUFFC PUFFC;
typedef struct PUFFER PUFFER;
typedef struct QW QW;
typedef struct RAIL RAIL;
typedef struct RAT RAT;
typedef struct RATHOLE RATHOLE;
typedef struct RATS RATS;
typedef struct RAY RAY;
typedef struct RCHM RCHM;
typedef struct REMIT REMIT;
typedef struct RESPK RESPK;
typedef struct REVERBK REVERBK;
typedef struct RGBA RGBA;
typedef struct RIP RIP;
typedef struct RIPG RIPG;
typedef struct RIPGT RIPGT;
typedef struct RIPPLE RIPPLE;
typedef struct RIPT RIPT;
typedef struct RO RO;
typedef struct ROB ROB;
typedef struct ROBS ROBS;
typedef struct ROC ROC;
typedef struct ROCS ROCS;
typedef struct ROH ROH;
typedef struct ROHS ROHS;
typedef struct ROP ROP;
typedef struct ROPS ROPS;
typedef struct ROSE ROSE;
typedef struct ROSES ROSES;
typedef struct ROST ROST;
typedef struct ROSTS ROSTS;
typedef struct ROV ROV;
typedef struct ROVS ROVS;
typedef struct ROVTS ROVTS;
typedef struct RPL RPL;
typedef struct RSMG RSMG;
typedef struct RTCK RTCK;
typedef struct RUMBLE RUMBLE;
typedef struct RUMK RUMK;
typedef struct RUMPAT RUMPAT;
typedef struct RUMS RUMS;
typedef struct RWAC RWAC;
typedef struct RWFI RWFI;
typedef struct RWM RWM;
typedef struct RWTI RWTI;
typedef struct SAA SAA;
typedef struct SAAF SAAF;
typedef struct SAAK SAAK;
typedef struct SAI SAI;
typedef struct SAVE SAVE;
typedef struct SBG SBG;
typedef struct SBI SBI;
typedef struct SCPRIZE SCPRIZE;
typedef struct SCROLLER SCROLLER;
typedef struct SEEK SEEK;
typedef struct SENSM SENSM;
typedef struct SENSOR SENSOR;
typedef struct SENSORS SENSORS;
typedef struct SFF SFF;
typedef struct SFX SFX;
typedef struct SFXID SFXID;
typedef struct SGG SGG;
typedef struct SGGS SGGS;
typedef struct SGS SGS;
typedef struct SGVR SGVR;
typedef struct SHADOW SHADOW;
typedef struct SHAPE SHAPE;
typedef struct SHD SHD;
typedef struct SHDK SHDK;
typedef struct SHDP SHDP;
typedef struct SHRAPNEL SHRAPNEL;
typedef struct SHUFFLE SHUFFLE;
typedef struct SKY SKY;
typedef struct SLOTHEAP SLOTHEAP;
typedef struct SM SM;
typedef struct SMA SMA;
typedef struct SMACK SMACK;
typedef struct SMARTGUARD SMARTGUARD;
typedef struct SMOKECLOUD SMOKECLOUD;
typedef struct SMOKETRAIL SMOKETRAIL;
typedef struct SMP SMP;
typedef struct SMPA SMPA;
typedef struct SNIP SNIP;
typedef struct SO SO;
typedef struct SPARK SPARK;
typedef struct SPEAKER SPEAKER;
typedef struct SPIRE SPIRE;
typedef struct SPKD SPKD;
typedef struct SPKS SPKS;
typedef struct SPLMISS SPLMISS;
typedef struct SPLOT SPLOT;
typedef struct SPRIZE SPRIZE;
typedef struct SQTRM SQTRM;
typedef struct STEP STEP;
typedef struct STEPGUARD STEPGUARD;
typedef struct STSO STSO;
typedef struct STUCK STUCK;
typedef struct SUBCEL SUBCEL;
typedef struct SUBGLOB SUBGLOB;
typedef struct SUBGLOBI SUBGLOBI;
typedef struct SUBPOSEF SUBPOSEF;
typedef struct SUR SUR;
typedef struct SURF SURF;
typedef struct SUV SUV;
typedef struct SUVS SUVS;
typedef struct SW SW;
typedef struct SWP SWP;
typedef struct SYMEVID SYMEVID;
typedef struct TAGK TAGK;
typedef struct TAIL TAIL;
typedef struct TANK TANK;
typedef struct TANKS TANKS;
typedef struct TARGET TARGET;
typedef struct TBSP TBSP;
typedef struct TEX TEX;
typedef struct TFT TFT;
typedef struct THROBK THROBK;
typedef struct TIMER TIMER;
typedef struct TIMERS TIMERS;
typedef struct TITLE TITLE;
typedef struct TMBL TMBL;
typedef struct TN TN;
typedef struct TNFN TNFN;
typedef struct TNS TNS;
typedef struct TOTALS TOTALS;
typedef struct TRAIL TRAIL;
typedef struct TRANS TRANS;
typedef struct TRLS TRLS;
typedef struct TRUNKCTR TRUNKCTR;
typedef struct TSURF TSURF;
typedef struct TURRET TURRET;
typedef struct TV TV;
typedef struct TVGS TVGS;
typedef struct TVS TVS;
typedef struct TWEF TWEF;
typedef struct TWR TWR;
typedef struct TZP TZP;
typedef struct UBG UBG;
typedef struct UFOK UFOK;
typedef struct UI UI;
typedef struct UIS UIS;
typedef struct UL UL;
typedef struct UPK UPK;
typedef struct UVF UVF;
typedef struct UVQ UVQ;
typedef struct VAULT VAULT;
typedef struct VBSP VBSP;
typedef struct VECTOR VECTOR;
typedef struct VECTOR4 VECTOR4;
typedef struct VECTORF VECTORF;
typedef struct VIFS VIFS;
typedef struct VISMAP VISMAP;
typedef struct VOL VOL;
typedef struct VOLBTN VOLBTN;
typedef struct VOLZP VOLZP;
typedef struct VTACT VTACT;
typedef struct VTXF VTXF;
typedef struct VU_FLOAT VU_FLOAT;
typedef struct VU_VECTOR VU_VECTOR;
typedef struct VU_VECTOR4 VU_VECTOR4;
typedef struct WARP WARP;
typedef struct WATER WATER;
typedef struct WAYPOINT WAYPOINT;
typedef struct WID WID;
typedef struct WIPE WIPE;
typedef struct WIPEK WIPEK;
typedef struct WIPES WIPES;
typedef struct WKR WKR;
typedef struct WM WM;
typedef struct WMC WMC;
typedef struct WMD WMD;
typedef struct WMS WMS;
typedef struct WORLDLEVEL WORLDLEVEL;
typedef struct WPS WPS;
typedef struct WPSG WPSG;
typedef struct WR WR;
typedef struct WREK WREK;
typedef struct XA XA;
typedef struct XFM XFM;
typedef struct XMG XMG;
typedef struct XP XP;
typedef struct XPK XPK;
typedef struct ZAPBREAK ZAPBREAK;
typedef struct ZPD ZPD;
typedef struct ZPK ZPK;
typedef struct ZPR ZPR;
typedef struct sceDmaChan sceDmaChan;
typedef struct sceIpuRGB32 sceIpuRGB32;
typedef struct sceMpeg sceMpeg;
typedef struct sceMpegCbData sceMpegCbData;
typedef struct sceMpegCbDataStr sceMpegCbDataStr;

undefined4 BuildEopids(void); /* 0x109488 BuildEopids__Fv */
undefined4 RefOpAdd(int arg0, CRef * arg1, CFrame * arg2); /* 0x112698 RefOpAdd__FiP4CRefP6CFrame */
undefined4 RefOpSub(int arg0, CRef * arg1, CFrame * arg2); /* 0x112968 RefOpSub__FiP4CRefP6CFrame */
undefined4 RefOpMult(int arg0, CRef * arg1, CFrame * arg2); /* 0x112C38 RefOpMult__FiP4CRefP6CFrame */
undefined4 RefOpDiv(int arg0, CRef * arg1, CFrame * arg2); /* 0x113240 RefOpDiv__FiP4CRefP6CFrame */
undefined4 RefOpPrint(int arg0, CRef * arg1, CFrame * arg2); /* 0x113730 RefOpPrint__FiP4CRefP6CFrame */
undefined4 RefOpPrintFrame(int arg0, CRef * arg1, CFrame * arg2); /* 0x113780 RefOpPrintFrame__FiP4CRefP6CFrame */
undefined4 RefOpPrintSidebag(int arg0, CRef * arg1, CFrame * arg2); /* 0x1137D0 RefOpPrintSidebag__FiP4CRefP6CFrame */
undefined4 RefOpIntEqual(int arg0, CRef * arg1, CFrame * arg2); /* 0x113820 RefOpIntEqual__FiP4CRefP6CFrame */
undefined4 RefCmp(CRef * arg0, CMPK arg1); /* 0x113888 RefCmp__FP4CRef4CMPK */
undefined4 RefOpL(int arg0, CRef * arg1, CFrame * arg2); /* 0x1139E8 RefOpL__FiP4CRefP6CFrame */
undefined4 RefOpLE(int arg0, CRef * arg1, CFrame * arg2); /* 0x113A18 RefOpLE__FiP4CRefP6CFrame */
undefined4 RefOpG(int arg0, CRef * arg1, CFrame * arg2); /* 0x113A48 RefOpG__FiP4CRefP6CFrame */
undefined4 RefOpGE(int arg0, CRef * arg1, CFrame * arg2); /* 0x113A78 RefOpGE__FiP4CRefP6CFrame */
undefined4 RefOpEqv(int arg0, CRef * arg1, CFrame * arg2); /* 0x113AA8 RefOpEqv__FiP4CRefP6CFrame */
undefined4 RefEqualHelper(CRef * arg0, CRef * arg1); /* 0x113B60 RefEqualHelper__FP4CRefT0 */
undefined4 RefOpEqual(int arg0, CRef * arg1, CFrame * arg2); /* 0x113E48 RefOpEqual__FiP4CRefP6CFrame */
undefined4 RefOpIsBoolean(int arg0, CRef * arg1, CFrame * arg2); /* 0x113E78 RefOpIsBoolean__FiP4CRefP6CFrame */
undefined4 RefOpIsNum(int arg0, CRef * arg1, CFrame * arg2); /* 0x113EE0 RefOpIsNum__FiP4CRefP6CFrame */
undefined4 RefOpIsFloat(int arg0, CRef * arg1, CFrame * arg2); /* 0x113F48 RefOpIsFloat__FiP4CRefP6CFrame */
undefined4 RefOpIsInteger(int arg0, CRef * arg1, CFrame * arg2); /* 0x113FB0 RefOpIsInteger__FiP4CRefP6CFrame */
undefined4 RefOpIsSymbol(int arg0, CRef * arg1, CFrame * arg2); /* 0x114018 RefOpIsSymbol__FiP4CRefP6CFrame */
undefined4 RefOpIsVector(int arg0, CRef * arg1, CFrame * arg2); /* 0x114080 RefOpIsVector__FiP4CRefP6CFrame */
undefined4 RefOpIsMatrix(int arg0, CRef * arg1, CFrame * arg2); /* 0x1140E8 RefOpIsMatrix__FiP4CRefP6CFrame */
undefined4 RefOpIsClq(int arg0, CRef * arg1, CFrame * arg2); /* 0x114150 RefOpIsClq__FiP4CRefP6CFrame */
undefined4 RefOpIsLm(int arg0, CRef * arg1, CFrame * arg2); /* 0x1141B8 RefOpIsLm__FiP4CRefP6CFrame */
undefined4 RefOpIsSmp(int arg0, CRef * arg1, CFrame * arg2); /* 0x114220 RefOpIsSmp__FiP4CRefP6CFrame */
undefined4 RefOpIsList(int arg0, CRef * arg1, CFrame * arg2); /* 0x114288 RefOpIsList__FiP4CRefP6CFrame */
undefined4 RefOpIsNull(int arg0, CRef * arg1, CFrame * arg2); /* 0x114300 RefOpIsNull__FiP4CRefP6CFrame */
undefined4 RefOpIsObject(int arg0, CRef * arg1, CFrame * arg2); /* 0x114360 RefOpIsObject__FiP4CRefP6CFrame */
undefined4 RefOpIsNullObj(int arg0, CRef * arg1, CFrame * arg2); /* 0x1143C8 RefOpIsNullObj__FiP4CRefP6CFrame */
undefined4 RefOpIsMethod(int arg0, CRef * arg1, CFrame * arg2); /* 0x114438 RefOpIsMethod__FiP4CRefP6CFrame */
undefined4 RefOpIsProcedure(int arg0, CRef * arg1, CFrame * arg2); /* 0x1144A0 RefOpIsProcedure__FiP4CRefP6CFrame */
undefined4 RefOpAreNear(int arg0, CRef * arg1, CFrame * arg2); /* 0x114518 RefOpAreNear__FiP4CRefP6CFrame */
undefined4 RefOpNot(int arg0, CRef * arg1, CFrame * arg2); /* 0x1145C8 RefOpNot__FiP4CRefP6CFrame */
undefined4 RefOpCons(int arg0, CRef * arg1, CFrame * arg2); /* 0x114638 RefOpCons__FiP4CRefP6CFrame */
undefined4 RefOpCar(int arg0, CRef * arg1, CFrame * arg2); /* 0x1146E0 RefOpCar__FiP4CRefP6CFrame */
undefined4 RefOpCdr(int arg0, CRef * arg1, CFrame * arg2); /* 0x114740 RefOpCdr__FiP4CRefP6CFrame */
undefined4 RefOpSetCadr(int arg0, CRef * arg1, CFrame * arg2, BIFK arg3); /* 0x1147B8 RefOpSetCadr__FiP4CRefP6CFrame4BIFK */
undefined4 RefOpSetCar(int arg0, CRef * arg1, CFrame * arg2); /* 0x114858 RefOpSetCar__FiP4CRefP6CFrame */
undefined4 RefOpSetCdr(int arg0, CRef * arg1, CFrame * arg2); /* 0x114888 RefOpSetCdr__FiP4CRefP6CFrame */
undefined4 RefOpLength(int arg0, CRef * arg1, CFrame * arg2); /* 0x1148B8 RefOpLength__FiP4CRefP6CFrame */
undefined4 RefOpNth(int arg0, CRef * arg1, CFrame * arg2); /* 0x114950 RefOpNth__FiP4CRefP6CFrame */
undefined4 RefOpIsMember(int arg0, CRef * arg1, CFrame * arg2); /* 0x1149F0 RefOpIsMember__FiP4CRefP6CFrame */
undefined4 RefOpList(int arg0, CRef * arg1, CFrame * arg2); /* 0x114B80 RefOpList__FiP4CRefP6CFrame */
undefined4 RefOpAppend(int arg0, CRef * arg1, CFrame * arg2); /* 0x114BB0 RefOpAppend__FiP4CRefP6CFrame */
undefined4 RefOpMap(int arg0, CRef * arg1, CFrame * arg2); /* 0x114D18 RefOpMap__FiP4CRefP6CFrame */
undefined4 RefOpFilter(int arg0, CRef * arg1, CFrame * arg2); /* 0x114F48 RefOpFilter__FiP4CRefP6CFrame */
undefined4 RefOpForEach(int arg0, CRef * arg1, CFrame * arg2); /* 0x1151C0 RefOpForEach__FiP4CRefP6CFrame */
undefined4 RefOpEval(int arg0, CRef * arg1, CFrame * arg2); /* 0x115398 RefOpEval__FiP4CRefP6CFrame */
undefined4 RefOpVector(int arg0, CRef * arg1, CFrame * arg2); /* 0x115440 RefOpVector__FiP4CRefP6CFrame */
undefined4 RefOpMatrix(int arg0, CRef * arg1, CFrame * arg2); /* 0x115510 RefOpMatrix__FiP4CRefP6CFrame */
undefined4 RefOpSetMusicRegister(int arg0, CRef * arg1, CFrame * arg2); /* 0x1156B0 RefOpSetMusicRegister__FiP4CRefP6CFrame */
undefined4 RefOpClq(int arg0, CRef * arg1, CFrame * arg2); /* 0x115710 RefOpClq__FiP4CRefP6CFrame */
undefined4 RefOpLm(int arg0, CRef * arg1, CFrame * arg2); /* 0x1157E0 RefOpLm__FiP4CRefP6CFrame */
undefined4 RefOpSmp(int arg0, CRef * arg1, CFrame * arg2); /* 0x1158B8 RefOpSmp__FiP4CRefP6CFrame */
undefined4 RefOpGetElement(int arg0, CRef * arg1, CFrame * arg2); /* 0x1159B8 RefOpGetElement__FiP4CRefP6CFrame */
undefined4 RefOpRandomSeed(int arg0, CRef * arg1, CFrame * arg2); /* 0x115B78 RefOpRandomSeed__FiP4CRefP6CFrame */
undefined4 RefOpRandom(int arg0, CRef * arg1, CFrame * arg2); /* 0x115C00 RefOpRandom__FiP4CRefP6CFrame */
undefined4 RefUfo(CRef * arg0, UFOK arg1); /* 0x115CA0 RefUfo__FP4CRef4UFOK */
undefined4 RefOpSqrt(int arg0, CRef * arg1, CFrame * arg2); /* 0x115D48 RefOpSqrt__FiP4CRefP6CFrame */
undefined4 RefOpSin(int arg0, CRef * arg1, CFrame * arg2); /* 0x115D78 RefOpSin__FiP4CRefP6CFrame */
undefined4 RefOpCos(int arg0, CRef * arg1, CFrame * arg2); /* 0x115DA8 RefOpCos__FiP4CRefP6CFrame */
undefined4 RefOpTan(int arg0, CRef * arg1, CFrame * arg2); /* 0x115DD8 RefOpTan__FiP4CRefP6CFrame */
undefined4 RefOpAsin(int arg0, CRef * arg1, CFrame * arg2); /* 0x115E08 RefOpAsin__FiP4CRefP6CFrame */
undefined4 RefOpAcos(int arg0, CRef * arg1, CFrame * arg2); /* 0x115E38 RefOpAcos__FiP4CRefP6CFrame */
undefined4 RefOpAtan(int arg0, CRef * arg1, CFrame * arg2); /* 0x115E68 RefOpAtan__FiP4CRefP6CFrame */
undefined4 RefOpRadNormalize(int arg0, CRef * arg1, CFrame * arg2); /* 0x115E98 RefOpRadNormalize__FiP4CRefP6CFrame */
undefined4 RefOpAtan2(int arg0, CRef * arg1, CFrame * arg2); /* 0x115EC8 RefOpAtan2__FiP4CRefP6CFrame */
undefined4 RefOpVectorDotProduct(int arg0, CRef * arg1, CFrame * arg2); /* 0x115F70 RefOpVectorDotProduct__FiP4CRefP6CFrame */
undefined4 RefOpVectorCrossProduct(int arg0, CRef * arg1, CFrame * arg2); /* 0x115FF8 RefOpVectorCrossProduct__FiP4CRefP6CFrame */
undefined4 RefOpVectorLth(int arg0, CRef * arg1, CFrame * arg2); /* 0x116080 RefOpVectorLth__FiP4CRefP6CFrame */
undefined4 RefOpVectorDistance(int arg0, CRef * arg1, CFrame * arg2); /* 0x116108 RefOpVectorDistance__FiP4CRefP6CFrame */
undefined4 RefOpVectorDistanceSquared(int arg0, CRef * arg1, CFrame * arg2); /* 0x1161F8 RefOpVectorDistanceSquared__FiP4CRefP6CFrame */
undefined4 RefOpVectorNormalize(int arg0, CRef * arg1, CFrame * arg2); /* 0x1162D0 RefOpVectorNormalize__FiP4CRefP6CFrame */
undefined4 RefOpVectorProjectNormal(int arg0, CRef * arg1, CFrame * arg2); /* 0x116400 RefOpVectorProjectNormal__FiP4CRefP6CFrame */
undefined4 RefOpVectorProjectTangent(int arg0, CRef * arg1, CFrame * arg2); /* 0x116490 RefOpVectorProjectTangent__FiP4CRefP6CFrame */
undefined4 RefOpVectorBallisticVelocity(int arg0, CRef * arg1, CFrame * arg2); /* 0x116520 RefOpVectorBallisticVelocity__FiP4CRefP6CFrame */
undefined4 RefOpVectorRadianNormal(int arg0, CRef * arg1, CFrame * arg2); /* 0x116600 RefOpVectorRadianNormal__FiP4CRefP6CFrame */
undefined4 RefOpMatrixTranspose(int arg0, CRef * arg1, CFrame * arg2); /* 0x1166C0 RefOpMatrixTranspose__FiP4CRefP6CFrame */
undefined4 RefOpMatrixInvert(int arg0, CRef * arg1, CFrame * arg2); /* 0x116740 RefOpMatrixInvert__FiP4CRefP6CFrame */
undefined4 RefOpMatrixCalculateDmat(int arg0, CRef * arg1, CFrame * arg2); /* 0x1167C0 RefOpMatrixCalculateDmat__FiP4CRefP6CFrame */
undefined4 RefOpMatrixInterpolateRotate(int arg0, CRef * arg1, CFrame * arg2); /* 0x116840 RefOpMatrixInterpolateRotate__FiP4CRefP6CFrame */
undefined4 RefOpMatrixDecomposeToTranslate(int arg0, CRef * arg1, CFrame * arg2); /* 0x116978 RefOpMatrixDecomposeToTranslate__FiP4CRefP6CFrame */
undefined4 RefOpMatrixDecomposeToRotate(int arg0, CRef * arg1, CFrame * arg2); /* 0x1169E8 RefOpMatrixDecomposeToRotate__FiP4CRefP6CFrame */
undefined4 RefOpMatrixDecomposeToEuler(int arg0, CRef * arg1, CFrame * arg2); /* 0x116A88 RefOpMatrixDecomposeToEuler__FiP4CRefP6CFrame */
undefined4 RefOpMatrixDecomposeToRadianNormal(int arg0, CRef * arg1, CFrame * arg2); /* 0x116B08 RefOpMatrixDecomposeToRadianNormal__FiP4CRefP6CFrame */
undefined4 RefOpMatrixLookAt(int arg0, CRef * arg1, CFrame * arg2); /* 0x116BC8 RefOpMatrixLookAt__FiP4CRefP6CFrame */
undefined4 RefOpMatrixTiltUpright(int arg0, CRef * arg1, CFrame * arg2); /* 0x116C80 RefOpMatrixTiltUpright__FiP4CRefP6CFrame */
undefined4 RefOpClqEvaluate(int arg0, CRef * arg1, CFrame * arg2); /* 0x116D20 RefOpClqEvaluate__FiP4CRefP6CFrame */
undefined4 RefOpClqEvaluateLm(int arg0, CRef * arg1, CFrame * arg2); /* 0x116DC8 RefOpClqEvaluateLm__FiP4CRefP6CFrame */
undefined4 RefOpClqFit(int arg0, CRef * arg1, CFrame * arg2); /* 0x116EA8 RefOpClqFit__FiP4CRefP6CFrame */
undefined4 RefOpLmLimit(int arg0, CRef * arg1, CFrame * arg2); /* 0x116FE8 RefOpLmLimit__FiP4CRefP6CFrame */
undefined4 RefOpLmCheck(int arg0, CRef * arg1, CFrame * arg2); /* 0x117080 RefOpLmCheck__FiP4CRefP6CFrame */
undefined4 RefOpFloor(int arg0, CRef * arg1, CFrame * arg2); /* 0x117118 RefOpFloor__FiP4CRefP6CFrame */
undefined4 RefOpCeiling(int arg0, CRef * arg1, CFrame * arg2); /* 0x117180 RefOpCeiling__FiP4CRefP6CFrame */
undefined4 RefOpRound(int arg0, CRef * arg1, CFrame * arg2); /* 0x1171F0 RefOpRound__FiP4CRefP6CFrame */
undefined4 RefOpTruncate(int arg0, CRef * arg1, CFrame * arg2); /* 0x117260 RefOpTruncate__FiP4CRefP6CFrame */
undefined4 RefOpAbs(int arg0, CRef * arg1, CFrame * arg2); /* 0x1172C8 RefOpAbs__FiP4CRefP6CFrame */
undefined4 RefOpMaximum(int arg0, CRef * arg1, CFrame * arg2); /* 0x117360 RefOpMaximum__FiP4CRefP6CFrame */
undefined4 RefOpMinimum(int arg0, CRef * arg1, CFrame * arg2); /* 0x117478 RefOpMinimum__FiP4CRefP6CFrame */
undefined4 RefOpModulo(int arg0, CRef * arg1, CFrame * arg2); /* 0x117598 RefOpModulo__FiP4CRefP6CFrame */
undefined4 RefOpCurrentTime(int arg0, CRef * arg1, CFrame * arg2); /* 0x117610 RefOpCurrentTime__FiP4CRefP6CFrame */
undefined4 RefOpScheduleCallback(int arg0, CRef * arg1, CFrame * arg2); /* 0x117668 RefOpScheduleCallback__FiP4CRefP6CFrame */
undefined4 RefOpDeferObjectUpdate(int arg0, CRef * arg1, CFrame * arg2); /* 0x117880 RefOpDeferObjectUpdate__FiP4CRefP6CFrame */
undefined4 RefOpObjectOption(int arg0, CRef * arg1, CFrame * arg2, BIFK arg3); /* 0x117910 RefOpObjectOption__FiP4CRefP6CFrame4BIFK */
undefined4 RefOpAddO(int arg0, CRef * arg1, CFrame * arg2); /* 0x117A30 RefOpAddO__FiP4CRefP6CFrame */
undefined4 RefOpEnsureO(int arg0, CRef * arg1, CFrame * arg2); /* 0x117A60 RefOpEnsureO__FiP4CRefP6CFrame */
undefined4 RefOpSetO(int arg0, CRef * arg1, CFrame * arg2); /* 0x117A90 RefOpSetO__FiP4CRefP6CFrame */
undefined4 RefOpGetO(int arg0, CRef * arg1, CFrame * arg2); /* 0x117AC0 RefOpGetO__FiP4CRefP6CFrame */
undefined4 RefPairFromAplo(int arg0, LO * * arg1); /* 0x117AF0 RefPairFromAplo__FiPP2LO */
undefined4 RefOpFindObject(int arg0, CRef * arg1, CFrame * arg2); /* 0x117BC8 RefOpFindObject__FiP4CRefP6CFrame */
undefined4 RefOpFindObjects(int arg0, CRef * arg1, CFrame * arg2); /* 0x117C48 RefOpFindObjects__FiP4CRefP6CFrame */
undefined4 RefOpFindNearestObject(int arg0, CRef * arg1, CFrame * arg2); /* 0x117D00 RefOpFindNearestObject__FiP4CRefP6CFrame */
undefined4 RefOpFindNearestObjects(int arg0, CRef * arg1, CFrame * arg2); /* 0x117D78 RefOpFindNearestObjects__FiP4CRefP6CFrame */
undefined4 RefOpFindPlayerObject(int arg0, CRef * arg1, CFrame * arg2); /* 0x117E20 RefOpFindPlayerObject__FiP4CRefP6CFrame */
undefined4 RefOpFindWorldObject(int arg0, CRef * arg1, CFrame * arg2); /* 0x117E78 RefOpFindWorldObject__FiP4CRefP6CFrame */
undefined4 RefOpFindCameraObject(int arg0, CRef * arg1, CFrame * arg2); /* 0x117ED0 RefOpFindCameraObject__FiP4CRefP6CFrame */
undefined4 RefOpFindClassObjects(int arg0, CRef * arg1, CFrame * arg2); /* 0x117F28 RefOpFindClassObjects__FiP4CRefP6CFrame */
undefined4 RefOpFindObjectsInBoundingBox(int arg0, CRef * arg1, CFrame * arg2); /* 0x117FE0 RefOpFindObjectsInBoundingBox__FiP4CRefP6CFrame */
undefined4 RefOpFindObjectsInBoundingSphere(int arg0, CRef * arg1, CFrame * arg2); /* 0x1180C0 RefOpFindObjectsInBoundingSphere__FiP4CRefP6CFrame */
undefined4 RefOpHitTestObjectsImpl(BIFK arg0, int arg1, CRef * arg2, CFrame * arg3); /* 0x118198 RefOpHitTestObjectsImpl__F4BIFKiP4CRefP6CFrame */
undefined4 RefOpHitTestObjects(int arg0, CRef * arg1, CFrame * arg2); /* 0x1183B8 RefOpHitTestObjects__FiP4CRefP6CFrame */
undefined4 RefOpHitTestObjectsFirst(int arg0, CRef * arg1, CFrame * arg2); /* 0x118458 RefOpHitTestObjectsFirst__FiP4CRefP6CFrame */
undefined4 RefOpConvertObjectPosition(int arg0, CRef * arg1, CFrame * arg2); /* 0x1184F8 RefOpConvertObjectPosition__FiP4CRefP6CFrame */
undefined4 RefOpConvertObjectVector(int arg0, CRef * arg1, CFrame * arg2); /* 0x118580 RefOpConvertObjectVector__FiP4CRefP6CFrame */
undefined4 RefOpConvertObjectMatrix(int arg0, CRef * arg1, CFrame * arg2); /* 0x118608 RefOpConvertObjectMatrix__FiP4CRefP6CFrame */
undefined4 RefOpNearClipCenter(int arg0, CRef * arg1, CFrame * arg2); /* 0x118698 RefOpNearClipCenter__FiP4CRefP6CFrame */
undefined4 RefOpStartSound(int arg0, CRef * arg1, CFrame * arg2); /* 0x118720 RefOpStartSound__FiP4CRefP6CFrame */
undefined4 RefOpStopSound(int arg0, CRef * arg1, CFrame * arg2); /* 0x1187E8 RefOpStopSound__FiP4CRefP6CFrame */
undefined4 RefOpStartRumble(int arg0, CRef * arg1, CFrame * arg2); /* 0x118850 RefOpStartRumble__FiP4CRefP6CFrame */
undefined4 RefOpEmitSmokeCloud(int arg0, CRef * arg1, CFrame * arg2); /* 0x1188F0 RefOpEmitSmokeCloud__FiP4CRefP6CFrame */
undefined4 RefOpPredictAnimationEffect(int arg0, CRef * arg1, CFrame * arg2); /* 0x118988 RefOpPredictAnimationEffect__FiP4CRefP6CFrame */
void VU_FLOAT_constructor(VU_FLOAT *this, float arg1); /* 0x118CF0 __8VU_FLOATf */
void VU_VECTOR_constructor(VU_VECTOR *this, const VECTOR * arg1); /* 0x118D10 __9VU_VECTORRC6VECTOR */
undefined4 VECTOR_op_assign(VECTOR *this, VU_VECTOR arg1); /* 0x118D20 __as__6VECTORG9VU_VECTOR */
undefined4 op_multiply(VU_FLOAT arg0, VU_VECTOR arg1); /* 0x118D30 __ml__FG8VU_FLOATG9VU_VECTOR */
undefined4 RefEvalSymbol(CPair * arg0, CFrame * arg1); /* 0x118D48 RefEvalSymbol__FP5CPairP6CFrame */
undefined4 RefEvalSet(CPair * arg0, CFrame * arg1); /* 0x118DB8 RefEvalSet__FP5CPairP6CFrame */
undefined4 RefEvalDefine(CPair * arg0, CFrame * arg1); /* 0x118E80 RefEvalDefine__FP5CPairP6CFrame */
undefined4 RefEvalAssert(CPair * arg0, CFrame * arg1); /* 0x118F48 RefEvalAssert__FP5CPairP6CFrame */
undefined4 RefEvalIf(CPair * arg0, CFrame * arg1); /* 0x119030 RefEvalIf__FP5CPairP6CFrame */
undefined4 RefEvalOr(CPair * arg0, CFrame * arg1); /* 0x119128 RefEvalOr__FP5CPairP6CFrame */
undefined4 RefEvalAnd(CPair * arg0, CFrame * arg1); /* 0x119218 RefEvalAnd__FP5CPairP6CFrame */
undefined4 RefEvalCond(CPair * arg0, CFrame * arg1); /* 0x119310 RefEvalCond__FP5CPairP6CFrame */
undefined4 RefEvalCase(CPair * arg0, CFrame * arg1); /* 0x1194A8 RefEvalCase__FP5CPairP6CFrame */
undefined4 RefEvalLet(CPair * arg0, CFrame * arg1); /* 0x1196C8 RefEvalLet__FP5CPairP6CFrame */
undefined4 RefEvalWhile(CPair * arg0, CFrame * arg1); /* 0x119878 RefEvalWhile__FP5CPairP6CFrame */
undefined4 RefEvalLambda(CPair * arg0, CFrame * arg1); /* 0x119970 RefEvalLambda__FP5CPairP6CFrame */
undefined4 RefEvalLambdaBody(CPair * arg0, CFrame * arg1); /* 0x119A58 RefEvalLambdaBody__FP5CPairP6CFrame */
undefined4 RefEvalBegin(CPair * arg0, CFrame * arg1); /* 0x119AF8 RefEvalBegin__FP5CPairP6CFrame */
undefined4 RefEvalApply(CPair * arg0, CFrame * arg1); /* 0x119BB0 RefEvalApply__FP5CPairP6CFrame */
undefined4 RefEvalImport(CPair * arg0, CFrame * arg1); /* 0x119FA0 RefEvalImport__FP5CPairP6CFrame */
undefined4 RefEval(CPair * arg0, CFrame * arg1); /* 0x11A080 RefEval__FP5CPairP6CFrame */
undefined4 CFrame_SetSingleParent(CFrame *this, CFrame * arg1); /* 0x11A328 SetSingleParent__6CFrameP6CFrame */
undefined4 CFrame_AddParent(CFrame *this, CFrame * arg1); /* 0x11A338 AddParent__6CFrameP6CFrame */
undefined4 CFrame_RefAddBinding(CFrame *this, unsigned int arg1, CRef * arg2); /* 0x11A358 RefAddBinding__6CFrameUiP4CRef */
undefined4 CFrame_RefSetBinding(CFrame *this, unsigned int arg1, CRef * arg2); /* 0x11A400 RefSetBinding__6CFrameUiP4CRef */
int CFrame_FFindBinding(CFrame *this, unsigned int arg1, int arg2, CRef * arg3); /* 0x11A498 FFindBinding__6CFrameUiiP4CRef */
void * CFrame_PrefFindBinding(CFrame *this, unsigned int arg1, int arg2); /* 0x11A4D8 PrefFindBinding__6CFrameUii */
undefined4 CFrame_CloneTo(CFrame *this, CFrame * arg1); /* 0x11A5B0 CloneTo__6CFrameP6CFrame */
void * PframeNew(void); /* 0x11A630 PframeNew__Fv */
undefined4 DeleteFrame(CFrame * arg0); /* 0x11A670 DeleteFrame__FP6CFrame */
void CGc_constructor(CGc *this); /* 0x11A678 __3CGc */
void CGc_destructor(CGc *this); /* 0x11A680 _$_3CGc */
undefined4 CGc_Startup(CGc *this); /* 0x11A6A8 Startup__3CGc */
undefined4 CGc_Shutdown(CGc *this); /* 0x11A6B8 Shutdown__3CGc */
undefined4 CGc_AddRootFrame(CGc *this, CFrame * arg1); /* 0x11A6C0 AddRootFrame__3CGcP6CFrame */
undefined4 CGc_AddRootSidebag(CGc *this, CSidebag * arg1); /* 0x11A708 AddRootSidebag__3CGcP8CSidebag */
void * CGc_PushFrame(CGc *this, CFrame * arg1); /* 0x11A728 PushFrame__3CGcP6CFrame */
void * CGc_PframePop(CGc *this); /* 0x11A748 PframePop__3CGc */
void * CGc_PushPair(CGc *this, CPair * arg1); /* 0x11A770 PushPair__3CGcP5CPair */
void * CGc_PpairPop(CGc *this); /* 0x11A790 PpairPop__3CGc */
void * CGc_PushProc(CGc *this, CProc * arg1); /* 0x11A7B8 PushProc__3CGcP5CProc */
void * CGc_PprocPop(CGc *this); /* 0x11A7D8 PprocPop__3CGc */
undefined4 CGc_UpdateRecyclable(CGc *this); /* 0x11A800 UpdateRecyclable__3CGc */
undefined4 CGc_MarkLiveObjects(CGc *this); /* 0x11A850 MarkLiveObjects__3CGc */
undefined4 CGc_Collect(CGc *this); /* 0x11AB58 Collect__3CGc */
void * PmethodNew(void); /* 0x11AE78 PmethodNew__Fv */
undefined4 CPair_CloneTo(CPair *this, CPair * arg1, CFrame * arg2); /* 0x11AEB8 CloneTo__5CPairP5CPairP6CFrame */
void * PpairNew(void); /* 0x11AF28 PpairNew__Fv */
undefined4 DeletePair(CPair * arg0); /* 0x11AF78 DeletePair__FP5CPair */
undefined4 CProc_CloneTo(CProc *this, CProc * arg1, CFrame * arg2); /* 0x11AF98 CloneTo__5CProcP5CProcP6CFrame */
void * PprocNew(void); /* 0x11AFC8 PprocNew__Fv */
void CRef_constructor(CRef *this); /* 0x11B008 __4CRef */
void CRef_constructor_2(CRef *this, const CRef * arg1); /* 0x11B018 __4CRefRC4CRef */
void CRef_destructor(CRef *this); /* 0x11B060 _$_4CRef */
undefined4 CRef_op_assign(CRef *this, const CRef * arg1); /* 0x11B0A8 __as__4CRefRC4CRef */
undefined4 CRef_op_equal(CRef *this, const CRef * arg1); /* 0x11B0F8 __eq__4CRefRC4CRef */
undefined4 CRef_CloneTo(CRef *this, CRef * arg1, CFrame * arg2); /* 0x11B258 CloneTo__4CRefP4CRefP6CFrame */
undefined4 CRef_Decref(CRef *this); /* 0x11B418 Decref__4CRef */
undefined4 CRef_Incref(CRef *this); /* 0x11B4A8 Incref__4CRef */
undefined4 CRef_SetTag(CRef *this, TAGK arg1); /* 0x11B538 SetTag__4CRef4TAGK */
undefined4 CRef_SetS32(CRef *this, int arg1); /* 0x11B570 SetS32__4CRefi */
undefined4 CRef_SetF32(CRef *this, float arg1); /* 0x11B5B0 SetF32__4CReff */
undefined4 CRef_SetBool(CRef *this, int arg1); /* 0x11B5F0 SetBool__4CRefi */
undefined4 CRef_SetSymid(CRef *this, unsigned int arg1); /* 0x11B640 SetSymid__4CRefUi */
undefined4 CRef_SetBifk(CRef *this, BIFK arg1); /* 0x11B680 SetBifk__4CRef4BIFK */
undefined4 CRef_SetPair(CRef *this, CPair * arg1); /* 0x11B6C0 SetPair__4CRefP5CPair */
undefined4 CRef_SetProc(CRef *this, CProc * arg1); /* 0x11B700 SetProc__4CRefP5CProc */
undefined4 CRef_SetVector(CRef *this, VECTOR * arg1); /* 0x11B740 SetVector__4CRefP6VECTOR */
undefined4 CRef_SetMatrix(CRef *this, MATRIX4 * arg1); /* 0x11B788 SetMatrix__4CRefP7MATRIX4 */
undefined4 CRef_SetClq(CRef *this, CLQ * arg1); /* 0x11B7D0 SetClq__4CRefP3CLQ */
undefined4 CRef_SetLm(CRef *this, LM * arg1); /* 0x11B818 SetLm__4CRefP2LM */
undefined4 CRef_SetSmp(CRef *this, SMP * arg1); /* 0x11B860 SetSmp__4CRefP3SMP */
undefined4 CRef_SetBasic(CRef *this, BASIC * arg1); /* 0x11B8A8 SetBasic__4CRefP5BASIC */
undefined4 CRef_SetMethod(CRef *this, CMethod * arg1); /* 0x11B8E8 SetMethod__4CRefP7CMethod */
undefined4 CRef_RefCoerceS32(CRef *this); /* 0x11B928 RefCoerceS32__4CRef */
undefined4 CRef_RefCoerceF32(CRef *this); /* 0x11B9A8 RefCoerceF32__4CRef */
void * PpairSerializeIn(CBinaryInputStream * arg0); /* 0x11BA28 PpairSerializeIn__FP18CBinaryInputStream */
undefined4 CSidebag_RefAddBinding(CSidebag *this, int arg1, CRef * arg2); /* 0x11BD28 RefAddBinding__8CSidebagiP4CRef */
undefined4 CSidebag_RefSetBinding(CSidebag *this, int arg1, CRef * arg2); /* 0x11BDD0 RefSetBinding__8CSidebagiP4CRef */
int CSidebag_FFindBinding(CSidebag *this, int arg1, CRef * arg2); /* 0x11BE90 FFindBinding__8CSidebagiP4CRef */
undefined4 CSidebag_CloneTo(CSidebag *this, CSidebag * arg1); /* 0x11BEE0 CloneTo__8CSidebagP8CSidebag */
undefined4 PsidebagNew(void); /* 0x11BF30 PsidebagNew__Fv */
undefined4 StartupSplice(void); /* 0x11BF70 StartupSplice__Fv */
undefined4 ShutdownSplice(void); /* 0x11C040 ShutdownSplice__Fv */
undefined4 CSplotheap_Startup(CSplotheap *this, int arg1, int arg2); /* 0x11C128 Startup__10CSplotheapii */
undefined4 CSplotheap_Shutdown(CSplotheap *this); /* 0x11C1D0 Shutdown__10CSplotheap */
void * CSplotheap_PvAllocUnsafe(CSplotheap *this); /* 0x11C1D8 PvAllocUnsafe__10CSplotheap */
void * CSplotheap_PvAllocClear(CSplotheap *this); /* 0x11C240 PvAllocClear__10CSplotheap */
void * CSplotheap_PsplotLookup(CSplotheap *this, int arg1); /* 0x11C288 PsplotLookup__10CSplotheapi */
undefined4 CSplotheap_UpdateRecyclable(CSplotheap *this); /* 0x11C2A0 UpdateRecyclable__10CSplotheap */
undefined4 CSplotheap_UnmarkAll(CSplotheap *this); /* 0x11C2B0 UnmarkAll__10CSplotheap */
undefined4 CSplotheap_FreeGarbage(CSplotheap *this); /* 0x11C2E8 FreeGarbage__10CSplotheap */
void * PvFromPsplot(SPLOT * arg0); /* 0x11C3B8 PvFromPsplot__FP5SPLOT */
void * PsplotFromPv(void * arg0); /* 0x11C3C0 PsplotFromPv__FPv */
int FIsPvGarbage(void * arg0); /* 0x11C3C8 FIsPvGarbage__FPv */
undefined4 MarkPvAlive(void * arg0); /* 0x11C3F0 MarkPvAlive__FPv */
undefined4 CVarb_CloneTo(CVarb *this, CVarb * arg1, CFrame * arg2); /* 0x11C418 CloneTo__5CVarbP5CVarbP6CFrame */
void * PvarbNew(void); /* 0x11C498 PvarbNew__Fv */
undefined4 DeleteVarb(CVarb * arg0); /* 0x11C4E8 DeleteVarb__FP5CVarb */
void * PvectorNew(void); /* 0x11C508 PvectorNew__Fv */
undefined4 IncrefVector(VECTOR * arg0); /* 0x11C580 IncrefVector__FP6VECTOR */
undefined4 DecrefVector(VECTOR * arg0); /* 0x11C5B0 DecrefVector__FP6VECTOR */
void * PmatrixNew(void); /* 0x11C618 PmatrixNew__Fv */
undefined4 IncrefMatrix(MATRIX4 * arg0); /* 0x11C690 IncrefMatrix__FP7MATRIX4 */
undefined4 DecrefMatrix(MATRIX4 * arg0); /* 0x11C6C0 DecrefMatrix__FP7MATRIX4 */
undefined4 DeleteMatrix(MATRIX4 * arg0); /* 0x11C720 DeleteMatrix__FP7MATRIX4 */
void * PclqNew(void); /* 0x11C748 PclqNew__Fv */
undefined4 IncrefClq(CLQ * arg0); /* 0x11C7C0 IncrefClq__FP3CLQ */
undefined4 DecrefClq(CLQ * arg0); /* 0x11C7F0 DecrefClq__FP3CLQ */
void * PlmNew(void); /* 0x11C858 PlmNew__Fv */
undefined4 IncrefLm(LM * arg0); /* 0x11C8D0 IncrefLm__FP2LM */
undefined4 DecrefLm(LM * arg0); /* 0x11C900 DecrefLm__FP2LM */
void * PsmpNew(void); /* 0x11C968 PsmpNew__Fv */
undefined4 IncrefSmp(SMP * arg0); /* 0x11C9E0 IncrefSmp__FP3SMP */
undefined4 DecrefSmp(SMP * arg0); /* 0x11CA20 DecrefSmp__FP3SMP */
undefined4 StartupSpliceStructuredTypeFactories(void); /* 0x11CA90 StartupSpliceStructuredTypeFactories__Fv */
undefined4 ShutdownSpliceStructuredTypeFactories(void); /* 0x11CBB0 ShutdownSpliceStructuredTypeFactories__Fv */
undefined4 snd_GotReturns(void); /* 0x11D078 snd_GotReturns__Fv */
undefined4 snd_PrepareReturnBuffer(unsigned int * arg0, int arg1); /* 0x11D110 snd_PrepareReturnBuffer__FPUii */
undefined4 snd_SendIOPCommandAndWait(int arg0, int arg1, char * arg2); /* 0x11D968 snd_SendIOPCommandAndWait__FiiPc */
undefined4 snd_SendIOPCommandNoWait(int arg0, int arg1, char * arg2, void (*arg3)(int, unsigned long), unsigned long arg4); /* 0x11DB00 snd_SendIOPCommandNoWait__FiiPcPFiUl_vUl */
undefined4 snd_PostMessage(void); /* 0x11DDD8 snd_PostMessage__Fv */
undefined4 snd_SendCurrentBatch(void); /* 0x11DE18 snd_SendCurrentBatch__Fv */
undefined4 StartupBrx(void); /* 0x11E560 StartupBrx__Fv */
void * PloNew(CID arg0, SW * arg1, ALO * arg2, OID arg3, int arg4); /* 0x11E580 PloNew__F3CIDP2SWP3ALO3OIDi */
undefined4 LoadOptionFromBrx(void * arg0, EOPID * arg1, CBinaryInputStream * arg2); /* 0x11E680 LoadOptionFromBrx__FPvP5EOPIDP18CBinaryInputStream */
undefined4 LoadOptionsFromBrx(void * arg0, CBinaryInputStream * arg1); /* 0x11EC40 LoadOptionsFromBrx__FPvP18CBinaryInputStream */
undefined4 IploFromStockOid(int arg0); /* 0x11ECA0 IploFromStockOid__Fi */
undefined4 LoadSwObjectsFromBrx(SW * arg0, ALO * arg1, CBinaryInputStream * arg2); /* 0x11ECB8 LoadSwObjectsFromBrx__FP2SWP3ALOP18CBinaryInputStream */
undefined4 SetLoDefaults(LO * arg0); /* 0x11EDA8 SetLoDefaults__FP2LO */
undefined4 FindKey(float arg0, int arg1, int arg2, int arg3, char * arg4, float * arg5, float * arg6, void * * arg7); /* 0x11EE70 FindKey__FfiiiPcPfT5PPv */
undefined4 EvaluateAcp(ACP * arg0, ALO * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x11EF40 EvaluateAcp__FP3ACPP3ALOffiP6VECTORT5 */
undefined4 GetAcpTimes(ACP * arg0, int * arg1, float * * arg2); /* 0x11EF48 GetAcpTimes__FP3ACPPiPPf */
undefined4 EvaluateAcr(ACR * arg0, ALO * arg1, float arg2, float arg3, int arg4, MATRIX3 * arg5, VECTOR * arg6); /* 0x11EF60 EvaluateAcr__FP3ACRP3ALOffiP7MATRIX3P6VECTOR */
undefined4 EvaluateAcrEul(ACR * arg0, ALO * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x11EF68 EvaluateAcrEul__FP3ACRP3ALOffiP6VECTORT5 */
undefined4 GetAcrTimes(ACR * arg0, int * arg1, float * * arg2); /* 0x11EF70 GetAcrTimes__FP3ACRPiPPf */
undefined4 EvaluateAcs(ACS * arg0, ALO * arg1, float arg2, int arg3, MATRIX3 * arg4); /* 0x11EF88 EvaluateAcs__FP3ACSP3ALOfiP7MATRIX3 */
undefined4 GetAcsTimes(ACS * arg0, int * arg1, float * * arg2); /* 0x11EF90 GetAcsTimes__FP3ACSPiPPf */
undefined4 EvaluateAcg(ACG * arg0, ALO * arg1, float arg2, float arg3, int arg4, float * arg5, float * arg6); /* 0x11EFA8 EvaluateAcg__FP3ACGP3ALOffiPfT5 */
undefined4 GetAcgTimes(ACG * arg0, int * arg1, float * * arg2); /* 0x11EFB0 GetAcgTimes__FP3ACGPiPPf */
undefined4 LoadAcgbFromBrx(ACGB * arg0, CBinaryInputStream * arg1); /* 0x11EFC8 LoadAcgbFromBrx__FP4ACGBP18CBinaryInputStream */
undefined4 EvaluateAcgb(ACGB * arg0, ALO * arg1, float arg2, float arg3, int arg4, float * arg5, float * arg6); /* 0x11F0C8 EvaluateAcgb__FP4ACGBP3ALOffiPfT5 */
undefined4 GetAcgbTimes(ACGB * arg0, int * arg1, float * * arg2); /* 0x11F180 GetAcgbTimes__FP4ACGBPiPPf */
undefined4 LoadAcgbwFromBrx(ACGBW * arg0, CBinaryInputStream * arg1); /* 0x11F210 LoadAcgbwFromBrx__FP5ACGBWP18CBinaryInputStream */
undefined4 EvaluateAcgbw(ACGBW * arg0, ALO * arg1, float arg2, float arg3, int arg4, float * arg5, float * arg6); /* 0x11F320 EvaluateAcgbw__FP5ACGBWP3ALOffiPfT5 */
undefined4 GetAcgbwTimes(ACGBW * arg0, int * arg1, float * * arg2); /* 0x11F3E8 GetAcgbwTimes__FP5ACGBWPiPPf */
undefined4 EvaluateAcgl(ACGL * arg0, ALO * arg1, float arg2, float arg3, int arg4, float * arg5, float * arg6); /* 0x11F478 EvaluateAcgl__FP4ACGLP3ALOffiPfT5 */
undefined4 LoadAcglFromBrx(ACGL * arg0, CBinaryInputStream * arg1); /* 0x11F568 LoadAcglFromBrx__FP4ACGLP18CBinaryInputStream */
undefined4 GetAcglTimes(ACGL * arg0, int * arg1, float * * arg2); /* 0x11F620 GetAcglTimes__FP4ACGLPiPPf */
undefined4 EvaluateApacg(ACG * * arg0, ALO * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6, VECTOR * arg7); /* 0x11F6B0 EvaluateApacg__FPP3ACGP3ALOffiP6VECTORN25 */
undefined4 LoadApacgFromBrx(ACG * * arg0, VECTOR * arg1, CBinaryInputStream * arg2); /* 0x11F798 LoadApacgFromBrx__FPP3ACGP6VECTORP18CBinaryInputStream */
undefined4 GetApacgTimes(ACG * * arg0, int * arg1, float * * arg2); /* 0x11F850 GetApacgTimes__FPP3ACGPiPPf */
undefined4 EvaluateAkvb(int arg0, KVB * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x11F9F8 EvaluateAkvb__FiP3KVBffiP6VECTORT5 */
undefined4 LoadAkvbFromBrx(int * arg0, KVB * * arg1, CBinaryInputStream * arg2); /* 0x11FA88 LoadAkvbFromBrx__FPiPP3KVBP18CBinaryInputStream */
undefined4 GetAkvbTimes(int arg0, KVB * arg1, int * arg2, float * * arg3); /* 0x11FB98 GetAkvbTimes__FiP3KVBPiPPf */
undefined4 EvaluateAcpc(ACPC * arg0, ALO * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x11FC20 EvaluateAcpc__FP4ACPCP3ALOffiP6VECTORT5 */
undefined4 LoadAcpcFromBrx(ACPC * arg0, CBinaryInputStream * arg1); /* 0x11FC90 LoadAcpcFromBrx__FP4ACPCP18CBinaryInputStream */
undefined4 GetAcpcTimes(ACPC * arg0, int * arg1, float * * arg2); /* 0x11FDB8 GetAcpcTimes__FP4ACPCPiPPf */
undefined4 EvaluateAcpb(ACPB * arg0, ALO * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x11FDD8 EvaluateAcpb__FP4ACPBP3ALOffiP6VECTORT5 */
undefined4 LoadAcpbFromBrx(ACPB * arg0, CBinaryInputStream * arg1); /* 0x11FE40 LoadAcpbFromBrx__FP4ACPBP18CBinaryInputStream */
undefined4 GetAcpbTimes(ACPB * arg0, int * arg1, float * * arg2); /* 0x11FED8 GetAcpbTimes__FP4ACPBPiPPf */
undefined4 EvaluateAcrc(ACRC * arg0, ALO * arg1, float arg2, float arg3, int arg4, MATRIX3 * arg5, VECTOR * arg6); /* 0x11FF08 EvaluateAcrc__FP4ACRCP3ALOffiP7MATRIX3P6VECTOR */
undefined4 EvaluateAcrcEul(ACRC * arg0, ALO * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x11FFA8 EvaluateAcrcEul__FP4ACRCP3ALOffiP6VECTORT5 */
undefined4 LoadAcrcFromBrx(ACRC * arg0, CBinaryInputStream * arg1); /* 0x11FFD8 LoadAcrcFromBrx__FP4ACRCP18CBinaryInputStream */
undefined4 GetAcrcTimes(ACRC * arg0, int * arg1, float * * arg2); /* 0x120110 GetAcrcTimes__FP4ACRCPiPPf */
undefined4 EvaluateAcrb(ACRB * arg0, ALO * arg1, float arg2, float arg3, int arg4, MATRIX3 * arg5, VECTOR * arg6); /* 0x120130 EvaluateAcrb__FP4ACRBP3ALOffiP7MATRIX3P6VECTOR */
undefined4 EvaluateAcrbEul(ACRB * arg0, ALO * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x1201D0 EvaluateAcrbEul__FP4ACRBP3ALOffiP6VECTORT5 */
undefined4 LoadAcrbFromBrx(ACRB * arg0, CBinaryInputStream * arg1); /* 0x1201F0 LoadAcrbFromBrx__FP4ACRBP18CBinaryInputStream */
undefined4 GetAcrbTimes(ACRB * arg0, int * arg1, float * * arg2); /* 0x1202C0 GetAcrbTimes__FP4ACRBPiPPf */
undefined4 EvaluateAcsc(ACSC * arg0, ALO * arg1, float arg2, int arg3, MATRIX3 * arg4); /* 0x1202F0 EvaluateAcsc__FP4ACSCP3ALOfiP7MATRIX3 */
undefined4 LoadAcscFromBrx(ACSC * arg0, CBinaryInputStream * arg1); /* 0x120360 LoadAcscFromBrx__FP4ACSCP18CBinaryInputStream */
undefined4 GetAcscTimes(ACSC * arg0, int * arg1, float * * arg2); /* 0x120388 GetAcscTimes__FP4ACSCPiPPf */
undefined4 EvaluateAcsb(ACSB * arg0, ALO * arg1, float arg2, int arg3, MATRIX3 * arg4); /* 0x1203A8 EvaluateAcsb__FP4ACSBP3ALOfiP7MATRIX3 */
undefined4 LoadAcsbFromBrx(ACSB * arg0, CBinaryInputStream * arg1); /* 0x120418 LoadAcsbFromBrx__FP4ACSBP18CBinaryInputStream */
undefined4 GetAcsbTimes(ACSB * arg0, int * arg1, float * * arg2); /* 0x120440 GetAcsbTimes__FP4ACSBPiPPf */
undefined4 EvaluateAcpbl(ACPBL * arg0, ALO * arg1, float arg2, float arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x120470 EvaluateAcpbl__FP5ACPBLP3ALOffiP6VECTORT5 */
undefined4 EvaluateAcrbl(ACRBL * arg0, ALO * arg1, float arg2, float arg3, int arg4, MATRIX3 * arg5, VECTOR * arg6); /* 0x120700 EvaluateAcrbl__FP5ACRBLP3ALOffiP7MATRIX3P6VECTOR */
undefined4 EvaluateAcgblt(ACGBLT * arg0, ALO * arg1, float arg2, float arg3, int arg4, float * arg5, float * arg6); /* 0x120AA8 EvaluateAcgblt__FP6ACGBLTP3ALOffiPfT5 */
undefined4 EvaluateAcgblp(ACGBLP * arg0, ALO * arg1, float arg2, float arg3, int arg4, float * arg5, float * arg6); /* 0x120D58 EvaluateAcgblp__FP6ACGBLPP3ALOffiPfT5 */
void * PacpNew(ACVK arg0); /* 0x120FB0 PacpNew__F4ACVK */
void * PacrNew(ACVK arg0); /* 0x121050 PacrNew__F4ACVK */
void * PacsNew(ACVK arg0); /* 0x1210F0 PacsNew__F4ACVK */
void * PacgNew(ACGK arg0); /* 0x121160 PacgNew__F4ACGK */
void * PactNew(SW * arg0, ALO * arg1, VTACT * arg2); /* 0x121228 PactNew__FP2SWP3ALOP5VTACT */
void * PactNewClone(ACT * arg0, SW * arg1, ALO * arg2); /* 0x121280 PactNewClone__FP3ACTP2SWP3ALO */
undefined4 CloneAct(ACT * arg0, ACT * arg1); /* 0x1212D8 CloneAct__FP3ACTT0 */
undefined4 InitAct(ACT * arg0, ALO * arg1); /* 0x121338 InitAct__FP3ACTP3ALO */
undefined4 RetractAct(ACT * arg0, int arg1); /* 0x121358 RetractAct__FP3ACTi */
undefined4 GetActPositionGoal(ACT * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1214B8 GetActPositionGoal__FP3ACTfP6VECTORT2 */
undefined4 GetActRotationGoal(ACT * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x121508 GetActRotationGoal__FP3ACTfP7MATRIX3P6VECTOR */
undefined4 GetActTwistGoal(ACT * arg0, float * arg1, float * arg2); /* 0x121568 GetActTwistGoal__FP3ACTPfT1 */
undefined4 GetActScale(ACT * arg0, MATRIX3 * arg1); /* 0x121580 GetActScale__FP3ACTP7MATRIX3 */
float GGetActPoseGoal(ACT * arg0, int arg1); /* 0x1215A8 GGetActPoseGoal__FP3ACTi */
undefined4 CalculateActDefaultAck(ACT * arg0); /* 0x1215C0 CalculateActDefaultAck__FP3ACT */
undefined4 SnapAct(ACT * arg0, int arg1); /* 0x121648 SnapAct__FP3ACTi */
undefined4 CalculateAloPositionSpring(ALO * arg0, float arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4); /* 0x121760 CalculateAloPositionSpring__FP3ALOfP6VECTORN22 */
void * ProjectActPosition(ACT * arg0); /* 0x1218C0 ProjectActPosition__FP3ACT */
undefined4 CalculateAloRotationSpring(ALO * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3, VECTOR * arg4); /* 0x121C48 CalculateAloRotationSpring__FP3ALOfP7MATRIX3P6VECTORT3 */
void * ProjectActRotation(ACT * arg0); /* 0x121DE0 ProjectActRotation__FP3ACT */
void * ProjectActPose(ACT * arg0, int arg1); /* 0x122488 ProjectActPose__FP3ACTi */
void * PredictAloPosition(ALO * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x122550 PredictAloPosition__FP3ALOfP6VECTORT2 */
void * PredictAloRotation(ALO * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x1225D0 PredictAloRotation__FP3ALOfP7MATRIX3P6VECTOR */
undefined4 AdaptAct(ACT * arg0); /* 0x1226D8 AdaptAct__FP3ACT */
undefined4 InitActval(ACTVAL * arg0, ALO * arg1); /* 0x122708 InitActval__FP6ACTVALP3ALO */
undefined4 GetActvalPositionGoal(ACTVAL * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1227B0 GetActvalPositionGoal__FP6ACTVALfP6VECTORT2 */
undefined4 GetActvalRotationGoal(ACTVAL * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x1227F0 GetActvalRotationGoal__FP6ACTVALfP7MATRIX3P6VECTOR */
undefined4 GetActvalTwistGoal(ACTVAL * arg0, float * arg1, float * arg2); /* 0x122840 GetActvalTwistGoal__FP6ACTVALPfT1 */
undefined4 GetActvalScale(ACTVAL * arg0, MATRIX3 * arg1); /* 0x122858 GetActvalScale__FP6ACTVALP7MATRIX3 */
float GGetActvalPoseGoal(ACTVAL * arg0, int arg1); /* 0x122878 GGetActvalPoseGoal__FP6ACTVALi */
undefined4 InitActref(ACTREF * arg0, ALO * arg1); /* 0x122890 InitActref__FP6ACTREFP3ALO */
undefined4 GetActrefPositionGoal(ACTREF * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x122920 GetActrefPositionGoal__FP6ACTREFfP6VECTORT2 */
undefined4 GetActrefRotationGoal(ACTREF * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x122968 GetActrefRotationGoal__FP6ACTREFfP7MATRIX3P6VECTOR */
undefined4 GetActrefTwistGoal(ACTREF * arg0, float * arg1, float * arg2); /* 0x1229C0 GetActrefTwistGoal__FP6ACTREFPfT1 */
undefined4 GetActrefScale(ACTREF * arg0, MATRIX3 * arg1); /* 0x1229E0 GetActrefScale__FP6ACTREFP7MATRIX3 */
float GGetActrefPoseGoal(ACTREF * arg0, int arg1); /* 0x122A00 GGetActrefPoseGoal__FP6ACTREFi */
undefined4 InitActadj(ACTADJ * arg0, ALO * arg1); /* 0x122A18 InitActadj__FP6ACTADJP3ALO */
undefined4 GetActadjPositionGoal(ACTADJ * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x122A80 GetActadjPositionGoal__FP6ACTADJfP6VECTORT2 */
undefined4 GetActadjRotationGoal(ACTADJ * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x122B30 GetActadjRotationGoal__FP6ACTADJfP7MATRIX3P6VECTOR */
undefined4 GetActadjTwistGoal(ACTADJ * arg0, float * arg1, float * arg2); /* 0x122C48 GetActadjTwistGoal__FP6ACTADJPfT1 */
undefined4 GetActadjScale(ACTADJ * arg0, MATRIX3 * arg1); /* 0x122CB0 GetActadjScale__FP6ACTADJP7MATRIX3 */
float GGetActadjPoseGoal(ACTADJ * arg0, int arg1); /* 0x122D90 GGetActadjPoseGoal__FP6ACTADJi */
undefined4 InitActbank(ACTBANK * arg0, ALO * arg1); /* 0x122DA0 InitActbank__FP7ACTBANKP3ALO */
undefined4 GetActbankRotationGoal(ACTBANK * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x122DE0 GetActbankRotationGoal__FP7ACTBANKfP7MATRIX3P6VECTOR */
undefined4 RetractActseg(ACTSEG * arg0, int arg1); /* 0x122F28 RetractActseg__FP6ACTSEGi */
undefined4 CloneActseg(ACTSEG * arg0, ACTSEG * arg1); /* 0x122F88 CloneActseg__FP6ACTSEGT0 */
undefined4 GetActsegPositionGoal(ACTSEG * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x122FE0 GetActsegPositionGoal__FP6ACTSEGfP6VECTORT2 */
undefined4 GetActsegRotationGoal(ACTSEG * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x123120 GetActsegRotationGoal__FP6ACTSEGfP7MATRIX3P6VECTOR */
undefined4 GetActsegTwistGoal(ACTSEG * arg0, float * arg1, float * arg2); /* 0x123270 GetActsegTwistGoal__FP6ACTSEGPfT1 */
undefined4 GetActsegScale(ACTSEG * arg0, MATRIX3 * arg1); /* 0x1232E8 GetActsegScale__FP6ACTSEGP7MATRIX3 */
float GGetActsegPoseGoal(ACTSEG * arg0, int arg1); /* 0x123358 GGetActsegPoseGoal__FP6ACTSEGi */
undefined4 BreakAlbrk(ALBRK * arg0); /* 0x1233C0 BreakAlbrk__FP5ALBRK */
undefined4 SetAlbrkAlarm(ALBRK * arg0, ALARM * arg1); /* 0x123400 SetAlbrkAlarm__FP5ALBRKP5ALARM */
undefined4 InitAlarm(ALARM * arg0); /* 0x123408 InitAlarm__FP5ALARM */
void * PostAlarmLoad(ALARM * arg0); /* 0x123448 PostAlarmLoad__FP5ALARM */
undefined4 CloneAlarm(ALARM * arg0, ALARM * arg1); /* 0x123540 CloneAlarm__FP5ALARMT0 */
undefined4 UpdateAlarm(ALARM * arg0, float arg1); /* 0x123578 UpdateAlarm__FP5ALARMf */
void * PostAlarmLoadCallbackHookup(ALARM * arg0, MSGID arg1, void * arg2); /* 0x1236C8 PostAlarmLoadCallbackHookup__FP5ALARM5MSGIDPv */
undefined4 SetAlarmAlarms(ALARM * arg0, ALARMS arg1); /* 0x123888 SetAlarmAlarms__FP5ALARM6ALARMS */
undefined4 TriggerAlarm(ALARM * arg0, ALTK arg1); /* 0x123AB0 TriggerAlarm__FP5ALARM4ALTK */
undefined4 DisableAlarmAlbrk(ALARM * arg0); /* 0x123B18 DisableAlarmAlbrk__FP5ALARM */
undefined4 EnableAlarmSensors(ALARM * arg0); /* 0x123B28 EnableAlarmSensors__FP5ALARM */
undefined4 DisableAlarmSensors(ALARM * arg0); /* 0x123BB0 DisableAlarmSensors__FP5ALARM */
undefined4 NotifyAlarmSensorsOnTrigger(ALARM * arg0); /* 0x123C20 NotifyAlarmSensorsOnTrigger__FP5ALARM */
undefined4 AddAlarmAlbrk(ALARM * arg0, OID arg1); /* 0x123C90 AddAlarmAlbrk__FP5ALARM3OID */
undefined4 AddAlarmSensor(ALARM * arg0, OID arg1); /* 0x123CB8 AddAlarmSensor__FP5ALARM3OID */
undefined4 AddAlarmStepguard(ALARM * arg0, OID arg1); /* 0x123CE0 AddAlarmStepguard__FP5ALARM3OID */
undefined4 SetAlarmRsmg(ALARM * arg0, int arg1, OID arg2, OID arg3, OID arg4); /* 0x123D08 SetAlarmRsmg__FP5ALARMi3OIDN22 */
int FGetAlarmSensorList(ALARM * arg0, void * arg1); /* 0x123D40 FGetAlarmSensorList__FP5ALARMPv */
int FIsZeroV(VECTOR * arg0); /* 0x123DC0 FIsZeroV__FP6VECTOR */
int FIsZeroW(VECTOR * arg0); /* 0x123E00 FIsZeroW__FP6VECTOR */
int FIsZeroDv(VECTOR * arg0); /* 0x123E48 FIsZeroDv__FP6VECTOR */
int FIsZeroDw(VECTOR * arg0); /* 0x123E88 FIsZeroDw__FP6VECTOR */
undefined4 InitAlo(ALO * arg0); /* 0x123ED0 InitAlo__FP3ALO */
undefined4 AddAloHierarchy(ALO * arg0); /* 0x124050 AddAloHierarchy__FP3ALO */
undefined4 OnAloAdd(ALO * arg0); /* 0x1240F8 OnAloAdd__FP3ALO */
undefined4 RemoveAloHierarchy(ALO * arg0); /* 0x124338 RemoveAloHierarchy__FP3ALO */
undefined4 OnAloRemove(ALO * arg0); /* 0x1243E0 OnAloRemove__FP3ALO */
undefined4 UpdateAloOrig(ALO * arg0); /* 0x124540 UpdateAloOrig__FP3ALO */
undefined4 SetAloParent(ALO * arg0, ALO * arg1); /* 0x1245A8 SetAloParent__FP3ALOT0 */
undefined4 ApplyAloProxy(ALO * arg0, PROXY * arg1); /* 0x124868 ApplyAloProxy__FP3ALOP5PROXY */
undefined4 BindAlo(ALO * arg0); /* 0x1249A8 BindAlo__FP3ALO */
void * PostAloLoad(ALO * arg0); /* 0x124A48 PostAloLoad__FP3ALO */
void * PostAloLoadCallback(ALO * arg0, MSGID arg1, void * arg2); /* 0x124CC0 PostAloLoadCallback__FP3ALO5MSGIDPv */
undefined4 SnipAloObjects(ALO * arg0, int arg1, SNIP * arg2); /* 0x124DF8 SnipAloObjects__FP3ALOiP4SNIP */
undefined4 UpdateAloHierarchy(ALO * arg0, float arg1); /* 0x124EE8 UpdateAloHierarchy__FP3ALOf */
undefined4 UpdateAlo(ALO * arg0, float arg1); /* 0x124FC0 UpdateAlo__FP3ALOf */
undefined4 InvalidateAloLighting(ALO * arg0); /* 0x1250C8 InvalidateAloLighting__FP3ALO */
undefined4 UpdateAloXfWorld(ALO * arg0); /* 0x125108 UpdateAloXfWorld__FP3ALO */
undefined4 UpdateAloXfWorldHierarchy(ALO * arg0); /* 0x125138 UpdateAloXfWorldHierarchy__FP3ALO */
void * PresetAloAccel(ALO * arg0, float arg1); /* 0x125438 PresetAloAccel__FP3ALOf */
void * ProjectAloTransform(ALO * arg0, float arg1, int arg2); /* 0x125440 ProjectAloTransform__FP3ALOfi */
void * PredictAloTransform(ALO * arg0, ALO * arg1, float arg2, VECTOR * arg3, MATRIX3 * arg4, VECTOR * arg5, VECTOR * arg6); /* 0x125750 PredictAloTransform__FP3ALOT0fP6VECTORP7MATRIX3T3T3 */
void * PredictAloTransformAdjust(ALO * arg0, ALO * arg1, float arg2, VECTOR * arg3, MATRIX3 * arg4, VECTOR * arg5, VECTOR * arg6); /* 0x1259D8 PredictAloTransformAdjust__FP3ALOT0fP6VECTORP7MATRIX3T3T3 */
undefined4 DupAloRo(ALO * arg0, RO * arg1, RO * arg2); /* 0x125B70 DupAloRo__FP3ALOP2ROT1 */
undefined4 RenderFastShadow(ALO * arg0, CM * arg1, RO * arg2); /* 0x125BF0 RenderFastShadow__FP3ALOP2CMP2RO */
undefined4 RenderAloAll(ALO * arg0, CM * arg1, RO * arg2); /* 0x125C90 RenderAloAll__FP3ALOP2CMP2RO */
undefined4 RenderAloSelf(ALO * arg0, CM * arg1, RO * arg2); /* 0x1261C0 RenderAloSelf__FP3ALOP2CMP2RO */
undefined4 RenderAloGlobset(ALO * arg0, CM * arg1, RO * arg2); /* 0x126270 RenderAloGlobset__FP3ALOP2CMP2RO */
undefined4 RenderAloLine(ALO * arg0, CM * arg1, VECTOR * arg2, VECTOR * arg3, float arg4, float arg5); /* 0x1268B8 RenderAloLine__FP3ALOP2CMP6VECTORT2ff */
undefined4 SetAloOverrideCel(ALO * arg0, RGBA arg1); /* 0x126A48 SetAloOverrideCel__FP3ALOG4RGBA */
undefined4 UpdateAloThrob(ALO * arg0, float arg1); /* 0x126AC8 UpdateAloThrob__FP3ALOf */
undefined4 SetAloBlotContext(ALO * arg0, BLOT * arg1); /* 0x126BC0 SetAloBlotContext__FP3ALOP4BLOT */
undefined4 EnsureAloFader(ALO * arg0); /* 0x126C58 EnsureAloFader__FP3ALO */
undefined4 FadeAloIn(ALO * arg0, float arg1); /* 0x126CB8 FadeAloIn__FP3ALOf */
undefined4 FadeAloOut(ALO * arg0, float arg1); /* 0x126D60 FadeAloOut__FP3ALOf */
undefined4 AdjustAloRtckMat(ALO * arg0, CM * arg1, RTCK arg2, VECTOR * arg3, MATRIX4 * arg4); /* 0x126DE8 AdjustAloRtckMat__FP3ALOP2CM4RTCKP6VECTORP7MATRIX4 */
undefined4 CloneAloHierarchy(ALO * arg0, ALO * arg1); /* 0x126F78 CloneAloHierarchy__FP3ALOT0 */
undefined4 CloneAlo(ALO * arg0, ALO * arg1); /* 0x127048 CloneAlo__FP3ALOT0 */
undefined4 HandleAloMessage(ALO * arg0, MSGID arg1, void * arg2); /* 0x127378 HandleAloMessage__FP3ALO5MSGIDPv */
undefined4 TranslateAloToPos(ALO * arg0, VECTOR * arg1); /* 0x1273F0 TranslateAloToPos__FP3ALOP6VECTOR */
undefined4 RotateAloToMat(ALO * arg0, MATRIX3 * arg1); /* 0x127478 RotateAloToMat__FP3ALOP7MATRIX3 */
undefined4 SetAloVelocityVec(ALO * arg0, VECTOR * arg1); /* 0x1274F8 SetAloVelocityVec__FP3ALOP6VECTOR */
undefined4 SetAloVelocityXYZ(ALO * arg0, float arg1, float arg2, float arg3); /* 0x127558 SetAloVelocityXYZ__FP3ALOfff */
undefined4 SetAloAngularVelocityVec(ALO * arg0, VECTOR * arg1); /* 0x127590 SetAloAngularVelocityVec__FP3ALOP6VECTOR */
undefined4 SetAloAngularVelocityXYZ(ALO * arg0, float arg1, float arg2, float arg3); /* 0x1275F0 SetAloAngularVelocityXYZ__FP3ALOfff */
undefined4 SetAloVelocityLocal(ALO * arg0, VECTOR * arg1); /* 0x127628 SetAloVelocityLocal__FP3ALOP6VECTOR */
undefined4 GetAloVelocityLocal(ALO * arg0, VECTOR * arg1); /* 0x127678 GetAloVelocityLocal__FP3ALOP6VECTOR */
undefined4 MatchAloOtherObject(ALO * arg0, ALO * arg1); /* 0x1276C0 MatchAloOtherObject__FP3ALOT0 */
undefined4 CalculateAloMovement(ALO * arg0, ALO * arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6); /* 0x1278A8 CalculateAloMovement__FP3ALOT0P6VECTORN42 */
undefined4 CalculateAloTransform(ALO * arg0, ALO * arg1, int arg2, VECTOR * arg3, MATRIX3 * arg4, VECTOR * arg5, VECTOR * arg6); /* 0x127B20 CalculateAloTransform__FP3ALOT0iP6VECTORP7MATRIX3T3T3 */
undefined4 CalculateAloTransformAdjust(ALO * arg0, ALO * arg1, VECTOR * arg2, MATRIX3 * arg3, VECTOR * arg4, VECTOR * arg5); /* 0x127E60 CalculateAloTransformAdjust__FP3ALOT0P6VECTORP7MATRIX3T2T2 */
undefined4 ConvertAloPos(ALO * arg0, ALO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x128018 ConvertAloPos__FP3ALOT0P6VECTORT2 */
undefined4 ConvertAloVec(ALO * arg0, ALO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1280C0 ConvertAloVec__FP3ALOT0P6VECTORT2 */
undefined4 ConvertAloMat(ALO * arg0, ALO * arg1, MATRIX3 * arg2, MATRIX3 * arg3); /* 0x128150 ConvertAloMat__FP3ALOT0P7MATRIX3T2 */
int FDrivenAlo(ALO * arg0); /* 0x128230 FDrivenAlo__FP3ALO */
undefined4 RetractAloDrive(ALO * arg0); /* 0x128278 RetractAloDrive__FP3ALO */
undefined4 ConvertAloMovement(ALO * arg0, ALO * arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6, VECTOR * arg7, VECTOR * arg8, VECTOR * arg9, VECTOR * arg10); /* 0x128330 ConvertAloMovement__FP3ALOT0P6VECTORN82 */
undefined4 CalculateAloDrive(ALO * arg0, CLQ * arg1, LM * arg2, float arg3, float arg4, float * arg5, float * arg6, float * arg7); /* 0x128598 CalculateAloDrive__FP3ALOP3CLQP2LMffPfN25 */
int FGetAloChildrenList(ALO * arg0, void * arg1); /* 0x1288F0 FGetAloChildrenList__FP3ALOPv */
void * PactsegNewAlo(ALO * arg0); /* 0x128998 PactsegNewAlo__FP3ALO */
undefined4 LoadAloFromBrx(ALO * arg0, CBinaryInputStream * arg1); /* 0x1289C0 LoadAloFromBrx__FP3ALOP18CBinaryInputStream */
undefined4 LoadAloAloxFromBrx(ALO * arg0, CBinaryInputStream * arg1); /* 0x128C10 LoadAloAloxFromBrx__FP3ALOP18CBinaryInputStream */
undefined4 BindAloAlox(ALO * arg0); /* 0x128DB8 BindAloAlox__FP3ALO */
undefined4 AdjustAloRotation(ALO * arg0, MATRIX3 * arg1, VECTOR * arg2); /* 0x128E88 AdjustAloRotation__FP3ALOP7MATRIX3P6VECTOR */
undefined4 UnadjustAloRotation(ALO * arg0, MATRIX3 * arg1); /* 0x128FD0 UnadjustAloRotation__FP3ALOP7MATRIX3 */
undefined4 SetAloInitialVelocity(ALO * arg0, VECTOR * arg1); /* 0x1290B8 SetAloInitialVelocity__FP3ALOP6VECTOR */
undefined4 SetAloInitialAngularVelocity(ALO * arg0, VECTOR * arg1); /* 0x1290E0 SetAloInitialAngularVelocity__FP3ALOP6VECTOR */
void * PasegdEnsureAlo(ALO * arg0); /* 0x129108 PasegdEnsureAlo__FP3ALO */
undefined4 SetAloFastShadowRadius(ALO * arg0, float arg1); /* 0x129170 SetAloFastShadowRadius__FP3ALOf */
undefined4 GetAloFastShadowRadius(ALO * arg0, float * arg1); /* 0x129188 GetAloFastShadowRadius__FP3ALOPf */
undefined4 SetAloFastShadowDepth(ALO * arg0, float arg1); /* 0x1291A0 SetAloFastShadowDepth__FP3ALOf */
undefined4 GetAloFastShadowDepth(ALO * arg0, float * arg1); /* 0x1291B8 GetAloFastShadowDepth__FP3ALOPf */
void * PshadowAloEnsure(ALO * arg0); /* 0x1291D0 PshadowAloEnsure__FP3ALO */
undefined4 SetAloCastShadow(ALO * arg0, int arg1); /* 0x129228 SetAloCastShadow__FP3ALOi */
undefined4 SetAloShadowShader(ALO * arg0, OID arg1); /* 0x129288 SetAloShadowShader__FP3ALO3OID */
undefined4 SetAloShadowNearRadius(ALO * arg0, float arg1); /* 0x1292B8 SetAloShadowNearRadius__FP3ALOf */
undefined4 SetAloShadowFarRadius(ALO * arg0, float arg1); /* 0x1292E8 SetAloShadowFarRadius__FP3ALOf */
undefined4 SetAloShadowNearCast(ALO * arg0, float arg1); /* 0x129318 SetAloShadowNearCast__FP3ALOf */
undefined4 SetAloShadowFarCast(ALO * arg0, float arg1); /* 0x129348 SetAloShadowFarCast__FP3ALOf */
undefined4 SetAloShadowConeAngle(ALO * arg0, float arg1); /* 0x129378 SetAloShadowConeAngle__FP3ALOf */
undefined4 SetAloShadowFrustrumUp(ALO * arg0, VECTOR * arg1); /* 0x1293A8 SetAloShadowFrustrumUp__FP3ALOP6VECTOR */
undefined4 SetAloDynamicShadowObject(ALO * arg0, OID arg1); /* 0x1293D8 SetAloDynamicShadowObject__FP3ALO3OID */
void * PshadowInferAlo(ALO * arg0); /* 0x129400 PshadowInferAlo__FP3ALO */
undefined4 GetAloCastShadow(ALO * arg0, int * arg1); /* 0x129440 GetAloCastShadow__FP3ALOPi */
undefined4 GetAloShadowShader(ALO * arg0, OID * arg1); /* 0x129450 GetAloShadowShader__FP3ALOP3OID */
undefined4 GetAloShadowNearRadius(ALO * arg0, float * arg1); /* 0x129480 GetAloShadowNearRadius__FP3ALOPf */
undefined4 GetAloShadowFarRadius(ALO * arg0, float * arg1); /* 0x1294B0 GetAloShadowFarRadius__FP3ALOPf */
undefined4 GetAloShadowNearCast(ALO * arg0, float * arg1); /* 0x1294E0 GetAloShadowNearCast__FP3ALOPf */
undefined4 GetAloShadowFarCast(ALO * arg0, float * arg1); /* 0x129510 GetAloShadowFarCast__FP3ALOPf */
undefined4 GetAloShadowConeAngle(ALO * arg0, float * arg1); /* 0x129540 GetAloShadowConeAngle__FP3ALOPf */
undefined4 GetAloShadowFrustrumUp(ALO * arg0, VECTOR * arg1); /* 0x129598 GetAloShadowFrustrumUp__FP3ALOP6VECTOR */
undefined4 GetAloEuler(ALO * arg0, VECTOR * arg1); /* 0x1295C8 GetAloEuler__FP3ALOP6VECTOR */
undefined4 SetAloEuler(ALO * arg0, VECTOR * arg1); /* 0x129648 SetAloEuler__FP3ALOP6VECTOR */
undefined4 EnsureAloActRestore(ALO * arg0); /* 0x1296E0 EnsureAloActRestore__FP3ALO */
undefined4 EnsureAloActla(ALO * arg0); /* 0x129730 EnsureAloActla__FP3ALO */
undefined4 RecacheAloActList(ALO * arg0); /* 0x129780 RecacheAloActList__FP3ALO */
undefined4 InsertAloAct(ALO * arg0, ACT * arg1); /* 0x1299E0 InsertAloAct__FP3ALOP3ACT */
undefined4 ResortAloActList(ALO * arg0); /* 0x129A58 ResortAloActList__FP3ALO */
void * PasegaFindAlo(ALO * arg0, OID arg1); /* 0x129B98 PasegaFindAlo__FP3ALO3OID */
void * PsmaFindAlo(ALO * arg0, OID arg1); /* 0x129C20 PsmaFindAlo__FP3ALO3OID */
void * PasegaFindAloNearest(ALO * arg0); /* 0x129CA8 PasegaFindAloNearest__FP3ALO */
undefined4 CreateAloActadj(ALO * arg0, int arg1, ACTADJ * * arg2); /* 0x129D00 CreateAloActadj__FP3ALOiPP6ACTADJ */
int FIsAloStatic(ALO * arg0); /* 0x129D70 FIsAloStatic__FP3ALO */
undefined4 ResolveAlo(ALO * arg0); /* 0x129DF8 ResolveAlo__FP3ALO */
undefined4 SetAloPositionSpring(ALO * arg0, float arg1); /* 0x129E10 SetAloPositionSpring__FP3ALOf */
undefined4 SetAloPositionSpringDetail(ALO * arg0, CLQ * arg1); /* 0x129E88 SetAloPositionSpringDetail__FP3ALOP3CLQ */
undefined4 SetAloPositionDamping(ALO * arg0, float arg1); /* 0x129EE0 SetAloPositionDamping__FP3ALOf */
undefined4 SetAloPositionDampingDetail(ALO * arg0, CLQ * arg1); /* 0x129F58 SetAloPositionDampingDetail__FP3ALOP3CLQ */
undefined4 SetAloRotationSpring(ALO * arg0, float arg1); /* 0x129FB0 SetAloRotationSpring__FP3ALOf */
undefined4 SetAloRotationSpringDetail(ALO * arg0, CLQ * arg1); /* 0x12A028 SetAloRotationSpringDetail__FP3ALOP3CLQ */
undefined4 SetAloRotationDamping(ALO * arg0, float arg1); /* 0x12A080 SetAloRotationDamping__FP3ALOf */
undefined4 SetAloRotationDampingDetail(ALO * arg0, CLQ * arg1); /* 0x12A0F8 SetAloRotationDampingDetail__FP3ALOP3CLQ */
undefined4 SetAloPositionSmooth(ALO * arg0, float arg1); /* 0x12A150 SetAloPositionSmooth__FP3ALOf */
undefined4 SetAloPositionSmoothMaxAccel(ALO * arg0, float arg1); /* 0x12A1A0 SetAloPositionSmoothMaxAccel__FP3ALOf */
undefined4 SetAloPositionSmoothDetail(ALO * arg0, SMPA * arg1); /* 0x12A200 SetAloPositionSmoothDetail__FP3ALOP4SMPA */
undefined4 SetAloRotationSmooth(ALO * arg0, float arg1); /* 0x12A270 SetAloRotationSmooth__FP3ALOf */
undefined4 SetAloRotationSmoothMaxAccel(ALO * arg0, float arg1); /* 0x12A2C0 SetAloRotationSmoothMaxAccel__FP3ALOf */
undefined4 SetAloRotationSmoothDetail(ALO * arg0, SMPA * arg1); /* 0x12A320 SetAloRotationSmoothDetail__FP3ALOP4SMPA */
undefined4 SetAloDefaultAckPos(ALO * arg0, ACK arg1); /* 0x12A390 SetAloDefaultAckPos__FP3ALO3ACK */
undefined4 SetAloDefaultAckRot(ALO * arg0, ACK arg1); /* 0x12A398 SetAloDefaultAckRot__FP3ALO3ACK */
undefined4 SetAloRestorePosition(ALO * arg0, int arg1); /* 0x12A3A0 SetAloRestorePosition__FP3ALOi */
undefined4 SetAloRestorePositionAck(ALO * arg0, ACK arg1); /* 0x12A430 SetAloRestorePositionAck__FP3ALO3ACK */
undefined4 SetAloRestoreRotation(ALO * arg0, int arg1); /* 0x12A478 SetAloRestoreRotation__FP3ALOi */
undefined4 SetAloRestoreRotationAck(ALO * arg0, ACK arg1); /* 0x12A4A0 SetAloRestoreRotationAck__FP3ALO3ACK */
undefined4 SetAloLookAt(ALO * arg0, ACK arg1); /* 0x12A528 SetAloLookAt__FP3ALO3ACK */
undefined4 SetAloLookAtIgnore(ALO * arg0, float arg1); /* 0x12A580 SetAloLookAtIgnore__FP3ALOf */
undefined4 GetAloLookAtIgnore(ALO * arg0, float * arg1); /* 0x12A5B8 GetAloLookAtIgnore__FP3ALOPf */
undefined4 SetAloLookAtPanFunction(ALO * arg0, CLQ * arg1); /* 0x12A5D0 SetAloLookAtPanFunction__FP3ALOP3CLQ */
undefined4 GetAloLookAtPanFunction(ALO * arg0, CLQ * arg1); /* 0x12A610 GetAloLookAtPanFunction__FP3ALOP3CLQ */
undefined4 SetAloLookAtPanLimits(ALO * arg0, LM * arg1); /* 0x12A630 SetAloLookAtPanLimits__FP3ALOP2LM */
undefined4 GetAloLookAtPanLimits(ALO * arg0, LM * arg1); /* 0x12A678 GetAloLookAtPanLimits__FP3ALOP2LM */
undefined4 SetAloLookAtTiltFunction(ALO * arg0, CLQ * arg1); /* 0x12A6A0 SetAloLookAtTiltFunction__FP3ALOP3CLQ */
undefined4 GetAloLookAtTiltFunction(ALO * arg0, CLQ * arg1); /* 0x12A6E0 GetAloLookAtTiltFunction__FP3ALOP3CLQ */
undefined4 SetAloLookAtTiltLimits(ALO * arg0, LM * arg1); /* 0x12A700 SetAloLookAtTiltLimits__FP3ALOP2LM */
undefined4 GetAloLookAtTiltLimits(ALO * arg0, LM * arg1); /* 0x12A748 GetAloLookAtTiltLimits__FP3ALOP2LM */
undefined4 SetAloLookAtEnabledPriority(ALO * arg0, int arg1); /* 0x12A770 SetAloLookAtEnabledPriority__FP3ALOi */
undefined4 GetAloLookAtEnabledPriority(ALO * arg0, int * arg1); /* 0x12A7A8 GetAloLookAtEnabledPriority__FP3ALOPi */
undefined4 SetAloLookAtDisabledPriority(ALO * arg0, int arg1); /* 0x12A7C0 SetAloLookAtDisabledPriority__FP3ALOi */
undefined4 GetAloLookAtDisabledPriority(ALO * arg0, int * arg1); /* 0x12A7F8 GetAloLookAtDisabledPriority__FP3ALOPi */
int FUN_0012a8b8(ALO * arg0); /* 0x12A8B8 FUN_0012a8b8__FP3ALO */
undefined4 SetAloRotationMatchesVelocity(ALO * arg0, float arg1, float arg2, ACK arg3); /* 0x12A8D8 SetAloRotationMatchesVelocity__FP3ALOff3ACK */
void * PtargetEnsureAlo(ALO * arg0); /* 0x12A970 PtargetEnsureAlo__FP3ALO */
undefined4 SetAloTargetAttacks(ALO * arg0, int arg1); /* 0x12A9C8 SetAloTargetAttacks__FP3ALOi */
undefined4 SetAloTargetRadius(ALO * arg0, float arg1); /* 0x12AA00 SetAloTargetRadius__FP3ALOf */
undefined4 SetAloTargetHitTest(ALO * arg0, int arg1); /* 0x12AA28 SetAloTargetHitTest__FP3ALOi */
undefined4 SetAloScrollingMasterSpeeds(ALO * arg0, float arg1, float arg2); /* 0x12AA50 SetAloScrollingMasterSpeeds__FP3ALOff */
undefined4 SetAloEyesClosed(ALO * arg0, float arg1); /* 0x12AAE8 SetAloEyesClosed__FP3ALOf */
undefined4 EnsureAloSfx(ALO * arg0); /* 0x12ABA8 EnsureAloSfx__FP3ALO */
undefined4 SetAloSfxid(ALO * arg0, SFXID arg1); /* 0x12ABD0 SetAloSfxid__FP3ALO5SFXID */
undefined4 SetAloSfxidSpl(ALO * arg0, SFXID arg1); /* 0x12AC08 SetAloSfxidSpl__FP3ALO5SFXID */
undefined4 GetAloSfxid(ALO * arg0, SFXID * arg1); /* 0x12AC88 GetAloSfxid__FP3ALOP5SFXID */
undefined4 SetAloSStart(ALO * arg0, float arg1); /* 0x12ACA0 SetAloSStart__FP3ALOf */
undefined4 GetAloSStart(ALO * arg0, float * arg1); /* 0x12ACD8 GetAloSStart__FP3ALOPf */
undefined4 SetAloSFull(ALO * arg0, float arg1); /* 0x12ACF8 SetAloSFull__FP3ALOf */
undefined4 SetAloSndRepeat(ALO * arg0, LM * arg1); /* 0x12AD30 SetAloSndRepeat__FP3ALOP2LM */
undefined4 GetAloSFull(ALO * arg0, float * arg1); /* 0x12AD78 GetAloSFull__FP3ALOPf */
undefined4 SetAloUVolume(ALO * arg0, float arg1); /* 0x12AD98 SetAloUVolume__FP3ALOf */
undefined4 SetAloUDoppler(ALO * arg0, float arg1); /* 0x12ADD0 SetAloUDoppler__FP3ALOf */
undefined4 GetAloUDoppler(ALO * arg0, float * arg1); /* 0x12AE08 GetAloUDoppler__FP3ALOPf */
undefined4 SetAloUVolumeSpl(ALO * arg0, float arg1); /* 0x12AE20 SetAloUVolumeSpl__FP3ALOf */
undefined4 GetAloUVolume(ALO * arg0, float * arg1); /* 0x12AE58 GetAloUVolume__FP3ALOPf */
undefined4 SetAloUPitch(ALO * arg0, float arg1); /* 0x12AE78 SetAloUPitch__FP3ALOf */
undefined4 SetAloUPitchSpl(ALO * arg0, float arg1); /* 0x12AEB0 SetAloUPitchSpl__FP3ALOf */
undefined4 GetAloUPitch(ALO * arg0, float * arg1); /* 0x12AEE8 GetAloUPitch__FP3ALOPf */
undefined4 GetAloSndRepeat(ALO * arg0, LM * arg1); /* 0x12AF00 GetAloSndRepeat__FP3ALOP2LM */
undefined4 StartAloSound(ALO * arg0, SFXID arg1, float arg2, float arg3, float arg4, LM * arg5); /* 0x12AF38 StartAloSound__FP3ALO5SFXIDfffP2LM */
undefined4 StopAloSound(ALO * arg0); /* 0x12B010 StopAloSound__FP3ALO */
undefined4 EnsureAloThrob(ALO * arg0); /* 0x12B040 EnsureAloThrob__FP3ALO */
undefined4 SetAloThrobKind(ALO * arg0, THROBK arg1); /* 0x12B0B0 SetAloThrobKind__FP3ALO6THROBK */
undefined4 GetAloThrobKind(ALO * arg0, THROBK * arg1); /* 0x12B128 GetAloThrobKind__FP3ALOP6THROBK */
undefined4 SetAloThrobInColor(ALO * arg0, VECTOR * arg1); /* 0x12B140 SetAloThrobInColor__FP3ALOP6VECTOR */
undefined4 GetAloThrobInColor(ALO * arg0, VECTOR * arg1); /* 0x12B180 GetAloThrobInColor__FP3ALOP6VECTOR */
undefined4 SetAloThrobOutColor(ALO * arg0, VECTOR * arg1); /* 0x12B1A0 SetAloThrobOutColor__FP3ALOP6VECTOR */
undefined4 GetAloThrobOutColor(ALO * arg0, VECTOR * arg1); /* 0x12B1E0 GetAloThrobOutColor__FP3ALOP6VECTOR */
undefined4 SetAloThrobDtInOut(ALO * arg0, float arg1); /* 0x12B200 SetAloThrobDtInOut__FP3ALOf */
undefined4 GetAloThrobDtInOut(ALO * arg0, float * arg1); /* 0x12B238 GetAloThrobDtInOut__FP3ALOPf */
undefined4 SetAloInteractCane(ALO * arg0, int arg1); /* 0x12B250 SetAloInteractCane__FP3ALOi */
undefined4 GetAloInteractCane(ALO * arg0, int * arg1); /* 0x12B260 GetAloInteractCane__FP3ALOPi */
undefined4 SetAloInteractCaneSweep(ALO * arg0, int arg1); /* 0x12B270 SetAloInteractCaneSweep__FP3ALOi */
undefined4 GetAloInteractCaneSweep(ALO * arg0, int * arg1); /* 0x12B278 GetAloInteractCaneSweep__FP3ALOPi */
undefined4 SetAloInteractCaneRush(ALO * arg0, int arg1); /* 0x12B288 SetAloInteractCaneRush__FP3ALOi */
undefined4 GetAloInteractCaneRush(ALO * arg0, int * arg1); /* 0x12B290 GetAloInteractCaneRush__FP3ALOPi */
undefined4 SetAloInteractCaneSmash(ALO * arg0, int arg1); /* 0x12B2A0 SetAloInteractCaneSmash__FP3ALOi */
undefined4 GetAloInteractCaneSmash(ALO * arg0, int * arg1); /* 0x12B2A8 GetAloInteractCaneSmash__FP3ALOPi */
undefined4 SetAloInteractBomb(ALO * arg0, int arg1); /* 0x12B2B8 SetAloInteractBomb__FP3ALOi */
undefined4 GetAloInteractBomb(ALO * arg0, int * arg1); /* 0x12B2C0 GetAloInteractBomb__FP3ALOPi */
undefined4 SetAloInteractShock(ALO * arg0, int arg1); /* 0x12B2D0 SetAloInteractShock__FP3ALOi */
undefined4 GetAloInteractShock(ALO * arg0, int * arg1); /* 0x12B2D8 GetAloInteractShock__FP3ALOPi */
int FAbsorbAloWkr(ALO * arg0, WKR * arg1); /* 0x12B2E8 FAbsorbAloWkr__FP3ALOP3WKR */
undefined4 SetAloPoseCombo(ALO * arg0, OID arg1); /* 0x12B2F8 SetAloPoseCombo__FP3ALO3OID */
undefined4 SetAloForceCameraFade(ALO * arg0, int arg1); /* 0x12B420 SetAloForceCameraFade__FP3ALOi */
undefined4 SetAloRealClock(ALO * arg0, int arg1); /* 0x12B4C8 SetAloRealClock__FP3ALOi */
undefined4 StartupAseg(void); /* 0x12B868 StartupAseg__Fv */
undefined4 InitAseg(ASEG * arg0); /* 0x12B870 InitAseg__FP4ASEG */
undefined4 LoadAsegFromBrx(ASEG * arg0, CBinaryInputStream * arg1); /* 0x12B8C8 LoadAsegFromBrx__FP4ASEGP18CBinaryInputStream */
undefined4 LoadAsegEventsFromBrx(ASEG * arg0, CBinaryInputStream * arg1, int arg2, int * arg3, EA * * arg4); /* 0x12BC38 LoadAsegEventsFromBrx__FP4ASEGP18CBinaryInputStreamiPiPP2EA */
undefined4 CloneAseg(ASEG * arg0, LO * arg1); /* 0x12C140 CloneAseg__FP4ASEGP2LO */
void * PostAsegLoad(ASEG * arg0); /* 0x12C160 PostAsegLoad__FP4ASEG */
void * PostAsegLoadCallback(ASEG * arg0, MSGID arg1, void * arg2); /* 0x12C208 PostAsegLoadCallback__FP4ASEG5MSGIDPv */
undefined4 ApplyAsegOvr(ASEG * arg0, ALO * arg1, int arg2, OVR * arg3, float arg4, float arg5, int arg6, ASEGA * * arg7); /* 0x12C288 ApplyAsegOvr__FP4ASEGP3ALOiP3OVRffiPP5ASEGA */
undefined4 ApplyAseg(ASEG * arg0, ALO * arg1, float arg2, float arg3, int arg4, ASEGA * * arg5); /* 0x12C7B0 ApplyAseg__FP4ASEGP3ALOffiPP5ASEGA */
void * PasegaApplyAseg(ASEG * arg0, ALO * arg1, float arg2, float arg3, int arg4); /* 0x12C7D8 PasegaApplyAseg__FP4ASEGP3ALOffi */
void * PasegaFindAseg(ASEG * arg0, ALO * arg1); /* 0x12C808 PasegaFindAseg__FP4ASEGP3ALO */
undefined4 EnsureAseg(ASEG * arg0, ALO * arg1, SEEK arg2, float arg3, float arg4, int arg5, ASEGA * * arg6); /* 0x12C840 EnsureAseg__FP4ASEGP3ALO4SEEKffiPP5ASEGA */
void * PasegaEnsureAseg(ASEG * arg0, ALO * arg1, SEEK arg2, float arg3, float arg4, int arg5); /* 0x12C8F8 PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi */
undefined4 ApplyAsegCur(ASEG * arg0, ALO * arg1, float arg2, float arg3, int arg4, ASEGA * * arg5); /* 0x12C918 ApplyAsegCur__FP4ASEGP3ALOffiPP5ASEGA */
int FWipingAseg(ASEG * arg0); /* 0x12C9A8 FWipingAseg__FP4ASEG */
undefined4 FindAsegClosestPoint(ASEG * arg0, ALO * arg1, VECTOR * arg2, float arg3, float * arg4, VECTOR * arg5, VECTOR * arg6); /* 0x12C9E8 FindAsegClosestPoint__FP4ASEGP3ALOP6VECTORfPfT2T2 */
void * PeaFindAsegLabel(ASEG * arg0, OID arg1); /* 0x12CBE8 PeaFindAsegLabel__FP4ASEG3OID */
undefined4 TFindAsegLabel(ASEG * arg0, OID arg1); /* 0x12CCC0 TFindAsegLabel__FP4ASEG3OID */
void * PchnFindAseg(ASEG * arg0, ALO * arg1); /* 0x12CCE8 PchnFindAseg__FP4ASEGP3ALO */
void * PredictAsegEffect(ASEG * arg0, float arg1, float arg2, ALO * arg3, ALO * arg4, int arg5, VECTOR * arg6, MATRIX3 * arg7, VECTOR * arg8, VECTOR * arg9); /* 0x12CD78 PredictAsegEffect__FP4ASEGffP3ALOT3iP6VECTORP7MATRIX3T6T6 */
undefined4 GetAsegWaypoints(ASEG * arg0, ALO * arg1, int * arg2, WAYPOINT * * * arg3); /* 0x12D1B0 GetAsegWaypoints__FP4ASEGP3ALOPiPPP8WAYPOINT */
undefined4 StripAsegChn(ASEG * arg0, CHN * arg1); /* 0x12D2A8 StripAsegChn__FP4ASEGP3CHN */
undefined4 StripAsegAlo(ASEG * arg0, ALO * arg1); /* 0x12D398 StripAsegAlo__FP4ASEGP3ALO */
undefined4 LoadAsegblFromBrx(ASEGBL * arg0, CBinaryInputStream * arg1); /* 0x12D3E0 LoadAsegblFromBrx__FP6ASEGBLP18CBinaryInputStream */
void * PostAsegblLoad(ASEGBL * arg0); /* 0x12D3E8 PostAsegblLoad__FP6ASEGBL */
undefined4 CloneAsegbl(ASEGBL * arg0, LO * arg1); /* 0x12D3F0 CloneAsegbl__FP6ASEGBLP2LO */
void * PasegaNew(SW * arg0); /* 0x12D3F8 PasegaNew__FP2SW */
undefined4 SetAsegaHandsOff(ASEGA * arg0, int arg1); /* 0x12D448 SetAsegaHandsOff__FP5ASEGAi */
undefined4 UpdateAsegaIeaCur(ASEGA * arg0); /* 0x12D4A8 UpdateAsegaIeaCur__FP5ASEGA */
void * PactsegFindAsega(ASEGA * arg0, OID arg1); /* 0x12D570 PactsegFindAsega__FP5ASEGA3OID */
undefined4 HandleAsegaEvent(ASEGA * arg0, EA * arg1, int * arg2); /* 0x12D5D0 HandleAsegaEvent__FP5ASEGAP2EAPi */
undefined4 HandleAsegaEventsFF(ASEGA * arg0, ASEG * arg1, int * arg2); /* 0x12E4E0 HandleAsegaEventsFF__FP5ASEGAP4ASEGPi */
undefined4 HandleAsegaEvents(ASEGA * arg0, ASEG * arg1, int * arg2); /* 0x12E5D0 HandleAsegaEvents__FP5ASEGAP4ASEGPi */
undefined4 RemoveAsega(ASEGA * arg0); /* 0x12E710 RemoveAsega__FP5ASEGA */
undefined4 RetractAsega(ASEGA * arg0); /* 0x12E760 RetractAsega__FP5ASEGA */
undefined4 UFromEaErrorFunc(EA * arg0, float arg1); /* 0x12E968 UFromEaErrorFunc__FP2EAf */
int FWrapAsegaTime(ASEGA * arg0, float * arg1, float * arg2); /* 0x12E9E0 FWrapAsegaTime__FP5ASEGAPfT1 */
undefined4 UpdateAsega(ASEGA * arg0, float arg1); /* 0x12EBD8 UpdateAsega__FP5ASEGAf */
undefined4 SeekAsega(ASEGA * arg0, SEEK arg1, float arg2, float arg3); /* 0x12F0A0 SeekAsega__FP5ASEGA4SEEKff */
undefined4 SnapAsega(ASEGA * arg0, int arg1); /* 0x12F190 SnapAsega__FP5ASEGAi */
undefined4 AdaptAsega(ASEGA * arg0); /* 0x12F1D8 AdaptAsega__FP5ASEGA */
undefined4 FindChnClosestPointLocal(CHN * arg0, ALO * arg1, VECTOR * arg2, float arg3, float arg4, float arg5, float * arg6, VECTOR * arg7, VECTOR * arg8); /* 0x12F210 FindChnClosestPointLocal__FP3CHNP3ALOP6VECTORfffPfT2T2 */
undefined4 SetAsegaSpeed(ASEGA * arg0, float arg1); /* 0x12F6B0 SetAsegaSpeed__FP5ASEGAf */
undefined4 SetAsegaMasterSpeed(ASEGA * arg0, float arg1); /* 0x12F6D0 SetAsegaMasterSpeed__FP5ASEGAf */
undefined4 SetAsegaPriority(ASEGA * arg0, int arg1); /* 0x12F718 SetAsegaPriority__FP5ASEGAi */
undefined4 SendAsegaMessage(ASEGA * arg0, MSGID arg1, void * arg2); /* 0x12F760 SendAsegaMessage__FP5ASEGA5MSGIDPv */
undefined4 SubscribeAsegaStruct(ASEGA * arg0, void (*arg1)(void *, MSGID, void *), void * arg2); /* 0x12F7E0 SubscribeAsegaStruct__FP5ASEGAPFPv5MSGIDPv_vPv */
undefined4 SubscribeAsegaObject(ASEGA * arg0, LO * arg1); /* 0x12F810 SubscribeAsegaObject__FP5ASEGAP2LO */
undefined4 InitBarrier(BARRIER * arg0); /* 0x12F840 InitBarrier__FP7BARRIER */
undefined4 CloneBarrier(BARRIER * arg0, BARRIER * arg1); /* 0x12F888 CloneBarrier__FP7BARRIERT0 */
void * PostBarrierLoad(BARRIER * arg0); /* 0x12F8C8 PostBarrierLoad__FP7BARRIER */
undefined4 UpdateBarrier(BARRIER * arg0, float arg1); /* 0x12F9B8 UpdateBarrier__FP7BARRIERf */
int FIgnoreBarrierIntersection(BARRIER * arg0, SO * arg1); /* 0x12FA88 FIgnoreBarrierIntersection__FP7BARRIERP2SO */
undefined4 NotifyBarrierImpact(BARRIER * arg0, XP * arg1, int arg2); /* 0x12FB68 NotifyBarrierImpact__FP7BARRIERP2XPi */
undefined4 AddBarrierObject(BARRIER * arg0, OID arg1); /* 0x12FCB0 AddBarrierObject__FP7BARRIER3OID */
undefined4 AddBarrierClass(BARRIER * arg0, CID arg1); /* 0x12FCD0 AddBarrierClass__FP7BARRIER3CID */
void CBinaryAsyncStream_constructor(CBinaryAsyncStream *this, void * arg1); /* 0x12FCF0 __18CBinaryAsyncStreamPv */
void CBinaryAsyncStream_destructor(CBinaryAsyncStream *this); /* 0x12FD30 _$_18CBinaryAsyncStream */
int CBinaryAsyncStream_FOpenFile(CBinaryAsyncStream *this, CFileLocation * arg1); /* 0x12FD78 FOpenFile__18CBinaryAsyncStreamP13CFileLocation */
int CBinaryAsyncStream_FOpenSector(CBinaryAsyncStream *this, unsigned int arg1, unsigned int arg2); /* 0x12FDA0 FOpenSector__18CBinaryAsyncStreamUiUi */
undefined4 CBinaryAsyncStream_Close(CBinaryAsyncStream *this); /* 0x12FDE8 Close__18CBinaryAsyncStream */
undefined4 CBinaryAsyncStream_StartSpooling(CBinaryAsyncStream *this); /* 0x12FE70 StartSpooling__18CBinaryAsyncStream */
int CBinaryAsyncStream_FSpooling(CBinaryAsyncStream *this); /* 0x12FF10 FSpooling__18CBinaryAsyncStream */
int CBinaryAsyncStream_FSpoolingComplete(CBinaryAsyncStream *this); /* 0x12FF20 FSpoolingComplete__18CBinaryAsyncStream */
undefined4 CBinaryAsyncStream_FinishSpooling(CBinaryAsyncStream *this); /* 0x12FFE8 FinishSpooling__18CBinaryAsyncStream */
undefined4 CBinaryAsyncStream_Spool(CBinaryAsyncStream *this); /* 0x130070 Spool__18CBinaryAsyncStream */
undefined4 CBinaryAsyncStream_Skip(CBinaryAsyncStream *this, int arg1); /* 0x1300D8 Skip__18CBinaryAsyncStreami */
int FIsBasicDerivedFrom(BASIC * arg0, CID arg1); /* 0x1300E8 FIsBasicDerivedFrom__FP5BASIC3CID */
undefined4 EnsureBasicSidebag(BASIC * arg0); /* 0x130110 EnsureBasicSidebag__FP5BASIC */
undefined4 GetBasicCid(BASIC * arg0, CID * arg1); /* 0x130158 GetBasicCid__FP5BASICP3CID */
undefined4 EvaluateBezierWeightedFloat(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float * arg9, float * arg10, float * arg11); /* 0x130168 EvaluateBezierWeightedFloat__FfffffffffPfN29 */
undefined4 EvaluateBezierFloat(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float * arg7, float * arg8, float * arg9); /* 0x1303F0 EvaluateBezierFloat__FfffffffPfN27 */
undefined4 EvaluateBezierPos(float arg0, float arg1, float arg2, VECTOR * arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6, VECTOR * arg7, VECTOR * arg8, VECTOR * arg9); /* 0x130540 EvaluateBezierPos__FfffP6VECTORN63 */
undefined4 EvaluateBezierMat(float arg0, float arg1, float arg2, MATRIX3 * arg3, VECTOR * arg4, MATRIX3 * arg5, VECTOR * arg6, MATRIX3 * arg7, VECTOR * arg8, VECTOR * arg9); /* 0x130748 EvaluateBezierMat__FfffP7MATRIX3P6VECTORT3T4T3T4T4 */
undefined4 TesselateBezier(float arg0, float arg1, float arg2, VECTOR * arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6, int arg7, VECTOR * arg8); /* 0x130B48 TesselateBezier__FfffP6VECTORN33iT3 */
float SBezierPosLength(float arg0, float arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4, VECTOR * arg5); /* 0x130C20 SBezierPosLength__FffP6VECTORN32 */
undefined4 LimitBezierMulti(int arg0, ...); /* 0x130C58 LimitBezierMulti__Fie */
undefined4 InitBei(BEI * arg0, CLQ * arg1, float arg2, float arg3, int arg4); /* 0x130F48 InitBei__FP3BEIP3CLQffi */
float GEvaluateBei(BEI * arg0, int arg1); /* 0x131000 GEvaluateBei__FP3BEIi */
undefined4 InitBinoc(BINOC * arg0, BLOTK arg1); /* 0x1310F0 InitBinoc__FP5BINOC5BLOTK */
undefined4 ResetBinoc(BINOC * arg0); /* 0x131140 ResetBinoc__FP5BINOC */
void * PostBinocLoad(BINOC * arg0); /* 0x131198 PostBinocLoad__FP5BINOC */
int FDoneBinocAchz(BINOC * arg0); /* 0x136530 FDoneBinocAchz__FP5BINOC */
undefined4 SetBinocLookat(BINOC * arg0, ALO * arg1); /* 0x1365A0 SetBinocLookat__FP5BINOCP3ALO */
undefined4 SetBinocZoom(BINOC * arg0, float arg1); /* 0x1365A8 SetBinocZoom__FP5BINOCf */
undefined4 GetBinocReticleFocus(BINOC * arg0, float * arg1, float * arg2); /* 0x136EC8 GetBinocReticleFocus__FP5BINOCPfT1 */
undefined4 CTextBox_SetPos(CTextBox *this, float arg1, float arg2); /* 0x137228 SetPos__8CTextBoxff */
undefined4 CTextBox_SetSize(CTextBox *this, float arg1, float arg2); /* 0x137238 SetSize__8CTextBoxff */
undefined4 CTextBox_SetTextColor(CTextBox *this, RGBA * arg1); /* 0x137248 SetTextColor__8CTextBoxP4RGBA */
undefined4 CTextBox_SetHorizontalJust(CTextBox *this, JH arg1); /* 0x137260 SetHorizontalJust__8CTextBox2JH */
undefined4 CTextBox_SetVerticalJust(CTextBox *this, JV arg1); /* 0x137268 SetVerticalJust__8CTextBox2JV */
undefined4 _GLOBAL_$I$InitBei(BEI * arg0, CLQ * arg1, float arg2, float arg3, int arg4); /* 0x137270 _GLOBAL_$I$InitBei__FP3BEIP3CLQffi */
void CBinaryInputStream_constructor(CBinaryInputStream *this, void * arg1, int arg2, int arg3); /* 0x137290 __18CBinaryInputStreamPvii */
void CBinaryInputStream_destructor(CBinaryInputStream *this); /* 0x1372E0 _$_18CBinaryInputStream */
int CBinaryInputStream_FOpenSector(CBinaryInputStream *this, unsigned int arg1, unsigned int arg2); /* 0x137328 FOpenSector__18CBinaryInputStreamUiUi */
undefined4 CBinaryInputStream_OpenMemory(CBinaryInputStream *this, int arg1, void * arg2); /* 0x137398 OpenMemory__18CBinaryInputStreamiPv */
int CBinaryInputStream_FOpenFile(CBinaryInputStream *this, CFileLocation * arg1); /* 0x1373B0 FOpenFile__18CBinaryInputStreamP13CFileLocation */
undefined4 CBinaryInputStream_Close(CBinaryInputStream *this); /* 0x1373D0 Close__18CBinaryInputStream */
undefined4 CBinaryInputStream_DecrementCdReadLimit(CBinaryInputStream *this, int arg1); /* 0x137480 DecrementCdReadLimit__18CBinaryInputStreami */
void * CBinaryInputStream_PumpCd(CBinaryInputStream *this); /* 0x137490 PumpCd__18CBinaryInputStream */
void * CBinaryInputStream_PumpHost(CBinaryInputStream *this); /* 0x1377C0 PumpHost__18CBinaryInputStream */
undefined4 CBinaryInputStream_Pump(CBinaryInputStream *this); /* 0x137820 Pump__18CBinaryInputStream */
undefined4 CBinaryInputStream_Decompress(CBinaryInputStream *this); /* 0x1378A0 Decompress__18CBinaryInputStream */
undefined4 CBinaryInputStream_Read(CBinaryInputStream *this, int arg1, void * arg2); /* 0x137A60 Read__18CBinaryInputStreamiPv */
undefined4 CBinaryInputStream_Align(CBinaryInputStream *this, int arg1); /* 0x137B60 Align__18CBinaryInputStreami */
undefined4 CBinaryInputStream_U8Read(CBinaryInputStream *this); /* 0x137B90 U8Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_U16Read(CBinaryInputStream *this); /* 0x137BE0 U16Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_U32Read(CBinaryInputStream *this); /* 0x137C40 U32Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_S8Read(CBinaryInputStream *this); /* 0x137CC0 S8Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_S16Read(CBinaryInputStream *this); /* 0x137D10 S16Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_S32Read(CBinaryInputStream *this); /* 0x137D78 S32Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_F32Read(CBinaryInputStream *this); /* 0x137DF8 F32Read__18CBinaryInputStream */
undefined4 CBinaryInputStream_ReadVector(CBinaryInputStream *this, VECTOR * arg1); /* 0x137E70 ReadVector__18CBinaryInputStreamP6VECTOR */
undefined4 CBinaryInputStream_ReadVector4(CBinaryInputStream *this, VECTOR4 * arg1); /* 0x137E90 ReadVector4__18CBinaryInputStreamP7VECTOR4 */
undefined4 CBinaryInputStream_ReadMatrix(CBinaryInputStream *this, MATRIX3 * arg1); /* 0x137EB0 ReadMatrix__18CBinaryInputStreamP7MATRIX3 */
undefined4 CBinaryInputStream_ReadMatrix4(CBinaryInputStream *this, MATRIX4 * arg1); /* 0x137F08 ReadMatrix4__18CBinaryInputStreamP7MATRIX4 */
undefined4 CBinaryInputStream_ReadGeom(CBinaryInputStream *this, GEOM * arg1); /* 0x137FB0 ReadGeom__18CBinaryInputStreamP4GEOM */
undefined4 CBinaryInputStream_ReadBspc(CBinaryInputStream *this, GEOM * arg1, BSPC * arg2); /* 0x138278 ReadBspc__18CBinaryInputStreamP4GEOMP4BSPC */
undefined4 CBinaryInputStream_ReadVbsp(CBinaryInputStream *this, int * arg1, VBSP * * arg2); /* 0x138398 ReadVbsp__18CBinaryInputStreamPiPP4VBSP */
undefined4 CBinaryInputStream_ReadStringSw(CBinaryInputStream *this, char * * arg1); /* 0x1384A0 ReadStringSw__18CBinaryInputStreamPPc */
undefined4 CBinaryInputStream_Unknown1(CBinaryInputStream *this); /* 0x138518 Unknown1__18CBinaryInputStream */
undefined4 CBinaryInputStream_Unknown2(CBinaryInputStream *this, void * * arg1); /* 0x138550 Unknown2__18CBinaryInputStreamPPv */
undefined4 UpdateSwPox(SW * arg0, OXA * arg1, OXA * arg2, unsigned char arg3, unsigned char arg4); /* 0x1385A0 UpdateSwPox__FP2SWP3OXAT1UcUc */
void * PoxAddSw(SW * arg0, OXA * arg1, OXA * arg2); /* 0x138738 PoxAddSw__FP2SWP3OXAT1 */
void * PoxRemoveSw(SW * arg0, OXA * arg1, OXA * arg2); /* 0x138788 PoxRemoveSw__FP2SWP3OXAT1 */
void * PoxFromSoSo(SO * arg0, SO * arg1); /* 0x1387C0 PoxFromSoSo__FP2SOT0 */
void * PxpFirstFromSoSo(SO * arg0, SO * arg1); /* 0x1387F8 PxpFirstFromSoSo__FP2SOT0 */
undefined4 AddSwAaobrObject(SW * arg0, SO * arg1); /* 0x138828 AddSwAaobrObject__FP2SWP2SO */
undefined4 RemoveSwAaobrObject(SW * arg0, SO * arg1); /* 0x1388A0 RemoveSwAaobrObject__FP2SWP2SO */
undefined4 InvalidateSwAaox(SW * arg0); /* 0x1389C8 InvalidateSwAaox__FP2SW */
undefined4 UpdateSwAaox(SW * arg0); /* 0x1389D0 UpdateSwAaox__FP2SW */
undefined4 InvalidateSwXpForObject(SW * arg0, SO * arg1, int arg2); /* 0x138BE0 InvalidateSwXpForObject__FP2SWP2SOi */
undefined4 RecalcSwXpAll(SW * arg0, int arg1); /* 0x138C00 RecalcSwXpAll__FP2SWi */
undefined4 RecalcSwOxfFilterForObject(SW * arg0, SO * arg1); /* 0x138F28 RecalcSwOxfFilterForObject__FP2SWP2SO */
undefined4 VerifyAeaEquivalence(int arg0, EA * arg1, int arg2, EA * arg3); /* 0x138FF0 VerifyAeaEquivalence__FiP2EAiT1 */
undefined4 EnsureAsegBlendDynamic(ALO * arg0, int arg1, int arg2, void * arg3, int arg4, int * arg5, int * arg6, ASEGBL * * arg7); /* 0x139038 EnsureAsegBlendDynamic__FP3ALOiiPviPiT5PP6ASEGBL */
undefined4 FillBlAmrsg(int arg0, int arg1, void * arg2, int arg3, int arg4, OID * arg5); /* 0x139600 FillBlAmrsg__FiiPviiP3OID */
undefined4 CalculateBlendAmrsg(int arg0, int arg1, void * arg2, int arg3, int arg4, MRSG * arg5, float * arg6); /* 0x139740 CalculateBlendAmrsg__FiiPviiP4MRSGPf */
undefined4 ImrsgLookUp(float arg0, float arg1, int arg2, MRSG * arg3, float * arg4); /* 0x139970 ImrsgLookUp__FffiP4MRSGPf */
undefined4 ReblendAsegbl(ASEGBL * arg0, int arg1, int arg2, void * arg3); /* 0x1399F8 ReblendAsegbl__FP6ASEGBLiiPv */
undefined4 SetAsegblSlerp(ASEGBL * arg0, ALO * arg1); /* 0x139B38 SetAsegblSlerp__FP6ASEGBLP3ALO */
undefined4 BuildBlipAqwGifs(int arg0, QW * * arg1); /* 0x139B70 BuildBlipAqwGifs__FiPP2QW */
undefined4 StartupBlips(void); /* 0x139C38 StartupBlips__Fv */
void * PblipNew(BLIPG * arg0); /* 0x139C70 PblipNew__FP5BLIPG */
undefined4 RemoveBlip(BLIP * arg0); /* 0x139D28 RemoveBlip__FP4BLIP */
void * PblipgNew(SW * arg0); /* 0x139D68 PblipgNew__FP2SW */
undefined4 InitBlipg(BLIPG * arg0); /* 0x139DE8 InitBlipg__FP5BLIPG */
undefined4 OnBlipgAdd(BLIPG * arg0); /* 0x139E80 OnBlipgAdd__FP5BLIPG */
undefined4 OnBlipgRemove(BLIPG * arg0); /* 0x139EC8 OnBlipgRemove__FP5BLIPG */
undefined4 SetBlipgShader(BLIPG * arg0, OID arg1); /* 0x139F80 SetBlipgShader__FP5BLIPG3OID */
undefined4 PropagateBlipgShader(BLIPG * arg0); /* 0x13A008 PropagateBlipgShader__FP5BLIPG */
undefined4 SetBlipgEmitb(BLIPG * arg0, EMITB * arg1); /* 0x13A128 SetBlipgEmitb__FP5BLIPGP5EMITB */
undefined4 UpdateBlipg(BLIPG * arg0, float arg1); /* 0x13A3A0 UpdateBlipg__FP5BLIPGf */
undefined4 SubscribeBlipgObject(BLIPG * arg0, LO * arg1); /* 0x13A418 SubscribeBlipgObject__FP5BLIPGP2LO */
undefined4 CblipeProjectBlipTransformAccel(MATRIX4 * arg0, VU_FLOAT arg1, BLIPP * arg2, BLIPV * arg3, BLIPX * arg4, int arg5, BLIPOK arg6, VECTOR * arg7, VECTOR * arg8); /* 0x13A498 CblipeProjectBlipTransformAccel__FP7MATRIX4G8VU_FLOATP5BLIPPP5BLIPVP5BLIPXi6BLIPOKP6VECTORT7 */
void * ProjectBlipgTransformAccel(BLIPG * arg0, float arg1); /* 0x13A618 ProjectBlipgTransformAccel__FP5BLIPGf */
void * ProjectBlipgTransform(BLIPG * arg0, float arg1, int arg2); /* 0x13A940 ProjectBlipgTransform__FP5BLIPGfi */
undefined4 RenderBlipgSelf(BLIPG * arg0, CM * arg1, RO * arg2); /* 0x13AD08 RenderBlipgSelf__FP5BLIPGP2CMP2RO */
undefined4 DrawBlipg(RPL * arg0); /* 0x13AD80 DrawBlipg__FP3RPL */
undefined4 PropagateBlipgShaders(int arg0); /* 0x13B430 PropagateBlipgShaders__Fi */
undefined4 InitBomb(BOMB * arg0); /* 0x13B4C0 InitBomb__FP4BOMB */
undefined4 LoadBombFromBrx(BOMB * arg0, CBinaryInputStream * arg1); /* 0x13B598 LoadBombFromBrx__FP4BOMBP18CBinaryInputStream */
undefined4 CloneBomb(BOMB * arg0, BOMB * arg1); /* 0x13B5C8 CloneBomb__FP4BOMBT0 */
void * PostBombLoad(BOMB * arg0); /* 0x13B610 PostBombLoad__FP4BOMB */
undefined4 HandleBombMessage(BOMB * arg0, MSGID arg1, void * arg2); /* 0x13B708 HandleBombMessage__FP4BOMB5MSGIDPv */
undefined4 UpdateBomb(BOMB * arg0, float arg1); /* 0x13B778 UpdateBomb__FP4BOMBf */
int FAbsorbBombWkr(BOMB * arg0, WKR * arg1); /* 0x13BBA0 FAbsorbBombWkr__FP4BOMBP3WKR */
void * PrimeBomb(BOMB * arg0, float arg1); /* 0x13BE00 PrimeBomb__FP4BOMBf */
undefined4 ApplyBombThrow(BOMB * arg0, PO * arg1); /* 0x13BE18 ApplyBombThrow__FP4BOMBP2PO */
undefined4 DetonateBomb(BOMB * arg0); /* 0x13BF68 DetonateBomb__FP4BOMB */
void * PsfxEnsureBomb(BOMB * arg0, ENSK arg1); /* 0x13C950 PsfxEnsureBomb__FP4BOMB4ENSK */
undefined4 CByteQueue_Init(CByteQueue *this, int arg1, void * arg2); /* 0x13C988 Init__10CByteQueueiPv */
undefined4 CByteQueue_Reset(CByteQueue *this); /* 0x13C9B0 Reset__10CByteQueue */
undefined4 CByteQueue_CbFill(CByteQueue *this, int arg1, CQueueInput * arg2); /* 0x13C9D0 CbFill__10CByteQueueiP11CQueueInput */
undefined4 CByteQueue_CbDrain(CByteQueue *this, int arg1, CQueueOutput * arg2); /* 0x13CAD8 CbDrain__10CByteQueueiP12CQueueOutput */
undefined4 CByteQueue_CbFill_2(CByteQueue *this, int arg1, unsigned char * arg2); /* 0x13CC00 CbFill__10CByteQueueiPUc */
undefined4 CByteQueue_FreeDrain(CByteQueue *this, int arg1); /* 0x13CC48 FreeDrain__10CByteQueuei */
undefined4 CQueueInputMemory_CbRead(CQueueInputMemory *this, int arg1, void * arg2); /* 0x13CC80 CbRead__17CQueueInputMemoryiPv */
undefined4 CQueueInputFile_CbRead(CQueueInputFile *this, int arg1, void * arg2); /* 0x13CCE8 CbRead__15CQueueInputFileiPv */
undefined4 InitBrk(BRK * arg0); /* 0x13CCF8 InitBrk__FP3BRK */
undefined4 LoadBrkFromBrx(BRK * arg0, CBinaryInputStream * arg1); /* 0x13CD80 LoadBrkFromBrx__FP3BRKP18CBinaryInputStream */
undefined4 CloneBrk(BRK * arg0, BRK * arg1); /* 0x13CDE8 CloneBrk__FP3BRKT0 */
void * PostBrkLoad(BRK * arg0); /* 0x13CE40 PostBrkLoad__FP3BRK */
void * PostBrkLoadCallbackHookup(BRK * arg0, MSGID arg1, void * arg2); /* 0x13CE80 PostBrkLoadCallbackHookup__FP3BRK5MSGIDPv */
undefined4 UpdateBrk(BRK * arg0, float arg1); /* 0x13D068 UpdateBrk__FP3BRKf */
int FAbsorbBrkWkr(BRK * arg0, WKR * arg1); /* 0x13D0B0 FAbsorbBrkWkr__FP3BRKP3WKR */
undefined4 BreakBrk(BRK * arg0); /* 0x13D278 BreakBrk__FP3BRK */
undefined4 SetBrkBroken(BRK * arg0, int arg1); /* 0x13D820 SetBrkBroken__FP3BRKi */
undefined4 SetBrkExclude(BRK * arg0, OID arg1); /* 0x13D868 SetBrkExclude__FP3BRK3OID */
undefined4 SetBrkRemain(BRK * arg0, OID arg1); /* 0x13D8B0 SetBrkRemain__FP3BRK3OID */
undefined4 SetBrkFixed(BRK * arg0, OID arg1); /* 0x13D900 SetBrkFixed__FP3BRK3OID */
undefined4 SetBrkRemainFixed(BRK * arg0, OID arg1); /* 0x13D950 SetBrkRemainFixed__FP3BRK3OID */
undefined4 SetBrkOnPlayer(BRK * arg0, int arg1); /* 0x13D9A0 SetBrkOnPlayer__FP3BRKi */
undefined4 GetBrkOnPlayer(BRK * arg0, int * arg1); /* 0x13D9E0 GetBrkOnPlayer__FP3BRKPi */
undefined4 SetBrkOnBomb(BRK * arg0, int arg1); /* 0x13D9F0 SetBrkOnBomb__FP3BRKi */
undefined4 GetBrkOnBomb(BRK * arg0, int * arg1); /* 0x13DA30 GetBrkOnBomb__FP3BRKPi */
undefined4 AddBrkTouchObject(BRK * arg0, OID arg1); /* 0x13DA48 AddBrkTouchObject__FP3BRK3OID */
undefined4 AddBrkTouchClass(BRK * arg0, CID arg1); /* 0x13DA80 AddBrkTouchClass__FP3BRK3CID */
void * PsfxEnsureBrk(BRK * arg0, ENSK arg1); /* 0x13DAF0 PsfxEnsureBrk__FP3BRK4ENSK */
int FCheckBrkTouchObject(BRK * arg0, SO * arg1); /* 0x13DB28 FCheckBrkTouchObject__FP3BRKP2SO */
undefined4 UpdateBrkp(BRKP * arg0, float arg1); /* 0x13DC38 UpdateBrkp__FP4BRKPf */
undefined4 HandleBrkpMessage(BRKP * arg0, MSGID arg1, void * arg2); /* 0x13DCA8 HandleBrkpMessage__FP4BRKP5MSGIDPv */
int FIgnoreBrkpIntersection(BRKP * arg0, SO * arg1); /* 0x13DD08 FIgnoreBrkpIntersection__FP4BRKPP2SO */
undefined4 SetBrkpBrkps(BRKP * arg0, BRKPS arg1); /* 0x13DD78 SetBrkpBrkps__FP4BRKP5BRKPS */
undefined4 InitBreak(BREAK * arg0); /* 0x13DDB8 InitBreak__FP5BREAK */
undefined4 InitFragile(FRAGILE * arg0); /* 0x13DDF0 InitFragile__FP7FRAGILE */
undefined4 AdjustFragileNewXp(FRAGILE * arg0, XP * arg1, int arg2); /* 0x13DE38 AdjustFragileNewXp__FP7FRAGILEP2XPi */
undefined4 AdjustZapbreakNewXp(ZAPBREAK * arg0, XP * arg1, int arg2); /* 0x13DEE8 AdjustZapbreakNewXp__FP8ZAPBREAKP2XPi */
undefined4 UpdateZapbreak(ZAPBREAK * arg0, float arg1); /* 0x13DF68 UpdateZapbreak__FP8ZAPBREAKf */
undefined4 ClsgClipEdgeToBsp(BSP * arg0, VECTOR * arg1, VECTOR * arg2, int * arg3, int arg4, LSG * arg5); /* 0x13DFD8 ClsgClipEdgeToBsp__FP3BSPP6VECTORT1PiiP3LSG */
void * PruneBsp(BSP * arg0, VECTOR * arg1, float arg2, BSP * * arg3); /* 0x13E430 PruneBsp__FP3BSPP6VECTORfPP3BSP */
void * PbspPointInBspQuick(VECTOR * arg0, BSP * arg1); /* 0x13E658 PbspPointInBspQuick__FP6VECTORP3BSP */
undefined4 CloneBspc(GEOM * arg0, BSPC * arg1, GEOM * arg2, BSPC * arg3); /* 0x13E6C8 CloneBspc__FP4GEOMP4BSPCT0T1 */
void * PostAshLoad(SW * arg0, ASH * arg1, ALO * arg2); /* 0x13E7C0 PostAshLoad__FP2SWP3ASHP3ALO */
int FFoundAshAseg(ASH * arg0, ASEG * arg1); /* 0x13E868 FFoundAshAseg__FP3ASHP4ASEG */
int FAddAshAseg(ASH * arg0, ASEG * arg1); /* 0x13E8D8 FAddAshAseg__FP3ASHP4ASEG */
int FAddAshOid(ASH * arg0, OID arg1); /* 0x13E8F8 FAddAshOid__FP3ASH3OID */
undefined4 InitBtn(BTN * arg0); /* 0x13E918 InitBtn__FP3BTN */
undefined4 LoadBtn(BTN * arg0, ALO * arg1); /* 0x13E950 LoadBtn__FP3BTNP3ALO */
void * PostBtnLoad(BTN * arg0); /* 0x13EA38 PostBtnLoad__FP3BTN */
undefined4 RestoreBtnFromCheckpointCallback(BTN * arg0, MSGID arg1, void * arg2); /* 0x13EAE0 RestoreBtnFromCheckpointCallback__FP3BTN5MSGIDPv */
undefined4 SetBtnRsmg(BTN * arg0, int arg1, OID arg2, OID arg3, OID arg4); /* 0x13EB30 SetBtnRsmg__FP3BTNi3OIDN22 */
undefined4 SetBtnButtons(BTN * arg0, BUTTONS arg1); /* 0x13EB68 SetBtnButtons__FP3BTN7BUTTONS */
int FAddRsmg(RSMG * arg0, int arg1, int * arg2, int arg3, OID arg4, OID arg5, OID arg6); /* 0x13EC00 FAddRsmg__FP4RSMGiPii3OIDN24 */
undefined4 TriggerRsmg(SW * arg0, int arg1, RSMG * arg2, LO * arg3, int arg4); /* 0x13ECB0 TriggerRsmg__FP2SWiP4RSMGP2LOi */
undefined4 RunBtnAsegs(BTN * arg0, IASH arg1, int arg2, int arg3); /* 0x13ED90 RunBtnAsegs__FP3BTN4IASHii */
undefined4 TriggerBtn(BTN * arg0, int arg1, int arg2); /* 0x13EF50 TriggerBtn__FP3BTNii */
undefined4 UntriggerBtn(BTN * arg0, int arg1); /* 0x13F070 UntriggerBtn__FP3BTNi */
undefined4 InitButton(BUTTON * arg0); /* 0x13F0E0 InitButton__FP6BUTTON */
undefined4 LoadButtonFromBrx(BUTTON * arg0, CBinaryInputStream * arg1); /* 0x13F110 LoadButtonFromBrx__FP6BUTTONP18CBinaryInputStream */
undefined4 InsertButtonPos(BUTTON * arg0, PNT * arg1, VECTOR * arg2); /* 0x13F140 InsertButtonPos__FP6BUTTONP3PNTP6VECTOR */
undefined4 InsertButtonMat(BUTTON * arg0, XFM * arg1, MATRIX3 * arg2); /* 0x13F1D8 InsertButtonMat__FP6BUTTONP3XFMP7MATRIX3 */
void * PostButtonLoad(BUTTON * arg0); /* 0x13F290 PostButtonLoad__FP6BUTTON */
undefined4 CloneButton(BUTTON * arg0, BUTTON * arg1); /* 0x13F6C0 CloneButton__FP6BUTTONT0 */
undefined4 SetButtonButtons(BUTTON * arg0, BUTTONS arg1); /* 0x13F6F8 SetButtonButtons__FP6BUTTON7BUTTONS */
int FCheckButtonObject(BUTTON * arg0, SO * arg1); /* 0x13F718 FCheckButtonObject__FP6BUTTONP2SO */
undefined4 IposFindButtonClosest(BUTTON * arg0, float * arg1); /* 0x13F8A0 IposFindButtonClosest__FP6BUTTONPf */
undefined4 ImatFindButtonClosest(BUTTON * arg0, float * arg1); /* 0x13F940 ImatFindButtonClosest__FP6BUTTONPf */
void * PresetButtonAccel(BUTTON * arg0, float arg1); /* 0x13FA10 PresetButtonAccel__FP6BUTTONf */
undefined4 UpdateButtonInternalXps(BUTTON * arg0); /* 0x13FAE8 UpdateButtonInternalXps__FP6BUTTON */
undefined4 UpdateButton(BUTTON * arg0, float arg1); /* 0x13FD20 UpdateButton__FP6BUTTONf */
int FAbsorbButtonWkr(BUTTON * arg0, WKR * arg1); /* 0x140028 FAbsorbButtonWkr__FP6BUTTONP3WKR */
undefined4 InitVolbtn(VOLBTN * arg0); /* 0x1400A8 InitVolbtn__FP6VOLBTN */
undefined4 LoadVolbtnFromBrx(VOLBTN * arg0, CBinaryInputStream * arg1); /* 0x140100 LoadVolbtnFromBrx__FP6VOLBTNP18CBinaryInputStream */
void * PostVolbtnLoad(VOLBTN * arg0); /* 0x140140 PostVolbtnLoad__FP6VOLBTN */
undefined4 CloneVolbtn(VOLBTN * arg0, VOLBTN * arg1); /* 0x140200 CloneVolbtn__FP6VOLBTNT0 */
undefined4 SetVolbtnButtons(VOLBTN * arg0, BUTTONS arg1); /* 0x140238 SetVolbtnButtons__FP6VOLBTN7BUTTONS */
undefined4 UpdateVolbtn(VOLBTN * arg0, float arg1); /* 0x140258 UpdateVolbtn__FP6VOLBTNf */
int FGetVolbtnPushObjectsWithinList(VOLBTN * arg0, void * arg1); /* 0x140550 FGetVolbtnPushObjectsWithinList__FP6VOLBTNPv */
undefined4 AddBtnAseg(BTN * arg0, ALO * arg1, OID arg2); /* 0x1405D0 AddBtnAseg__FP3BTNP3ALO3OID */
undefined4 AddButtonAseg(BUTTON * arg0, OID arg1); /* 0x1405F0 AddButtonAseg__FP6BUTTON3OID */
undefined4 AddVolbtnAseg(VOLBTN * arg0, OID arg1); /* 0x140618 AddVolbtnAseg__FP6VOLBTN3OID */
undefined4 AddBtnOffAseg(BTN * arg0, ALO * arg1, OID arg2); /* 0x140640 AddBtnOffAseg__FP3BTNP3ALO3OID */
undefined4 AddButtonOffAseg(BUTTON * arg0, OID arg1); /* 0x140660 AddButtonOffAseg__FP6BUTTON3OID */
undefined4 AddVolbtnOffAseg(VOLBTN * arg0, OID arg1); /* 0x140688 AddVolbtnOffAseg__FP6VOLBTN3OID */
undefined4 AddButtonPushObject(BUTTON * arg0, OID arg1); /* 0x1406B0 AddButtonPushObject__FP6BUTTON3OID */
undefined4 AddButtonNoPushObject(BUTTON * arg0, OID arg1); /* 0x1406D0 AddButtonNoPushObject__FP6BUTTON3OID */
undefined4 AddButtonPushClass(BUTTON * arg0, CID arg1); /* 0x1406F0 AddButtonPushClass__FP6BUTTON3CID */
undefined4 AddButtonNoPushClass(BUTTON * arg0, CID arg1); /* 0x140710 AddButtonNoPushClass__FP6BUTTON3CID */
undefined4 AddVolbtnPushObject(VOLBTN * arg0, OID arg1); /* 0x140730 AddVolbtnPushObject__FP6VOLBTN3OID */
undefined4 SetButtonRsmg(BUTTON * arg0, int arg1, OID arg2, OID arg3, OID arg4); /* 0x140750 SetButtonRsmg__FP6BUTTONi3OIDN22 */
undefined4 SetVolbtnRsmg(VOLBTN * arg0, int arg1, OID arg2, OID arg3, OID arg4); /* 0x140770 SetVolbtnRsmg__FP6VOLBTNi3OIDN22 */
undefined4 StartupCatalog(void); /* 0x140790 StartupCatalog__Fv */
int FUN_001407A0(unsigned int * arg0); /* 0x1407A0 FUN_001407A0__FPUi */
undefined4 CpchzTokenizePath(char * arg0); /* 0x1407A8 CpchzTokenizePath__FPc */
int FValidCdMmode(void); /* 0x140968 FValidCdMmode__Fv */
undefined4 SetCdMmode(void); /* 0x1409A8 SetCdMmode__Fv */
undefined4 StartupCd(void); /* 0x1409D8 StartupCd__Fv */
undefined4 UpdateCd(void); /* 0x1409E0 UpdateCd__Fv */
undefined4 CdPath(char * arg0, char * arg1, int arg2); /* 0x140B60 CdPath__FPcT0i */
undefined4 ReadCd(unsigned int arg0, unsigned int arg1, void * arg2); /* 0x140C28 ReadCd__FUiUiPv */
undefined4 ReadCdDirect(unsigned int arg0, unsigned int arg1, void * arg2); /* 0x140CC8 ReadCdDirect__FUiUiPv */
int FCdCompleted(int arg0); /* 0x140D68 FCdCompleted__Fi */
undefined4 ResetChkmgrCheckpoints(CHKMGR * arg0); /* 0x140D90 ResetChkmgrCheckpoints__FP6CHKMGR */
undefined4 SaveChkmgrCheckpoint(CHKMGR * arg0, OID arg1, OID arg2); /* 0x140E10 SaveChkmgrCheckpoint__FP6CHKMGR3OIDT1 */
undefined4 ReturnChkmgrToCheckpoint(CHKMGR * arg0); /* 0x140ED0 ReturnChkmgrToCheckpoint__FP6CHKMGR */
undefined4 RestoreChkmgrFromCheckpoint(CHKMGR * arg0); /* 0x140F48 RestoreChkmgrFromCheckpoint__FP6CHKMGR */
undefined4 IchkAllocChkmgr(CHKMGR * arg0); /* 0x140FF8 IchkAllocChkmgr__FP6CHKMGR */
int FGetChkmgrIchk(CHKMGR * arg0, int arg1); /* 0x141008 FGetChkmgrIchk__FP6CHKMGRi */
undefined4 SetChkmgrIchk(CHKMGR * arg0, int arg1); /* 0x141040 SetChkmgrIchk__FP6CHKMGRi */
undefined4 ClearChkmgrIchk(CHKMGR * arg0, int arg1); /* 0x1410A0 ClearChkmgrIchk__FP6CHKMGRi */
undefined4 LoadVolFromBrx(VOL * arg0, CBinaryInputStream * arg1); /* 0x141108 LoadVolFromBrx__FP3VOLP18CBinaryInputStream */
int FCheckVolPoint(VOL * arg0, VECTOR * arg1); /* 0x141170 FCheckVolPoint__FP3VOLP6VECTOR */
undefined4 InitChkpnt(CHKPNT * arg0); /* 0x1411A8 InitChkpnt__FP6CHKPNT */
undefined4 LoadChkpntFromBrx(CHKPNT * arg0, CBinaryInputStream * arg1); /* 0x141210 LoadChkpntFromBrx__FP6CHKPNTP18CBinaryInputStream */
undefined4 BindChkpnt(CHKPNT * arg0); /* 0x141338 BindChkpnt__FP6CHKPNT */
void * PostChkpntLoad(CHKPNT * arg0); /* 0x141438 PostChkpntLoad__FP6CHKPNT */
undefined4 CloneChkpnt(CHKPNT * arg0, CHKPNT * arg1); /* 0x1415D0 CloneChkpnt__FP6CHKPNTT0 */
undefined4 UpdateChkpnt(CHKPNT * arg0, float arg1); /* 0x141690 UpdateChkpnt__FP6CHKPNTf */
undefined4 TriggerChkpnt(CHKPNT * arg0); /* 0x141870 TriggerChkpnt__FP6CHKPNT */
int FUN_001419E0(int * arg0, int arg1); /* 0x1419E0 FUN_001419E0__FPii */
void * PsoHitTestLineObjects(int arg0, VECTOR * arg1, VECTOR * arg2, int arg3, SO * * arg4, LSG * arg5); /* 0x1419E8 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG */
undefined4 ClsgClipEdgeToObject(SO * arg0, VECTOR * arg1, VECTOR * arg2, int arg3, LSG * arg4); /* 0x141C28 ClsgClipEdgeToObject__FP2SOP6VECTORT1iP3LSG */
undefined4 ClsgClipEdgeToObjectPruned(SO * arg0, BSP * arg1, VECTOR * arg2, VECTOR * arg3, int arg4, LSG * arg5); /* 0x141C90 ClsgClipEdgeToObjectPruned__FP2SOP3BSPP6VECTORT2iP3LSG */
undefined4 ClsgClipCylinderToObject(SO * arg0, VECTOR * arg1, VECTOR * arg2, float arg3, int arg4, LSG * arg5); /* 0x141D00 ClsgClipCylinderToObject__FP2SOP6VECTORT1fiP3LSG */
undefined4 ClsgClipLineToSphere(VECTOR * arg0, float arg1, VECTOR * arg2, VECTOR * arg3, int arg4, LSG * arg5); /* 0x141D88 ClsgClipLineToSphere__FP6VECTORfT0T0iP3LSG */
undefined4 ClsgClipEdgeToSphere(VECTOR * arg0, float arg1, VECTOR * arg2, VECTOR * arg3, int arg4, LSG * arg5); /* 0x141F48 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG */
undefined4 ClsgClipCylinderToSphere(VECTOR * arg0, float arg1, VECTOR * arg2, VECTOR * arg3, float arg4, int arg5, LSG * arg6); /* 0x142170 ClsgClipCylinderToSphere__FP6VECTORfT0T0fiP3LSG */
undefined4 ClsgClipEdgeToCylinder(VECTOR * arg0, VECTOR * arg1, float arg2, VECTOR * arg3, VECTOR * arg4, int arg5, LSG * arg6); /* 0x142278 ClsgClipEdgeToCylinder__FP6VECTORT0fT0T0iP3LSG */
undefined4 SgnCompareMaa(MAA * arg0, MAA * arg1); /* 0x142998 SgnCompareMaa__FP3MAAT0 */
undefined4 ClsgMergeAlsg(int arg0, LSG * arg1); /* 0x1429F8 ClsgMergeAlsg__FiP3LSG */
undefined4 ClsgClipCylinderToBsp(BSPC * arg0, GEOM * arg1, VECTOR * arg2, VECTOR * arg3, float arg4, int arg5, LSG * arg6); /* 0x142B78 ClsgClipCylinderToBsp__FP4BSPCP4GEOMP6VECTORT2fiP3LSG */
undefined4 SetClockRate(float arg0); /* 0x142ED0 SetClockRate__Ff */
undefined4 MarkClockTick(CLOCK * arg0); /* 0x142F10 MarkClockTick__FP5CLOCK */
undefined4 MarkClockTickRealOnly(CLOCK * arg0); /* 0x143030 MarkClockTickRealOnly__FP5CLOCK */
undefined4 ResetClock(CLOCK * arg0, float arg1); /* 0x1430B8 ResetClock__FP5CLOCKf */
undefined4 SetClockEnabled(CLOCK * arg0, int arg1); /* 0x1430C0 SetClockEnabled__FP5CLOCKi */
undefined4 StartupClock(void); /* 0x1430C8 StartupClock__Fv */
undefined4 TickNow(void); /* 0x1430F8 TickNow__Fv */
undefined4 StartupCm(void); /* 0x143140 StartupCm__Fv */
undefined4 CalcCmAdjust(CM * arg0, SO * arg1, CPDEFI * arg2, VECTOR * arg3); /* 0x143148 CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR */
undefined4 SpringCm(float arg0, float arg1, float arg2, CM * arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6); /* 0x143180 SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR */
undefined4 AdjustCmCpdefi(CM * arg0, SO * arg1, float arg2, CPDEFI * arg3); /* 0x143208 AdjustCmCpdefi__FP2CMP2SOfP6CPDEFI */
undefined4 ResetCmAdjust(CM * arg0, SO * arg1, CPDEFI * arg2); /* 0x1433E0 ResetCmAdjust__FP2CMP2SOP6CPDEFI */
undefined4 GetCmCpdefi(CM * arg0, SO * arg1, float arg2, CPDEFI * arg3); /* 0x143418 GetCmCpdefi__FP2CMP2SOfP6CPDEFI */
undefined4 BuildCmFgfn(CM * arg0, float arg1, FGFN * arg2); /* 0x1434C8 BuildCmFgfn__FP2CMfP4FGFN */
undefined4 RecalcCmFrustrum(CM * arg0); /* 0x143560 RecalcCmFrustrum__FP2CM */
undefined4 InitCm(CM * arg0); /* 0x143648 InitCm__FP2CM */
undefined4 SetSwCameraFov(float arg0); /* 0x1437C0 SetSwCameraFov__Ff */
undefined4 SetSwCameraNearClip(float arg0); /* 0x1437E8 SetSwCameraNearClip__Ff */
undefined4 SetSwCameraFarClip(float arg0); /* 0x143810 SetSwCameraFarClip__Ff */
undefined4 SetSwCameraSProgress(float arg0); /* 0x143838 SetSwCameraSProgress__Ff */
int FUN_00143860(float arg0); /* 0x143860 FUN_00143860__Ff */
int FUN_00143888(float arg0); /* 0x143888 FUN_00143888__Ff */
undefined4 SetSwCameraRgbaFog(SW * arg0, RGBA * arg1); /* 0x1438B0 SetSwCameraRgbaFog__FP2SWP4RGBA */
undefined4 SetSwCameraMrdRatio(float arg0); /* 0x1438D8 SetSwCameraMrdRatio__Ff */
undefined4 SetCmPos(CM * arg0, VECTOR * arg1); /* 0x143900 SetCmPos__FP2CMP6VECTOR */
undefined4 SetCmMat(CM * arg0, MATRIX3 * arg1); /* 0x143920 SetCmMat__FP2CMP7MATRIX3 */
undefined4 SetCmFov(CM * arg0, float arg1); /* 0x143940 SetCmFov__FP2CMf */
undefined4 SetCmNearClip(CM * arg0, float arg1); /* 0x143968 SetCmNearClip__FP2CMf */
undefined4 SetCmFarClip(CM * arg0, float arg1); /* 0x143988 SetCmFarClip__FP2CMf */
undefined4 SetCmSProgress(CM * arg0, float arg1); /* 0x1439A8 SetCmSProgress__FP2CMf */
int FUN_001439c8(CM * arg0, float arg1); /* 0x1439C8 FUN_001439c8__FP2CMf */
int FUN_001439e8(CM * arg0, float arg1); /* 0x1439E8 FUN_001439e8__FP2CMf */
undefined4 SetCmRgbaFog(CM * arg0, RGBA * arg1); /* 0x143A08 SetCmRgbaFog__FP2CMP4RGBA */
undefined4 SetCmMrdRatio(CM * arg0, float arg1); /* 0x143A38 SetCmMrdRatio__FP2CMf */
undefined4 ClearCmFadeObjects(CM * arg0); /* 0x143AF0 ClearCmFadeObjects__FP2CM */
undefined4 AddCmFadeObject(CM * arg0, OID arg1); /* 0x143AF8 AddCmFadeObject__FP2CM3OID */
undefined4 SetupCm(CM * arg0); /* 0x144270 SetupCm__FP2CM */
undefined4 DrawCm(CM * arg0); /* 0x144848 DrawCm__FP2CM */
undefined4 SetCmPosMat(CM * arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x1448C8 SetCmPosMat__FP2CMP6VECTORP7MATRIX3 */
undefined4 AdjustCmJoy(CM * arg0, JOY * arg1, JOYID arg2, float * arg3); /* 0x144FF8 AdjustCmJoy__FP2CMP3JOY5JOYIDPf */
undefined4 SetCmPolicy(CM * arg0, CPP arg1, CPLCY * arg2, SO * arg3, void * arg4); /* 0x145088 SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv */
undefined4 RevokeCmPolicy(CM * arg0, int arg1, CPP arg2, CPLCY * arg3, SO * arg4, void * arg5); /* 0x1451F0 RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv */
undefined4 SetCmCut(CM * arg0, float * arg1); /* 0x1455C0 SetCmCut__FP2CMPf */
undefined4 SetResetFlag(CM * arg0); /* 0x1455E0 SetResetFlag__FP2CM */
undefined4 ClearCmCut(CM * arg0); /* 0x1455F0 ClearCmCut__FP2CM */
int FUN_00145dd8(CM * arg0); /* 0x145DD8 FUN_00145dd8__FP2CM */
void * PushLookkCm(CM * arg0, LOOKK arg1); /* 0x145FB8 PushLookkCm__FP2CM5LOOKK */
undefined4 LookkPopCm(CM * arg0); /* 0x145FD8 LookkPopCm__FP2CM */
undefined4 LookkCurCm(CM * arg0); /* 0x145FF8 LookkCurCm__FP2CM */
undefined4 SetCmSniperFocus(CM * arg0, PNT * arg1, float arg2, float arg3); /* 0x146018 SetCmSniperFocus__FP2CMP3PNTff */
int FUN_00146028(CM * arg0); /* 0x146028 FUN_00146028__FP2CM */
undefined4 _GLOBAL_$I$StartupCm(void); /* 0x1460E0 _GLOBAL_$I$StartupCm__Fv */
undefined4 InitCnvo(CNVO * arg0); /* 0x146100 InitCnvo__FP4CNVO */
undefined4 LoadCnvoFromBrx(CNVO * arg0, CBinaryInputStream * arg1); /* 0x146130 LoadCnvoFromBrx__FP4CNVOP18CBinaryInputStream */
void * PostCnvoLoad(CNVO * arg0); /* 0x146178 PostCnvoLoad__FP4CNVO */
undefined4 AdjustCnvoXpVelocity(CNVO * arg0, XP * arg1, int arg2); /* 0x1461A8 AdjustCnvoXpVelocity__FP4CNVOP2XPi */
undefined4 SetCnvoBeltSpeed(CNVO * arg0, float arg1); /* 0x146240 SetCnvoBeltSpeed__FP4CNVOf */
undefined4 MatchCnvoScrollerToBeltSpeed(CNVO * arg0); /* 0x146298 MatchCnvoScrollerToBeltSpeed__FP4CNVO */
undefined4 InitDprize(DPRIZE * arg0); /* 0x146340 InitDprize__FP6DPRIZE */
undefined4 LoadDprizeFromBrx(DPRIZE * arg0, CBinaryInputStream * arg1); /* 0x1463C0 LoadDprizeFromBrx__FP6DPRIZEP18CBinaryInputStream */
undefined4 CloneDprize(DPRIZE * arg0, DPRIZE * arg1); /* 0x146418 CloneDprize__FP6DPRIZET0 */
void * PostDprizeLoad(DPRIZE * arg0); /* 0x146470 PostDprizeLoad__FP6DPRIZE */
void * ProjectDprizeTransform(DPRIZE * arg0, float arg1, int arg2); /* 0x146518 ProjectDprizeTransform__FP6DPRIZEfi */
int FFilterDprizeObjects(DPRIZE * arg0, SO * arg1); /* 0x146D10 FFilterDprizeObjects__FP6DPRIZEP2SO */
undefined4 CheckDprizeBounce(DPRIZE * arg0); /* 0x146DB0 CheckDprizeBounce__FP6DPRIZE */
undefined4 CheckDprizeCollect(DPRIZE * arg0); /* 0x1471B0 CheckDprizeCollect__FP6DPRIZE */
int FAbsorbDprizeWkr(DPRIZE * arg0, WKR * arg1); /* 0x1473E0 FAbsorbDprizeWkr__FP6DPRIZEP3WKR */
undefined4 UpdateDprize(DPRIZE * arg0, float arg1); /* 0x147428 UpdateDprize__FP6DPRIZEf */
undefined4 RenderDprizeAll(DPRIZE * arg0, CM * arg1, RO * arg2); /* 0x1478F0 RenderDprizeAll__FP6DPRIZEP2CMP2RO */
undefined4 SetDprizeDprizes(DPRIZE * arg0, DPRIZES arg1); /* 0x147AB0 SetDprizeDprizes__FP6DPRIZE7DPRIZES */
undefined4 InitCoin(COIN * arg0); /* 0x147E40 InitCoin__FP4COIN */
undefined4 UpdateCoin(COIN * arg0, float arg1); /* 0x147FB0 UpdateCoin__FP4COINf */
undefined4 CreateSwCharm(SW * arg0); /* 0x148038 CreateSwCharm__FP2SW */
undefined4 AddLife(void * arg0); /* 0x148178 AddLife__FPv */
undefined4 OnCoinSmack(COIN * arg0); /* 0x1481A0 OnCoinSmack__FP4COIN */
undefined4 SetCoinDprizes(COIN * arg0, DPRIZES arg1); /* 0x148298 SetCoinDprizes__FP4COIN7DPRIZES */
undefined4 InitCharm(CHARM * arg0); /* 0x148400 InitCharm__FP5CHARM */
undefined4 SetCharmDprizes(CHARM * arg0, DPRIZES arg1); /* 0x148470 SetCharmDprizes__FP5CHARM7DPRIZES */
undefined4 InitKey(KEY * arg0); /* 0x148510 InitKey__FP3KEY */
undefined4 SetKeyDprizes(KEY * arg0, DPRIZES arg1); /* 0x148598 SetKeyDprizes__FP3KEY7DPRIZES */
int FUN_00148910(float * arg0, float * arg1); /* 0x148910 FUN_00148910__FPfT0 */
undefined4 CpdprizeAttractSwDprizes(SW * arg0, CID arg1, VECTOR * arg2, int arg3, DPRIZE * * arg4); /* 0x148AC0 CpdprizeAttractSwDprizes__FP2SW3CIDP6VECTORiPP6DPRIZE */
undefined4 RemoveSwExtraneousCharms(SW * arg0); /* 0x148CE0 RemoveSwExtraneousCharms__FP2SW */
undefined4 CollectLifetkn(LIFETKN * arg0); /* 0x148FF0 CollectLifetkn__FP7LIFETKN */
undefined4 InitCplcy(CPLCY * arg0, CM * arg1); /* 0x149398 InitCplcy__FP5CPLCYP2CM */
int FActiveCplcy(CPLCY * arg0); /* 0x1493A0 FActiveCplcy__FP5CPLCY */
undefined4 SetCpmanCpmt(CPMAN * arg0, CPMT arg1); /* 0x1493B8 SetCpmanCpmt__FP5CPMAN4CPMT */
int FUN_001493c0(void); /* 0x1493C0 FUN_001493c0__Fv */
void * PushCplookLookk(CPLOOK * arg0, LOOKK arg1); /* 0x1495E8 PushCplookLookk__FP6CPLOOK5LOOKK */
undefined4 LookkPopCplook(CPLOOK * arg0); /* 0x149610 LookkPopCplook__FP6CPLOOK */
undefined4 LookkCurCplook(CPLOOK * arg0); /* 0x149638 LookkCurCplook__FP6CPLOOK */
int FUN_0014aa90(int * arg0, int arg1); /* 0x14AA90 FUN_0014aa90__FPii */
int FUN_0014aa98(void * arg0); /* 0x14AA98 FUN_0014aa98__FPv */
undefined4 InitCredit(CREDIT * arg0, BLOTK arg1); /* 0x14ABD0 InitCredit__FP6CREDIT5BLOTK */
void * PostCreditLoad(CREDIT * arg0); /* 0x14AC48 PostCreditLoad__FP6CREDIT */
undefined4 SetCreditClock(CREDIT * arg0, float * arg1); /* 0x14AD00 SetCreditClock__FP6CREDITPf */
undefined4 UpdateCredit(CREDIT * arg0); /* 0x14AD70 UpdateCredit__FP6CREDIT */
undefined4 DrawCredit(CREDIT * arg0); /* 0x14ADE0 DrawCredit__FP6CREDIT */
void * PlaceCredit(CREDIT * arg0, float arg1, float arg2, int arg3); /* 0x14AEA0 PlaceCredit__FP6CREDITffi */
undefined4 VacateCredit(CREDIT * arg0); /* 0x14AF10 VacateCredit__FP6CREDIT */
undefined4 SetCreditLine(CREDIT * arg0, int arg1, char * arg2, float arg3); /* 0x14AF38 SetCreditLine__FP6CREDITiPcf */
undefined4 CroutDecomp(int arg0, float * arg1, float * arg2); /* 0x14B0C0 CroutDecomp__FiPfT1 */
undefined4 CroutSolve(int arg0, float * arg1, float * arg2, float * arg3); /* 0x14B3E0 CroutSolve__FiPfN21 */
undefined4 OnCrfodAdd(CRFOD * arg0); /* 0x14B550 OnCrfodAdd__FP5CRFOD */
undefined4 OnCrfodRemove(CRFOD * arg0); /* 0x14B588 OnCrfodRemove__FP5CRFOD */
undefined4 CloneCrfod(CRFOD * arg0, CRFOD * arg1); /* 0x14B5C0 CloneCrfod__FP5CRFODT0 */
undefined4 InitCrfodb(CRFODB * arg0); /* 0x14B608 InitCrfodb__FP6CRFODB */
void * PostCrfodbLoad(CRFODB * arg0); /* 0x14B640 PostCrfodbLoad__FP6CRFODB */
undefined4 CalcHeadingVector(float arg0, VECTOR * arg1); /* 0x14B678 CalcHeadingVector__FfP6VECTOR */
undefined4 UpdateCrfodbGoal(CRFODB * arg0, int arg1); /* 0x14B6A8 UpdateCrfodbGoal__FP6CRFODBi */
int FDetectCrfodb(CRFODB * arg0); /* 0x14BB08 FDetectCrfodb__FP6CRFODB */
int FAbsorbCrfodbWkr(CRFODB * arg0, WKR * arg1); /* 0x14BCE8 FAbsorbCrfodbWkr__FP6CRFODBP3WKR */
undefined4 SgsNextCrfodkAI(CRFODK * arg0); /* 0x14BDC8 SgsNextCrfodkAI__FP6CRFODK */
int FDetectCrfodk(CRFODK * arg0); /* 0x14BEA8 FDetectCrfodk__FP6CRFODK */
int FAbsorbCrfodkWkr(CRFODK * arg0, WKR * arg1); /* 0x14BEF8 FAbsorbCrfodkWkr__FP6CRFODKP3WKR */
undefined4 InitCrbrain(CRBRAIN * arg0); /* 0x14C018 InitCrbrain__FP7CRBRAIN */
float SMeasureApos(int arg0, VECTOR * arg1, float * arg2); /* 0x14D0A8 SMeasureApos__FiP6VECTORPf */
float GWrapApos(float arg0, int arg1, float * arg2, int arg3); /* 0x14D138 GWrapApos__FfiPfi */
undefined4 IposFindAposG(float arg0, int arg1, float * arg2, int arg3, float * arg4, float * arg5); /* 0x14D1A0 IposFindAposG__FfiPfiT2T2 */
undefined4 EvaluateAposG(float arg0, int arg1, VECTOR * arg2, float * arg3, int arg4, VECTOR * arg5, VECTOR * arg6); /* 0x14D280 EvaluateAposG__FfiP6VECTORPfiT2T2 */
undefined4 FindAposClosestPointAll(VECTOR * arg0, CONSTR * arg1, int arg2, VECTOR * arg3, VECTOR * arg4, VECTOR * arg5, int * arg6, float * arg7); /* 0x14D3A8 FindAposClosestPointAll__FP6VECTORP6CONSTRiT0N20PiPf */
undefined4 FindAposClosestPointSegment(VECTOR * arg0, CONSTR * arg1, int arg2, VECTOR * arg3, int arg4, int arg5, VECTOR * arg6, VECTOR * arg7, int * arg8, float * arg9); /* 0x14D680 FindAposClosestPointSegment__FP6VECTORP6CONSTRiT0iiT0T0PiPf */
undefined4 ConvertApos(int arg0, VECTOR * arg1, MATRIX4 * arg2, MATRIX4 * arg3); /* 0x14D938 ConvertApos__FiP6VECTORP7MATRIX4T2 */
void * PcrvNew(CRVK arg0); /* 0x14D9A8 PcrvNew__F4CRVK */
float SFromCrvU(CRV * arg0, float arg1); /* 0x14DA18 SFromCrvU__FP3CRVf */
undefined4 UFromCrvS(CRV * arg0, float arg1); /* 0x14DA28 UFromCrvS__FP3CRVf */
undefined4 IcvFindCrvU(CRV * arg0, float arg1, float * arg2, float * arg3); /* 0x14DA38 IcvFindCrvU__FP3CRVfPfT2 */
undefined4 IcvFindCrvS(CRV * arg0, float arg1, float * arg2, float * arg3); /* 0x14DA68 IcvFindCrvS__FP3CRVfPfT2 */
float GMeasureCrvU(CRVMC * arg0, float arg1); /* 0x14DA98 GMeasureCrvU__FP5CRVMCf */
undefined4 UMaxCrv(CRV * arg0); /* 0x14DB40 UMaxCrv__FP3CRV */
float SMaxCrv(CRV * arg0); /* 0x14DB58 SMaxCrv__FP3CRV */
float SMeasureCrvSegmentU(CRVMS * arg0, float arg1); /* 0x14DB78 SMeasureCrvSegmentU__FP5CRVMSf */
undefined4 FindCrvClosestPointOnLineSegmentFromU(CRV * arg0, VECTOR * arg1, VECTOR * arg2, float arg3, VECTOR * arg4, VECTOR * arg5, float * arg6, float * arg7); /* 0x14DBD0 FindCrvClosestPointOnLineSegmentFromU__FP3CRVP6VECTORT1fT1T1PfT6 */
undefined4 DuGetCrvSearchIncrement(CRV * arg0); /* 0x14DD00 DuGetCrvSearchIncrement__FP3CRV */
undefined4 LoadCrvlFromBrx(CRVL * arg0, CBinaryInputStream * arg1); /* 0x14DD28 LoadCrvlFromBrx__FP4CRVLP18CBinaryInputStream */
undefined4 EvaluateCrvlFromU(CRVL * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x14DE08 EvaluateCrvlFromU__FP4CRVLfP6VECTORT2 */
undefined4 EvaluateCrvlFromS(CRVL * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x14DE40 EvaluateCrvlFromS__FP4CRVLfP6VECTORT2 */
undefined4 RenderCrvlSegment(CRVL * arg0, int arg1, MATRIX4 * arg2, CM * arg3, RGBA arg4, int arg5); /* 0x14DE78 RenderCrvlSegment__FP4CRVLiP7MATRIX4P2CMG4RGBAi */
undefined4 ConvertCrvl(CRVL * arg0, MATRIX4 * arg1, MATRIX4 * arg2); /* 0x14DF68 ConvertCrvl__FP4CRVLP7MATRIX4T1 */
float SFromCrvlU(CRVL * arg0, float arg1); /* 0x14DF98 SFromCrvlU__FP4CRVLf */
undefined4 UFromCrvlS(CRVL * arg0, float arg1); /* 0x14E000 UFromCrvlS__FP4CRVLf */
undefined4 MeasureCrvl(CRVL * arg0); /* 0x14E068 MeasureCrvl__FP4CRVL */
undefined4 FindCrvlClosestPointAll(CRVL * arg0, VECTOR * arg1, CONSTR * arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, float * arg6); /* 0x14E090 FindCrvlClosestPointAll__FP4CRVLP6VECTORP6CONSTRT1T1PfT5 */
undefined4 FindCrvlClosestPointFromU(CRVL * arg0, VECTOR * arg1, float arg2, CONSTR * arg3, VECTOR * arg4, VECTOR * arg5, float * arg6, float * arg7); /* 0x14E170 FindCrvlClosestPointFromU__FP4CRVLP6VECTORfP6CONSTRT1T1PfT6 */
undefined4 FindCrvlClosestPointFromS(CRVL * arg0, VECTOR * arg1, float arg2, CONSTR * arg3, VECTOR * arg4, VECTOR * arg5, float * arg6, float * arg7); /* 0x14E2A0 FindCrvlClosestPointFromS__FP4CRVLP6VECTORfP6CONSTRT1T1PfT6 */
undefined4 LoadCrvcFromBrx(CRVC * arg0, CBinaryInputStream * arg1); /* 0x14E3D0 LoadCrvcFromBrx__FP4CRVCP18CBinaryInputStream */
undefined4 InvalidateCrvcCache(CRVC * arg0); /* 0x14E500 InvalidateCrvcCache__FP4CRVC */
undefined4 FillCrvcCache(CRVC * arg0, int arg1); /* 0x14E510 FillCrvcCache__FP4CRVCi */
undefined4 EvaluateCrvcFromU(CRVC * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x14E5B8 EvaluateCrvcFromU__FP4CRVCfP6VECTORT2 */
undefined4 EvaluateCrvcFromS(CRVC * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x14E6A8 EvaluateCrvcFromS__FP4CRVCfP6VECTORT2 */
undefined4 RenderCrvcSegment(CRVC * arg0, int arg1, MATRIX4 * arg2, CM * arg3, RGBA arg4, int arg5); /* 0x14E710 RenderCrvcSegment__FP4CRVCiP7MATRIX4P2CMG4RGBAi */
undefined4 ConvertCrvc(CRVC * arg0, MATRIX4 * arg1, MATRIX4 * arg2); /* 0x14E828 ConvertCrvc__FP4CRVCP7MATRIX4T1 */
float SFromCrvcU(CRVC * arg0, float arg1); /* 0x14E910 SFromCrvcU__FP4CRVCf */
undefined4 UFromCrvcS(CRVC * arg0, float arg1); /* 0x14E990 UFromCrvcS__FP4CRVCf */
undefined4 MeasureCrvc(CRVC * arg0); /* 0x14EA48 MeasureCrvc__FP4CRVC */
undefined4 FindCrvcClosestPointAll(CRVC * arg0, VECTOR * arg1, CONSTR * arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, float * arg6); /* 0x14EB10 FindCrvcClosestPointAll__FP4CRVCP6VECTORP6CONSTRT1T1PfT5 */
undefined4 FindCrvcClosestPointFromU(CRVC * arg0, VECTOR * arg1, float arg2, CONSTR * arg3, VECTOR * arg4, VECTOR * arg5, float * arg6, float * arg7); /* 0x14EC70 FindCrvcClosestPointFromU__FP4CRVCP6VECTORfP6CONSTRT1T1PfT6 */
undefined4 FindCrvcClosestPointFromS(CRVC * arg0, VECTOR * arg1, float arg2, CONSTR * arg3, VECTOR * arg4, VECTOR * arg5, float * arg6, float * arg7); /* 0x14ED98 FindCrvcClosestPointFromS__FP4CRVCP6VECTORfP6CONSTRT1T1PfT6 */
undefined4 InitDart(DART * arg0); /* 0x14EE40 InitDart__FP4DART */
undefined4 OnDartAdd(DART * arg0); /* 0x14EE70 OnDartAdd__FP4DART */
undefined4 RemoveDart(DART * arg0); /* 0x14EF00 RemoveDart__FP4DART */
undefined4 CloneDart(DART * arg0, DART * arg1); /* 0x14EF40 CloneDart__FP4DARTT0 */
undefined4 LoadDartFromBrx(DART * arg0, CBinaryInputStream * arg1); /* 0x14EF88 LoadDartFromBrx__FP4DARTP18CBinaryInputStream */
undefined4 HandleDartMessage(DART * arg0, MSGID arg1, void * arg2); /* 0x14EFB8 HandleDartMessage__FP4DART5MSGIDPv */
void * PostDartLoad(DART * arg0); /* 0x14F020 PostDartLoad__FP4DART */
undefined4 UpdateDart(DART * arg0, float arg1); /* 0x14F058 UpdateDart__FP4DARTf */
undefined4 SetDartDarts(DART * arg0, DARTS arg1); /* 0x14F110 SetDartDarts__FP4DART5DARTS */
undefined4 ApplyDartThrow(DART * arg0, PO * arg1); /* 0x14F168 ApplyDartThrow__FP4DARTP2PO */
undefined4 UpdateDartAirborne(DART * arg0, float arg1); /* 0x14F270 UpdateDartAirborne__FP4DARTf */
undefined4 InitDartgun(DARTGUN * arg0); /* 0x14F740 InitDartgun__FP7DARTGUN */
undefined4 HandleDartgunMessage(DARTGUN * arg0, MSGID arg1, void * arg2); /* 0x14F770 HandleDartgunMessage__FP7DARTGUN5MSGIDPv */
undefined4 BindDartgun(DARTGUN * arg0); /* 0x14F850 BindDartgun__FP7DARTGUN */
void * PostDartgunLoad(DARTGUN * arg0); /* 0x14F920 PostDartgunLoad__FP7DARTGUN */
undefined4 UpdateDartgun(DARTGUN * arg0, float arg1); /* 0x14FA88 UpdateDartgun__FP7DARTGUNf */
int FIgnoreDartgunIntersection(DARTGUN * arg0, SO * arg1); /* 0x14FBE0 FIgnoreDartgunIntersection__FP7DARTGUNP2SO */
undefined4 BreakDartgun(DARTGUN * arg0); /* 0x14FC38 BreakDartgun__FP7DARTGUN */
undefined4 SetDartgunGoalState(DARTGUN * arg0, OID arg1); /* 0x14FCE8 SetDartgunGoalState__FP7DARTGUN3OID */
undefined4 TrackDartgun(DARTGUN * arg0, OID * arg1); /* 0x14FDA8 TrackDartgun__FP7DARTGUNP3OID */
int FPrepareDartgunToFire(DARTGUN * arg0); /* 0x14FEC0 FPrepareDartgunToFire__FP7DARTGUN */
undefined4 FireDartgun(DARTGUN * arg0); /* 0x150008 FireDartgun__FP7DARTGUN */
undefined4 AgeDartgunStuckDart(DARTGUN * arg0); /* 0x150298 AgeDartgunStuckDart__FP7DARTGUN */
void * PratGetDartgunRatTarget(DARTGUN * arg0); /* 0x150338 PratGetDartgunRatTarget__FP7DARTGUN */
undefined4 AddDartgunRatTarget(DARTGUN * arg0, OID arg1); /* 0x1503E0 AddDartgunRatTarget__FP7DARTGUN3OID */
undefined4 StartDartgunTargetAreaChange(DARTGUN * arg0); /* 0x150408 StartDartgunTargetAreaChange__FP7DARTGUN */
undefined4 AddDartgunTargetAreaTarget(DARTGUN * arg0, ALO * arg1); /* 0x150418 AddDartgunTargetAreaTarget__FP7DARTGUNP3ALO */
undefined4 InitDialog(DIALOG * arg0); /* 0x1504E0 InitDialog__FP6DIALOG */
undefined4 LoadDialogFromBrx(DIALOG * arg0, CBinaryInputStream * arg1); /* 0x150528 LoadDialogFromBrx__FP6DIALOGP18CBinaryInputStream */
undefined4 LoadDialogEventsFromBrx(DIALOG * arg0, CBinaryInputStream * arg1, int * arg2, DE * * arg3); /* 0x150570 LoadDialogEventsFromBrx__FP6DIALOGP18CBinaryInputStreamPiPP2DE */
void * PostDialogLoad(DIALOG * arg0); /* 0x1506F0 PostDialogLoad__FP6DIALOG */
undefined4 SetDialogInstruct(DIALOG * arg0); /* 0x150750 SetDialogInstruct__FP6DIALOG */
undefined4 SetDialogConfront(DIALOG * arg0); /* 0x150760 SetDialogConfront__FP6DIALOG */
undefined4 GetDialogPlayed(DIALOG * arg0, int * arg1); /* 0x150770 GetDialogPlayed__FP6DIALOGPi */
undefined4 SetDialogPlayed(DIALOG * arg0, int arg1); /* 0x150780 SetDialogPlayed__FP6DIALOGi */
undefined4 SetDialogDialogs(DIALOG * arg0, DIALOGS arg1); /* 0x150790 SetDialogDialogs__FP6DIALOG7DIALOGS */
undefined4 UpdateDialog(DIALOG * arg0, float arg1); /* 0x150AE8 UpdateDialog__FP6DIALOGf */
undefined4 HandleDialogEvent(DIALOG * arg0, DE * arg1); /* 0x150DC0 HandleDialogEvent__FP6DIALOGP2DE */
undefined4 HandleDialogMessage(DIALOG * arg0, MSGID arg1, void * arg2); /* 0x1512A8 HandleDialogMessage__FP6DIALOG5MSGIDPv */
int FPauseDialog(DIALOG * arg0); /* 0x151300 FPauseDialog__FP6DIALOG */
undefined4 HandleDialogEvents(DIALOG * arg0); /* 0x1517C0 HandleDialogEvents__FP6DIALOG */
int FUN_00151860(DIALOG * arg0, BLOT * arg1); /* 0x151860 FUN_00151860__FP6DIALOGP4BLOT */
undefined4 TriggerDialog(DIALOG * arg0); /* 0x1518B8 TriggerDialog__FP6DIALOG */
undefined4 UntriggerDialog(DIALOG * arg0); /* 0x1519A8 UntriggerDialog__FP6DIALOG */
int FUN_00151A58(void); /* 0x151A58 FUN_00151A58__Fv */
undefined4 OnDifficultyGameLoad(DIFFICULTY * arg0); /* 0x151A68 OnDifficultyGameLoad__FP10DIFFICULTY */
undefined4 OnDifficultyInitialTeleport(DIFFICULTY * arg0); /* 0x151E18 OnDifficultyInitialTeleport__FP10DIFFICULTY */
undefined4 OnDifficultyTriggerCheckpoint(DIFFICULTY * arg0, CHKPNT * arg1); /* 0x151ED8 OnDifficultyTriggerCheckpoint__FP10DIFFICULTYP6CHKPNT */
undefined4 OnDifficultyCollectKey(DIFFICULTY * arg0); /* 0x151FC8 OnDifficultyCollectKey__FP10DIFFICULTY */
undefined4 ChangeSuck(float arg0, DIFFICULTY * arg1); /* 0x152410 ChangeSuck__FfP10DIFFICULTY */
undefined4 InitDl(DL * arg0, int arg1); /* 0x152438 InitDl__FP2DLi */
undefined4 ClearDl(DL * arg0); /* 0x152440 ClearDl__FP2DL */
undefined4 ClearDle(DLE * arg0); /* 0x152450 ClearDle__FP3DLE */
void * PdleFromDlEntry(DL * arg0, void * arg1); /* 0x152460 PdleFromDlEntry__FP2DLPv */
undefined4 AppendDlEntry(DL * arg0, void * arg1); /* 0x152470 AppendDlEntry__FP2DLPv */
void * PrependDlEntry(DL * arg0, void * arg1); /* 0x1524D8 PrependDlEntry__FP2DLPv */
undefined4 InsertDlEntryBefore(DL * arg0, void * arg1, void * arg2); /* 0x152540 InsertDlEntryBefore__FP2DLPvT1 */
undefined4 RemoveDlEntry(DL * arg0, void * arg1); /* 0x152600 RemoveDlEntry__FP2DLPv */
int FFindDlEntry(DL * arg0, void * arg1); /* 0x1526D0 FFindDlEntry__FP2DLPv */
int FIsDlEmpty(DL * arg0); /* 0x152720 FIsDlEmpty__FP2DL */
undefined4 MergeDl(DL * arg0, DL * arg1); /* 0x152730 MergeDl__FP2DLT0 */
int CPvDl(DL * arg0); /* 0x1527D8 CPvDl__FP2DL */
undefined4 StartupDma(void); /* 0x152810 StartupDma__Fv */
void DMAS_constructor(DMAS *this); /* 0x152888 __4DMAS */
undefined4 DMAS_Clear(DMAS *this); /* 0x1528C8 Clear__4DMAS */
undefined4 DMAS_Reset(DMAS *this); /* 0x1528E0 Reset__4DMAS */
undefined4 DMAS_AllocGlobal(DMAS *this, int arg1); /* 0x1528F0 AllocGlobal__4DMASi */
undefined4 DMAS_AllocSw(DMAS *this, int arg1, int arg2); /* 0x152938 AllocSw__4DMASii */
undefined4 DMAS_AllocStack(DMAS *this, int arg1); /* 0x152980 AllocStack__4DMASi */
undefined4 DMAS_AllocStatic(DMAS *this, int arg1, QW * arg2); /* 0x1529C8 AllocStatic__4DMASiP2QW */
undefined4 DMAS_Detach(DMAS *this, int * arg1, QW * * arg2); /* 0x1529E0 Detach__4DMASPiPP2QW */
undefined4 DMAS_DetachCopySw(DMAS *this, int * arg1, QW * * arg2, QW * * arg3, int arg4); /* 0x152A50 DetachCopySw__4DMASPiPP2QWT2i */
undefined4 DMAS_Send(DMAS *this, sceDmaChan * arg1); /* 0x152AE0 Send__4DMASP10sceDmaChan */
undefined4 DMAS_AddDmaCnt(DMAS *this); /* 0x152B38 AddDmaCnt__4DMAS */
undefined4 DMAS_AddDmaRefs(DMAS *this, int arg1, QW * arg2); /* 0x152B80 AddDmaRefs__4DMASiP2QW */
undefined4 DMAS_AddDmaCall(DMAS *this, QW * arg1); /* 0x152C18 AddDmaCall__4DMASP2QW */
undefined4 DMAS_AddDmaRet(DMAS *this); /* 0x152CA0 AddDmaRet__4DMAS */
undefined4 DMAS_AddDmaBulk(DMAS *this, int arg1, QW * arg2); /* 0x152CE0 AddDmaBulk__4DMASiP2QW */
undefined4 DMAS_AddDmaEnd(DMAS *this); /* 0x152D30 AddDmaEnd__4DMAS */
undefined4 DMAS_EndDmaCnt(DMAS *this); /* 0x152D70 EndDmaCnt__4DMAS */
undefined4 DMAS_EndPrim(DMAS *this, int arg1); /* 0x152E18 EndPrim__4DMASi */
undefined4 InitDysh(DYSH * arg0); /* 0x152E28 InitDysh__FP4DYSH */
undefined4 SetDyshShadow(DYSH * arg0, SHADOW * arg1); /* 0x152E48 SetDyshShadow__FP4DYSHP6SHADOW */
undefined4 RenderDyshSelf(DYSH * arg0, CM * arg1, RO * arg2); /* 0x153328 RenderDyshSelf__FP4DYSHP2CMP2RO */
undefined4 DrawDysh(RPL * arg0); /* 0x1533A8 DrawDysh__FP3RPL */
undefined4 InitDzg(DZG * arg0, int arg1); /* 0x153528 InitDzg__FP3DZGi */
undefined4 ClearDzgSolution(DZG * arg0); /* 0x153608 ClearDzgSolution__FP3DZG */
undefined4 AppendDzgDz(DZG * arg0, DZ * arg1); /* 0x1536C8 AppendDzgDz__FP3DZGP2DZ */
undefined4 FillDzgDz(DZG * arg0, int arg1, DZ * arg2, int arg3, XP * * arg4, int * arg5, SO * * * arg6); /* 0x153780 FillDzgDz__FP3DZGiP2DZiPP2XPPiPPP2SO */
undefined4 EnforceDzgDz(DZG * arg0, DZ * arg1); /* 0x153A50 EnforceDzgDz__FP3DZGP2DZ */
undefined4 SolveDzg(DZG * arg0, int arg1, int arg2, XP * * arg3, int * arg4, SO * * * arg5); /* 0x153EC0 SolveDzg__FP3DZGiiPP2XPPiPPP2SO */
undefined4 SolveDzgFric(DZG * arg0, int arg1, int arg2, XP * * arg3, int * arg4, SO * * * arg5, float arg6); /* 0x154088 SolveDzgFric__FP3DZGiiPP2XPPiPPP2SOf */
undefined4 ApplyDzg(DZG * arg0, int arg1, int * arg2, SO * * * arg3, float arg4, float arg5); /* 0x154370 ApplyDzg__FP3DZGiPiPPP2SOff */
undefined4 SolveInequalities(int arg0, float * arg1, float * arg2, float * arg3); /* 0x154880 SolveInequalities__FiPfN21 */
undefined4 InitEmitb(EMITB * arg0); /* 0x1549C8 InitEmitb__FP5EMITB */
undefined4 InitEmitter(EMITTER * arg0); /* 0x154C10 InitEmitter__FP7EMITTER */
undefined4 LoadEmitmeshFromBrx(EMITMESH * arg0, CBinaryInputStream * arg1); /* 0x154C80 LoadEmitmeshFromBrx__FP8EMITMESHP18CBinaryInputStream */
undefined4 LoadEmitblipColorsFromBrx(EMITBLIP * arg0, int arg1, LO * arg2, CBinaryInputStream * arg3); /* 0x154EE0 LoadEmitblipColorsFromBrx__FP8EMITBLIPiP2LOP18CBinaryInputStream */
undefined4 LoadEmitterFromBrx(EMITTER * arg0, CBinaryInputStream * arg1); /* 0x154F98 LoadEmitterFromBrx__FP7EMITTERP18CBinaryInputStream */
undefined4 CloneEmitter(EMITTER * arg0, EMITTER * arg1); /* 0x155080 CloneEmitter__FP7EMITTERT0 */
undefined4 BindEmitterCallback(EMITTER * arg0, MSGID arg1, void * arg2); /* 0x1550B8 BindEmitterCallback__FP7EMITTER5MSGIDPv */
undefined4 BindEmitter(EMITTER * arg0); /* 0x1550E8 BindEmitter__FP7EMITTER */
void * PostEmitterLoad(EMITTER * arg0); /* 0x155270 PostEmitterLoad__FP7EMITTER */
undefined4 HandleEmitterMessage(EMITTER * arg0, MSGID arg1, void * arg2); /* 0x155678 HandleEmitterMessage__FP7EMITTER5MSGIDPv */
void * PemitbCopyOnWrite(EMITB * arg0); /* 0x1556E8 PemitbCopyOnWrite__FP5EMITB */
void * PemitbEnsureEmitter(EMITTER * arg0, ENSK arg1); /* 0x155778 PemitbEnsureEmitter__FP7EMITTER4ENSK */
undefined4 PemitterEnsureEmitter(EMITTER * arg0, ENSK arg1); /* 0x1557B8 PemitterEnsureEmitter__FP7EMITTER4ENSK */
undefined4 AddEmitterSkeleton(EMITTER * arg0, OID arg1, OID arg2, float arg3, float arg4, float arg5, float arg6); /* 0x1557D0 AddEmitterSkeleton__FP7EMITTER3OIDT1ffff */
undefined4 ModifyEmitterParticles(EMITTER * arg0); /* 0x155868 ModifyEmitterParticles__FP7EMITTER */
undefined4 UpdateEmitter(EMITTER * arg0, float arg1); /* 0x155AB0 UpdateEmitter__FP7EMITTERf */
void * PauseEmitter(EMITTER * arg0, float arg1); /* 0x155F78 PauseEmitter__FP7EMITTERf */
void * PauseEmitterIndefinite(EMITTER * arg0); /* 0x155F90 PauseEmitterIndefinite__FP7EMITTER */
undefined4 UnpauseEmitter(EMITTER * arg0); /* 0x155FA0 UnpauseEmitter__FP7EMITTER */
int FPausedEmitter(EMITTER * arg0); /* 0x155FB0 FPausedEmitter__FP7EMITTER */
undefined4 SetEmitterEnabled(EMITTER * arg0, int arg1); /* 0x156000 SetEmitterEnabled__FP7EMITTERi */
undefined4 GetEmitterEnabled(EMITTER * arg0, int * arg1); /* 0x156030 GetEmitterEnabled__FP7EMITTERPi */
undefined4 GetEmitterPaused(EMITTER * arg0, int * arg1); /* 0x156060 GetEmitterPaused__FP7EMITTERPi */
undefined4 OnEmitterValuesChanged(EMITTER * arg0); /* 0x156088 OnEmitterValuesChanged__FP7EMITTER */
undefined4 SetEmitterParticleCount(EMITTER * arg0, int arg1); /* 0x156108 SetEmitterParticleCount__FP7EMITTERi */
undefined4 SetEmitterAutoPause(EMITTER * arg0, int arg1); /* 0x156178 SetEmitterAutoPause__FP7EMITTERi */
undefined4 SetEmitbRipt(EMITB * arg0, RIPT arg1); /* 0x156188 SetEmitbRipt__FP5EMITB4RIPT */
undefined4 SetEmitterRipt(EMITTER * arg0, RIPT arg1); /* 0x156218 SetEmitterRipt__FP7EMITTER4RIPT */
undefined4 SetExploRipt(EXPLO * arg0, RIPT arg1); /* 0x156250 SetExploRipt__FP5EXPLO4RIPT */
undefined4 WakeSoWater(SO * arg0, WATER * arg1, float arg2, VECTOR * arg3, VECTOR * arg4, float arg5, float arg6); /* 0x156288 WakeSoWater__FP2SOP5WATERfP6VECTORT3ff */
undefined4 StandardSmokeCloud(VECTOR * arg0, float arg1); /* 0x1566C8 StandardSmokeCloud__FP6VECTORf */
undefined4 ChooseEmitoPos(EMITO * arg0, int arg1, int arg2, VECTOR * arg3, VECTOR * arg4); /* 0x156718 ChooseEmitoPos__FP5EMITOiiP6VECTORT3 */
undefined4 ConvertEmitoPosVec(EMITO * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x156F08 ConvertEmitoPosVec__FP5EMITOP6VECTORT1 */
undefined4 CalculateEmitvx(int arg0, LM * arg1, int arg2, EMITVX * arg3); /* 0x156FC8 CalculateEmitvx__FiP2LMiP6EMITVX */
undefined4 ChooseEmitVelocity(EMITVX * arg0, float arg1, float arg2, LM * arg3, VECTOR * arg4, int arg5, VECTOR * arg6); /* 0x157098 ChooseEmitVelocity__FP6EMITVXffP2LMP6VECTORiT4 */
undefined4 ChooseEmitvVelocityAge(EMITV * arg0, EMITVX * arg1, EMITO * arg2, int arg3, VECTOR * arg4, VECTOR * arg5, VECTOR * arg6, float * arg7, float * arg8); /* 0x157248 ChooseEmitvVelocityAge__FP5EMITVP6EMITVXP5EMITOiP6VECTORN24PfT7 */
undefined4 EmitRips(EMITB * arg0, EMITG * arg1, int arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, float * arg6); /* 0x157320 EmitRips__FP5EMITBP5EMITGiP6VECTORT3PfT5 */
undefined4 EmitBlips(EMITB * arg0, EMITG * arg1, int arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, float * arg6, VECTOR * arg7, VECTOR * arg8); /* 0x1575D8 EmitBlips__FP5EMITBP5EMITGiP6VECTORT3PfT5T3T3 */
undefined4 OriginateParticles(int arg0, EMITB * arg1, EMITGEN * arg2); /* 0x1579B0 OriginateParticles__FiP5EMITBP7EMITGEN */
undefined4 OriginateSplineSinkParticles(int arg0, EMITB * arg1, EMITGEN * arg2, EMITGEN * arg3); /* 0x157B88 OriginateSplineSinkParticles__FiP5EMITBR7EMITGENT2 */
undefined4 EmitParticles(int arg0, EMITB * arg1, EMITG * arg2); /* 0x157E00 EmitParticles__FiP5EMITBP5EMITG */
undefined4 EmitRipsSphere(VECTOR * arg0, VECTOR * arg1, int arg2, EMITRIP * arg3, EMITV * arg4, RIPG * * arg5, LO * arg6); /* 0x157EF8 EmitRipsSphere__FP6VECTORT0iP7EMITRIPP5EMITVPP4RIPGP2LO */
undefined4 StockSplashBig(VECTOR * arg0, float arg1, SO * arg2); /* 0x157FF8 StockSplashBig__FP6VECTORfP2SO */
undefined4 StockSplashSmall(VECTOR * arg0, float arg1, SO * arg2); /* 0x158108 StockSplashSmall__FP6VECTORfP2SO */
undefined4 AddEmitoSkeleton(EMITO * arg0, OID arg1, OID arg2, float arg3, float arg4, float arg5, float arg6, LO * arg7); /* 0x158198 AddEmitoSkeleton__FP5EMITO3OIDT1ffffP2LO */
undefined4 BindEmitb(EMITB * arg0, LO * arg1); /* 0x158288 BindEmitb__FP5EMITBP2LO */
undefined4 SetEmitdvEmitb(EMITDV * arg0, EMITB * arg1); /* 0x1583E8 SetEmitdvEmitb__FP6EMITDVP5EMITB */
undefined4 CalculateEmitdvMatrix(EMITDV * arg0, float arg1, MATRIX4 * arg2); /* 0x158480 CalculateEmitdvMatrix__FP6EMITDVfP7MATRIX4 */
void * PostExplLoad(EXPL * arg0); /* 0x1585F8 PostExplLoad__FP4EXPL */
undefined4 CalculateExplTransform(EXPL * arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x158630 CalculateExplTransform__FP4EXPLP6VECTORP7MATRIX3 */
undefined4 ExplodeExpl(EXPL * arg0); /* 0x158730 ExplodeExpl__FP4EXPL */
undefined4 ExplodeExplParams(EXPL * arg0, unsigned int arg1, ALO * arg2, VECTOR * arg3, VECTOR * arg4, float arg5, float arg6); /* 0x158778 ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff */
undefined4 ExplodeExplExplso(EXPL * arg0, EXPLSO * arg1); /* 0x1587C0 ExplodeExplExplso__FP4EXPLP6EXPLSO */
undefined4 LoadExplgFromBrx(EXPLG * arg0, CBinaryInputStream * arg1); /* 0x1587C8 LoadExplgFromBrx__FP5EXPLGP18CBinaryInputStream */
undefined4 CloneExplg(EXPLG * arg0, EXPLG * arg1); /* 0x158980 CloneExplg__FP5EXPLGT0 */
undefined4 BindExplg(EXPLG * arg0); /* 0x158A10 BindExplg__FP5EXPLG */
undefined4 ExplodeExplgExplso(EXPLG * arg0, EXPLSO * arg1); /* 0x158A80 ExplodeExplgExplso__FP5EXPLGP6EXPLSO */
undefined4 InitExplo(EXPLO * arg0); /* 0x158B00 InitExplo__FP5EXPLO */
undefined4 LoadExploFromBrx(EXPLO * arg0, CBinaryInputStream * arg1); /* 0x158B30 LoadExploFromBrx__FP5EXPLOP18CBinaryInputStream */
undefined4 CloneExplo(EXPLO * arg0, EXPLO * arg1); /* 0x158C28 CloneExplo__FP5EXPLOT0 */
undefined4 BindExplo(EXPLO * arg0); /* 0x158C60 BindExplo__FP5EXPLO */
undefined4 ExplodeExploExplso(EXPLO * arg0, EXPLSO * arg1); /* 0x158D38 ExplodeExploExplso__FP5EXPLOP6EXPLSO */
undefined4 AddExploSkeleton(EXPLO * arg0, OID arg1, OID arg2, float arg3, float arg4, float arg5, float arg6); /* 0x158D40 AddExploSkeleton__FP5EXPLO3OIDT1ffff */
void * PemitbEnsureExplo(EXPLO * arg0, ENSK arg1); /* 0x158DD8 PemitbEnsureExplo__FP5EXPLO4ENSK */
undefined4 InitExpls(EXPLS * arg0); /* 0x158E10 InitExpls__FP5EXPLS */
undefined4 BindExpls(EXPLS * arg0); /* 0x158E48 BindExpls__FP5EXPLS */
undefined4 HandleExplsMessage(EXPLS * arg0, MSGID arg1, void * arg2); /* 0x158F10 HandleExplsMessage__FP5EXPLS5MSGIDPv */
undefined4 ExplodeExplsExplso(EXPLS * arg0, EXPLSO * arg1); /* 0x158F80 ExplodeExplsExplso__FP5EXPLSP6EXPLSO */
void * PsfxEnsureExpls(EXPLS * arg0, ENSK arg1); /* 0x159068 PsfxEnsureExpls__FP5EXPLS4ENSK */
undefined4 FireExplsExplso(EXPLS * arg0, EXPLSO * arg1); /* 0x1590A0 FireExplsExplso__FP5EXPLSP6EXPLSO */
undefined4 InferExpl(EXPL * * arg0, ALO * arg1); /* 0x159478 InferExpl__FPP4EXPLP3ALO */
undefined4 FireSwTimedExplodeStyles(SW * arg0); /* 0x159588 FireSwTimedExplodeStyles__FP2SW */
undefined4 InitEyes(EYES * arg0, SAAF * arg1); /* 0x159680 InitEyes__FP4EYESP4SAAF */
void * PostEyesLoad(EYES * arg0); /* 0x1596E0 PostEyesLoad__FP4EYES */
undefined4 SetEyesEyess(EYES * arg0, EYESS arg1); /* 0x159770 SetEyesEyess__FP4EYES5EYESS */
undefined4 UpdateEyes(EYES * arg0, float arg1); /* 0x159890 UpdateEyes__FP4EYESf */
undefined4 SetEyesClosed(EYES * arg0, float arg1); /* 0x159A00 SetEyesClosed__FP4EYESf */
void * PsaiFromEyesShd(EYES * arg0, SHD * arg1); /* 0x159A80 PsaiFromEyesShd__FP4EYESP3SHD */
undefined4 UpdateFader(FADER * arg0, float arg1); /* 0x159AD0 UpdateFader__FP5FADERf */
void * PfaderNew(ALO * arg0); /* 0x159BB0 PfaderNew__FP3ALO */
undefined4 RemoveFader(FADER * arg0); /* 0x159C28 RemoveFader__FP5FADER */
void * PdlFromSwOid(SW * arg0, OID arg1); /* 0x159F20 PdlFromSwOid__FP2SW3OID */
undefined4 MatchSwObject(LO * arg0, int arg1, int arg2, int arg3, LO * arg4, int arg5, int * arg6, LO * * arg7, int * arg8); /* 0x159F48 MatchSwObject__FP2LOiiiT0iPiPP2LOT6 */
undefined4 CploFindSwObjects(SW * arg0, int arg1, OID arg2, LO * arg3, int arg4, LO * * arg5); /* 0x15A198 CploFindSwObjects__FP2SWi3OIDP2LOiPP2LO */
void * PloFindSwObject(SW * arg0, int arg1, OID arg2, LO * arg3); /* 0x15A418 PloFindSwObject__FP2SWi3OIDP2LO */
void * PloFindSwNearest(SW * arg0, OID arg1, LO * arg2); /* 0x15A448 PloFindSwNearest__FP2SW3OIDP2LO */
void * PloFindSwChild(SW * arg0, OID arg1, ALO * arg2); /* 0x15A480 PloFindSwChild__FP2SW3OIDP3ALO */
int FIsCidDerivedFrom(CID arg0, CID arg1); /* 0x15A4B8 FIsCidDerivedFrom__F3CIDT0 */
undefined4 CploFindSwObjectsByClass(SW * arg0, int arg1, CID arg2, LO * arg3, int arg4, LO * * arg5); /* 0x15A4F0 CploFindSwObjectsByClass__FP2SWi3CIDP2LOiPP2LO */
void * PloFindSwObjectByClass(SW * arg0, int arg1, CID arg2, LO * arg3); /* 0x15A838 PloFindSwObjectByClass__FP2SWi3CIDP2LO */
void * PaloFindLoCommonParent(LO * arg0, LO * arg1); /* 0x15A868 PaloFindLoCommonParent__FP2LOT0 */
undefined4 InitFlash(FLASH * arg0); /* 0x15A8B8 InitFlash__FP5FLASH */
undefined4 LoadFlashFromBrx(FLASH * arg0, CBinaryInputStream * arg1); /* 0x15A918 LoadFlashFromBrx__FP5FLASHP18CBinaryInputStream */
undefined4 UpdateFlash(FLASH * arg0, float arg1); /* 0x15A960 UpdateFlash__FP5FLASHf */
undefined4 RenderFlashSelf(FLASH * arg0, CM * arg1, RO * arg2); /* 0x15A9A8 RenderFlashSelf__FP5FLASHP2CMP2RO */
int FPosFlashWithin(FLASH * arg0, VECTOR * arg1); /* 0x15AA50 FPosFlashWithin__FP5FLASHP6VECTOR */
undefined4 InitFly(FLY * arg0); /* 0x15AAE0 InitFly__FP3FLY */
undefined4 LoadFlyFromBrx(FLY * arg0, CBinaryInputStream * arg1); /* 0x15AC08 LoadFlyFromBrx__FP3FLYP18CBinaryInputStream */
undefined4 CloneFly(FLY * arg0, FLY * arg1); /* 0x15AD80 CloneFly__FP3FLYT0 */
undefined4 FreezeFly(FLY * arg0, int arg1); /* 0x15AE38 FreezeFly__FP3FLYi */
void * PostFlyLoad(FLY * arg0); /* 0x15AEB0 PostFlyLoad__FP3FLY */
void * PresetFlyAccel(FLY * arg0, float arg1); /* 0x15AF50 PresetFlyAccel__FP3FLYf */
undefined4 UpdateFly(FLY * arg0, float arg1); /* 0x15B128 UpdateFly__FP3FLYf */
undefined4 RenderFlySelf(FLY * arg0, CM * arg1, RO * arg2); /* 0x15B4D0 RenderFlySelf__FP3FLYP2CMP2RO */
int FAbsorbFlyWkr(FLY * arg0, WKR * arg1); /* 0x15B720 FAbsorbFlyWkr__FP3FLYP3WKR */
undefined4 SetFlyFlys(FLY * arg0, FLYS arg1); /* 0x15B7B8 SetFlyFlys__FP3FLY4FLYS */
undefined4 EmitFlyDroppings(FLY * arg0); /* 0x15BC78 EmitFlyDroppings__FP3FLY */
int FFindFlyClosestLandingPos(FLY * arg0, VECTOR * arg1); /* 0x15BD48 FFindFlyClosestLandingPos__FP3FLYP6VECTOR */
undefined4 FlysAttemptedFlyLanding(FLY * arg0); /* 0x15BEF0 FlysAttemptedFlyLanding__FP3FLY */
int FShouldFlyFlee(FLY * arg0); /* 0x15BFC0 FShouldFlyFlee__FP3FLY */
int FFilterFly(void * arg0, SO * arg1); /* 0x15C058 FFilterFly__FPvP2SO */
int FCheckFlyOpenSpaceBelow(FLY * arg0); /* 0x15C0A0 FCheckFlyOpenSpaceBelow__FP3FLY */
undefined4 StartupFont(void); /* 0x15C178 StartupFont__Fv */
undefined4 CFont_CopyTo(CFont *this, CFont * arg1); /* 0x15C260 CopyTo__5CFontP5CFont */
undefined4 CFont_SetupDraw(CFont *this, CTextBox * arg1, GIFS * arg2); /* 0x15C2E8 SetupDraw__5CFontP8CTextBoxP4GIFS */
undefined4 CFont_CleanupDraw(CFont *this, CTextBox * arg1, GIFS * arg2); /* 0x15C3C0 CleanupDraw__5CFontP8CTextBoxP4GIFS */
undefined4 CFont_DxFromPchz(CFont *this, char * arg1); /* 0x15C418 DxFromPchz__5CFontPc */
undefined4 CFont_DyWrapPchz(CFont *this, char * arg1, float arg2); /* 0x15C4A8 DyWrapPchz__5CFontPcf */
undefined4 CFont_ClineWrapPchz(CFont *this, char * arg1, float arg2); /* 0x15C4E8 ClineWrapPchz__5CFontPcf */
undefined4 CFont_DrawPchz(CFont *this, char * arg1, CTextBox * arg2, CTextBox * arg3, GIFS * arg4); /* 0x15C638 DrawPchz__5CFontPcP8CTextBoxT2P4GIFS */
void * CFont_PushScaling(CFont *this, float arg1, float arg2); /* 0x15C8B8 PushScaling__5CFontff */
void * CFont_PopScaling(CFont *this); /* 0x15C900 PopScaling__5CFont */
void * CFontBrx_PfontClone(CFontBrx *this, float arg1, float arg2); /* 0x15C930 PfontClone__8CFontBrxff */
undefined4 CFontBrx_CopyTo(CFontBrx *this, CFontBrx * arg1); /* 0x15C9B0 CopyTo__8CFontBrxP8CFontBrx */
int CFontBrx_FValid(CFontBrx *this, char arg1); /* 0x15CA38 FValid__8CFontBrxc */
undefined4 CFontBrx_DxFromCh(CFontBrx *this, char arg1); /* 0x15CA60 DxFromCh__8CFontBrxc */
int CFontBrx_FEnsureLoaded(CFontBrx *this, GIFS * arg1); /* 0x15CAB8 FEnsureLoaded__8CFontBrxP4GIFS */
undefined4 CFontBrx_SetupDraw(CFontBrx *this, CTextBox * arg1, GIFS * arg2); /* 0x15CB88 SetupDraw__8CFontBrxP8CTextBoxP4GIFS */
undefined4 CFontBrx_SwitchTex0(CFontBrx *this, GIFS * arg1); /* 0x15CC80 SwitchTex0__8CFontBrxP4GIFS */
undefined4 CFontBrx_DxDrawCh(CFontBrx *this, char arg1, float arg2, float arg3, unsigned int arg4, GIFS * arg5); /* 0x15CD18 DxDrawCh__8CFontBrxcffUiP4GIFS */
undefined4 CFontBrx_DrawPart(CFontBrx *this, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, unsigned int arg9, GIFS * arg10); /* 0x15D338 DrawPart__8CFontBrxffffffffUiP4GIFS */
undefined4 CFontBrx_EdgeRect(CFontBrx *this, CTextEdge * arg1, CTextBox * arg2, GIFS * arg3); /* 0x15D4E0 EdgeRect__8CFontBrxP9CTextEdgeP8CTextBoxP4GIFS */
undefined4 CFontBrx_LoadFromBrx(CFontBrx *this, CBinaryInputStream * arg1); /* 0x15D8A8 LoadFromBrx__8CFontBrxP18CBinaryInputStream */
void * CFontBrx_PostLoad(CFontBrx *this, GSB * arg1); /* 0x15D998 PostLoad__8CFontBrxP3GSB */
void * CFontBrx_PglyffFromCh(CFontBrx *this, char arg1); /* 0x15DAB8 PglyffFromCh__8CFontBrxc */
void CRichText_constructor(CRichText *this, char * arg1, CFont * arg2); /* 0x15DB28 __9CRichTextPcP5CFont */
undefined4 CRichText_Reset(CRichText *this); /* 0x15DB80 Reset__9CRichText */
undefined4 CRichText_SetBaseColor(CRichText *this, RGBA * arg1); /* 0x15DBB8 SetBaseColor__9CRichTextP4RGBA */
undefined4 CRichText_ChNext(CRichText *this); /* 0x15DBE0 ChNext__9CRichText */
undefined4 CRichText_Cch(CRichText *this); /* 0x15DF58 Cch__9CRichText */
undefined4 CRichText_Trim(CRichText *this, int arg1); /* 0x15DFA0 Trim__9CRichTexti */
undefined4 CRichText_Dx(CRichText *this); /* 0x15DFF8 Dx__9CRichText */
undefined4 CRichText_ClineWrap(CRichText *this, float arg1); /* 0x15E068 ClineWrap__9CRichTextf */
undefined4 CRichText_DxMaxLine(CRichText *this); /* 0x15E1F0 DxMaxLine__9CRichText */
undefined4 CRichText_GetExtents(CRichText *this, float * arg1, float * arg2, float arg3); /* 0x15E290 GetExtents__9CRichTextPfT1f */
undefined4 CRichText_Draw(CRichText *this, CTextBox * arg1, CTextBox * arg2, GIFS * arg3); /* 0x15E318 Draw__9CRichTextP8CTextBoxT1P4GIFS */
void * PostFontsLoad(void); /* 0x15E5F0 PostFontsLoad__Fv */
undefined4 VU1_Interrupt(int arg0); /* 0x15E6A8 VU1_Interrupt__Fi */
undefined4 StartupFrame(void); /* 0x15E810 StartupFrame__Fv */
undefined4 OpenFrame(void); /* 0x15E9F0 OpenFrame__Fv */
undefined4 EnsureVu1Code(VIFS * arg0, void * arg1, void * arg2); /* 0x15EAE0 EnsureVu1Code__FP4VIFSPvT1 */
undefined4 FinalizeFrameVifs(VIFS * arg0, int * arg1, QW * * arg2); /* 0x15EB20 FinalizeFrameVifs__FP4VIFSPiPP2QW */
undefined4 FinalizeFrameGifs(GIFS * arg0, int * arg1, QW * * arg2); /* 0x15EBF0 FinalizeFrameGifs__FP4GIFSPiPP2QW */
undefined4 CloseFrame(void); /* 0x15EC68 CloseFrame__Fv */
void * PrepareGsForFrameRender(FRM * arg0); /* 0x15ED50 PrepareGsForFrameRender__FP3FRM */
undefined4 check_anticrack_antigrab(void); /* 0x15EDB8 check_anticrack_antigrab__Fv */
undefined4 FrameRenderLoop(void * arg0); /* 0x15EE80 FrameRenderLoop__FPv */
undefined4 RenderFrame(FRM * arg0, int arg1); /* 0x15EF88 RenderFrame__FP3FRMi */
undefined4 ClearPendingFrame(FRM * arg0); /* 0x15EFE8 ClearPendingFrame__FP3FRM */
undefined4 FlushFrames(int arg0); /* 0x15F210 FlushFrames__Fi */
undefined4 BlendPrevFrame(void); /* 0x15F320 BlendPrevFrame__Fv */
undefined4 RemergeSwObject(SW * arg0, ALO * arg1); /* 0x15F678 RemergeSwObject__FP2SWP3ALO */
undefined4 MergeSwFreezeGroups(SW * arg0, ALO * arg1, ALO * arg2); /* 0x15F6C0 MergeSwFreezeGroups__FP2SWP3ALOT1 */
undefined4 SplinterSwFreezeGroup(SW * arg0, ALO * arg1); /* 0x15F710 SplinterSwFreezeGroup__FP2SWP3ALO */
undefined4 MergeSwGroup(SW * arg0, MRG * arg1); /* 0x15F7D8 MergeSwGroup__FP2SWP3MRG */
undefined4 AddSwMergeGroup(SW * arg0, MRG * arg1); /* 0x15F8B0 AddSwMergeGroup__FP2SWP3MRG */
undefined4 RemoveFromArray(int * arg0, void * * arg1, void * arg2); /* 0x15F930 RemoveFromArray__FPiPPvPv */
undefined4 RemoveSwMergeGroup(SW * arg0, MRG * arg1); /* 0x15F9A0 RemoveSwMergeGroup__FP2SWP3MRG */
undefined4 RemergeSwObjects(SW * arg0); /* 0x15FA58 RemergeSwObjects__FP2SW */
undefined4 FreezeAloHierarchy(ALO * arg0, int arg1); /* 0x15FB28 FreezeAloHierarchy__FP3ALOi */
undefined4 GetAloFrozen(ALO * arg0, int * arg1); /* 0x15FBA0 GetAloFrozen__FP3ALOPi */
undefined4 FreezeAlo(ALO * arg0, int arg1); /* 0x15FBB8 FreezeAlo__FP3ALOi */
undefined4 FreezeSo(SO * arg0, int arg1); /* 0x15FCD8 FreezeSo__FP2SOi */
undefined4 RefreezeSwObjects(SW * arg0); /* 0x15FD78 RefreezeSwObjects__FP2SW */
undefined4 UpdateSwBusyList(SW * arg0); /* 0x15FF58 UpdateSwBusyList__FP2SW */
void * PostFrzgLoad(FRZG * arg0); /* 0x15FF88 PostFrzgLoad__FP4FRZG */
undefined4 AddFrzgObject(FRZG * arg0, OID arg1); /* 0x160050 AddFrzgObject__FP4FRZG3OID */
undefined4 StartupGame(void); /* 0x160070 StartupGame__Fv */
undefined4 search_level_by_load_data(LevelLoadData * arg0); /* 0x1600A0 search_level_by_load_data__FP13LevelLoadData */
undefined4 search_level_by_id(WID arg0); /* 0x160110 search_level_by_id__F3WID */
void * PchzFriendlyFromWid(WID arg0); /* 0x160148 PchzFriendlyFromWid__F3WID */
undefined4 GetLevelCompletionById(WID arg0); /* 0x1601D8 GetLevelCompletionById__F3WID */
undefined4 get_game_completion(void); /* 0x1602A0 get_game_completion__Fv */
undefined4 UnlockIntroCutsceneFromWid(GAMEWORLD arg0); /* 0x160340 UnlockIntroCutsceneFromWid__F9GAMEWORLD */
undefined4 DefeatBossFromWorld(GAMEWORLD arg0); /* 0x1603E8 DefeatBossFromWorld__F9GAMEWORLD */
undefined4 InitGameState(GS * arg0); /* 0x1605E8 InitGameState__FP2GS */
undefined4 SetupGame(char * arg0, int arg1); /* 0x160690 SetupGame__FPci */
undefined4 UpdateGameState(float arg0); /* 0x1607D0 UpdateGameState__Ff */
undefined4 GrflsFromWid(WID arg0); /* 0x160850 GrflsFromWid__F3WID */
undefined4 UnloadGame(void); /* 0x160880 UnloadGame__Fv */
undefined4 RetryGame(void); /* 0x1608E0 RetryGame__Fv */
undefined4 StartGame(void); /* 0x160918 StartGame__Fv */
undefined4 CalculatePercentCompletion(GS * arg0); /* 0x160B28 CalculatePercentCompletion__FP2GS */
undefined4 SetCcharm(int arg0); /* 0x160C48 SetCcharm__Fi */
int FCharmAvailable(void); /* 0x160C58 FCharmAvailable__Fv */
void * PfLookupDialog(LS * arg0, OID arg1); /* 0x160CA0 PfLookupDialog__FP2LS3OID */
undefined4 OnGameLoad(GAME * arg0); /* 0x160CC8 OnGameLoad__FP4GAME */
undefined4 OnGameWorldTransition(GAME * arg0); /* 0x160CE8 OnGameWorldTransition__FP4GAME */
undefined4 OnGameAlarmTriggered(GAME * arg0); /* 0x160CF0 OnGameAlarmTriggered__FP4GAME */
undefined4 OnGameAlarmDisabled(GAME * arg0); /* 0x160D00 OnGameAlarmDisabled__FP4GAME */
undefined4 GetGrfvault_unknown(void); /* 0x160D10 GetGrfvault_unknown__Fv */
undefined4 GetBlueprintInfo(GRFVAULT * arg0); /* 0x160D30 GetBlueprintInfo__FP8GRFVAULT */
undefined4 CcharmMost(void); /* 0x160D98 CcharmMost__Fv */
undefined4 reload_post_death(void); /* 0x160DA0 reload_post_death__Fv */
undefined4 InitGeom(GEOM * arg0); /* 0x160E80 InitGeom__FP4GEOM */
undefined4 CloneGeom(GEOM * arg0, MATRIX4 * arg1, GEOM * arg2); /* 0x160EA0 CloneGeom__FP4GEOMP7MATRIX4T0 */
void GIFS_constructor(GIFS *this); /* 0x1611B8 __4GIFS */
undefined4 GIFS_AddPrimEnd(GIFS *this); /* 0x161200 AddPrimEnd__4GIFS */
undefined4 GIFS_EndPrim(GIFS *this, int arg1); /* 0x161278 EndPrim__4GIFSi */
undefined4 GIFS_CheckReg(GIFS *this, int arg1, int arg2); /* 0x1612E8 CheckReg__4GIFSii */
undefined4 GIFS_AddPrimBulk(GIFS *this, int arg1, int arg2, int arg3, unsigned long arg4, QW * * arg5); /* 0x1612F8 AddPrimBulk__4GIFSiiiUlPP2QW */
undefined4 GIFS_AddPrimPack(GIFS *this, int arg1, int arg2, unsigned long arg3); /* 0x1613C0 AddPrimPack__4GIFSiiUl */
void * GIFS_PackRGBA(GIFS *this, unsigned int arg1); /* 0x161458 PackRGBA__4GIFSUi */
void * GIFS_PackUV(GIFS *this, int arg1, int arg2); /* 0x1614C8 PackUV__4GIFSii */
void * GIFS_PackSTQ(GIFS *this, float arg1, float arg2, float arg3); /* 0x161520 PackSTQ__4GIFSfff */
void * GIFS_PackXYZ(GIFS *this, int arg1, int arg2, int arg3); /* 0x161588 PackXYZ__4GIFSiii */
void * GIFS_PackXYZF(GIFS *this, int arg1, int arg2, int arg3, int arg4); /* 0x1615F0 PackXYZF__4GIFSiiii */
void * GIFS_PackXYZFNoKick(GIFS *this, int arg1, int arg2, int arg3, int arg4); /* 0x161670 PackXYZFNoKick__4GIFSiiii */
void * GIFS_PackAD(GIFS *this, long arg1, long arg2); /* 0x161708 PackAD__4GIFSll */
undefined4 GIFS_AddPrimList(GIFS *this, int arg1, unsigned long arg2); /* 0x161768 AddPrimList__4GIFSiUl */
undefined4 GIFS_ListRGBAQ(GIFS *this, unsigned int arg1, float arg2); /* 0x1617E8 ListRGBAQ__4GIFSUif */
undefined4 GIFS_ListUV(GIFS *this, int arg1, int arg2); /* 0x161860 ListUV__4GIFSii */
undefined4 GIFS_ListXYZF(GIFS *this, int arg1, int arg2, int arg3, int arg4); /* 0x1618C0 ListXYZF__4GIFSiiii */
undefined4 GIFS_AddImage(GIFS *this, int arg1); /* 0x161958 AddImage__4GIFSi */
void GLBS_constructor(GLBS *this); /* 0x1619C0 __4GLBS */
void GLBS_destructor(GLBS *this); /* 0x161A88 _$_4GLBS */
undefined4 GLBS_SetTransform(GLBS *this, VECTOR * arg1, MATRIX3 * arg2); /* 0x161AB0 SetTransform__4GLBSP6VECTORP7MATRIX3 */
undefined4 GLBS_FindLights(GLBS *this, VECTOR * arg1, float arg2); /* 0x161B10 FindLights__4GLBSP6VECTORf */
undefined4 GLBS_ResetStrip(GLBS *this); /* 0x161B80 ResetStrip__4GLBS */
undefined4 GLBS_BeginStrip(GLBS *this, SHD * arg1); /* 0x161BB0 BeginStrip__4GLBSP3SHD */
undefined4 GLBS_DrawPrelit(GLBS *this); /* 0x161C00 DrawPrelit__4GLBS */
undefined4 GLBS_DrawThreeWay(GLBS *this); /* 0x161F70 DrawThreeWay__4GLBS */
undefined4 GLBS_EndStrip(GLBS *this); /* 0x162508 EndStrip__4GLBS */
undefined4 GLBS_SetNormal(GLBS *this, VECTOR * arg1); /* 0x162680 SetNormal__4GLBSP6VECTOR */
undefined4 GLBS_SetRgba(GLBS *this, RGBA arg1); /* 0x1626A8 SetRgba__4GLBSG4RGBA */
undefined4 GLBS_SetUv(GLBS *this, UVF * arg1); /* 0x1626C0 SetUv__4GLBSP3UVF */
undefined4 GLBS_AddVtx(GLBS *this, int arg1); /* 0x1626D8 AddVtx__4GLBSi */
undefined4 BuildGlobsetSaaArray(GLOBSET * arg0); /* 0x162810 BuildGlobsetSaaArray__FP7GLOBSET */
undefined4 LoadGlobsetFromBrx(GLOBSET * arg0, CBinaryInputStream * arg1, ALO * arg2); /* 0x162890 LoadGlobsetFromBrx__FP7GLOBSETP18CBinaryInputStreamP3ALO */
undefined4 EnsureBuffer(int arg0, VIFS * arg1); /* 0x163938 EnsureBuffer__FiP4VIFS */
undefined4 EnsureBufferCel(int arg0, VIFS * arg1); /* 0x163990 EnsureBufferCel__FiP4VIFS */
undefined4 BuildSubcel(GLOBSET * arg0, int arg1, SUBCEL * arg2, int arg3, VECTORF * arg4, int arg5, TWEF * arg6, SUBPOSEF * arg7, VECTORF * arg8, float * arg9, VIFS * arg10); /* 0x1639E8 BuildSubcel__FP7GLOBSETiP6SUBCELiP7VECTORFiP4TWEFP8SUBPOSEFT4PfP4VIFS */
undefined4 BuildSubglobSinglePass(GLOBSET * arg0, GLOB * arg1, int arg2, SUBGLOB * arg3, SHD * arg4, VECTORF * arg5, VECTORF * arg6, RGBA * arg7, UVF * arg8, int arg9, VTXF * arg10, SUBPOSEF * arg11, VECTORF * arg12, VECTORF * arg13, float * arg14, VIFS * arg15, SGVR * arg16); /* 0x163ED8 BuildSubglobSinglePass__FP7GLOBSETP4GLOBiP7SUBGLOBP3SHDP7VECTORFT5P4RGBAP3UVFiP4VTXFP8SUBPOSEFT5T5PfP4VIFSP4SGVR */
undefined4 BuildSubglobThreeWay(GLOBSET * arg0, GLOB * arg1, int arg2, SUBGLOB * arg3, SHD * arg4, VECTORF * arg5, VECTORF * arg6, RGBA * arg7, UVF * arg8, int arg9, VTXF * arg10, SUBPOSEF * arg11, VECTORF * arg12, VECTORF * arg13, float * arg14, VIFS * arg15, SGVR * arg16); /* 0x164868 BuildSubglobThreeWay__FP7GLOBSETP4GLOBiP7SUBGLOBP3SHDP7VECTORFT5P4RGBAP3UVFiP4VTXFP8SUBPOSEFT5T5PfP4VIFSP4SGVR */
undefined4 BuildSubglobLighting(GLOB * arg0, SUBGLOB * arg1, SUBGLOBI * arg2); /* 0x165588 BuildSubglobLighting__FP4GLOBP7SUBGLOBP8SUBGLOBI */
void * PostGlobsetLoad(GLOBSET * arg0, ALO * arg1); /* 0x165728 PostGlobsetLoad__FP7GLOBSETP3ALO */
undefined4 BindGlobset(GLOBSET * arg0, ALO * arg1); /* 0x165828 BindGlobset__FP7GLOBSETP3ALO */
undefined4 CloneGlobset(GLOBSET * arg0, ALO * arg1, GLOBSET * arg2); /* 0x165920 CloneGlobset__FP7GLOBSETP3ALOT0 */
undefined4 CloneGlob(GLOBSET * arg0, GLOB * arg1, GLOBI * arg2); /* 0x165AE8 CloneGlob__FP7GLOBSETP4GLOBP5GLOBI */
undefined4 UpdateGlobset(GLOBSET * arg0, ALO * arg1, float arg2); /* 0x165FE0 UpdateGlobset__FP7GLOBSETP3ALOf */
undefined4 UpdateAloConstraints(ALO * arg0); /* 0x1660A0 UpdateAloConstraints__FP3ALO */
undefined4 UpdateAloInfluences(ALO * arg0, RO * arg1); /* 0x1660E8 UpdateAloInfluences__FP3ALOP2RO */
void * PredrawGlob(GLOBSET * arg0, GLOB * arg1, GLOBI * arg2, ALO * arg3); /* 0x1662A8 PredrawGlob__FP7GLOBSETP4GLOBP5GLOBIP3ALO */
undefined4 RotateVu1Buffer(void); /* 0x166658 RotateVu1Buffer__Fv */
undefined4 DrawGlob(RPL * arg0); /* 0x166690 DrawGlob__FP3RPL */
undefined4 InitGomer(GOMER * arg0); /* 0x167D68 InitGomer__FP5GOMER */
void * PostGomerLoad(GOMER * arg0); /* 0x167E08 PostGomerLoad__FP5GOMER */
undefined4 RenderGomerSelf(GOMER * arg0, CM * arg1, RO * arg2); /* 0x167EF0 RenderGomerSelf__FP5GOMERP2CMP2RO */
int FDetectGomer(GOMER * arg0); /* 0x167F10 FDetectGomer__FP5GOMER */
undefined4 BlendDisplayOnBufferMismatch(void); /* 0x168130 BlendDisplayOnBufferMismatch__Fv */
undefined4 VBlankS_Interrupt(int arg0); /* 0x1682C0 VBlankS_Interrupt__Fi */
undefined4 SyncVBlank(void); /* 0x1683B8 SyncVBlank__Fv */
undefined4 SwapGsBuffers(void); /* 0x1683E8 SwapGsBuffers__Fv */
undefined4 RestoreGsBuffers(void); /* 0x1684E8 RestoreGsBuffers__Fv */
float GS_Interrupt(int arg0); /* 0x1685B8 GS_Interrupt__Fi */
undefined4 ResetGs(void); /* 0x168698 ResetGs__Fv */
undefined4 SendDmaSyncGsFinish(sceDmaChan * arg0, QW * arg1); /* 0x1686E8 SendDmaSyncGsFinish__FP10sceDmaChanP2QW */
undefined4 BuildClearGifs(QW * arg0, RGBA arg1, int arg2); /* 0x168770 BuildClearGifs__FP2QWG4RGBAi */
undefined4 StartupGs(void); /* 0x1688B8 StartupGs__Fv */
undefined4 BlastAqwGifsBothFrames(QW * arg0); /* 0x168A48 BlastAqwGifsBothFrames__FP2QW */
undefined4 ClearFrameBuffers(void); /* 0x168AF8 ClearFrameBuffers__Fv */
undefined4 FadeFramesToBlack(float arg0); /* 0x168B68 FadeFramesToBlack__Ff */
undefined4 ResetGsMemory(void); /* 0x168D00 ResetGsMemory__Fv */
undefined4 NLog2(unsigned int arg0); /* 0x168D30 NLog2__FUi */
undefined4 InitGsb(GSB * arg0, int arg1, int arg2); /* 0x168D68 InitGsb__FP3GSBii */
undefined4 ResetGsb(GSB * arg0); /* 0x168D78 ResetGsb__FP3GSB */
undefined4 IgsAllocGsb(GSB * arg0, int arg1); /* 0x168D88 IgsAllocGsb__FP3GSBi */
undefined4 BuildImageGifs(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, GIFS * arg6); /* 0x168D98 BuildImageGifs__FiiiiiiP4GIFS */
undefined4 BuildClutTex2(CLUT * arg0, int arg1); /* 0x168E78 BuildClutTex2__FP4CLUTi */
undefined4 BuildClutGifs(CLUT * arg0, int arg1, GIFS * arg2); /* 0x168F48 BuildClutGifs__FP4CLUTiP4GIFS */
undefined4 BuildBmpTex0(BMP * arg0, int arg1); /* 0x168FB0 BuildBmpTex0__FP3BMPi */
undefined4 BuildBmpGifs(BMP * arg0, int arg1, GIFS * arg2); /* 0x169088 BuildBmpGifs__FP3BMPiP4GIFS */
int FBuildUploadBitmapGifs(int arg0, GSB * arg1, GIFS * arg2); /* 0x1690C0 FBuildUploadBitmapGifs__FiP3GSBP4GIFS */
undefined4 UploadBitmaps(int arg0, GSB * arg1); /* 0x1692B0 UploadBitmaps__FiP3GSB */
void * PqwGifsBitmapUpload(int arg0); /* 0x1693A8 PqwGifsBitmapUpload__Fi */
undefined4 PropagateSur(SUR * arg0); /* 0x1694A0 PropagateSur__FP3SUR */
undefined4 ReferenceShaderAqwRegs(SHD * arg0, SHDP * arg1, QW * arg2, int arg3, int arg4, SAI * arg5); /* 0x1694F8 ReferenceShaderAqwRegs__FP3SHDP4SHDPP2QWiiP3SAI */
undefined4 ReferenceUVAnimation(QW * arg0, int arg1, SAI * arg2); /* 0x169608 ReferenceUVAnimation__FP2QWiP3SAI */
undefined4 RebaseSurs(int arg0, int arg1, void * arg2, void * arg3); /* 0x1696B8 RebaseSurs__FiiPvT2 */
undefined4 PropagateSurs(void); /* 0x169718 PropagateSurs__Fv */
void * PqwVifsBitmapUpload(int arg0); /* 0x169780 PqwVifsBitmapUpload__Fi */
undefined4 DrawOnBitmap(BMP * arg0, GIFS * arg1); /* 0x169B18 DrawOnBitmap__FP3BMPP4GIFS */
undefined4 StartupHide(void); /* 0x169C58 StartupHide__Fv */
undefined4 ResetHideList(void); /* 0x169CA0 ResetHideList__Fv */
undefined4 InitHshape(HSHAPE * arg0); /* 0x169CD8 InitHshape__FP6HSHAPE */
undefined4 OnHshapeAdd(HSHAPE * arg0); /* 0x169D20 OnHshapeAdd__FP6HSHAPE */
undefined4 OnHshapeRemove(HSHAPE * arg0); /* 0x169D58 OnHshapeRemove__FP6HSHAPE */
undefined4 BindHshape(HSHAPE * arg0); /* 0x169D90 BindHshape__FP6HSHAPE */
undefined4 CloneHshape(HSHAPE * arg0, HSHAPE * arg1); /* 0x169DD8 CloneHshape__FP6HSHAPET0 */
undefined4 GetHshapeHidePos(HSHAPE * arg0, float arg1, VECTOR * arg2, float * arg3); /* 0x169E20 GetHshapeHidePos__FP6HSHAPEfP6VECTORPf */
undefined4 GetHshapeClosestHidePos(HSHAPE * arg0, float * arg1, VECTOR * arg2, float * arg3); /* 0x169FC0 GetHshapeClosestHidePos__FP6HSHAPEPfP6VECTORT1 */
undefined4 InitHpnt(HPNT * arg0); /* 0x16A100 InitHpnt__FP4HPNT */
undefined4 OnHpntAdd(HPNT * arg0); /* 0x16A140 OnHpntAdd__FP4HPNT */
undefined4 OnHpntRemove(HPNT * arg0); /* 0x16A178 OnHpntRemove__FP4HPNT */
undefined4 BindHpnt(HPNT * arg0); /* 0x16A1B0 BindHpnt__FP4HPNT */
undefined4 CloneHpnt(HPNT * arg0, HPNT * arg1); /* 0x16A1F8 CloneHpnt__FP4HPNTT0 */
undefined4 GetHpntClosestHidePos(HPNT * arg0, VECTOR * arg1, float * arg2); /* 0x16A240 GetHpntClosestHidePos__FP4HPNTP6VECTORPf */
undefined4 InitHbsk(HBSK * arg0); /* 0x16A3A8 InitHbsk__FP4HBSK */
undefined4 LoadHbskFromBrx(HBSK * arg0, CBinaryInputStream * arg1); /* 0x16A420 LoadHbskFromBrx__FP4HBSKP18CBinaryInputStream */
undefined4 OnHbskAdd(HBSK * arg0); /* 0x16A490 OnHbskAdd__FP4HBSK */
undefined4 OnHbskRemove(HBSK * arg0); /* 0x16A4C8 OnHbskRemove__FP4HBSK */
undefined4 CloneHbsk(HBSK * arg0, HBSK * arg1); /* 0x16A500 CloneHbsk__FP4HBSKT0 */
int FIgnoreHbskIntersection(HBSK * arg0, SO * arg1); /* 0x16A548 FIgnoreHbskIntersection__FP4HBSKP2SO */
void * PresetHbskAccel(HBSK * arg0, float arg1); /* 0x16A580 PresetHbskAccel__FP4HBSKf */
undefined4 SetHbskHbsks(HBSK * arg0, HBSKS arg1); /* 0x16A5F0 SetHbskHbsks__FP4HBSK5HBSKS */
undefined4 CdartStuckHbsk(HBSK * arg0); /* 0x16A758 CdartStuckHbsk__FP4HBSK */
void * PdartOldestHbskStuck(HBSK * arg0); /* 0x16A820 PdartOldestHbskStuck__FP4HBSK */
undefined4 GetHbskClosestHidePos(HBSK * arg0, VECTOR * arg1, float * arg2); /* 0x16A910 GetHbskClosestHidePos__FP4HBSKP6VECTORPf */
undefined4 InitHnd(HND * arg0); /* 0x16C470 InitHnd__FP3HND */
undefined4 LoadHndFromBrx(HND * arg0, CBinaryInputStream * arg1); /* 0x16C4B8 LoadHndFromBrx__FP3HNDP18CBinaryInputStream */
undefined4 RenderIkhSelf(IKH * arg0, CM * arg1, RO * arg2); /* 0x16C4E8 RenderIkhSelf__FP3IKHP2CMP2RO */
undefined4 RenderLikhSelf(LIKH * arg0, CM * arg1, RO * arg2); /* 0x16C508 RenderLikhSelf__FP4LIKHP2CMP2RO */
undefined4 SolveAloIK(ALO * arg0); /* 0x16C528 SolveAloIK__FP3ALO */
undefined4 InitJlo(JLO * arg0); /* 0x16CE00 InitJlo__FP3JLO */
undefined4 LoadJloFromBrx(JLO * arg0, CBinaryInputStream * arg1); /* 0x16CE80 LoadJloFromBrx__FP3JLOP18CBinaryInputStream */
void * PostJloLoad(JLO * arg0); /* 0x16CF70 PostJloLoad__FP3JLO */
void * PresetJloAccel(JLO * arg0, float arg1); /* 0x16D0C0 PresetJloAccel__FP3JLOf */
undefined4 UpdateJlo(JLO * arg0, float arg1); /* 0x16D128 UpdateJlo__FP3JLOf */
undefined4 JlosNextJlo(JLO * arg0); /* 0x16D1E0 JlosNextJlo__FP3JLO */
undefined4 SetJloJlovol(JLO * arg0, JLOVOL * arg1); /* 0x16D3F0 SetJloJlovol__FP3JLOP6JLOVOL */
undefined4 FireJlo(JLO * arg0); /* 0x16D490 FireJlo__FP3JLO */
undefined4 LandJlo(JLO * arg0); /* 0x16D788 LandJlo__FP3JLO */
undefined4 JumpJlo(JLO * arg0); /* 0x16D828 JumpJlo__FP3JLO */
undefined4 HandleJloMessage(JLO * arg0, MSGID arg1, void * arg2); /* 0x16DA00 HandleJloMessage__FP3JLO5MSGIDPv */
undefined4 SetJloJlos(JLO * arg0, JLOS arg1); /* 0x16DAC0 SetJloJlos__FP3JLO4JLOS */
undefined4 ActivateJlo(JLO * arg0); /* 0x16DCF0 ActivateJlo__FP3JLO */
undefined4 DeactivateJlo(JLO * arg0); /* 0x16DD00 DeactivateJlo__FP3JLO */
undefined4 InitJloc(JLOC * arg0); /* 0x16DD10 InitJloc__FP4JLOC */
undefined4 LoadJlocFromBrx(JLOC * arg0, CBinaryInputStream * arg1); /* 0x16DD90 LoadJlocFromBrx__FP4JLOCP18CBinaryInputStream */
void * PostJlocLoad(JLOC * arg0); /* 0x16DDE8 PostJlocLoad__FP4JLOC */
void * PxfmChooseJloc(JLOC * arg0); /* 0x16DE20 PxfmChooseJloc__FP4JLOC */
undefined4 InitJlovol(JLOVOL * arg0); /* 0x16DF30 InitJlovol__FP6JLOVOL */
undefined4 BindJlovol(JLOVOL * arg0); /* 0x16DF68 BindJlovol__FP6JLOVOL */
undefined4 HandleJlovolMessage(JLOVOL * arg0, MSGID arg1, void * arg2); /* 0x16DFE0 HandleJlovolMessage__FP6JLOVOL5MSGIDPv */
undefined4 StartupJoy(void); /* 0x16E0B8 StartupJoy__Fv */
undefined4 AddGrfusr(int arg0); /* 0x16E0F0 AddGrfusr__Fi */
undefined4 RemoveGrfusr(int arg0); /* 0x16E118 RemoveGrfusr__Fi */
undefined4 UpdateGrfjoytFromGrfusr(void); /* 0x16E148 UpdateGrfjoytFromGrfusr__Fv */
undefined4 InitJoy(JOY * arg0, int arg1, int arg2); /* 0x16E1A0 InitJoy__FP3JOYii */
undefined4 UpdateJoy(JOY * arg0); /* 0x16E238 UpdateJoy__FP3JOY */
undefined4 SetJoyJoys(JOY * arg0, JOYS arg1, JOYK arg2); /* 0x16E630 SetJoyJoys__FP3JOY4JOYS4JOYK */
undefined4 GetJoyXYDeflection(JOY * arg0, unsigned char arg1, unsigned char arg2, float * arg3, float * arg4, float * arg5, unsigned char * arg6, unsigned char * arg7, int * arg8, LM * arg9); /* 0x16E738 GetJoyXYDeflection__FP3JOYUcUcPfN23PUcT6PiP2LM */
int FReadJoy(JOY * arg0); /* 0x16E940 FReadJoy__FP3JOY */
undefined4 SetJoyBtnHandled(JOY * arg0, unsigned short arg1); /* 0x16EC20 SetJoyBtnHandled__FP3JOYUs */
undefined4 TriggerJoyRumbleRumk(JOY * arg0, RUMK arg1, float arg2); /* 0x16EC38 TriggerJoyRumbleRumk__FP3JOY4RUMKf */
undefined4 StartJoySelection(JOY * arg0); /* 0x16EC88 StartJoySelection__FP3JOY */
undefined4 DxSelectionJoy(JOY * arg0); /* 0x16EC98 DxSelectionJoy__FP3JOY */
undefined4 DySelectionJoy(JOY * arg0); /* 0x16EED0 DySelectionJoy__FP3JOY */
undefined4 UBtnpJoy(JOY * arg0, BTNP arg1); /* 0x16F108 UBtnpJoy__FP3JOY4BTNP */
undefined4 AddCode(CODE * arg0); /* 0x16F188 AddCode__FP4CODE */
undefined4 _ResetCodes(void); /* 0x16F1F8 _ResetCodes__Fv */
undefined4 _MatchCodes(JOY * arg0, unsigned short arg1); /* 0x16F238 _MatchCodes__FP3JOYUs */
undefined4 UpdateCodes(void); /* 0x16F2E0 UpdateCodes__Fv */
undefined4 ClearFchts(void); /* 0x16F408 ClearFchts__Fv */
undefined4 AddFcht(int arg0); /* 0x16F430 AddFcht__Fi */
undefined4 Chetkido(void); /* 0x16F478 Chetkido__Fv */
undefined4 StartupCodes(void); /* 0x16F588 StartupCodes__Fv */
undefined4 InitJt(JT * arg0); /* 0x16F608 InitJt__FP2JT */
undefined4 LoadJtFromBrx(JT * arg0, CBinaryInputStream * arg1); /* 0x16F7B0 LoadJtFromBrx__FP2JTP18CBinaryInputStream */
void * PostJtLoad(JT * arg0); /* 0x16F810 PostJtLoad__FP2JT */
void * PresetJtAccel(JT * arg0, float arg1); /* 0x1701B0 PresetJtAccel__FP2JTf */
undefined4 AdjustJtNewXp(JT * arg0, XP * arg1, int arg2); /* 0x170410 AdjustJtNewXp__FP2JTP2XPi */
undefined4 AdjustJtDz(JT * arg0, int arg1, DZ * arg2, int arg3, float arg4); /* 0x170528 AdjustJtDz__FP2JTiP2DZif */
undefined4 UpdateJtInternalXps(JT * arg0); /* 0x170660 UpdateJtInternalXps__FP2JT */
int FCheckJtXpBase(JT * arg0, XP * arg1, int arg2); /* 0x170790 FCheckJtXpBase__FP2JTP2XPi */
undefined4 AdjustJtXpVelocity(JT * arg0, XP * arg1, int arg2); /* 0x170820 AdjustJtXpVelocity__FP2JTP2XPi */
undefined4 HandleJtMessage(JT * arg0, MSGID arg1, void * arg2); /* 0x170960 HandleJtMessage__FP2JT5MSGIDPv */
int FTurnJtToTarget(JT * arg0); /* 0x171180 FTurnJtToTarget__FP2JT */
undefined4 UpdateJtBalance(JT * arg0); /* 0x171238 UpdateJtBalance__FP2JT */
undefined4 RebuildJtXmg(JT * arg0, ALO * arg1, float arg2, ALO * arg3, ACTADJ * arg4, XMG * arg5); /* 0x1719E8 RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG */
int FMatchJtXmg(JT * arg0, XMG * arg1, ACTADJ * arg2); /* 0x171C80 FMatchJtXmg__FP2JTP3XMGP6ACTADJ */
undefined4 UpdateJtStand(JT * arg0); /* 0x171DD8 UpdateJtStand__FP2JT */
undefined4 ThrowJt(JT * arg0, VECTOR * arg1, float arg2, float arg3); /* 0x171F28 ThrowJt__FP2JTP6VECTORff */
undefined4 UnhookJt(JT * arg0); /* 0x171FE0 UnhookJt__FP2JT */
undefined4 CalculateJtToolSpin(JT * arg0, float arg1, MATRIX3 * arg2); /* 0x172078 CalculateJtToolSpin__FP2JTfP7MATRIX3 */
undefined4 RenderJtAll(JT * arg0, CM * arg1, RO * arg2); /* 0x1721B0 RenderJtAll__FP2JTP2CMP2RO */
undefined4 UpdateJtTool(JT * arg0); /* 0x1727B0 UpdateJtTool__FP2JT */
undefined4 UpdateJtPosWorldPrev(JT * arg0); /* 0x172AE0 UpdateJtPosWorldPrev__FP2JT */
undefined4 UpdateJtBounds(JT * arg0); /* 0x172B88 UpdateJtBounds__FP2JT */
void * PsoGetJtEffect(JT * arg0, int * arg1); /* 0x172BF8 PsoGetJtEffect__FP2JTPi */
undefined4 AddJtCustomXps(JT * arg0, SO * arg1, int arg2, BSP * arg3, BSP * arg4, XP * * arg5); /* 0x172CF0 AddJtCustomXps__FP2JTP2SOiP3BSPT3PP2XP */
undefined4 CtTorqueJt(JT * arg0); /* 0x172EB8 CtTorqueJt__FP2JT */
undefined4 GetJtCpdefiFlatten(JT * arg0, CPDEFI * arg1); /* 0x1733B8 GetJtCpdefiFlatten__FP2JTP6CPDEFI */
undefined4 UpdateJtActive(JT * arg0, JOY * arg1, float arg2); /* 0x173888 UpdateJtActive__FP2JTP3JOYf */
undefined4 UpdateJt(JT * arg0, float arg1); /* 0x174808 UpdateJt__FP2JTf */
undefined4 UpdateJtDrive(JT * arg0); /* 0x174E20 UpdateJtDrive__FP2JT */
undefined4 ChooseJtPhys(JT * arg0); /* 0x174F50 ChooseJtPhys__FP2JT */
undefined4 EnableJtActadj(JT * arg0, int arg1); /* 0x175078 EnableJtActadj__FP2JTi */
undefined4 SetJtJts(JT * arg0, JTS arg1, JTBS arg2); /* 0x175170 SetJtJts__FP2JT3JTS4JTBS */
void * ProfileJt(JT * arg0, int arg1); /* 0x1777F8 ProfileJt__FP2JTi */
undefined4 SetJtPuppet(JT * arg0, ASEGA * arg1); /* 0x177800 SetJtPuppet__FP2JTP5ASEGA */
void * PaloAbsorbWkr(WKR * arg0, int arg1, ALO * * arg2); /* 0x177838 PaloAbsorbWkr__FP3WKRiPP3ALO */
undefined4 NCmpWkr(WKR * arg0, WKR * arg1); /* 0x177968 NCmpWkr__FP3WKRT0 */
undefined4 UpdateJtEffect(JT * arg0); /* 0x177990 UpdateJtEffect__FP2JT */
int FIsJtSoundBase(JT * arg0); /* 0x177E20 FIsJtSoundBase__FP2JT */
undefined4 CollectJtPrize(JT * arg0, PCK arg1, ALO * arg2); /* 0x177E70 CollectJtPrize__FP2JT3PCKP3ALO */
undefined4 GetJtDiapi(JT * arg0, DIALOG * arg1, DIAPI * arg2); /* 0x177EE0 GetJtDiapi__FP2JTP6DIALOGP5DIAPI */
void * PlayJtDialog(JT * arg0, DIALOG * arg1); /* 0x177F98 PlayJtDialog__FP2JTP6DIALOG */
undefined4 InitJsg(JSG * arg0); /* 0x17B998 InitJsg__FP3JSG */
undefined4 GetJsgLocation(JSG * arg0, LO * arg1, VECTOR * arg2, float * arg3); /* 0x17B9D0 GetJsgLocation__FP3JSGP2LOP6VECTORPf */
undefined4 SetJsgFocus(JSG * arg0, LO * arg1); /* 0x17BB78 SetJsgFocus__FP3JSGP2LO */
undefined4 SetJsgTn(JSG * arg0, TN * arg1); /* 0x17BC20 SetJsgTn__FP3JSGP2TN */
undefined4 NextJsgJsge(JSG * arg0); /* 0x17BCD0 NextJsgJsge__FP3JSG */
int FIsJsgJsgeComplete(JSG * arg0, JSGE * arg1); /* 0x17C428 FIsJsgJsgeComplete__FP3JSGP4JSGE */
undefined4 UpdateJsgJsge(JSG * arg0); /* 0x17C660 UpdateJsgJsge__FP3JSG */
undefined4 ReadJsgJoystick(JSG * arg0, JOY * arg1); /* 0x17C718 ReadJsgJoystick__FP3JSGP3JOY */
int FIsJsgActive(JSG * arg0); /* 0x17CDA8 FIsJsgActive__FP3JSG */
undefined4 ClearJsg(JSG * arg0); /* 0x17CDE0 ClearJsg__FP3JSG */
undefined4 ApplyJsg(JSG * arg0, JT * arg1); /* 0x17CE20 ApplyJsg__FP3JSGP2JT */
undefined4 RetractJsg(JSG * arg0); /* 0x17CE80 RetractJsg__FP3JSG */
void * PjsgeAllocJsg(JSG * arg0, JSGEK arg1, OID arg2, int arg3); /* 0x17CF38 PjsgeAllocJsg__FP3JSG5JSGEK3OIDi */
undefined4 AddJsgContext(JSG * arg0, OID arg1); /* 0x17CFC8 AddJsgContext__FP3JSG3OID */
undefined4 AddJsgCut(JSG * arg0, OID arg1); /* 0x17CFF0 AddJsgCut__FP3JSG3OID */
undefined4 AddJsgFocus(JSG * arg0, OID arg1); /* 0x17D018 AddJsgFocus__FP3JSG3OID */
undefined4 AddJsgLabel(JSG * arg0, OID arg1); /* 0x17D040 AddJsgLabel__FP3JSG3OID */
undefined4 AddJsgTunnel(JSG * arg0, OID arg1); /* 0x17D078 AddJsgTunnel__FP3JSG3OID */
undefined4 AddJsgPause(JSG * arg0, OID arg1, float arg2); /* 0x17D0A0 AddJsgPause__FP3JSG3OIDf */
undefined4 AddJsgAseg(JSG * arg0, OID arg1, int arg2); /* 0x17D0D8 AddJsgAseg__FP3JSG3OIDi */
undefined4 AddJsgJump(JSG * arg0, OID arg1, JSGJK arg2, JSGLK arg3, int arg4); /* 0x17D100 AddJsgJump__FP3JSG3OID5JSGJK5JSGLKi */
undefined4 AddJsgRun(JSG * arg0, OID arg1, float arg2, int arg3); /* 0x17D148 AddJsgRun__FP3JSG3OIDfi */
undefined4 AddJsgClimb(JSG * arg0, OID arg1, float arg2, int arg3); /* 0x17D180 AddJsgClimb__FP3JSG3OIDfi */
undefined4 AddJsgAttack(JSG * arg0, OID arg1, FTAK arg2, int arg3); /* 0x17D1B8 AddJsgAttack__FP3JSG3OID4FTAKi */
undefined4 AddJsgClock(JSG * arg0, float arg1); /* 0x17D1E8 AddJsgClock__FP3JSGf */
undefined4 AddJsgUnknown(JSG * arg0); /* 0x17D220 AddJsgUnknown__FP3JSG */
void * PresetJtAccelJump(JT * arg0); /* 0x17D248 PresetJtAccelJump__FP2JT */
undefined4 UpdateJtActiveJump(JT * arg0, JOY * arg1); /* 0x17D5D8 UpdateJtActiveJump__FP2JTP3JOY */
int FCheckJtSingleEdge(JT * arg0, SO * arg1, EDGE * arg2, VECTOR * arg3); /* 0x17DCE0 FCheckJtSingleEdge__FP2JTP2SOP4EDGEP6VECTOR */
int FCheckJtEdgeNormal(JT * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x17DE88 FCheckJtEdgeNormal__FP2JTP6VECTORT1 */
int FCheckJtEdgeGrab(JT * arg0, SO * arg1, VECTOR * arg2, XPK arg3, void * arg4, VECTOR * arg5); /* 0x17E088 FCheckJtEdgeGrab__FP2JTP2SOP6VECTOR3XPKPvT2 */
void * PxpFindJtBestEdge(JT * arg0, int * arg1, VECTOR * arg2); /* 0x17E3C8 PxpFindJtBestEdge__FP2JTPiP6VECTOR */
undefined4 JtsResetJt(JT * arg0); /* 0x17E6D0 JtsResetJt__FP2JT */
undefined4 HandleJtDiveEffect(JT * arg0); /* 0x17E710 HandleJtDiveEffect__FP2JT */
undefined4 UpdateJtJump(JT * arg0); /* 0x17F018 UpdateJtJump__FP2JT */
int FTimeJtJumpToTarget(JT * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4, float * arg5); /* 0x17FAC0 FTimeJtJumpToTarget__FP2JTP6VECTORN31Pf */
undefined4 GetJtJumpVelocity(JT * arg0, VECTOR * arg1); /* 0x17FB78 GetJtJumpVelocity__FP2JTP6VECTOR */
undefined4 GetJtJumpToTargetVelocity(JT * arg0, VECTOR * arg1); /* 0x17FC48 GetJtJumpToTargetVelocity__FP2JTP6VECTOR */
undefined4 GetJtJumpBoostVelocity(JT * arg0, VECTOR * arg1); /* 0x17FCC8 GetJtJumpBoostVelocity__FP2JTP6VECTOR */
undefined4 StartupJmt(void); /* 0x17FD48 StartupJmt__Fv */
undefined4 ResetJmtList(void); /* 0x17FD70 ResetJmtList__Fv */
undefined4 OnJmtAdd(JMT * arg0); /* 0x17FD90 OnJmtAdd__FP3JMT */
undefined4 OnJmtRemove(JMT * arg0); /* 0x17FDC8 OnJmtRemove__FP3JMT */
undefined4 CloneJmt(JMT * arg0, JMT * arg1); /* 0x17FE00 CloneJmt__FP3JMTT0 */
void * PostJmtLoad(JMT * arg0); /* 0x17FE48 PostJmtLoad__FP3JMT */
undefined4 InitKeyhole(KEYHOLE * arg0); /* 0x17FE90 InitKeyhole__FP7KEYHOLE */
undefined4 LoadKeyholeFromBrx(KEYHOLE * arg0, CBinaryInputStream * arg1); /* 0x17FEC0 LoadKeyholeFromBrx__FP7KEYHOLEP18CBinaryInputStream */
undefined4 DrawKeyholeMask(KEYHOLE * arg0, float arg1, float arg2, float arg3, float arg4); /* 0x180108 DrawKeyholeMask__FP7KEYHOLEffff */
undefined4 DrawKeyhole(KEYHOLE * arg0, float arg1); /* 0x180398 DrawKeyhole__FP7KEYHOLEf */
undefined4 _GLOBAL_$I$InitKeyhole(KEYHOLE * arg0); /* 0x180E90 _GLOBAL_$I$InitKeyhole__FP7KEYHOLE */
undefined4 OnLandingAdd(LANDING * arg0); /* 0x180EB0 OnLandingAdd__FP7LANDING */
undefined4 OnLandingRemove(LANDING * arg0); /* 0x180EE8 OnLandingRemove__FP7LANDING */
undefined4 CloneLanding(LANDING * arg0, LANDING * arg1); /* 0x180F20 CloneLanding__FP7LANDINGT0 */
undefined4 InitLgn(LGN * arg0); /* 0x180F68 InitLgn__FP3LGN */
void * PostLgnLoad(LGN * arg0); /* 0x180F98 PostLgnLoad__FP3LGN */
undefined4 UpdateLgnActive(LGN * arg0, JOY * arg1, float arg2); /* 0x181078 UpdateLgnActive__FP3LGNP3JOYf */
undefined4 UpdateLgn(LGN * arg0, float arg1); /* 0x181448 UpdateLgn__FP3LGNf */
undefined4 OnLgnActive(LGN * arg0, int arg1, PO * arg2); /* 0x181780 OnLgnActive__FP3LGNiP2PO */
undefined4 RenderLgnAll(LGN * arg0, CM * arg1, RO * arg2); /* 0x181818 RenderLgnAll__FP3LGNP2CMP2RO */
undefined4 GetLgnCpdefi(LGN * arg0, float arg1, CPDEFI * arg2); /* 0x181A58 GetLgnCpdefi__FP3LGNfP6CPDEFI */
int FInvulnerableLgn(LGN * arg0, ZPK arg1); /* 0x181A98 FInvulnerableLgn__FP3LGN3ZPK */
undefined4 JthsCurrentLgn(LGN * arg0); /* 0x181AE0 JthsCurrentLgn__FP3LGN */
undefined4 UseLgnCharm(LGN * arg0); /* 0x181AF0 UseLgnCharm__FP3LGN */
undefined4 ApplyLgnThrow(LGN * arg0, PO * arg1); /* 0x181B20 ApplyLgnThrow__FP3LGNP2PO */
int FTakeLgnDamage(LGN * arg0, ZPR * arg1); /* 0x181BC8 FTakeLgnDamage__FP3LGNP3ZPR */
undefined4 HandleLgnMessage(LGN * arg0, MSGID arg1, void * arg2); /* 0x181D28 HandleLgnMessage__FP3LGN5MSGIDPv */
undefined4 SetLgnLgns(LGN * arg0, LGNS arg1); /* 0x181DA8 SetLgnLgns__FP3LGN4LGNS */
undefined4 UpdateLgnrAim(LGNR * arg0, JOY * arg1); /* 0x181ED0 UpdateLgnrAim__FP4LGNRP3JOY */
undefined4 DrawLgnr(LGNR * arg0); /* 0x1821B0 DrawLgnr__FP4LGNR */
undefined4 InitSwp(SWP * arg0); /* 0x182470 InitSwp__FP3SWP */
void * PostSwpLoad(SWP * arg0); /* 0x1824D8 PostSwpLoad__FP3SWP */
undefined4 UpdateSwp(SWP * arg0, float arg1); /* 0x182548 UpdateSwp__FP3SWPf */
void * ProjectSwpTransform(SWP * arg0, float arg1, int arg2); /* 0x182748 ProjectSwpTransform__FP3SWPfi */
undefined4 SetSwpShape(SWP * arg0, SHAPE * arg1, float arg2); /* 0x182948 SetSwpShape__FP3SWPP5SHAPEf */
undefined4 InitLo(LO * arg0); /* 0x182C18 InitLo__FP2LO */
void * PostLoLoad(LO * arg0); /* 0x182C58 PostLoLoad__FP2LO */
undefined4 AddLo(LO * arg0); /* 0x182C80 AddLo__FP2LO */
undefined4 AddLoHierarchy(LO * arg0); /* 0x182D00 AddLoHierarchy__FP2LO */
undefined4 OnLoAdd(LO * arg0); /* 0x182D48 OnLoAdd__FP2LO */
undefined4 RemoveLo(LO * arg0); /* 0x182D50 RemoveLo__FP2LO */
undefined4 DeferLoRemove(LO * arg0); /* 0x182DD8 DeferLoRemove__FP2LO */
undefined4 SetLoSuckHideLimits(LO * arg0, LM * arg1); /* 0x182E40 SetLoSuckHideLimits__FP2LOP2LM */
undefined4 RemoveLoHierarchy(LO * arg0); /* 0x182E88 RemoveLoHierarchy__FP2LO */
undefined4 OnLoRemove(LO * arg0); /* 0x182ED0 OnLoRemove__FP2LO */
undefined4 SnipLo(LO * arg0); /* 0x182ED8 SnipLo__FP2LO */
int FFindLoParent(LO * arg0, ALO * arg1); /* 0x182F40 FFindLoParent__FP2LOP3ALO */
undefined4 SetLoParent(LO * arg0, ALO * arg1); /* 0x182F78 SetLoParent__FP2LOP3ALO */
int FIsLoInWorld(LO * arg0); /* 0x182FC8 FIsLoInWorld__FP2LO */
undefined4 GetLoInWorld(LO * arg0, int * arg1); /* 0x183028 GetLoInWorld__FP2LOPi */
void * PloCloneLo(LO * arg0, SW * arg1, ALO * arg2); /* 0x183058 PloCloneLo__FP2LOP2SWP3ALO */
undefined4 CloneLoHierarchy(LO * arg0, LO * arg1); /* 0x1830B0 CloneLoHierarchy__FP2LOT0 */
undefined4 CloneLo(LO * arg0, LO * arg1); /* 0x1830D8 CloneLo__FP2LOT0 */
undefined4 SubscribeSwPpmqStruct(SW * arg0, MQ * * arg1, void (*arg2)(void *, MSGID, void *), void * arg3); /* 0x1831E8 SubscribeSwPpmqStruct__FP2SWPP2MQPFPv5MSGIDPv_vPv */
undefined4 UnsubscribeSwPpmqStruct(SW * arg0, MQ * * arg1, void (*arg2)(void *, MSGID, void *), void * arg3); /* 0x183238 UnsubscribeSwPpmqStruct__FP2SWPP2MQPFPv5MSGIDPv_vPv */
undefined4 SubscribeLoStruct(LO * arg0, void (*arg1)(void *, MSGID, void *), void * arg2); /* 0x183290 SubscribeLoStruct__FP2LOPFPv5MSGIDPv_vPv */
undefined4 UnsubscribeLoStruct(LO * arg0, void (*arg1)(void *, MSGID, void *), void * arg2); /* 0x1832C0 UnsubscribeLoStruct__FP2LOPFPv5MSGIDPv_vPv */
undefined4 SubscribeLoObject(LO * arg0, LO * arg1); /* 0x1832F0 SubscribeLoObject__FP2LOT0 */
undefined4 UnsubscribeLoObject(LO * arg0, LO * arg1); /* 0x183320 UnsubscribeLoObject__FP2LOT0 */
undefined4 SendLoMessage(LO * arg0, MSGID arg1, void * arg2); /* 0x183350 SendLoMessage__FP2LO5MSGIDPv */
undefined4 LoadLoFromBrx(LO * arg0, CBinaryInputStream * arg1); /* 0x1833D0 LoadLoFromBrx__FP2LOP18CBinaryInputStream */
int FMatchesLoName(LO * arg0, OID arg1); /* 0x1833F0 FMatchesLoName__FP2LO3OID */
undefined4 OidProxyLo(LO * arg0); /* 0x183438 OidProxyLo__FP2LO */
undefined4 OidProxyLoPreferred(LO * arg0); /* 0x183458 OidProxyLoPreferred__FP2LO */
undefined4 GetLoOidProxy(LO * arg0, OID * arg1); /* 0x183478 GetLoOidProxy__FP2LOP3OID */
void * PostSpliceEventCallback(LO * arg0, unsigned int arg1, void * arg2); /* 0x1834A0 PostSpliceEventCallback__FP2LOUiPv */
int FFilterSpliceEvent(LO * arg0, SYMEVID arg1, int arg2, void * * arg3); /* 0x183668 FFilterSpliceEvent__FP2LO7SYMEVIDiPPv */
undefined4 HandleLoSpliceEvent(LO * arg0, unsigned int arg1, int arg2, void * * arg3); /* 0x1837E0 HandleLoSpliceEvent__FP2LOUiiPPv */
undefined4 EnsureLoSidebagBool(LO * arg0, OPTID arg1, int arg2); /* 0x183910 EnsureLoSidebagBool__FP2LO5OPTIDi */
undefined4 EnsureLoSidebagInt(LO * arg0, OPTID arg1, int arg2); /* 0x183990 EnsureLoSidebagInt__FP2LO5OPTIDi */
undefined4 EnsureLoSidebagFloat(LO * arg0, OPTID arg1, float arg2); /* 0x183A10 EnsureLoSidebagFloat__FP2LO5OPTIDf */
undefined4 EnsureLoSidebagClq(LO * arg0, OPTID arg1, CLQ * arg2); /* 0x183A90 EnsureLoSidebagClq__FP2LO5OPTIDP3CLQ */
undefined4 EnsureLoSidebagLm(LO * arg0, OPTID arg1, LM * arg2); /* 0x183B20 EnsureLoSidebagLm__FP2LO5OPTIDP2LM */
undefined4 EnsureLoSidebagOid(LO * arg0, OPTID arg1, OID arg2); /* 0x183BB8 EnsureLoSidebagOid__FP2LO5OPTID3OID */
undefined4 EnsureLoSidebagVector(LO * arg0, OPTID arg1, VECTOR * arg2); /* 0x183C38 EnsureLoSidebagVector__FP2LO5OPTIDP6VECTOR */
undefined4 InitLight(LIGHT * arg0); /* 0x183CC8 InitLight__FP5LIGHT */
undefined4 UpdateLightXfWorldHierarchy(LIGHT * arg0); /* 0x183D88 UpdateLightXfWorldHierarchy__FP5LIGHT */
undefined4 RemoveLightFromSw(LIGHT * arg0); /* 0x183DC0 RemoveLightFromSw__FP5LIGHT */
undefined4 AddLightToSw(LIGHT * arg0); /* 0x183DF8 AddLightToSw__FP5LIGHT */
undefined4 OnLightAdd(LIGHT * arg0); /* 0x183E40 OnLightAdd__FP5LIGHT */
undefined4 OnLightRemove(LIGHT * arg0); /* 0x183E70 OnLightRemove__FP5LIGHT */
undefined4 CloneLight(LIGHT * arg0, LIGHT * arg1); /* 0x183EA0 CloneLight__FP5LIGHTT0 */
undefined4 FitLinearFunction(float arg0, float arg1, float arg2, float arg3, float * arg4, float * arg5); /* 0x183F40 FitLinearFunction__FffffPfT4 */
undefined4 FitRecipFunction(float arg0, float arg1, float arg2, float arg3, float * arg4, float * arg5); /* 0x183FE0 FitRecipFunction__FffffPfT4 */
undefined4 ConvertFallOff(LM * arg0, float * arg1, float * arg2); /* 0x1840B8 ConvertFallOff__FP2LMPfT1 */
undefined4 ConvertAngleStrength(float arg0, float arg1, float arg2, float arg3, float * arg4, float * arg5); /* 0x1840F0 ConvertAngleStrength__FffffPfT4 */
undefined4 InvalidateLight(LIGHT * arg0); /* 0x1841B0 InvalidateLight__FP5LIGHT */
undefined4 RebuildLightVifs(LIGHT * arg0); /* 0x1841D0 RebuildLightVifs__FP5LIGHT */
undefined4 SetLightKind(LIGHT * arg0, LIGHTK arg1); /* 0x184768 SetLightKind__FP5LIGHT6LIGHTK */
undefined4 SetLightHighlightColor(LIGHT * arg0, VECTOR * arg1); /* 0x1847F0 SetLightHighlightColor__FP5LIGHTP6VECTOR */
undefined4 SetLightMidtoneStrength(LIGHT * arg0, float arg1); /* 0x184818 SetLightMidtoneStrength__FP5LIGHTf */
undefined4 SetLightShadowStrength(LIGHT * arg0, float arg1); /* 0x184838 SetLightShadowStrength__FP5LIGHTf */
undefined4 SetLightHighlightAngle(LIGHT * arg0, float arg1); /* 0x184858 SetLightHighlightAngle__FP5LIGHTf */
undefined4 SetLightMidtoneAngle(LIGHT * arg0, float arg1); /* 0x184878 SetLightMidtoneAngle__FP5LIGHTf */
undefined4 SetLightShadowAngle(LIGHT * arg0, float arg1); /* 0x184898 SetLightShadowAngle__FP5LIGHTf */
undefined4 SetLightDirection(LIGHT * arg0, VECTOR * arg1); /* 0x1848B8 SetLightDirection__FP5LIGHTP6VECTOR */
undefined4 SetLightDynamic(LIGHT * arg0, int arg1); /* 0x184968 SetLightDynamic__FP5LIGHTi */
undefined4 SetLightFallOff(LIGHT * arg0, LM * arg1); /* 0x184990 SetLightFallOff__FP5LIGHTP2LM */
undefined4 SetLightConeAngle(LIGHT * arg0, float arg1); /* 0x1849D0 SetLightConeAngle__FP5LIGHTf */
undefined4 SetLightHotSpotAngle(LIGHT * arg0, float arg1); /* 0x184A08 SetLightHotSpotAngle__FP5LIGHTf */
undefined4 SetLightFrustrumUp(LIGHT * arg0, VECTOR * arg1); /* 0x184A38 SetLightFrustrumUp__FP5LIGHTP6VECTOR */
undefined4 RebuildLightFrustrum(LIGHT * arg0); /* 0x184A70 RebuildLightFrustrum__FP5LIGHT */
undefined4 UpdateLightBeamGrfzon(LIGHT * arg0); /* 0x184B58 UpdateLightBeamGrfzon__FP5LIGHT */
undefined4 SetLightDiffuse_Old(LIGHT * arg0, float arg1); /* 0x184CD0 SetLightDiffuse_Old__FP5LIGHTf */
undefined4 GetLightDiffuse_Old(LIGHT * arg0, float * arg1); /* 0x184D10 GetLightDiffuse_Old__FP5LIGHTPf */
undefined4 SetLightSaturate_Old(LIGHT * arg0, VECTOR * arg1); /* 0x184D20 SetLightSaturate_Old__FP5LIGHTP6VECTOR */
undefined4 GetLightSaturate_Old(LIGHT * arg0, VECTOR * arg1); /* 0x184D58 GetLightSaturate_Old__FP5LIGHTP6VECTOR */
undefined4 NCmpFindLight(LIGHT * * arg0, LIGHT * * arg1); /* 0x184D78 NCmpFindLight__FPP5LIGHTT0 */
void * PrepareSwLightsForDraw(SW * arg0); /* 0x184DE8 PrepareSwLightsForDraw__FP2SW */
undefined4 TwpsFindSwLights(SW * arg0, VECTOR * arg1, float arg2, int arg3, int arg4, int * arg5, int * arg6, LIGHT * * arg7); /* 0x185150 TwpsFindSwLights__FP2SWP6VECTORfiiPiT5PP5LIGHT */
undefined4 InitActla(ACTLA * arg0, ALO * arg1); /* 0x185358 InitActla__FP5ACTLAP3ALO */
undefined4 SetActlaTarget(ACTLA * arg0, ALO * arg1, VECTOR * arg2); /* 0x1853F0 SetActlaTarget__FP5ACTLAP3ALOP6VECTOR */
void * PaloGetActlaTarget(ACTLA * arg0); /* 0x185468 PaloGetActlaTarget__FP5ACTLA */
undefined4 UpdateActla(ACTLA * arg0, float arg1); /* 0x185498 UpdateActla__FP5ACTLAf */
undefined4 GetActlaRotationGoal(ACTLA * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x185538 GetActlaRotationGoal__FP5ACTLAfP7MATRIX3P6VECTOR */
undefined4 StartupSif(void); /* 0x1858F8 StartupSif__Fv */
undefined4 StartupVU0(void); /* 0x185A58 StartupVU0__Fv */
undefined4 StartupVU1(void); /* 0x185AC8 StartupVU1__Fv */
undefined4 Startup(void); /* 0x185B38 Startup__Fv */
undefined4 MuFromAmtlk(MTLK * arg0); /* 0x185C18 MuFromAmtlk__FP4MTLK */
undefined4 ElasFromAmtlk(MTLK * arg0); /* 0x185CA0 ElasFromAmtlk__FP4MTLK */
void * PxpAdd(SO * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3, float arg4, XPK arg5, void * arg6, void * arg7, XP * * arg8); /* 0x185D20 PxpAdd__FP2SOT0P6VECTORT2f3XPKPvT6PP2XP */
undefined4 RecalcSwXpPos(SW * arg0, int arg1, XP * * arg2); /* 0x185F48 RecalcSwXpPos__FP2SWiPP2XP */
undefined4 RecalcSwXpMovement(SW * arg0, int arg1, XP * * arg2); /* 0x1860A8 RecalcSwXpMovement__FP2SWiPP2XP */
undefined4 FreeSwXpList(SW * arg0, XP * arg1); /* 0x1861E8 FreeSwXpList__FP2SWP2XP */
undefined4 FindClosestPointOnLine(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, float * arg3, float * arg4); /* 0x186230 FindClosestPointOnLine__FP6VECTORN20PfT3 */
undefined4 FindClosestPointOnLineSegment(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, float * arg3, float * arg4); /* 0x186320 FindClosestPointOnLineSegment__FP6VECTORN20PfT3 */
undefined4 ClsgClipSoAllEdges(SO * arg0, SO * arg1, BSP * arg2, int arg3, LSG * arg4); /* 0x186450 ClsgClipSoAllEdges__FP2SOT0P3BSPiP3LSG */
undefined4 ClsgClipSoBspEdges(SO * arg0, SO * arg1, int arg2, BSP * arg3, int arg4, LSG * arg5); /* 0x186568 ClsgClipSoBspEdges__FP2SOT0iP3BSPiP3LSG */
undefined4 CategorizeAlsg(int arg0, LSG * arg1, int * arg2, int * arg3, LSG * * arg4, LSG * * arg5); /* 0x1867C8 CategorizeAlsg__FiP3LSGPiT2PP3LSGT4 */
undefined4 CplsgFindEdgePath(SURF * arg0, int arg1, int arg2, LSG * arg3, LSG * * arg4); /* 0x186A70 CplsgFindEdgePath__FP4SURFiiP3LSGPP3LSG */
undefined4 MarkSoContactsBspBsp(SO * arg0, SO * arg1, int arg2, BSP * arg3, BSP * arg4, XP * * arg5); /* 0x186BA8 MarkSoContactsBspBsp__FP2SOT0iP3BSPT3PP2XP */
undefined4 CsbiIntersectSphereBsp(VECTOR * arg0, float arg1, int arg2, BSP * arg3, BSP * arg4, GEOM * arg5, int arg6, SBI * arg7); /* 0x187260 CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI */
undefined4 MarkSoContactsSphereBsp(SO * arg0, VECTOR * arg1, float arg2, SO * arg3, int arg4, BSP * arg5, BSP * arg6, XP * * arg7); /* 0x1879C0 MarkSoContactsSphereBsp__FP2SOP6VECTORfT0iP3BSPT5PP2XP */
undefined4 MarkSoContactsSphereSphere(SO * arg0, SO * arg1, XP * * arg2); /* 0x187A88 MarkSoContactsSphereSphere__FP2SOT0PP2XP */
undefined4 CalculateCenterContact(SO * arg0, VECTOR * arg1, float arg2, VECTOR * arg3, float * arg4); /* 0x187B60 CalculateCenterContact__FP2SOP6VECTORfT1Pf */
int FMarkSoContactsCenterBsp(SO * arg0, SO * arg1, int arg2, BSP * arg3, BSP * arg4, XP * * arg5); /* 0x187C28 FMarkSoContactsCenterBsp__FP2SOT0iP3BSPT3PP2XP */
int FClipEdgeToSphere(VECTOR * arg0, float arg1, VECTOR * arg2, VECTOR * arg3, float * arg4, VECTOR * arg5, VECTOR * arg6, float * arg7); /* 0x187D08 FClipEdgeToSphere__FP6VECTORfT0T0PfT0T0T4 */
int FMarkSoContactsCenterSphere(SO * arg0, SO * arg1, XP * * arg2); /* 0x187E88 FMarkSoContactsCenterSphere__FP2SOT0PP2XP */
undefined4 AddSoXps(SO * arg0, SO * arg1, int arg2, int arg3, BSP * arg4, BSP * arg5, XP * * arg6); /* 0x187F40 AddSoXps__FP2SOT0iiP3BSPT4PP2XP */
void * PxpMarkSwContactsRoot(SW * arg0, SO * * arg1, int arg2); /* 0x188270 PxpMarkSwContactsRoot__FP2SWPP2SOi */
void * MATRIX4_PostCopyMatrix3(MATRIX4 *this); /* 0x1884C0 PostCopyMatrix3__7MATRIX4 */
undefined4 MATRIX4_op_assign(MATRIX4 *this, const MATRIX3 * arg1); /* 0x1884E0 __as__7MATRIX4RC7MATRIX3 */
undefined4 MatMulMatTransMat(const MATRIX3 * arg0, const MATRIX3 * arg1); /* 0x188520 MatMulMatTransMat__FRC7MATRIX3T0 */
undefined4 LoadIdentityMatrix4(MATRIX4 * arg0); /* 0x1885E0 LoadIdentityMatrix4__FP7MATRIX4 */
undefined4 op_multiply_2(const MATRIX4 * arg0, VU_FLOAT arg1); /* 0x188628 __ml__FRC7MATRIX4G8VU_FLOAT */
undefined4 op_multiply_3(const MATRIX4 * arg0, const MATRIX4 * arg1); /* 0x188668 __ml__FRC7MATRIX4T0 */
undefined4 MultiplyMatrix4Vector(MATRIX4 * arg0, VECTOR * arg1, float arg2, VECTOR * arg3); /* 0x188700 MultiplyMatrix4Vector__FP7MATRIX4P6VECTORfT1 */
undefined4 op_multiply_4(const MATRIX4 * arg0, VU_VECTOR4 arg1); /* 0x188740 __ml__FRC7MATRIX4G10VU_VECTOR4 */
undefined4 TransposeMatrix4(MATRIX4 * arg0, MATRIX4 * arg1); /* 0x188770 TransposeMatrix4__FP7MATRIX4T0 */
undefined4 AddMatrix4Matrix4(MATRIX4 * arg0, MATRIX4 * arg1, MATRIX4 * arg2); /* 0x188810 AddMatrix4Matrix4__FP7MATRIX4N20 */
undefined4 LoadRotateMatrixRad(float arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x188850 LoadRotateMatrixRad__FfP6VECTORP7MATRIX3 */
undefined4 LoadRotateMatrix(VECTOR * arg0, MATRIX3 * arg1); /* 0x188978 LoadRotateMatrix__FP6VECTORP7MATRIX3 */
undefined4 LoadRotateMatrixEuler(VECTOR * arg0, MATRIX3 * arg1); /* 0x188A20 LoadRotateMatrixEuler__FP6VECTORP7MATRIX3 */
undefined4 LoadMatrixFromPosRot(VECTOR * arg0, MATRIX3 * arg1, MATRIX4 * arg2); /* 0x188B08 LoadMatrixFromPosRot__FP6VECTORP7MATRIX3P7MATRIX4 */
undefined4 LoadMatrixFromPosRotInverse(VECTOR * arg0, MATRIX3 * arg1, MATRIX4 * arg2); /* 0x188B48 LoadMatrixFromPosRotInverse__FP6VECTORP7MATRIX3P7MATRIX4 */
undefined4 LoadMatrixFromPosRotScale(VECTOR * arg0, MATRIX3 * arg1, VECTOR * arg2, MATRIX4 * arg3); /* 0x188C10 LoadMatrixFromPosRotScale__FP6VECTORP7MATRIX3T0P7MATRIX4 */
undefined4 CosRotateMatrixMagnitude(MATRIX3 * arg0); /* 0x188CE0 CosRotateMatrixMagnitude__FP7MATRIX3 */
undefined4 DecomposeRotateMatrixRad(MATRIX3 * arg0, float * arg1, VECTOR * arg2); /* 0x188D28 DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR */
undefined4 DecomposeRotateMatrixEuler(MATRIX3 * arg0, VECTOR * arg1); /* 0x188FD8 DecomposeRotateMatrixEuler__FP7MATRIX3P6VECTOR */
undefined4 NormalizeRotateMatrix3(MATRIX3 * arg0); /* 0x1890A0 NormalizeRotateMatrix3__FP7MATRIX3 */
undefined4 CalculateDmat(MATRIX3 * arg0, MATRIX3 * arg1, MATRIX3 * arg2); /* 0x189150 CalculateDmat__FP7MATRIX3N20 */
undefined4 CalculateDmat4(MATRIX4 * arg0, MATRIX4 * arg1, MATRIX4 * arg2); /* 0x1891C0 CalculateDmat4__FP7MATRIX4N20 */
undefined4 DecomposeRotateMatrixPanTilt(MATRIX3 * arg0, float * arg1, float * arg2); /* 0x189230 DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1 */
undefined4 LoadRotateMatrixPanTilt(float arg0, float arg1, MATRIX3 * arg2); /* 0x1892A0 LoadRotateMatrixPanTilt__FffP7MATRIX3 */
undefined4 LoadLookAtMatrix(VECTOR * arg0, MATRIX3 * arg1); /* 0x189350 LoadLookAtMatrix__FP6VECTORP7MATRIX3 */
undefined4 TiltMatUpright(MATRIX3 * arg0, MATRIX3 * arg1, MATRIX3 * arg2); /* 0x189378 TiltMatUpright__FP7MATRIX3N20 */
int FInvertMatrix(int arg0, float * arg1, float * arg2); /* 0x189438 FInvertMatrix__FiPfT1 */
int FInvertMatrix3(MATRIX3 * arg0, MATRIX3 * arg1); /* 0x1897F0 FInvertMatrix3__FP7MATRIX3T0 */
int FInvertMatrix4(MATRIX4 * arg0, MATRIX4 * arg1); /* 0x189AF0 FInvertMatrix4__FP7MATRIX4T0 */
undefined4 BuildOrthonormalMatrixY(VECTOR * arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x189B18 BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3 */
undefined4 BuildOrthonormalMatrixZ(VECTOR * arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x189C28 BuildOrthonormalMatrixZ__FP6VECTORT0P7MATRIX3 */
undefined4 BuildRotateVectorsMatrix(VECTOR * arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x189D38 BuildRotateVectorsMatrix__FP6VECTORT0P7MATRIX3 */
undefined4 BuildSimpleProjectionMatrix(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, MATRIX4 * arg6); /* 0x189F58 BuildSimpleProjectionMatrix__FffffffP7MATRIX4 */
undefined4 LoadScaleMatrixScalar(VECTOR * arg0, float arg1, MATRIX4 * arg2); /* 0x18A008 LoadScaleMatrixScalar__FP6VECTORfP7MATRIX4 */
undefined4 LoadScaleMatrixVector(VECTOR * arg0, MATRIX3 * arg1, VECTOR * arg2, MATRIX4 * arg3); /* 0x18A040 LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4 */
undefined4 LoadRotateVectorMatrix(VECTOR * arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x18A160 LoadRotateVectorMatrix__FP6VECTORT0P7MATRIX3 */
undefined4 InitMbg(MBG * arg0); /* 0x18A388 InitMbg__FP3MBG */
undefined4 LoadMbgFromBrx(MBG * arg0, CBinaryInputStream * arg1); /* 0x18A3B8 LoadMbgFromBrx__FP3MBGP18CBinaryInputStream */
void * PostMbgLoad(MBG * arg0); /* 0x18A3F0 PostMbgLoad__FP3MBG */
void * PsoHitTestCylinderObjects(int arg0, VECTOR * arg1, VECTOR * arg2, float arg3, int arg4, SO * * arg5, LSG * arg6); /* 0x18A6C0 PsoHitTestCylinderObjects__FiP6VECTORT1fiPP2SOP3LSG */
int FFilterMbgAttackObjects(MBG * arg0, SO * arg1); /* 0x18A830 FFilterMbgAttackObjects__FP3MBGP2SO */
int FObstructedMbg(MBG * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x18A910 FObstructedMbg__FP3MBGP6VECTORT1 */
int FCanMbgAttack(MBG * arg0); /* 0x18A9A8 FCanMbgAttack__FP3MBG */
int FDetectMbg(MBG * arg0); /* 0x18AAE0 FDetectMbg__FP3MBG */
int FUN_0018ab88(int arg0); /* 0x18AB88 FUN_0018ab88__Fi */
int FUN_0018abf0(int arg0); /* 0x18ABF0 FUN_0018abf0__Fi */
int FUN_0018ac58(int arg0); /* 0x18AC58 FUN_0018ac58__Fi */
undefined4 UpdateMbg(MBG * arg0, float arg1); /* 0x18ACD0 UpdateMbg__FP3MBGf */
undefined4 UpdateMbgGoal(MBG * arg0, int arg1); /* 0x18AD88 UpdateMbgGoal__FP3MBGi */
undefined4 UpdateMbgSgs(MBG * arg0); /* 0x18AE38 UpdateMbgSgs__FP3MBG */
undefined4 OnMgExitingSgs(MBG * arg0, SGS arg1); /* 0x18B2E8 OnMgExitingSgs__FP3MBG3SGS */
undefined4 HandleMbgMessage(MBG * arg0, MSGID arg1, void * arg2); /* 0x18B340 HandleMbgMessage__FP3MBG5MSGIDPv */
undefined4 StartupMemcard(void); /* 0x18B580 StartupMemcard__Fv */
undefined4 InitMemcard(MEMCARD * arg0); /* 0x18B5C0 InitMemcard__FP7MEMCARD */
int FUN_0018b600(void); /* 0x18B600 FUN_0018b600__Fv */
undefined4 CreateMemcardThread(MEMCARD * arg0, int arg1, int arg2); /* 0x18B670 CreateMemcardThread__FP7MEMCARDii */
undefined4 SetMemcardThreadHighPrio(MEMCARD * arg0); /* 0x18B720 SetMemcardThreadHighPrio__FP7MEMCARD */
int FMemcardThreadValid(MEMCARD * arg0); /* 0x18B770 FMemcardThreadValid__FP7MEMCARD */
int FUN_0018b910(int arg0); /* 0x18B910 FUN_0018b910__Fi */
int FUN_0018b930(int arg0); /* 0x18B930 FUN_0018b930__Fi */
undefined4 InitSave(SAVE * arg0, int arg1, int arg2); /* 0x18BD58 InitSave__FP4SAVEii */
undefined4 UpdateSave(SAVE * arg0); /* 0x18BDC8 UpdateSave__FP4SAVE */
undefined4 CompareSaves(SAVE * arg0, SAVE * arg1); /* 0x18BFA8 CompareSaves__FP4SAVET0 */
int FUN_0018c7f8(SAVE * arg0); /* 0x18C7F8 FUN_0018c7f8__FP4SAVE */
undefined4 CFileLocation_Clear(CFileLocation *this); /* 0x18D410 Clear__13CFileLocation */
undefined4 StartupMemMgr(void); /* 0x18D430 StartupMemMgr__Fv */
void * PvAllocGlobalImpl(int arg0); /* 0x18D4B0 PvAllocGlobalImpl__Fi */
undefined4 CheckForOutOfMemory(void); /* 0x18D4F8 CheckForOutOfMemory__Fv */
void * PvAllocSwImpl(int arg0); /* 0x18D500 PvAllocSwImpl__Fi */
undefined4 FreeSw(void); /* 0x18D550 FreeSw__Fv */
void * PvAllocSwCopyImpl(int arg0, void * arg1); /* 0x18D568 PvAllocSwCopyImpl__FiPv */
void * PvAllocSwClearImpl(int arg0); /* 0x18D5C0 PvAllocSwClearImpl__Fi */
undefined4 InitStackImpl(void); /* 0x18D608 InitStackImpl__Fv */
void * PvAllocStackImpl(int arg0); /* 0x18D658 PvAllocStackImpl__Fi */
void * PvAllocStackClearImpl(int arg0); /* 0x18D6A8 PvAllocStackClearImpl__Fi */
undefined4 FreeStackImpl(void); /* 0x18D6F0 FreeStackImpl__Fv */
undefined4 CopyAqw(void * arg0, void * arg1, int arg2); /* 0x18D780 CopyAqw__FPvT0i */
undefined4 CopyAb(void * arg0, void * arg1, unsigned int arg2); /* 0x18D800 CopyAb__FPvT0Ui */
undefined4 InitMissile(MISSILE * arg0); /* 0x18D8E0 InitMissile__FP7MISSILE */
undefined4 LoadMissileFromBrx(MISSILE * arg0, CBinaryInputStream * arg1); /* 0x18D910 LoadMissileFromBrx__FP7MISSILEP18CBinaryInputStream */
undefined4 OnMissileRemove(MISSILE * arg0); /* 0x18D978 OnMissileRemove__FP7MISSILE */
void * ProjectMissileTransform(MISSILE * arg0, float arg1, int arg2); /* 0x18D9B8 ProjectMissileTransform__FP7MISSILEfi */
undefined4 FireMissile(MISSILE * arg0, ALO * arg1, VECTOR * arg2); /* 0x18DA40 FireMissile__FP7MISSILEP3ALOP6VECTOR */
undefined4 RenderMissileAll(MISSILE * arg0, CM * arg1, RO * arg2); /* 0x18DB20 RenderMissileAll__FP7MISSILEP2CMP2RO */
undefined4 InitAccmiss(ACCMISS * arg0); /* 0x18DDA0 InitAccmiss__FP7ACCMISS */
undefined4 FireAccmiss(ACCMISS * arg0, ALO * arg1, VECTOR * arg2); /* 0x18DDD8 FireAccmiss__FP7ACCMISSP3ALOP6VECTOR */
void * PresetAccmissAccel(ACCMISS * arg0, float arg1); /* 0x18DE70 PresetAccmissAccel__FP7ACCMISSf */
undefined4 FireSplmiss(SPLMISS * arg0, ALO * arg1, VECTOR * arg2); /* 0x18DEE8 FireSplmiss__FP7SPLMISSP3ALOP6VECTOR */
void * ProjectSplmissTransform(SPLMISS * arg0, float arg1, int arg2); /* 0x18E040 ProjectSplmissTransform__FP7SPLMISSfi */
undefined4 StartupMpeg(void); /* 0x18E5E8 StartupMpeg__Fv */
undefined4 CQueueOutputIop_Init(CQueueOutputIop *this, int arg1, int arg2); /* 0x18E678 Init__15CQueueOutputIopii */
undefined4 CQueueOutputIop_Reset(CQueueOutputIop *this); /* 0x18E6A0 Reset__15CQueueOutputIop */
undefined4 CQueueOutputIop_CbWrite(CQueueOutputIop *this, int arg1, void * arg2); /* 0x18E6C0 CbWrite__15CQueueOutputIopiPv */
undefined4 CQueueOutputIop_CbSend(CQueueOutputIop *this, int arg1, void * arg2); /* 0x18E7C0 CbSend__15CQueueOutputIopiPv */
undefined4 CQueueOutputIop_Update(CQueueOutputIop *this); /* 0x18E838 Update__15CQueueOutputIop */
int CQueueOutputIop_FAsyncDrain(CQueueOutputIop *this); /* 0x18E8C0 FAsyncDrain__15CQueueOutputIop */
undefined4 CQueueOutputIpu_CbWrite(CQueueOutputIpu *this, int arg1, void * arg2); /* 0x18E8C8 CbWrite__15CQueueOutputIpuiPv */
int CQueueOutputIpu_FAsyncDrain(CQueueOutputIpu *this); /* 0x18E938 FAsyncDrain__15CQueueOutputIpu */
undefined4 CMpegAudio_Init(CMpegAudio *this); /* 0x18E940 Init__10CMpegAudio */
undefined4 CMpegAudio_Reset(CMpegAudio *this); /* 0x18EA48 Reset__10CMpegAudio */
undefined4 CMpegAudio_Close(CMpegAudio *this); /* 0x18EAA0 Close__10CMpegAudio */
int CMpegAudio_FAccept(CMpegAudio *this, int arg1, unsigned char * arg2); /* 0x18EAF8 FAccept__10CMpegAudioiPUc */
undefined4 CMpegAudio_Update(CMpegAudio *this); /* 0x18EB98 Update__10CMpegAudio */
int FMpegAcceptVideo(sceMpeg * arg0, sceMpegCbDataStr * arg1, CMpeg * arg2); /* 0x18EC40 FMpegAcceptVideo__FP7sceMpegP16sceMpegCbDataStrP5CMpeg */
int FMpegAcceptAudio(sceMpeg * arg0, sceMpegCbDataStr * arg1, CMpeg * arg2); /* 0x18EC80 FMpegAcceptAudio__FP7sceMpegP16sceMpegCbDataStrP5CMpeg */
int FMpegDecodeVideo(sceMpeg * arg0, sceMpegCbData * arg1, CMpeg * arg2); /* 0x18ECA8 FMpegDecodeVideo__FP7sceMpegP13sceMpegCbDataP5CMpeg */
int FMpegDecoderIdle(sceMpeg * arg0, sceMpegCbData * arg1, CMpeg * arg2); /* 0x18ED78 FMpegDecoderIdle__FP7sceMpegP13sceMpegCbDataP5CMpeg */
int FMpegDecoderError(sceMpeg * arg0, sceMpegCbData * arg1, CMpeg * arg2); /* 0x18EDA0 FMpegDecoderError__FP7sceMpegP13sceMpegCbDataP5CMpeg */
undefined4 BuildMpegGifs(QW * arg0, sceIpuRGB32 * arg1, int arg2, int arg3, int arg4, int arg5, int arg6); /* 0x18EDA8 BuildMpegGifs__FP2QWP11sceIpuRGB32iiiii */
undefined4 CMpeg_ExecuteOids(CMpeg *this); /* 0x18F148 ExecuteOids__5CMpeg */
undefined4 CMpeg_Execute(CMpeg *this); /* 0x18F198 Execute__5CMpeg */
undefined4 CMpeg_Start(CMpeg *this, CBinaryAsyncStream * arg1); /* 0x18F448 Start__5CMpegP18CBinaryAsyncStream */
int CMpeg_FUN_0018f610(CMpeg *this); /* 0x18F610 FUN_0018f610__5CMpeg */
undefined4 CMpeg_Update(CMpeg *this); /* 0x18F6E8 Update__5CMpeg */
undefined4 CMpeg_Finish(CMpeg *this); /* 0x18F7D0 Finish__5CMpeg */
undefined4 CMpeg_CbDemuxed(CMpeg *this, int arg1); /* 0x18F890 CbDemuxed__5CMpegi */
undefined4 InitMrkv(MRKV * arg0); /* 0x18F988 InitMrkv__FP4MRKV */
undefined4 RenderMsGlobset(MS * arg0, CM * arg1, RO * arg2); /* 0x18F9D8 RenderMsGlobset__FP2MSP2CMP2RO */
undefined4 InitMurray(MURRAY * arg0); /* 0x18FEF8 InitMurray__FP6MURRAY */
void * PostMurrayLoad(MURRAY * arg0); /* 0x18FF28 PostMurrayLoad__FP6MURRAY */
undefined4 OnMurrayEnteringSgs(MURRAY * arg0, SGS arg1, ASEG * arg2); /* 0x18FFB0 OnMurrayEnteringSgs__FP6MURRAY3SGSP4ASEG */
undefined4 OnMurrayExitingSgs(MURRAY * arg0, SGS arg1); /* 0x1900A0 OnMurrayExitingSgs__FP6MURRAY3SGS */
undefined4 UpdateMurrayGoal(MURRAY * arg0, int arg1); /* 0x190128 UpdateMurrayGoal__FP6MURRAYi */
undefined4 UpdateMurraySgs(MURRAY * arg0); /* 0x190258 UpdateMurraySgs__FP6MURRAY */
int FUN_001903f0(MURRAY * arg0, int arg1); /* 0x1903F0 FUN_001903f0__FP6MURRAYi */
int FUN_00190450(MURRAY * arg0, ZPR * arg1); /* 0x190450 FUN_00190450__FP6MURRAYP3ZPR */
int FAbsorbMurrayWkr(MURRAY * arg0, WKR * arg1); /* 0x1904E0 FAbsorbMurrayWkr__FP6MURRAYP3WKR */
int FDetectMurray(MURRAY * arg0); /* 0x190570 FDetectMurray__FP6MURRAY */
int FCanMurrayAttack(MURRAY * arg0); /* 0x190658 FCanMurrayAttack__FP6MURRAY */
undefined4 AddMurrayEnemy(MURRAY * arg0, ALO * arg1); /* 0x190660 AddMurrayEnemy__FP6MURRAYP3ALO */
undefined4 SetMurrayPursueXfm(MURRAY * arg0, XFM * arg1); /* 0x1906E8 SetMurrayPursueXfm__FP6MURRAYP3XFM */
undefined4 SetMurrayPatrolXfm(MURRAY * arg0, XFM * arg1); /* 0x1906F0 SetMurrayPatrolXfm__FP6MURRAYP3XFM */
undefined4 CollectMurrayPrize(MURRAY * arg0, PCK arg1, ALO * arg2); /* 0x1906F8 CollectMurrayPrize__FP6MURRAY3PCKP3ALO */
undefined4 CheckMurrayStunOrDying(MURRAY * arg0); /* 0x190740 CheckMurrayStunOrDying__FP6MURRAY */
undefined4 HandleMurrayMessage(MURRAY * arg0, MSGID arg1, void * arg2); /* 0x190770 HandleMurrayMessage__FP6MURRAY5MSGIDPv */
void * PcbspExtract(CBSP * arg0); /* 0x1907E0 PcbspExtract__FP4CBSP */
void * PcgtExtract(CGT * arg0); /* 0x1907F0 PcgtExtract__FP3CGT */
void * PcgtPointInCbspQuick(CBSP * arg0, VECTOR * arg1); /* 0x190810 PcgtPointInCbspQuick__FP4CBSPP6VECTOR */
void * PcgtPointInCbspSafe(CBSP * arg0, VECTOR * arg1); /* 0x1908C0 PcgtPointInCbspSafe__FP4CBSPP6VECTOR */
undefined4 CbskFromG(float arg0); /* 0x1909B0 CbskFromG__Ff */
undefined4 ClsgClipEdgeToCbsp(CBSP * arg0, VECTOR * arg1, VECTOR * arg2, int arg3, LSG * arg4); /* 0x1909F0 ClsgClipEdgeToCbsp__FP4CBSPP6VECTORT1iP3LSG */
int FClipEdgeToCbsp(CBSP * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x190E30 FClipEdgeToCbsp__FP4CBSPP6VECTORT1 */
undefined4 IcgvFromPcgv(CG * arg0, CGV * arg1); /* 0x190EA8 IcgvFromPcgv__FP2CGP3CGV */
undefined4 FindPathAStar(CG * arg0, CGV * arg1, CGV * arg2, int arg3, int * arg4, CGV * * arg5); /* 0x190EB8 FindPathAStar__FP2CGP3CGVT1iPiPP3CGV */
undefined4 SimplifyApcgvNeighbor(CBSP * arg0, int * arg1, CGV * * arg2); /* 0x191128 SimplifyApcgvNeighbor__FP4CBSPPiPP3CGV */
undefined4 CposFindPath(CG * arg0, VECTOR * arg1, VECTOR * arg2, int arg3, VECTOR * arg4); /* 0x191290 CposFindPath__FP2CGP6VECTORT1iT1 */
undefined4 FindClosestPointInCg(CG * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x191570 FindClosestPointInCg__FP2CGP6VECTORT1 */
undefined4 LoadPathzoneFromBrx(PATHZONE * arg0, CBinaryInputStream * arg1); /* 0x1916D0 LoadPathzoneFromBrx__FP8PATHZONEP18CBinaryInputStream */
undefined4 HookupCg(CG * arg0); /* 0x1919F8 HookupCg__FP2CG */
undefined4 CposFindPathzonePath(PATHZONE * arg0, VECTOR * arg1, VECTOR * arg2, int arg3, VECTOR * arg4); /* 0x191A68 CposFindPathzonePath__FP8PATHZONEP6VECTORT1iT1 */
undefined4 FindPathzoneClosestPoint(PATHZONE * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x191A88 FindPathzoneClosestPoint__FP8PATHZONEP6VECTORT1 */
undefined4 ChoosePathzoneRandomPoint(PATHZONE * arg0, VECTOR * arg1); /* 0x191C78 ChoosePathzoneRandomPoint__FP8PATHZONEP6VECTOR */
undefined4 SetPhase(PHASE arg0); /* 0x191E70 SetPhase__F5PHASE */
undefined4 ClearPhase(PHASE arg0); /* 0x191EB0 ClearPhase__F5PHASE */
undefined4 StartupPipe(void); /* 0x191EC0 StartupPipe__Fv */
undefined4 ResetPipeList(void); /* 0x191EE8 ResetPipeList__Fv */
undefined4 InitPipe(PIPE * arg0); /* 0x191F08 InitPipe__FP4PIPE */
undefined4 OnPipeAdd(PIPE * arg0); /* 0x191F68 OnPipeAdd__FP4PIPE */
undefined4 OnPipeRemove(PIPE * arg0); /* 0x191FA0 OnPipeRemove__FP4PIPE */
void * PostPipeLoad(PIPE * arg0); /* 0x191FD8 PostPipeLoad__FP4PIPE */
undefined4 ClonePipe(PIPE * arg0, PIPE * arg1); /* 0x192020 ClonePipe__FP4PIPET0 */
undefined4 LoadPntFromBrx(PNT * arg0, CBinaryInputStream * arg1); /* 0x192068 LoadPntFromBrx__FP3PNTP18CBinaryInputStream */
undefined4 GetPntPos(PNT * arg0, VECTOR * arg1); /* 0x1920B0 GetPntPos__FP3PNTP6VECTOR */
undefined4 SetPntParent(PNT * arg0, ALO * arg1); /* 0x1920E0 SetPntParent__FP3PNTP3ALO */
undefined4 ApplyPntProxy(PNT * arg0, PROXY * arg1); /* 0x192128 ApplyPntProxy__FP3PNTP5PROXY */
int FUN_00192150(PNT * arg0, CBinaryInputStream * arg1); /* 0x192150 FUN_00192150__FP3PNTP18CBinaryInputStream */
int FUN_00192190(PNT * arg0); /* 0x192190 FUN_00192190__FP3PNT */
undefined4 InitPo(PO * arg0); /* 0x1921A8 InitPo__FP2PO */
undefined4 ClonePo(PO * arg0, PO * arg1); /* 0x1921E8 ClonePo__FP2POT0 */
undefined4 HandlePoMessage(PO * arg0, MSGID arg1, void * arg2); /* 0x192230 HandlePoMessage__FP2PO5MSGIDPv */
undefined4 OnPoActive(PO * arg0, int arg1, PO * arg2); /* 0x1922E8 OnPoActive__FP2POiT0 */
undefined4 GetPoCpdefi(PO * arg0, float arg1, CPDEFI * arg2); /* 0x192380 GetPoCpdefi__FP2POfP6CPDEFI */
int FIsPoSoundBase(PO * arg0); /* 0x192410 FIsPoSoundBase__FP2PO */
undefined4 MakePoActive(PO * arg0); /* 0x192418 MakePoActive__FP2PO */
int FInvulnerablePo(PO * arg0, ZPK arg1); /* 0x192450 FInvulnerablePo__FP2PO3ZPK */
int FTakePoDamage(PO * arg0, ZPR * arg1); /* 0x192488 FTakePoDamage__FP2POP3ZPR */
undefined4 JthsCurrentPo(PO * arg0); /* 0x192490 JthsCurrentPo__FP2PO */
undefined4 CollectPoPrize(PO * arg0, PCK arg1, ALO * arg2); /* 0x1924C8 CollectPoPrize__FP2PO3PCKP3ALO */
void * PpoCur(void); /* 0x1925F0 PpoCur__Fv */
void * PpoStart(void); /* 0x192620 PpoStart__Fv */
undefined4 _IppoFindPo(PO * arg0); /* 0x192688 _IppoFindPo__FP2PO */
undefined4 AddPoToList(PO * arg0); /* 0x1926D0 AddPoToList__FP2PO */
undefined4 RemovePoFromList(PO * arg0); /* 0x192780 RemovePoFromList__FP2PO */
undefined4 OnPoAdd(PO * arg0); /* 0x192820 OnPoAdd__FP2PO */
undefined4 OnPoRemove(PO * arg0); /* 0x192850 OnPoRemove__FP2PO */
undefined4 SwitchToIppo(int arg0); /* 0x192880 SwitchToIppo__Fi */
undefined4 SetPoPlayable(PO * arg0, int arg1); /* 0x192990 SetPoPlayable__FP2POi */
undefined4 SwitchToPo(PO * arg0); /* 0x1929D0 SwitchToPo__FP2PO */
void * PpziCur(void); /* 0x1929F8 PpziCur__Fv */
undefined4 GetPoDiapi(PO * arg0, DIALOG * arg1, DIAPI * arg2); /* 0x192A28 GetPoDiapi__FP2POP6DIALOGP5DIAPI */
void * PlayPoDialog(PO * arg0, DIALOG * arg1); /* 0x192A38 PlayPoDialog__FP2POP6DIALOG */
undefined4 UpdatePo(PO * arg0, float arg1); /* 0x192B58 UpdatePo__FP2POf */
undefined4 UsePoCharm(PO * arg0); /* 0x192C58 UsePoCharm__FP2PO */
int FUN_001930B0(PO * arg0); /* 0x1930B0 FUN_001930B0__FP2PO */
undefined4 _GLOBAL_$I$InitPo(PO * arg0); /* 0x1931F0 _GLOBAL_$I$InitPo__FP2PO */
void CProg_constructor(CProg *this, RGBA * arg1, RGBA * arg2, RGBA * arg3, RGBA * arg4); /* 0x193210 __5CProgP4RGBAN31 */
undefined4 CProg_Begin(CProg *this); /* 0x193270 Begin__5CProg */
undefined4 CProg_SetRemain(CProg *this, int arg1); /* 0x193288 SetRemain__5CProgi */
undefined4 CProg_End(CProg *this); /* 0x193300 End__5CProg */
undefined4 CProg_Draw(CProg *this); /* 0x193318 Draw__5CProg */
undefined4 AchzFromRespk(RESPK arg0); /* 0x193598 AchzFromRespk__F5RESPK */
int FUN_00193660(void); /* 0x193660 FUN_00193660__Fv */
undefined4 SetPromptPrk(PROMPT * arg0, PRK arg1); /* 0x1936A0 SetPromptPrk__FP6PROMPT3PRK */
void * PostPromptLoad(PROMPT * arg0); /* 0x193E58 PostPromptLoad__FP6PROMPT */
int FUN_00193f88(void); /* 0x193F88 FUN_00193f88__Fv */
undefined4 OnPromptActive(PROMPT * arg0, int arg1); /* 0x1940E8 OnPromptActive__FP6PROMPTi */
int FUN_00194398(void); /* 0x194398 FUN_00194398__Fv */
undefined4 UpdatePromptActive(PROMPT * arg0, JOY * arg1); /* 0x1943E8 UpdatePromptActive__FP6PROMPTP3JOY */
undefined4 SetPrompt(PROMPT * arg0, PRP arg1, PRK arg2); /* 0x194D30 SetPrompt__FP6PROMPT3PRP3PRK */
undefined4 SetPromptBlots(PROMPT * arg0, BLOTS arg1); /* 0x194E60 SetPromptBlots__FP6PROMPT5BLOTS */
undefined4 DrawPrompt(PROMPT * arg0); /* 0x194F80 DrawPrompt__FP6PROMPT */
undefined4 ExecutePrompt(PROMPT * arg0); /* 0x195958 ExecutePrompt__FP6PROMPT */
undefined4 CancelPrompt(PROMPT * arg0); /* 0x1961C0 CancelPrompt__FP6PROMPT */
undefined4 _GLOBAL_$I$AchzFromRespk(RESPK arg0); /* 0x1963B8 _GLOBAL_$I$AchzFromRespk__F5RESPK */
undefined4 InitProxy(PROXY * arg0); /* 0x1963D8 InitProxy__FP5PROXY */
undefined4 LoadProxyFromBrx(PROXY * arg0, CBinaryInputStream * arg1); /* 0x196410 LoadProxyFromBrx__FP5PROXYP18CBinaryInputStream */
undefined4 CloneProxy(PROXY * arg0, PROXY * arg1); /* 0x196810 CloneProxy__FP5PROXYT0 */
void * PostProxyLoad(PROXY * arg0); /* 0x196900 PostProxyLoad__FP5PROXY */
undefined4 InitPuffer(PUFFER * arg0); /* 0x196938 InitPuffer__FP6PUFFER */
undefined4 LoadPufferFromBrx(PUFFER * arg0, CBinaryInputStream * arg1); /* 0x1969C0 LoadPufferFromBrx__FP6PUFFERP18CBinaryInputStream */
void * PostPufferLoad(PUFFER * arg0); /* 0x1969F8 PostPufferLoad__FP6PUFFER */
void * PresetPufferAccel(PUFFER * arg0, float arg1); /* 0x196B78 PresetPufferAccel__FP6PUFFERf */
int FFilterPuffer(PUFFER * arg0, SO * arg1); /* 0x196E48 FFilterPuffer__FP6PUFFERP2SO */
undefined4 UpdatePuffer(PUFFER * arg0, float arg1); /* 0x196EB0 UpdatePuffer__FP6PUFFERf */
void * PpufftChoosePuffer(PUFFER * arg0); /* 0x1971B8 PpufftChoosePuffer__FP6PUFFER */
undefined4 OnPufferActive(PUFFER * arg0, int arg1, PO * arg2); /* 0x1974D8 OnPufferActive__FP6PUFFERiP2PO */
undefined4 UpdatePufferActive(PUFFER * arg0, JOY * arg1, float arg2); /* 0x1974F8 UpdatePufferActive__FP6PUFFERP3JOYf */
undefined4 AddPufferWaterAcceleration(PUFFER * arg0, WATER * arg1, float arg2); /* 0x197A88 AddPufferWaterAcceleration__FP6PUFFERP5WATERf */
undefined4 HandlePufferMessage(PUFFER * arg0, MSGID arg1, void * arg2); /* 0x197F10 HandlePufferMessage__FP6PUFFER5MSGIDPv */
void * PostPuffcLoad(PUFFC * arg0); /* 0x198090 PostPuffcLoad__FP5PUFFC */
void * PresetPuffcAccel(PUFFC * arg0, float arg1); /* 0x1980B0 PresetPuffcAccel__FP5PUFFCf */
undefined4 UpdatePuffcGoal(PUFFC * arg0, int arg1); /* 0x198318 UpdatePuffcGoal__FP5PUFFCi */
undefined4 OnPuffcExitingSgs(PUFFC * arg0, SGS arg1); /* 0x1984B8 OnPuffcExitingSgs__FP5PUFFC3SGS */
undefined4 OnPuffcEnteringSgs(PUFFC * arg0, SGS arg1, ASEG * arg2); /* 0x198530 OnPuffcEnteringSgs__FP5PUFFC3SGSP4ASEG */
undefined4 UpdatePuffcSgs(PUFFC * arg0); /* 0x198570 UpdatePuffcSgs__FP5PUFFC */
undefined4 HandlePuffcMessage(PUFFC * arg0, MSGID arg1, void * arg2); /* 0x1986E8 HandlePuffcMessage__FP5PUFFC5MSGIDPv */
undefined4 UpdatePuffc(PUFFC * arg0, float arg1); /* 0x198760 UpdatePuffc__FP5PUFFCf */
int FCanPuffcAttack(PUFFC * arg0); /* 0x198858 FCanPuffcAttack__FP5PUFFC */
void * PostPuffbLoad(PUFFB * arg0); /* 0x198920 PostPuffbLoad__FP5PUFFB */
undefined4 InitSprize(SPRIZE * arg0); /* 0x198980 InitSprize__FP6SPRIZE */
undefined4 LoadSprizeFromBrx(SPRIZE * arg0, CBinaryInputStream * arg1); /* 0x1989B0 LoadSprizeFromBrx__FP6SPRIZEP18CBinaryInputStream */
undefined4 BindSprize(SPRIZE * arg0); /* 0x198A88 BindSprize__FP6SPRIZE */
void * PostSprizeLoad(SPRIZE * arg0); /* 0x198B28 PostSprizeLoad__FP6SPRIZE */
undefined4 UpdateSprize(SPRIZE * arg0, float arg1); /* 0x198BD8 UpdateSprize__FP6SPRIZEf */
undefined4 CollectSprize(SPRIZE * arg0); /* 0x198DA8 CollectSprize__FP6SPRIZE */
undefined4 EmitSprizeExplosion(SPRIZE * arg0); /* 0x198E58 EmitSprizeExplosion__FP6SPRIZE */
void * PcsFromSprize(SPRIZE * arg0); /* 0x198E98 PcsFromSprize__FP6SPRIZE */
undefined4 AddSprizeAseg(SPRIZE * arg0, OID arg1); /* 0x198ED8 AddSprizeAseg__FP6SPRIZE3OID */
undefined4 HandleSprizeMessage(SPRIZE * arg0, MSGID arg1, void * arg2); /* 0x198EF8 HandleSprizeMessage__FP6SPRIZE5MSGIDPv */
int FIgnoreSprizeIntersection(SPRIZE * arg0, SO * arg1); /* 0x198FB0 FIgnoreSprizeIntersection__FP6SPRIZEP2SO */
undefined4 InitScprize(SCPRIZE * arg0); /* 0x199070 InitScprize__FP7SCPRIZE */
undefined4 CloneScprize(SCPRIZE * arg0, SCPRIZE * arg1); /* 0x1990A8 CloneScprize__FP7SCPRIZET0 */
void * PcsFromScprize(SCPRIZE * arg0); /* 0x1990E0 PcsFromScprize__FP7SCPRIZE */
undefined4 CollectScprize(SCPRIZE * arg0); /* 0x199138 CollectScprize__FP7SCPRIZE */
undefined4 LoadLockFromBrx(LOCK * arg0, CBinaryInputStream * arg1); /* 0x199170 LoadLockFromBrx__FP4LOCKP18CBinaryInputStream */
void * PostLockLoad(LOCK * arg0); /* 0x1991A8 PostLockLoad__FP4LOCK */
undefined4 LoadLockgFromBrx(LOCKG * arg0, CBinaryInputStream * arg1); /* 0x1991E0 LoadLockgFromBrx__FP5LOCKGP18CBinaryInputStream */
void * PostLockgLoad(LOCKG * arg0); /* 0x199218 PostLockgLoad__FP5LOCKG */
undefined4 SetLockgIndex(LOCKG * arg0, int arg1); /* 0x199380 SetLockgIndex__FP5LOCKGi */
undefined4 AddLockgLock(LOCKG * arg0, OID arg1); /* 0x199398 AddLockgLock__FP5LOCKG3OID */
undefined4 TriggerLockg(LOCKG * arg0); /* 0x1993C0 TriggerLockg__FP5LOCKG */
undefined4 InitClue(CLUE * arg0); /* 0x1993F0 InitClue__FP4CLUE */
undefined4 LoadClueFromBrx(CLUE * arg0, CBinaryInputStream * arg1); /* 0x199428 LoadClueFromBrx__FP4CLUEP18CBinaryInputStream */
undefined4 CloneClue(CLUE * arg0, CLUE * arg1); /* 0x1994C8 CloneClue__FP4CLUET0 */
void * PostClueLoad(CLUE * arg0); /* 0x199500 PostClueLoad__FP4CLUE */
undefined4 OnClueSmack(CLUE * arg0); /* 0x199850 OnClueSmack__FP4CLUE */
undefined4 CollectClue(CLUE * arg0); /* 0x1999D0 CollectClue__FP4CLUE */
undefined4 BreakClue(CLUE * arg0); /* 0x199AF0 BreakClue__FP4CLUE */
undefined4 CollectClueSilent(CLUE * arg0); /* 0x199B18 CollectClueSilent__FP4CLUE */
undefined4 ImpactClue(CLUE * arg0, int arg1); /* 0x199C58 ImpactClue__FP4CLUEi */
int FAbsorbClueWkr(CLUE * arg0, WKR * arg1); /* 0x199C78 FAbsorbClueWkr__FP4CLUEP3WKR */
undefined4 RenderClueAll(CLUE * arg0, CM * arg1, RO * arg2); /* 0x199D08 RenderClueAll__FP4CLUEP2CMP2RO */
undefined4 CollectAllClues(int arg0); /* 0x199F38 CollectAllClues__Fi */
undefined4 SetGrfvault(int arg0); /* 0x199FF0 SetGrfvault__Fi */
undefined4 InitVault(VAULT * arg0); /* 0x19A148 InitVault__FP5VAULT */
void * PostTmblLoad(TMBL * arg0, OID arg1); /* 0x19A178 PostTmblLoad__FP4TMBL3OID */
void * PostVaultLoad(VAULT * arg0); /* 0x19A1E0 PostVaultLoad__FP5VAULT */
undefined4 OnVaultActive(VAULT * arg0, int arg1, PO * arg2); /* 0x19A520 OnVaultActive__FP5VAULTiP2PO */
undefined4 UpdateVaultActive(VAULT * arg0, JOY * arg1, float arg2); /* 0x19A6A8 UpdateVaultActive__FP5VAULTP3JOYf */
undefined4 HandleVaultMessage(VAULT * arg0, MSGID arg1, void * arg2); /* 0x19AB78 HandleVaultMessage__FP5VAULT5MSGIDPv */
undefined4 AddVaultGoadDialog(VAULT * arg0, GOADK arg1, OID arg2); /* 0x19AD30 AddVaultGoadDialog__FP5VAULT5GOADK3OID */
undefined4 OpenVault(VAULT * arg0); /* 0x19AD68 OpenVault__FP5VAULT */
undefined4 InitRail(RAIL * arg0); /* 0x19AF00 InitRail__FP4RAIL */
undefined4 OnRailAdd(RAIL * arg0); /* 0x19AF38 OnRailAdd__FP4RAIL */
undefined4 OnRailRemove(RAIL * arg0); /* 0x19AF70 OnRailRemove__FP4RAIL */
void * PostLoadRail(RAIL * arg0); /* 0x19AFA8 PostLoadRail__FP4RAIL */
undefined4 CloneRail(RAIL * arg0, RAIL * arg1); /* 0x19AFF0 CloneRail__FP4RAILT0 */
undefined4 InitRat(RAT * arg0); /* 0x19B038 InitRat__FP3RAT */
undefined4 LoadRatFromBrx(RAT * arg0, CBinaryInputStream * arg1); /* 0x19B0A0 LoadRatFromBrx__FP3RATP18CBinaryInputStream */
void * PostRatLoad(RAT * arg0); /* 0x19B188 PostRatLoad__FP3RAT */
undefined4 OnRatAdd(RAT * arg0); /* 0x19B1E0 OnRatAdd__FP3RAT */
undefined4 OnRatRemove(RAT * arg0); /* 0x19B218 OnRatRemove__FP3RAT */
undefined4 CloneRat(RAT * arg0, RAT * arg1); /* 0x19B250 CloneRat__FP3RATT0 */
void * PresetRatAccel(RAT * arg0, float arg1); /* 0x19B298 PresetRatAccel__FP3RATf */
undefined4 UpdateRat(RAT * arg0, float arg1); /* 0x19B378 UpdateRat__FP3RATf */
undefined4 AdjustRatNewXp(RAT * arg0, XP * arg1, int arg2); /* 0x19BB10 AdjustRatNewXp__FP3RATP2XPi */
undefined4 AdjustRatXpVelocity(RAT * arg0, XP * arg1, int arg2); /* 0x19BB90 AdjustRatXpVelocity__FP3RATP2XPi */
undefined4 RenderRatAll(RAT * arg0, CM * arg1, RO * arg2); /* 0x19BC40 RenderRatAll__FP3RATP2CMP2RO */
int FAbsorbRatWkr(RAT * arg0, WKR * arg1); /* 0x19BE08 FAbsorbRatWkr__FP3RATP3WKR */
undefined4 ChooseRatFleeTarget(RAT * arg0); /* 0x19BE80 ChooseRatFleeTarget__FP3RAT */
undefined4 HideRat(RAT * arg0, int arg1); /* 0x19C068 HideRat__FP3RATi */
undefined4 SetRatRats(RAT * arg0, RATS arg1); /* 0x19C1C0 SetRatRats__FP3RAT4RATS */
undefined4 OnRatholeAdd(RATHOLE * arg0); /* 0x19C3D0 OnRatholeAdd__FP7RATHOLE */
undefined4 OnRatholeRemove(RATHOLE * arg0); /* 0x19C408 OnRatholeRemove__FP7RATHOLE */
undefined4 InitRchm(RCHM * arg0); /* 0x19C440 InitRchm__FP4RCHM */
undefined4 LoadRchmFromBrx(RCHM * arg0, CBinaryInputStream * arg1); /* 0x19C470 LoadRchmFromBrx__FP4RCHMP18CBinaryInputStream */
void * PostRchmLoad(RCHM * arg0); /* 0x19C728 PostRchmLoad__FP4RCHM */
undefined4 ReblendRchm(RCHM * arg0, TWR * arg1, VECTOR * arg2); /* 0x19C9C8 ReblendRchm__FP4RCHMP3TWRP6VECTOR */
undefined4 BuildRchmCoefficients(RCHM * arg0, float arg1, float arg2, float arg3, float * arg4); /* 0x19CC10 BuildRchmCoefficients__FP4RCHMfffPf */
undefined4 ConvertRchmIposToRclIoLhub(RCHM * arg0, int arg1, float * arg2, float * arg3, float * arg4); /* 0x19CD90 ConvertRchmIposToRclIoLhub__FP4RCHMiPfN22 */
undefined4 SetRchmNaturalCoefficients(RCHM * arg0, float arg1, float arg2, float arg3); /* 0x19CE28 SetRchmNaturalCoefficients__FP4RCHMfff */
undefined4 SetRchmCenterCoefficients(RCHM * arg0, float arg1, float arg2, float arg3); /* 0x19CE38 SetRchmCenterCoefficients__FP4RCHMfff */
void * PredictRchmTargetPos(RCHM * arg0, TARGET * arg1, float arg2, VECTOR * arg3); /* 0x19CE50 PredictRchmTargetPos__FP4RCHMP6TARGETfP6VECTOR */
void * PredictRchmTargetLocalPos(RCHM * arg0, TARGET * arg1, float arg2, VECTOR * arg3); /* 0x19CEC0 PredictRchmTargetLocalPos__FP4RCHMP6TARGETfP6VECTOR */
void * PtwrMapRchmSafe(RCHM * arg0, BSP * arg1, VECTOR * arg2); /* 0x19CF68 PtwrMapRchmSafe__FP4RCHMP3BSPP6VECTOR */
undefined4 FindRchmClosestPoint(RCHM * arg0, VECTOR * arg1, VECTOR * arg2, TWR * * arg3, float * arg4); /* 0x19D0E0 FindRchmClosestPoint__FP4RCHMP6VECTORT1PP3TWRPf */
undefined4 TrackJtTarget(JT * arg0, RCHM * arg1, TARGET * arg2); /* 0x19D2A8 TrackJtTarget__FP2JTP4RCHMP6TARGET */
undefined4 TrackJtPipe(JT * arg0, RCHM * arg1, PIPE * arg2, float * arg3); /* 0x19D338 TrackJtPipe__FP2JTP4RCHMP4PIPEPf */
undefined4 SubmitRpl(RPL * arg0); /* 0x19D410 SubmitRpl__FP3RPL */
undefined4 NCmpPrplReverseZ(RPL * * arg0, RPL * * arg1); /* 0x19D468 NCmpPrplReverseZ__FPP3RPLT0 */
undefined4 CprplPartitionArpl(int arg0, RPL * arg1, RPL * * arg2); /* 0x19D4B0 CprplPartitionArpl__FiP3RPLPP3RPL */
undefined4 RenderSw(SW * arg0, CM * arg1); /* 0x19D6C0 RenderSw__FP2SWP2CM */
undefined4 EnsureRenderGlobals(void); /* 0x19D860 EnsureRenderGlobals__Fv */
undefined4 EnsureCameraGlobals(void); /* 0x19D930 EnsureCameraGlobals__Fv */
undefined4 EnsureScreenCleared(void); /* 0x19D968 EnsureScreenCleared__Fv */
undefined4 SetupRpDynamicTexture(RPL * arg0); /* 0x19DA30 SetupRpDynamicTexture__FP3RPL */
undefined4 SetupRpBackground(RPL * arg0); /* 0x19DA60 SetupRpBackground__FP3RPL */
undefined4 SetupRpBlotContext(RPL * arg0); /* 0x19DAD8 SetupRpBlotContext__FP3RPL */
undefined4 SetupRpGlob(RPL * arg0); /* 0x19DB20 SetupRpGlob__FP3RPL */
undefined4 SetupRpBlip(RPL * arg0); /* 0x19DB68 SetupRpBlip__FP3RPL */
undefined4 SetupRpWorldMap(RPL * arg0); /* 0x19DBB0 SetupRpWorldMap__FP3RPL */
undefined4 DrawSw(SW * arg0, CM * arg1); /* 0x19DC98 DrawSw__FP2SWP2CM */
undefined4 FillScreenRect(int arg0, int arg1, int arg2, int arg3, float arg4, float arg5, float arg6, float arg7, GIFS * arg8); /* 0x19DDA0 FillScreenRect__FiiiiffffP4GIFS */
undefined4 StartupRender(void); /* 0x19DF48 StartupRender__Fv */
void * PripgNew(SW * arg0, RIPGT arg1); /* 0x19E040 PripgNew__FP2SW5RIPGT */
undefined4 InitRipg(RIPG * arg0); /* 0x19E0B8 InitRipg__FP4RIPG */
undefined4 SetRipgEmitb(RIPG * arg0, EMITB * arg1); /* 0x19E158 SetRipgEmitb__FP4RIPGP5EMITB */
undefined4 OnRipgRemove(RIPG * arg0); /* 0x19E168 OnRipgRemove__FP4RIPG */
void * ProjectRipgTransform(RIPG * arg0, float arg1, int arg2); /* 0x19E220 ProjectRipgTransform__FP4RIPGfi */
undefined4 UpdateRipgBounds(RIPG * arg0); /* 0x19E418 UpdateRipgBounds__FP4RIPG */
undefined4 BounceRipgRips(RIPG * arg0); /* 0x19E558 BounceRipgRips__FP4RIPG */
undefined4 RenderRipgSelf(RIPG * arg0, CM * arg1, RO * arg2); /* 0x19E848 RenderRipgSelf__FP4RIPGP2CMP2RO */
void * PvtripFromRipt(RIPT arg0); /* 0x19E908 PvtripFromRipt__F4RIPT */
void * PripNewRipg(RIPT arg0, RIPG * arg1); /* 0x19EA78 PripNewRipg__F4RIPTP4RIPG */
undefined4 InitRip(RIP * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x19EB28 InitRip__FP3RIPP6VECTORfP2SO */
undefined4 RemoveRip(RIP * arg0); /* 0x19EBE8 RemoveRip__FP3RIP */
undefined4 AddRipRef(RIP * arg0); /* 0x19EC20 AddRipRef__FP3RIP */
undefined4 ReleaseRip(RIP * arg0); /* 0x19EC30 ReleaseRip__FP3RIP */
undefined4 TouchRip(RIP * arg0, int arg1); /* 0x19ECE0 TouchRip__FP3RIPi */
undefined4 ForceRipFade(RIP * arg0, float arg1); /* 0x19ED00 ForceRipFade__FP3RIPf */
int FBounceRip(RIP * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x19ED58 FBounceRip__FP3RIPP2SOP6VECTORT2 */
void * ProjectRipTransform(RIP * arg0, float arg1); /* 0x19F390 ProjectRipTransform__FP3RIPf */
undefined4 UpdateRip(RIP * arg0, float arg1); /* 0x19F560 UpdateRip__FP3RIPf */
int FRenderRipPosMat(RIP * arg0, CM * arg1, VECTOR * arg2, MATRIX3 * arg3); /* 0x19F620 FRenderRipPosMat__FP3RIPP2CMP6VECTORP7MATRIX3 */
undefined4 RenderRip(RIP * arg0, CM * arg1); /* 0x19F858 RenderRip__FP3RIPP2CM */
undefined4 SubscribeRipObject(RIP * arg0, LO * arg1); /* 0x19F8E8 SubscribeRipObject__FP3RIPP2LO */
undefined4 SubscribeRipStruct(RIP * arg0, void (*arg1)(void *, MSGID, void *), void * arg2); /* 0x19F918 SubscribeRipStruct__FP3RIPPFPv5MSGIDPv_vPv */
undefined4 UnsubscribeRipStruct(RIP * arg0, void (*arg1)(void *, MSGID, void *), void * arg2); /* 0x19F950 UnsubscribeRipStruct__FP3RIPPFPv5MSGIDPv_vPv */
undefined4 InitDroplet(DROPLET * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x19F988 InitDroplet__FP7DROPLETP6VECTORfP2SO */
undefined4 TouchDroplet(DROPLET * arg0, int arg1); /* 0x19F9D0 TouchDroplet__FP7DROPLETi */
undefined4 InitBublet(BUBLET * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x19FA98 InitBublet__FP6BUBLETP6VECTORfP2SO */
void * ProjectBubletTransform(BUBLET * arg0, float arg1); /* 0x19FB08 ProjectBubletTransform__FP6BUBLETf */
undefined4 TouchBublet(BUBLET * arg0, int arg1); /* 0x19FCE8 TouchBublet__FP6BUBLETi */
undefined4 InitRipple(RIPPLE * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x19FD08 InitRipple__FP6RIPPLEP6VECTORfP2SO */
undefined4 InitPuff(PUFF * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x19FD70 InitPuff__FP4PUFFP6VECTORfP2SO */
undefined4 InitDablet(DABLET * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x19FDC0 InitDablet__FP6DABLETP6VECTORfP2SO */
undefined4 InitFlake(FLAKE * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x19FE10 InitFlake__FP5FLAKEP6VECTORfP2SO */
undefined4 UpdateFlake(FLAKE * arg0, float arg1); /* 0x19FE50 UpdateFlake__FP5FLAKEf */
undefined4 RenderFlake(FLAKE * arg0, CM * arg1); /* 0x19FF20 RenderFlake__FP5FLAKEP2CM */
undefined4 TouchFlake(FLAKE * arg0, int arg1); /* 0x1A0020 TouchFlake__FP5FLAKEi */
undefined4 InitSpark(SPARK * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A0040 InitSpark__FP5SPARKP6VECTORfP2SO */
undefined4 RenderSpark(SPARK * arg0, CM * arg1); /* 0x1A00A0 RenderSpark__FP5SPARKP2CM */
undefined4 InitBurst(BURST * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A01B8 InitBurst__FP5BURSTP6VECTORfP2SO */
undefined4 InitTrail(TRAIL * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A0258 InitTrail__FP5TRAILP6VECTORfP2SO */
undefined4 OnTrailRemove(TRAIL * arg0); /* 0x1A0318 OnTrailRemove__FP5TRAIL */
undefined4 SetTrailTrls(TRAIL * arg0, TRLS arg1, void * arg2); /* 0x1A0338 SetTrailTrls__FP5TRAIL4TRLSPv */
undefined4 DetachTrail(TRAIL * arg0); /* 0x1A04A0 DetachTrail__FP5TRAIL */
void * ProjectTrailTransform(TRAIL * arg0, float arg1); /* 0x1A05D8 ProjectTrailTransform__FP5TRAILf */
undefined4 RenderTrail(TRAIL * arg0, CM * arg1); /* 0x1A0758 RenderTrail__FP5TRAILP2CM */
undefined4 HandleTrailMessage(TRAIL * arg0, MSGID arg1, void * arg2); /* 0x1A0950 HandleTrailMessage__FP5TRAIL5MSGIDPv */
undefined4 InitFireball(FIREBALL * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A09C0 InitFireball__FP8FIREBALLP6VECTORfP2SO */
undefined4 UpdateFireball(FIREBALL * arg0, float arg1); /* 0x1A0A78 UpdateFireball__FP8FIREBALLf */
undefined4 InitSmokecloud(SMOKECLOUD * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A0B20 InitSmokecloud__FP10SMOKECLOUDP6VECTORfP2SO */
undefined4 InitSmoketrail(SMOKETRAIL * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A0BA0 InitSmoketrail__FP10SMOKETRAILP6VECTORfP2SO */
undefined4 InitDebris(DEBRIS * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A0C50 InitDebris__FP6DEBRISP6VECTORfP2SO */
undefined4 InitSmack(SMACK * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A0C98 InitSmack__FP5SMACKP6VECTORfP2SO */
void * ProjectSmackTransform(SMACK * arg0, float arg1); /* 0x1A0D60 ProjectSmackTransform__FP5SMACKf */
undefined4 RenderSmack(SMACK * arg0, CM * arg1); /* 0x1A0DF0 RenderSmack__FP5SMACKP2CM */
undefined4 UpdateSmack(SMACK * arg0, float arg1); /* 0x1A0F88 UpdateSmack__FP5SMACKf */
undefined4 InitOrbit(ORBIT * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A0FE8 InitOrbit__FP5ORBITP6VECTORfP2SO */
void * ProjectOrbitTransform(ORBIT * arg0, float arg1); /* 0x1A1030 ProjectOrbitTransform__FP5ORBITf */
undefined4 UpdateOrbit(ORBIT * arg0, float arg1); /* 0x1A11C0 UpdateOrbit__FP5ORBITf */
undefined4 RenderOrbit(ORBIT * arg0, CM * arg1); /* 0x1A1398 RenderOrbit__FP5ORBITP2CM */
undefined4 InitRay(RAY * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A1410 InitRay__FP3RAYP6VECTORfP2SO */
undefined4 InitRose(ROSE * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A1458 InitRose__FP4ROSEP6VECTORfP2SO */
void * ProjectRoseTransform(ROSE * arg0, float arg1); /* 0x1A1498 ProjectRoseTransform__FP4ROSEf */
undefined4 UpdateRose(ROSE * arg0, float arg1); /* 0x1A14A0 UpdateRose__FP4ROSEf */
undefined4 RenderRose(ROSE * arg0, CM * arg1); /* 0x1A15D8 RenderRose__FP4ROSEP2CM */
undefined4 SetRoseRoses(ROSE * arg0, ROSES arg1); /* 0x1A1DF0 SetRoseRoses__FP4ROSE5ROSES */
undefined4 SgnCmpHp(const void * arg0, const void * arg1); /* 0x1A1F18 SgnCmpHp__FPCvT0 */
undefined4 ChpBuildConvexHullScreen(VECTOR * arg0, int arg1, HP * arg2); /* 0x1A1F40 ChpBuildConvexHullScreen__FP6VECTORiP2HP */
undefined4 ChpBuildConvexHullXY(MATRIX4 * arg0, int arg1, HP * arg2); /* 0x1A2070 ChpBuildConvexHullXY__FP7MATRIX4iP2HP */
void * PostFlyingEmit(FLYING * arg0, EMITB * arg1); /* 0x1A22C8 PostFlyingEmit__FP6FLYINGP5EMITB */
undefined4 RenderFlying(FLYING * arg0, CM * arg1); /* 0x1A22E0 RenderFlying__FP6FLYINGP2CM */
undefined4 CreateStuck(RIP * arg0, ALO * arg1, SO * arg2, VECTOR * arg3, VECTOR * arg4, STUCK * * arg5); /* 0x1A2380 CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK */
int FBounceFlying(FLYING * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1A25F0 FBounceFlying__FP6FLYINGP2SOP6VECTORT2 */
undefined4 UpdateStuck(STUCK * arg0, float arg1); /* 0x1A26B0 UpdateStuck__FP5STUCKf */
undefined4 RenderStuck(STUCK * arg0, CM * arg1); /* 0x1A26F8 RenderStuck__FP5STUCKP2CM */
void * PostLeafEmit(LEAF * arg0, EMITB * arg1); /* 0x1A2770 PostLeafEmit__FP4LEAFP5EMITB */
void * ProjectLeafTransform(LEAF * arg0, float arg1); /* 0x1A2830 ProjectLeafTransform__FP4LEAFf */
int FBounceLeaf(LEAF * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1A2A68 FBounceLeaf__FP4LEAFP2SOP6VECTORT2 */
int FFilterFlameObjects(void * arg0, SO * arg1); /* 0x1A2B18 FFilterFlameObjects__FPvP2SO */
void * PostFlameEmit(FLAME * arg0, EMITB * arg1); /* 0x1A2B48 PostFlameEmit__FP5FLAMEP5EMITB */
void * PostBulletEmit(BULLET * arg0, EMITB * arg1); /* 0x1A2D30 PostBulletEmit__FP6BULLETP5EMITB */
undefined4 RenderBullet(BULLET * arg0, CM * arg1); /* 0x1A2D88 RenderBullet__FP6BULLETP2CM */
int FBounceBullet(BULLET * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1A2E68 FBounceBullet__FP6BULLETP2SOP6VECTORT2 */
void * PostShrapnelEmit(SHRAPNEL * arg0, EMITB * arg1); /* 0x1A3008 PostShrapnelEmit__FP8SHRAPNELP5EMITB */
int FBounceShrapnel(SHRAPNEL * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1A3128 FBounceShrapnel__FP8SHRAPNELP2SOP6VECTORT2 */
undefined4 RenderShrapnel(SHRAPNEL * arg0, CM * arg1); /* 0x1A31A0 RenderShrapnel__FP8SHRAPNELP2CM */
undefined4 InitGlint(GLINT * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A31F0 InitGlint__FP5GLINTP6VECTORfP2SO */
undefined4 RenderGlint(GLINT * arg0, CM * arg1); /* 0x1A3250 RenderGlint__FP5GLINTP2CM */
undefined4 InitMatch(MATCH * arg0, VECTOR * arg1, float arg2, SO * arg3); /* 0x1A3598 InitMatch__FP5MATCHP6VECTORfP2SO */
undefined4 LaunchMatch(MATCH * arg0); /* 0x1A35F0 LaunchMatch__FP5MATCH */
void * ProjectMatchTransform(MATCH * arg0, float arg1); /* 0x1A3730 ProjectMatchTransform__FP5MATCHf */
undefined4 UpdateMatch(MATCH * arg0, float arg1); /* 0x1A38F0 UpdateMatch__FP5MATCHf */
undefined4 RenderMatch(MATCH * arg0, CM * arg1); /* 0x1A3990 RenderMatch__FP5MATCHP2CM */
void * PostRemitEmit(REMIT * arg0, EMITB * arg1); /* 0x1A39C8 PostRemitEmit__FP5REMITP5EMITB */
undefined4 UpdateRemit(REMIT * arg0, float arg1); /* 0x1A3A18 UpdateRemit__FP5REMITf */
undefined4 InitRov(ROV * arg0); /* 0x1A3AE0 InitRov__FP3ROV */
undefined4 LoadRovFromBrx(ROV * arg0, CBinaryInputStream * arg1); /* 0x1A3B20 LoadRovFromBrx__FP3ROVP18CBinaryInputStream */
void * PostRovLoad(ROV * arg0); /* 0x1A3B58 PostRovLoad__FP3ROV */
undefined4 UpdateRovActive(ROV * arg0, JOY * arg1, float arg2); /* 0x1A3C40 UpdateRovActive__FP3ROVP3JOYf */
undefined4 UpdateRov(ROV * arg0, float arg1); /* 0x1A3D40 UpdateRov__FP3ROVf */
undefined4 ReadRovJoystick(ROV * arg0, JOY * arg1); /* 0x1A3F40 ReadRovJoystick__FP3ROVP3JOY */
undefined4 RovsNextRov(ROV * arg0); /* 0x1A3FE0 RovsNextRov__FP3ROV */
undefined4 SetRovRovs(ROV * arg0, ROVS arg1); /* 0x1A4070 SetRovRovs__FP3ROV4ROVS */
undefined4 RovtsNextRov(ROV * arg0); /* 0x1A4258 RovtsNextRov__FP3ROV */
undefined4 SetRovRovts(ROV * arg0, ROVTS arg1); /* 0x1A42C8 SetRovRovts__FP3ROV5ROVTS */
undefined4 HandleRovMessage(ROV * arg0, MSGID arg1, void * arg2); /* 0x1A43C8 HandleRovMessage__FP3ROV5MSGIDPv */
void * PresetRovAccel(ROV * arg0, float arg1); /* 0x1A44E8 PresetRovAccel__FP3ROVf */
undefined4 AdjustRovXpVelocity(ROV * arg0, XP * arg1, int arg2); /* 0x1A4538 AdjustRovXpVelocity__FP3ROVP2XPi */
undefined4 AdjustRovNewXp(ROV * arg0, XP * arg1, int arg2); /* 0x1A45B8 AdjustRovNewXp__FP3ROVP2XPi */
undefined4 PropagateRovForce(ROV * arg0, int arg1, XP * arg2, int arg3, DZ * arg4, FX * arg5); /* 0x1A4610 PropagateRovForce__FP3ROViP2XPiP2DZP2FX */
int FIsRovSoundBase(ROV * arg0); /* 0x1A4710 FIsRovSoundBase__FP3ROV */
undefined4 InitRob(ROB * arg0); /* 0x1A4718 InitRob__FP3ROB */
undefined4 SetRobCollectible(ROB * arg0, OID arg1); /* 0x1A4858 SetRobCollectible__FP3ROB3OID */
undefined4 SetRobHarvester(ROB * arg0, OID arg1); /* 0x1A4860 SetRobHarvester__FP3ROB3OID */
undefined4 SetRobVehicle(ROB * arg0, OID arg1); /* 0x1A4868 SetRobVehicle__FP3ROB3OID */
undefined4 SetRobPrize(ROB * arg0, OID arg1); /* 0x1A4870 SetRobPrize__FP3ROB3OID */
undefined4 AddRobSpawnTunnel(ROB * arg0, OID arg1); /* 0x1A4878 AddRobSpawnTunnel__FP3ROB3OID */
undefined4 RobkCur(void); /* 0x1A4898 RobkCur__Fv */
undefined4 BindRob(ROB * arg0); /* 0x1A48C0 BindRob__FP3ROB */
void * PostRobLoad(ROB * arg0); /* 0x1A4B30 PostRobLoad__FP3ROB */
undefined4 UpdateRob(ROB * arg0, float arg1); /* 0x1A4C48 UpdateRob__FP3ROBf */
undefined4 RobsNextRob(ROB * arg0); /* 0x1A4DC0 RobsNextRob__FP3ROB */
undefined4 SetRobRobs(ROB * arg0, ROBS arg1); /* 0x1A4EF0 SetRobRobs__FP3ROB4ROBS */
undefined4 AddRobRoc(ROB * arg0); /* 0x1A5120 AddRobRoc__FP3ROB */
undefined4 AddRobRoh(ROB * arg0); /* 0x1A54F8 AddRobRoh__FP3ROB */
undefined4 AdjustRobDifficulty(ROB * arg0, float arg1); /* 0x1A5760 AdjustRobDifficulty__FP3ROBf */
undefined4 DestroyedRobRoc(ROB * arg0, ROC * arg1); /* 0x1A5B28 DestroyedRobRoc__FP3ROBP3ROC */
undefined4 SpawnedRobRoh(ROB * arg0, ROH * arg1); /* 0x1A5C38 SpawnedRobRoh__FP3ROBP3ROH */
undefined4 GrabbedRobRoh(ROB * arg0, ROH * arg1); /* 0x1A5C90 GrabbedRobRoh__FP3ROBP3ROH */
undefined4 DroppedRobRoh(ROB * arg0, ROH * arg1); /* 0x1A5D50 DroppedRobRoh__FP3ROBP3ROH */
undefined4 ReturnedRobRoh(ROB * arg0, ROH * arg1); /* 0x1A5DD8 ReturnedRobRoh__FP3ROBP3ROH */
undefined4 ExitedRobRoh(ROB * arg0, ROH * arg1); /* 0x1A5DF8 ExitedRobRoh__FP3ROBP3ROH */
undefined4 KilledRobRoh(ROB * arg0, ROH * arg1); /* 0x1A5F78 KilledRobRoh__FP3ROBP3ROH */
int FChooseRobRoc(ROB * arg0, ROH * arg1); /* 0x1A6090 FChooseRobRoc__FP3ROBP3ROH */
undefined4 TakeRobRoc(ROB * arg0, ROH * arg1, ROC * arg2); /* 0x1A6168 TakeRobRoc__FP3ROBP3ROHP3ROC */
int FChooseRobRoh(ROB * arg0, ROC * arg1); /* 0x1A6238 FChooseRobRoh__FP3ROBP3ROC */
int FChooseRobReturnPoint(ROB * arg0, ROH * arg1); /* 0x1A6328 FChooseRobReturnPoint__FP3ROBP3ROH */
undefined4 ChooseRobWanderLocation(ROB * arg0, ROH * arg1); /* 0x1A63F8 ChooseRobWanderLocation__FP3ROBP3ROH */
void * ProddCurRob(ROB * arg0, ENSK arg1); /* 0x1A6480 ProddCurRob__FP3ROB4ENSK */
undefined4 InitRoh(ROH * arg0); /* 0x1A6498 InitRoh__FP3ROH */
undefined4 LoadRohFromBrx(ROH * arg0, CBinaryInputStream * arg1); /* 0x1A64F8 LoadRohFromBrx__FP3ROHP18CBinaryInputStream */
undefined4 CloneRoh(ROH * arg0, ROH * arg1); /* 0x1A6540 CloneRoh__FP3ROHT0 */
void * PostRohLoad(ROH * arg0); /* 0x1A6588 PostRohLoad__FP3ROH */
undefined4 UpdateRoh(ROH * arg0, float arg1); /* 0x1A65C8 UpdateRoh__FP3ROHf */
undefined4 MoveRohToTarget(ROH * arg0, VECTOR * arg1, int arg2); /* 0x1A6788 MoveRohToTarget__FP3ROHP6VECTORi */
undefined4 RohsNextRoh(ROH * arg0); /* 0x1A69F8 RohsNextRoh__FP3ROH */
undefined4 SetRohRohs(ROH * arg0, ROHS arg1); /* 0x1A6BE0 SetRohRohs__FP3ROH4ROHS */
int FAbsorbRohWkr(ROH * arg0, WKR * arg1); /* 0x1A6DE0 FAbsorbRohWkr__FP3ROHP3WKR */
void * ProcContactRoh(ROH * arg0); /* 0x1A6F28 ProcContactRoh__FP3ROH */
undefined4 InitRoc(ROC * arg0); /* 0x1A6F88 InitRoc__FP3ROC */
undefined4 LoadRocFromBrx(ROC * arg0, CBinaryInputStream * arg1); /* 0x1A7008 LoadRocFromBrx__FP3ROCP18CBinaryInputStream */
undefined4 CloneRoc(ROC * arg0, ROC * arg1); /* 0x1A7050 CloneRoc__FP3ROCT0 */
void * PostRocLoad(ROC * arg0); /* 0x1A7098 PostRocLoad__FP3ROC */
undefined4 UpdateRoc(ROC * arg0, float arg1); /* 0x1A7128 UpdateRoc__FP3ROCf */
void * PresetRocAccel(ROC * arg0, float arg1); /* 0x1A7230 PresetRocAccel__FP3ROCf */
undefined4 AdjustRocNewXp(ROC * arg0, XP * arg1, int arg2); /* 0x1A7290 AdjustRocNewXp__FP3ROCP2XPi */
int FAbsorbRocWkr(ROC * arg0, WKR * arg1); /* 0x1A72B0 FAbsorbRocWkr__FP3ROCP3WKR */
undefined4 RocsNextRoc(ROC * arg0); /* 0x1A7420 RocsNextRoc__FP3ROC */
undefined4 SetRocRocs(ROC * arg0, ROCS arg1); /* 0x1A7480 SetRocRocs__FP3ROC4ROCS */
undefined4 InitRost(ROST * arg0); /* 0x1A7520 InitRost__FP4ROST */
undefined4 LoadRostFromBrx(ROST * arg0, CBinaryInputStream * arg1); /* 0x1A7550 LoadRostFromBrx__FP4ROSTP18CBinaryInputStream */
undefined4 CloneRost(ROST * arg0, ROST * arg1); /* 0x1A7588 CloneRost__FP4ROSTT0 */
void * PostRostLoad(ROST * arg0); /* 0x1A75D0 PostRostLoad__FP4ROST */
undefined4 UpdateRost(ROST * arg0, float arg1); /* 0x1A7648 UpdateRost__FP4ROSTf */
undefined4 RostsNextRost(ROST * arg0); /* 0x1A7698 RostsNextRost__FP4ROST */
undefined4 SetRostRosts(ROST * arg0, ROSTS arg1); /* 0x1A76A0 SetRostRosts__FP4ROST5ROSTS */
undefined4 InitRop(ROP * arg0); /* 0x1A7708 InitRop__FP3ROP */
undefined4 LoadRopFromBrx(ROP * arg0, CBinaryInputStream * arg1); /* 0x1A7750 LoadRopFromBrx__FP3ROPP18CBinaryInputStream */
void * PostRopLoad(ROP * arg0); /* 0x1A7798 PostRopLoad__FP3ROP */
undefined4 UpdateRop(ROP * arg0, float arg1); /* 0x1A7800 UpdateRop__FP3ROPf */
undefined4 SetRopRops(ROP * arg0, ROPS arg1); /* 0x1A7998 SetRopRops__FP3ROP4ROPS */
undefined4 RopsNextRop(ROP * arg0); /* 0x1A7AA0 RopsNextRop__FP3ROP */
undefined4 InitRumble(RUMBLE * arg0, int arg1, int arg2); /* 0x1A7B20 InitRumble__FP6RUMBLEii */
undefined4 UpdateRumble(RUMBLE * arg0); /* 0x1A7B88 UpdateRumble__FP6RUMBLE */
undefined4 TriggerRumbleRumk(RUMBLE * arg0, RUMK arg1, float arg2); /* 0x1A7CE8 TriggerRumbleRumk__FP6RUMBLE4RUMKf */
undefined4 TriggerRumbleRumpat(RUMBLE * arg0, RUMPAT * arg1, float arg2); /* 0x1A7D18 TriggerRumbleRumpat__FP6RUMBLEP6RUMPATf */
undefined4 SetRumbleRums(RUMBLE * arg0, RUMS arg1); /* 0x1A7D98 SetRumbleRums__FP6RUMBLE4RUMS */
undefined4 StopRumbleActuators(RUMBLE * arg0); /* 0x1A7E40 StopRumbleActuators__FP6RUMBLE */
undefined4 RumbleUnknown1(void); /* 0x1A7E70 RumbleUnknown1__Fv */
undefined4 RumbleUnknown2(GS * arg0); /* 0x1A7E90 RumbleUnknown2__FP2GS */
undefined4 RumbleUnknown3(GS * arg0); /* 0x1A7EE8 RumbleUnknown3__FP2GS */
undefined4 RumbleUnknown4(GS * arg0); /* 0x1A7F50 RumbleUnknown4__FP2GS */
undefined4 InitRwm(RWM * arg0); /* 0x1A7FE8 InitRwm__FP3RWM */
undefined4 OnRwmRemove(RWM * arg0); /* 0x1A80E0 OnRwmRemove__FP3RWM */
undefined4 InitRwmCallback(RWM * arg0, MSGID arg1, void * arg2); /* 0x1A8208 InitRwmCallback__FP3RWM5MSGIDPv */
void * PostRwmLoad(RWM * arg0); /* 0x1A8590 PostRwmLoad__FP3RWM */
void * PrwcFindRwm(RWM * arg0, OID arg1); /* 0x1A8718 PrwcFindRwm__FP3RWM3OID */
undefined4 EnableRwmRwc(RWM * arg0, OID arg1); /* 0x1A8778 EnableRwmRwc__FP3RWM3OID */
undefined4 DisableRwmRwc(RWM * arg0, OID arg1); /* 0x1A87A8 DisableRwmRwc__FP3RWM3OID */
undefined4 ResizeRwmRwc(RWM * arg0, OID arg1, int arg2); /* 0x1A87E0 ResizeRwmRwc__FP3RWM3OIDi */
int FIsRwmAmmo(RWM * arg0, SO * arg1); /* 0x1A8820 FIsRwmAmmo__FP3RWMP2SO */
int FAvailableRwmAmmo(RWM * arg0, SO * arg1); /* 0x1A88A0 FAvailableRwmAmmo__FP3RWMP2SO */
undefined4 CycleRwmCache(RWM * arg0); /* 0x1A89E8 CycleRwmCache__FP3RWM */
undefined4 ReloadRwm(RWM * arg0); /* 0x1A8AF8 ReloadRwm__FP3RWM */
int FEnsureRwmLoaded(RWM * arg0); /* 0x1A8C50 FEnsureRwmLoaded__FP3RWM */
int FFireRwm(RWM * arg0, int arg1); /* 0x1A8C90 FFireRwm__FP3RWMi */
undefined4 ClearRwmFireInfo(RWM * arg0); /* 0x1A93E8 ClearRwmFireInfo__FP3RWM */
undefined4 ClearRwmTargetInfo(RWM * arg0); /* 0x1A9438 ClearRwmTargetInfo__FP3RWM */
undefined4 ClearRwmAimConstraints(RWM * arg0); /* 0x1A9498 ClearRwmAimConstraints__FP3RWM */
undefined4 GetRwfiPosMat(RWFI * arg0, VECTOR * arg1, MATRIX3 * arg2); /* 0x1A94C0 GetRwfiPosMat__FP4RWFIP6VECTORP7MATRIX3 */
undefined4 GetRwtiPos(RWTI * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x1A95D0 GetRwtiPos__FP4RWTIP6VECTORT1 */
undefined4 GetRwacPan(RWAC * arg0, float * arg1); /* 0x1A97C8 GetRwacPan__FP4RWACPf */
undefined4 GetRwacTilt(RWAC * arg0, float * arg1); /* 0x1A9868 GetRwacTilt__FP4RWACPf */
void * PostSbgLoad(SBG * arg0); /* 0x1A98F8 PostSbgLoad__FP3SBG */
int FUN_001a9928(SBG * arg0); /* 0x1A9928 FUN_001a9928__FP3SBG */
undefined4 UpdateSbgGoal(SBG * arg0, int arg1); /* 0x1A9960 UpdateSbgGoal__FP3SBGi */
undefined4 UpdateSbgSgs(SBG * arg0); /* 0x1A99B8 UpdateSbgSgs__FP3SBG */
undefined4 OnSbgEnteringSgs(SBG * arg0, SGS arg1, ASEG * arg2); /* 0x1A99F8 OnSbgEnteringSgs__FP3SBG3SGSP4ASEG */
undefined4 UpdateSbg(SBG * arg0, float arg1); /* 0x1A9A40 UpdateSbg__FP3SBGf */
int FUN_001a9a98(void); /* 0x1A9A98 FUN_001a9a98__Fv */
int FAbsorbSbgWkr(SBG * arg0, WKR * arg1); /* 0x1A9AE8 FAbsorbSbgWkr__FP3SBGP3WKR */
int FUN_001a9c58(SBG * arg0, int arg1, int arg2, int arg3); /* 0x1A9C58 FUN_001a9c58__FP3SBGiii */
undefined4 StartupScreen(void); /* 0x1A9C68 StartupScreen__Fv */
void * PostBlotsLoad(void); /* 0x1A9F78 PostBlotsLoad__Fv */
undefined4 UpdateBlots(void); /* 0x1A9FD0 UpdateBlots__Fv */
undefined4 ForceHideBlots(void); /* 0x1AA060 ForceHideBlots__Fv */
undefined4 ResetBlots(void); /* 0x1AA0C0 ResetBlots__Fv */
undefined4 RenderBlots(void); /* 0x1AA110 RenderBlots__Fv */
undefined4 DrawBlots(void); /* 0x1AA178 DrawBlots__Fv */
undefined4 InitBlot(BLOT * arg0, BLOTK arg1); /* 0x1AA1F0 InitBlot__FP4BLOT5BLOTK */
void * PostBlotLoad(BLOT * arg0); /* 0x1AA268 PostBlotLoad__FP4BLOT */
undefined4 UpdateBlot(BLOT * arg0); /* 0x1AA298 UpdateBlot__FP4BLOT */
undefined4 SetBlotAchzDraw(BLOT * arg0, char * arg1); /* 0x1AA4F0 SetBlotAchzDraw__FP4BLOTPc */
undefined4 SetBlotRgba(BLOT * arg0, unsigned int arg1); /* 0x1AA5A0 SetBlotRgba__FP4BLOTUi */
undefined4 SetBlotFontScale(BLOT * arg0, float arg1); /* 0x1AA788 SetBlotFontScale__FP4BLOTf */
undefined4 DrawBlot(BLOT * arg0); /* 0x1AA790 DrawBlot__FP4BLOT */
undefined4 DtAppearBlot(BLOT * arg0); /* 0x1AA898 DtAppearBlot__FP4BLOT */
undefined4 DtVisibleBlot(BLOT * arg0); /* 0x1AA8A0 DtVisibleBlot__FP4BLOT */
undefined4 DtDisappearBlot(BLOT * arg0); /* 0x1AA8A8 DtDisappearBlot__FP4BLOT */
undefined4 SetBlotDtAppear(BLOT * arg0, float arg1); /* 0x1AA8B0 SetBlotDtAppear__FP4BLOTf */
undefined4 SetBlotDtVisible(BLOT * arg0, float arg1); /* 0x1AA8B8 SetBlotDtVisible__FP4BLOTf */
undefined4 SetBlotDtDisappear(BLOT * arg0, float arg1); /* 0x1AA8C0 SetBlotDtDisappear__FP4BLOTf */
undefined4 OnBlotReset(BLOT * arg0); /* 0x1AA8C8 OnBlotReset__FP4BLOT */
undefined4 ShowBlot(BLOT * arg0); /* 0x1AA8F0 ShowBlot__FP4BLOT */
undefined4 HideBlot(BLOT * arg0); /* 0x1AA958 HideBlot__FP4BLOT */
undefined4 SetBlotBlots(BLOT * arg0, BLOTS arg1); /* 0x1AA998 SetBlotBlots__FP4BLOT5BLOTS */
int FIncludeBlotForPeg(BLOT * arg0, BLOT * arg1); /* 0x1AAAC8 FIncludeBlotForPeg__FP4BLOTT0 */
undefined4 ResizeBlot(BLOT * arg0, float arg1, float arg2); /* 0x1AAB20 ResizeBlot__FP4BLOTff */
undefined4 RepositionBlot(BLOT * arg0); /* 0x1AAB60 RepositionBlot__FP4BLOT */
undefined4 RepositionBlotDependents(BLOT * arg0); /* 0x1AAEC0 RepositionBlotDependents__FP4BLOT */
undefined4 SetBlotClock(BLOT * arg0, float * arg1); /* 0x1AAF58 SetBlotClock__FP4BLOTPf */
void * PostCtrLoad(CTR * arg0); /* 0x1AAF88 PostCtrLoad__FP3CTR */
undefined4 UpdateCtr(CTR * arg0); /* 0x1AB058 UpdateCtr__FP3CTR */
undefined4 DrawCtr(CTR * arg0); /* 0x1AB198 DrawCtr__FP3CTR */
undefined4 RebuildCtrAchzDraw(CTR * arg0); /* 0x1AB2B8 RebuildCtrAchzDraw__FP3CTR */
undefined4 DtVisibleCtr(CTR * arg0); /* 0x1AB5D8 DtVisibleCtr__FP3CTR */
undefined4 UpdateTimer(TIMER * arg0); /* 0x1AB660 UpdateTimer__FP5TIMER */
undefined4 DrawTimer(TIMER * arg0); /* 0x1AB710 DrawTimer__FP5TIMER */
undefined4 SetTimer(TIMER * arg0, float arg1); /* 0x1AB890 SetTimer__FP5TIMERf */
undefined4 SetTimerSpeed(TIMER * arg0, float arg1); /* 0x1AB920 SetTimerSpeed__FP5TIMERf */
undefined4 SetTimerExpire(TIMER * arg0, float arg1, void * arg2); /* 0x1AB928 SetTimerExpire__FP5TIMERfPv */
undefined4 StartTimer(TIMER * arg0); /* 0x1AB938 StartTimer__FP5TIMER */
undefined4 StopTimer(TIMER * arg0); /* 0x1AB958 StopTimer__FP5TIMER */
undefined4 RebuildTimerAchzDraw(TIMER * arg0, float arg1); /* 0x1AB980 RebuildTimerAchzDraw__FP5TIMERf */
undefined4 SetTimerTimers(TIMER * arg0, TIMERS arg1); /* 0x1ABE20 SetTimerTimers__FP5TIMER6TIMERS */
undefined4 DtVisibleTrunkctr(TRUNKCTR * arg0); /* 0x1ABE40 DtVisibleTrunkctr__FP8TRUNKCTR */
undefined4 DtVisibleCrusherctr(CRUSHERCTR * arg0); /* 0x1ABE50 DtVisibleCrusherctr__FP10CRUSHERCTR */
int FUN_001ABE60(void); /* 0x1ABE60 FUN_001ABE60__Fv */
void * PostNoteLoad(NOTE * arg0); /* 0x1AC5C0 PostNoteLoad__FP4NOTE */
undefined4 SetNoteAchzDraw(NOTE * arg0, char * arg1); /* 0x1AC638 SetNoteAchzDraw__FP4NOTEPc */
undefined4 DrawNote(NOTE * arg0); /* 0x1AC700 DrawNote__FP4NOTE */
undefined4 DrawTitle(TITLE * arg0); /* 0x1ACAA8 DrawTitle__FP5TITLE */
void * PostTotalsLoad(TOTALS * arg0); /* 0x1ACDA0 PostTotalsLoad__FP6TOTALS */
undefined4 SetTotalsBlots(TOTALS * arg0, BLOTS arg1); /* 0x1AD320 SetTotalsBlots__FP6TOTALS5BLOTS */
undefined4 DrawTotals(TOTALS * arg0); /* 0x1AD3F0 DrawTotals__FP6TOTALS */
undefined4 DrawLetterbox(LETTERBOX * arg0); /* 0x1ADB00 DrawLetterbox__FP9LETTERBOX */
undefined4 DrawLogo(LOGO * arg0); /* 0x1ADD28 DrawLogo__FP4LOGO */
undefined4 UpdateAttract(ATTRACT * arg0); /* 0x1AE178 UpdateAttract__FP7ATTRACT */
undefined4 DrawAttract(ATTRACT * arg0); /* 0x1AE220 DrawAttract__FP7ATTRACT */
undefined4 DrawLineScreen(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5, RGBA arg6, int arg7); /* 0x1AE3B8 DrawLineScreen__FUiUiUiUiUiUiG4RGBAi */
undefined4 InitSensor(SENSOR * arg0); /* 0x1AECB0 InitSensor__FP6SENSOR */
undefined4 SetSensorAlarm(SENSOR * arg0, ALARM * arg1); /* 0x1AECE0 SetSensorAlarm__FP6SENSORP5ALARM */
undefined4 SetSensorSensors(SENSOR * arg0, SENSORS arg1); /* 0x1AECE8 SetSensorSensors__FP6SENSOR7SENSORS */
int FCheckSensorObject(SENSOR * arg0, SO * arg1); /* 0x1AED78 FCheckSensorObject__FP6SENSORP2SO */
int FIgnoreSensorObject(SENSOR * arg0, SO * arg1); /* 0x1AEE50 FIgnoreSensorObject__FP6SENSORP2SO */
int FOnlySensorTriggerObject(SENSOR * arg0, SO * arg1); /* 0x1AEF00 FOnlySensorTriggerObject__FP6SENSORP2SO */
void * PauseSensor(SENSOR * arg0); /* 0x1AEF68 PauseSensor__FP6SENSOR */
undefined4 UpdateSensor(SENSOR * arg0, float arg1); /* 0x1AEFA0 UpdateSensor__FP6SENSORf */
undefined4 AddSensorTriggerObject(SENSOR * arg0, OID arg1); /* 0x1AF000 AddSensorTriggerObject__FP6SENSOR3OID */
undefined4 AddSensorNoTriggerObject(SENSOR * arg0, OID arg1); /* 0x1AF028 AddSensorNoTriggerObject__FP6SENSOR3OID */
undefined4 AddSensorTriggerClass(SENSOR * arg0, CID arg1); /* 0x1AF050 AddSensorTriggerClass__FP6SENSOR3CID */
undefined4 AddSensorNoTriggerClass(SENSOR * arg0, CID arg1); /* 0x1AF078 AddSensorNoTriggerClass__FP6SENSOR3CID */
undefined4 InitLasen(LASEN * arg0); /* 0x1AF0A0 InitLasen__FP5LASEN */
undefined4 LoadLasenFromBrx(LASEN * arg0, CBinaryInputStream * arg1); /* 0x1AF0D0 LoadLasenFromBrx__FP5LASENP18CBinaryInputStream */
undefined4 BindLasen(LASEN * arg0); /* 0x1AF108 BindLasen__FP5LASEN */
void * PostLasenLoad(LASEN * arg0); /* 0x1AF3B8 PostLasenLoad__FP5LASEN */
undefined4 UpdateBusyLasenSenseTimes(void); /* 0x1AF508 UpdateBusyLasenSenseTimes__Fv */
undefined4 UpdateLasen(LASEN * arg0, float arg1); /* 0x1AF5C8 UpdateLasen__FP5LASENf */
undefined4 FreezeLasen(LASEN * arg0, int arg1); /* 0x1AF7A8 FreezeLasen__FP5LASENi */
undefined4 RenderLasenSelf(LASEN * arg0, CM * arg1, RO * arg2); /* 0x1AF820 RenderLasenSelf__FP5LASENP2CMP2RO */
int FFilterLasen(void * arg0, SO * arg1); /* 0x1AFAF8 FFilterLasen__FPvP2SO */
undefined4 SenseLasen(LASEN * arg0, SENSORS * arg1); /* 0x1AFBB0 SenseLasen__FP5LASENP7SENSORS */
undefined4 EnableLasen(LASEN * arg0, SENSM arg1); /* 0x1B00E8 EnableLasen__FP5LASEN5SENSM */
undefined4 DisableLasen(LASEN * arg0); /* 0x1B0120 DisableLasen__FP5LASEN */
undefined4 OnLasenAlarmTriggered(LASEN * arg0); /* 0x1B0160 OnLasenAlarmTriggered__FP5LASEN */
undefined4 SetLasenSensors(LASEN * arg0, SENSORS arg1); /* 0x1B01B0 SetLasenSensors__FP5LASEN7SENSORS */
float SCalcLasenShapeExtent(LASEN * arg0, LBEAM * arg1); /* 0x1B0360 SCalcLasenShapeExtent__FP5LASENP5LBEAM */
undefined4 RetractLasen(LASEN * arg0, float arg1); /* 0x1B0470 RetractLasen__FP5LASENf */
undefined4 ExtendLasen(LASEN * arg0, float arg1); /* 0x1B0488 ExtendLasen__FP5LASENf */
undefined4 InitCamsen(CAMSEN * arg0); /* 0x1B04A0 InitCamsen__FP6CAMSEN */
void * PostCamsenLoad(CAMSEN * arg0); /* 0x1B04D0 PostCamsenLoad__FP6CAMSEN */
undefined4 UpdateCamsen(CAMSEN * arg0, float arg1); /* 0x1B0578 UpdateCamsen__FP6CAMSENf */
undefined4 RenderCamsenSelf(CAMSEN * arg0, CM * arg1, RO * arg2); /* 0x1B0838 RenderCamsenSelf__FP6CAMSENP2CMP2RO */
int FIgnoreCamsenIntersection(CAMSEN * arg0, SO * arg1); /* 0x1B0BD8 FIgnoreCamsenIntersection__FP6CAMSENP2SO */
int FFilterCamsen(void * arg0, SO * arg1); /* 0x1B0BE0 FFilterCamsen__FPvP2SO */
undefined4 SenseCamsen(CAMSEN * arg0, SENSORS * arg1); /* 0x1B0C68 SenseCamsen__FP6CAMSENP7SENSORS */
undefined4 EnableCamsen(CAMSEN * arg0, SENSM arg1); /* 0x1B0EA8 EnableCamsen__FP6CAMSEN5SENSM */
undefined4 DisableCamsen(CAMSEN * arg0); /* 0x1B0EE0 DisableCamsen__FP6CAMSEN */
undefined4 OnCamsenAlarmTriggered(CAMSEN * arg0); /* 0x1B0F70 OnCamsenAlarmTriggered__FP6CAMSEN */
undefined4 SetCamsenSensors(CAMSEN * arg0, SENSORS arg1); /* 0x1B0FC0 SetCamsenSensors__FP6CAMSEN7SENSORS */
undefined4 SetCamsenCsdts(CAMSEN * arg0, CSDTS arg1); /* 0x1B1070 SetCamsenCsdts__FP6CAMSEN5CSDTS */
undefined4 InitPrsen(PRSEN * arg0); /* 0x1B1158 InitPrsen__FP5PRSEN */
void * PostPrsenLoad(PRSEN * arg0); /* 0x1B11A0 PostPrsenLoad__FP5PRSEN */
undefined4 UpdatePrsen(PRSEN * arg0, float arg1); /* 0x1B1238 UpdatePrsen__FP5PRSENf */
undefined4 SensePrsen(PRSEN * arg0, SENSORS * arg1); /* 0x1B1438 SensePrsen__FP5PRSENP7SENSORS */
undefined4 EnablePrsen(PRSEN * arg0, SENSM arg1); /* 0x1B15D0 EnablePrsen__FP5PRSEN5SENSM */
undefined4 DisablePrsen(PRSEN * arg0); /* 0x1B1608 DisablePrsen__FP5PRSEN */
undefined4 OnPrsenAlarmTriggered(PRSEN * arg0); /* 0x1B1698 OnPrsenAlarmTriggered__FP5PRSEN */
undefined4 SetPrsenSensors(PRSEN * arg0, SENSORS arg1); /* 0x1B1710 SetPrsenSensors__FP5PRSEN7SENSORS */
undefined4 UpdatePrsenLoopShader(PRSEN * arg0); /* 0x1B1898 UpdatePrsenLoopShader__FP5PRSEN */
undefined4 InitShadow(SHADOW * arg0); /* 0x1B1AC8 InitShadow__FP6SHADOW */
void * PostShadowLoad(SHADOW * arg0); /* 0x1B1B38 PostShadowLoad__FP6SHADOW */
undefined4 InvalidateShadowVifs(SHADOW * arg0); /* 0x1B1BF0 InvalidateShadowVifs__FP6SHADOW */
undefined4 RebuildShadowRegion(SHADOW * arg0); /* 0x1B1BF8 RebuildShadowRegion__FP6SHADOW */
undefined4 SetShadowShader(SHADOW * arg0, OID arg1); /* 0x1B1CF8 SetShadowShader__FP6SHADOW3OID */
int FShadowRadiusSet(SHADOW * arg0); /* 0x1B1D38 FShadowRadiusSet__FP6SHADOW */
undefined4 SetShadowNearRadius(SHADOW * arg0, float arg1); /* 0x1B1D70 SetShadowNearRadius__FP6SHADOWf */
undefined4 SetShadowFarRadius(SHADOW * arg0, float arg1); /* 0x1B1DA8 SetShadowFarRadius__FP6SHADOWf */
undefined4 SetShadowCastPosition(SHADOW * arg0, VECTOR * arg1); /* 0x1B1DE0 SetShadowCastPosition__FP6SHADOWP6VECTOR */
undefined4 SetShadowCastNormal(SHADOW * arg0, VECTOR * arg1); /* 0x1B1EC8 SetShadowCastNormal__FP6SHADOWP6VECTOR */
undefined4 SetShadowNearCast(SHADOW * arg0, float arg1); /* 0x1B1FB0 SetShadowNearCast__FP6SHADOWf */
undefined4 SetShadowFarCast(SHADOW * arg0, float arg1); /* 0x1B1FE0 SetShadowFarCast__FP6SHADOWf */
undefined4 SetShadowConeAngle(SHADOW * arg0, float arg1); /* 0x1B2010 SetShadowConeAngle__FP6SHADOWf */
undefined4 SetShadowFrustrumUp(SHADOW * arg0, VECTOR * arg1); /* 0x1B2068 SetShadowFrustrumUp__FP6SHADOWP6VECTOR */
int FShadowValid(SHADOW * arg0, int arg1); /* 0x1B2090 FShadowValid__FP6SHADOWi */
int FFilterFastShadows(void * arg0, SO * arg1); /* 0x1B2118 FFilterFastShadows__FPvP2SO */
undefined4 UpdateShadow(SHADOW * arg0, float arg1); /* 0x1B2140 UpdateShadow__FP6SHADOWf */
undefined4 RebuildShadowVifs(SHADOW * arg0); /* 0x1B2358 RebuildShadowVifs__FP6SHADOW */
undefined4 DrawShadow(SHADOW * arg0); /* 0x1B2640 DrawShadow__FP6SHADOW */
int FShadowIntersectsSphere(SHADOW * arg0, VECTOR * arg1, float arg2); /* 0x1B26F8 FShadowIntersectsSphere__FP6SHADOWP6VECTORf */
undefined4 FindSwShadows(SW * arg0, VECTOR * arg1, float arg2, int arg3, int * arg4, SHADOW * * arg5); /* 0x1B2790 FindSwShadows__FP2SWP6VECTORfiPiPP6SHADOW */
undefined4 LoadShapeFromBrx(SHAPE * arg0, CBinaryInputStream * arg1); /* 0x1B2840 LoadShapeFromBrx__FP5SHAPEP18CBinaryInputStream */
undefined4 SetShapeParent(SHAPE * arg0, ALO * arg1); /* 0x1B28A8 SetShapeParent__FP5SHAPEP3ALO */
undefined4 Tex0FromTexIframeCtk(TEX * arg0, int arg1, CTK arg2); /* 0x1B2988 Tex0FromTexIframeCtk__FP3TEXi3CTK */
void * PackTexGifs(TEX * arg0, int arg1, CTK arg2, SHDK arg3, GIFS * arg4); /* 0x1B29E0 PackTexGifs__FP3TEXi3CTK4SHDKP4GIFS */
undefined4 LoadClutFromBrx(CBinaryInputStream * arg0, CLUT * arg1); /* 0x1B2B50 LoadClutFromBrx__FP18CBinaryInputStreamP4CLUT */
undefined4 LoadColorTablesFromBrx(CBinaryInputStream * arg0); /* 0x1B2BA8 LoadColorTablesFromBrx__FP18CBinaryInputStream */
undefined4 LoadBmpFromBrx(CBinaryInputStream * arg0, BMP * arg1); /* 0x1B2CA8 LoadBmpFromBrx__FP18CBinaryInputStreamP3BMP */
undefined4 LoadBitmapsFromBrx(CBinaryInputStream * arg0); /* 0x1B2CF8 LoadBitmapsFromBrx__FP18CBinaryInputStream */
undefined4 LoadFontsFromBrx(CBinaryInputStream * arg0); /* 0x1B2DF8 LoadFontsFromBrx__FP18CBinaryInputStream */
undefined4 LoadTexFromBrx(CBinaryInputStream * arg0, TEX * arg1); /* 0x1B2F00 LoadTexFromBrx__FP18CBinaryInputStreamP3TEX */
undefined4 LoadShadersFromBrx(CBinaryInputStream * arg0); /* 0x1B3040 LoadShadersFromBrx__FP18CBinaryInputStream */
undefined4 UploadPermShaders(void); /* 0x1B3450 UploadPermShaders__Fv */
undefined4 PropagateShaders(int arg0); /* 0x1B3488 PropagateShaders__Fi */
undefined4 FillShaders(int arg0); /* 0x1B3510 FillShaders__Fi */
undefined4 UnloadShaders(void); /* 0x1B40C8 UnloadShaders__Fv */
undefined4 ConvertRgbToHsv(VECTOR * arg0, VECTOR * arg1); /* 0x1B4188 ConvertRgbToHsv__FP6VECTORT0 */
undefined4 ConvertHsvToRgb(VECTOR * arg0, VECTOR * arg1); /* 0x1B4330 ConvertHsvToRgb__FP6VECTORT0 */
undefined4 ConvertUserHsvToUserRgb(VECTOR * arg0, VECTOR * arg1); /* 0x1B4580 ConvertUserHsvToUserRgb__FP6VECTORT0 */
undefined4 ConvertUserRgbToUserHsv(VECTOR * arg0, VECTOR * arg1); /* 0x1B4600 ConvertUserRgbToUserHsv__FP6VECTORT0 */
void * PshdFindShader(OID arg0); /* 0x1B4688 PshdFindShader__F3OID */
undefined4 SetSaiIframe(SAI * arg0, int arg1); /* 0x1B46E0 SetSaiIframe__FP3SAIi */
undefined4 SetSaiDuDv(SAI * arg0, float arg1, float arg2); /* 0x1B4750 SetSaiDuDv__FP3SAIff */
undefined4 PropagateSais(void); /* 0x1B47C0 PropagateSais__Fv */
undefined4 UpdateShaders(float arg0); /* 0x1B4878 UpdateShaders__Ff */
undefined4 CbFromSaak(SAAK arg0); /* 0x1B4920 CbFromSaak__F4SAAK */
void * PvtsaaFromSaak(SAAK arg0); /* 0x1B4980 PvtsaaFromSaak__F4SAAK */
void * PsaaLoadFromBrx(CBinaryInputStream * arg0); /* 0x1B4A10 PsaaLoadFromBrx__FP18CBinaryInputStream */
undefined4 InitSaa(SAA * arg0, SAAF * arg1); /* 0x1B4AA0 InitSaa__FP3SAAP4SAAF */
void * PostSaaLoad(SAA * arg0); /* 0x1B4AD0 PostSaaLoad__FP3SAA */
int FUpdatableSaa(SAA * arg0); /* 0x1B4B08 FUpdatableSaa__FP3SAA */
undefined4 UCompleteSaa(SAA * arg0); /* 0x1B4B38 UCompleteSaa__FP3SAA */
void * PsaiFromSaaShd(SAA * arg0, SHD * arg1); /* 0x1B4B48 PsaiFromSaaShd__FP3SAAP3SHD */
undefined4 InitLoop(LOOP * arg0, SAAF * arg1); /* 0x1B4B68 InitLoop__FP4LOOPP4SAAF */
void * PostLoopLoad(LOOP * arg0); /* 0x1B4BC8 PostLoopLoad__FP4LOOP */
undefined4 UpdateLoop(LOOP * arg0, float arg1); /* 0x1B4C30 UpdateLoop__FP4LOOPf */
undefined4 UCompleteLoop(LOOP * arg0); /* 0x1B4D18 UCompleteLoop__FP4LOOP */
undefined4 InitPingpong(PINGPONG * arg0, SAAF * arg1); /* 0x1B4D48 InitPingpong__FP8PINGPONGP4SAAF */
void * PostPingpongLoad(PINGPONG * arg0); /* 0x1B4DA8 PostPingpongLoad__FP8PINGPONG */
undefined4 UpdatePingpong(PINGPONG * arg0, float arg1); /* 0x1B4E18 UpdatePingpong__FP8PINGPONGf */
undefined4 UCompletePingpong(PINGPONG * arg0); /* 0x1B4F18 UCompletePingpong__FP8PINGPONG */
undefined4 InitShuffle(SHUFFLE * arg0, SAAF * arg1); /* 0x1B4F80 InitShuffle__FP7SHUFFLEP4SAAF */
undefined4 UpdateShuffle(SHUFFLE * arg0, float arg1); /* 0x1B4FC0 UpdateShuffle__FP7SHUFFLEf */
undefined4 InitHologram(HOLOGRAM * arg0, SAAF * arg1); /* 0x1B5060 InitHologram__FP8HOLOGRAMP4SAAF */
void * PostHologramLoad(HOLOGRAM * arg0); /* 0x1B5108 PostHologramLoad__FP8HOLOGRAM */
undefined4 NotifyHologramRender(HOLOGRAM * arg0, ALO * arg1, RPL * arg2); /* 0x1B5160 NotifyHologramRender__FP8HOLOGRAMP3ALOP3RPL */
undefined4 InitScroller(SCROLLER * arg0, SAAF * arg1); /* 0x1B5200 InitScroller__FP8SCROLLERP4SAAF */
undefined4 UpdateScroller(SCROLLER * arg0, float arg1); /* 0x1B5278 UpdateScroller__FP8SCROLLERf */
undefined4 UCompleteScroller(SCROLLER * arg0); /* 0x1B5308 UCompleteScroller__FP8SCROLLER */
undefined4 SetScrollerMasterSpeeds(SCROLLER * arg0, float arg1, float arg2); /* 0x1B5388 SetScrollerMasterSpeeds__FP8SCROLLERff */
undefined4 InitCircler(CIRCLER * arg0, SAAF * arg1); /* 0x1B5398 InitCircler__FP7CIRCLERP4SAAF */
undefined4 UpdateCircler(CIRCLER * arg0, float arg1); /* 0x1B5400 UpdateCircler__FP7CIRCLERf */
undefined4 UCompleteCircler(CIRCLER * arg0); /* 0x1B5488 UCompleteCircler__FP7CIRCLER */
undefined4 InitLooker(LOOKER * arg0, SAAF * arg1); /* 0x1B54D0 InitLooker__FP6LOOKERP4SAAF */
undefined4 SetLookerSgvr(LOOKER * arg0, SGVR * arg1, GLOBSET * arg2, GLOB * arg3, SUBGLOB * arg4); /* 0x1B5568 SetLookerSgvr__FP6LOOKERP4SGVRP7GLOBSETP4GLOBP7SUBGLOB */
undefined4 SetVecPosad(VECTOR * arg0, POSAD * arg1); /* 0x1B5588 SetVecPosad__FP6VECTORP5POSAD */
undefined4 SetUvPuvqd(UVF * arg0, UVQ * arg1); /* 0x1B55A8 SetUvPuvqd__FP3UVFP3UVQ */
undefined4 NotifyLookerRender(LOOKER * arg0, ALO * arg1, RPL * arg2); /* 0x1B55C0 NotifyLookerRender__FP6LOOKERP3ALOP3RPL */
void * PostSkyLoad(SKY * arg0); /* 0x1B5CD8 PostSkyLoad__FP3SKY */
undefined4 UpdateSky(SKY * arg0, float arg1); /* 0x1B5D28 UpdateSky__FP3SKYf */
undefined4 _InitSlotheap(SLOTHEAP * arg0, int arg1, int arg2); /* 0x1B5D80 _InitSlotheap__FP8SLOTHEAPii */
undefined4 CreateSlotheapSw(SLOTHEAP * arg0, int arg1, int arg2); /* 0x1B5DD0 CreateSlotheapSw__FP8SLOTHEAPii */
undefined4 CreateSlotheapSwAlign64(SLOTHEAP * arg0, int arg1, int arg2); /* 0x1B5E30 CreateSlotheapSwAlign64__FP8SLOTHEAPii */
void * PvAllocSlotheapUnsafe(SLOTHEAP * arg0); /* 0x1B5EA0 PvAllocSlotheapUnsafe__FP8SLOTHEAP */
void * PvAllocSlotheapImpl(SLOTHEAP * arg0); /* 0x1B5EC0 PvAllocSlotheapImpl__FP8SLOTHEAP */
void * PvAllocSlotheapClearImpl(SLOTHEAP * arg0); /* 0x1B5EE0 PvAllocSlotheapClearImpl__FP8SLOTHEAP */
undefined4 FreeSlotheapPv(SLOTHEAP * arg0, void * arg1); /* 0x1B5F28 FreeSlotheapPv__FP8SLOTHEAPPv */
undefined4 LoadSmFromBrx(SM * arg0, CBinaryInputStream * arg1); /* 0x1B5F50 LoadSmFromBrx__FP2SMP18CBinaryInputStream */
void * PostSmLoad(SM * arg0); /* 0x1B61A8 PostSmLoad__FP2SM */
void * PostSmLoadCallback(SM * arg0, MSGID arg1, void * arg2); /* 0x1B61F0 PostSmLoadCallback__FP2SM5MSGIDPv */
void * PsmaApplySm(SM * arg0, ALO * arg1, OID arg2, int arg3); /* 0x1B6290 PsmaApplySm__FP2SMP3ALO3OIDi */
void * PsmaFindSm(SM * arg0, ALO * arg1); /* 0x1B6388 PsmaFindSm__FP2SMP3ALO */
undefined4 IsmsFindSmOptional(SM * arg0, OID arg1); /* 0x1B63C0 IsmsFindSmOptional__FP2SM3OID */
undefined4 IsmsFindSmRequired(SM * arg0, OID arg1); /* 0x1B63F8 IsmsFindSmRequired__FP2SM3OID */
undefined4 OidFromSmIsms(SM * arg0, int arg1); /* 0x1B6420 OidFromSmIsms__FP2SMi */
undefined4 RetractSma(SMA * arg0); /* 0x1B6438 RetractSma__FP3SMA */
undefined4 SetSmaGoal(SMA * arg0, OID arg1); /* 0x1B64D8 SetSmaGoal__FP3SMA3OID */
undefined4 GetSmaGoal(SMA * arg0, OID * arg1); /* 0x1B6568 GetSmaGoal__FP3SMAP3OID */
undefined4 GetSmaCur(SMA * arg0, OID * arg1); /* 0x1B6598 GetSmaCur__FP3SMAP3OID */
undefined4 GetSmaNext(SMA * arg0, OID * arg1); /* 0x1B65C8 GetSmaNext__FP3SMAP3OID */
undefined4 SetSmaSvt(SMA * arg0, float arg1); /* 0x1B65F8 SetSmaSvt__FP3SMAf */
undefined4 SeekSma(SMA * arg0, OID arg1); /* 0x1B6628 SeekSma__FP3SMA3OID */
undefined4 ChooseSmaTransition(SMA * arg0); /* 0x1B66A0 ChooseSmaTransition__FP3SMA */
undefined4 EndSmaTransition(SMA * arg0); /* 0x1B6C68 EndSmaTransition__FP3SMA */
undefined4 HandleSmaMessage(SMA * arg0, MSGID arg1, void * arg2); /* 0x1B6CA8 HandleSmaMessage__FP3SMA5MSGIDPv */
undefined4 SkipSma(SMA * arg0, float arg1); /* 0x1B6CF0 SkipSma__FP3SMAf */
undefined4 SendSmaMessage(SMA * arg0, MSGID arg1, void * arg2); /* 0x1B6D78 SendSmaMessage__FP3SMA5MSGIDPv */
undefined4 NotifySmaSpliceOnEnterState(SMA * arg0, int arg1, int arg2); /* 0x1B6E28 NotifySmaSpliceOnEnterState__FP3SMAii */
undefined4 InitSmartguard(SMARTGUARD * arg0); /* 0x1B6EC8 InitSmartguard__FP10SMARTGUARD */
void * PostSmartguardLoadFlashlight(SMARTGUARD * arg0); /* 0x1B6F50 PostSmartguardLoadFlashlight__FP10SMARTGUARD */
undefined4 UseSmartguardFlashlightTarget(SMARTGUARD * arg0, SGS arg1, OID arg2); /* 0x1B70B0 UseSmartguardFlashlightTarget__FP10SMARTGUARD3SGS3OID */
int FUN_001B7100(SMARTGUARD * arg0, int arg1); /* 0x1B7100 FUN_001B7100__FP10SMARTGUARDi */
void * PostSmartguardLoad(SMARTGUARD * arg0); /* 0x1B7128 PostSmartguardLoad__FP10SMARTGUARD */
int FFilterSmartguardDetect(SMARTGUARD * arg0, SO * arg1); /* 0x1B71C8 FFilterSmartguardDetect__FP10SMARTGUARDP2SO */
int FDetectSmartguard(SMARTGUARD * arg0); /* 0x1B7280 FDetectSmartguard__FP10SMARTGUARD */
undefined4 UpdateSmartguard(SMARTGUARD * arg0, float arg1); /* 0x1B7608 UpdateSmartguard__FP10SMARTGUARDf */
undefined4 UpdateSmartguardFlashlight(SMARTGUARD * arg0); /* 0x1B7638 UpdateSmartguardFlashlight__FP10SMARTGUARD */
undefined4 OnSmartguardEnteringSgs(SMARTGUARD * arg0, SGS arg1, ASEG * arg2); /* 0x1B7790 OnSmartguardEnteringSgs__FP10SMARTGUARD3SGSP4ASEG */
int FCanSmartguardAttack(SMARTGUARD * arg0); /* 0x1B7818 FCanSmartguardAttack__FP10SMARTGUARD */
undefined4 SgasGetSmartguard(SMARTGUARD * arg0); /* 0x1B7860 SgasGetSmartguard__FP10SMARTGUARD */
undefined4 HandleSmartguardMessage(SMARTGUARD * arg0, MSGID arg1, void * arg2); /* 0x1B78C0 HandleSmartguardMessage__FP10SMARTGUARD5MSGIDPv */
undefined4 FreezeSmartguard(SMARTGUARD * arg0, int arg1); /* 0x1B7920 FreezeSmartguard__FP10SMARTGUARDi */
undefined4 InitSo(SO * arg0); /* 0x1B7968 InitSo__FP2SO */
undefined4 OnSoAdd(SO * arg0); /* 0x1B7A98 OnSoAdd__FP2SO */
undefined4 OnSoRemove(SO * arg0); /* 0x1B7B78 OnSoRemove__FP2SO */
undefined4 EnableSoPhys(SO * arg0, int arg1); /* 0x1B7C40 EnableSoPhys__FP2SOi */
undefined4 DisplaceSo(SO * arg0, int arg1); /* 0x1B7D00 DisplaceSo__FP2SOi */
undefined4 ImpactSo(SO * arg0, int arg1); /* 0x1B7F78 ImpactSo__FP2SOi */
void * PivotSo(SO * arg0, int arg1); /* 0x1B8148 PivotSo__FP2SOi */
undefined4 ExtendSoBounds(SO * arg0, VECTOR * arg1, float arg2); /* 0x1B8420 ExtendSoBounds__FP2SOP6VECTORf */
undefined4 UpdateSoBounds(SO * arg0); /* 0x1B8540 UpdateSoBounds__FP2SO */
undefined4 UpdateGeomWorld(GEOM * arg0, GEOM * arg1, VU_VECTOR arg2, MATRIX3 * arg3); /* 0x1B8820 UpdateGeomWorld__FP4GEOMT0G9VU_VECTORP7MATRIX3 */
undefined4 UpdateSoXfWorldHierarchy(SO * arg0); /* 0x1B8960 UpdateSoXfWorldHierarchy__FP2SO */
undefined4 UpdateSoXfWorld(SO * arg0); /* 0x1B89B8 UpdateSoXfWorld__FP2SO */
int FIgnoreSoIntersection(SO * arg0, SO * arg1); /* 0x1B8A08 FIgnoreSoIntersection__FP2SOT0 */
undefined4 UpdateSoImpacts(SO * arg0); /* 0x1B8A48 UpdateSoImpacts__FP2SO */
undefined4 UProjectVector(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x1B8B30 UProjectVector__FP6VECTORN20 */
undefined4 AdjustSoXpLocal(SO * arg0, XP * arg1, int arg2); /* 0x1B8B90 AdjustSoXpLocal__FP2SOP2XPi */
undefined4 CalculateSoAngularEffectWorld(SO * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x1B8FE8 CalculateSoAngularEffectWorld__FP2SOP6VECTORT1 */
undefined4 AccelSoTowardPosSpring(SO * arg0, VECTOR * arg1, CLQ * arg2, VECTOR * arg3, CLQ * arg4, float arg5); /* 0x1B9058 AccelSoTowardPosSpring__FP2SOP6VECTORP3CLQT1T2f */
undefined4 AccelSoTowardMatSpring(SO * arg0, MATRIX3 * arg1, CLQ * arg2, VECTOR * arg3, CLQ * arg4, float arg5); /* 0x1B91A8 AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f */
void * PresetSoAccel(SO * arg0, float arg1); /* 0x1B9338 PresetSoAccel__FP2SOf */
undefined4 RenderSoSelf(SO * arg0, CM * arg1, RO * arg2); /* 0x1B93D8 RenderSoSelf__FP2SOP2CMP2RO */
undefined4 UpdateSo(SO * arg0, float arg1); /* 0x1B93F8 UpdateSo__FP2SOf */
undefined4 SetSoMass(SO * arg0, float arg1); /* 0x1B9418 SetSoMass__FP2SOf */
undefined4 AdjustSoMomint(SO * arg0, float arg1); /* 0x1B9448 AdjustSoMomint__FP2SOf */
undefined4 DiscardSoXps(SO * arg0); /* 0x1B94F0 DiscardSoXps__FP2SO */
undefined4 UpdateSoPosWorldPrev(SO * arg0); /* 0x1B9680 UpdateSoPosWorldPrev__FP2SO */
undefined4 TranslateSoToPos(SO * arg0, VECTOR * arg1); /* 0x1B9690 TranslateSoToPos__FP2SOP6VECTOR */
undefined4 RotateSoToMat(SO * arg0, MATRIX3 * arg1); /* 0x1B97E0 RotateSoToMat__FP2SOP7MATRIX3 */
undefined4 TranslateSoToPosSafe(SO * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x1B9860 TranslateSoToPosSafe__FP2SOP6VECTORT1 */
undefined4 SetSoVelocityVec(SO * arg0, VECTOR * arg1); /* 0x1B9940 SetSoVelocityVec__FP2SOP6VECTOR */
undefined4 SetSoAngularVelocityVec(SO * arg0, VECTOR * arg1); /* 0x1B99F0 SetSoAngularVelocityVec__FP2SOP6VECTOR */
undefined4 AddSoAcceleration(SO * arg0, VECTOR * arg1); /* 0x1B9AB0 AddSoAcceleration__FP2SOP6VECTOR */
undefined4 AddSoAngularAcceleration(SO * arg0, VECTOR * arg1); /* 0x1B9AC8 AddSoAngularAcceleration__FP2SOP6VECTOR */
undefined4 SetSoConstraints(SO * arg0, CT arg1, VECTOR * arg2, CT arg3, VECTOR * arg4); /* 0x1B9AE0 SetSoConstraints__FP2SO2CTP6VECTORT1T2 */
undefined4 SetSoParent(SO * arg0, ALO * arg1); /* 0x1B9B50 SetSoParent__FP2SOP3ALO */
undefined4 ApplySoProxy(SO * arg0, PROXY * arg1); /* 0x1B9C80 ApplySoProxy__FP2SOP5PROXY */
undefined4 AccelSoTowardMatSmooth(SO * arg0, float arg1, MATRIX3 * arg2, SMP * arg3); /* 0x1B9D10 AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP */
undefined4 GetSoCpdefi(SO * arg0, float arg1, CPDEFI * arg2); /* 0x1B9F30 GetSoCpdefi__FP2SOfP6CPDEFI */
int FIsSoTouching(SO * arg0, SO * arg1); /* 0x1B9FB0 FIsSoTouching__FP2SOT0 */
void * PsoFirstSoTouching(SO * arg0); /* 0x1BA068 PsoFirstSoTouching__FP2SO */
undefined4 CloneSo(SO * arg0, SO * arg1); /* 0x1BA130 CloneSo__FP2SOT0 */
undefined4 ApplySoConstraintWorld(SO * arg0, CONSTR * arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4); /* 0x1BA2E8 ApplySoConstraintWorld__FP2SOP6CONSTRP6VECTORN22 */
undefined4 ApplyConstr(CONSTR * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1BA430 ApplyConstr__FP6CONSTRP6VECTORN21 */
undefined4 ApplySoConstraintLocal(SO * arg0, CONSTR * arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4); /* 0x1BA500 ApplySoConstraintLocal__FP2SOP6CONSTRP6VECTORN22 */
undefined4 AddSoXa(SO * arg0, XA * arg1); /* 0x1BA528 AddSoXa__FP2SOP2XA */
undefined4 RemoveSoXa(SO * arg0, XA * arg1); /* 0x1BA550 RemoveSoXa__FP2SOP2XA */
undefined4 AddSoWaterAcceleration(SO * arg0, WATER * arg1, float arg2); /* 0x1BA5B0 AddSoWaterAcceleration__FP2SOP5WATERf */
undefined4 AddSoExternalAccelerations(SO * arg0, XA * arg1, float arg2); /* 0x1BAC28 AddSoExternalAccelerations__FP2SOP2XAf */
undefined4 LoadSoFromBrx(SO * arg0, CBinaryInputStream * arg1); /* 0x1BAC30 LoadSoFromBrx__FP2SOP18CBinaryInputStream */
undefined4 SetSoSphere(SO * arg0, float arg1); /* 0x1BAFE0 SetSoSphere__FP2SOf */
undefined4 SetSoNoInteract(SO * arg0, int arg1); /* 0x1BB000 SetSoNoInteract__FP2SOi */
undefined4 ConstrFromCnstr(CNSTR arg0, CT * arg1, VECTOR * arg2); /* 0x1BB028 ConstrFromCnstr__F5CNSTRP2CTP6VECTOR */
undefined4 SetSoCnstrForce(SO * arg0, CNSTR arg1); /* 0x1BB058 SetSoCnstrForce__FP2SO5CNSTR */
undefined4 SetSoCnstrTorque(SO * arg0, CNSTR arg1); /* 0x1BB0C8 SetSoCnstrTorque__FP2SO5CNSTR */
undefined4 SetSoCameraStyle(SO * arg0, CMK arg1); /* 0x1BB138 SetSoCameraStyle__FP2SO3CMK */
undefined4 SetSoIgnoreLocked(SO * arg0, int arg1); /* 0x1BB168 SetSoIgnoreLocked__FP2SOi */
undefined4 SetSoIceable(SO * arg0, int arg1); /* 0x1BB1A0 SetSoIceable__FP2SOi */
undefined4 SetSoMtlk(SO * arg0, MTLK arg1); /* 0x1BB1D8 SetSoMtlk__FP2SO4MTLK */
undefined4 SetSoEdgeGrab(SO * arg0, EGK arg1); /* 0x1BB1E0 SetSoEdgeGrab__FP2SO3EGK */
undefined4 SendSoMessage(SO * arg0, MSGID arg1, void * arg2); /* 0x1BB210 SendSoMessage__FP2SO5MSGIDPv */
void * PxpFindSoGround(SO * arg0, SO * arg1, int * arg2); /* 0x1BB290 PxpFindSoGround__FP2SOT0Pi */
undefined4 SetSoNoGravity(SO * arg0, int arg1); /* 0x1BB378 SetSoNoGravity__FP2SOi */
undefined4 SetSoNoXpsAll(SO * arg0, int arg1); /* 0x1BB3B0 SetSoNoXpsAll__FP2SOi */
undefined4 SetSoNoXpsSelf(SO * arg0, int arg1); /* 0x1BB400 SetSoNoXpsSelf__FP2SOi */
undefined4 SetSoNoXpsCenter(SO * arg0, int arg1); /* 0x1BB450 SetSoNoXpsCenter__FP2SOi */
undefined4 RebuildSoPhysHook(SO * arg0); /* 0x1BB4A0 RebuildSoPhysHook__FP2SO */
void * PsoFindSoPhysHook(SO * arg0, int arg1); /* 0x1BB540 PsoFindSoPhysHook__FP2SOi */
undefined4 RecalcSoLocked(SO * arg0); /* 0x1BB580 RecalcSoLocked__FP2SO */
int FGetSoContactList(SO * arg0, void * arg1); /* 0x1BB710 FGetSoContactList__FP2SOPv */
undefined4 GetSoContacts(SO * arg0, int * arg1, SO * * * arg2); /* 0x1BB800 GetSoContacts__FP2SOPiPPP2SO */
int FSoInStsoList(STSO * arg0, SO * arg1); /* 0x1BB9A0 FSoInStsoList__FP4STSOP2SO */
undefined4 GenerateSoSpliceTouchingEvents(SO * arg0); /* 0x1BB9D0 GenerateSoSpliceTouchingEvents__FP2SO */
int FInflictSoZap(SO * arg0, XP * arg1, ZPR * arg2); /* 0x1BBC30 FInflictSoZap__FP2SOP2XPP3ZPR */
undefined4 EnsureSoLvo(SO * arg0); /* 0x1BBC38 EnsureSoLvo__FP2SO */
void * ProjectSoLvo(SO * arg0, float arg1); /* 0x1BBEB8 ProjectSoLvo__FP2SOf */
void * ProjectSoTransform(SO * arg0, float arg1, int arg2); /* 0x1BC088 ProjectSoTransform__FP2SOfi */
undefined4 ApplySoImpulse(SO * arg0, VECTOR * arg1, VECTOR * arg2, float arg3); /* 0x1BC0E0 ApplySoImpulse__FP2SOP6VECTORT1f */
undefined4 CalculateSoTrajectoryApex(SO * arg0, VECTOR * arg1, float arg2, VECTOR * arg3); /* 0x1BC260 CalculateSoTrajectoryApex__FP2SOP6VECTORfT1 */
int FAbsorbSoWkr(SO * arg0, WKR * arg1); /* 0x1BC320 FAbsorbSoWkr__FP2SOP3WKR */
undefined4 CloneSoPhys(SO * arg0, SO * arg1, int arg2); /* 0x1BC368 CloneSoPhys__FP2SOT0i */
undefined4 RenumberSo(SO * arg0, int * arg1, SO * * arg2); /* 0x1BC760 RenumberSo__FP2SOPiPP2SO */
undefined4 CalculateSoEffect(SO * arg0, VECTOR * arg1, FX * arg2, VECTOR * arg3); /* 0x1BC7F8 CalculateSoEffect__FP2SOP6VECTORP2FXT1 */
undefined4 PropagateSoForce(SO * arg0, int arg1, XP * arg2, int arg3, DZ * arg4, FX * arg5); /* 0x1BC828 PropagateSoForce__FP2SOiP2XPiP2DZP2FX */
undefined4 DistributeSoEffects(SO * arg0, int arg1, int arg2, SO * * arg3, FX * arg4); /* 0x1BC978 DistributeSoEffects__FP2SOiiPP2SOP2FX */
undefined4 SolveSwGroup(SW * arg0, int arg1, SO * * arg2, int arg3, XP * * arg4, float arg5, int arg6); /* 0x1BCD00 SolveSwGroup__FP2SWiPP2SOiPP2XPfi */
undefined4 CpxpBuildXpArray(int arg0, SO * * arg1, int arg2, XP * * arg3); /* 0x1BD558 CpxpBuildXpArray__FiPP2SOiPP2XP */
undefined4 BuildContactGroup(SO * arg0, int * arg1, SO * * arg2, int * arg3, SO * * arg4); /* 0x1BD678 BuildContactGroup__FP2SOPiPP2SOT1T2 */
undefined4 SplitSoFreeze(SO * arg0, int arg1); /* 0x1BD790 SplitSoFreeze__FP2SOi */
undefined4 SortSwGroup(int arg0, SO * * arg1); /* 0x1BD888 SortSwGroup__FiPP2SO */
undefined4 SplitSwGroup(SW * arg0, int arg1, SO * * arg2, float arg3, int arg4); /* 0x1BDA50 SplitSwGroup__FP2SWiPP2SOfi */
undefined4 SolveSw(SW * arg0, float arg1, int arg2); /* 0x1BDD00 SolveSw__FP2SWfi */
undefined4 SwapEntries(void * arg0, int arg1, int arg2, int arg3); /* 0x1BE068 SwapEntries__FPviii */
undefined4 HeapSort(void * arg0, int arg1, int arg2, int (*arg3)(void *, void *)); /* 0x1BE0A8 HeapSort__FPviiPFPvPv_i */
undefined4 UnloadMusic(void); /* 0x1BE1E8 UnloadMusic__Fv */
undefined4 SbpEnsureBank(int arg0); /* 0x1BE268 SbpEnsureBank__Fi */
undefined4 SbpEnsureBank_2(SFXID arg0); /* 0x1BE4A8 SbpEnsureBank__F5SFXID */
undefined4 NewSfx(SFX * * arg0); /* 0x1BE4D8 NewSfx__FPP3SFX */
int FContinuousSound(SFXID arg0); /* 0x1BE568 FContinuousSound__F5SFXID */
undefined4 SetVagUnpaused(void); /* 0x1BE5E8 SetVagUnpaused__Fv */
void * PreloadVag(char * arg0, FK arg1); /* 0x1BE5F8 PreloadVag__FPc2FK */
int FPauseForVag(void); /* 0x1BE810 FPauseForVag__Fv */
undefined4 RefreshPambVolPan(AMB * arg0); /* 0x1BE860 RefreshPambVolPan__FP3AMB */
int FVagPlaying(void); /* 0x1BE980 FVagPlaying__Fv */
undefined4 StopVag(void); /* 0x1BE998 StopVag__Fv */
void * PauseVag(void); /* 0x1BEA28 PauseVag__Fv */
undefined4 ContinueVag(void); /* 0x1BEA50 ContinueVag__Fv */
undefined4 KillMusic(void); /* 0x1BEA78 KillMusic__Fv */
void * PreloadMusidSongComplete(unsigned int arg0, unsigned long arg1); /* 0x1BEAC8 PreloadMusidSongComplete__FUiUl */
void * PreloadMusidSong(MUSID arg0); /* 0x1BEB10 PreloadMusidSong__F5MUSID */
undefined4 StartMusidSong(MUSID arg0); /* 0x1BEC58 StartMusidSong__F5MUSID */
void * PauseMusic(void); /* 0x1BECF8 PauseMusic__Fv */
undefined4 ContinueMusic(void); /* 0x1BED20 ContinueMusic__Fv */
void * PexcAlloc(void); /* 0x1BED98 PexcAlloc__Fv */
undefined4 RemoveExc(EXC * arg0); /* 0x1BEDF8 RemoveExc__FP3EXC */
undefined4 KillExcitement(void); /* 0x1BEE48 KillExcitement__Fv */
void * PexcSetExcitement(int arg0); /* 0x1BEEF8 PexcSetExcitement__Fi */
undefined4 SetIexcCurHigh(EXC * arg0); /* 0x1BEF88 SetIexcCurHigh__FP3EXC */
undefined4 UnsetExcitement(EXC * arg0); /* 0x1BF048 UnsetExcitement__FP3EXC */
undefined4 UnsetExcitementHyst(EXC * arg0); /* 0x1BF0D8 UnsetExcitementHyst__FP3EXC */
undefined4 StartupSound(void); /* 0x1BF130 StartupSound__Fv */
int FAmbientsPaused(void); /* 0x1BF1F0 FAmbientsPaused__Fv */
undefined4 CalculateVolPan(float arg0, VECTOR * arg1, float * arg2, float * arg3, float arg4, float arg5, float arg6); /* 0x1BF200 CalculateVolPan__FfP6VECTORPfT2fff */
void * PposEar(void); /* 0x1BF3D0 PposEar__Fv */
undefined4 SetDoppler(AMB * arg0); /* 0x1BF428 SetDoppler__FP3AMB */
undefined4 PfneardistGet(void); /* 0x1BF578 PfneardistGet__Fv */
float SDistEar(VECTOR * arg0); /* 0x1BF5E0 SDistEar__FP6VECTOR */
undefined4 CalculateDistVolPan(VECTOR * arg0, float * arg1, float * arg2, float arg3, float arg4, float arg5); /* 0x1BF620 CalculateDistVolPan__FP6VECTORPfT1fff */
void * PambAlloc(void); /* 0x1BF6B8 PambAlloc__Fv */
undefined4 DropPamb(AMB * * arg0); /* 0x1BF718 DropPamb__FPP3AMB */
undefined4 RemoveAmb(AMB * arg0); /* 0x1BF728 RemoveAmb__FP3AMB */
undefined4 StopSound(AMB * arg0, int arg1); /* 0x1BF788 StopSound__FP3AMBi */
undefined4 SetPambFrq(AMB * arg0, float arg1); /* 0x1BF7F8 SetPambFrq__FP3AMBf */
undefined4 SetPambVol(AMB * arg0, float arg1); /* 0x1BF8E8 SetPambVol__FP3AMBf */
undefined4 FillPamb(AMB * arg0, AMB * * arg1, int arg2, ALO * arg3, VECTOR * arg4, float arg5, float arg6, float arg7, float arg8, float arg9, LM * arg10, LM * arg11); /* 0x1BF920 FillPamb__FP3AMBPP3AMBiP3ALOP6VECTORfffffP2LMT10_ */
undefined4 ActivatePamb(AMB * arg0, SFXID arg1); /* 0x1BFAF8 ActivatePamb__FP3AMB5SFXID */
undefined4 ScheduleNextIntermittentSound(AMB * arg0); /* 0x1BFBF8 ScheduleNextIntermittentSound__FP3AMB */
undefined4 StartSound(SFXID arg0, AMB * * arg1, ALO * arg2, VECTOR * arg3, float arg4, float arg5, float arg6, float arg7, float arg8, LM * arg9, LM * arg10); /* 0x1BFCD8 StartSound__F5SFXIDPP3AMBP3ALOP6VECTORfffffP2LMT9 */
undefined4 UpdateSounds(void); /* 0x1C0070 UpdateSounds__Fv */
undefined4 SetMvgkUvol(float arg0); /* 0x1C05D0 SetMvgkUvol__Ff */
undefined4 MvgkUnknown1(MVGK arg0); /* 0x1C0600 MvgkUnknown1__F4MVGK */
undefined4 SetMvgkRvol(int arg0, MVGK arg1, float arg2); /* 0x1C06A0 SetMvgkRvol__Fi4MVGKf */
undefined4 MvgkUnknown2(void); /* 0x1C06D8 MvgkUnknown2__Fv */
undefined4 KillSoundSystem(void); /* 0x1C07B0 KillSoundSystem__Fv */
undefined4 KillSounds(int arg0); /* 0x1C0808 KillSounds__Fi */
void * PushSwReverb(SW * arg0, REVERBK arg1, int arg2); /* 0x1C08B0 PushSwReverb__FP2SW7REVERBKi */
void * PopSwReverb(SW * arg0); /* 0x1C0950 PopSwReverb__FP2SW */
undefined4 SetSwDefaultReverb(SW * arg0, REVERBK arg1, int arg2); /* 0x1C09D8 SetSwDefaultReverb__FP2SW7REVERBKi */
undefined4 StartSwIntermittentSounds(SW * arg0); /* 0x1C0B38 StartSwIntermittentSounds__FP2SW */
undefined4 SetAMRegister(int arg0, unsigned char arg1); /* 0x1C0C08 SetAMRegister__FiUc */
undefined4 GetAMRegister(int arg0); /* 0x1C0C50 GetAMRegister__Fi */
undefined4 UpdateAMRegister(int arg0, int arg1); /* 0x1C0C68 UpdateAMRegister__Fii */
int FUN_001c0cb0(void); /* 0x1C0CB0 FUN_001c0cb0__Fv */
undefined4 HsNextFootFall(void); /* 0x1C0CF0 HsNextFootFall__Fv */
undefined4 NextSneakyFootstep(void); /* 0x1C0EC0 NextSneakyFootstep__Fv */
undefined4 InitSpeaker(SPEAKER * arg0); /* 0x1C0F30 InitSpeaker__FP7SPEAKER */
void * PostSpeakerLoad(SPEAKER * arg0); /* 0x1C0FF0 PostSpeakerLoad__FP7SPEAKER */
undefined4 SetSpeakerSmIdle(SPEAKER * arg0, OID arg1); /* 0x1C1030 SetSpeakerSmIdle__FP7SPEAKER3OID */
undefined4 InitSpire(SPIRE * arg0); /* 0x1C10A8 InitSpire__FP5SPIRE */
undefined4 OnSpireAdd(SPIRE * arg0); /* 0x1C10D8 OnSpireAdd__FP5SPIRE */
undefined4 OnSpireRemove(SPIRE * arg0); /* 0x1C1110 OnSpireRemove__FP5SPIRE */
undefined4 CloneSpire(SPIRE * arg0, SPIRE * arg1); /* 0x1C1148 CloneSpire__FP5SPIRET0 */
undefined4 LoadSwSpliceFromBrx(SW * arg0, CBinaryInputStream * arg1); /* 0x1C1190 LoadSwSpliceFromBrx__FP2SWP18CBinaryInputStream */
void * PframeFromIsplice(int arg0, SW * arg1); /* 0x1C1390 PframeFromIsplice__FiP2SW */
undefined4 RefEvalModule(int arg0, SW * arg1); /* 0x1C13E8 RefEvalModule__FiP2SW */
void * PeopidFind(BASIC * arg0, int arg1); /* 0x1C14C0 PeopidFind__FP5BASICi */
undefined4 RefGetObjectList(BASIC * arg0, OTYP arg1, void (*arg2)(void *)); /* 0x1C1530 RefGetObjectList__FP5BASIC4OTYPPFPv_v */
undefined4 RefGetPeopid(BASIC * arg0, EOPID * arg1); /* 0x1C15D8 RefGetPeopid__FP5BASICP5EOPID */
int FAppendSpliceListElement(void * arg0, void * arg1); /* 0x1C1A28 FAppendSpliceListElement__FPvT0 */
int FSpliceListElementExists(void * arg0, void * arg1); /* 0x1C1AD8 FSpliceListElementExists__FPvT0 */
undefined4 RefSetPvsFromSplice(int arg0, CRef * arg1, OTYP * arg2, void * * arg3); /* 0x1C1BF8 RefSetPvsFromSplice__FiP4CRefP4OTYPPPv */
undefined4 RefSetArgListFromPvs(int arg0, OTYP * arg1, void * * arg2); /* 0x1C1E48 RefSetArgListFromPvs__FiP4OTYPPPv */
undefined4 RefSetPeopid(BASIC * arg0, EOPID * arg1, CRef * arg2); /* 0x1C1F20 RefSetPeopid__FP5BASICP5EOPIDP4CRef */
undefined4 RefGetOption(BASIC * arg0, int arg1); /* 0x1C21A0 RefGetOption__FP5BASICi */
undefined4 RefSetOption(BASIC * arg0, int arg1, CRef * arg2); /* 0x1C2238 RefSetOption__FP5BASICiP4CRef */
undefined4 RefAddOption(BASIC * arg0, int arg1, CRef * arg2); /* 0x1C22B8 RefAddOption__FP5BASICiP4CRef */
undefined4 RefEnsureOption(BASIC * arg0, int arg1, CRef * arg2); /* 0x1C2320 RefEnsureOption__FP5BASICiP4CRef */
undefined4 RefSetArgsFromSplice(int arg0, CRef * arg1, OTYP * arg2, ...); /* 0x1C23B0 RefSetArgsFromSplice__FiP4CRefP4OTYPe */
undefined4 LoadSprBuf(int arg0, ...); /* 0x1C2430 LoadSprBuf__Fie */
undefined4 SaveSprBuf(void * arg0, ...); /* 0x1C25B0 SaveSprBuf__FPve */
undefined4 UpdateSqtrm(SQTRM * arg0, VECTOR * arg1, MATRIX3 * arg2, float arg3, float arg4); /* 0x1C29F8 UpdateSqtrm__FP5SQTRMP6VECTORP7MATRIX3ff */
undefined4 RenderSqtrm(SQTRM * arg0, CM * arg1); /* 0x1C3028 RenderSqtrm__FP5SQTRMP2CM */
undefined4 DrawSqtrm(RPL * arg0); /* 0x1C30E8 DrawSqtrm__FP3RPL */
undefined4 InitStep(STEP * arg0); /* 0x1C4458 InitStep__FP4STEP */
void * PostStepLoad(STEP * arg0); /* 0x1C44F0 PostStepLoad__FP4STEP */
undefined4 LimitStepHands(STEP * arg0, int arg1); /* 0x1C4578 LimitStepHands__FP4STEPi */
undefined4 RenderStepSelf(STEP * arg0, CM * arg1, RO * arg2); /* 0x1C49C8 RenderStepSelf__FP4STEPP2CMP2RO */
undefined4 ReadStepJoystick(STEP * arg0, JOY * arg1); /* 0x1C49E8 ReadStepJoystick__FP4STEPP3JOY */
undefined4 UpdateStepFootfall(STEP * arg0, float arg1, SFF * arg2); /* 0x1C4A80 UpdateStepFootfall__FP4STEPfP3SFF */
undefined4 UpdateStepPhys(STEP * arg0); /* 0x1C4C20 UpdateStepPhys__FP4STEP */
undefined4 SetStepPhys(STEP * arg0, SO * arg1, int arg2); /* 0x1C4D60 SetStepPhys__FP4STEPP2SOi */
undefined4 UpdateStep(STEP * arg0, float arg1); /* 0x1C4ED0 UpdateStep__FP4STEPf */
undefined4 CtTorqueStep(STEP * arg0); /* 0x1C4F00 CtTorqueStep__FP4STEP */
undefined4 PropagateStepForce(STEP * arg0, int arg1, XP * arg2, int arg3, DZ * arg4, FX * arg5); /* 0x1C4F08 PropagateStepForce__FP4STEPiP2XPiP2DZP2FX */
undefined4 RotateStepToMat(STEP * arg0, MATRIX3 * arg1); /* 0x1C4FA0 RotateStepToMat__FP4STEPP7MATRIX3 */
undefined4 CloneStepPhys(STEP * arg0, SO * arg1, int arg2); /* 0x1C4FF8 CloneStepPhys__FP4STEPP2SOi */
void * PresetStepAccel(STEP * arg0, float arg1); /* 0x1C5118 PresetStepAccel__FP4STEPf */
void * PresetStepAccelBase(STEP * arg0); /* 0x1C5148 PresetStepAccelBase__FP4STEP */
int FCheckStepXpBase(STEP * arg0, XP * arg1, int arg2); /* 0x1C5248 FCheckStepXpBase__FP4STEPP2XPi */
undefined4 AdjustStepNewXp(STEP * arg0, XP * arg1, int arg2); /* 0x1C5338 AdjustStepNewXp__FP4STEPP2XPi */
undefined4 AdjustStepDz(STEP * arg0, int arg1, DZ * arg2, int arg3, float arg4); /* 0x1C5388 AdjustStepDz__FP4STEPiP2DZif */
undefined4 AdjustStepDzBase(STEP * arg0, int arg1, DZ * arg2, int arg3); /* 0x1C53A8 AdjustStepDzBase__FP4STEPiP2DZi */
undefined4 UpdateStepMatTarget(STEP * arg0); /* 0x1C53B0 UpdateStepMatTarget__FP4STEP */
undefined4 AdjustStepXpVelocity(STEP * arg0, XP * arg1, int arg2); /* 0x1C53E0 AdjustStepXpVelocity__FP4STEPP2XPi */
undefined4 UpdateStepXfWorld(STEP * arg0); /* 0x1C5438 UpdateStepXfWorld__FP4STEP */
undefined4 AdjustStepXpVelocityBase(STEP * arg0, XP * arg1, int arg2); /* 0x1C54D0 AdjustStepXpVelocityBase__FP4STEPP2XPi */
undefined4 AdjustStepXps(STEP * arg0); /* 0x1C57C8 AdjustStepXps__FP4STEP */
undefined4 AddStepCustomXps(STEP * arg0, SO * arg1, int arg2, BSP * arg3, BSP * arg4, XP * * arg5); /* 0x1C5BF0 AddStepCustomXps__FP4STEPP2SOiP3BSPT3PP2XP */
undefined4 AddStepCustomXpsBase(STEP * arg0, SO * arg1, BSP * arg2, XP * * arg3); /* 0x1C5C10 AddStepCustomXpsBase__FP4STEPP2SOP3BSPPP2XP */
undefined4 FixStepAngularVelocity(STEP * arg0); /* 0x1C5D58 FixStepAngularVelocity__FP4STEP */
void * PredictStepRotation(STEP * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x1C5DB8 PredictStepRotation__FP4STEPfP7MATRIX3P6VECTOR */
undefined4 SetStepSpinRatio(STEP * arg0, float arg1); /* 0x1C5E50 SetStepSpinRatio__FP4STEPf */
undefined4 SetStepGravityRatio(STEP * arg0, float arg1); /* 0x1C5EA8 SetStepGravityRatio__FP4STEPf */
undefined4 GetActaddPositionGoal(ACTADD * arg0, float arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1C5F18 GetActaddPositionGoal__FP6ACTADDfP6VECTORT2 */
undefined4 GetActaddRotationGoal(ACTADD * arg0, float arg1, MATRIX3 * arg2, VECTOR * arg3); /* 0x1C6028 GetActaddRotationGoal__FP6ACTADDfP7MATRIX3P6VECTOR */
undefined4 SetJtJtcs(JT * arg0, JTCS arg1); /* 0x1C61E0 SetJtJtcs__FP2JT4JTCS */
undefined4 UpdateJtCane(JT * arg0); /* 0x1C6890 UpdateJtCane__FP2JT */
undefined4 UpdateJtActiveCane(JT * arg0, JOY * arg1); /* 0x1C6928 UpdateJtActiveCane__FP2JTP3JOY */
undefined4 ChooseJtAttackTarget(JT * arg0, int arg1, VECTOR * arg2, float arg3, float arg4, TARGET * * arg5, VECTOR * arg6); /* 0x1C6AA8 ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2 */
undefined4 ChooseJtSweepTarget(JT * arg0, BL * arg1, ASEGBL * arg2); /* 0x1C6D00 ChooseJtSweepTarget__FP2JTP2BLP6ASEGBL */
undefined4 ChooseJtRushTarget(JT * arg0); /* 0x1C6E58 ChooseJtRushTarget__FP2JT */
undefined4 ChooseJtSmashTarget(JT * arg0); /* 0x1C6ED0 ChooseJtSmashTarget__FP2JT */
undefined4 InitStepguard(STEPGUARD * arg0); /* 0x1C6F48 InitStepguard__FP9STEPGUARD */
undefined4 LoadStepguardFromBrx(STEPGUARD * arg0, CBinaryInputStream * arg1); /* 0x1C7140 LoadStepguardFromBrx__FP9STEPGUARDP18CBinaryInputStream */
undefined4 CloneStepguard(STEPGUARD * arg0, STEPGUARD * arg1); /* 0x1C7188 CloneStepguard__FP9STEPGUARDT0 */
undefined4 BindStepguard(STEPGUARD * arg0); /* 0x1C71E0 BindStepguard__FP9STEPGUARD */
void * PostStepguardLoadCallback(STEPGUARD * arg0, MSGID arg1, void * arg2); /* 0x1C7278 PostStepguardLoadCallback__FP9STEPGUARD5MSGIDPv */
void * PostStepguardLoad(STEPGUARD * arg0); /* 0x1C72A0 PostStepguardLoad__FP9STEPGUARD */
int FIgnoreStepguardIntersection(STEPGUARD * arg0, SO * arg1); /* 0x1C7468 FIgnoreStepguardIntersection__FP9STEPGUARDP2SO */
undefined4 OnStepguardAdd(STEPGUARD * arg0); /* 0x1C74E8 OnStepguardAdd__FP9STEPGUARD */
undefined4 OnStepguardRemove(STEPGUARD * arg0); /* 0x1C7520 OnStepguardRemove__FP9STEPGUARD */
void * PresetStepguardAccel(STEPGUARD * arg0, float arg1); /* 0x1C75B0 PresetStepguardAccel__FP9STEPGUARDf */
undefined4 DradEnemyStepguard(STEPGUARD * arg0); /* 0x1C7A60 DradEnemyStepguard__FP9STEPGUARD */
undefined4 SetStepguardTargetHeading(STEPGUARD * arg0, float arg1, float arg2); /* 0x1C7AE0 SetStepguardTargetHeading__FP9STEPGUARDff */
undefined4 UpdateStepguardDrive(STEPGUARD * arg0); /* 0x1C7BE8 UpdateStepguardDrive__FP9STEPGUARD */
undefined4 UpdateStepguard(STEPGUARD * arg0, float arg1); /* 0x1C7CB8 UpdateStepguard__FP9STEPGUARDf */
undefined4 SgsNextStepguardAI(STEPGUARD * arg0); /* 0x1C8010 SgsNextStepguardAI__FP9STEPGUARD */
undefined4 SetStepguardGoal(STEPGUARD * arg0, VECTOR * arg1); /* 0x1C8418 SetStepguardGoal__FP9STEPGUARDP6VECTOR */
int FReachedStepguardGoal(STEPGUARD * arg0); /* 0x1C84C0 FReachedStepguardGoal__FP9STEPGUARD */
int FFilterStepguardJump(STEPGUARD * arg0, SO * arg1); /* 0x1C84E8 FFilterStepguardJump__FP9STEPGUARDP2SO */
undefined4 MoveStepguardToGoal(STEPGUARD * arg0); /* 0x1C8590 MoveStepguardToGoal__FP9STEPGUARD */
undefined4 LookStepguardAtGoal(STEPGUARD * arg0); /* 0x1C8BC0 LookStepguardAtGoal__FP9STEPGUARD */
undefined4 UpdateStepguardGoal(STEPGUARD * arg0, int arg1); /* 0x1C8C08 UpdateStepguardGoal__FP9STEPGUARDi */
undefined4 OnStepguardWaypointActive(STEPGUARD * arg0); /* 0x1C8D78 OnStepguardWaypointActive__FP9STEPGUARD */
undefined4 UpdateStepguardSgs(STEPGUARD * arg0); /* 0x1C8E28 UpdateStepguardSgs__FP9STEPGUARD */
undefined4 SetStepguardSgs(STEPGUARD * arg0, SGS arg1, ASEG * arg2); /* 0x1C8F20 SetStepguardSgs__FP9STEPGUARD3SGSP4ASEG */
undefined4 SetStepguardSgsExternal(STEPGUARD * arg0, SGS arg1, ASEG * arg2); /* 0x1C8FD0 SetStepguardSgsExternal__FP9STEPGUARD3SGSP4ASEG */
undefined4 OnStepguardExitingSgs(STEPGUARD * arg0, SGS arg1); /* 0x1C9008 OnStepguardExitingSgs__FP9STEPGUARD3SGS */
undefined4 OnStepguardEnteringSgs(STEPGUARD * arg0, SGS arg1, ASEG * arg2); /* 0x1C91C8 OnStepguardEnteringSgs__FP9STEPGUARD3SGSP4ASEG */
undefined4 SggsGetStepguard(STEPGUARD * arg0); /* 0x1C96B8 SggsGetStepguard__FP9STEPGUARD */
int FAbsorbStepguardWkr(STEPGUARD * arg0, WKR * arg1); /* 0x1C96D8 FAbsorbStepguardWkr__FP9STEPGUARDP3WKR */
int FTakeStepguardDamage(STEPGUARD * arg0, ZPR * arg1); /* 0x1C9990 FTakeStepguardDamage__FP9STEPGUARDP3ZPR */
int FUN_001c9a48(STEPGUARD * arg0, int arg1); /* 0x1C9A48 FUN_001c9a48__FP9STEPGUARDi */
undefined4 HandleStepguardGrfsgsc(STEPGUARD * arg0); /* 0x1C9A58 HandleStepguardGrfsgsc__FP9STEPGUARD */
undefined4 DoStepguardFreefallJump(STEPGUARD * arg0); /* 0x1C9AF8 DoStepguardFreefallJump__FP9STEPGUARD */
undefined4 DoStepguardFreefallLanding(STEPGUARD * arg0); /* 0x1C9CF8 DoStepguardFreefallLanding__FP9STEPGUARD */
undefined4 HandleStepguardMessage(STEPGUARD * arg0, MSGID arg1, void * arg2); /* 0x1C9DE0 HandleStepguardMessage__FP9STEPGUARD5MSGIDPv */
undefined4 SgasGetStepguard(STEPGUARD * arg0); /* 0x1CA460 SgasGetStepguard__FP9STEPGUARD */
int FCanStepguardAttack(STEPGUARD * arg0); /* 0x1CA468 FCanStepguardAttack__FP9STEPGUARD */
undefined4 RenderStepguardSelf(STEPGUARD * arg0, CM * arg1, RO * arg2); /* 0x1CA5E0 RenderStepguardSelf__FP9STEPGUARDP2CMP2RO */
int FValidSgs(SGS arg0); /* 0x1CA600 FValidSgs__F3SGS */
undefined4 UseStepguardAnimation(STEPGUARD * arg0, SGS arg1, OID arg2); /* 0x1CA608 UseStepguardAnimation__FP9STEPGUARD3SGS3OID */
undefined4 UseStepguardAnimationImmediate(STEPGUARD * arg0, SGS arg1, OID arg2); /* 0x1CA658 UseStepguardAnimationImmediate__FP9STEPGUARD3SGS3OID */
undefined4 UseStepguardDeathAnimation(STEPGUARD * arg0, int arg1, OID arg2); /* 0x1CA720 UseStepguardDeathAnimation__FP9STEPGUARDi3OID */
void * PasegFindStepguard(STEPGUARD * arg0, OID arg1); /* 0x1CA758 PasegFindStepguard__FP9STEPGUARD3OID */
undefined4 LoadStepguardAnimations(STEPGUARD * arg0); /* 0x1CA7C0 LoadStepguardAnimations__FP9STEPGUARD */
undefined4 UseStepguardExpl(STEPGUARD * arg0, OID arg1); /* 0x1CA878 UseStepguardExpl__FP9STEPGUARD3OID */
undefined4 UseStepguardRwm(STEPGUARD * arg0, OID arg1); /* 0x1CA888 UseStepguardRwm__FP9STEPGUARD3OID */
undefined4 UseStepguardPhys(STEPGUARD * arg0, SGS arg1, OID arg2); /* 0x1CA898 UseStepguardPhys__FP9STEPGUARD3SGS3OID */
undefined4 LoadStepguardPhys(STEPGUARD * arg0); /* 0x1CA8E8 LoadStepguardPhys__FP9STEPGUARD */
undefined4 AddStepguardEffect(STEPGUARD * arg0, OID arg1, ZPK arg2); /* 0x1CA960 AddStepguardEffect__FP9STEPGUARD3OID3ZPK */
undefined4 SetStepguardPathzone(STEPGUARD * arg0, OID arg1); /* 0x1CA998 SetStepguardPathzone__FP9STEPGUARD3OID */
void * PsoEnemyStepguard(STEPGUARD * arg0); /* 0x1CAA08 PsoEnemyStepguard__FP9STEPGUARD */
undefined4 SetStepguardEnemyObject(STEPGUARD * arg0, SO * arg1); /* 0x1CAB00 SetStepguardEnemyObject__FP9STEPGUARDP2SO */
undefined4 RebindStepguardEnemy(STEPGUARD * arg0); /* 0x1CAB10 RebindStepguardEnemy__FP9STEPGUARD */
int FUN_001cac28(STEPGUARD * arg0); /* 0x1CAC28 FUN_001cac28__FP9STEPGUARD */
undefined4 AdjustStepguardDz(STEPGUARD * arg0, int arg1, DZ * arg2, int arg3, float arg4); /* 0x1CACB0 AdjustStepguardDz__FP9STEPGUARDiP2DZif */
undefined4 SetStepguardAttackAngleMax(STEPGUARD * arg0, float arg1); /* 0x1CAD28 SetStepguardAttackAngleMax__FP9STEPGUARDf */
undefined4 AddStepguardAlarm(STEPGUARD * arg0, ALARM * arg1); /* 0x1CAD40 AddStepguardAlarm__FP9STEPGUARDP5ALARM */
undefined4 MatchStepguardAnimationPhase(STEPGUARD * arg0, OID arg1, OID arg2, OID arg3, OID arg4); /* 0x1CAD60 MatchStepguardAnimationPhase__FP9STEPGUARD3OIDN31 */
undefined4 AddStepguardCustomXps(STEPGUARD * arg0, SO * arg1, int arg2, BSP * arg3, BSP * arg4, XP * * arg5); /* 0x1CAD98 AddStepguardCustomXps__FP9STEPGUARDP2SOiP3BSPT3PP2XP */
undefined4 UpdateStepguardEffect(STEPGUARD * arg0); /* 0x1CAF38 UpdateStepguardEffect__FP9STEPGUARD */
undefined4 SetStepguardPatrolAnimation(STEPGUARD * arg0, ASEG * arg1); /* 0x1CB328 SetStepguardPatrolAnimation__FP9STEPGUARDP4ASEG */
int FInflictStepguardZap(STEPGUARD * arg0, XP * arg1, ZPR * arg2); /* 0x1CB3C0 FInflictStepguardZap__FP9STEPGUARDP2XPP3ZPR */
int FDetectStepguard(STEPGUARD * arg0); /* 0x1CB3C8 FDetectStepguard__FP9STEPGUARD */
int FCheckStepguardEnemyHidden(STEPGUARD * arg0); /* 0x1CB3D0 FCheckStepguardEnemyHidden__FP9STEPGUARD */
void * PsggNew(SW * arg0); /* 0x1CB5B8 PsggNew__FP2SW */
undefined4 InitSgg(SGG * arg0); /* 0x1CB618 InitSgg__FP3SGG */
undefined4 AddSggGuard(SGG * arg0, STEPGUARD * arg1); /* 0x1CB648 AddSggGuard__FP3SGGP9STEPGUARD */
undefined4 AddSggGuardName(SGG * arg0, OID arg1); /* 0x1CB6A8 AddSggGuardName__FP3SGG3OID */
undefined4 AddSggSearchXfmName(SGG * arg0, OID arg1); /* 0x1CB6D0 AddSggSearchXfmName__FP3SGG3OID */
undefined4 RemoveSggGuard(SGG * arg0, STEPGUARD * arg1); /* 0x1CB6F8 RemoveSggGuard__FP3SGGP9STEPGUARD */
undefined4 BindSgg(SGG * arg0); /* 0x1CB7A0 BindSgg__FP3SGG */
void * PostSggLoadCallback(SGG * arg0, MSGID arg1, void * arg2); /* 0x1CB8B8 PostSggLoadCallback__FP3SGG5MSGIDPv */
undefined4 EnsureSggCallback(SGG * arg0); /* 0x1CBAA0 EnsureSggCallback__FP3SGG */
void * PsoEnemySgg(SGG * arg0); /* 0x1CBAF8 PsoEnemySgg__FP3SGG */
undefined4 UpdateSggCallback(SGG * arg0, MSGID arg1, void * arg2); /* 0x1CBB20 UpdateSggCallback__FP3SGG5MSGIDPv */
undefined4 SggsNextSgg(SGG * arg0); /* 0x1CBB88 SggsNextSgg__FP3SGG */
int FDetectSgg(SGG * arg0); /* 0x1CBCB8 FDetectSgg__FP3SGG */
int FAbandonSggSearch(SGG * arg0); /* 0x1CBD58 FAbandonSggSearch__FP3SGG */
undefined4 EnsureSggAlarm(SGG * arg0, ALARM * arg1); /* 0x1CBE20 EnsureSggAlarm__FP3SGGP5ALARM */
undefined4 TriggerSggAlarms(SGG * arg0, ALTK arg1); /* 0x1CBE70 TriggerSggAlarms__FP3SGG4ALTK */
undefined4 SetSggSggs(SGG * arg0, SGGS arg1); /* 0x1CBEE8 SetSggSggs__FP3SGG4SGGS */
undefined4 AssignSggSearchPoints(SGG * arg0); /* 0x1CC120 AssignSggSearchPoints__FP3SGG */
void * PostJtLoadSwing(JT * arg0, BL * arg1, ASEGBL * * arg2); /* 0x1CC410 PostJtLoadSwing__FP2JTP2BLPP6ASEGBL */
undefined4 AnticipateJtForce(JT * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3, FX * arg4); /* 0x1CC490 AnticipateJtForce__FP2JTP2SOP6VECTORT2P2FX */
undefined4 CalculateJtHangAccel(JT * arg0); /* 0x1CC818 CalculateJtHangAccel__FP2JT */
void * PresetJtAccelHang(JT * arg0); /* 0x1CCF98 PresetJtAccelHang__FP2JT */
undefined4 AddJtExternalAccelerations(JT * arg0, XA * arg1, float arg2); /* 0x1CD088 AddJtExternalAccelerations__FP2JTP2XAf */
undefined4 UpdateJtActiveHang(JT * arg0, JOY * arg1); /* 0x1CD0C8 UpdateJtActiveHang__FP2JTP3JOY */
undefined4 CheckJtUnhook(JT * arg0); /* 0x1CD6C0 CheckJtUnhook__FP2JT */
undefined4 UpdateJtHookOx(JT * arg0, LO * arg1, int arg2); /* 0x1CD7E0 UpdateJtHookOx__FP2JTP2LOi */
undefined4 AddJtHookXps(JT * arg0, int arg1, LO * arg2, VECTOR * arg3, VECTOR * arg4, VECTOR * arg5); /* 0x1CD870 AddJtHookXps__FP2JTiP2LOP6VECTORN23 */
undefined4 GetJtHangHeading(JT * arg0, float * arg1); /* 0x1CDB28 GetJtHangHeading__FP2JTPf */
undefined4 UpdateJtIkHang(JT * arg0); /* 0x1CDB70 UpdateJtIkHang__FP2JT */
undefined4 JtbsChooseJtHide(JT * arg0, LO * arg1, JTHK * arg2); /* 0x1CDFB8 JtbsChooseJtHide__FP2JTP2LOP4JTHK */
undefined4 MeasureJtJumpToTarget(JT * arg0, VECTOR * arg1, ALO * arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, float * arg6, VECTOR * arg7, VECTOR * arg8); /* 0x1CE590 MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1 */
undefined4 GetJtRailLanding(JT * arg0, RAIL * arg1, float arg2, VECTOR * arg3, VECTOR * arg4); /* 0x1CE800 GetJtRailLanding__FP2JTP4RAILfP6VECTORT3 */
float GMeasureJumpRail(MJR * arg0, float arg1); /* 0x1CE9E8 GMeasureJumpRail__FP3MJRf */
float GMeasureJumpHshape(MJH * arg0, float arg1); /* 0x1CEAB8 GMeasureJumpHshape__FP3MJHf */
undefined4 UpdateJtActiveHide(JT * arg0, JOY * arg1); /* 0x1CFFD0 UpdateJtActiveHide__FP2JTP3JOY */
undefined4 MatchJtXmgRail(JT * arg0, XMG * arg1, ACTADJ * arg2); /* 0x1D0B20 MatchJtXmgRail__FP2JTP3XMGP6ACTADJ */
undefined4 UpdateJtHide(JT * arg0); /* 0x1D0C78 UpdateJtHide__FP2JT */
undefined4 UpdateJtInternalXpsHide(JT * arg0); /* 0x1D0F20 UpdateJtInternalXpsHide__FP2JT */
undefined4 SetJtHfdk(JT * arg0, HFDK arg1); /* 0x1D1200 SetJtHfdk__FP2JT4HFDK */
undefined4 ResetJtDynamicTunnel(JT * arg0); /* 0x1D1260 ResetJtDynamicTunnel__FP2JT */
void * PresetJtAccelHide(JT * arg0); /* 0x1D12F0 PresetJtAccelHide__FP2JT */
void * PostJtLoadPipe(JT * arg0); /* 0x1D14F0 PostJtLoadPipe__FP2JT */
undefined4 GetJtPipeGoalMat(JT * arg0, PIPE * arg1, float arg2, MATRIX3 * arg3); /* 0x1D1630 GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3 */
void * PresetJtAccelPipe(JT * arg0); /* 0x1D1A80 PresetJtAccelPipe__FP2JT */
undefined4 UpdateJtActivePipe(JT * arg0, JOY * arg1); /* 0x1D1BB0 UpdateJtActivePipe__FP2JTP3JOY */
undefined4 UpdateJtInternalXpsPipe(JT * arg0); /* 0x1D2518 UpdateJtInternalXpsPipe__FP2JT */
undefined4 SetJtJtpdk(JT * arg0, JTPDK arg1); /* 0x1D27C0 SetJtJtpdk__FP2JT5JTPDK */
void * PlaceJtOnPipe(JT * arg0, PIPE * arg1); /* 0x1D2830 PlaceJtOnPipe__FP2JTP4PIPE */
undefined4 SetFsp(FSP arg0); /* 0x1D29C8 SetFsp__F3FSP */
undefined4 UpdateJtActivePowerUp(JT * arg0, JOY * arg1); /* 0x1D2BB8 UpdateJtActivePowerUp__FP2JTP3JOY */
undefined4 IRotatePowerUp(JOY * arg0, int arg1, int arg2, int * arg3); /* 0x1D3100 IRotatePowerUp__FP3JOYiiPi */
undefined4 func_001D31D0(LO * arg0, int arg1); /* 0x1D31D0 func_001D31D0__FP2LOi */
undefined4 func_001D32D8(int arg0, JT * arg1, long arg2); /* 0x1D32D8 func_001D32D8__FiP2JTl */
void * PostStepLoadRun(STEP * arg0, BLRUN * arg1, ASEGBL * * arg2); /* 0x1D36F0 PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL */
undefined4 CalculateBlrunV(int arg0, BLRUN * arg1, MRSG * arg2, VECTOR * arg3); /* 0x1D39E0 CalculateBlrunV__FiP5BLRUNP4MRSGP6VECTOR */
void * ProjectStepRunPlant(STEP * arg0, BLRUN * arg1, float arg2, float arg3, int arg4, int arg5, VECTOR * arg6); /* 0x1D3A38 ProjectStepRunPlant__FP4STEPP5BLRUNffiiP6VECTOR */
int FIntersectStepRunPlant(STEP * arg0, VECTOR * arg1, VECTOR * arg2, float * arg3); /* 0x1D3B58 FIntersectStepRunPlant__FP4STEPP6VECTORT1Pf */
int FReblendAbl2D(int arg0, int arg1, int arg2, BL * arg3, ...); /* 0x1D3C68 FReblendAbl2D__FiiiP2BLe */
undefined4 AdjustStepRun(STEP * arg0, BLRUN * arg1, ASEGBL * arg2, ASEGA * arg3); /* 0x1D3E00 AdjustStepRun__FP4STEPP5BLRUNP6ASEGBLP5ASEGA */
undefined4 SetStepRunTarget(STEP * arg0, float arg1, float arg2, BLRUN * arg3, ASEGBL * arg4); /* 0x1D40A0 SetStepRunTarget__FP4STEPffP5BLRUNP6ASEGBL */
void * PostJtLoadSidestep(JT * arg0, BLSS * arg1, ASEGBL * * arg2); /* 0x1D4148 PostJtLoadSidestep__FP2JTP4BLSSPP6ASEGBL */
undefined4 AdjustJtSidestep(JT * arg0, BLSS * arg1, ASEGBL * arg2); /* 0x1D4348 AdjustJtSidestep__FP2JTP4BLSSP6ASEGBL */
undefined4 SetJtSidestepTarget(JT * arg0, BLSS * arg1, ASEGBL * arg2, float arg3, float arg4); /* 0x1D4698 SetJtSidestepTarget__FP2JTP4BLSSP6ASEGBLff */
void * PostJtLoadZap(JT * arg0); /* 0x1D4848 PostJtLoadZap__FP2JT */
void * PresetJtAccelZap(JT * arg0); /* 0x1D48E8 PresetJtAccelZap__FP2JT */
undefined4 UpdateJtZap(JT * arg0); /* 0x1D4A98 UpdateJtZap__FP2JT */
int FUN_001d4c98(JT * arg0); /* 0x1D4C98 FUN_001d4c98__FP2JT */
int FTakeJtDamage(JT * arg0, ZPR * arg1); /* 0x1D4D08 FTakeJtDamage__FP2JTP3ZPR */
int FUN_001d51a0(JT * arg0); /* 0x1D51A0 FUN_001d51a0__FP2JT */
int FUN_001d5398(JT * arg0); /* 0x1D5398 FUN_001d5398__FP2JT */
int FUN_001d5418(JT * arg0); /* 0x1D5418 FUN_001d5418__FP2JT */
int FUN_001d5468(JT * arg0); /* 0x1D5468 FUN_001d5468__FP2JT */
undefined4 SgnCmpSpkn(const void * arg0, const void * arg1); /* 0x1D5650 SgnCmpSpkn__FPCvT0 */
undefined4 DrawHaloSpks(VECTOR * arg0, int arg1, SPKS * arg2, SPKD * arg3, RPL * arg4); /* 0x1D5678 DrawHaloSpks__FP6VECTORiP4SPKSP4SPKDP3RPL */
undefined4 DrawJtHaloElectric(RPL * arg0); /* 0x1D5FA8 DrawJtHaloElectric__FP3RPL */
undefined4 DrawJtHaloFire(RPL * arg0); /* 0x1D60B0 DrawJtHaloFire__FP3RPL */
int FUN_001d61c8(RPL * arg0); /* 0x1D61C8 FUN_001d61c8__FP3RPL */
undefined4 RenderJtSelfZap(JT * arg0, CM * arg1, RO * arg2); /* 0x1D62E0 RenderJtSelfZap__FP2JTP2CMP2RO */
undefined4 JthsCurrentJt(JT * arg0); /* 0x1D65D8 JthsCurrentJt__FP2JT */
undefined4 UseJtCharm(JT * arg0); /* 0x1D6608 UseJtCharm__FP2JT */
undefined4 UpdateJtWater(JT * arg0); /* 0x1D66A8 UpdateJtWater__FP2JT */
int FFindJtWaterSurface(JT * arg0, WATER * arg1, VECTOR * arg2); /* 0x1D6A18 FFindJtWaterSurface__FP2JTP5WATERP6VECTOR */
undefined4 AddJtWaterAcceleration(JT * arg0, WATER * arg1, float arg2); /* 0x1D6B18 AddJtWaterAcceleration__FP2JTP5WATERf */
undefined4 InitZpr(ZPR * arg0, ZPK arg1, LO * arg2); /* 0x1D7098 InitZpr__FP3ZPR3ZPKP2LO */
void OSTRM_constructor(OSTRM *this, int arg1); /* 0x1D7100 __5OSTRMi */
void OSTRM_constructor_2(OSTRM *this, void * arg1, int arg2); /* 0x1D7120 __5OSTRMPvi */
void OSTRM_destructor(OSTRM *this); /* 0x1D7148 _$_5OSTRM */
undefined4 OSTRM_CbWrite(OSTRM *this, void * arg1, int arg2); /* 0x1D7190 CbWrite__5OSTRMPvi */
undefined4 OSTRM_Flush(OSTRM *this); /* 0x1D72C8 Flush__5OSTRM */
undefined4 InitSuv(SUV * arg0); /* 0x1D73A8 InitSuv__FP3SUV */
void * PostSuvLoad(SUV * arg0); /* 0x1D7440 PostSuvLoad__FP3SUV */
void * PresetSuvAccel(SUV * arg0, float arg1); /* 0x1D7778 PresetSuvAccel__FP3SUVf */
float GExcludeAlm(int arg0, LM * arg1, float arg2); /* 0x1D8470 GExcludeAlm__FiP2LMf */
undefined4 UpdateSuvBalance(SUV * arg0); /* 0x1D8578 UpdateSuvBalance__FP3SUV */
undefined4 DsGetTrackRelative(float arg0, float arg1, float arg2); /* 0x1D86F8 DsGetTrackRelative__Ffff */
int FIsSuvAheadOf(SUV * arg0, SUV * arg1); /* 0x1D8740 FIsSuvAheadOf__FP3SUVT0 */
undefined4 UpdateSuvLine(SUV * arg0, int * arg1); /* 0x1D87C8 UpdateSuvLine__FP3SUVPi */
undefined4 UpdateSuvHeading(SUV * arg0); /* 0x1D8BD0 UpdateSuvHeading__FP3SUV */
undefined4 UpdateSuvWheels(SUV * arg0); /* 0x1D8D90 UpdateSuvWheels__FP3SUV */
undefined4 UpdateSuvExpls(SUV * arg0); /* 0x1D8E40 UpdateSuvExpls__FP3SUV */
undefined4 BoostSuv(SUV * arg0); /* 0x1D92F0 BoostSuv__FP3SUV */
undefined4 UpdateSuvVolumes(SUV * arg0, int arg1); /* 0x1D9488 UpdateSuvVolumes__FP3SUVi */
undefined4 UpdateSuvSounds(SUV * arg0, float arg1); /* 0x1D9678 UpdateSuvSounds__FP3SUVf */
undefined4 UpdateSuvPuncher(SUV * arg0); /* 0x1D9AC8 UpdateSuvPuncher__FP3SUV */
undefined4 UpdateSuv(SUV * arg0, float arg1); /* 0x1D9C98 UpdateSuv__FP3SUVf */
undefined4 UpdateSuvActive(SUV * arg0, JOY * arg1, float arg2); /* 0x1D9D78 UpdateSuvActive__FP3SUVP3JOYf */
undefined4 UpdateSuvInternalXps(SUV * arg0); /* 0x1DA310 UpdateSuvInternalXps__FP3SUV */
undefined4 AddSuvCustomXps(SUV * arg0, SO * arg1, int arg2, BSP * arg3, BSP * arg4, XP * * arg5); /* 0x1DA320 AddSuvCustomXps__FP3SUVP2SOiP3BSPT3PP2XP */
undefined4 AdjustSuvNewXp(SUV * arg0, XP * arg1, int arg2); /* 0x1DA6E0 AdjustSuvNewXp__FP3SUVP2XPi */
undefined4 UpdateSuvInfluences(SUV * arg0, RO * arg1); /* 0x1DA7E0 UpdateSuvInfluences__FP3SUVP2RO */
undefined4 RenderSuvSelf(SUV * arg0, CM * arg1, RO * arg2); /* 0x1DAA18 RenderSuvSelf__FP3SUVP2CMP2RO */
undefined4 UpdateSuvBounds(SUV * arg0); /* 0x1DAC20 UpdateSuvBounds__FP3SUV */
undefined4 CollectSuvPrize(SUV * arg0, PCK arg1, ALO * arg2); /* 0x1DACB0 CollectSuvPrize__FP3SUV3PCKP3ALO */
undefined4 UpdateSuvShapes(SUV * arg0); /* 0x1DAD28 UpdateSuvShapes__FP3SUV */
undefined4 UpdateSuvXfWorld(SUV * arg0); /* 0x1DAE18 UpdateSuvXfWorld__FP3SUV */
undefined4 GetSuvCpdefi(SUV * arg0, float arg1, CPDEFI * arg2); /* 0x1DAE48 GetSuvCpdefi__FP3SUVfP6CPDEFI */
undefined4 OnSuvActive(SUV * arg0, int arg1, PO * arg2); /* 0x1DAE68 OnSuvActive__FP3SUViP2PO */
undefined4 HandleSuvMessage(SUV * arg0, MSGID arg1, void * arg2); /* 0x1DAF08 HandleSuvMessage__FP3SUV5MSGIDPv */
undefined4 SetSuvTrack(SUV * arg0, SHAPE * arg1); /* 0x1DAFB8 SetSuvTrack__FP3SUVP5SHAPE */
undefined4 SetSuvLine(SUV * arg0, SHAPE * arg1); /* 0x1DB0C8 SetSuvLine__FP3SUVP5SHAPE */
undefined4 AddSuvCheckPoint(SUV * arg0, VOL * arg1); /* 0x1DB110 AddSuvCheckPoint__FP3SUVP3VOL */
undefined4 AddSuvFeature(SUV * arg0, VOL * arg1, float arg2, float arg3, EXPL * arg4, EXPL * arg5); /* 0x1DB1E8 AddSuvFeature__FP3SUVP3VOLffP4EXPLT4 */
undefined4 SetSuvSuvs(SUV * arg0, SUVS arg1); /* 0x1DB238 SetSuvSuvs__FP3SUV4SUVS */
undefined4 ResetSuv(SUV * arg0); /* 0x1DB290 ResetSuv__FP3SUV */
undefined4 VecCombo(VU_FLOAT arg0, VU_VECTOR arg1, VU_FLOAT arg2, VU_VECTOR arg3); /* 0x1DB460 VecCombo__FG8VU_FLOATG9VU_VECTORT0T1 */
undefined4 InitSwDlHash(SW * arg0); /* 0x1DB480 InitSwDlHash__FP2SW */
undefined4 InitSw(SW * arg0); /* 0x1DB4C8 InitSw__FP2SW */
undefined4 DeleteSw(SW * arg0); /* 0x1DB838 DeleteSw__FP2SW */
undefined4 SetupBulkDataFromBrx(int arg0, CBinaryInputStream * arg1); /* 0x1DB928 SetupBulkDataFromBrx__FiP18CBinaryInputStream */
undefined4 LoadBulkDataFromBrx(CBinaryInputStream * arg0); /* 0x1DBA38 LoadBulkDataFromBrx__FP18CBinaryInputStream */
undefined4 SetSwGravity(SW * arg0, float arg1); /* 0x1DBA90 SetSwGravity__FP2SWf */
int FUN_001dbae0(SW * arg0, int arg1); /* 0x1DBAE0 FUN_001dbae0__FP2SWi */
int FUN_001dbb00(SW * arg0, int arg1, int arg2); /* 0x1DBB00 FUN_001dbb00__FP2SWii */
int FOverflowSwLo(SW * arg0, LO * arg1, int arg2); /* 0x1DBB20 FOverflowSwLo__FP2SWP2LOi */
void * PxaAllocSw(SW * arg0); /* 0x1DBB50 PxaAllocSw__FP2SW */
undefined4 FreeSwXaList(SW * arg0, XA * arg1); /* 0x1DBB90 FreeSwXaList__FP2SWP2XA */
void * PmqAllocSw(SW * arg0); /* 0x1DBBD8 PmqAllocSw__FP2SW */
undefined4 FreeSwMqList(SW * arg0, MQ * arg1); /* 0x1DBC18 FreeSwMqList__FP2SWP2MQ */
undefined4 EnsureSwCallback(SW * arg0, void (*arg1)(void *, MSGID, void *), void * arg2, MSGID arg3, void * arg4); /* 0x1DBC60 EnsureSwCallback__FP2SWPFPv5MSGIDPv_vPv5MSGIDT2 */
void * PostSwCallback(SW * arg0, void (*arg1)(void *, MSGID, void *), void * arg2, MSGID arg3, void * arg4); /* 0x1DBCC8 PostSwCallback__FP2SWPFPv5MSGIDPv_vPv5MSGIDT2 */
undefined4 ClearSwCallbacks(SW * arg0, int arg1, void (*arg2)(void *, MSGID, void *), void * arg3, MSGID arg4, void * arg5); /* 0x1DBD40 ClearSwCallbacks__FP2SWiPFPv5MSGIDPv_vPv5MSGIDT3 */
void * ProcessSwCallbacks(SW * arg0); /* 0x1DBE48 ProcessSwCallbacks__FP2SW */
void * ProcessSwSpliceScheduledCallbacks(SW * arg0, float arg1); /* 0x1DBEC8 ProcessSwSpliceScheduledCallbacks__FP2SWf */
void * PstsoAllocSw(SW * arg0); /* 0x1DC0C8 PstsoAllocSw__FP2SW */
undefined4 FreeSwStsoList(SW * arg0, STSO * arg1); /* 0x1DC108 FreeSwStsoList__FP2SWP4STSO */
undefined4 AddSwProxySource(SW * arg0, LO * arg1, int arg2); /* 0x1DC150 AddSwProxySource__FP2SWP2LOi */
void * PloGetSwProxySource(SW * arg0, int arg1); /* 0x1DC208 PloGetSwProxySource__FP2SWi */
undefined4 IntersectSwBoundingBox(SW * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3, int (*arg4)(void *, SO *), void * arg5, int * arg6, SO * * * arg7); /* 0x1DC238 IntersectSwBoundingBox__FP2SWP2SOP6VECTORT2PFPvP2SO_iPvPiPPP2SO */
undefined4 IntersectSwBoundingSphere(SW * arg0, SO * arg1, VECTOR * arg2, float arg3, int (*arg4)(void *, SO *), void * arg5, int * arg6, SO * * * arg7); /* 0x1DC4D0 IntersectSwBoundingSphere__FP2SWP2SOP6VECTORfPFPvP2SO_iPvPiPPP2SO */
undefined4 RemoveOxa(OXA * arg0, OXA * * arg1); /* 0x1DC710 RemoveOxa__FP3OXAPP3OXA */
undefined4 InitSwAoxa(SW * arg0); /* 0x1DC740 InitSwAoxa__FP2SW */
undefined4 AddOxa(OXA * arg0, OXA * * arg1); /* 0x1DC7B0 AddOxa__FP3OXAPP3OXA */
void * PoxaAllocSw(SW * arg0, SO * arg1); /* 0x1DC7D0 PoxaAllocSw__FP2SWP2SO */
undefined4 FreeSwPoxa(SW * arg0, OXA * arg1); /* 0x1DC828 FreeSwPoxa__FP2SWP3OXA */
undefined4 CreateSwDefaultLights(SW * arg0); /* 0x1DC9A0 CreateSwDefaultLights__FP2SW */
int FUN_001dccc0(CBinaryInputStream * arg0); /* 0x1DCCC0 FUN_001dccc0__FP18CBinaryInputStream */
undefined4 CreateSwPrizes(SW * arg0); /* 0x1DCD28 CreateSwPrizes__FP2SW */
undefined4 LoadSwFromBrx(SW * arg0, CBinaryInputStream * arg1); /* 0x1DCEA0 LoadSwFromBrx__FP2SWP18CBinaryInputStream */
int FClipLineHomogeneous(VECTOR4 * arg0); /* 0x1DD218 FClipLineHomogeneous__FP7VECTOR4 */
undefined4 DrawLineWorld(VECTOR * arg0, VECTOR * arg1, RGBA arg2, CM * arg3, int arg4); /* 0x1DD3E0 DrawLineWorld__FP6VECTORT0G4RGBAP2CMi */
undefined4 DrawAxesWorld(VECTOR * arg0, MATRIX3 * arg1, float arg2, CM * arg3, int arg4); /* 0x1DD548 DrawAxesWorld__FP6VECTORP7MATRIX3fP2CMi */
undefined4 SetSwIllum(SW * arg0, float arg1); /* 0x1DD5F8 SetSwIllum__FP2SWf */
undefined4 SetSwIllumShadow(SW * arg0, float arg1); /* 0x1DD610 SetSwIllumShadow__FP2SWf */
undefined4 SetSwExcitement(SW * arg0, float arg1); /* 0x1DD628 SetSwExcitement__FP2SWf */
int FLevelSwVisited(SW * arg0, WID arg1); /* 0x1DD690 FLevelSwVisited__FP2SW3WID */
int FLevelSwPrimary(SW * arg0, WID arg1); /* 0x1DD6B0 FLevelSwPrimary__FP2SW3WID */
int FLevelSwSecondary(SW * arg0, WID arg1); /* 0x1DD6D0 FLevelSwSecondary__FP2SW3WID */
int FLevelSwTertiary(SW * arg0, WID arg1); /* 0x1DD6F0 FLevelSwTertiary__FP2SW3WID */
int FUN_001dd8e8(SW * arg0, GAMEWORLD arg1); /* 0x1DD8E8 FUN_001dd8e8__FP2SW9GAMEWORLD */
int FUN_001dd908(SW * arg0, GAMEWORLD arg1); /* 0x1DD908 FUN_001dd908__FP2SW9GAMEWORLD */
int FUN_001dd9a0(float arg0); /* 0x1DD9A0 FUN_001dd9a0__Ff */
int FUN_001dd9c0(void * arg0, float * arg1); /* 0x1DD9C0 FUN_001dd9c0__FPvPf */
undefined4 SetSwPlayerSuck(SW * arg0, float arg1); /* 0x1DD9D8 SetSwPlayerSuck__FP2SWf */
undefined4 GetSwPlayerSuck(SW * arg0, float * arg1); /* 0x1DDA08 GetSwPlayerSuck__FP2SWPf */
undefined4 IncrementSwHandsOff(SW * arg0); /* 0x1DDA20 IncrementSwHandsOff__FP2SW */
undefined4 DecrementSwHandsOff(SW * arg0); /* 0x1DDA50 DecrementSwHandsOff__FP2SW */
undefined4 IsSwHandsOff(SW * arg0); /* 0x1DDA80 IsSwHandsOff__FP2SW */
undefined4 IsSwVagPlaying(SW * arg0, int * arg1); /* 0x1DDA90 IsSwVagPlaying__FP2SWPi */
undefined4 SetSwDarken(SW * arg0, float arg1); /* 0x1DDAB8 SetSwDarken__FP2SWf */
undefined4 SetSwDarkenSmooth(SW * arg0, float arg1); /* 0x1DDAC8 SetSwDarkenSmooth__FP2SWf */
undefined4 CancelSwDialogPlaying(SW * arg0); /* 0x1DDAD0 CancelSwDialogPlaying__FP2SW */
int FUN_001ddc38(SW * arg0, LO * arg1); /* 0x1DDC38 FUN_001ddc38__FP2SWP2LO */
int FUN_001ddc78(void * arg0, int arg1); /* 0x1DDC78 FUN_001ddc78__FPvi */
undefined4 InitTail(TAIL * arg0); /* 0x1DDCE0 InitTail__FP4TAIL */
void * PostTailLoad(TAIL * arg0); /* 0x1DDD18 PostTailLoad__FP4TAIL */
undefined4 UpdateTailConstraints(TAIL * arg0); /* 0x1DDE90 UpdateTailConstraints__FP4TAIL */
undefined4 MatchTailOtherObject(TAIL * arg0, ALO * arg1); /* 0x1DE768 MatchTailOtherObject__FP4TAILP3ALO */
undefined4 InitTank(TANK * arg0); /* 0x1DE798 InitTank__FP4TANK */
void * PostTankLoad(TANK * arg0); /* 0x1DE808 PostTankLoad__FP4TANK */
undefined4 UpdateTank(TANK * arg0, float arg1); /* 0x1DE910 UpdateTank__FP4TANKf */
undefined4 UseTankCharm(TANK * arg0); /* 0x1DEBB8 UseTankCharm__FP4TANK */
undefined4 UpdateTankActive(TANK * arg0, JOY * arg1, float arg2); /* 0x1DEBE8 UpdateTankActive__FP4TANKP3JOYf */
undefined4 OnTankActive(TANK * arg0, int arg1, PO * arg2); /* 0x1DF290 OnTankActive__FP4TANKiP2PO */
undefined4 RenderTankAll(TANK * arg0, CM * arg1, RO * arg2); /* 0x1DF2C8 RenderTankAll__FP4TANKP2CMP2RO */
undefined4 ImpactTank(TANK * arg0, int arg1); /* 0x1DF520 ImpactTank__FP4TANKi */
int FInvulnerableTank(TANK * arg0, ZPK arg1); /* 0x1DF5A0 FInvulnerableTank__FP4TANK3ZPK */
undefined4 ApplyTankThrow(TANK * arg0, PO * arg1); /* 0x1DF600 ApplyTankThrow__FP4TANKP2PO */
int FTakeTankDamage(TANK * arg0, ZPR * arg1); /* 0x1DF700 FTakeTankDamage__FP4TANKP3ZPR */
undefined4 AdjustTankNewXp(TANK * arg0, XP * arg1, int arg2); /* 0x1DFA40 AdjustTankNewXp__FP4TANKP2XPi */
undefined4 HandleTankMessage(TANK * arg0, MSGID arg1, void * arg2); /* 0x1DFB08 HandleTankMessage__FP4TANK5MSGIDPv */
undefined4 JthsCurrentTank(TANK * arg0); /* 0x1DFBD0 JthsCurrentTank__FP4TANK */
undefined4 SetTankTanks(TANK * arg0, TANKS arg1); /* 0x1DFBE0 SetTankTanks__FP4TANK5TANKS */
undefined4 StartupTarget(void); /* 0x1DFD48 StartupTarget__Fv */
undefined4 ResetTargetList(void); /* 0x1DFD70 ResetTargetList__Fv */
undefined4 InitTarget(TARGET * arg0); /* 0x1DFD90 InitTarget__FP6TARGET */
undefined4 OnTargetAdd(TARGET * arg0); /* 0x1DFDC8 OnTargetAdd__FP6TARGET */
undefined4 OnTargetRemove(TARGET * arg0); /* 0x1DFE00 OnTargetRemove__FP6TARGET */
undefined4 CloneTarget(TARGET * arg0, TARGET * arg1); /* 0x1DFE38 CloneTarget__FP6TARGETT0 */
undefined4 CchParsePchzInt(char * arg0, int * arg1); /* 0x1E08F8 CchParsePchzInt__FPcPi */
undefined4 CchParsePchzTft(char * arg0, TFT * arg1, char * * arg2); /* 0x1E0978 CchParsePchzTft__FPcP3TFTPPc */
undefined4 WriteTftPchz(TFT * arg0, OSTRM * arg1, char * arg2); /* 0x1E0CD0 WriteTftPchz__FP3TFTP5OSTRMPc */
int FNegTftUl(TFT * arg0, UL * arg1); /* 0x1E0E18 FNegTftUl__FP3TFTP2UL */
undefined4 UnRadixFromChConversion(char arg0); /* 0x1E0EF8 UnRadixFromChConversion__Fc */
undefined4 CchAchFromUl(char * arg0, int arg1, unsigned long arg2, unsigned int arg3); /* 0x1E0F58 CchAchFromUl__FPciUlUi */
undefined4 WriteTftUl(TFT * arg0, OSTRM * arg1, unsigned long arg2); /* 0x1E1028 WriteTftUl__FP3TFTP5OSTRMUl */
undefined4 ExpFirstFromG(double arg0); /* 0x1E1330 ExpFirstFromG__Fd */
undefined4 ChDigitFromG(double arg0, int arg1, int arg2); /* 0x1E13D0 ChDigitFromG__Fdii */
undefined4 CchAchFromDouble(char * arg0, int arg1, TFT * arg2, double arg3); /* 0x1E1498 CchAchFromDouble__FPciP3TFTd */
undefined4 WriteTftDouble(TFT * arg0, OSTRM * arg1, double arg2); /* 0x1E17A8 WriteTftDouble__FP3TFTP5OSTRMd */
undefined4 WriteTft(TFT * arg0, OSTRM * arg1, char * * arg2, char * arg3, int arg4); /* 0x1E1A08 WriteTft__FP3TFTP5OSTRMPPcPci */
undefined4 CchOstrmPrintf(OSTRM * arg0, char * arg1, char * arg2); /* 0x1E1DB8 CchOstrmPrintf__FP5OSTRMPcT1 */
undefined4 UpperizePchz(char * arg0); /* 0x1E2218 UpperizePchz__FPc */
undefined4 SemaCreate(int arg0, int arg1); /* 0x1E2268 SemaCreate__Fii */
undefined4 InitCritSect(CRITSECT * arg0); /* 0x1E22C0 InitCritSect__FP8CRITSECT */
undefined4 EnterCritSect(CRITSECT * arg0); /* 0x1E22F8 EnterCritSect__FP8CRITSECT */
undefined4 LeaveCritSect(CRITSECT * arg0); /* 0x1E2358 LeaveCritSect__FP8CRITSECT */
undefined4 StartupThread(void); /* 0x1E2398 StartupThread__Fv */
void * PtnfnFromTn(TN * arg0); /* 0x1E2420 PtnfnFromTn__FP2TN */
undefined4 GetTnfnNose(TNFN * arg0, CPDEFI * arg1, VECTOR * arg2, TN * arg3); /* 0x1E2438 GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN */
undefined4 InitTn(TN * arg0); /* 0x1E2520 InitTn__FP2TN */
undefined4 OnTnRemove(TN * arg0); /* 0x1E25F8 OnTnRemove__FP2TN */
undefined4 LoadTnFromBrx(TN * arg0, CBinaryInputStream * arg1); /* 0x1E2648 LoadTnFromBrx__FP2TNP18CBinaryInputStream */
void * PostTnLoad(TN * arg0); /* 0x1E2758 PostTnLoad__FP2TN */
undefined4 SetTnTns(TN * arg0, TNS arg1); /* 0x1E2778 SetTnTns__FP2TN3TNS */
int FUN_001e2840(TN * arg0, TNS arg1); /* 0x1E2840 FUN_001e2840__FP2TN3TNS */
undefined4 UpdateTnCallback(TN * arg0, MSGID arg1, void * arg2); /* 0x1E2870 UpdateTnCallback__FP2TN5MSGIDPv */
undefined4 UpdateTn(TN * arg0, float arg1); /* 0x1E2940 UpdateTn__FP2TNf */
undefined4 RenderTnSelf(TN * arg0, CM * arg1, RO * arg2); /* 0x1E2988 RenderTnSelf__FP2TNP2CMP2RO */
undefined4 FreezeTn(TN * arg0, int arg1); /* 0x1E29A8 FreezeTn__FP2TNi */
undefined4 CalculateTnCrv(TN * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1E2A00 CalculateTnCrv__FP2TNP6VECTORN21 */
undefined4 CalculateTnPos(TN * arg0, VECTOR * arg1, float arg2, float arg3, CLQ * arg4, LM * arg5, FTND arg6, VECTOR * arg7); /* 0x1E2BF0 CalculateTnPos__FP2TNP6VECTORffP3CLQP2LM4FTNDT1 */
undefined4 ActivateCptn(CPTN * arg0, void * arg1); /* 0x1E2E68 ActivateCptn__FP4CPTNPv */
undefined4 DeactivateCptn(CPTN * arg0, void * arg1); /* 0x1E30A0 DeactivateCptn__FP4CPTNPv */
undefined4 SetCptn(CPTN * arg0, void * arg1); /* 0x1E30D8 SetCptn__FP4CPTNPv */
undefined4 RevokeCptn(CPTN * arg0, void * arg1); /* 0x1E30E0 RevokeCptn__FP4CPTNPv */
undefined4 UpdateCptn(CPTN * arg0, CPDEFI * arg1, JOY * arg2, float arg3); /* 0x1E31F0 UpdateCptn__FP4CPTNP6CPDEFIP3JOYf */
undefined4 LoadTbspFromBrx(CBinaryInputStream * arg0, int * arg1, TSURF * * arg2, int * arg3, TBSP * * arg4); /* 0x1E4C48 LoadTbspFromBrx__FP18CBinaryInputStreamPiPP5TSURFT1PP4TBSP */
int FCheckTbspPoint(TBSP * arg0, VECTOR * arg1); /* 0x1E4DC0 FCheckTbspPoint__FP4TBSPP6VECTOR */
void CTransition_constructor(CTransition *this); /* 0x1E4E38 __11CTransition */
undefined4 CTransition_Set(CTransition *this, char * arg1, OID arg2, OID arg3, int arg4); /* 0x1E4E80 Set__11CTransitionPc3OIDT2i */
undefined4 CTransition_Execute(CTransition *this); /* 0x1E4EA8 Execute__11CTransition */
undefined4 ResetWorld(FTRANS arg0); /* 0x1E5278 ResetWorld__F6FTRANS */
undefined4 InitTurret(TURRET * arg0); /* 0x1E5378 InitTurret__FP6TURRET */
void * PostTurretLoad(TURRET * arg0); /* 0x1E5428 PostTurretLoad__FP6TURRET */
undefined4 UpdateTurret(TURRET * arg0, float arg1); /* 0x1E55D0 UpdateTurret__FP6TURRETf */
undefined4 UpdateTurretActive(TURRET * arg0, JOY * arg1, float arg2); /* 0x1E56A0 UpdateTurretActive__FP6TURRETP3JOYf */
undefined4 OnTurretActive(TURRET * arg0, int arg1, PO * arg2); /* 0x1E5750 OnTurretActive__FP6TURRETiP2PO */
int FFilterTurret(TURRET * arg0, SO * arg1); /* 0x1E5888 FFilterTurret__FP6TURRETP2SO */
undefined4 UpdateTurretAim(TURRET * arg0); /* 0x1E5938 UpdateTurretAim__FP6TURRET */
undefined4 FireTurret(TURRET * arg0); /* 0x1E5C78 FireTurret__FP6TURRET */
undefined4 HandleTurretMessage(TURRET * arg0, MSGID arg1, void * arg2); /* 0x1E5CE8 HandleTurretMessage__FP6TURRET5MSGIDPv */
int FIgnoreTurretIntersection(TURRET * arg0, SO * arg1); /* 0x1E5DA8 FIgnoreTurretIntersection__FP6TURRETP2SO */
undefined4 CollectTurretPrize(TURRET * arg0, PCK arg1, ALO * arg2); /* 0x1E5E08 CollectTurretPrize__FP6TURRET3PCKP3ALO */
undefined4 GetTurretDiapi(TURRET * arg0, DIALOG * arg1, DIAPI * arg2); /* 0x1E5E50 GetTurretDiapi__FP6TURRETP6DIALOGP5DIAPI */
undefined4 InitTv(TV * arg0, BLOTK arg1); /* 0x1E5E70 InitTv__FP2TV5BLOTK */
void * PostTvLoad(TV * arg0); /* 0x1E6188 PostTvLoad__FP2TV */
undefined4 GetTvItvbMinMax(TV * arg0, int * arg1, int * arg2); /* 0x1E6268 GetTvItvbMinMax__FP2TVPiT1 */
undefined4 DrawTvArea(TV * arg0, GIFS * arg1, int arg2); /* 0x1E62A8 DrawTvArea__FP2TVR4GIFSi */
undefined4 DrawTvBands(TV * arg0, GIFS * arg1); /* 0x1E6600 DrawTvBands__FP2TVR4GIFS */
undefined4 DrawTvOutline(TV * arg0, GIFS * arg1); /* 0x1E6C20 DrawTvOutline__FP2TVR4GIFS */
undefined4 DrawTv(TV * arg0); /* 0x1E73B8 DrawTv__FP2TV */
undefined4 SetTvTvs(TV * arg0, TVS arg1); /* 0x1E7440 SetTvTvs__FP2TV3TVS */
undefined4 AcceptTvSpeaker(TV * arg0); /* 0x1E7460 AcceptTvSpeaker__FP2TV */
undefined4 SetTvTvgs(TV * arg0, TVGS arg1); /* 0x1E7518 SetTvTvgs__FP2TV4TVGS */
undefined4 SetTvBlots(TV * arg0, BLOTS arg1); /* 0x1E76E0 SetTvBlots__FP2TV5BLOTS */
undefined4 UpdateTv(TV * arg0); /* 0x1E77C0 UpdateTv__FP2TV */
undefined4 RenderTv(TV * arg0); /* 0x1E7C60 RenderTv__FP2TV */
void * PreTvContext(RPL * arg0); /* 0x1E80D8 PreTvContext__FP3RPL */
void * PostTvContext(RPL * arg0); /* 0x1E83E0 PostTvContext__FP3RPL */
undefined4 SetTvSpeaker(TV * arg0, SPEAKER * arg1); /* 0x1E86E0 SetTvSpeaker__FP2TVP7SPEAKER */
undefined4 SetTvReplace(TV * arg0, ALO * arg1); /* 0x1E87F0 SetTvReplace__FP2TVP3ALO */
undefined4 OnTvReset(TV * arg0); /* 0x1E8840 OnTvReset__FP2TV */
undefined4 InitUbg(UBG * arg0); /* 0x1E88D0 InitUbg__FP3UBG */
void * PostUbgLoad(UBG * arg0); /* 0x1E8948 PostUbgLoad__FP3UBG */
void * PsoPadUbgClosest(UBG * arg0, VECTOR * arg1); /* 0x1E89F0 PsoPadUbgClosest__FP3UBGP6VECTOR */
undefined4 OnUbgEnteringSgs(UBG * arg0, SGS arg1, ASEG * arg2); /* 0x1E8A50 OnUbgEnteringSgs__FP3UBG3SGSP4ASEG */
undefined4 SgsNextUbgAI(UBG * arg0); /* 0x1E8D58 SgsNextUbgAI__FP3UBG */
int FDetectUbg(UBG * arg0); /* 0x1E8DB0 FDetectUbg__FP3UBG */
int FCanUbgAttack(UBG * arg0); /* 0x1E8DD0 FCanUbgAttack__FP3UBG */
undefined4 DoUbgFreefallJump(UBG * arg0); /* 0x1E8E08 DoUbgFreefallJump__FP3UBG */
undefined4 DoUbgFreefallLanding(UBG * arg0); /* 0x1E8E48 DoUbgFreefallLanding__FP3UBG */
undefined4 UpdateUbgGoal(UBG * arg0, int arg1); /* 0x1E8EF8 UpdateUbgGoal__FP3UBGi */
undefined4 UpdateUbgSgs(UBG * arg0); /* 0x1E8FA8 UpdateUbgSgs__FP3UBG */
int FIgnoreUbgIntersection(UBG * arg0, SO * arg1); /* 0x1E9038 FIgnoreUbgIntersection__FP3UBGP2SO */
undefined4 StartupUi(void); /* 0x1E9088 StartupUi__Fv */
undefined4 InitUi(UI * arg0); /* 0x1E90A8 InitUi__FP2UI */
void * PostUiLoad(UI * arg0); /* 0x1E90E8 PostUiLoad__FP2UI */
undefined4 UpdateUi(UI * arg0); /* 0x1E9108 UpdateUi__FP2UI */
void * PushUiActiveBlot(UI * arg0, BLOT * arg1); /* 0x1E9498 PushUiActiveBlot__FP2UIP4BLOT */
void * PopUiActiveBlot(UI * arg0); /* 0x1E9570 PopUiActiveBlot__FP2UI */
undefined4 DrawUi(void); /* 0x1E9648 DrawUi__Fv */
undefined4 RenderUi(void); /* 0x1E9668 RenderUi__Fv */
undefined4 ResetUi(UI * arg0); /* 0x1E9688 ResetUi__FP2UI */
undefined4 SetUiUis(UI * arg0, UIS arg1); /* 0x1E96F8 SetUiUis__FP2UI3UIS */
undefined4 SetUiUPause(UI * arg0, float arg1); /* 0x1E98E8 SetUiUPause__FP2UIf */
int FUN_001e9970(void); /* 0x1E9970 FUN_001e9970__Fv */
int FUN_001e9a10(void); /* 0x1E9A10 FUN_001e9a10__Fv */
int FUN_001e9a68(void); /* 0x1E9A68 FUN_001e9a68__Fv */
int FUN_001e9ad8(void); /* 0x1E9AD8 FUN_001e9ad8__Fv */
undefined4 UpdateSwObjects(SW * arg0, float arg1); /* 0x1E9C78 UpdateSwObjects__FP2SWf */
undefined4 UpdateSwPosWorldPrev(SW * arg0); /* 0x1E9E30 UpdateSwPosWorldPrev__FP2SW */
undefined4 UpdateSwRealClock(SW * arg0, float arg1); /* 0x1E9EE8 UpdateSwRealClock__FP2SWf */
undefined4 UpdateSwDarkening(SW * arg0, float arg1); /* 0x1EA0A8 UpdateSwDarkening__FP2SWf */
undefined4 UpdateSw(SW * arg0, float arg1); /* 0x1EA118 UpdateSw__FP2SWf */
float RadNormalize(float arg0); /* 0x1EA408 RadNormalize__Ff */
float GLimitAbs(float arg0, float arg1); /* 0x1EA480 GLimitAbs__Fff */
float GSmooth(float arg0, float arg1, float arg2, SMP * arg3, float * arg4); /* 0x1EA4B8 GSmooth__FfffP3SMPPf */
float GSmoothA(float arg0, float arg1, float arg2, float arg3, SMPA * arg4, float * arg5); /* 0x1EA620 GSmoothA__FffffP4SMPAPf */
float RadSmooth(float arg0, float arg1, float arg2, SMP * arg3, float * arg4); /* 0x1EA728 RadSmooth__FfffP3SMPPf */
float RadSmoothA(float arg0, float arg1, float arg2, float arg3, SMPA * arg4, float * arg5); /* 0x1EA798 RadSmoothA__FffffP4SMPAPf */
undefined4 NRandInRange(int arg0, int arg1); /* 0x1EAA70 NRandInRange__Fii */
float GRandInRange(float arg0, float arg1); /* 0x1EAAE0 GRandInRange__Fff */
float GRandGaussian(float arg0, float arg1, float arg2); /* 0x1EAB48 GRandGaussian__Ffff */
int FFloatsNear(float arg0, float arg1, float arg2); /* 0x1EAC68 FFloatsNear__Ffff */
int CSolveQuadratic(float arg0, float arg1, float arg2, float * arg3); /* 0x1EACA0 CSolveQuadratic__FfffPf */
undefined4 PrescaleClq(CLQ * arg0, float arg1, float arg2, CLQ * arg3); /* 0x1EAD30 PrescaleClq__FP3CLQffT0 */
undefined4 CalculateSinCos(float arg0, float * arg1, float * arg2); /* 0x1EAD88 CalculateSinCos__FfPfT1 */
float GTrunc(double arg0); /* 0x1EAE78 GTrunc__Fd */
float GTrunc_2(float arg0); /* 0x1EAF28 GTrunc__Ff */
float GModPositive(float arg0, float arg1); /* 0x1EAFE0 GModPositive__Fff */
undefined4 FitClq(float arg0, float arg1, float arg2, float arg3, CLQ * arg4); /* 0x1EB018 FitClq__FffffP3CLQ */
int FCheckLm(LM * arg0, float arg1); /* 0x1EB050 FCheckLm__FP2LMf */
int FCheckAlm(int arg0, LM * arg1, float arg2); /* 0x1EB080 FCheckAlm__FiP2LMf */
float GLimitLm(LM * arg0, float arg1); /* 0x1EB0F8 GLimitLm__FP2LMf */
undefined4 SgnCompareG(float * arg0, float * arg1); /* 0x1EB128 SgnCompareG__FPfT0 */
undefined4 Force(void * arg0); /* 0x1EB160 Force__FPv */
undefined4 MinimizeRange(float (*arg0)(void *, float), void * arg1, float arg2, float arg3, float arg4, float arg5, float * arg6, float * arg7); /* 0x1EB168 MinimizeRange__FPFPvf_fPvffffPfT6 */
int FUN_001EB518(SO * arg0, CBinaryInputStream * arg1); /* 0x1EB518 FUN_001EB518__FP2SOP18CBinaryInputStream */
int FUN_001EB550(void * arg0); /* 0x1EB550 FUN_001EB550__FPv */
int FUN_001EB598(ALO * arg0); /* 0x1EB598 FUN_001EB598__FP3ALO */
int FUN_001EB608(PO * arg0, int arg1, PO * arg2); /* 0x1EB608 FUN_001EB608__FP2POiT0 */
int FUN_001EBC88(void * arg0); /* 0x1EBC88 FUN_001EBC88__FPv */
int FUN_001EBCD8(void * arg0, void * arg1); /* 0x1EBCD8 FUN_001EBCD8__FPvT0 */
int FUN_001EBD08(void); /* 0x1EBD08 FUN_001EBD08__Fv */
int FUN_001EBF40(void * arg0, CBinaryInputStream * arg1); /* 0x1EBF40 FUN_001EBF40__FPvP18CBinaryInputStream */
int FUN_001EC098(PO * arg0); /* 0x1EC098 FUN_001EC098__FP2PO */
int FUN_001EC0B8(PO * arg0); /* 0x1EC0B8 FUN_001EC0B8__FP2PO */
int FUN_001EC188(void); /* 0x1EC188 FUN_001EC188__Fv */
int FUN_001EC380(ALO * arg0, CM * arg1, RO * arg2); /* 0x1EC380 FUN_001EC380__FP3ALOP2CMP2RO */
int FUN_001EC478(void * arg0, int arg1); /* 0x1EC478 FUN_001EC478__FPvi */
int FUN_001ECDF8(void * arg0); /* 0x1ECDF8 FUN_001ECDF8__FPv */
int FUN_001ECE98(void * arg0, int arg1); /* 0x1ECE98 FUN_001ECE98__FPvi */
int FUN_001ED018(void * arg0, int arg1); /* 0x1ED018 FUN_001ED018__FPvi */
int FUN_001ED020(void * arg0); /* 0x1ED020 FUN_001ED020__FPv */
int FUN_001ED050(void * arg0, int arg1); /* 0x1ED050 FUN_001ED050__FPvi */
int FUN_001ED070(void * arg0, int arg1); /* 0x1ED070 FUN_001ED070__FPvi */
int FUN_001ED090(void * arg0, void * arg1, void * arg2); /* 0x1ED090 FUN_001ED090__FPvN20 */
int FUN_001ED168(LO * arg0); /* 0x1ED168 FUN_001ED168__FP2LO */
int FUN_001ED198(LO * arg0); /* 0x1ED198 FUN_001ED198__FP2LO */
int FUN_001ED1D8(void * arg0); /* 0x1ED1D8 FUN_001ED1D8__FPv */
int FUN_001ED210(void * arg0); /* 0x1ED210 FUN_001ED210__FPv */
int FUN_001ED318(void * arg0, int * arg1); /* 0x1ED318 FUN_001ED318__FPvPi */
int FUN_001ED4C8(void * arg0, int arg1, void * arg2, float arg3); /* 0x1ED4C8 FUN_001ED4C8__FPviT0f */
int FUN_001ED558(void * arg0, void * arg1, void * arg2, float arg3); /* 0x1ED558 FUN_001ED558__FPvN20f */
int FUN_001ED588(void * arg0, void * arg1, void * arg2, float arg3); /* 0x1ED588 FUN_001ED588__FPvN20f */
int FUN_001ED5B8(void * arg0, void * arg1, float arg2); /* 0x1ED5B8 FUN_001ED5B8__FPvT0f */
int FUN_001ED5D8(void * arg0, void * arg1, float arg2); /* 0x1ED5D8 FUN_001ED5D8__FPvT0f */
int FUN_001ED5F8(void * arg0, void * arg1, float arg2); /* 0x1ED5F8 FUN_001ED5F8__FPvT0f */
int FUN_001ED618(void * arg0, void * arg1, float arg2); /* 0x1ED618 FUN_001ED618__FPvT0f */
undefined4 SetVectorCylind(VECTOR * arg0, float arg1, float arg2, float arg3); /* 0x1ED650 SetVectorCylind__FP6VECTORfff */
undefined4 SetVectorSphere(VECTOR * arg0, float arg1, float arg2, float arg3); /* 0x1ED6B0 SetVectorSphere__FP6VECTORfff */
float SProjectVector(VECTOR * arg0, VECTOR * arg1); /* 0x1ED738 SProjectVector__FP6VECTORT0 */
undefined4 GetNormalVectors(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1ED780 GetNormalVectors__FP6VECTORN30 */
undefined4 GetNormalVector(VECTOR * arg0, VECTOR * arg1); /* 0x1ED840 GetNormalVector__FP6VECTORT0 */
float RadBetweenVectors(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x1ED908 RadBetweenVectors__FP6VECTORN20 */
undefined4 FindClosestPointBetweenLines(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3, float * arg4, float * arg5, VECTOR * arg6); /* 0x1EDA80 FindClosestPointBetweenLines__FP6VECTORN30PfT4T0 */
undefined4 FindClosestPointBetweenLineSegments(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3, VECTOR * arg4, float * arg5, VECTOR * arg6); /* 0x1EDC08 FindClosestPointBetweenLineSegments__FP6VECTORN40PfT0 */
undefined4 CalculateVectorPanTilt(VECTOR * arg0, float * arg1, float * arg2); /* 0x1EDDB0 CalculateVectorPanTilt__FP6VECTORPfT1 */
undefined4 ConvertDeulToW(VECTOR * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x1EDE38 ConvertDeulToW__FP6VECTORN20 */
int FCalculateMuzzleVelocity(VECTOR * arg0, VECTOR * arg1, float arg2, VECTOR * arg3, SO * arg4); /* 0x1EDEF0 FCalculateMuzzleVelocity__FP6VECTORT0fT0P2SO */
int FCalculateMuzzleVelocitySpeed(VECTOR * arg0, VECTOR * arg1, float arg2, VECTOR * arg3, SO * arg4); /* 0x1EE090 FCalculateMuzzleVelocitySpeed__FP6VECTORT0fT0P2SO */
int FCalculateMuzzleVelocityAngle(VECTOR * arg0, VECTOR * arg1, float arg2, VECTOR * arg3, SO * arg4); /* 0x1EE290 FCalculateMuzzleVelocityAngle__FP6VECTORT0fT0P2SO */
undefined4 LimitVectorLength(VECTOR * arg0, float arg1, VECTOR * arg2); /* 0x1EE2B0 LimitVectorLength__FP6VECTORfT0 */
void VIFS_constructor(VIFS *this); /* 0x1EE318 __4VIFS */
undefined4 VIFS_Align(VIFS *this, int arg1); /* 0x1EE368 Align__4VIFSi */
undefined4 VIFS_AddVifBaseOffset(VIFS *this, int arg1, int arg2); /* 0x1EE3B8 AddVifBaseOffset__4VIFSii */
undefined4 VIFS_AddVifMscal(VIFS *this, void * arg1); /* 0x1EE3F0 AddVifMscal__4VIFSPv */
undefined4 VIFS_AddVifMscalf(VIFS *this, void * arg1); /* 0x1EE420 AddVifMscalf__4VIFSPv */
undefined4 VIFS_AddVifFlush(VIFS *this); /* 0x1EE450 AddVifFlush__4VIFS */
undefined4 VIFS_AddVifFlusha(VIFS *this); /* 0x1EE468 AddVifFlusha__4VIFS */
undefined4 VIFS_AddVifFlushe(VIFS *this); /* 0x1EE480 AddVifFlushe__4VIFS */
undefined4 VIFS_AddVifStcycl(VIFS *this, int arg1, int arg2); /* 0x1EE498 AddVifStcycl__4VIFSii */
undefined4 VIFS_AddVifStrow(VIFS *this, QW * arg1); /* 0x1EE4C0 AddVifStrow__4VIFSP2QW */
undefined4 VIFS_AddVifStmask(VIFS *this, unsigned int arg1); /* 0x1EE528 AddVifStmask__4VIFSUi */
undefined4 VIFS_CbUnpackSetup(VIFS *this, UPK arg1, int arg2, int arg3); /* 0x1EE560 CbUnpackSetup__4VIFS3UPKii */
undefined4 VIFS_UnpackHelper(VIFS *this, UPK arg1, int arg2, int arg3, int * arg4, unsigned int * * arg5); /* 0x1EE5C8 UnpackHelper__4VIFS3UPKiiPiPPUi */
undefined4 VIFS_AddVifUnpack(VIFS *this, UPK arg1, int arg2, void * arg3, int arg4); /* 0x1EE668 AddVifUnpack__4VIFS3UPKiPvi */
undefined4 VIFS_AddVifUnpackRefs(VIFS *this, UPK arg1, int arg2, void * arg3, int arg4, void * * * arg5); /* 0x1EE718 AddVifUnpackRefs__4VIFS3UPKiPviPPPv */
undefined4 VIFS_AddVifDirect(VIFS *this, int arg1, QW * arg2, int arg3); /* 0x1EE7D0 AddVifDirect__4VIFSiP2QWi */
undefined4 VIFS_AddVifDirectRefs(VIFS *this, int arg1, QW * arg2, int arg3); /* 0x1EE850 AddVifDirectRefs__4VIFSiP2QWi */
undefined4 VIFS_AddVifGifs(VIFS *this, GIFS * arg1); /* 0x1EE8D0 AddVifGifs__4VIFSP4GIFS */
undefined4 InitVismap(VISMAP * arg0); /* 0x1EE900 InitVismap__FP6VISMAP */
undefined4 LoadVismapFromBrx(VISMAP * arg0, CBinaryInputStream * arg1); /* 0x1EE930 LoadVismapFromBrx__FP6VISMAPP18CBinaryInputStream */
undefined4 GrfzonOneHop(VISMAP * arg0, VBSP * arg1); /* 0x1EE9D0 GrfzonOneHop__FP6VISMAPP4VBSP */
undefined4 ClipVbspSphereOneHop(VISMAP * arg0, VBSP * arg1, VU_VECTOR arg2, float arg3, int * arg4); /* 0x1EEA40 ClipVbspSphereOneHop__FP6VISMAPP4VBSPG9VU_VECTORfPi */
undefined4 ClipVismapSphereOneHop(VISMAP * arg0, VECTOR * arg1, float arg2, int * arg3); /* 0x1EEB60 ClipVismapSphereOneHop__FP6VISMAPP6VECTORfPi */
undefined4 ClipVismapPointNoHop(VISMAP * arg0, VECTOR * arg1, int * arg2); /* 0x1EEBB0 ClipVismapPointNoHop__FP6VISMAPP6VECTORPi */
undefined4 InitWater(WATER * arg0); /* 0x1EEC60 InitWater__FP5WATER */
void * PostWaterLoad(WATER * arg0); /* 0x1EECE0 PostWaterLoad__FP5WATER */
undefined4 CalculateWaterCurrent(WATER * arg0, VECTOR * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1EED68 CalculateWaterCurrent__FP5WATERP6VECTORN21 */
undefined4 UpdateSwXaList(SW * arg0, XA * * arg1); /* 0x1EEE50 UpdateSwXaList__FP2SWPP2XA */
undefined4 UpdateWater(WATER * arg0, float arg1); /* 0x1EEF90 UpdateWater__FP5WATERf */
undefined4 AddWaterExternalAccelerations(WATER * arg0, XA * arg1, float arg2); /* 0x1EF3A8 AddWaterExternalAccelerations__FP5WATERP2XAf */
undefined4 HandleWaterMessage(WATER * arg0, MSGID arg1, void * arg2); /* 0x1EF3D8 HandleWaterMessage__FP5WATER5MSGIDPv */
undefined4 UpdateWaterMergeGroup(WATER * arg0); /* 0x1EF520 UpdateWaterMergeGroup__FP5WATER */
undefined4 UGetWaterSubmerged(WATER * arg0, SO * arg1, VECTOR * arg2, VECTOR * arg3); /* 0x1EF5B8 UGetWaterSubmerged__FP5WATERP2SOP6VECTORT2 */
undefined4 UpdateWaterBounds(WATER * arg0); /* 0x1EF768 UpdateWaterBounds__FP5WATER */
int FInflictWaterZap(WATER * arg0, XP * arg1, ZPR * arg2); /* 0x1EF808 FInflictWaterZap__FP5WATERP2XPP3ZPR */
void * PzpdEnsureWater(WATER * arg0, ENSK arg1); /* 0x1EF828 PzpdEnsureWater__FP5WATER4ENSK */
int FUN_001ef830(WATER * arg0); /* 0x1EF830 FUN_001ef830__FP5WATER */
undefined4 InitWaypoint(WAYPOINT * arg0); /* 0x1EF838 InitWaypoint__FP8WAYPOINT */
void * PostWaypointLoad(WAYPOINT * arg0); /* 0x1EF868 PostWaypointLoad__FP8WAYPOINT */
undefined4 SetWaypointRsmg(WAYPOINT * arg0, int arg1, OID arg2, OID arg3, OID arg4); /* 0x1EF8C0 SetWaypointRsmg__FP8WAYPOINTi3OIDN22 */
undefined4 UpdateWaypoint(WAYPOINT * arg0, float arg1); /* 0x1EF8F8 UpdateWaypoint__FP8WAYPOINTf */
undefined4 SetWaypointWps(WAYPOINT * arg0, WPS arg1); /* 0x1EF900 SetWaypointWps__FP8WAYPOINT3WPS */
undefined4 HandleWaypointMessage(WAYPOINT * arg0, MSGID arg1, void * arg2); /* 0x1EF9C8 HandleWaypointMessage__FP8WAYPOINT5MSGIDPv */
void * PwpsgNew(void); /* 0x1EFA30 PwpsgNew__Fv */
undefined4 AddWpsgWaypoint(WPSG * arg0, WAYPOINT * arg1); /* 0x1EFA60 AddWpsgWaypoint__FP4WPSGP8WAYPOINT */
undefined4 RemoveWpsgWaypoint(WPSG * arg0, WAYPOINT * arg1); /* 0x1EFA88 RemoveWpsgWaypoint__FP4WPSGP8WAYPOINT */
undefined4 UpdateWpsgCallback(WPSG * arg0, MSGID arg1, void * arg2); /* 0x1EFB20 UpdateWpsgCallback__FP4WPSG5MSGIDPv */
undefined4 EnsureWpsgCallback(WPSG * arg0); /* 0x1EFC98 EnsureWpsgCallback__FP4WPSG */
undefined4 InitWipe(WIPE * arg0); /* 0x1EFCE8 InitWipe__FP4WIPE */
undefined4 UpdateWipe(WIPE * arg0, JOY * arg1); /* 0x1EFD10 UpdateWipe__FP4WIPEP3JOY */
undefined4 DrawWipe(WIPE * arg0); /* 0x1EFEE0 DrawWipe__FP4WIPE */
undefined4 ActivateWipe(WIPE * arg0, TRANS * arg1, WIPEK arg2); /* 0x1EFFA0 ActivateWipe__FP4WIPEP5TRANS5WIPEK */
undefined4 SetWipeButtonTrans(WIPE * arg0, TRANS * arg1, WIPEK arg2); /* 0x1F00C0 SetWipeButtonTrans__FP4WIPEP5TRANS5WIPEK */
int FCatchWipeButtonTrans(WIPE * arg0, JOY * arg1, WIPES arg2); /* 0x1F00F0 FCatchWipeButtonTrans__FP4WIPEP3JOY5WIPES */
undefined4 SetWipeWipes(WIPE * arg0, WIPES arg1); /* 0x1F0220 SetWipeWipes__FP4WIPE5WIPES */
void * PostWmLoad(WM * arg0); /* 0x1F0660 PostWmLoad__FP2WM */
undefined4 BindWm(WM * arg0); /* 0x1F0758 BindWm__FP2WM */
undefined4 RefreshWmMoveStats(WM * arg0, WORLDLEVEL arg1); /* 0x1F0878 RefreshWmMoveStats__FP2WM10WORLDLEVEL */
undefined4 ThrowWmDisplayState(WM * arg0, WORLDLEVEL arg1, int arg2); /* 0x1F08F0 ThrowWmDisplayState__FP2WM10WORLDLEVELi */
undefined4 CatchWmDisplayState(WM * arg0); /* 0x1F0908 CatchWmDisplayState__FP2WM */
undefined4 UpdateWm(WM * arg0, float arg1); /* 0x1F0AE0 UpdateWm__FP2WMf */
undefined4 RenderWmAll(WM * arg0, CM * arg1, RO * arg2); /* 0x1F0EB8 RenderWmAll__FP2WMP2CMP2RO */
undefined4 HandleWmMessage(WM * arg0, MSGID arg1, void * arg2); /* 0x1F0F70 HandleWmMessage__FP2WM5MSGIDPv */
undefined4 SetWmWms(WM * arg0, WMS arg1); /* 0x1F1050 SetWmWms__FP2WM3WMS */
undefined4 ShowWm(WM * arg0, WORLDLEVEL arg1, WMS arg2); /* 0x1F1590 ShowWm__FP2WM10WORLDLEVEL3WMS */
undefined4 HideWm(WM * arg0); /* 0x1F1610 HideWm__FP2WM */
undefined4 MoveWm(WM * arg0, WMD arg1); /* 0x1F1648 MoveWm__FP2WM3WMD */
undefined4 GetWmWorldPosScreen(WM * arg0, WORLDLEVEL arg1, VECTOR * arg2); /* 0x1F17A0 GetWmWorldPosScreen__FP2WM10WORLDLEVELP6VECTOR */
undefined4 SetWmCursor(WM * arg0, WORLDLEVEL arg1); /* 0x1F18B0 SetWmCursor__FP2WM10WORLDLEVEL */
void * PostWmcLoad(WMC * arg0); /* 0x1F1960 PostWmcLoad__FP3WMC */
undefined4 UpdateWmcActive(WMC * arg0, JOY * arg1); /* 0x1F1A08 UpdateWmcActive__FP3WMCP3JOY */
undefined4 OnWmcActive(WMC * arg0, int arg1); /* 0x1F1C90 OnWmcActive__FP3WMCi */
undefined4 DrawWmFan(float arg0, float arg1, float arg2, float arg3, int arg4, RGBA arg5, RGBA arg6, int arg7); /* 0x1F1E38 DrawWmFan__FffffiG4RGBAT5i */
undefined4 DrawWmc(WMC * arg0); /* 0x1F20A8 DrawWmc__FP3WMC */
undefined4 InitWr(WR * arg0); /* 0x1F2758 InitWr__FP2WR */
undefined4 ApplyWrGlob(WR * arg0, ALO * arg1, GLOB * arg2); /* 0x1F2798 ApplyWrGlob__FP2WRP3ALOP4GLOB */
undefined4 UpdateWrStateVectors(WR * arg0); /* 0x1F2840 UpdateWrStateVectors__FP2WR */
undefined4 WarpWrTransform(WR * arg0, float arg1, VECTOR * arg2, MATRIX3 * arg3, VECTOR * arg4, MATRIX3 * arg5, VECTOR * arg6); /* 0x1F2EF0 WarpWrTransform__FP2WRfP6VECTORP7MATRIX3T2T3T2 */
undefined4 GetWrBounds(WR * arg0, VECTOR * arg1); /* 0x1F3140 GetWrBounds__FP2WRP6VECTOR */
undefined4 UNoise(int arg0); /* 0x1F31F8 UNoise__Fi */
undefined4 UNoise_2(float arg0, float arg1, float arg2); /* 0x1F3250 UNoise__Ffff */
undefined4 UBias(float arg0, float arg1); /* 0x1F3328 UBias__Fff */
float GFromOnz(ONZ * arg0); /* 0x1F3358 GFromOnz__FP3ONZ */
undefined4 UpdateWrMatrixes(WR * arg0); /* 0x1F3408 UpdateWrMatrixes__FP2WR */
undefined4 AddWrCircleWarp(WR * arg0); /* 0x1F36E8 AddWrCircleWarp__FP2WR */
undefined4 AddWrBendWarp(WR * arg0); /* 0x1F3768 AddWrBendWarp__FP2WR */
void * PwreGetWrCur(WR * arg0, ENSK arg1, WREK arg2); /* 0x1F37D8 PwreGetWrCur__FP2WR4ENSK4WREK */
void * PwreGetWrCircle(WR * arg0, ENSK arg1); /* 0x1F3810 PwreGetWrCircle__FP2WR4ENSK */
void * PwreGetWrBend(WR * arg0, ENSK arg1); /* 0x1F3830 PwreGetWrBend__FP2WR4ENSK */
undefined4 SetWrWavelength(WR * arg0, float arg1); /* 0x1F3850 SetWrWavelength__FP2WRf */
undefined4 GetWrWavelength(WR * arg0, float * arg1); /* 0x1F38A0 GetWrWavelength__FP2WRPf */
undefined4 AddOnzOnze(ONZ * arg0, float arg1, float arg2, float arg3, float arg4); /* 0x1F38F0 AddOnzOnze__FP3ONZffff */
undefined4 AddWrBendNoise(WR * arg0, float arg1, float arg2, float arg3, float arg4); /* 0x1F3928 AddWrBendNoise__FP2WRffff */
undefined4 AddWrSwivelNoise(WR * arg0, float arg1, float arg2, float arg3, float arg4); /* 0x1F3990 AddWrSwivelNoise__FP2WRffff */
undefined4 InitXfm(XFM * arg0); /* 0x1F39F8 InitXfm__FP3XFM */
undefined4 LoadXfmFromBrx(XFM * arg0, CBinaryInputStream * arg1); /* 0x1F3A40 LoadXfmFromBrx__FP3XFMP18CBinaryInputStream */
undefined4 SetXfmParent(XFM * arg0, ALO * arg1); /* 0x1F3A90 SetXfmParent__FP3XFMP3ALO */
undefined4 ApplyXfmProxy(XFM * arg0, PROXY * arg1); /* 0x1F3AF0 ApplyXfmProxy__FP3XFMP5PROXY */
undefined4 ConvertXfmLocalToWorld(XFM * arg0, VECTOR * arg1, VECTOR * arg2); /* 0x1F3B48 ConvertXfmLocalToWorld__FP3XFMP6VECTORT1 */
undefined4 GetXfmPos(XFM * arg0, VECTOR * arg1); /* 0x1F3BD8 GetXfmPos__FP3XFMP6VECTOR */
undefined4 GetXfmMat(XFM * arg0, MATRIX3 * arg1); /* 0x1F3C08 GetXfmMat__FP3XFMP7MATRIX3 */
void * PwarpFromOid(OID arg0, OID arg1); /* 0x1F3C38 PwarpFromOid__F3OIDT0 */
undefined4 LoadWarpFromBrx(WARP * arg0, CBinaryInputStream * arg1); /* 0x1F3D80 LoadWarpFromBrx__FP4WARPP18CBinaryInputStream */
undefined4 CloneWarp(WARP * arg0, WARP * arg1); /* 0x1F3EE0 CloneWarp__FP4WARPT0 */
void * PostWarpLoad(WARP * arg0); /* 0x1F3F80 PostWarpLoad__FP4WARP */
undefined4 TriggerWarp(WARP * arg0); /* 0x1F4008 TriggerWarp__FP4WARP */
undefined4 SetWarpRsmg(WARP * arg0, int arg1, OID arg2, OID arg3, OID arg4); /* 0x1F42D0 SetWarpRsmg__FP4WARPi3OIDN22 */
int FUN_001F4308(WARP * arg0, float arg1); /* 0x1F4308 FUN_001F4308__FP4WARPf */
undefined4 TeleportSwPlayer(SW * arg0, OID arg1, OID arg2); /* 0x1F4318 TeleportSwPlayer__FP2SW3OIDT1 */
void * PexitDefault(void); /* 0x1F4378 PexitDefault__Fv */
undefined4 TriggerDefaultExit(int arg0, WIPEK arg1); /* 0x1F4408 TriggerDefaultExit__Fi5WIPEK */
undefined4 LoadExitFromBrx(EXIT * arg0, CBinaryInputStream * arg1); /* 0x1F4500 LoadExitFromBrx__FP4EXITP18CBinaryInputStream */
void * PostExitLoad(EXIT * arg0); /* 0x1F4660 PostExitLoad__FP4EXIT */
undefined4 SetExitExits(EXIT * arg0, EXITS arg1); /* 0x1F4760 SetExitExits__FP4EXIT5EXITS */
undefined4 TriggerExit(EXIT * arg0); /* 0x1F4808 TriggerExit__FP4EXIT */
undefined4 WipeExit(EXIT * arg0); /* 0x1F4A30 WipeExit__FP4EXIT */
undefined4 UpdateExit(float arg0, EXIT * arg1); /* 0x1F4AE0 UpdateExit__FfP4EXIT */
undefined4 InitCamera(CAMERA * arg0); /* 0x1F4E18 InitCamera__FP6CAMERA */
void * PostCameraLoad(CAMERA * arg0); /* 0x1F4E48 PostCameraLoad__FP6CAMERA */
undefined4 EnableCamera(CAMERA * arg0); /* 0x1F4ED0 EnableCamera__FP6CAMERA */
undefined4 DisableCamera(CAMERA * arg0); /* 0x1F4F20 DisableCamera__FP6CAMERA */
undefined4 InitTzp(TZP * arg0); /* 0x1F4F70 InitTzp__FP3TZP */
void * PostTzpLoad(TZP * arg0); /* 0x1F4FD8 PostTzpLoad__FP3TZP */
undefined4 UpdateTzp(TZP * arg0, float arg1); /* 0x1F5008 UpdateTzp__FP3TZPf */
undefined4 CloneTzp(TZP * arg0, TZP * arg1); /* 0x1F51A0 CloneTzp__FP3TZPT0 */
undefined4 RenderTzpAll(TZP * arg0, CM * arg1, RO * arg2); /* 0x1F51C8 RenderTzpAll__FP3TZPP2CMP2RO */
int FInflictTzpZap(TZP * arg0, XP * arg1, ZPR * arg2); /* 0x1F51E8 FInflictTzpZap__FP3TZPP2XPP3ZPR */
void * PzpdEnsureTzp(TZP * arg0, ENSK arg1); /* 0x1F5208 PzpdEnsureTzp__FP3TZP4ENSK */
int FUN_001F5210(TZP * arg0); /* 0x1F5210 FUN_001F5210__FP3TZP */
undefined4 InitVolzp(VOLZP * arg0); /* 0x1F5218 InitVolzp__FP5VOLZP */
undefined4 UpdateVolzp(VOLZP * arg0, float arg1); /* 0x1F5268 UpdateVolzp__FP5VOLZPf */
undefined4 InitZpd(ZPD * arg0, SO * arg1); /* 0x1F5590 InitZpd__FP3ZPDP2SO */
void * PostZpdLoad(ZPD * arg0); /* 0x1F55A8 PostZpdLoad__FP3ZPD */
undefined4 ApplyZpdThrow(ZPD * arg0, PO * arg1); /* 0x1F56D8 ApplyZpdThrow__FP3ZPDP2PO */
undefined4 InflictZpdZap(ZPD * arg0, XP * arg1, ZPR * arg2); /* 0x1F57E0 InflictZpdZap__FP3ZPDP2XPP3ZPR */
undefined4 AddZpdZapObject(ZPD * arg0, OID arg1); /* 0x1F5840 AddZpdZapObject__FP3ZPD3OID */
undefined4 AddZpdZapLo(ZPD * arg0, LO * arg1); /* 0x1F5868 AddZpdZapLo__FP3ZPDP2LO */
undefined4 RemoveZpdZapLo(ZPD * arg0, LO * arg1); /* 0x1F5930 RemoveZpdZapLo__FP3ZPDP2LO */
undefined4 __main(void); /* 0x1FAE18 __main__Fv */
