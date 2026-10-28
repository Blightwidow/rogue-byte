struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad0[0xC]; VT *vt; };
struct ITEM { OBJ *obj; int extra; };
struct LIST { int count; ITEM item[1]; };
extern "C" char B_003DD490;
extern "C" OBJ *PloFindSwObject_thunk(void *, int, int, void *);
void PostAshLoad(LIST *list, void *owner)
{
    for (int index = 0; index < list->count; index++) {
        OBJ **slot = &list->item[index].obj;
        OBJ *obj = PloFindSwObject_thunk(&B_003DD490, 4, *(int *)slot, owner);
        if (obj != 0) {
            *slot = obj;
            obj->vt->fn((char *)obj + obj->vt->delta);
        } else {
            *slot = 0;
        }
    }
}
