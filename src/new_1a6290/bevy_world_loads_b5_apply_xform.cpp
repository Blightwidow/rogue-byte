struct LO;
struct VT {
    char pad0[0xE0]; short deltaList; short idxList; int (*pfnList)(LO *, LO ***);
    char pad1[0x128 - 0xE8]; short deltaApply; short idxApply; void (*pfnApply)(LO *, const void *);
};
struct LO { char pad[0xC]; VT *pvt; };
void bevy_world_loads_b5_apply_xform(LO *plo, const void *pmat)
{
    LO **aplo;
    int count = plo->pvt->pfnList((LO *)((char *)plo + plo->pvt->deltaList), &aplo);
    for (int i = 0; i < count; i++) {
        LO *plof = aplo[i];
        plof->pvt->pfnApply((LO *)((char *)plof + plof->pvt->deltaApply), pmat);
    }
}
