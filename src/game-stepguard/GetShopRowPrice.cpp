struct SHOP_1DC820 { char pad0[0x4C]; unsigned item[1]; };
struct SHOPSTATE_1DC820 { char pad[0x4C]; int unused; };
struct ITEMDEF_1DC820 { int a; int b; int price; char pad[20]; };
struct SHOPGLOBAL_1DC820 { char pad0[0x4C]; char rows[0x250 - 0x4C]; int base; };
extern SHOPGLOBAL_1DC820 B_003DA150;
extern ITEMDEF_1DC820 D_002BCD00[];
extern const char RO_002A79A0[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" void GetShopRowPrice(char *out, int row)
{
    unsigned itemId = *(unsigned *)((char *)&B_003DA150 + (B_003DA150.base + row) * 8 + 0x4C);
    int price = 0;
    if (itemId < 0x2B)
        price = D_002BCD00[itemId].price;
    if (price != 0)
        sprintf(out, RO_002A79A0, price);
    else
        *out = 0;
}
