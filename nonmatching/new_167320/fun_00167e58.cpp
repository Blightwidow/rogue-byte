struct VUDATA { char pad[0x3010]; int base; char pad2[0x3070 - 0x3014]; int u0; int u4; int rowA; int rowB; int rowEnd; int colA; int colB; int u1C; int alphaAFlag; int alphaBOff; int alphaAOff; };
void func_00167E58(char *data)
{
    char *p = data + 0x3070;
    int base = *(int *)(data + 0x3010);
    unsigned char *end = (unsigned char *)data + *(int *)(p + 0x10) * 16;
    unsigned char *rowB = (unsigned char *)data + *(int *)(p + 0xC) * 16;
    unsigned char *alphaB = (unsigned char *)(*(int *)(p + 0x24) + base);
    unsigned char *rowA = (unsigned char *)data + *(int *)(p + 8) * 16;
    unsigned short *colA = (unsigned short *)(*(int *)(p + 0x14) + base);
    unsigned short *colB = (unsigned short *)(*(int *)(p + 0x18) + base);
    unsigned char *alphaA = (unsigned char *)(*(int *)(p + 0x20) + base);
    if (rowB < end) {
        do {
            unsigned short *dstB = colB;
            *colA = ((rowA[4] >> 3) << 5) | (rowA[0] >> 3) | ((rowA[8] >> 3) << 10) | ((rowA[0xC] >> 7) << 15);
            colA++;
            colB++;
            *dstB = ((rowB[4] >> 3) << 5) | (rowB[0] >> 3) | ((rowB[8] >> 3) << 10) | ((rowA[0xC] >> 7) << 15);
            *alphaB = rowB[0xC];
            alphaB++;
            if (*(int *)(p + 0x20) != 0) {
                *alphaA = rowA[0xC];
                alphaA++;
            }
            rowB += 16;
            rowA += 16;
        } while (rowB < end);
    }
}
