extern int B_003E1080;
extern int B_00443740;
int FSwLoadBusy(void)
{
    if (B_003E1080 != 0) return 1;
    return B_00443740 == 1;
}
