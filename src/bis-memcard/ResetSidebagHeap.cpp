extern "C" {
void ResetSlotheap(void *);
extern unsigned B_002DD2C0;
extern unsigned B_002DD2C4;
extern unsigned B_002DD2C8;
extern unsigned B_002DD2CC;
extern char B_00452148[];
}

extern "C" void ResetSidebagHeap()
{
    B_002DD2C0 = 0;
    B_002DD2C8 = 0;
    B_002DD2CC = 0;
    B_002DD2C4 = 0;
    ResetSlotheap(B_00452148);
}
