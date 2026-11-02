struct QW;
struct CM;
struct FGFN;
struct CBinaryInputStream;
enum UPK { UPK_0 };

class CStackFrame {
public:
    int w;
    CStackFrame();
    ~CStackFrame();
};

class DMAS {
public:
    int w0;
    unsigned pqwStart;
    int w8;
    unsigned pqwCur;
    int rest[8];
    void AllocStack(int);
    void AddDmaCnt();
    void EndDmaCnt();
    void AddDmaRet();
    void Reset();
};

class VIFS : public DMAS {
public:
    VIFS();
    void UnpackHelper(UPK, int, int, int *, unsigned **);
    void AddVifUnpack(UPK, int, void *, int);
    void AddVifStrow(QW *);
    void AddVifStmask(unsigned);
    void AddVifMscal(void *);
};

class GIFS : public DMAS {
public:
    GIFS();
    void AddPrimPack(int, int, unsigned long);
    void PackAD(long, long);
    void PackRGBA(unsigned);
    void PackXYZF(int, int, int, int);
    void EndPrim(int);
};

struct ALLOC_16E438 {
    int cb;
    int align;
    ALLOC_16E438(int cbNew, int alignNew) { cb = cbNew; align = alignNew; }
};
struct SUBGLOB_16E438 { int a; int b; int c; int d[17]; };
struct GLOB_16E438 { char pad0; signed char cweight; char pad2[10]; int base; char pad10[4]; };
struct GLOBI_16E438 { char pad0[0x10]; char pad10[8]; SUBGLOB_16E438 *asub; };
struct DESC_16E438 { unsigned short flags; short a; short b; short pad6; short c; short d; short e; short f; short idx[4]; };

void BuildCmFgfn(CM *, float, FGFN *);
int PvAllocSwClearImpl(int);

