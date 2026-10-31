extern "C" {
struct Item_1DDF00 { char pad[0x5C]; int id; };
struct Entry_1DDF00 { Item_1DDF00 *item; int unused0; int unused1; };
struct Table_1DDF00 { char pad[0x48]; int count; Entry_1DDF00 entries[1]; };
extern Table_1DDF00 B_003DA3C0;
extern char B_003DD490;
char *PchzStringFromId(void *, int);
char *strcpy(char *, char *);

void func_001DDF00(char *dest, int index) {
    if (index < B_003DA3C0.count) {
        strcpy(dest, PchzStringFromId(&B_003DD490, B_003DA3C0.entries[index].item->id));
    }
}
}
