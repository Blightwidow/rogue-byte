extern "C" {
void PwreGetWrCur__FP2WR4ENSK4WREK(void* pwr, int ensk, int wrek);
}

void PwreGetWrBend__FP2WR4ENSK(void* pwr, int ensk)
{
    PwreGetWrCur__FP2WR4ENSK4WREK(pwr, ensk, 1);
}