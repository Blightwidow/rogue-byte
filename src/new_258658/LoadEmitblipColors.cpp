#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct Blip { char pad[0xC]; int colorRanges; char pad2[0xC]; int *table; };
struct Emitb { char pad[0xC0]; Blip blip; };
struct B4 { char b[4]; };
struct Emitter { char pad[0xE4]; Emitb *emitb; };
extern "C" {
unsigned U16Read__18CBinaryInputStream(Bis *);
unsigned U8Read__18CBinaryInputStream(Bis *);
unsigned U32Read__18CBinaryInputStream(Bis *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void FilterColorRgba8_1ed278(void *);
void LoadEmitblipColors(Emitter *emitter, Bis *bis)
{
    int count = U16Read__18CBinaryInputStream(bis);
    if (count) {
        Blip *emitb = &emitter->emitb->blip;
        union { ALLOCREQ req; unsigned rgba; B4 raw; } u;
        u.req.cb = count * 4 + 4;
        u.req.cbAlign = 0x10;
        int *table = (int *)PvAllocSwImpl__Fi(&u.req);
        emitb->table = table;
        emitb->colorRanges = U8Read__18CBinaryInputStream(bis);
        int limit = 0x20;
        if (count <= 0x1f) limit = count;
        *table = limit;
        for (int index = 0; index < count; index++) {
            u.rgba = U32Read__18CBinaryInputStream(bis);
            FilterColorRgba8_1ed278(&u.rgba);
            if (index < *table) ((B4 *)(table + 1))[index] = u.raw;
        }
    }
}
}
