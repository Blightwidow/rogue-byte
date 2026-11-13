#include "sly2.h"
struct Lo { char pad[0x18]; int oid; };
struct AsegRec { Lo *plo; };
struct Aseg { char pad[0x14]; AsegRec *rec; };
struct AshEntry { Aseg *paseg; int grfapl; };
struct Ash { int caseg; AshEntry aaseg[8]; };
struct Btn {
    Lo *owner; Ash aash[2]; char pad[0x8C - 0x4 - 0x88]; float svt; char pad90[0xA0 - 0x90];
    int fSeekEnd; char padA4[4]; Lo *pjsgSubject; void *pjsg; int crsmg; char arsmg[1];
};
enum SEEK { SEEK_X };
extern char B_003DD490[];
extern char B_002DEB30[];
extern "C" {
void *PloFindSwObject_thunk(void *, int, int, void *);
void PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(Aseg *, void *, SEEK, float, float, int);
void TriggerRsmg(void *, int, void *, void *, int);
void StartJsg(void *, Lo *);
void ApplyTaskStateRequests(void *, int, void *, void *);
}
// Retail: StartJsg takes (JSG *, ALO *): $a0 = pbtn->pjsg (0xAC), $a1 = pbtn->pjsgSubject (0xA8), so the
// call passes the joint-sequence pointer, not pbtn. The owner is read through pbtn->owner at each use (no
// copy into a local target first): retail keeps pbtn in $s0 and paseg in $s1, which a separate owner local
// swapped. Ash is exactly 0x44 bytes (caseg + 8 entries), no padding.
// Remaining (score 3): retail forms the loop entry pointer as iash*0x44 + (pbtn + 0xC); ours as
// (iash*0x44 + 0xC) + pbtn (loop.c giv base order). Entry-pointer, Ash-pointer, pointer-increment,
// unsigned iash, continue and statement-order (permuter) forms did not change it.
extern "C" void RunBtnAsegs(Btn *pbtn, int iash)
{
    int i;
    for (i = 0; i < pbtn->aash[iash].caseg; i++) {
        Aseg *paseg = pbtn->aash[iash].aaseg[i].paseg;
        if (paseg != 0) {
            int oid = paseg->rec->plo->oid;
            int grf = pbtn->aash[iash].aaseg[i].grfapl;
            Lo *target;
            if (pbtn->owner->oid == oid)
                target = pbtn->owner;
            else if (oid != -1)
                target = (Lo *)PloFindSwObject_thunk(B_003DD490, 4, oid, pbtn->owner);
            else
                target = 0;
            if (pbtn->fSeekEnd != 0) {
                int seek = 0;
                if (pbtn->svt < 0.0f)
                    seek = 2;
                PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(paseg, target, (SEEK)seek, 0.0f, pbtn->svt, grf);
            } else {
                PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(paseg, target, (SEEK)1, 0.0f, pbtn->svt, grf);
            }
        }
    }
    TriggerRsmg(B_003DD490, pbtn->crsmg, pbtn->arsmg, pbtn->owner, iash == 0);
    if (iash == 0) {
        if (pbtn->pjsg != 0)
            StartJsg(pbtn->pjsg, pbtn->pjsgSubject);
        ApplyTaskStateRequests(B_002DEB30, *(int *)((char *)pbtn + 0x134), (char *)pbtn + 0x138, pbtn->owner);
    }
}
