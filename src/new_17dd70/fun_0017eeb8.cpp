struct Crv_17EEB8 { char pad[0xE4]; int locked; };
struct Obj_17EEB8 { char pad[0x30]; Crv_17EEB8 *crv; int useMax; float target; };
extern "C" {
float SMaxCrv(Crv_17EEB8 *);
float SMinCrv(Crv_17EEB8 *);
extern const float RO_002BE7B8;
int func_0017EEB8(Obj_17EEB8 *self) {
    Crv_17EEB8 *crv = self->crv;
    if (crv->locked == 0) {
        float value;
        if (self->useMax != 0) {
            value = SMaxCrv(crv);
        } else {
            value = SMinCrv(crv);
        }
        if (RO_002BE7B8 < __builtin_fabsf(self->target - value)) {
            return 0;
        }
        return 1;
    }
    return 0;
}
}
