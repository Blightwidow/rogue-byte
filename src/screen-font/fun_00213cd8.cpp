#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct SUB { char pad[0x14]; int id; };
struct ENT { unsigned short count; unsigned short itemCount; SUB *subs; char pad[0x2C - 8]; QW *transform; };
struct VT { char pad[8]; short delta; short index; void *(*fn)(void *, int, int); };
struct HEAP { VT *vt; };
struct OBJ { char pad[0x80]; unsigned short count; unsigned short pad2; ENT *entries; char pad3[0xC4 - 0x88]; HEAP *heap; };

void func_00213CD8(OBJ *obj, int id, QW *src)
{
    for (int i = 0; i < obj->count; i++) {
        ENT *ent = &obj->entries[i];
        for (int j = 0; j < ent->count; j++) {
            SUB *sub = &ent->subs[j];
            if (sub->id != id)
                continue;
            if (ent->transform == 0) {
                HEAP *heap = obj->heap;
                ent->transform = (QW *)heap->vt->fn((char *)heap + heap->vt->delta, 0x20, 0x1F);
            }
            QW *dst = ent->transform;
            dst[0] = src[0];
            dst[1] = src[1];
            return;
        }
    }
}
