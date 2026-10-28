#include "sly2.h"
struct CLS { int cid; int pad; };
struct STG { char pad[0x150]; int count; CLS *classes; };
struct CONTACT { void *toucher; char pad[0x8]; int hit; char pad2[0x30]; unsigned long grf; };
extern "C" int FStgSwitchDone(STG *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void SetStgSwitchHitter(STG *, void *, int);
int func_001BADF0(STG *stg, CONTACT *contact)
{
    if (FStgSwitchDone(stg))
        return 0;
    if (((int *)contact)[0x44 / 4] == 0)
        return 0;
    if ((contact->grf & 0xC00000000UL) != 0x800000000UL)
        return 1;
    if (stg->count != 0 && contact->toucher != stg) {
        int index = 0;
        while (index < stg->count) {
            if (FIsBasicDerivedFrom(contact->toucher, stg->classes[index].cid))
                break;
            index++;
        }
        if (!(index < stg->count))
            return 0;
    }
    SetStgSwitchHitter(stg, contact->toucher, contact->hit);
    return 1;
}
