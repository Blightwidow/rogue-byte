#include "sly2.h"
enum UPK { UPK_DUMMY };
struct VIFS {
    char pad[8];
    int cursor;
    void AddVifUnpackRefs(UPK upk, int c, void *pvSrc, int uAddr, void ***ppvOut);
};
extern "C" {
void Align__4VIFSi(VIFS *, int);
int VIFS_AddUnpackCommand(VIFS *, UPK, int, int);
void AddDmaRefs__4DMASiP2QW(void *, int, void *);
}
void VIFS::AddVifUnpackRefs(UPK upk, int c, void *pvSrc, int uAddr, void ***ppvOut)
{
    if (c != 0) {
        Align__4VIFSi(this, 3);
        int cb = VIFS_AddUnpackCommand(this, upk, c, uAddr);
        AddDmaRefs__4DMASiP2QW(this, (cb + 15) / 16, pvSrc);
        if (ppvOut != 0)
            *(int *)ppvOut = cursor - 0xC;
    }
}
