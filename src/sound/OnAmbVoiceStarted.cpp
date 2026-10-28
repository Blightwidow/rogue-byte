struct AMB;
struct AMBV { short delta; short index; void (*fn)(AMB *); };
struct AMB { char pad[0x0C]; AMBV *vt; char pad2[0x30]; int voice; char pad3[0x0E]; short cVoice; };
extern "C" void OnAmbVoiceStarted(int voice, long arg)
{
    AMB *pamb = (AMB *)arg;
    pamb->voice = voice;
    pamb->cVoice = 0;
    AMBV *slot = (AMBV *)((char *)pamb->vt + 0x10);
    slot->fn((AMB *)((char *)pamb + slot->delta));
}
