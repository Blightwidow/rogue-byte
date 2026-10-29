extern "C" {
typedef int s32;
typedef int s128 __attribute__((mode(TI)));
s128 PosLoWorld(s32);
s32 func_00227C90(s32, s128);

s32 func_00155A68(char *arg0) {
    s32 *obj;
    obj = *(s32 **)(arg0 + 0x38);
    if (func_00227C90(obj[3], PosLoWorld(*(s32 *)(arg0 + 0x4C))) != 0
        || (obj = *(s32 **)(arg0 + 0x38), func_00227C90(obj[7], PosLoWorld(*(s32 *)(arg0 + 0x4C))) == 0)) {
        return (*(s32 **)(arg0 + 0x38))[1];
    }
    return (*(s32 **)(arg0 + 0x38))[5];
}
}
