typedef int s32; typedef long s64; typedef signed char s8;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
struct Ent { s32 id; s32 p4; s32 p8; s32 flags; s32 p10[5]; s8 *obj; };
extern "C" {
void func_001F69F8(s8 *arg0, s32 arg1) {
    s32 i;
    for (i = 0; i < M2C_FIELD(arg0, s32 *, 0xB8); i++) {
        Ent *e = &M2C_FIELD(arg0, Ent **, 0xC0)[i];
        if (e->id == arg1) {
            s8 *obj = e->obj;
            e->flags |= 0x800;
            if (obj != 0) {
                M2C_FIELD(obj, s64 *, 0x10) |= (0x8000L << 0x23);
            }
        }
    }
}
}
