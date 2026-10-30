extern "C" {
float GRandInRange(float, float);
extern float g_2dded0;
extern const float RO_002A5594;
struct Owner_179E80 { char pad[0x2CC]; float limit; float limit2; };
struct Obj_179E80 { char pad0[0x10]; Owner_179E80 *owner; char pad1[0x1C]; float timer; };
void func_00179E80(Obj_179E80 *self) {
    if (self->timer < RO_002A5594) {
    } else {
        float limit = self->owner->limit;
        if (limit == RO_002A5594) {
            self->timer = RO_002A5594;
        } else {
            float base = g_2dded0;
            self->timer = base + GRandInRange(limit, self->owner->limit2);
        }
    }
}
}
