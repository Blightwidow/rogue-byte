struct VT_1421F8 { char pad[0x2C0]; short d2C0; short i2C0; void (*f2C4)(void *, int); };
struct Obj_1421F8 { char p0[0xC]; VT_1421F8 *vt; char p1[0x4B0]; char attach[8]; int state4C8; };
extern "C" {
void StartAttach(void *, int, int, int);
void func_001CD308(void *, int);
void func_001421F8(Obj_1421F8 *obj, int arg1) {
    if (arg1 != 0) {
        StartAttach((char *)obj + 0x4C0, 5, arg1, 0);
        func_001CD308((char *)obj + 0x900, arg1);
    } else if (obj->state4C8 == 5) {
        obj->vt->f2C4((char *)obj + obj->vt->d2C0, 0);
    }
}
}
