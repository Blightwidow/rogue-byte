struct VT_1371C8 { char pad[0x2C0]; short delta; short index; void (*fn)(void *, int); };
struct OBJ_1371C8 { char pad0[0xC]; VT_1371C8 *vt; char pad1[0x1030 - 0x10]; int asega; };
struct HOLDER_1371C8 { OBJ_1371C8 *obj; };
extern "C" int FAsegaGone(int);
extern "C" void bevy_player_p25_1371c8(HOLDER_1371C8 *holder)
{
    if (FAsegaGone(holder->obj->asega) != 0) {
        OBJ_1371C8 *obj = holder->obj;
        obj->vt->fn((char *)obj + obj->vt->delta, 0);
    }
}
