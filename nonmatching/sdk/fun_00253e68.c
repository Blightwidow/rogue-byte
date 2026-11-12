extern unsigned func_00252148(char *mpeg, unsigned count);
extern void func_0024FA38(char *mpeg, const char *message);
extern const char RO_002AC6E0[];
extern const char RO_002AC708[];
void func_00253E68(char *mpeg)
{
    unsigned selector;
    unsigned status;
    unsigned countHigh;
    unsigned countLow;
    unsigned fieldA;
    unsigned fieldB;
    unsigned fieldC;
    unsigned fieldD;
    unsigned fieldE;
    unsigned fieldF;
    unsigned fieldG;
    unsigned value;
    *(int *)(mpeg + 0x858) = 1;
    *(volatile unsigned *)0x10002010 = *(volatile unsigned *)0x10002010 & 0xFF7FFFFF;
    value = func_00252148(mpeg, 0x1C);
    countHigh = (value >> 1) & 0xFFF;
    fieldD = (value >> 17) & 0x3;
    fieldE = (value >> 13) & 0x3;
    fieldF = (value >> 15) & 0x3;
    *(unsigned *)(mpeg + 0x150) = fieldD;
    if (fieldD != 1)
        func_0024FA38(mpeg, RO_002AC6E0);
    *(unsigned *)(mpeg + 0x14C) = (value >> 19) & 0x1;
    selector = value >> 20;
    value = func_00252148(mpeg, 0x10) >> 8;
    if (selector != 0x48 && selector != 0x58 && selector != 0x44)
        func_0024FA38(mpeg, RO_002AC708);
    fieldA = *(unsigned *)(mpeg + 0x134) & 0xFFF;
    fieldB = *(unsigned *)(mpeg + 0x138) & 0xFFF;
    fieldC = *(unsigned *)(mpeg + 0x144);
    fieldG = *(unsigned *)(mpeg + 0x148);
    *(unsigned *)(mpeg + 0x148) = fieldG + (value << 10);
    *(unsigned *)(mpeg + 0x134) = (fieldF << 12) | fieldA;
    *(unsigned *)(mpeg + 0x138) = (fieldE << 12) | fieldB;
    *(unsigned *)(mpeg + 0x144) = fieldC + (countHigh << 18);
}
