struct MOVIE { char pad[0x40]; };
struct CMpeg {
    int cmovie;
    MOVIE amovie[4];
    char pad[0x104 - 4 - 0x100];
    void *psubtitle;
    int fRepeat;
    void Execute(MOVIE *);
};
extern "C" unsigned int func_001AE150(int);
extern "C" void *func_001B2820(MOVIE *);

int FPlayQueuedMovies(CMpeg *pmpeg)
{
    if (pmpeg->cmovie <= 0)
        return 0;
    if (func_001AE150(1) < 0x41FC40) {
        pmpeg->cmovie = 0;
        return 0;
    }
    for (int imovie = 0; imovie < pmpeg->cmovie; imovie++) {
        MOVIE *pmovie = &pmpeg->amovie[imovie];
        pmpeg->psubtitle = func_001B2820(pmovie);
        do {
            pmpeg->Execute(pmovie);
        } while (pmpeg->fRepeat != 0);
        pmpeg->psubtitle = 0;
    }
    pmpeg->cmovie = 0;
    return 1;
}
