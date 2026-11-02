// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct ALLOCREQ { int size; int align; };
struct RGBA { u8 r, g, b, a; };
struct VEC3 { float x, y, z; };
struct UV { float u, v; };

struct VIFS {
    int field0;
    u32 start;
    int field8;
    u32 end;
    char pad10[0x20];
};

struct VTBL_16A000 { char pad[0x50]; short offset; short pad52; int (*method)(void *); };
struct MAT_16A000 { char pad0[0xC]; VTBL_16A000 *vtable; char pad10[0x10]; int grf; char pad24[0x20]; int qw44; int qw48; };

struct SHD_16A000 { char pad0[4]; u8 type; u8 grf; char pad6[2]; RGBA rgba; char padC[8]; u16 field14; char pad16[0xE]; u16 field24; char pad26[2]; MAT_16A000 *pmat; };

struct UVL_16A000 { s16 u; s16 v; u16 link; } __attribute__((packed));
struct ST_16A000 { s16 s; s16 t; };

struct SUBMESH_16A000 {
    int cvtx;
    SHD_16A000 *pshd;
    int grf;
    MAT_16A000 *pmat;
    int cvtxUnique;
    int *aipos;
    float (*apos)[4];
    ST_16A000 *ast;
    UVL_16A000 *auvl;
    u16 *aiNormal;
    u16 *aiNormal2;
    u8 *aweightA;
    u8 *aweightB;
    RGBA *argbaLight;
    RGBA *argbaNormal;
    u8 *aweight;
};

struct PAIR_16A000 {
    int ipos;
    SUBMESH_16A000 *psmFirst;
    int ivtxFirst;
    SUBMESH_16A000 *psm;
    int ivtx;
};

struct DESC_16A000 {
    u16 base;
    u16 mid;
    u16 next;
    u16 extra6;
    u16 aiLayer[3];
    u16 extraE;
    u16 unique;
    u16 link;
    u16 mat;
    u16 extra16;
    u16 shd18;
    u16 fog;
    u16 weight;
    u16 shd1E;
};

struct REC_16A000 {
    u16 field0;
    u16 field2;
    char pad4[2];
    u16 field6;
    u16 grf;
    u16 cqw;
    u16 fieldC;
    u16 fieldE;
    u16 aweight[4];
    DESC_16A000 adesc[2];
};

struct FOG_16A000 {
    float field0;
    float scale1;
    float scale2;
    float fieldC;
    int field10[2];
    int ifog;
    int fFlag;
    float vec[4];
};

struct SL_16A000 { int field0; int field4; int field8; };
struct SLE_16A000 { int cvtx; u32 apos; u32 aptr[4]; struct SLE_16A000 *next; };

struct OBJ_16A000 {
    int field0;
    void *pglobi;
    int field8;
    int fieldC;
    int count;
    int field14;
    int field18;
    u16 grf;
    u16 pad1E;
    int cqw;
    int pad24[3];
    int ifog;
    float afog[4];
    char pad44[0xC];
    float mat[16];
    SLE_16A000 *sl;
    int sl94[2];
    struct OBJ_16A000 *next;
    char padA0[0x10];
};

struct GLOBSET_16A000 {
    void *palo;
    char pad4[0x24];
    void **apSub;
    int coid;
    int *aoid;
    char pad34[0x18];
    int field4C;
    unsigned long grf;
    OBJ_16A000 *pobjFirst;
    struct SAVED_16A000 *psavedFirst;
};

struct GLOB_16A000 {
    int type : 8;
    int count : 8;
    int grf : 8;
    float sMax;
    void *pdma;
    int iweight;
    u32 qwDma;
};

struct GLOBI_16A000 {
    u16 field0;
    char pad2[2];
    char *pbase;
    char pad8[4];
    u32 grf;
    u32 qwDma;
    char pad14[4];
    char *aweights;
    OBJ_16A000 *pobj;
    MAT_16A000 *pmat;
};

struct CMPARAM_16A000 { float sFog; int cqw; int mode; };

struct WEIGHTENTRY_16A000 { u16 a; u16 b; u8 c; };
struct NORMALSET_16A000 { int field0; WEIGHTENTRY_16A000 *aentry; };
struct NORMALS_16A000 { int field0; NORMALSET_16A000 *aset; int *aiset; };

struct SAVEDSM_16A000 { int cvtx; int grf; u32 ast; u32 apos; u32 auvl; u32 alight; u32 anormal; int field1C; };
struct SAVED_16A000 { GLOB_16A000 *pglob; int csm; SAVEDSM_16A000 *asm_; struct SAVED_16A000 *next; };

struct VIFSPAIR_16A000 {
    VIFS vifs;
    VIFS vifsRefs;
};

union SCRATCH_16A000 {
    ALLOCREQ req;
    float avec[4];
    int aread[3];
    RGBA rgba;
};

struct LOCALS_16A000 {
    FOG_16A000 fog;
    union {
        OBJ_16A000 obj;
        struct {
            VIFS vifsBatch;
            union {
                ALLOCREQ req;
                RGBA rgba;
            } uF0;
        } s;
    } uC0;
    int *apbatch[0x400];
};

