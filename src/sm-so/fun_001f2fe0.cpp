#include "sly2.h"
struct BASIC {
    char pad0[0xC];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void v46(unsigned);
};
struct NODE : BASIC { char pad1[0x14]; NODE *next; };
struct S : BASIC {
    char pad1[0x30]; unsigned flags; char pad2[0x20]; NODE *first; char pad3[0x08]; NODE *last;
};

void func_001F2FE0(S *s, unsigned mask)
{
    struct G { int a; ~G() {} };
    G g;
    unsigned f = s->flags;
    if ((f ^ 1) & 1)
        *(unsigned *)f |= mask;
    else
        s->flags = f | mask;
    for (NODE *node = s->first; node != s->last; node = node->next)
        node->v46(mask);
}
