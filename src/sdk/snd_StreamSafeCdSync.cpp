extern "C" {
void func_00235078(int *, char *);
int sceCdSync(int);
void snd_FlushSoundCommands(void);
extern int B_00448400[16];
extern int D_002C464C;
extern int D_002C4658;
int snd_StreamSafeCdSync(int arg0) {
    int done;
    if (D_002C464C == 0) {
        return sceCdSync(arg0);
    }
    char *last = (char *)B_00448400 + 0x3F;
    func_00235078((int *)(last - 0x3F), last);
    done = *(int *)(last - 0x3F) == 0;
    D_002C4658 = done;
    if (done != 1) {
        if (arg0 == 1) {
            return 1;
        }
        if (done == 0) {
            do {
                snd_FlushSoundCommands();
                func_00235078(B_00448400, last);
                done = B_00448400[0] == 0;
                D_002C4658 = done;
            } while (done == 0);
        }
    }
    return 0;
}
}
