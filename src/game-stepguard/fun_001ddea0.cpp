extern "C" {
struct Item_1DDEA0 { char pad[0x6C]; int id; };
struct Entry_1DDEA0 { Item_1DDEA0 *item; int unused0; int unused1; };
struct Table_1DDEA0 { char pad[0x48]; int count; Entry_1DDEA0 entries[1]; };
extern Table_1DDEA0 B_003DA3C0;
extern char B_003DD490;
char *PchzStringFromId(void *, int);
char *strcpy(char *, char *);

void func_001DDEA0(char *dest, int index) {
    if (index < B_003DA3C0.count) {
        strcpy(dest, PchzStringFromId(&B_003DD490, B_003DA3C0.entries[index].item->id));
    }
}
}
