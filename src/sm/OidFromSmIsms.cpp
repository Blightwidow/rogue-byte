struct ISMS {
    int oid;
    int other;
};
struct SM {
    char pad[0x50];
    int count;
    ISMS *items;
};
extern "C" int OidFromSmIsms(SM *sm, int index)
{
    if (index < 0 || index >= sm->count)
        return -1;
    return sm->items[index].oid;
}
