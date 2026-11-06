struct Limit { float first; int second; float third; };
struct JtPipe {
    int field0;
    int field4;
    char pad8[0x28];
    Limit limitA;
    char pad3C[4];
    Limit limitB;
};
void InitJtPipe(JtPipe *pipe, int owner)
{
    Limit *limitA = &pipe->limitA;
    Limit *limitB = &pipe->limitB;
    pipe->field0 = owner;
    pipe->field4 = -1;
    limitA->first = 45.0f;
    limitA->third = 40.0f;
    limitA->second = 0;
    limitB->first = 45.0f;
    limitB->third = -20.0f;
    limitB->second = 0;
}
