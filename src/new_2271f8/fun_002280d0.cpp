typedef int s32;

struct SwObject {
    char pad0[0x130];
    s32 linked;
};

extern "C" {
s32 CploFindSwObjectsByClass(void *, s32, s32, s32, s32, SwObject **);
extern s32 B_003DD490;

SwObject *func_002280D0(void) {
    SwObject *objects[32] __attribute__((aligned(16)));
    SwObject *found = 0;
    s32 count = CploFindSwObjectsByClass(&B_003DD490, 5, 0x1A, 0, 0x20, objects);
    if (count > 0) {
        SwObject **cursor = objects;
        s32 remaining = count;
        do {
            SwObject *candidate = *cursor;
            remaining -= 1;
            cursor += 1;
            found = (candidate->linked != 0) ? candidate : found;
        } while (remaining != 0);
    }
    return found;
}
}
