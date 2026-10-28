extern "C" void* PwreGetWrCur(void* p, int ensk, int wr);
void* PwreGetWrCircle__FP2WR4ENSK(void* p, int ensk)
{
    PwreGetWrCur(p, ensk, 0);
}