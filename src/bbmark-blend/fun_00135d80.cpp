#include "sly2.h"
struct BENTLEY;
extern "C" void *PasegAttachBase(void *, int *);
extern "C" void *bevy_player_p7_damage_1a23f8(void *, int *);
extern "C" void *func_0019C870(void *, int *);
extern "C" void func_00203D00(BENTLEY *, void *, int);
void SetBentleyAnimBase(char *b)
{
    int flag = 0;
    void *base;
    int state = *(int *)(b + 0x13D0);
    switch (state) {
    case 3: base = PasegAttachBase(b + 0x4C0, &flag); break;
    case 4: base = bevy_player_p7_damage_1a23f8(b + 0xDF0, &flag); break;
    case 2: base = func_0019C870(b + 0x2C0, &flag); break;
    default: base = 0;
    }
    if (!base) base = *(void **)(b + 0x268);
    func_00203D00((BENTLEY *)b, base, flag);
}
