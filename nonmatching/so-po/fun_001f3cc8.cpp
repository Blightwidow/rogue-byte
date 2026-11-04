// SPDX-License-Identifier: GPL-3.0-or-later
struct PACKED_k02 { char b[0x30]; } __attribute__((packed));
struct VTC_k02 { char pad[0xA0]; short delta; void (*fn)(void *, int, void *, float, float); };
struct NODE_k02 { char pad0[0xC]; VTC_k02 *vptr; char pad1[0x24 - 0x10]; NODE_k02 *next; };
struct ALO_k02 {
    char pad0[0x64];
    NODE_k02 *first;
    char pad1[0x70 - 0x68];
    NODE_k02 *end;
    char pad2[0x80 - 0x74];
    char globset[0];
};
extern "C" {
void func_001A4478(void *, int, void *);
void RenderGlobset(void *, int, void *, float, float);
extern char B_003DD490[];
}
extern "C" void func_001F3CC8(ALO_k02 *palo, int a1, void *a2, float f12, float f13)
{
    PACKED_k02 local;
    void *pso = a2;
    if (pso == 0) {
        PACKED_k02 *psrc = *(PACKED_k02 **)((char *)palo + 0x134);
        if (psrc != 0) {
            local = *psrc;
            pso = &local;
            func_001A4478(B_003DD490, a1, pso);
        }
    }
    RenderGlobset((char *)palo + 0x80, a1, pso, f12, f13);
    NODE_k02 *pnode = palo->first;
    if (pnode != palo->end) {
        do {
            VTC_k02 *vt = pnode->vptr;
            vt->fn((char *)pnode + vt->delta, a1, pso, f12, f13);
            pnode = pnode->next;
        } while (pnode != palo->end);
    }
}
