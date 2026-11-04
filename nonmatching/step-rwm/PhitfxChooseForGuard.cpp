// SPDX-License-Identifier: GPL-3.0-or-later
struct NODE_k02 {
    char pad0[0x44];
    int f44;
    char pad1[0xC];
    int t54;
    NODE_k02 *next58;
};
struct VTD_k02 { char pad[0x2C8]; short delta; char p[2]; int (*fn)(void *, void *); };
struct PH_k02 {
    char pad0[0xC];
    VTD_k02 *vptr;
    char pad1[0xF04 - 0x10];
    float f0F04;
    char pad2[0xF64 - 0xF08];
    int f0F64;
};
extern "C" {
int func_00208D70(void *, void *);
int NCompareHitfxForGuard(void *, void *, void *);
void *PentryFindSensorLo(int, int);
void SetSensorEntryState(int, void *, int);
extern NODE_k02 *B_003E148C;
extern float g_2dded0;
extern float D_FLT_002C3DB0;
}
extern "C" void *PhitfxChooseForGuard(PH_k02 *pthis, void *arg1)
{
    if (func_00208D70(pthis, arg1) == 0)
        return arg1;
    void *pbest = arg1;
    NODE_k02 *pnode = B_003E148C;
    while (pnode != 0) {
        if (pthis->vptr->fn((char *)pthis + pthis->vptr->delta, pnode) != 0) {
            if (pbest == 0 || NCompareHitfxForGuard(pthis, pnode, pbest) < 0)
                pbest = pnode;
        }
        pnode = pnode->next58;
    }
    if (pbest == 0)
        return 0;
    if (((NODE_k02 *)pbest)->t54 != 4)
        return pbest;
    void *psensor = PentryFindSensorLo(pthis->f0F64, ((NODE_k02 *)pbest)->f44);
    if (psensor == 0)
        return pbest;
    if (((int *)psensor)[1] != 0)
        return arg1;
    SetSensorEntryState(pthis->f0F64, psensor, 2);
    pthis->f0F04 = g_2dded0 + D_FLT_002C3DB0;
    return arg1;
}
