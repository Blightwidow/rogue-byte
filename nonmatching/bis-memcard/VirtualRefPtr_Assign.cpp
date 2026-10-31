typedef int s32; typedef short s16;
extern "C" {
struct Obj_258040;
struct VT_258040 {
    char pad0[8]; s16 d8; s16 pa; void (*fnC)(char *);
    s16 d10; s16 p12; void (*fn14)(char *, Obj_258040 *);
};
struct Obj_258040 { char pad[0xC]; VT_258040 *vt; };
void VirtualRefPtr_Assign(Obj_258040 **arg0, Obj_258040 *arg1) {
    if (arg1 != 0)
        arg1->vt->fnC((char *)arg1 + arg1->vt->d8);
    Obj_258040 *old = *arg0;
    if (old != 0)
        old->vt->fn14((char *)old + old->vt->d10, old);
    *arg0 = arg1;
}
}
