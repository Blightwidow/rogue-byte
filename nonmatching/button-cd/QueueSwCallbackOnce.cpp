#include "sly2.h"
struct Packed { short a; short s1; short s2; short s3; };
struct SwCallback { int fn; short pad4; short key1; short key2; short pad10; int arg; SwCallback *next; };
struct SwHolder { char pad[0x3CA8]; SwCallback *head; };
extern "C" {
void QueueSwCallback(SwHolder *holder, int fn, long bits, int arg);
}
extern "C" void QueueSwCallbackOnce(SwHolder *holder, int fn, long bits, int arg)
{
    SwCallback *cb = holder->head;
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
    QueueSwCallback(holder, fn, bits, arg);
}
