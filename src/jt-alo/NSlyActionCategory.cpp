#include "sly.h"
extern "C" {
int func_00143C78(JT *, void *);
int NSlyActionCategory(SLY *arg0) {
    int result;
    if (arg0->field_0x204 != 0) {
        result = 0;
    } else {
        switch (arg0->jts) {
        case 13:
        case 14:
            result = 1;
            break;
        case 24:
            result = 0xF;
            break;
        case 3:
        case 8:
        case 21:
        case 22:
            result = 0;
            break;
        default:
            result = func_00143C78(arg0, arg0);
            break;
        }
    }
    return result;
}
}
