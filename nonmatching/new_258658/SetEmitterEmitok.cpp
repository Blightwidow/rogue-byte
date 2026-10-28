// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SZ { int size; int align; };
struct PEMITB { char pad[0x10]; int emitok; char pad2[0x1C]; int p30; };
struct INNER { char pad[0x10]; int value; };
struct OBJ { char pad[0xE4]; INNER *inner; };
extern "C" void *PvAllocSwClearImpl__Fi(SZ *);
extern "C" PEMITB *PemitbEnsureEmitter(OBJ *, int);
static inline int Alloc(int size)
{
    SZ request;
    request.size = size;
    request.align = 0x10;
    return (int)PvAllocSwClearImpl__Fi(&request);
}
extern "C" void SetEmitterEmitok(OBJ *obj, int value)
{
    int current = obj->inner->value;
    if (current != value) {
        if (current == 0) {
            PEMITB *emitter = PemitbEnsureEmitter(obj, 1);
            emitter->emitok = value;
            int block;
            SZ request;
            switch (value) {
            case 1:
                request.size = 0x20;
                goto allocate;
            case 2:
                block = -1;
                goto store;
            case 3:
                request.size = 0x30;
            allocate:
                request.align = 0x10;
                block = (int)PvAllocSwClearImpl__Fi(&request);
            store:
                emitter->p30 = block;
            }
        }
    }
}
