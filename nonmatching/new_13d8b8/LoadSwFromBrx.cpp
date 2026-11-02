// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct Bis;
struct RGBA {
    unsigned char r, g, b, a;
    RGBA(const RGBA &rgba) { *this = rgba; }
};
struct ZPR_13DA18 { char ab[0x630]; };
struct FLOC_13DA18 { int n0; int n4; int n8; char pad[0x110 - 0xC]; };
struct BIS_13DA18 { char ab[0x70]; };
struct FRAME_13DA18 { char ab[0x10]; };
struct LOGO_13DA18 { int n0; };
struct VT_13DA18 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct LO_13DA18 { char pad[0xC]; VT_13DA18 *vt; };
struct PLOARRAY_13DA18 { int n0; int n4; int c; LO_13DA18 **aplo; };
struct WL_13DA18 {
    int cplo;
    LO_13DA18 **aplo;
    int cset;
    int nC;
    int n10;
    int n14;
    int *an;
    char achName[0x40];
    int fNoClone;
    int n60;
    char pad[0x6C - 0x64];
};
struct SW_13DA18 {
    char pad0[0x39D0];
    void *p39D0;
    int c39D4;
    void *p39D8;
    int c39DC;
    void *p39E0;
    void *p39E4;
    int n39E8;
    char pad1[0x3A18 - 0x39EC];
    char savevars[0x3E00 - 0x3A18];
    RGBA rgbaClear;
    char pad2[0x3E38 - 0x3E04];
    int fBlackClear;
    char pad3[0x3F04 - 0x3E3C];
    int cwl;
    WL_13DA18 *awl;
    int n3F0C;
    int iwlLoading;
};
extern "C" {
void StartupCatalog__Fv();
int S16Read__18CBinaryInputStream(Bis *);
int S32Read__18CBinaryInputStream(Bis *);
void CBinaryInputStream_Read_thunk(Bis *, int, void *);
void Align__18CBinaryInputStreami(Bis *, int);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void StartLoadingLogo(LOGO_13DA18 *);
void StopLoadingLogo(LOGO_13DA18 *);
void func_001C9090(LOGO_13DA18 *, char *);
void LoadSndFromBrx(void *, Bis *);
void LoadSndBank(void *);
void LoadSaveVarsFromBis(void *, Bis *);
void LoadLevelTableFromBrx(SW_13DA18 *, Bis *);
void LoadSwStringsFromBrx(SW_13DA18 *, Bis *);
void LoadSwBspFromBrx(SW_13DA18 *, Bis *);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, Bis *);
void InitSwRootFrame(SW_13DA18 *);
void CreateSwSavePaths(SW_13DA18 *);
void UpdateSwFog(SW_13DA18 *);
void BuildClearGifs__FP2QWG4RGBAi(void *, RGBA, int);
void CStackFrame_Construct(FRAME_13DA18 *);
void CStackFrame_Destructor(FRAME_13DA18 *, int);
void InitZpr__FP3ZPR3ZPKP2LO(ZPR_13DA18 *, int, int);
void InitIdHashTables_1ed3a8();
void ShutdownIdHashTables_1ed448();
void func_001EA9F0(SW_13DA18 *, ZPR_13DA18 *);
void Clear__13CFileLocation(FLOC_13DA18 *);
char *PchzFidName_14b690(char *);
void CBinaryInputStream_ConstructFromBuffer(BIS_13DA18 *, int, void *, int);
void CBinaryFileStream_Destructor(BIS_13DA18 *, int);
void func_0020F5D0(int, Bis *);
void ReadSpliceBlock(SW_13DA18 *, int, Bis *);
void LoadShadersFromBrx(ZPR_13DA18 *, ZPR_13DA18 *, Bis *);
void LoadSwPzgraphFromBrx(SW_13DA18 *, Bis *);
void InitPloarray(PLOARRAY_13DA18 *);
void LoadSwObjectsFromBrx(void *, Bis *, PLOARRAY_13DA18 *);
void func_001EC7A0();
void CopyAb__FPvT0Ui(void *, void *, unsigned int);
LO_13DA18 *PloCloneLo(LO_13DA18 *, void *);
}
extern "C" char B_003DD040[];
extern "C" char B_003DD490[];
extern "C" char B_002DDF40[];
extern "C" char B_002DEDC0[];
extern "C" int B_003E1C34;
extern "C" char RO_002A4BD0[];
static inline void *PvAllocSw(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwImpl__Fi(&req);
}
static inline void *PvAllocSwClear(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwClearImpl__Fi(&req);
}
static inline void *PvAllocStack(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocStackImpl__Fi(&req);
}
extern "C" void LoadSwFromBrx(SW_13DA18 *psw, Bis *pbis)
{
    int iwl;
    StartupCatalog__Fv();
    int cwl = S16Read__18CBinaryInputStream(pbis);
    psw->cwl = cwl;
    psw->awl = (WL_13DA18 *)PvAllocSwClear(cwl * sizeof(WL_13DA18));
    LOGO_13DA18 logo;
    StartLoadingLogo(&logo);
    func_001C9090(&logo, RO_002A4BD0);
    for (iwl = 0; iwl < psw->cwl; iwl++) {
        WL_13DA18 *pwl = &psw->awl[iwl];
        CBinaryInputStream_Read_thunk(pbis, 0x40, pwl->achName);
        pwl->fNoClone = S32Read__18CBinaryInputStream(pbis);
        pwl->n60 = S32Read__18CBinaryInputStream(pbis);
        pwl->n10 = S32Read__18CBinaryInputStream(pbis);
        pwl->n14 = S32Read__18CBinaryInputStream(pbis);
        pwl->cset = S32Read__18CBinaryInputStream(pbis);
        pwl->an = (int *)PvAllocSw(pwl->cset * 4);
        memset(pwl->an, -1, pwl->cset * 4);
    }
    LoadSndFromBrx(B_003DD040, pbis);
    LoadSaveVarsFromBis(psw->savevars, pbis);
    LoadLevelTableFromBrx(psw, pbis);
    LoadSwStringsFromBrx(psw, pbis);
    LoadSwBspFromBrx(psw, pbis);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(B_003DD490, pbis);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(B_002DDF40, pbis);
    Align__18CBinaryInputStreami(pbis, 0x10);
    InitSwRootFrame(psw);
    CreateSwSavePaths(psw);
    UpdateSwFog(psw);
    if (psw->fBlackClear)
        *(int *)&psw->rgbaClear = 0x80000000;
    BuildClearGifs__FP2QWG4RGBAi(B_002DEDC0, psw->rgbaClear, 3);
    psw->p39E4 = psw->p39E0 = PvAllocStack(0x10000);
    psw->p39D0 = PvAllocStack(0x6000);
    psw->c39D4 = 0;
    psw->p39D8 = PvAllocStack(0x3000);
    psw->c39DC = 0;
    FRAME_13DA18 frame;
    CStackFrame_Construct(&frame);
    ZPR_13DA18 zpr1;
    InitZpr__FP3ZPR3ZPKP2LO(&zpr1, 0x1800, 0x4000);
    InitIdHashTables_1ed3a8();
    ZPR_13DA18 zpr2;
    InitZpr__FP3ZPR3ZPKP2LO(&zpr2, 0x1000, 0x1800);
    func_001EA9F0(psw, &zpr1);
    for (iwl = 0; iwl < psw->cwl; iwl++) {
        WL_13DA18 *pwl = &psw->awl[iwl];
        FLOC_13DA18 floc;
        floc.n8 = 2;
        Clear__13CFileLocation(&floc);
        func_001C9090(&logo, PchzFidName_14b690(pwl->achName));
        psw->iwlLoading = pwl->fNoClone == 0 ? iwl : -1;
        char ab[0x4040];
        BIS_13DA18 bis;
        CBinaryInputStream_ConstructFromBuffer(&bis, 0x403F, ab, 0);
        func_0020F5D0(1, pbis);
        B_003E1C34 = S32Read__18CBinaryInputStream(pbis);
        ReadSpliceBlock(psw, pwl->n10, pbis);
        LoadShadersFromBrx(&zpr1, &zpr2, pbis);
        LoadSwPzgraphFromBrx(psw, pbis);
        FRAME_13DA18 frameLoad;
        CStackFrame_Construct(&frameLoad);
        PLOARRAY_13DA18 ploarray;
        InitPloarray(&ploarray);
        LoadSwObjectsFromBrx(0, pbis, &ploarray);
        Align__18CBinaryInputStreami(pbis, 0x10);
        PchzFidName_14b690(pwl->achName);
        func_001EC7A0();
        psw->n39E8 = 0;
        pwl->cplo = ploarray.c;
        pwl->aplo = (LO_13DA18 **)PvAllocSwClear(ploarray.c * pwl->cset * 4);
        CopyAb__FPvT0Ui(pwl->aplo, ploarray.aplo, pwl->cplo * 4);
        LO_13DA18 **pplo = &pwl->aplo[pwl->cplo];
        for (int iset = 1; iset < pwl->cset; iset++)
            for (int iplo = 0; iplo < pwl->cplo; iplo++)
                *pplo++ = PloCloneLo(pwl->aplo[iplo], 0);
        if (pwl->fNoClone)
            pwl->nC++;
        else {
            for (int iplo = 0; iplo < pwl->cset * pwl->cplo; iplo++) {
                LO_13DA18 *plo = pwl->aplo[iplo];
                plo->vt->fn((char *)plo + plo->vt->delta);
            }
        }
        CStackFrame_Destructor(&frameLoad, 2);
        CBinaryFileStream_Destructor(&bis, 2);
    }
    ShutdownIdHashTables_1ed448();
    psw->iwlLoading = -2;
    LoadSndBank(B_003DD040);
    func_001C9090(&logo, 0);
    StopLoadingLogo(&logo);
    CStackFrame_Destructor(&frame, 2);
}
