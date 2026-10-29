#include "sly2.h"
extern "C" int BuildSlotFilePath(int arg0, int arg1, char *path);
extern "C" int WriteMemcardFile(int slot, char *path, int arg1, int size);

extern "C" void WriteSaveSlot(int arg0, int arg1)
{
    char sp[0x50] __attribute__((aligned(16)));
    BuildSlotFilePath(arg0, arg1, sp);
    WriteMemcardFile(arg0, sp, arg1, 0x5408);
}
