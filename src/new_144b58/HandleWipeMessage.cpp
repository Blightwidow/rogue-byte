struct WIPE { char pad0[0x160]; int unk160; int unk164; int unk168; int unk16C; int unk170; };
struct MSGARGS { int unk0; int unk4; int msg; };
extern "C" void HandleLoMessage(WIPE *, int, MSGARGS *);
extern "C" void SetWipeState(WIPE *, int);

void HandleWipeMessage(WIPE *wipe, int msgid, MSGARGS *args)
{
    HandleLoMessage(wipe, msgid, args);
    if (msgid != 9) return;
    if (args->unk0 != wipe->unk160) return;
    switch (args->msg) {
    case 0x5FB: wipe->unk164 = 1; break;
    case 0x5FC: wipe->unk164 = 0; break;
    case 0x5FD: wipe->unk168 = 1; break;
    case 0x5FE: wipe->unk168 = 0; break;
    case 0x5FF: wipe->unk16C = 0; break;
    case 0x600: wipe->unk16C = 1; break;
    case 0x601:
        if (wipe->unk170 != -1) SetWipeState(wipe, 3);
        break;
    }
}
