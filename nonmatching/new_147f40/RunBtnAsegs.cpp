#include "sly2.h"
struct Lo { char pad[0x18]; int oid; };
struct AsegRec { Lo *plo; };
struct Aseg { char pad[0x14]; AsegRec *rec; };
struct AshEntry { Aseg *paseg; int grfapl; };
struct Ash { int caseg; AshEntry aaseg[8]; char pad[0x44 - 4 - 64]; };
struct Btn {
    Lo *owner; Ash aash[2]; char pad[0x8C - 0x4 - 0x88]; float svt; char pad90[0xA0 - 0x90];
    int fSeekEnd; char padA4[4]; int pjsgSubject; int pjsg; int crsmg; char arsmg[1];
};
enum SEEK { SEEK_X };
extern char B_003DD490[];
extern char B_002DEB30[];
extern "C" {
void *PloFindSwObject_thunk(void *, int, int, void *);
void PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(Aseg *, void *, SEEK, float, float, int);
void TriggerRsmg(void *, int, void *, void *, int);
void StartJsg(int, int);
void ApplyTaskStateRequests(void *, int, void *, void *);
}
extern "C" void RunBtnAsegs(Btn *pbtn, int iash)
{
    Ash *pash = pbtn->aash + iash;
    int i;
    for (i = 0; i < pash->caseg; i++) {
        Aseg *paseg = pash->aaseg[i].paseg;
        if (paseg != 0) {
            Lo *owner = pbtn->owner;
            int oid = paseg->rec->plo->oid;
            int grf = pash->aaseg[i].grfapl;
            Lo *target = owner;
            if (owner->oid != oid) {
                if (oid != -1)
                    target = (Lo *)PloFindSwObject_thunk(B_003DD490, 4, oid, owner);
                else
                    target = 0;
            }
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
