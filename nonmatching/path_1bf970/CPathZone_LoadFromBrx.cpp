#include "sly2.h"
struct BIS;
struct REQ { int size; int align; };
struct Vert { VECTOR pos; int n; char **list; char pad[8]; };
struct Edge { Vert *v[3]; };
struct Brx { float x, y, z; short a; short b; };
struct PZ { char pad0[0x18]; int kind; char pad1[0xE0 - 0x1C]; int nVerts; Vert *verts; int nEdges; char *edges; int nB; Brx *bs; char pad2[0x114 - 0xF8]; int serial; };
struct SW { char pad[0x3D70]; int serial; char pad2[0x45C8 - 0x3D74]; PZ *pz; };
extern "C" {
void LoadXfmFromBrx(void *, BIS *);
void *PvAllocSwClearImpl__Fi(REQ *);
void *PvAllocSwImpl__Fi(REQ *);
void ReadVector__18CBinaryInputStreamP6VECTOR(BIS *, VECTOR *);
float F32Read__18CBinaryInputStream(BIS *);
int U16Read__18CBinaryInputStream(BIS *);
int U8Read__18CBinaryInputStream(BIS *);
void HookupCg__FP2CG(void *);
extern SW B_003DD490;
}
extern "C" void CPathZone_LoadFromBrx(PZ *o, BIS *in)
{
    REQ request;
    int i = 0;
    int j;
    LoadXfmFromBrx(o, in);
    o->nVerts = U16Read__18CBinaryInputStream(in);
    request.size = o->nVerts << 5;
    request.align = 0x10;
    o->verts = (Vert *)PvAllocSwClearImpl__Fi(&request);
    o->nEdges = U16Read__18CBinaryInputStream(in);
    request.size = o->nEdges * 12;
    request.align = 0x10;
    o->edges = (char *)PvAllocSwClearImpl__Fi(&request);
    if (o->nVerts > 0) {
        do {
            Vert *v = (Vert *)((char *)o->verts + (i << 5));
            int k = i + 1;
            j = 0;
            ReadVector__18CBinaryInputStreamP6VECTOR(in, &v->pos);
            v->n = U8Read__18CBinaryInputStream(in);
            request.size = v->n * 8 + 8;
            request.align = 0x10;
            v->list = (char **)PvAllocSwImpl__Fi(&request);
            if (v->n > 0) {
                do {
                    char **slot = (char **)((char *)v->list + j * 8);
                    j++;
                    *slot = (char *)o->verts + (U16Read__18CBinaryInputStream(in) << 5);
                } while (j < v->n);
            }
            i = k;
        } while (i < o->nVerts);
    }
    {
        int e;
        for (e = 0; e < o->nEdges; e++) {
            Vert **p = (Vert **)(o->edges + e * 12);
            j = 2;
            do {
                j--;
                *p = (Vert *)((char *)o->verts + (U16Read__18CBinaryInputStream(in) << 5));
                p++;
            } while (j >= 0);
        }
    }
    o->nB = U16Read__18CBinaryInputStream(in);
    request.size = o->nB << 4;
    request.align = 0x10;
    o->bs = (Brx *)PvAllocSwClearImpl__Fi(&request);
    for (i = 0; i < o->nB; i++) {
        Brx *b = &o->bs[i];
        b->x = F32Read__18CBinaryInputStream(in);
        b->y = F32Read__18CBinaryInputStream(in);
        b->z = F32Read__18CBinaryInputStream(in);
        b->a = U16Read__18CBinaryInputStream(in);
        b->b = U16Read__18CBinaryInputStream(in);
    }
    HookupCg__FP2CG(&o->nVerts);
    if (o->kind == 0x2CA)
        B_003DD490.pz = o;
    B_003DD490.serial++;
    o->serial = B_003DD490.serial;
}
