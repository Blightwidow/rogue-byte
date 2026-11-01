extern "C" {
void TriggerBtn(char *);
void UntriggerBtn(char *);
extern float g_2dded0;
void SetBtnButtons__FP3BTN7BUTTONS(char *self, int buttons) {
    int old = *(int *)(self + 0x90);
    if (old != buttons) {
        int trigger = (old == 0) && (buttons == 1);
        int untrigger = (old != -1) && (buttons == 0);
        *(int *)(self + 0x90) = buttons;
        *(float *)(self + 0x94) = g_2dded0;
        if (trigger) TriggerBtn(self);
        if (untrigger) UntriggerBtn(self);
    }
}
}
