// 0x1A1F68 UpdateUbgSgs__FP3UBG
extern "C" void func_801A0B40(void* p, int state);

void UpdateUbgSgs__FP3UBG(void* p)
{
    int* v = *(int**)((unsigned char*)p + 0x10);
    if (*v > 0) {
        func_801A0B40(p, 0);
    } else {
        func_801A0B40(p, 8);
    }
}