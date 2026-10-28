#include "sly2.h"
struct ENT { int item; int pad[3]; };
struct S {
    char pad0[0x410]; ENT ents[7]; int pad1; int limit; int index; int pad2; int pad3; int pz;
};
extern char B_002DEB30[];
extern "C" void bevy_camera_follow_activity(char *, int, S *);
extern "C" int SpewPrizes(int, int);
extern "C" void func_001F17F8(S *, int);
extern "C" void func_001F1CF8(S *);

int func_001F1E20(S *s)
{
    int index = s->index;
    if (index >= s->limit)
        return 0;
    bevy_camera_follow_activity(B_002DEB30, 0x19, s);
    int result = SpewPrizes(s->pz, *(int *)((char *)s + 0x410 + (s->index << 4)));
    func_001F17F8(s, -1);
    s->index = s->index + 1;
    func_001F1CF8(s);
    return result;
}
