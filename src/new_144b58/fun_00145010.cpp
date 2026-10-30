struct Obj_145010 { char p0[0x60]; int i60; char p1[4]; float f68, f6C, f70, f74, f78; };
extern "C" {
void func_001EEF68();
void func_00145010(Obj_145010 *obj) {
    func_001EEF68();
    obj->i60 = -1;
    obj->f68 = 0.25f;
    obj->f6C = 250.0f;
    obj->f70 = 350.0f;
    obj->f74 = 1.0f;
    obj->f78 = 1.2f;
}
}
