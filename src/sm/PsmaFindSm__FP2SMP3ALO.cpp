struct ALO;
struct LINK { char pad[0x14]; LINK *next; };
struct SM { char pad[0x68]; struct STEP *first; };
struct STEP { char pad[0x14]; STEP *next; char pad2[0x10]; ALO *palo; };
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
STEP *PsmaFindSm__FP2SMP3ALO(SM *psm, ALO *palo)
{
    VECTOR vector;
    for (STEP *step = psm->first; step; step = step->next)
        if (step->palo == palo) return step;
    return 0;
}
