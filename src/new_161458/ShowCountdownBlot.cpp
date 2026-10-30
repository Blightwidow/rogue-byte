struct Obj_1618F8;
struct Vt_1618F8 { char pad[0x188]; short delta; short pad2; void (*fn)(char *, int); };
struct Obj_1618F8 { char pad[0xC]; Vt_1618F8 *vt; char pad2[0x7C]; int field8C; };
struct Host_1618F8 { char pad[0x3BC4]; Obj_1618F8 *obj; char pad2[0xBA4]; float t; };
extern "C" {
extern float g_2dded0;
void ShowCountdownBlot(Host_1618F8 *self, float delay) {
    Obj_1618F8 *obj = self->obj;
    if (obj != 0) {
        obj->field8C = 0;
        obj->vt->fn((char *)obj + obj->vt->delta, -1);
    }
    self->t = g_2dded0 + delay;
}
}
