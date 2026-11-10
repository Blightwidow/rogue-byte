struct OXA {
    char pad[0x70];
    long flags;
};
#include "so.h"
extern "C" int GetSoNoXpsAll(SO *so)
{
    if (so->poxa == 0)
        return 1;
    return (int)(so->poxa->flags >> 2) & 1;
}
