/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct PO { char pad[0x150]; void *pvjoy; };
struct VT278 { char pad[0x278]; short delta; short index; void (*fn)(void *, int); };
struct SWG { char pad[0x3EB8]; unsigned cpo; PO *apo[16]; char pad2[0x3EFC - 0x3EBC - 64]; PO *ppoFocus; };
extern "C" SWG B_003DD490;
extern "C" void *__builtin_new(unsigned int);
extern "C" int GetPoVjoyMode(PO *);
extern "C" void *VJOY_constructor(void *, PO *);
extern "C" void SetVjoyMode(void *, int);
extern "C" void SetSwFocusBase(SWG *, PO *);
extern "C" void SetPoPlayable(PO *ppo, int vjoym)
{
    if (vjoym == GetPoVjoyMode(ppo))
        return;
    if (ppo->pvjoy == 0) {
        unsigned cpo = B_003DD490.cpo;
        if (cpo >= 16)
            return;
        B_003DD490.apo[cpo] = ppo;
        B_003DD490.cpo = cpo + 1;
        ppo->pvjoy = VJOY_constructor(__builtin_new(0xE0), ppo);
    }
    if (vjoym >= -1) {
        if (vjoym > 0) {
            if (vjoym == 1 && ppo != B_003DD490.ppoFocus) {
                PO *ppoFocus = B_003DD490.ppoFocus;
                if (ppoFocus != 0) {
                    VT278 *vtable = (VT278 *)*(void **)((char *)ppoFocus + 0xC);
                    vtable->fn((char *)ppoFocus + vtable->delta, 0);
                }
                SetSwFocusBase(&B_003DD490, ppo);
            }
        } else {
            if (ppo == B_003DD490.ppoFocus)
                SetSwFocusBase(&B_003DD490, 0);
        }
    }
    SetVjoyMode(ppo->pvjoy, vjoym);
}
