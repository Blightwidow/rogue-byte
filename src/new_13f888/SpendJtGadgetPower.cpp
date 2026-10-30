struct JT;
struct GADGET { int pad0[3]; int field_0xC; int pad10[4]; };
extern "C" {
int GetJtPower(JT *);
void SetJtPower(JT *, int);
extern GADGET D_002BCD00[];
extern float g_2dded0;
}
struct JT { char pad[0x1304]; float field_0x1304; };

extern "C" void SpendJfield_0x1304Power(JT *jt, int gadget)
{
    if (gadget != -1)
        SetJtPower(jt, GetJtPower(jt) - D_002BCD00[gadget].field_0xC);
    jt->field_0x1304 = g_2dded0;
}
