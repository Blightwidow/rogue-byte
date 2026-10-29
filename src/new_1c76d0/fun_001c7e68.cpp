#include "m2c_macros.h"
extern "C" {
void func_001CB518(char *);
void func_001C7E68(char *arg0) {
    char *vt;
    s16 off;
    void (*fn)(char *, s32);
    func_001CB518(arg0);
    vt = *(char **)(arg0 + 0xC);
    off = *(s16 *)(vt + 0x260);
    fn = *(void (**)(char *, s32))(vt + 0x264);
    fn(arg0 + off, 0);
}
}
