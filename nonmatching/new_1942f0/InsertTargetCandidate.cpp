#include "sly2.h"
void *memmove(void *, const void *, unsigned int);
struct Obj { char pad[0x18]; int group; };
struct JT {
    char pad0[0x2CC]; Obj *jumpTarget; char pad1[0x37C - 0x2D0]; Obj *obj37c;
    char pad2[0x4D4 - 0x380]; Obj *attach; Obj *attach2;
    char pad3[0xF5C - 0x4DC]; Obj *objF5c;
    char pad4[0x1000 - 0xF60]; unsigned mask;
    char pad5[0x18C4 - 0x1004]; Obj *obj18c4;
    char pad6[0x1F18 - 0x18C8]; Obj *obj1f18;
};
struct Lo { char pad[0x10]; int ranged; char pad2[0x38 - 0x14]; float radius; };
struct Member;
struct VT {
    char pad0[0x10]; short d1; short i1; void (*getU)(void *, JT *, float *);
    short d2; short i2; void (*getPos)(void *, float, JT *, QW *, int);
    short d3; short i3; void (*adjust)(void *, float *);
};
struct Member { char pad[0x10]; int priority; char pad1[4]; int group; unsigned mask; VT *vt; };
struct Target { Lo *plo; Member *pmember; float sDist; int nPriority; int pindicator; float tStart; float u; int du; QW pos; };
extern "C" {
QW PosLoWorld(Lo *);
extern JT *g_2e1e40;
extern int B_002E1E4C;
extern float D_FLT_002BF664;
extern float g_2dded0;
}
void CopyAb__FPvT0Ui(void *, void *, unsigned int);
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }

void InsertTargetCandidate(void *unused, JT *jt, QW posFrom, Lo *plo, Member *member, int ctarget, Target *atarget)
{
    if (plo->ranged != 0) {
        QW pos = PosLoWorld(plo);
        float radius = plo->radius;
        asm volatile("qmtc2.ni %0, vf2\n\tlqc2 vf3, %1\n\tvsub.xyzw vf1, vf2, vf3" : : "r" (pos), "m" (posFrom));
        float radiusSquared = radius * radius;
        QW lengthBits;
        asm volatile("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (lengthBits));
        if (radiusSquared < Lane(lengthBits))
            return;
    }
    Obj *attach = jt->attach;
    if (plo == (Lo *)attach || plo == (Lo *)jt->jumpTarget)
        return;
    if (member->group != 0 && jt->attach2 != 0 && member->group == jt->attach2->group)
        return;
    if (plo == (Lo *)jt->obj37c)
        return;
    Obj *objF5c = jt->objF5c;
    if (plo == (Lo *)objF5c)
        return;
    JT *sly = g_2e1e40;
    if (jt == sly) {
        if (plo == (Lo *)jt->obj18c4 || plo == (Lo *)jt->obj1f18)
            return;
    }
    if ((jt->mask & member->mask) == 0)
        return;
    if (B_002E1E4C != 0) {
        if (attach != 0)
            return;
        if (objF5c != 0)
            return;
        if (jt == sly) {
            if (jt->obj18c4 != 0)
                return;
            if (jt->obj1f18 != 0)
                return;
        }
    }
    Target local;
    VT *vt = member->vt;
    vt->getU((char *)member + vt->d1, jt, &local.u);
    vt = member->vt;
    vt->getPos((char *)member + vt->d2, local.u, jt, &local.pos, 0);
    asm volatile("lqc2 vf2, %0\n\tlqc2 vf1, %1\n\tvsub.xyzw vf1, vf2, vf1" : : "m" (posFrom), "m" (local.pos));
    local.nPriority = member->priority;
    vt = member->vt;
    asm volatile("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    QW distBits;
    asm volatile("qmfc2.ni %0, vf1" : "=r" (distBits));
    local.sDist = Lane(distBits);
    vt->adjust((char *)member + vt->d3, &local.sDist);
    if (D_FLT_002BF664 < local.sDist)
        return;
    int group = member->group;
    int index = ctarget;
    if (group != 0) {
        if (ctarget > 0 && atarget[0].pmember != 0) {
            index = 0;
            Target *entry = atarget;
            do {
                Member *other = entry->pmember;
                if (other->group == group) {
                    if (local.sDist < atarget[index].sDist) {
                        CopyAb__FPvT0Ui(&atarget[index], &atarget[index + 1], (ctarget - index - 1) * sizeof(Target));
                        memset(&atarget[ctarget - 1], 0, sizeof(Target));
                        atarget[ctarget - 1].sDist = D_FLT_002BF664;
                        break;
                    }
                    return;
                }
                index++;
                entry++;
            } while (index < ctarget && entry->pmember != 0);
            index = ctarget;
        }
    }
    int priority = local.nPriority;
    float dist = local.sDist;
    Target *prev = &atarget[index - 1];
    for (;;) {
        int prevPriority = prev->nPriority;
        index--;
        if (priority < prevPriority) { index++; break; }
        if (prevPriority == priority && prev->sDist < dist) { index++; break; }
        if (index == 0) break;
        prev--;
    }
    if (index == ctarget)
        return;
    memmove(&atarget[index + 1], &atarget[index], (ctarget - index) * sizeof(Target) - sizeof(Target));
    asm("" : "+r" (index));
    local.plo = plo;
    local.pmember = member;
    local.tStart = g_2dded0;
    local.pindicator = 0;
    local.du = 0;
    atarget[index] = local;
}
