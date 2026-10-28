extern "C" void ClearHudLabel(int *label, int id)
{
    if (id == -1) {
        label[8] = -1;
        label[7] = 0;
    } else if (id == label[6]) {
        label[7] = 0;
    } else if (id == label[8]) {
        label[8] = -1;
    }
}
