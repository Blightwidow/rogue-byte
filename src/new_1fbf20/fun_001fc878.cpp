struct AMBVT { char pad[8]; short delta; short index; void (*addref)(void *); };
struct AMB { char pad0[0xC]; AMBVT *vptr; char pad1[0x40 - 0x10]; int voice; char pad2[0x4E - 0x44]; short pause; unsigned short grf; unsigned short start; char pad3[0x68 - 0x54]; unsigned long played; };
struct SND { char pad[0x1F0]; unsigned long now; unsigned long prev; };
extern SND B_003DD040;
extern "C" {
void func_002330D0(int, int, int, int, int, int, int, void *, long);
void func_001FCC30();
void OnAmbVoicePolled();
}
void SetAmbGrf(AMB *, int, int);
void func_001FC878(AMB *pamb)
{
    if (pamb->grf & 0x1000) {
        pamb->vptr->addref((char *)pamb + pamb->vptr->delta);
        func_002330D0(0x524B5553, 7, pamb->voice, 0, 0, 0, 0, (void *)func_001FCC30, (long)pamb);
        SetAmbGrf(pamb, 0x1000, 0);
    }
    if (pamb->start == 0) {
        if (pamb->grf & 0x400) {
            pamb->vptr->addref((char *)pamb + pamb->vptr->delta);
            func_002330D0(0x524B5553, 8, pamb->voice, 0, 0, 0, 0, (void *)OnAmbVoicePolled, (long)pamb);
            SetAmbGrf(pamb, 0x400, 0);
        }
        if ((pamb->grf & 0x800) && pamb->pause < 1)
            pamb->played += B_003DD040.now - B_003DD040.prev;
    }
}
