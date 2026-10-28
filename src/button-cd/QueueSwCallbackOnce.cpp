struct Packed { short a; short s1; short s2; short s3; };
struct Cb { int fn; short pad; short key1; short key2; short pad2; int arg; Cb *next; };
struct Holder { char pad[0x3CA8]; Cb *head; };
extern "C" void QueueSwCallback(Holder *, int, long, int);
extern "C" void QueueSwCallbackOnce(Holder *holder, int fn, long bits, int arg)
{
    Cb *cb = holder->head;
    if (cb) {
        Packed *packed = (Packed *)&bits;
        int s1 = packed->s1;
        int s2 = packed->s2;
        int w4 = *(int *)&packed->s2;
        do {
            if (cb->fn == fn && cb->key1 == s1) {
                if (cb->key1 == -1 || cb->key2 != s2 ? *(int *)&cb->key2 == w4 : 1) {
                    if (cb->arg == arg)
                        return;
                }
            }
            cb = cb->next;
        } while (cb);
    }
    QueueSwCallback(holder, fn, *(volatile long *)&bits, arg);
}
