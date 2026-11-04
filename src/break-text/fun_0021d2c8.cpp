typedef float f32;

struct Object {
    char pad0[0x38];
    f32 limit;
    char pad3C[0xEC - 0x3C];
    f32 base;
};

extern "C" {
void PostLoLoad();
extern f32 RO_002C40C0;

void func_0021D2C8(Object *object) {
    PostLoLoad();
    if (object->limit == 1e10f) {
        object->limit = object->base + RO_002C40C0;
    }
}
}
