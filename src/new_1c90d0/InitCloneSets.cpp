#include "sly2.h"
struct VTE { short delta; short index; void *fn; };
struct XFLO { char pad[0x24]; int flag; };
struct VTLO { char pad0[0xC8]; VTE setCloneId; };
struct LO { char pad[0xC]; VTLO *vt; char pad10[0x2C]; XFLO *xf; };
struct ALLOCREQ { int cb; int cbAlign; };
struct CLONESET { int cpalo; LO **apalo; int cclone; int icloneFree; char pad10[4]; int value; int *aoidClone; char pad1c[0x64 - 0x1C]; char *amat; char *axf; char pad6c[0]; };
struct SW { char pad[0x3F04]; int cset; CLONESET *acloneSet; };
struct MAT { VECTOR pos; VECTOR row[3]; };
struct ROWS3 { VECTOR row[3]; };
struct XFC { VECTOR pos; float mat[16]; };
extern "C" {
unsigned MakeCloneId(int, int);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
QW PosLoWorld(LO *);
ROWS3 *PmatLoWorld(LO *);
void NormalizeRotateMatrix3__FP7MATRIX3(MATRIX3 *);
static inline void SetIdentity_1CA500(float *mat)
{
    memset(mat, 0, 0x40);
    mat[0xF] = 1.0f;
    mat[10] = 1.0f;
    mat[5] = 1.0f;
    mat[0] = 1.0f;
}
void InitCloneSets(SW *sw) {
    int iset = 0;
    int iclone, index;
    LO *lo;
    while (iset < sw->cset) {
        CLONESET *set = sw->acloneSet + iset;
        int next = iset + 1;
        if (set->icloneFree < set->cclone) {
            iclone = set->icloneFree;
            do {
                unsigned cloneid = MakeCloneId(iset, iclone);
                set->aoidClone[iclone] = set->value;
                index = 0;
                while (index < set->cpalo) {
                    lo = set->apalo[iclone * set->cpalo + index];
                    index++;
                    ((void (*)(void *, unsigned, int))lo->vt->setCloneId.fn)((char *)lo + lo->vt->setCloneId.delta, cloneid, 1);
                    lo->xf->flag = 1;
                }
                iclone++;
            } while (iclone < set->cclone);
            ALLOCREQ request;
            request.cb = set->cpalo << 6;
            request.cbAlign = 0x10;
            set->amat = (char *)PvAllocSwClearImpl__Fi(&request);
            index = 0;
            while (index < set->cpalo) {
                MAT *mat = (MAT *)set->amat + index;
                lo = set->apalo[set->icloneFree * set->cpalo + index];
                index++;
                *(QW *)&mat->pos = PosLoWorld(lo);
                ROWS3 *rows = PmatLoWorld(lo);
                mat->row[0] = rows->row[0];
                mat->row[1] = rows->row[1];
                mat->row[2] = rows->row[2];
                NormalizeRotateMatrix3__FP7MATRIX3((MATRIX3 *)mat->row);
            }
            request.cb = (set->cclone - set->icloneFree) * 0x50;
            request.cbAlign = 0x10;
            set->axf = (char *)PvAllocSwClearImpl__Fi(&request);
            for (iclone = set->icloneFree; iclone < set->cclone; iclone++)
                SetIdentity_1CA500(((XFC *)set->axf)[iclone - set->icloneFree].mat);
        }
        iset = next;
    }
}
}
