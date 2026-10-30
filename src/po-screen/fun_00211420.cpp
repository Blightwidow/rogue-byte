#include "sly2.h"
struct Kind { int p0; int idx; };
struct Carried { char p0[0x224]; int sid; char p1[0x244 - 0x228]; Kind *pkind; };
struct JT { char p0[0x4C8]; int attachKind; char p1[0x9A0 - 0x4CC]; Carried *pcarried; char p2[0x1318 - 0x9A4]; int sidDefault; };
struct Rec { int a; int sid; int c; };
extern "C" {
extern char B_003DD490;
extern Rec D_002C3288[];
void *PpoSwFocusBase(void *);
int FIsBasicDerivedFrom(void *, int);
char *PchzStringFromId(void *, int);
char *strcpy(char *, const char *);
}
void func_00211420(char *pchzDest)
{
    int sid = -1;
    JT *pjt = (JT *)PpoSwFocusBase(&B_003DD490);
    if (pjt != 0) {
        if (FIsBasicDerivedFrom(pjt, 0x34)) {
            Carried *pcarried = pjt->pcarried;
            if (pcarried != 0) {
                int kind = pjt->attachKind;
                if (kind == 0xC) {
                    if (FIsBasicDerivedFrom(pcarried, 0x5E))
                        sid = D_002C3288[pcarried->pkind->idx].sid;
                    else if (FIsBasicDerivedFrom(pcarried, 0x5C))
                        sid = pcarried->sid;
                    else
                        sid = pjt->sidDefault;
                }
            }
        }
    }
    if (sid != -1)
        strcpy(pchzDest, PchzStringFromId(&B_003DD490, sid));
    else
        *pchzDest = 0;
}
