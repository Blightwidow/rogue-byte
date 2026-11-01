// SPDX-License-Identifier: GPL-3.0-or-later
struct Vt206820 {
    char pad0[0x18];
    short d18;
    short i18;
    int (*f18)(void *, int, int, int, void *, int);
    char pad1[0xD0 - 0x20];
    short dD0;
    short iD0;
    void (*fD4)(void *, int);
    short dD8;
    short iD8;
    void (*fDC)(void *, int);
};
struct Obj206820 {
    char pad[0xC];
    Vt206820 *vptr;
};
struct Locals206820 {
    int zero;
    int *self;
};
extern "C" void func_00206820(Obj206820 *object)
{
    Locals206820 l;
    l.self = &l.zero;
    Vt206820 *vt = object->vptr;
    void (*stopA)(void *, int) = vt->fDC;
    l.zero = 0;
    stopA((char *)object + vt->dD8, 0);
    vt = object->vptr;
    int (*callA)(void *, int, int, int, void *, int) = vt->f18;
    callA((char *)object + vt->d18, 0xF, 0, 1, &l.self, 0);
    vt = object->vptr;
    void (*stopB)(void *, int) = vt->fD4;
    stopB((char *)object + vt->dD0, 0);
    vt = object->vptr;
    int (*callB)(void *, int, int, int, void *, int) = vt->f18;
    callB((char *)object + vt->d18, 0xE, 0, 1, &l.self, 0);
}
