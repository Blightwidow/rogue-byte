struct RGBA4_2275B8 {
    unsigned char c[4];
    RGBA4_2275B8() {}
    ~RGBA4_2275B8() {}
};
extern "C" RGBA4_2275B8 func_002275B8(int kind)
{
    RGBA4_2275B8 color;
    switch (kind) {
    case 0x35:
        color.c[0] = 0x33; color.c[1] = 0x66; color.c[2] = 0x99; color.c[3] = 0x7F;
        break;
    case 0x37:
        color.c[1] = 0x99; color.c[2] = 0x33; color.c[3] = 0x7F; color.c[0] = 0x33;
        break;
    case 0x36:
        color.c[0] = 0x99; color.c[1] = 0x33; color.c[2] = 0x66; color.c[3] = 0x7F;
        break;
    case 0x3F:
        color.c[2] = 0x33; color.c[0] = 0x99; color.c[3] = 0x7F; color.c[1] = 0x33;
        break;
    case 0x3C:
        color.c[1] = 0x33; color.c[2] = 0x99; color.c[3] = 0x7F; color.c[0] = 0x99;
        break;
    default:
        color.c[2] = 0x66; color.c[3] = 0x7F; color.c[0] = 0x66; color.c[1] = 0x66;
        break;
    }
    RGBA4_2275B8 result = color;
    return result;
}