extern "C" {
int U8Read__18CBinaryInputStream(void *);
int S8Read__18CBinaryInputStream(void *);
int S16Read__18CBinaryInputStream(void *);
int S32Read__18CBinaryInputStream(void *);
float F32Read__18CBinaryInputStream(void *);
void ReadVector__18CBinaryInputStreamP6VECTOR(void *, void *);
void CBinaryInputStream_ReadMatrix4(void *, void *);
int CBinaryInputStream_Read_thunk(void *, int, void *);
void func_00117F90(void *, void *);
void func_00117FB0(void *, void *);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void __4VIFS(VIFS *);
void AllocStack__4DMASi(VIFS *, int);
void AddDmaCnt__4DMAS(VIFS *);
void EndDmaCnt__4DMAS(VIFS *);
void AddDmaRet__4DMAS(VIFS *);
void AddDmaRefs__4DMASiP2QW(VIFS *, int, void *);
void DMAS_DetachCopyPermanent(VIFS *, u32 *, u32 *, u32 *);
int Align__4VIFSi(VIFS *, int);
void AddVifUnpack__4VIFS3UPKiPvi(VIFS *, int, int, void *, int);
void UnpackHelper__4VIFS3UPKiiPiPPUi(VIFS *, int, int, int, int *, void *);
void AddVifStcycl__4VIFSii(VIFS *, int, int);
void AddVifStmask__4VIFSUi(VIFS *, u32);
void AddVifStrow__4VIFSP2QW(VIFS *, void *);
void AddVifMscal__4VIFSPv(VIFS *, void *);
int FIsBasicDerivedFrom(void *, int);
void BuildCmFgfn__FP2CMfP4FGFN(void *, float, void *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
void *memset(void *, int, unsigned int);
void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
int func_00169988(const void *, const void *);
NORMALS_16A000 *func_0016C8E0(GLOBSET_16A000 *, void *);
void InitSl(void *, int);
void AppendSlEntry(void *, void *);
SHD_16A000 *PshdFromIndex(int);
SHD_16A000 *PshdFindShader__F3OID(int);
int func_001EC688(SHD_16A000 *, int, int, VIFS *);
int func_001EC6D0(SHD_16A000 *, int, int, VIFS *);
int func_001ED960(MAT_16A000 *, int, VIFS *);
void FilterColorRgba8_1ed278(RGBA *);
void CopyAb__FPvT0Ui(void *, void *, unsigned int);
void CopyGlobDmaChain(GLOB_16A000 *, GLOBI_16A000 *, int, u32, u32, u32, u32);
void func_001EC740(int, int, u32, u32, u32);
void func_001699E8(GLOBSET_16A000 *, GLOB_16A000 *, GLOBI_16A000 *, void *, int, int, int *, SUBMESH_16A000 **, void *);

extern int B_003DA790;
extern int B_003E12D0;
extern char B_002DDF40[];
extern int B_002DEB54;
extern char B_002DEB60[];
extern u32 D_002BE540[];
extern int D_002BE558[];
extern int D_002BE580;
extern int B_003E11EC;
extern char VU1_START_0[];
extern char D_00000010[];
extern char D_00002E20[];
extern char D_00002E68[];
extern char D_00002EB0[];
extern char D_00002EE8[];
extern char D_00002EF8[];
extern char D_00002F80[];
extern char D_00002FC8[];
extern char D_00003358[];
extern char D_00003628[];
extern char D_000037A8[];
}

static inline void RelocateQw(u32 *pqw, u32 cb, u32 from, u32 to)
{
    if (pqw != 0 && *pqw >= from && *pqw < from + cb)
        *pqw += to - from;
}

static inline u32 QwRelocated(u32 qw, u32 cb, u32 from, u32 to)
{
    if (qw != 0 && qw >= from && qw < from + cb)
        return qw + (to - from);
    return qw;
}

struct CStackFrame_16A000 {
    int field0;
    CStackFrame_16A000() { CStackFrame_Construct(this); }
    ~CStackFrame_16A000() { CStackFrame_Destructor(this, 2); }
};

extern "C" void LoadGlobFromBrx(GLOBSET_16A000 *pglobset, GLOB_16A000 *pglob, GLOBI_16A000 *pglobi, CMPARAM_16A000 *pcmparam, void *pextra, int cextra, void *pbis)
{
    float *psFog;
    REC_16A000 *prec;
    u16 *pmscal;
    int *pbatch;
    VEC3 *pnormalOut;
    RGBA *prgbaOut;
    VEC3 *pposOut;
    u32 cqwDetach;
    u32 qwFrom;
    u32 qwTo;
    u32 qwRefStart;
    int cqw;
    NORMALS_16A000 *pnormals;
    int csubglob;
    int cbatch;
    int *acsm;
    SUBMESH_16A000 **aasm;

    pglob->grf = U8Read__18CBinaryInputStream(pbis);
    int isub = S16Read__18CBinaryInputStream(pbis);
    if (isub >= 0)
        pglobi->pmat = (MAT_16A000 *)pglobset->apSub[isub];
    if (pglob->grf & 1)
        pglobi->grf |= 0x100;
    if (pglob->grf & 2)
        pglobi->grf |= 0x200;

    CStackFrame_16A000 frame;
    VIFSPAIR_16A000 l;
    SCRATCH_16A000 u80;
    LOCALS_16A000 lb;
    __4VIFS(&l.vifs);
    __4VIFS(&l.vifsRefs);
    AllocStack__4DMASi(&l.vifs, 0x2000);
    pglobi->grf = (pglobi->grf & 0xFFC01FFF) | ((B_003DA790 & 0x1FF) << 13);
    qwRefStart = l.vifs.end;

    if (pglob->grf & 1) {
        AddDmaCnt__4DMAS(&l.vifs);
        pglobset->grf |= 0x8000L << 17;
    } else {
        AllocStack__4DMASi(&l.vifsRefs, 0x800);
        if (FIsBasicDerivedFrom(pglobset->palo, 0x31) && !(pglob->grf & 4) && (u8)(pglob->type - 7) >= 2
            && pglob->sMax == 3.402823466e+38f && B_003E12D0 == 0) {
            pglobi->grf |= 0x1000;
            u80.avec[0] = 1.0f;
            u80.avec[1] = 1.0f;
            u80.avec[2] = 0;
            u80.avec[3] = 0;
            AddDmaCnt__4DMAS(&l.vifsRefs);
            AddVifUnpack__4VIFS3UPKiPvi(&l.vifsRefs, 0xC, 4, pglobi->pbase + 0x40, 0);
            AddVifUnpack__4VIFS3UPKiPvi(&l.vifsRefs, 0xC, 1, u80.avec, 8);
            EndDmaCnt__4DMAS(&l.vifsRefs);
        }
    }

    UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0xC, 1, 9, 0, &psFog);
    BuildCmFgfn__FP2CMfP4FGFN(B_002DDF40, pcmparam->sFog, psFog);

    pglob->count = U8Read__18CBinaryInputStream(pbis);
    ALLOCREQ *preq = &u80.req;
    u80.req.size = pglob->count * 0x50;
    preq->align = 0x10;
    pglobi->aweights = (char *)PvAllocSwClearImpl__Fi(preq);
    for (int iweight = 0; iweight < pglob->count; iweight++) {
        int *pweight = (int *)(pglobi->aweights + iweight * 0x50);
        pweight[0] = S32Read__18CBinaryInputStream(pbis);
        pweight[2] = S16Read__18CBinaryInputStream(pbis);
    }

    cqw = (pglob->grf & 1) ? 0x21 : 0x15;
    if (pglob->count != 0) {
        pglob->iweight = cqw;
        cqw += pglob->count * 4;
    }

    lb.fog.ifog = S8Read__18CBinaryInputStream(pbis);
    if (lb.fog.ifog != -1) {
        func_00117F90(pbis, &lb.fog.field0);
        func_00117FB0(pbis, lb.fog.field10);
        ReadVector__18CBinaryInputStreamP6VECTOR(pbis, lb.fog.vec);
        lb.fog.scale1 *= 0.007874016f;
        lb.fog.scale2 *= 6.2000123e-05f;
        lb.fog.fFlag = pglob->grf & 1;
    }

    pnormals = func_0016C8E0(pglobset, pbis);

    if (pglob->grf & 4) {
        memset(&lb.uC0.obj, 0, 0xB0);
        lb.uC0.obj.field8 = S32Read__18CBinaryInputStream(pbis);
        lb.uC0.obj.ifog = S8Read__18CBinaryInputStream(pbis);
        if (lb.uC0.obj.ifog != -1) {
            lb.uC0.obj.afog[0] = F32Read__18CBinaryInputStream(pbis);
            lb.uC0.obj.afog[1] = F32Read__18CBinaryInputStream(pbis);
            lb.uC0.obj.afog[2] = F32Read__18CBinaryInputStream(pbis);
            lb.uC0.obj.afog[3] = F32Read__18CBinaryInputStream(pbis);
            CBinaryInputStream_ReadMatrix4(pbis, lb.uC0.obj.mat);
        }
        lb.uC0.obj.count = U8Read__18CBinaryInputStream(pbis);
        lb.uC0.obj.field14 = U8Read__18CBinaryInputStream(pbis);
        lb.uC0.obj.field18 = U8Read__18CBinaryInputStream(pbis);
        u80.req.size = 0xB0;
        preq->align = 0x10;
        OBJ_16A000 *pobj = (OBJ_16A000 *)PvAllocSwCopyImpl__FiPv(preq, &lb.uC0.obj);
        pobj->field0 = *(int *)pglobset;
        pobj->grf = pobj->count;
        pobj->pglobi = pglobi;
        if (pobj->field14 != 0)
            pobj->grf |= 0x100;
        if (pobj->field18 != 0)
            pobj->grf |= 0x200;
        InitSl(&pobj->sl, 0x18);
        pobj->cqw = cqw;
        if (pobj->field14 != 0)
            cqw += pobj->count * 4;
        if (pobj->field18 != 0)
            cqw += pobj->count * 4;
        pglobi->pobj = pobj;
        pobj->next = pglobset->pobjFirst;
        pglobset->pobjFirst = pobj;
    }

    cbatch = 0;
    csubglob = S16Read__18CBinaryInputStream(pbis);
    __4VIFS(&lb.uC0.s.vifsBatch);
    if (!(pglob->grf & 1)) {
        AllocStack__4DMASi(&lb.uC0.s.vifsBatch, 0x2000);
        AddDmaCnt__4DMAS(&lb.uC0.s.vifsBatch);
    }
    u80.req.size = csubglob * 4;
    preq->align = 0x10;
    acsm = (int *)PvAllocStackClearImpl__Fi(preq);
    u80.req.size = csubglob * 4;
    preq->align = 0x10;
    aasm = (SUBMESH_16A000 **)PvAllocStackClearImpl__Fi(preq);

    for (int isubglob = 0; isubglob < csubglob; isubglob++) {
        int csm;
        SUBMESH_16A000 *asm_;
        int cvtx;
        VEC3 *apos;
        UV *auv;
        VEC3 *anormal;
        RGBA *argba;
        int cweight;
        u8 *aweight;
        u32 *pbits;
        u32 bitMask;
        int fAll;
        int fNoMat;
        PAIR_16A000 *apair;
        int ism;
        u8 *pipos;
        csm = U8Read__18CBinaryInputStream(pbis);
        u80.req.size = csm << 6;
        u80.req.align = 0x10;
        asm_ = (SUBMESH_16A000 *)PvAllocStackClearImpl__Fi((ALLOCREQ *)&u80);
        acsm[isubglob] = csm;
        aasm[isubglob] = asm_;
        UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0xD, 0xB, 0xA, 0, &prec);
        memset(prec, 0, 0x58);
        switch (isubglob) {
        case 0:
            prec->grf = 1;
            switch (pcmparam->mode) {
            case 0:
                prec->grf |= 0x100;
                break;
            case 1:
                prec->grf |= 0x200;
                break;
            case 2:
                prec->grf |= 0x400;
                break;
            }
            break;
        case 1:
            prec->grf = 4;
            break;
        }
        prec->field2 = pglobi->field0;
        if (pglob->grf & 1)
            prec->grf |= 2;
        if (pglob->grf & 0x10)
            prec->grf |= 0x80;
        if (pglobi->pobj != 0) {
            prec->fieldC = pglobi->pobj->grf;
            prec->fieldE = pglobi->pobj->cqw;
        }
        if (pglob->count != 0)
            prec->fieldE = pglob->iweight;

        cvtx = 0;
        if (csm > 0) {
            SUBMESH_16A000 *psm = asm_;
            for (int ism = csm; ism != 0; ism--) {
                CBinaryInputStream_Read_thunk(pbis, 0xC, u80.aread);
                psm->cvtx = u80.aread[0];
                psm->pshd = PshdFromIndex(u80.aread[1]);
                psm->grf = u80.aread[2];
                MAT_16A000 *pmat = pglobi->pmat;
                if (pmat != 0 && pmat->vtable->method((char *)pmat + pmat->vtable->offset))
                    psm->pmat = pglobi->pmat;
                if (psm->pmat == 0) {
                    pmat = psm->pshd->pmat;
                    if (pmat != 0 && pmat->vtable->method((char *)pmat + pmat->vtable->offset))
                        psm->pmat = psm->pshd->pmat;
                }
                if (psm->pmat != 0) {
                    if (psm->pmat->grf & 1)
                        psm->grf |= 0x10;
                    if (psm->pmat->grf & 2)
                        psm->grf |= 8;
                }
                if (psm->grf & 0x20) {
                    ALLOCREQ *preqSm = &lb.uC0.s.uF0.req;
                    lb.uC0.s.uF0.req.size = psm->cvtx << 2;
                    preqSm->align = 0x10;
                    psm->aipos = (int *)PvAllocStackClearImpl__Fi(preqSm);
                }
                cvtx += psm->cvtx;
                if (B_002DEB54 != 0)
                    psm->grf &= ~2;
                switch (psm->pshd->type) {
                case 3:
                    psm->grf |= 6;
                    break;
                case 7:
                    if (!(psm->pshd->grf & 0x20))
                        psm->grf |= 4;
                    break;
                }
                psm++;
            }
        }

        int cqwFog = cvtx + 0x1F;
        CStackFrame_16A000 frame2;
        int cpos = U8Read__18CBinaryInputStream(pbis);
        u80.req.size = cpos * 0xC;
        u80.req.align = 0x10;
        apos = (VEC3 *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
        CBinaryInputStream_Read_thunk(pbis, cpos * 0xC, apos);
        u80.req.size = cpos * 8;
        u80.req.align = 0x10;
        auv = (UV *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
        CBinaryInputStream_Read_thunk(pbis, cpos * 8, auv);
        u80.req.size = cpos * 0xC;
        u80.req.align = 0x10;
        anormal = (VEC3 *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
        CBinaryInputStream_Read_thunk(pbis, cpos * 0xC, anormal);
        u80.req.size = cpos * 4;
        u80.req.align = 0x10;
        argba = (RGBA *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
        CBinaryInputStream_Read_thunk(pbis, cpos * 4, argba);
        for (RGBA *prgba = argba; prgba < argba + cpos; prgba++)
            FilterColorRgba8_1ed278(prgba);

        cweight = S8Read__18CBinaryInputStream(pbis);
        if (pglob->type < 9) {
            if (pglob->type >= 3)
                cweight = 1;
        }

        if (pglob->count != 0) {
            for (int iweight = 0; iweight < 4; iweight++)
                prec->aweight[iweight] = (u16)pglob->iweight + U8Read__18CBinaryInputStream(pbis) * 4;
            int cweightAlloc = 4;
            if (pglob->count <= 3)
                cweightAlloc = pglob->count;
            u80.req.size = cweightAlloc * cpos;
            u80.req.align = 0x10;
            aweight = (u8 *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
            int cweightRead = 4;
            if (pglob->count <= 3)
                cweightRead = pglob->count;
            CBinaryInputStream_Read_thunk(pbis, cweightRead * cpos, aweight);
        } else {
            aweight = 0;
        }

        u80.req.size = cvtx;
        u80.req.align = 0x10;
        u8 *aipos = (u8 *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
        bitMask = 1;
        CBinaryInputStream_Read_thunk(pbis, cvtx, aipos);
        int cbBits = (cqwFog / 32) * 4;
        fAll = 0;
        u80.req.size = cbBits;
        u80.req.align = 0x10;
        u32 *abits = (u32 *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
        CBinaryInputStream_Read_thunk(pbis, cbBits, abits);
        pbits = abits;
        if ((pglob->grf & 5) || pglob->count != 0 || lb.fog.ifog != -1)
            fAll = 1;
        fNoMat = 0;
        if (!fAll && asm_[0].pmat == 0)
        {
            fNoMat = 1;
            if (asm_[1].pmat != 0)
                fNoMat = 0;
        }

        int qw = cqw;
        prec->cqw = qw;
        if (pglob->count == 0 && !(pglob->grf & 1) && lb.fog.ifog == -1) {
            apair = 0;
        } else if (pglob->grf & 8) {
            u80.req.size = cvtx * 0x14;
            u80.req.align = 0x10;
            u8 *pipos = aipos;
            apair = (PAIR_16A000 *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
            PAIR_16A000 *ppair = apair;
            for (int ism = 0; ism < csm; ism++) {
                SUBMESH_16A000 *psm = &asm_[ism];
                psm->cvtxUnique = 0;
                for (int ivtx = 0; ivtx < psm->cvtx; ivtx++) {
                    ppair->ivtxFirst = ivtx;
                    ppair->ivtx = ivtx;
                    ppair->ipos = *pipos++;
                    ppair->psm = psm;
                    ppair->psmFirst = psm;
                    ppair++;
                }
            }
        } else {
            int cbFirst = cpos * 4;
            u80.req.size = cbFirst;
            u80.req.align = 0x10;
            PAIR_16A000 **appairFirst = (PAIR_16A000 **)PvAllocStackClearImpl__Fi((ALLOCREQ *)&u80);
            u80.req.size = cvtx * 0x14;
            u80.req.align = 0x10;
            apair = (PAIR_16A000 *)PvAllocStackImpl__Fi((ALLOCREQ *)&u80);
            u8 *pipos = aipos + cvtx;
            PAIR_16A000 *ppair = apair;
            for (int ism = 0; ism < csm; ism++)
                asm_[ism].cvtxUnique = asm_[ism].cvtx;
            SUBMESH_16A000 *psmUnique = &asm_[csm - 1];
            for (int ism = csm - 1; ism >= 0; ism--) {
                SUBMESH_16A000 *psm = &asm_[ism];
                for (int ivtx = psm->cvtx - 1; ivtx >= 0; ivtx--) {
                    int ipos = *--pipos;
                    PAIR_16A000 **pppair = &appairFirst[ipos];
                    if (*pppair != 0) {
                        *ppair = **pppair;
                    } else {
                        ppair->psmFirst = psmUnique;
                        ppair->ipos = ipos;
                        ppair->ivtxFirst = --psmUnique->cvtxUnique;
                        *pppair = ppair;
                        if (psmUnique->cvtxUnique == 0)
                            psmUnique--;
                    }
                    ppair->ivtx = ivtx;
                    ppair->psm = psm;
                    ppair++;
                }
                if (!fAll) {
                    psmUnique = &asm_[ism - 1];
                    memset(appairFirst, 0, cbFirst);
                }
            }
            qsort(apair, cvtx, 0x14, func_00169988);
        }

        if (lb.fog.ifog != -1) {
            prec->adesc[0].extra16 = prec->adesc[1].extra16 = cqw;
            qw = cqw + 3;
            AddVifUnpack__4VIFS3UPKiPvi(&l.vifs, 0xC, 3, &lb.fog, prec->adesc[0].extra16);
        }

        pipos = aipos;
        for (ism = 0; ism < csm; ism++) {
            SUBMESH_16A000 *psm = &asm_[ism];
            DESC_16A000 *pdesc = &prec->adesc[ism];
            pdesc->extra6 = psm->cvtx | 0x8000;
            pdesc->shd18 = psm->pshd->field14;
            pdesc->shd1E = psm->pshd->field24;
            for (int ilayer = 0; ilayer < 3; ilayer++) {
                for (int ismPrev = 0; ismPrev < ism; ismPrev++) {
                    DESC_16A000 *pdescPrev = &prec->adesc[ismPrev];
                    SUBMESH_16A000 *psmPrev = &asm_[ismPrev];
                    if (psm->pshd == psmPrev->pshd && (psm->grf >> ilayer) & 1 && (psmPrev->grf >> ilayer) & 1) {
                        pdesc->aiLayer[ilayer] = pdescPrev->aiLayer[ilayer];
                        break;
                    }
                }
            }
            for (int ilayer = 0; ilayer < 3; ilayer++) {
                if (pdesc->aiLayer[ilayer] == 0 && (psm->grf >> ilayer) & 1) {
                    if (pglob->grf & 2) {
                        for (int ioid = pglobset->coid - 1; ioid >= 0; ioid--)
                            qw += func_001EC6D0(PshdFindShader__F3OID(pglobset->aoid[ioid]), ilayer, qw, &l.vifs);
                    }
                    pdesc->aiLayer[ilayer] = qw;
                    qw += func_001EC688(psm->pshd, ilayer, qw, &l.vifs);
                }
            }
            if (psm->pmat != 0) {
                for (int ismPrev = 0; ismPrev < ism; ismPrev++) {
                    DESC_16A000 *pdescPrev = &prec->adesc[ismPrev];
                    SUBMESH_16A000 *psmPrev = &asm_[ismPrev];
                    if (psm->pmat == psmPrev->pmat) {
                        pdesc->mat = pdescPrev->mat;
                        break;
                    }
                }
                if (pdesc->mat == 0) {
                    pdesc->mat = qw;
                    qw += func_001ED960(psm->pmat, qw, &l.vifs);
                }
            }
            qw++;
            pdesc->base = qw;
            int qwBase = qw;
            qw += psm->cvtx * 4;
            pdesc->next = qw;
            pdesc->mid = qwBase + ((psm->cvtx / 2 & ~3) + 2) * 4;
            if (apair != 0)
                pdesc->unique = qwBase + psm->cvtxUnique * 4;
            if (pglob->count != 0) {
                pdesc->weight = qw;
                qw += psm->cvtx - psm->cvtxUnique;
                if (pglob->grf & 1)
                    prec->grf |= 0x20;
                else
                    prec->grf |= 0x10;
            }
            if (psm->pshd->type == 3 && prec->field6 == 0) {
                prec->adesc[0].extraE = prec->adesc[1].extraE = qw;
                qw += func_001EC688(psm->pshd, 3, qw, &l.vifs);
                UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 1, 1, qw, 0, &pmscal);
                *pmscal = qw + 2;
                prec->field6 = qw;
                qw += 0x1A;
            }
            if (lb.fog.ifog != -1) {
                if (pglob->grf & 1) {
                    pdesc->fog = pdesc->unique + 1;
                } else {
                    pdesc->fog = qw;
                    int cvtxFog = psm->cvtx - psm->cvtxUnique;
                    qw += cvtxFog;
                    UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0x1E, cvtxFog, pdesc->fog, 0, &psm->argbaNormal);
                }
            }
            if (pglobi->pobj != 0) {
                pdesc->weight = qw;
                qw += pglobi->pobj->count * psm->cvtx;
                prec->grf |= 0x40;
            }
            AddVifStcycl__4VIFSii(&l.vifs, 1, 4);
            if ((pglob->grf & 1) || pglob->count != 0 || lb.fog.ifog != -1)
                UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0x19, psm->cvtx, pdesc->base, 0, &psm->auvl);
            else
                UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0x15, psm->cvtx, pdesc->base, 0, &psm->ast);
            if (pglob->grf & 1) {
                if (psm->cvtxUnique < psm->cvtx) {
                    UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0x1E, psm->cvtx - psm->cvtxUnique, pdesc->unique + 1, 0, &psm->argbaNormal);
                    UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0xE, psm->cvtx - psm->cvtxUnique, pdesc->unique + 2, 0, &psm->argbaLight);
                }
            } else {
                Align__4VIFSi(&l.vifs, 0);
                AddDmaRefs__4DMASiP2QW(&l.vifsRefs, (int)(l.vifs.end - qwRefStart) >> 4, (void *)qwRefStart);
                qwRefStart = l.vifs.end;
                AddDmaCnt__4DMAS(&l.vifsRefs);
                UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifsRefs, 0xF, psm->cvtx, pdesc->base + 1, 0, &psm->aiNormal);
                if ((psm->grf & 2) && psm->pshd->type != 3)
                    UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifsRefs, 0xF, psm->cvtx, pdesc->base + 2, 0, &psm->aiNormal2);
                if (cweight != 0 || psm->aiNormal2 != 0) {
                    AddVifStmask__4VIFSUi(&l.vifsRefs, 0x3F3F3F3F);
                    if (cweight != 0)
                        UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifsRefs, 2, psm->cvtx, pdesc->base + 1, 0, &psm->aweightA);
                    if (psm->aiNormal2 != 0)
                        UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifsRefs, 2, psm->cvtx, pdesc->base + 2, 0, &psm->aweightB);
                    AddVifStmask__4VIFSUi(&l.vifsRefs, 0);
                }
                EndDmaCnt__4DMAS(&l.vifsRefs);
            }
            UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0xC, psm->cvtx, pdesc->base + 3, 0, &psm->apos);
            AddVifStcycl__4VIFSii(&l.vifs, 1, 1);
            if (pglob->count != 0 && psm->cvtxUnique < psm->cvtx) {
                if (pglob->count < 4) {
                    AddVifStrow__4VIFSP2QW(&l.vifs, B_002DEB60);
                    int cweightMask = 4;
                    if (pglob->count <= 3)
                        cweightMask = pglob->count;
                    AddVifStmask__4VIFSUi(&l.vifs, D_002BE540[cweightMask]);
                }
                int cweightUnpack = 4;
                if (pglob->count <= 3)
                    cweightUnpack = pglob->count;
                UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, D_002BE558[cweightUnpack], psm->cvtx - psm->cvtxUnique, pdesc->weight, 0, &psm->aweight);
                if (pglob->count < 4)
                    AddVifStmask__4VIFSUi(&l.vifs, 0);
            }
            if (pglobi->pobj != 0) {
                int qwObj = pdesc->weight;
                u80.req.size = 0x1C;
                u80.req.align = 0x10;
                SLE_16A000 *psle = (SLE_16A000 *)PvAllocSwClearImpl__Fi((ALLOCREQ *)&u80);
                AppendSlEntry(&pglobi->pobj->sl, psle);
                psle->cvtx = psm->cvtx;
                psle->apos = (u32)psm->apos;
                for (int iobj = 0; iobj < pglobi->pobj->count; iobj++) {
                    UnpackHelper__4VIFS3UPKiiPiPPUi(&l.vifs, 0xC, psm->cvtx, qwObj, 0, &psle->aptr[iobj]);
                    memset((void *)psle->aptr[iobj], 0, psm->cvtx << 4);
                    qwObj += psm->cvtx;
                }
            }

            if (!(pglob->grf & 1)) {
                int type = psm->pshd->type;
                if (type != 1 && type != 7) {
                    u16 *aiNormal = psm->aiNormal;
                    u8 *pweight = psm->aweightA;
                    for (int ivtx = 0; ivtx < psm->cvtx; ivtx++) {
                        u16 *pclr = aiNormal++;
                        int ipos = pipos[ivtx];
                        u80.rgba = argba[ipos];
                        lb.uC0.s.uF0.rgba = psm->pshd->rgba;
                        u8 alpha = (u80.rgba.a * lb.uC0.s.uF0.rgba.a + 0xFF) / 0x1FE;
                        u8 red = (u80.rgba.r * lb.uC0.s.uF0.rgba.r + 0xFF) / 0x100;
                        u8 green = (u80.rgba.g * lb.uC0.s.uF0.rgba.g + 0xFF) / 0x100;
                        u8 blue = (u80.rgba.b * lb.uC0.s.uF0.rgba.b + 0xFF) / 0x100;
                        u16 clr = (red >> 3) | ((green >> 3) << 5) | ((blue >> 3) << 10) | ((alpha >> 7) << 15);
                        *pclr = clr;
                        if (pweight != 0)
                            *pweight++ = alpha;
                    }
                } else {
                    if (D_002BE580 != 0 || !(psm->grf & 0x20)) {
                        for (int ivtxBatch = 0; ivtxBatch < psm->cvtx; ) {
                            int cvtxBatch = 0x27;
                            if (psm->cvtx - ivtxBatch <= 0x27)
                                cvtxBatch = psm->cvtx - ivtxBatch;
                            UnpackHelper__4VIFS3UPKiiPiPPUi(&lb.uC0.s.vifsBatch, 0xC, 3, 0x307, 0, &pbatch);
                            pbatch[0] = 0x30A;
                            pbatch[1] = pbatch[0] + cvtxBatch * 3;
                            pbatch[2] = pbatch[1];
                            pbatch[3] = pbatch[2] + cvtxBatch;
                            pbatch[4] = pbatch[3] + cvtxBatch;
                            pbatch[5] = (int)(psm->aiNormal + ivtxBatch);
                            pbatch[6] = (int)(psm->aiNormal2 + ivtxBatch);
                            if (cweight != 0)
                                pbatch[8] = (int)(psm->aweightA + ivtxBatch);
                            else
                                pbatch[8] = 0;
                            pbatch[9] = (int)(psm->aweightB + ivtxBatch);
                            ((float *)pbatch)[7] = psm->pshd->field14 * 0.000244140625f;
                            lb.apbatch[cbatch++] = pbatch;
                            AddVifStcycl__4VIFSii(&lb.uC0.s.vifsBatch, 1, 3);
                            UnpackHelper__4VIFS3UPKiiPiPPUi(&lb.uC0.s.vifsBatch, 8, cvtxBatch, 0x30A, 0, &pnormalOut);
                            UnpackHelper__4VIFS3UPKiiPiPPUi(&lb.uC0.s.vifsBatch, 0xE, cvtxBatch, 0x30B, 0, &prgbaOut);
                            UnpackHelper__4VIFS3UPKiiPiPPUi(&lb.uC0.s.vifsBatch, 8, cvtxBatch, 0x30C, 0, &pposOut);
                            AddVifStcycl__4VIFSii(&lb.uC0.s.vifsBatch, 1, 1);
                            u8 *pipos2 = pipos + ivtxBatch;
                            for (int ivtx = cvtxBatch; ivtx != 0; ivtx--) {
                                int ipos = *pipos2++;
                                *pnormalOut++ = anormal[ipos];
                                *pposOut++ = apos[ipos];
                                u80.rgba = argba[ipos];
                                lb.uC0.s.uF0.rgba = psm->pshd->rgba;
                                u80.rgba.r = (u80.rgba.r * lb.uC0.s.uF0.rgba.r + 0xFF) / 0x100;
                                u80.rgba.g = (u80.rgba.g * lb.uC0.s.uF0.rgba.g + 0xFF) / 0x100;
                                u80.rgba.b = (u80.rgba.b * lb.uC0.s.uF0.rgba.b + 0xFF) / 0x100;
                                u80.rgba.a = (u80.rgba.a * lb.uC0.s.uF0.rgba.a + 0xFF) / 0x1FE;
                                *prgbaOut++ = u80.rgba;
                            }
                            AddVifMscal__4VIFSPv(&lb.uC0.s.vifsBatch, D_00000010);
                            ivtxBatch += 0x27;
                            *(int *)lb.uC0.s.vifsBatch.end = 0x90000000;
                            lb.uC0.s.vifsBatch.end += 4;
                        }
                    }
                }
            }

            float sOne = -1.0f;
            for (int ivtx = 0; ivtx < psm->cvtx; ivtx++) {
                int ipos = pipos[ivtx];
                if (pglob->count == 0) {
                    *(VEC3 *)psm->apos[ivtx] = apos[ipos];
                } else if (ivtx < psm->cvtxUnique) {
                    VEC3 *ppos = (VEC3 *)psm->apos[ivtx];
                    ppos->z = sOne;
                    ppos->y = sOne;
                    ppos->x = sOne;
                }
                if (*pbits & bitMask)
                    psm->apos[ivtx][3] = *psFog + 4096.0f;
                else
                    psm->apos[ivtx][3] = *psFog;
                bitMask <<= 1;
                if (bitMask == 0) {
                    bitMask = 1;
                    pbits++;
                }
                if (psm->auvl != 0) {
                    UV *puv = &auv[ipos];
                    psm->auvl[ivtx].u = (int)(puv->u * 4096.0f + 0.5f);
                    psm->auvl[ivtx].v = (int)(puv->v * 4096.0f + 0.5f);
                } else {
                    UV *puv = &auv[ipos];
                    psm->ast[ivtx].s = (int)(puv->u * 4096.0f + 0.5f);
                    psm->ast[ivtx].t = (int)(puv->v * 4096.0f + 0.5f);
                }
                if (psm->grf & 0x20) {
                    psm->aipos[ivtx] = ipos;
                    WEIGHTENTRY_16A000 *pentry = &pnormals->aset[pnormals->aiset[isubglob]].aentry[ipos];
                    psm->aiNormal[ivtx] = pentry->a;
                    psm->aiNormal2[ivtx] = pentry->b;
                    psm->aweightB[ivtx] = pentry->c;
                    if (psm->aweightA != 0) {
                        u80.rgba = argba[ipos];
                        lb.uC0.s.uF0.rgba = psm->pshd->rgba;
                        psm->aweightA[ivtx] = (u80.rgba.a * lb.uC0.s.uF0.rgba.a + 0xFF) / 0x1FE;
                    }
                }
            }
            pipos += psm->cvtx;

            if (!fAll) {
                if (ism == 0) {
                    AddVifMscal__4VIFSPv(&l.vifs, VU1_START_0);
                    if (pglob->type == 0xB || pglob->type == 0xD) {
                        AddVifMscal__4VIFSPv(&l.vifs, D_00003628);
                    } else {
                        char *pmscal;
                        switch (isubglob) {
                        case 0:
                            pmscal = fNoMat ? D_00002E20 : D_00002EF8;
                            break;
                        case 1:
                            pmscal = fNoMat ? D_00002E68 : D_00002F80;
                            break;
                        default:
                            pmscal = fNoMat ? D_00002EB0 : D_00002FC8;
                            break;
                        }
                        AddVifMscal__4VIFSPv(&l.vifs, pmscal);
                    }
                } else if (pglob->type == 0xB || pglob->type == 0xD) {
                    AddVifMscal__4VIFSPv(&l.vifs, D_000037A8);
                } else {
                    AddVifMscal__4VIFSPv(&l.vifs, fNoMat ? D_00002EE8 : D_00003358);
                }
            }
        }

        if (fAll) {
            AddVifMscal__4VIFSPv(&l.vifs, VU1_START_0);
            if (pglob->type == 0xB || pglob->type == 0xD) {
                AddVifMscal__4VIFSPv(&l.vifs, D_00003628);
                AddVifMscal__4VIFSPv(&l.vifs, D_000037A8);
            } else {
                switch (isubglob) {
                case 0:
                    AddVifMscal__4VIFSPv(&l.vifs, D_00002EF8);
                    break;
                case 1:
                    AddVifMscal__4VIFSPv(&l.vifs, D_00002F80);
                    break;
                default:
                    AddVifMscal__4VIFSPv(&l.vifs, D_00002FC8);
                    break;
                }
                AddVifMscal__4VIFSPv(&l.vifs, D_00003358);
            }
        }

        if (apair != 0) {
            PAIR_16A000 *ppairMax = apair + cvtx;
            SUBMESH_16A000 *psmPrev = 0;
            for (PAIR_16A000 *ppair = apair; ppair < ppairMax; ppair++) {
                SUBMESH_16A000 *psm = ppair->psm;
                DESC_16A000 *pdesc = &prec->adesc[psm - asm_];
                if (psmPrev != ppair->psmFirst) {
                    psmPrev = ppair->psmFirst;
                    DESC_16A000 *pdescFirst = &prec->adesc[psmPrev - asm_];
                    pdescFirst->link = pdesc->base + ppair->ivtx * 4;
                }
                int link = 0;
                if (ppair != ppairMax - 1 && ppair[1].psmFirst == psmPrev) {
                    link = prec->adesc[ppair[1].psm - asm_].base + ppair[1].ivtx * 4;
                    if ((ppair->ivtxFirst ^ ppair[1].ivtxFirst) == 0)
                        link |= 0x8000;
                }
                psm->auvl[ppair->ivtx].link = link;
            }
            float sScale = 127.0f;
            for (PAIR_16A000 *ppair = apair; ppair < ppairMax; ) {
                int ipos = ppair->ipos;
                SUBMESH_16A000 *psm = ppair->psmFirst;
                int ivtx = ppair->ivtxFirst;
                u80.rgba = argba[ipos];
                int r = u80.rgba.r;
                int g = u80.rgba.g;
                int b = u80.rgba.b;
                int lum;
                if (g < r && b < r) {
                    lum = r;
                } else {
                    lum = g;
                    if (b >= g)
                        lum = b;
                }
                float s = lum * 0.003921569f;
                if (psm->argbaNormal != 0) {
                    s *= sScale;
                    VEC3 *pnormal = &anormal[ipos];
                    RGBA *pout = &psm->argbaNormal[ivtx - psm->cvtxUnique];
                    pout->r = (int)(pnormal->x * sScale);
                    pout->g = (int)(pnormal->y * sScale);
                    pout->a = (int)s;
                    pout->b = (int)(pnormal->z * sScale);
                }
                if (psm->argbaLight != 0) {
                    lb.uC0.s.uF0.rgba = psm->pshd->rgba;
                    RGBA *pout = &psm->argbaLight[ivtx - psm->cvtxUnique];
                    pout->r = (u80.rgba.r * lb.uC0.s.uF0.rgba.r + 0xFF) / 0x200;
                    pout->g = (u80.rgba.g * lb.uC0.s.uF0.rgba.g + 0xFF) / 0x200;
                    pout->b = (u80.rgba.b * lb.uC0.s.uF0.rgba.b + 0xFF) / 0x200;
                    pout->a = (u80.rgba.a * lb.uC0.s.uF0.rgba.a + 0xFF) / 0x1FE;
                }
                if (pglob->count != 0) {
                    *(VEC3 *)psm->apos[ivtx] = apos[ipos];
                    int cweightVtx = 4;
                    if (pglob->count <= 3)
                        cweightVtx = pglob->count;
                    CopyAb__FPvT0Ui(psm->aweight + (ivtx - psm->cvtxUnique) * cweightVtx, aweight + ipos * cweightVtx, cweightVtx);
                }
                ppair++;
                while (ppair < ppairMax && ppair->psmFirst == psm && ppair->ivtxFirst == ivtx)
                    ppair++;
            }
        }
    }

    if (pglob->grf & 1) {
        EndDmaCnt__4DMAS(&l.vifs);
        AddDmaRet__4DMAS(&l.vifs);
        DMAS_DetachCopyPermanent(&l.vifs, &cqwDetach, &qwFrom, &qwTo);
        pglob->qwDma = cqwDetach;
        pglobi->qwDma = qwTo;
    } else {
        Align__4VIFSi(&l.vifs, 0);
        AddDmaRefs__4DMASiP2QW(&l.vifsRefs, (int)(l.vifs.end - qwRefStart) >> 4, (void *)qwRefStart);
        AddDmaRet__4DMAS(&l.vifsRefs);
        DMAS_DetachCopyPermanent(&l.vifs, &cqwDetach, &qwFrom, &qwTo);
        if (pglobi->pmat != 0) {
            pglobi->pmat->qw44 = cqwDetach;
            pglobi->pmat->qw48 = qwTo;
        }
        CopyGlobDmaChain(pglob, pglobi, (l.vifsRefs.end - l.vifsRefs.start) >> 4, l.vifsRefs.start, cqwDetach, qwTo, qwFrom);
        if (cbatch > 0) {
            EndDmaCnt__4DMAS(&lb.uC0.s.vifsBatch);
            AddDmaRet__4DMAS(&lb.uC0.s.vifsBatch);
            u32 cqwBatch = (lb.uC0.s.vifsBatch.end - lb.uC0.s.vifsBatch.start) >> 4;
            pcmparam->cqw = cqwBatch;
            u80.req.size = cqwBatch << 4;
            preq->align = 0x10;
            pglob->pdma = PvAllocSwCopyImpl__FiPv(preq, (void *)lb.uC0.s.vifsBatch.start);
        }
    }
    if (pnormals != 0)
        pglobset->field4C = B_003E11EC;
    pglobi->grf = (pglobi->grf & 0x803FFFFF) | ((B_003DA790 & 0x1FF) << 22);
    func_001EC740((pglobi->grf >> 13) & 0x1FF, (pglobi->grf >> 22) & 0x1FF, cqwDetach << 4, qwFrom, qwTo);

    if (pglobi->pobj != 0) {
        for (SLE_16A000 *psle = pglobi->pobj->sl; psle != 0; psle = psle->next) {
            RelocateQw(&psle->apos, cqwDetach << 4, qwFrom, qwTo);
            for (int iobj = 0; iobj < pglobi->pobj->count; iobj++)
                RelocateQw(&psle->aptr[iobj], cqwDetach << 4, qwFrom, qwTo);
        }
    }

    if (pglob->grf & 8) {
        int csmTotal = 0;
        for (int isubglob = 0; isubglob < csubglob; isubglob++)
            csmTotal += acsm[isubglob];
        u80.req.size = 0x10;
        preq->align = 0x10;
        SAVED_16A000 *psaved = (SAVED_16A000 *)PvAllocSwClearImpl__Fi(preq);
        psaved->next = pglobset->psavedFirst;
        pglobset->psavedFirst = psaved;
        psaved->pglob = pglob;
        psaved->csm = csmTotal;
        u80.req.size = csmTotal << 5;
        preq->align = 0x10;
        psaved->asm_ = (SAVEDSM_16A000 *)PvAllocSwImpl__Fi(preq);
        SAVEDSM_16A000 *psavedsm = psaved->asm_;
        for (int isubglob = 0; isubglob < csubglob; isubglob++) {
            SUBMESH_16A000 *psm = aasm[isubglob];
            for (int ism = 0; ism < acsm[isubglob]; ism++) {
                psavedsm->cvtx = psm->cvtx;
                psavedsm->grf = psm->grf;
                psavedsm->apos = QwRelocated((u32)psm->apos, cqwDetach << 4, qwFrom, qwTo);
                psavedsm->ast = QwRelocated((u32)psm->ast, cqwDetach << 4, qwFrom, qwTo);
                psavedsm->auvl = QwRelocated((u32)psm->auvl, cqwDetach << 4, qwFrom, qwTo);
                psavedsm->alight = QwRelocated((u32)psm->argbaLight, cqwDetach << 4, qwFrom, qwTo);
                psavedsm->anormal = QwRelocated((u32)psm->argbaNormal, cqwDetach << 4, qwFrom, qwTo);
                psavedsm->field1C = 0;
                psm++;
                psavedsm++;
            }
        }
    }

    func_001699E8(pglobset, pglob, pglobi, pextra, cextra, csubglob, acsm, aasm, pbis);
}
