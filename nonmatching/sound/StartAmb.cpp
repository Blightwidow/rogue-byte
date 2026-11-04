struct VT { char pad[8]; short d8; short i8; void (*f8)(char *); };
struct AMB {
    char pad0[0xC]; VT *vt;
    char pad1[0x14 - 0x10]; int pan; float uPitch;
    char pad2[0x44 - 0x1C]; float uVol;
    char pad3[0x50 - 0x48]; unsigned short grf; short fPending;
    char pad4[0x60 - 0x54]; int sfxid;
};
struct SNDPLAY {
    int hBank; int unused4; int vol; int pan; short isndrec; short pad12[7]; short pitch; short pad22[3]; unsigned grf; int pad2c;
};
extern "C" {
void *func_001FD028(void *, int);
short func_001FD070(void *, void *);
void DeactivateAmb(AMB *);
void *memset(void *, int, unsigned);
void func_00232320(SNDPLAY *, void (*)(int, AMB *), AMB *);
void func_002322F0(SNDPLAY *);
void SetAmbGrf(AMB *, int, int);
void *PpoSwFocusBase(void *);
void func_001FEED0(void *);
void OnAmbVoiceStarted(int, AMB *);
extern char B_003DD040[];
extern char B_003DD490[];
extern void *g_2f7900;
extern void *g_2dd5bc;
extern void *g_2e1e40;
}

void StartAmb(AMB *amb)
{
    int *rec = (int *)func_001FD028(B_003DD040, amb->sfxid);
    if (rec == 0 || *(int *)(B_003DD040 + 0xE8) == 0) {
        SetAmbGrf(amb, 0x1FFF, 0);
        return;
    }
    if (amb->grf & 2) {
        DeactivateAmb(amb);
        return;
    }
    SNDPLAY play;
    memset(&play, 0, 0x30);
    play.grf = 3;
    play.hBank = *(int *)(B_003DD040 + 0xE8);
    play.isndrec = func_001FD070(B_003DD040, rec);
    if (amb->grf & 0x10) {
        play.grf |= 4;
        play.vol = (int)(amb->uVol * 1024.0f);
    }
    if (amb->grf & 0x20) {
        play.grf |= 8;
        play.pan = amb->pan;
    }
    if (amb->grf & 0x40) {
        play.grf |= 0x10;
        play.pitch = (short)(int)(amb->uPitch * 1524.0f);
    }
    if (*rec == 2) {
        amb->fPending = 1;
        amb->vt->f8((char *)amb + amb->vt->d8);
        func_00232320(&play, OnAmbVoiceStarted, amb);
        SetAmbGrf(amb, 0x7F, 0);
    } else {
        func_002322F0(&play);
        SetAmbGrf(amb, 0x1FFF, 0);
        void *speaker = 0;
        switch (amb->sfxid) {
        case 0x6F: speaker = g_2e1e40; break;
        case 0x73: speaker = g_2dd5bc; break;
        case 0x15: speaker = g_2f7900; break;
        }
        if (speaker == PpoSwFocusBase(B_003DD490))
            func_001FEED0(B_003DD040);
    }
}
