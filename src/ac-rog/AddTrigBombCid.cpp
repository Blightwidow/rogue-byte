struct S { char pad[0x24C]; unsigned count; int cid[4]; };
void AddTrigBombCid(S *self, int cid) {
    unsigned n = self->count;
    if (n < 4) {
        self->cid[n] = cid;
        self->count = n + 1;
    }
}
