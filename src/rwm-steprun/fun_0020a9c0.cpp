struct Owner_20A9C0 {
    char pad0[0xEB8]; int types[8];
    int typeCount;
    int plos[8];
    int ploCount;
};
extern "C" {
int PloNew(int, Owner_20A9C0 *, int, int);

int func_0020A9C0(Owner_20A9C0 *self) {
    int plo;
    if (self->typeCount == 0) {
        plo = PloNew(0x78, self, 0x2CC, -1);
        self->plos[self->ploCount++] = plo;
        self->types[self->typeCount++] = 0x2CC;
    } else {
        plo = self->plos[0];
    }
    return plo;
}
}
