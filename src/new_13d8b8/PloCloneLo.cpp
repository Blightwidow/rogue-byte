struct VT { char pad0[0x30]; short d30; short i30; void *(*f34)(void *); char pad1[0x140-0x38]; short d140; short i140; void (*f144)(void *, void *); };
struct Obj { char p[0xC]; VT *vt; char q[8]; int f18; };
struct Plo { char p[0xC]; VT *vt; };
struct Ty { int a; int b; };
extern "C" Plo *PloNew(int, int, int, int);
Plo *PloCloneLo(Obj *obj, int arg1) {
    Plo *result;
    if (obj != 0) {
        Ty *type = (Ty *)obj->vt->f34((char *)obj + obj->vt->d30);
        Plo *clone = PloNew(type->b, arg1, obj->f18, -1);
        clone->vt->f144((char *)clone + clone->vt->d140, obj);
        result = clone;
    } else {
        result = 0;
    }
    return result;
}
