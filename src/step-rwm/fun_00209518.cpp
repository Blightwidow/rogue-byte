struct Inner_209518 { char pad[0x24]; char *f24; char pad2[0x10]; char *f38; };
struct Ref_209518 { int kind; int pad; Inner_209518 *obj; };
extern "C" {
char *func_00209518(Ref_209518 *ref) {
    switch (ref->kind) {
    case 0: return (char *)ref->obj;
    case 1: return *(char **)((char *)ref->obj + 0x30);
    case 2: return ref->obj->f38;
    case 3: return ref->obj->f24;
    }
    return 0;
}
}
