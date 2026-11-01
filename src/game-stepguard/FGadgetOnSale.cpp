extern "C" {
int NEpisodeBest(void);
extern char D_002BCD00[];

int FGadgetOnSale(int index) {
    char *entry = D_002BCD00 + (index << 5);
    if (*(int *)(entry + 0x10) == -1) {
        return 0;
    }
    return NEpisodeBest() >= *(int *)(entry + 0x10);
}
}
