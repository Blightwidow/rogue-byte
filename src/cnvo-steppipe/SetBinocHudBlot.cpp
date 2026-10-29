void SetBinocHudBlot(int *arg0, int arg1)
{
    if (arg1 != 0) {
        arg0[4] = arg1;
        return;
    }
    arg0[4] = arg0[3];
}
