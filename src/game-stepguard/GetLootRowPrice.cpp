extern "C" {
struct Slot_1DC9C0 { int pad; unsigned int kind; };
struct Vars_1DC9C0 { char pad0[0x48]; Slot_1DC9C0 slot[1]; };
struct Vars2_1DC9C0 { char pad0[0x250]; int first; };
struct Price_1DC9C0 { int price; int pad[2]; };
void sprintf(char *, const char *, int);
extern Vars_1DC9C0 B_003DA150;
extern Price_1DC9C0 D_002C3288[];
extern const char RO_002A79A0[];

void GetLootRowPrice(char *out, int row) {
    unsigned int kind = B_003DA150.slot[((Vars2_1DC9C0 *)&B_003DA150)->first + row].kind;
    int price = 0;
    if (kind < 0x40U) {
        price = D_002C3288[kind].price;
    }
    if (price != 0) {
        sprintf(out, RO_002A79A0, price);
        return;
    }
    *out = 0;
}
}
