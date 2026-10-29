struct UL { unsigned long v; } __attribute__((packed));
extern "C" {
float PostLoLoad();
void QueueSwCallback(char *, int, unsigned long, int);
extern char B_003DD490[];
extern const UL RO_002A5010;
void PostRhythmLoad(int arg0) {
    PostLoLoad();
    QueueSwCallback(B_003DD490, arg0, RO_002A5010.v, 0);
}
}
