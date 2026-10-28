struct ITEM { char *mode; int pad[6]; };
struct SCREEN { char pad[0x24]; int count; char pad2[4]; ITEM items[1]; };
extern "C" char D_002BFDA8[], D_002BFE08[], D_002BFE68[];
extern "C" int CGc_FFindScreen(SCREEN *);
int func_001B0078(SCREEN *p)
{
    if (CGc_FFindScreen(p) == 0)
        return -1;
    int n = p->count;
    if (n <= 0)
        return -1;
    char *m = p->items[n - 1].mode;
    if (m == D_002BFDA8)
        return 0x1E;
    if (m != D_002BFE08)
        return m != D_002BFE68 ? -1 : 0x19;
    return 0x1F;
}
