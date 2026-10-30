typedef int s32;
struct Level_1A5078 { char p0[4]; s32 f4; char p8[0x34]; s32 f3C; };
struct Entry_1A5078 { char p0[8]; Level_1A5078 *level; s32 fC; s32 f10; };
extern "C" Entry_1A5078 *PentryAddBootQueue(void *, s32);
extern "C" void AddBootQueueLevel(void *queue, Level_1A5078 *level, s32 arg2, s32 arg3) {
    s32 changed;
    if (level == 0) { changed = 0; } else {
        changed = level->f4 != level->f3C;
    }
    if (changed != 0) {
        Entry_1A5078 *entry = PentryAddBootQueue(queue, 2);
        entry->level = level;
        entry->fC = arg2;
        entry->f10 = arg3;
    }
}
