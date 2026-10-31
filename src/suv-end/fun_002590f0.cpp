typedef int s32; typedef signed char s8;
struct Params { s32 size; s32 align; };
extern "C" {
s32 *PvAllocSwCopyImpl__FiPv(Params *, s32 *);
s32 *func_002590F0(s8 *arg0, s32 arg1) {
    if (arg1 == 1) {
        *(s32 *)(arg0 + 0xE0) = arg1;
        s32 *counter = *(s32 **)(arg0 + 0xE4);
        s32 value = *counter;
        if (value >= 2) {
            *counter = value - 1;
            Params params;
            params.size = 0x100;
            params.align = 0x10;
            s32 *fresh = PvAllocSwCopyImpl__FiPv(&params, *(s32 **)(arg0 + 0xE4));
            *(s32 **)(arg0 + 0xE4) = fresh;
            *fresh = arg1;
        }
    }
    return *(s32 **)(arg0 + 0xE4);
}
}
