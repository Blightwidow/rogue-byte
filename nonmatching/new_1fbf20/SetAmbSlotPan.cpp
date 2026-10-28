struct Amb { char pad[0x88]; int pan[6]; char pad2[0x3BC - 0xA0]; unsigned flags; };
extern "C" void SetAmbGrf(Amb *, int, int, int);
extern "C" void SetAmbSlotPan(Amb *amb, unsigned slot, int degrees)
{
    if (slot < 6) {
        int pan = degrees % 360;
        if (pan < 0) pan += 360;
        if (amb->pan[slot] != pan) {
            amb->pan[slot] = pan;
            amb->flags |= 1 << slot;
            SetAmbGrf(amb, 0x100, 0x100, pan);
        }
    }
}
