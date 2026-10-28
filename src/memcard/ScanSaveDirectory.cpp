#include "sly2.h"
struct SAVE { int port; int slot; int pad8; int state; };
struct SAVEMC { char pad[0xFD5C]; int mc; };
extern "C" {
int sceMcGetDir(int, int, const char *, int, int, int);
int McSync(int *, int, int, int *);
void GetCardFreeBytes(SAVE *, int *);
void ReadSaveSlot(SAVE *, void *);
}
extern char RO_002A6BB0[];
extern "C" int ScanSaveDirectory(SAVE *psave)
{
    int ac[2];
    int *pmc = &((SAVEMC *)psave)->mc;
    int start = sceMcGetDir(psave->port, psave->slot, RO_002A6BB0, 0, -1, 0);
    int error = McSync(pmc, start, 0xD, &ac[0]);
    if (ac[0] < 1) {
        GetCardFreeBytes(psave, &ac[1]);
        if (ac[1] < 0x19000)
            psave->state = 4;
        return 0xE;
    }
    int islot = 0;
    if (error == 0) {
        char *pslot = (char *)psave + 0x24;
        do {
            ReadSaveSlot(psave, pslot);
            pslot += 0x5464;
            islot++;
        } while (error == 0 && islot < 3);
        if (error == 0) {
            if (psave->state < 5)
                psave->state = 5;
        }
    }
    return error;
}
