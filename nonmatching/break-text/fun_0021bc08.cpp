typedef int QW __attribute__((mode(TI)));
struct Mat { QW row[4]; };
struct Obj;
struct VT { char pad[0xF8]; short delta; short index; Mat *(*fn)(void *); };
struct Rec { float t; float alpha; char pad[8]; Mat mat; };
struct Obj {
    char pad[0xC]; VT *vtable;
    char pad10[0x158 - 0x10];
    int count; Rec *records; int next; int idle;
};
extern float g_2dded0;
static inline float ItoF(int v) { float r; asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (r) : "r" (v)); return r; }

extern "C" void func_0021BC08(Obj *obj)
{
    float t = g_2dded0;
    VT *vt = obj->vtable;
    Mat world = *vt->fn((char *)obj + vt->delta);
    int count = obj->count;
    t = t - ItoF(count) * 0.016666668f;
    for (int i = count - 1; i >= 0; i--) {
        Rec *rec = (Rec *)((char *)obj->records + obj->next * 0x50);
        obj->next = (obj->next + 1) % obj->count;
        rec->t = t;
        rec->alpha = 0.0f;
        t = t + 0.016666668f;
        rec->mat = world;
    }
    obj->idle = 0;
}
