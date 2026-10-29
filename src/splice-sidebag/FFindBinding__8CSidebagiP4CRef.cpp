// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Binding_12AB28 { char pad0[8]; int iKey; char ref[8]; Binding_12AB28 *next; };
struct Sidebag_12AB28 { char pad0[8]; Binding_12AB28 *head; };
extern "C" {
void *__as__4CRefRC4CRef(void *dst, void *src);
}

extern "C" int FFindBinding__8CSidebagiP4CRef(Sidebag_12AB28 *psidebag, int iKey, void *pref)
{
    for (Binding_12AB28 *pbinding = psidebag->head; pbinding != 0; pbinding = pbinding->next) {
        if (pbinding->iKey == iKey) {
            if (pref != 0) __as__4CRefRC4CRef(pref, pbinding->ref);
            return 1;
        }
    }
    return 0;
}
