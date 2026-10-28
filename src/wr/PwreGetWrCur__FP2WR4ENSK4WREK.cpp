enum ENSK { ENSK_Get, ENSK_Set };
enum WREK { WREK_A, WREK_B };
struct WR { char pad0[0x54]; int cwre; char pad1[0x60 - 0x58]; char awre[0x680]; int iwreCur; char pad2[0x8FC - 0x6E4]; int fValuesChanged; };
void *PwreGetWrCur(WR *pwr, ENSK ensk, WREK wrek)
{
    if (pwr->cwre == 0)
        return 0;
    if (ensk == ENSK_Set)
        pwr->fValuesChanged = ensk;
    return pwr->awre + pwr->iwreCur * 0xD0;
}
