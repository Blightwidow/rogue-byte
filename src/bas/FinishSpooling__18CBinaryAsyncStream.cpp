#include "sly2.h"
struct CBinaryAsyncStream {
    int mode;
    int pad4;
    int isector;
    int cbSpooling;
    int pbSpooling;
    char pad14[8];
    int cbAvail;
    int pbCur;
    int cbConsumed;
    int cbRemaining;
    int FSpoolingComplete();
    void FinishSpooling();
};

void CBinaryAsyncStream::FinishSpooling()
{
    if (FSpoolingComplete() == 0)
        return;
    if (mode == 1)
        isector += cbSpooling / 0x800;
    cbRemaining -= cbSpooling;
    cbAvail = cbSpooling;
    pbCur = pbSpooling;
    cbSpooling = 0;
    pbSpooling = 0;
    cbConsumed = 0;
}
