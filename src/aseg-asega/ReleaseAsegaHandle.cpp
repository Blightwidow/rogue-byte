typedef short s16;
struct Obj_1306A8;
struct VT_1306A8 { char pad[0x10]; s16 delta; s16 p; void (*fn)(char *); };
struct Obj_1306A8 { int pad[3]; VT_1306A8 *vt; };
extern "C" void ReleaseAsegaHandle(Obj_1306A8 **handle)
{
    Obj_1306A8 *obj = *handle;
    if (obj != 0) {
        obj->vt->fn((char *)obj + obj->vt->delta);
        *handle = 0;
    }
}
