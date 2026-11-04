// SPDX-License-Identifier: GPL-3.0-or-later
struct VCS_k02 { char pad[0x70]; short delta; char p[2]; void (*fn)(void *, int); };
struct SRC_k02 { char pad[0x103C]; float f103C; float f1040; float f1044; };
struct MENU_k02 { char pad0[0xC]; VCS_k02 *vt; char pad1[0x10 - 0x10]; SRC_k02 *psrc; char pad2[0x28 - 0x14]; int stickIndex; };
extern "C" float atan2f(float, float);
extern "C" void Menu_UpdateStick(MENU_k02 *pthis)
{
    SRC_k02 *psrc = pthis->psrc;
    if (psrc == 0)
        return;
    int stickIndex = pthis->stickIndex;
    if (stickIndex == -1) {
        if (0.8f < psrc->f1044) {
            float angle = atan2f(psrc->f1040, psrc->f103C);
            float scaled = angle * 1.27323949f + 8.5f;
            int target = (int)scaled;
            int wrapped = (stickIndex < target) ? target : target + 7;
            int remainder = target - ((wrapped >> 3) << 3);
            pthis->vt->fn((char *)pthis + pthis->vt->delta, remainder);
        }
    } else {
        if (psrc->f1044 < 0.5f)
            pthis->vt->fn((char *)pthis + pthis->vt->delta, -1);
    }
}
