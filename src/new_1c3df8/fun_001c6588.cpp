struct VT_1C6588 { char pad[0x260]; short delta; short unused; void (*fn)(void *, int); };
struct OBJ_1C6588 { char pad0[0xC]; VT_1C6588 *vt; char pad1[0x150 - 0x10]; int state; char pad2[0x238 - 0x154]; float timer; };
extern "C" {
void UpdateDprize();
extern float g_2dded4;
void func_001C6588(OBJ_1C6588 *obj)
{
    UpdateDprize();
    if (obj->state == 0) {
        obj->timer = obj->timer - g_2dded4;
        if (obj->timer <= 0.0f)
            obj->vt->fn((char *)obj + obj->vt->delta, 5);
    }
}
}
