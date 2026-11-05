struct Link { char pad0[4]; int owner; char pad8[4]; Link *next; };
struct Water { char pad0[0x150]; Link *links; };
extern "C" {
void FreeSwXaList__FP2SWP2XA(void *, Link *);
void RemoveSoLoHierarchy();
void RemoveSoXa__FP2SOP2XA(int, Link *);
extern char B_003DD490;

void RemoveWater(Water *water) {
    Link *link;

    RemoveSoLoHierarchy();
    link = water->links;
    if (link != 0) {
        do {
            RemoveSoXa__FP2SOP2XA(link->owner, link);
            link = link->next;
        } while (link != 0);
    }
    FreeSwXaList__FP2SWP2XA(&B_003DD490, water->links);
    water->links = 0;
}
}
