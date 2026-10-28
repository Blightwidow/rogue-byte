struct JT { char pad[0x12FC]; int *pnPower; int nMax; };
void SetJtPower(JT *pjt, int nPower)
{
    int *pn = pjt->pnPower;
    if (pn) {
        int nMax = pjt->nMax;
        *pn = nPower < nMax ? nPower : nMax;
    }
}
