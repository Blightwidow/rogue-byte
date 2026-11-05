extern "C" {
void snd_FlushSoundCommands(void);
extern int *D_002C4660[];
extern int D_002C4680;
void snd_PostMessage__Fv(void) {
    int *counter = D_002C4660[D_002C4680];
    *counter += 1;
    snd_FlushSoundCommands();
}
}
