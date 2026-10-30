extern "C" {
float GRandInRange(float, float);
extern float g_2dded0;
extern const float RO_002A5598;
struct Owner_179EF8 { char pad[0x2D4]; float limit; float limit2; };
struct Obj_179EF8 { char pad0[0x10]; Owner_179EF8 *owner; char pad1[0x20]; float timer; };
void func_00179EF8(Obj_179EF8 *self) {
    if (self->timer < RO_002A5598) {
    } else {
        float limit = self->owner->limit;
        if (limit == RO_002A5598) {
            self->timer = RO_002A5598;
        } else {
            float base = g_2dded0;
            self->timer = base + GRandInRange(limit, self->owner->limit2);
        }
    }
}
}
