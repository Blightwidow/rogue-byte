struct Sly { char pad[0x2044]; void *emitter; };
extern "C" void SetClockRate(void *, int, float);
extern "C" void StopAmb(void *, float);
extern "C" void VirtualRefPtr_Assign(void *, void *);
extern "C" void func_00141E28(void *);
extern char g_2dded0[];
extern float g_3e1bec;

extern "C" void ReleaseSlyGadget(Sly *sly, int gadget)
{
    if (gadget == 0x1D || gadget == 0x2A) {
        SetClockRate(g_2dded0, 1, 1.0f);
        void **slot = &sly->emitter;
        if (*slot != 0) {
            StopAmb(*slot, 0.0f);
            VirtualRefPtr_Assign(slot, 0);
        }
        g_3e1bec = 0.0f;
    } else {
        func_00141E28(sly);
    }
}
