#include "sly2.h"
extern "C" char *PjsgeAllocJsg(int arg0, int arg1, int arg2);
extern "C" void AddSeqRecordSetTunnel(int arg0, int arg1, int arg2) {
    char *record = PjsgeAllocJsg(arg0, 0x18, 1);
    *(int *)(record + 0x10) = arg1;
    *(int *)(record + 0x14) = arg2;
}
