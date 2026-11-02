typedef int QW __attribute__((mode(TI)));
extern "C" {
int FIsBasicDerivedFrom(int, int);
QW PosLoWorld(int);
extern char g_2a2dc0[];
QW PosCplookAnchor(int *arg0)
{
    struct { QW dead; QW result; } frame;
    int word;
    frame.result = PosLoWorld(*arg0);
    if (FIsBasicDerivedFrom(*arg0, 0x34) != 0) {
        // word is written (mfc1) before the later inputs are read, so it must not share a register with them
        asm("lqc2 vf3, %2\n\t"
            "mfc1 %0, %4\n\t"
            "lqc2 vf1, 0(%3)\n\t"
            "qmtc2.ni %0, vf2\n\t"
            "vadda.xyzw ACC, vf3, vf0\n\t"
            "vmaddx.xyzw vf3, vf1, vf2x\n\t"
            "sqc2 vf2, %1\n\t"
            "sqc2 vf3, %2"
            : "=&r"(word), "=m"(frame.dead), "+m"(frame.result)
            : "r"(g_2a2dc0), "f"(150.0f));
    }
    return frame.result;
}
}
