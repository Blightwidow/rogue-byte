struct Item_240050 { int field0; int field4; int key; };
struct List_240050 { struct Item_240050 **items; int count; };
struct Out_240050 { struct Item_240050 **values; int count; };

void func_00240050(struct List_240050 *list, struct Out_240050 *out)
{
    int count = list->count;
    int nextIndex[count];
    int head = -1;
    int index = 0;
    int link;
    int ahead;
    int cursor;
    int nextLink;
    int outCount;
    struct Item_240050 **items;

    if (count == 0) {
        goto compact;
    }
outer:
    link = head;
    if (link == -1) {
        goto headInsert;
    }
    items = list->items;
    if (items[index]->key - items[link]->key >= 0) {
        goto headInsert;
    }
    ahead = index + 1;
    cursor = link;
emit:
    outCount = out->count;
    out->values[outCount] = items[cursor];
    nextLink = nextIndex[cursor];
    out->count = outCount + 1;
    items[cursor] = 0;
    if (nextLink == -1) {
        goto tailInsert;
    }
    cursor = nextLink;
    if (items[index]->key - items[cursor]->key < 0) {
        goto emit;
    }
    head = index;
    nextIndex[index] = cursor;
    index = ahead;
    goto check;
headInsert:
    head = index;
    nextIndex[index] = link;
    index = index + 1;
    goto check;
tailInsert:
    head = index;
    nextIndex[index] = -1;
    index = index + 1;
check:
    if (index < count) {
        goto outer;
    }
    index = 0;
compact:
    link = 0;
    if (count == 0) {
        goto done;
    }
    items = list->items;
    for (index = 0; index < count; index++) {
        if (items[index] != 0) {
            items[link] = items[index];
            link = link + 1;
        }
    }
done:
    list->count = link;
}
