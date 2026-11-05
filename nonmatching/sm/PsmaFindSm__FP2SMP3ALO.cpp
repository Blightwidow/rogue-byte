struct SMA {
    char pad0[0x14];
    SMA *next;
    char pad1[0x10];
    void *key;
};
struct SM {
    char pad[0x68];
    SMA *head;
};
extern "C" SMA *PsmaFindSm__FP2SMP3ALO(SM *sm, void *key)
{
    char unused[8];
    SMA *node = sm->head;
    while (node) {
        if (node->key == key)
            return node;
        node = node->next;
    }
    return 0;
}
