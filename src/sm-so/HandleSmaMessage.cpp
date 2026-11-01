#include "sly2.h"
struct BASIC {
    char pad0[0xC];
    virtual void v0(); virtual void v1(); virtual void v2();
};
struct SMA : BASIC {
    char pad1[0x20];
    int key;
};
struct Hold {
    SMA *p;
    Hold(SMA *s) { p = s; s->v0(); }
    ~Hold() { p->v1(); }
};
extern "C" void EndSmaTransition(SMA *);
extern "C" void ChooseSmaTransition(SMA *, int);

extern "C" void HandleSmaMessage(SMA *sma, int msg, int key)
{
    if (msg == 2 && key == sma->key) {
        Hold hold(sma);
        EndSmaTransition(sma);
        ChooseSmaTransition(sma, 0);
    }
}
