typedef int s32; typedef short s16; typedef unsigned short u16;
struct VEnt { char pad0[8]; s16 adj; s16 pad; void (*fn)(void *); };
struct Obj { char pad[0xC]; VEnt *vt; char pad2[0x30]; s32 voice; char pad3[0xC]; u16 flags; };
extern "C" {
void SetAmbGrf(void *, s32, s32);
void snd_SoundIsStillPlaying_CB(s32, void *, void *);
extern char OnAmbVoicePolled;
void PollAmb(Obj *arg0) {
    if (arg0->flags & 0x400) {
        VEnt *vt = arg0->vt;
        void (*fn)(void *) = vt->fn;
        fn((char *)arg0 + vt->adj);
        snd_SoundIsStillPlaying_CB(arg0->voice, &OnAmbVoicePolled, arg0);
        SetAmbGrf(arg0, 0x400, 0);
    }
}
}
