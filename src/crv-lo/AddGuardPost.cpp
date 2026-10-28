#include "sly2.h"
struct Post { int postA; int pad4; int zoneA; int pad0xC; int postB; int pad0x14; int zoneB; char pad[0x24 - 0x1C]; };
struct Guard { char pad[0x1010]; int count; Post *posts; };
void AddGuardPost(Guard *guard, int postA, int zoneA, int postB, int zoneB)
{
    int index = guard->count;
    guard->count = index + 1;
    Post *post = &guard->posts[index];
    post->postA = postA;
    post->zoneA = zoneA;
    post->postB = postB;
    post->zoneB = zoneB;
}
