#include "sly2.h"

extern "C" int FActiveCplcy(void *);
extern char B_002DE2E0[];

int func_0018D500(char *arg0)
{
    int result = 1;
    if (*(int *)(arg0 + 0xF04) == 1) {
        return 0;
    } else {
        if (FActiveCplcy(B_002DE2E0)) {
            result = 0;
        }
        return result;
    }
}
