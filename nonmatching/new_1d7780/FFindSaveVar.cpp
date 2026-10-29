struct SAVEVARREC { short symid; signed char savek; unsigned char cElement; unsigned short ib; unsigned short irecChild; unsigned short irecNext; };
struct SAVEVARS { int crec; SAVEVARREC *arec; };
struct SAVEPATH { int csym; unsigned short *asymid; };
struct SAVEVARLOC { SAVEVARREC *prec; int iElement; };

int FFindSaveVar(SAVEVARS *psavevars, SAVEPATH *ppath, SAVEVARLOC *psavevarloc)
{
    unsigned short irec;
    SAVEVARREC *base = psavevars->arec;
    if (base->irecChild == 0)
        return 0;
    int isym = 0;
    SAVEVARREC *prec = base + base->irecChild;
    psavevarloc->iElement = 0;
    for (;;) {
        if (prec->symid == ppath->asymid[isym]) {
            isym++;
            if (isym == ppath->csym) {
                psavevarloc->prec = prec;
                return 1;
            }
            if (prec->cElement != 0) {
                psavevarloc->prec = prec;
                psavevarloc->iElement = ppath->asymid[isym++];
                return isym == ppath->csym;
            }
            if (prec->savek != -1)
                return 0;
            irec = prec->irecChild;
            if (irec == 0)
                return 0;
        } else {
            irec = prec->irecNext;
            if (irec == 0)
                return 0;
        }
        prec = psavevars->arec + irec;
    }
}