extern "C" {
int U8Read__18CBinaryInputStream(CBinaryInputStream *);
int S16Read__18CBinaryInputStream(CBinaryInputStream *);
int S32Read__18CBinaryInputStream(CBinaryInputStream *);
SUBGLOB_16E438 *PvAllocSwClearImpl__Fi(ALLOC_16E438);
void *memset(void *, int, unsigned);
void VIFS_AddVifUnpackFromStream(VIFS *, int, int, CBinaryInputStream *, int);
void DMAS_DetachCopyPermanent(VIFS *, void *, void *, void *);
void func_001699E8(int, GLOB_16E438 *, GLOBI_16E438 *, int, int, int, int, int, CBinaryInputStream *);
extern CM B_002DDF40;
extern QW B_002DEB60;
extern unsigned D_002BE540[];
extern int D_002BE558[];
extern unsigned g_2deb50;
extern char VU1_START_0[];
extern char D_00000738[];
extern char D_000007F0[];

void LoadGlobSkinnedFromBrx(int arg0, GLOB_16E438 *pglob, GLOBI_16E438 *pglobi, float *pr, int arg4, int arg5,
                            CBinaryInputStream *pbis) {
    VIFS vifs;
    CStackFrame frame;
    FGFN *pfgfn;

    vifs.AllocStack(0x2000);
    vifs.AddDmaCnt();
    vifs.UnpackHelper((UPK)0xC, 1, 9, 0, (unsigned **)&pfgfn);
    BuildCmFgfn(&B_002DDF40, *pr, pfgfn);
    pglob->cweight = U8Read__18CBinaryInputStream(pbis);
    pglobi->asub = PvAllocSwClearImpl__Fi(ALLOC_16E438(pglob->cweight * 0x50, 0x10));
    for (int i = 0; i < pglob->cweight; i++) {
        SUBGLOB_16E438 *psub = &pglobi->asub[i];
        psub->a = S32Read__18CBinaryInputStream(pbis);
        psub->c = S16Read__18CBinaryInputStream(pbis);
    }
    int base = 0x22;
    GIFS gifs;
    gifs.AllocStack(8);
    gifs.AddPrimPack(0, 2, 0x1E);
    gifs.PackAD(0x42, 0x44);
    gifs.PackRGBA(g_2deb50);
    gifs.EndPrim(1);
    vifs.AddVifUnpack((UPK)0xC, (gifs.pqwCur - gifs.pqwStart) >> 4, (void *)gifs.pqwStart, 0xD);
    gifs.Reset();
    gifs.AddPrimPack(0xC1, 3, 0x44E);
    gifs.PackAD(0x47, 0x73001);
    gifs.PackXYZF(0, 0, 0, 0);
    gifs.PackXYZF(0, 0, 0, 0);
    gifs.EndPrim(0);
    gifs.AddPrimPack(1, 3, 0x44E);
    gifs.PackAD(0x47, 0x72001);
    gifs.PackXYZF(0, 0, 0, 0);
    gifs.PackXYZF(0, 0, 0, 0);
    gifs.EndPrim(1);
    vifs.AddVifUnpack((UPK)0xC, 2, (void *)gifs.pqwStart, 0x12);
    vifs.AddVifUnpack((UPK)0xC, 2, (void *)(gifs.pqwStart + 0x40), 0x16);
    vifs.AddVifUnpack((UPK)0xC, 2, (void *)gifs.pqwStart, 0x1A);
    vifs.AddVifUnpack((UPK)0xC, 2, (void *)(gifs.pqwStart + 0x40), 0x1E);
    if (pglob->cweight != 0) {
        pglob->base = base;
        base += pglob->cweight * 4;
    }
    int cpass = S16Read__18CBinaryInputStream(pbis);
    void *pvGlob = (char *)pglob + 0x10;
    void *pvGlobi = (char *)pglobi + 0x10;
    for (int ipass = 0; ipass < cpass; ipass++) {
        CStackFrame frameLoop;
        DESC_16E438 *pdesc;
        vifs.UnpackHelper((UPK)0xD, 3, 0xA, 0, (unsigned **)&pdesc);
        memset(pdesc, 0, 0x18);
        switch (ipass) {
        case 0:
            pdesc->flags |= 1;
            break;
        case 1:
            pdesc->flags |= 2;
            break;
        }
        int offset = base;
        pdesc->a = offset;
        int cvtx = U8Read__18CBinaryInputStream(pbis);
        VIFS_AddVifUnpackFromStream(&vifs, 8, cvtx, pbis, offset);
        pdesc->c = offset;
        offset += cvtx;
        pdesc->d = offset;
        if (pglob->cweight != 0) {
            int cweight = U8Read__18CBinaryInputStream(pbis);
            int iweight;
            for (iweight = 0; iweight < cweight; iweight++) {
                pdesc->idx[iweight] = (short)pglob->base + U8Read__18CBinaryInputStream(pbis) * 4;
            }
            for (; iweight < 4; iweight++) {
                pdesc->idx[iweight] = pdesc->idx[0];
            }
            if (cweight < 4) {
                vifs.AddVifStrow(&B_002DEB60);
                vifs.AddVifStmask(D_002BE540[cweight]);
            }
            VIFS_AddVifUnpackFromStream(&vifs, D_002BE558[cweight], cvtx, pbis, offset);
            pdesc->b = offset;
            offset += cvtx;
            if (cweight < 4) {
                vifs.AddVifStmask(0);
            }
        }
        int cnormal = U8Read__18CBinaryInputStream(pbis);
        VIFS_AddVifUnpackFromStream(&vifs, 0xE, cnormal, pbis, offset);
        pdesc->e = offset;
        pdesc->f = offset + cnormal;
        vifs.AddVifMscal(VU1_START_0);
        vifs.AddVifMscal(D_00000738);
        vifs.AddVifMscal(D_000007F0);
    }
    vifs.EndDmaCnt();
    vifs.AddDmaRet();
    int dmaCopy;
    DMAS_DetachCopyPermanent(&vifs, pvGlob, &dmaCopy, pvGlobi);
    func_001699E8(arg0, pglob, pglobi, arg4, arg5, 0, 0, 0, pbis);
}
}
