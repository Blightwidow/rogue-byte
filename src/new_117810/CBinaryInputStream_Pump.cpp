#include "sly2.h"
struct CBinaryInputStream {
    unsigned flags;
    int unk0x4;
    int cb;
    int cbPumped;
    char *pbRaw;
    int cbRaw;
    char pad[0x18];
    virtual void RawPump();
    void Decompress();
};

void CBinaryInputStream_Pump(CBinaryInputStream *pbis)
{
    if (pbis->cb == 0) {
        if (pbis->flags & 2) {
            pbis->Decompress();
        } else {
            pbis->RawPump();
            pbis->cb = pbis->cbRaw;
            pbis->unk0x4 = (int)pbis->pbRaw;
            pbis->pbRaw = pbis->pbRaw + pbis->cbRaw;
            pbis->cbRaw = 0;
        }
        pbis->cbPumped += pbis->cb;
    }
}
