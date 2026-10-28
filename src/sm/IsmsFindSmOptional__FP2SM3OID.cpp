struct ISMS {
    int oid;
    int other;
};
struct SM {
    char pad[0x50];
    int count;
    ISMS *items;
};
extern "C" int IsmsFindSmOptional__FP2SM3OID(SM *sm, int oid)
{
    for (int index = 0; index < sm->count; index++) {
        if (sm->items[index].oid == oid)
            return index;
    }
    return -1;
}
