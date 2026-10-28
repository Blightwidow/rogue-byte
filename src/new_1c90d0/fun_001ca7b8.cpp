#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct CFrame { int cref; };
struct OPT { int a; int b; CFrame *pframe; int d; int e; int f; };
union U { ALLOCREQ req; CFrame *clone; };
struct POOL { char pad[0xEC]; int count; OPT *options; };
extern "C" void CloneXfm(POOL *, POOL *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void PframeClone(CFrame **, CFrame *, POOL *);
extern "C" void CFrame_DeletingDestructor(CFrame *, int);
extern "C" void func_00259A88(CFrame *);

void func_001CA7B8(POOL *pool, POOL *base)
{
    U u;
    CloneXfm(pool, base);
    for (int index = 0; index < pool->count; index++) {
        OPT *option = &pool->options[index];
        if (option->pframe == 0)
            continue;
        if (pool->options == base->options) {
            u.req.cb = pool->count * 0x18;
            u.req.cbAlign = 0x10;
            pool->options = (OPT *)PvAllocSwCopyImpl__FiPv(&u.req, pool->options);
            option = &pool->options[index];
        }
        PframeClone(&u.clone, option->pframe, pool);
        option->pframe = u.clone;
        CFrame *held = u.clone;
        if (held != 0) {
            int c = held->cref - 1;
            held->cref = c;
            if (c == 0)
                CFrame_DeletingDestructor(held, 3);
        }
        func_00259A88(option->pframe);
    }
}
