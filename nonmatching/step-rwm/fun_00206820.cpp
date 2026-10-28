#include "sly2.h"
struct VT {
    char pad0[0x18]; short d18; short i18; int (*f18)(void *, int, int, int, void *, int);
    char pad1[0xD0 - 0x20]; short dD0; short iD0; void (*fD4)(void *, int);
    short dD8; short iD8; void (*fDC)(void *, int);
};
struct OBJ { char pad[0xC]; VT *vptr; };
void func_00206820(OBJ *object)
{
    struct L { int zero; int *self; } l;
    l.self = &l.zero;
    VT *v = object->vptr;
    l.zero = 0;
    void (*fa)(void *, int) = v->fDC;
    fa((char *)object + v->dD8, 0);
    v = object->vptr;
    int (*fb)(void *, int, int, int, void *, int) = v->f18;
    fb((char *)object + v->d18, 0xF, 0, 1, &l.self, 0);
    v = object->vptr;
    void (*fc)(void *, int) = v->fD4;
    fc((char *)object + v->dD0, 0);
    v = object->vptr;
    int (*fd)(void *, int, int, int, void *, int) = v->f18;
    fd((char *)object + v->d18, 0xE, 0, 1, &l.self, 0);
}
