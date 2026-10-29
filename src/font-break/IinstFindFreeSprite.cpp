#include "sly2.h"
extern "C" int IinstFindFreeSprite(char *arg0) {
    unsigned short count = *(unsigned short *)(arg0 + 2);
    int index = 0;
    if (count != 0) {
        char *entry = *(char **)(arg0 + 8) + 8;
        do {
            if (*(short *)entry < 0) return index;
            index += 1;
            entry += 0x18;
        } while (index < (int)count);
    }
    return 0;
}
