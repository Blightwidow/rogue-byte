#include "sly2.h"

int func_001FCF88(int arg0, int arg1) {
    int temp_a1 = arg1;
    *(int*)(arg1 + 0xA4) = arg0;
    *(int*)(arg1 + 0xA0) = 0;
    return 0;
}

