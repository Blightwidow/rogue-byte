struct ALLOCREQ { int size; int align; };
struct GLOB { char pad[0x10]; int cqw; };
struct GLOBI { char pad[0x10]; int chain; int data; };
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
void CopyGlobDmaChain(GLOB *pglob, GLOBI *pglobi, int cqw, char *source, int relocate, int newBase, int oldBase)
{
    pglob->cqw = cqw;
    ALLOCREQ req;
    int align = 0x10;
    req.size = cqw << 4;
    char *chain = (char *)PvAllocSwCopyImpl__FiPv((req.align = align, &req), source);
    pglobi->chain = (int)chain;
    pglobi->data = pglobi->data + ((int)chain - (int)source);
    if (relocate != 0) {
        char *pw = chain;
        int delta = newBase - oldBase;
        while (pw < (char *)pglobi->chain + pglob->cqw * 16) {
            switch ((int)(*(unsigned *)pw >> 28)) {
            case 4:
                *(int *)(pw + 4) = *(int *)(pw + 4) + delta;
                pw += 16;
                break;
            case 1:
                pw += *(unsigned short *)pw * 16 + 16;
                break;
            case 6:
                pw = (char *)pglobi->chain + pglob->cqw * 16;
                break;
            default:
                break;
            }
        }
    }
}
