enum OID { OID_none };
struct Touch { int oid; int data; };
struct BRK { char pad[0x148]; unsigned count; Touch touch[4]; };
void AddBrkTouchObject(BRK *brk, OID oid, int data)
{
    unsigned n = brk->count;
    if (n < 4) {
        brk->count = n + 1;
        Touch *entry = &brk->touch[n];
        entry->oid = oid;
        entry->data = data;
    }
}
