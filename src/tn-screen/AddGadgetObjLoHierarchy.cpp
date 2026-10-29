extern "C" {
/* 0x224028: add the hierarchy, then if the object at +0x164 is set, link it with the field at +0x168 as the fifth argument */
typedef int s32;
void AddSoLoHierarchy(void *);
void func_001F1448(void *, void *, s32, s32, void *);
void AddGadgetObjLoHierarchy(char *arg0) {
    char *child;
    AddSoLoHierarchy(arg0);
    child = *(char **)(arg0 + 0x164);
    if (child != 0) {
        func_001F1448(child, arg0, -1, 0, arg0 + 0x168);
    }
}
}
