#include "sly2.h"
extern "C" char *PjsgeAllocJsg(int arg0, int arg1, int arg2);
extern "C" void AddSeqRecordVoice(int arg0, int arg1, int arg2, int arg3) {
    char *record = PjsgeAllocJsg(arg0, 0x45, arg3);
    *(int *)(record + 0x10) = arg1;
    *(int *)(record + 0x14) = arg2;
}
