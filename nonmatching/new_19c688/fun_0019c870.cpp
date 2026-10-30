typedef int s32;
struct Owner_19C870 { char p0[0x520]; s32 f520; };
struct Obj_19C870 { Owner_19C870 *owner; char p4[0x18]; s32 f1C; char p20[0xA0]; s32 fC0; s32 fC4; };
extern "C" s32 func_0019C870(Obj_19C870 *self, s32 *out) {
    s32 result;
    s32 kind = self->f1C;
    if (kind < 0xB) {
        result = self->fC0;
    } else if (kind < 0xE) {
        result = self->owner->f520;
    } else if (kind != 0x11) {
        result = self->fC0;
    } else {
        result = self->fC4;
    }
    *out = 0;
    return result;
}
