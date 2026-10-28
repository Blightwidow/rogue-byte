// SPDX-License-Identifier: GPL-3.0-or-later
struct XF;
struct ALO { char pad[0x54]; char *axf; };
extern int B_004437A0;
extern XF *B_004437A8[];
XF *PxfFromRef(unsigned ref, ALO *parent, ALO *alo)
{
    XF *result = 0;
    switch ((int)(ref & 0x3000)) {
    case 0:
        if (alo != 0)
            result = (XF *)(alo->axf + ref * 256);
        break;
    case 0x1000:
        ref &= 0xFFFF0FFF;
        result = (XF *)(parent->axf + ref * 256);
        break;
    case 0x2000:
        result = B_004437A8[B_004437A0 - 1];
        break;
    }
    return result;
}
