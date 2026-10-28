struct DANCER { char pad[0x2C4]; int cmove; };
extern "C" void *PaloFindDancerAnim(DANCER *, int);
void ResolveDancerMoves(DANCER *dancer)
{
    for (int imove = 0; imove < dancer->cmove; imove++) {
        void **ppanim = (void **)((char *)dancer + imove * 0x28 + 0x2D0);
        for (int istep = 0; istep < 3; istep++) {
            int oid = ((int *)ppanim)[-1];
            if (oid != -1)
                *ppanim = PaloFindDancerAnim(dancer, oid);
            ppanim = (void **)((char *)ppanim + 12);
        }
    }
}
