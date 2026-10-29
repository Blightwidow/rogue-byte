struct UL { unsigned long v; } __attribute__((packed));
extern "C" {
void PostLoLoad();
void QueueSwCallback(char *, char *, unsigned long, int);
extern char B_003DD490[];
extern const UL RO_002A46C8;
void PostAsegLoad(char *arg0) {
    PostLoLoad();
    int count = *(int *)(arg0 + 0xB0);
    if (count != 0) {
        QueueSwCallback(B_003DD490, arg0, RO_002A46C8.v, count);
    }
}
}
