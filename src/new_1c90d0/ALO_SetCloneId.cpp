// SPDX-License-Identifier: GPL-3.0-or-later
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct ALO;
struct VTBL { char pad[0xC8]; short offset; short pad2; void (*method)(void *, int, int); };
struct OBJ { char pad[0xC]; VTBL *vtbl; };
struct CHILD { char pad[0x24]; CHILD *next; };
struct ALO { char pad[0x64]; CHILD *first; };
extern "C" void LO_SetCloneId(void *, int, int);
extern "C" void ALO_SetCloneId(ALO *palo, int id, int mode)
{
    VECTOR vector;
    LO_SetCloneId(palo, id, mode);
    for (CHILD *child = palo->first; child; child = child->next) {
        VTBL *vtbl = ((OBJ *)child)->vtbl;
        vtbl->method((char *)child + vtbl->offset, id, 0);
    }
}
