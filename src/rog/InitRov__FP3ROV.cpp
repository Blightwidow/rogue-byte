struct ROV { char pad[0x264]; int field264; char pad2[8]; float field26C_unused[0]; float field270; float field274; };
extern "C" void InitMissile(ROV *);
void InitRov__FP3ROV(ROV *rov)
{
    InitMissile(rov);
    rov->field270 = 2000.0f;
    rov->field274 = 5000.0f;
    rov->field264 = 0;
}
