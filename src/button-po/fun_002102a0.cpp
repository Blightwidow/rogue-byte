struct VT { char pad[0xC0]; short delta; short idx; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; char pad2[0x10]; OBJ *next; };
struct SW { char pad[0x3038]; };
extern "C" void SetSwFocusOverride(void *, int);
void func_002102A0(SW *psw)
{
    SetSwFocusOverride(psw, 0);
    for (int cid = 0; cid <= 0xC6; cid++) {
        OBJ *obj = *(OBJ **)((char *)psw + 0x3038 + cid * 12);
        while (obj != 0) {
            obj->vt->fn((char *)obj + obj->vt->delta);
            obj = obj->next;
        }
    }
}
