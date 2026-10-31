typedef int s32; typedef long s64;
extern "C" {
struct B_1F2798 { char pad[0xA0]; s32 f_a0; char p1[0x1C]; s32 f_c0; };
struct A_1F2798 { char pad0[0x10]; A_1F2798 *next; char pad1[0xD4]; B_1F2798 *obj; char pad2[0x5C]; s64 flags; };
A_1F2798 *func_001F2798(A_1F2798 *arg0) {
    A_1F2798 *result = 0;
    for (; arg0 != 0; arg0 = result->next) {
        result = arg0;
        B_1F2798 *obj = arg0->obj;
        if (obj != 0 && !(obj->f_c0 == 3 && obj->f_a0 == obj->f_c0))
            break;
        if (result->flags & (s64)0x8000 << 19)
            break;
    }
    return result;
}
}
