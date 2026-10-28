struct JSG { char pad[0x50]; int phase; char pad2[4]; int value; char pad3[0x24]; int flag; };
extern "C" void func_001E01C8(JSG *jsg, int value)
{
    if (value > 0) {
        if (value < 0x200) {
            if (jsg->phase < 2) {
                jsg->value = value;
                jsg->flag = 1;
            }
        }
    }
}
