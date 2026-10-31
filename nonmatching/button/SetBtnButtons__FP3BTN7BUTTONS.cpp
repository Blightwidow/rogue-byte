extern "C" {
void TriggerBtn(char *);
void UntriggerBtn(char *);
extern float g_2dded0;
void SetBtnButtons__FP3BTN7BUTTONS(char *self, int buttons) {
    int old = *(int *)(self + 0x90);
    if (old != buttons) {
        int trigger = 0;
        int untrigger = 0;
        if (old == 0) trigger = buttons == 1;
        if (old != -1) { if (buttons == 0) untrigger = 1; }
        *(int *)(self + 0x90) = buttons;
        *(float *)(self + 0x94) = g_2dded0;
        if (trigger) TriggerBtn(self);
        if (untrigger) UntriggerBtn(self);
    }
}
}
