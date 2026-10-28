#include "sly2.h"
struct BASIC {
    char pad0[0xC];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(int, int);
};
struct SMA : BASIC {
    char pad1[0x18];
    BASIC *pobj;
};
struct Hold {
    SMA *p;
    Hold(SMA *s) { p = s; s->v0(); }
    ~Hold() { p->v1(); }
};
extern "C" void PostLoMessage(SMA *, int, int);

void SendSmaMessage(SMA *sma, int msg, int arg)
{
    Hold hold(sma);
    if (sma->pobj)
        sma->pobj->v4(msg, arg);
    PostLoMessage(sma, msg, arg);
}
