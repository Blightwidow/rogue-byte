struct UL { unsigned long v; } __attribute__((packed));
extern "C" {
void QueueSwCallbackOnce(char *, char *, unsigned long, int);
void func_001A6178();
extern char B_003DD490[];
extern const UL RO_002A77C0;
void ClonePool_AddLoGrfEntry(char *arg0) {
    func_001A6178();
    if (*(int *)(arg0 + 0xE4) == 0) {
        QueueSwCallbackOnce(B_003DD490, arg0, RO_002A77C0.v, 0);
    }
}
}
