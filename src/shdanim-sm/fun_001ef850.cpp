struct Object { char pad0[0x40]; int flagsOrPointer; char pad1[0x148 - 0x44]; long mask; };
extern "C" {
void PostSoLoad();
void func_001A6CA8(Object *, int);
void func_001EF850(Object *object) {
    PostSoLoad();
    func_001A6CA8(object, 1);
    int value = object->flagsOrPointer;
    if ((value ^ 1) & 1) {
        *(int *)value = *(int *)value | 2;
    } else {
        object->flagsOrPointer = value | 2;
    }
    object->mask = object->mask & ~(1L << 35);
}
}
