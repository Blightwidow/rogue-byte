extern "C" float g_2dded0;
extern "C" float RO_FLT_002A5590;
extern "C" void *func_00205438(void *, int);
extern "C" void func_00171C18(void *, void *);
extern "C" void Goal_Pop(void *);
extern "C" void func_00179EF8(void *);
extern "C" void func_00179E80(void *);
extern "C" void SetGuardScript(void *, int, int, void *);

void GoalIdle_SetState(char *self, int state)
{
    if (state == *(int *)(self + 0x38))
        return;
    if (*(int *)(self + 0x38) == 0)
        func_00171C18(*(void **)(self + 0x18), *(char **)(self + 0x10) + 0x2DC);
    Goal_Pop(self + 0x18);
    *(int *)(self + 0x38) = state;
    *(float *)(self + 0x3C) = g_2dded0;
    if (state < 3) {
        if (state > 0) {
            char *object = (char *)func_00205438(*(void **)(self + 0x10), 0x9E);
            char *objectType = *(char **)(object + 0xC);
            void (*slot)(void *) = *(void (**)(void *))(objectType + 0x44);
            slot(object + *(short *)(objectType + 0x40));
            func_00179EF8(self);
            *(float *)(self + 0x30) = RO_FLT_002A5590;
        } else if (state == 0) {
            char *object = (char *)func_00205438(*(void **)(self + 0x10), 0xA9);
            SetGuardScript(object, *(int *)(self + 0x40), 0, *(char **)(self + 0x10) + 0x2DC);
            char *objectType = *(char **)(object + 0xC);
            void (*slot)(void *) = *(void (**)(void *))(objectType + 0x44);
            slot(object + *(short *)(objectType + 0x40));
            func_00179E80(self);
            *(float *)(self + 0x34) = RO_FLT_002A5590;
        }
    } else if (state == 3) {
        char *object = (char *)func_00205438(*(void **)(self + 0x10), 0x9E);
        *(int *)(object + 0x3C) = 1;
        char *objectType = *(char **)(object + 0xC);
        void (*slot)(void *) = *(void (**)(void *))(objectType + 0x44);
        slot(object + *(short *)(objectType + 0x40));
    }
}
