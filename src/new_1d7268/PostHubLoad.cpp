#include "sly2.h"
extern "C" void PostSoLoad(char *arg0);
extern "C" void PostHubLoad(char *arg0) {
    PostSoLoad(arg0);
    char *hub = *(char **)(arg0 + 0xC);
    (*(void (**)(char *, int))(hub + 0x27C))(arg0 + *(short *)(hub + 0x278), 0);
}
