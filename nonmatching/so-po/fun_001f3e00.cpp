// SPDX-License-Identifier: GPL-3.0-or-later
struct VTA_k02 { char pad[0xB0]; short delta; void (*fn)(void *); };
struct VTB_k02 { char pad[0x188]; short delta; void (*fn)(void *); };
struct NODE_k02 { char pad0[0xC]; VTA_k02 *vptr; char pad1[0x24 - 0x10]; NODE_k02 *next; };
struct ALO_k02 {
    char pad0[0xC];
    VTB_k02 *vptr;
    char pad1[0x60 - 0x10];
    ALO_k02 *parent60;
    char pad2[0x64 - 0x64 + 0x0];
    NODE_k02 *first64;
    char pad3[0x70 - 0x68];
    NODE_k02 *end70;
    char pad4[0xEC - 0x74];
    void *dl;
};
extern "C" {
void RemoveAloHierarchy(void *);
void RemoveAloFromRenderTree(void *);
void RemoveDlEntry(void *, void *);
extern char B_003E11AC[];
}
extern "C" void func_001F3E00(ALO_k02 *palo)
{
    RemoveAloHierarchy(palo);
    RemoveAloFromRenderTree(palo);
    NODE_k02 *pnode = palo->first64;
    if (pnode != palo->end70) {
        do {
            VTA_k02 *vt = pnode->vptr;
            vt->fn((char *)pnode + vt->delta);
            pnode = pnode->next;
        } while (pnode != palo->end70);
    }
    if (palo->dl != 0) {
        if (((ALO_k02 *)palo->dl)->parent60 == palo) {
            VTB_k02 *vt = palo->vptr;
            vt->fn((char *)palo + vt->delta);
            RemoveDlEntry(B_003E11AC, palo->dl);
        }
    }
}
