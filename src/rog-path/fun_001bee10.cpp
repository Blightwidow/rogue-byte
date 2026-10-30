typedef int s32;
struct Elem_1BEE10 { char bytes[40]; };
extern "C" {
extern Elem_1BEE10 B_003E1A78[];
extern int *D_002C0BF8[];
s32 func_001BEE10(char *arg0, s32 arg1) {
    Elem_1BEE10 *elem = *(Elem_1BEE10 **)(arg0 + 0x128);
    if (elem == 0) return -1;
    return D_002C0BF8[elem - B_003E1A78][arg1];
}
}
