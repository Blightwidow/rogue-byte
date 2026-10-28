void *memset(void *, int, unsigned int);
extern "C" char B_003DD490[];
extern "C" int D_002C3E70[];
extern "C" void *PloFindSwObject_thunk(void *, int, int, int);
extern "C" void func_00213C68(void *, float *);
extern "C" int CcluesFound();
extern "C" int func_001C7D00();
void InitSwHudBlots(char *sw)
{
    float transform[8];
    memset(transform, 0, 0x20);
    transform[3] = 1.0f;
    transform[0] = 1.0f;
    for (int i = 0; i < 4; i++) {
        void *blot = PloFindSwObject_thunk(B_003DD490, 0x405, D_002C3E70[i], 0);
        if (blot) {
            func_00213C68(blot, transform);
            *(void **)(sw + 0x3BA0 + i * 0xC) = blot;
        }
    }
    *(int *)(sw + 0x4764) = CcluesFound();
    *(int *)(sw + 0x4768) = func_001C7D00();
}
