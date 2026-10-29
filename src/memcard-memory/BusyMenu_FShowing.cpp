#include "sly2.h"
extern "C" int BusyMenu_FShowing(char *arg0) {
    char *menu = *(char **)(arg0 + 0x24);
    if (menu == 0) return 0;
    int result = 1;
    if (*(int *)(menu + 0x58) < 2) {
        result = 1;
        if (*(int *)(menu + 0x64) < 2) return 0;
    }
    return result;
}
