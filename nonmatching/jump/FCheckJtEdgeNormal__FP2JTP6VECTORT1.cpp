#include "sly2.h"
struct Coll { char p0[0x10]; long flags; char p1[0x48]; Coll *next; };
struct Body { char p0[0x34]; Coll *head; char p1[0x38]; long flags; };
struct Obj { char p0[0xEC]; Body *body; };
struct Node { char p0[4]; Node *next; char p1[4]; Obj *obj; };
struct Holder { char p0[0x64]; Node *head; };
struct Owner { char p0[0xEC]; Holder *holder; };
struct JT { Owner *owner; };
struct M4 { QW row[4]; };
struct Out { char p0[0x28]; float dot; char p1[0x14]; float len; char p2[0x2C]; };
extern "C" {
void GetNormalVectors__FP6VECTORN30(QW, QW, QW, QW *);
s32 __as__6VECTORG9VU_VECTOR(QW *, QW);
void BuildJmpEdgeProbes(JT *, JT *, M4 *, int);
int ClsgClipEdgeToObject(Coll *, QW, QW, int, Out *);
extern QW g_2a2db0;
extern QW g_2a2dc0;
}
int FCheckJtEdgeNormal(JT *jt, QW pos, QW normal)
{
    struct { QW q; QW n[2]; M4 mat; QW probe[22]; Out out; } l;
    int hits = 0;
    l.q = normal;
    GetNormalVectors__FP6VECTORN30(normal, g_2a2dc0, g_2a2db0, l.n);
    M4 *pmat = &l.mat;
    __as__6VECTORG9VU_VECTOR(&l.mat.row[3], pos);
    pmat->row[0] = l.q;
    pmat->row[1] = l.n[0];
    pmat->row[2] = l.n[1];
    ((int *)pmat)[0x5C / 4 - 0xC] = 0;
    ((int *)pmat)[0x4C / 4 - 0xC] = 0;
    ((int *)pmat)[0x3C / 4 - 0xC] = 0;
    ((float *)pmat)[0x3C / 4 - 0xC] = 1.0f;
    BuildJmpEdgeProbes(jt, jt, pmat, 0x16);
    for (Node *node = jt->owner->holder->head; node; node = node->next) {
        if (node->obj->body->flags & 4) continue;
        QW *pa = l.probe;
        for (unsigned i = 0; i < 0x16; i += 2, pa += 2) {
            for (Coll *coll = node->obj->body->head; coll; coll = coll->next) {
                if (coll->flags & (0x8000L << 33)) continue;
                if (ClsgClipEdgeToObject(coll, l.probe[i + 1], *pa, 1, &l.out) > 0) {
                    if (i < 4) return 0;
                    if (l.out.len == 0.0f) return 0;
                    if (l.out.dot > 0.7f) hits++;
                }
            }
        }
    }
    return hits >= 2;
}
