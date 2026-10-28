struct AMB { char pad0[0x14]; int pan; float pitch; char pad1[0x40 - 0x1C]; int voice; float volEffective; char pad2[0x50 - 0x48]; unsigned short grf; char pad3[0x70 - 0x52]; float slotVol[6]; int slotPan[6]; char pad4[0x3BC - 0xA0]; unsigned mask; };
extern "C" void func_00233088(int, int, int, int, int, int, int);
void ApplyStreamAmbParams(AMB *pamb)
{
    unsigned grf = pamb->grf;
    if (grf & 0x70) {
        int param = 0;
        int vol;
        int pitch;
        if (grf & 0x10) {
            param = 1;
            vol = (int)(pamb->volEffective * 1024.0f);
        }
        if (grf & 0x20) param |= 4;
        if (grf & 0x40) {
            param |= 8;
            pitch = (int)(pamb->pitch * 12.0f);
        }
        func_00233088(0x524B5553, 5, pamb->voice, param, vol, pamb->pan, pitch);
    }
    if (pamb->grf & 0x180) {
        int slot;
        unsigned one;
        for (slot = 0, one = 1; slot < 6; slot++) {
            if (pamb->mask & (one << slot))
                func_00233088(0x524B5553, 6, pamb->voice, slot, (int)(pamb->slotVol[slot] * 1024.0f), pamb->slotPan[slot], 0);
        }
        pamb->mask = 0;
    }
}
