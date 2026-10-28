struct AMB { char pad[0x18]; float pitch; };
extern "C" void SetAmbGrf(AMB *, unsigned short, unsigned short);
extern "C" void SetAmbPitch(AMB *pamb, float pitch)
{
    if (pitch != pamb->pitch) {
        pamb->pitch = pitch;
        SetAmbGrf(pamb, 0x40, 0x40);
    }
}
