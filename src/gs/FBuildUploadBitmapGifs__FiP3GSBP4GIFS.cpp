#include "sly2.h"
struct Ctl { int pad0; int f4; int f8; };
struct Ctx { int pad0[3]; int fC; };
struct Clut { int id; unsigned char group; char pad5[5]; unsigned short size; int fC; int f10; long f18; };
struct Bmp { int id; unsigned char group; char pad5[7]; unsigned char fC; char padD; unsigned short size; int f10; int f14; int f18; int pad1C; long f20; };
extern "C" {
void AddDmaRefs__4DMASiP2QW(Ctx *, int, int);
void AddToIdTableA_1ed470(Bmp *);
void AddToIdTableB_1ed560(Clut *);
int AllocZpr(Ctl *, int);
void BuildBmpGifs__FP3BMPiP4GIFS(Bmp *, int, Ctx *);
void BuildBmpTex0__FP3BMPi(Bmp *, int);
void BuildClutGifs__FP4CLUTiP4GIFS(Clut *, int, Ctx *);
void BuildClutTex2__FP4CLUTi(Clut *, int);
Bmp *PidFindInIdTableA_1ed4e0(int);
Clut *PidFindInIdTableB_1ed5d0(int);
extern int B_003DCFF0;
extern Bmp *B_003DCFF4;
extern int B_003DCFF8;
extern Clut *B_003DCFFC;
}
extern "C" int FBuildUploadBitmapGifs__FiP3GSBP4GIFS(int mask, Ctl *b, Ctx *c)
{
    int saved;
    if (c != 0) {
        saved = c->fC;
    } else {
        saved = 0;
    }
    for (int i = 0; i < B_003DCFF8; i++) {
        Clut *e = &B_003DCFFC[i];
        if (mask == e->group) {
            Clut *found = PidFindInIdTableB_1ed5d0(e->id);
            if (found != 0) {
                e->f18 = found->f18;
            } else {
                int v = AllocZpr(b, e->size);
                BuildClutTex2__FP4CLUTi(e, v);
                if (c != 0 && b->f4 <= b->f8) {
                    BuildClutGifs__FP4CLUTiP4GIFS(e, v, c);
                    AddDmaRefs__4DMASiP2QW(c, e->f10, e->fC);
                }
                AddToIdTableB_1ed560(e);
            }
        }
    }
    for (int i = 0; i < B_003DCFF0; i++) {
        Bmp *e = &B_003DCFF4[i];
        if (mask == e->group) {
            Bmp *found = PidFindInIdTableA_1ed4e0(e->id);
            if (found != 0) {
                e->f20 = found->f20;
            } else {
                if (e->fC == 0) {
                    int rem = b->f4 & 0x1F;
                    if (rem != 0)
                        AllocZpr(b, 0x20 - rem);
                }
                int v = AllocZpr(b, e->size);
                BuildBmpTex0__FP3BMPi(e, v);
                if (c != 0 && b->f4 <= b->f8) {
                    BuildBmpGifs__FP3BMPiP4GIFS(e, v, c);
                    AddDmaRefs__4DMASiP2QW(c, e->f18, e->f14);
                }
                AddToIdTableA_1ed470(e);
            }
        }
    }
    if (c == 0)
        return 0;
    return c->fC != saved;
}
