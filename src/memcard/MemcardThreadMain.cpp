extern "C" {
extern void ExitDeleteThread();
extern int SignalSema(int);
extern int WaitSema(int);
extern void *memset(void *, int, unsigned);
extern char B_002E65E0[];
extern int B_004425D8;

void MemcardThreadMain(char *arg0) {
    WaitSema(*(int *)arg0);
    *(int *)(arg0 + 0x10) = (*(int (**)(void *))(arg0 + 0xC))(*(short *)(arg0 + 8) + B_002E65E0);
    memset(arg0 + 8, 0, 8);
    *(int *)(arg0 + 4) = -1;
    B_004425D8 = -1;
    SignalSema(*(int *)arg0);
    ExitDeleteThread();
}

}
