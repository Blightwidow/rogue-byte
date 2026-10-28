struct Owner {
    char pad0[0xEB8];
    int items[8];
    unsigned count;
};
void AddGuardAimOid(Owner *owner, int oid)
{
    if (oid != -1) {
        unsigned count = owner->count;
        if (count < 8) {
            owner->items[count] = oid;
            owner->count = count + 1;
        }
    }
}
