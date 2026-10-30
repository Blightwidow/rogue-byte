extern "C" {
struct Link_1A6290 { int pad0; Link_1A6290 *next; int oid; int padc; void *owner; };
struct Lo_1A6290 { char pad0[0x18]; int oid; char pad1[0x20]; Link_1A6290 *links; };

int FLoHasOid(Lo_1A6290 *lo, int oid) {
    Link_1A6290 *link;
    if (lo->oid == oid) return 1;
    link = lo->links;
    while (link) {
        if (link->owner != lo) break;
        if (link->oid == oid) return 1;
        link = link->next;
    }
    return 0;
}
}
