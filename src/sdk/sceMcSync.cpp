extern "C" {
int PollSema(int);
int SignalSema(int);
int WaitSema(int);
extern int B_00451E40;
extern int D_002C8350;
extern int D_002C8354;
extern int D_002C8358;
int sceMcSync(int mode, int *command, int *result) {
    if (D_002C8350 == 0) {
        return -1;
    }
    int failed;
    if (PollSema(D_002C8358) < 0) failed = 1; else failed = 0;
    if (mode == 0 && failed != 0) {
        failed = 0;
        WaitSema(D_002C8358);
    }
    int done = failed == 0;
    if (command != 0) {
        *command = D_002C8350;
    }
    if (done != 0) {
        D_002C8350 = 0;
        if (result != 0) {
            *result = B_00451E40;
        }
        SignalSema(D_002C8354);
    }
    return done;
}
}
