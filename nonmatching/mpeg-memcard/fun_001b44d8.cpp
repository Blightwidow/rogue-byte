struct SO { char pad0[0x20]; SO *next; char pad1[0xE0 - 0x24]; int cgeom; char *ageom; };
struct ALLOCREQ { int size; int align; };
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern SO *B_003E0714;
void func_001B44D8(int *pcgeom, void ***papgeom)
{
    register int total asm("$3") = 0; register SO *pso asm("$4") = B_003E0714; while (pso != 0) { int n = pso->cgeom; pso = pso->next; total += n; }
    ALLOCREQ req;
    req.size = total * 4;
    req.align = 0x10;
    void **apgeom = (void **)PvAllocStackImpl__Fi(&req);
    void **next = apgeom;
    for (SO *pso2 = B_003E0714; pso2 != 0; pso2 = pso2->next) {
        for (int index = 0; index < pso2->cgeom; index++) {
            char *pgeom = pso2->ageom + index * 0xB0;
            if ((*(unsigned long *)(pgeom + 0x10) & (1UL << 48)) == 0)
                *next++ = pgeom;
        }
    }
    *pcgeom = next - apgeom;
    *papgeom = apgeom;
}
