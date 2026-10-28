extern "C" void SetHudLabelState(int *, int);
extern "C" void InitHudLabel(int *label)
{
    label[6] = -1;
    label[8] = -1;
    label[10] = 0;
    SetHudLabelState(label, 0);
}
