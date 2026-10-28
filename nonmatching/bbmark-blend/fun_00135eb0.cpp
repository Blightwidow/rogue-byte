typedef int QW __attribute__((mode(TI)));
struct ACT { char pad[0x148]; unsigned long flags; };
struct GEOM { char pad0[0x40]; int unk40; char pad44[8]; ACT *act; char pad50[0x10]; QW pos; char pad70[0x18]; float unk88; };
struct SELF { char pad0[0x4C0]; char sub4C0[1]; char pad4C1[0x51F]; char sub9E0[1]; char pad9E1[0x56F]; char subF50[1]; char padF51[0x47F]; int unk13D0; };
extern "C" void AddSafePointOnGeom(void *, int, QW);
extern "C" void func_001942F0(void *);
extern "C" void UpdateJtPipeLook(void *);

void func_00135EB0(SELF *self)
{
    switch (self->unk13D0) {
    case 0: case 1: case 5: case 6: case 7: case 11: case 12: case 14: {
        GEOM *geom = *(GEOM **)((char *)self + 0x208);
        if (geom) {
            float level = geom->unk88;
            float limit;
            asm("li.s %0, 0.7\n\tnop" : "=f" (limit));
            if (limit < level) {
                if (!(geom->act->flags & 0x20000000UL)) {
                    if (*(int *)((char *)self + 0x108C) == 0)
                        AddSafePointOnGeom(self->sub9E0, geom->unk40, geom->pos);
                }
            }
        }
        break;
    }
    case 3:
        func_001942F0(self->sub4C0);
        break;
    case 13:
        UpdateJtPipeLook(self->subF50);
        break;
    }
}
