struct Obj1C5DF0;
struct VT1C5DF0 { char pad[0x260]; short delta; short index; void (*fn)(void *, int); };
struct Obj1C5DF0 { char pad[0xC]; VT1C5DF0 *vt; char pad2[0x1C8 - 0x10]; int f1c8; };
struct Other1C5DF0 { char pad[0x44]; unsigned flags; };
extern "C" int FAbsorbDprizeWkr(Obj1C5DF0 *obj, Other1C5DF0 *other)
{
    if (obj->f1c8 != 0) {
        if (other->flags & 8) {
            VT1C5DF0 *vt = obj->vt;
            vt->fn((char *)obj + vt->delta, 1);
            return 1;
        }
        return 0;
    }
    return 0;
}
