#include "sly2.h"
struct CBinaryAsyncStream {
    int mode;
    int fd;
    int pad8;
    int pbSpooling;
    int cbSpooling;
    char pad14[8];
    int cbAvail;
    int pad20;
    int cbConsumed;
    int FSpooling();
    int FSpoolingComplete();
};
extern "C" int sceIoctl(int, int, int *);
extern "C" int sceCdSync(int);
extern "C" int sceCdGetError();

int CBinaryAsyncStream::FSpoolingComplete()
{
    int fComplete = 0;
    int ierror = 0;
    if (cbAvail == cbConsumed && FSpooling() != 0) {
        switch (mode) {
        case 0: {
            int anState[4];
            ierror = sceIoctl(fd, 1, anState);
            fComplete = anState[0] == 0;
            break;
        }
        case 1: {
            int nBusy = sceCdSync(1);
            fComplete = nBusy == 0;
            if (fComplete != 0)
                ierror = sceCdGetError();
            break;
        }
        }
    }
    if (ierror != 0) {
        pbSpooling = 0;
        cbSpooling = 0;
        fComplete = 0;
    }
    return fComplete;
}
