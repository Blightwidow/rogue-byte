typedef int s32; typedef unsigned u32; typedef signed char s8;
extern "C" {
void *memset(void *, int, unsigned);
extern s32 B_002E1E68;
struct Entry { s32 key; char pad[0x18]; };
struct Queue { u32 count; Entry entries[16]; };
s32 *PentryAddBootQueue(Queue *queue, s32 arg1) {
    u32 index = queue->count;
    s32 *result;
    if (index < 0x10U) {
        queue->count = index + 1;
        Entry *entry = &queue->entries[index];
        memset(entry, 0, 0x1C);
        entry->key = arg1;
        result = (s32 *)entry;
    } else {
        result = &B_002E1E68;
    }
    return result;
}
}
