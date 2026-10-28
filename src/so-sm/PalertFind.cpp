struct ALERT {
    char pad0[0xC];
    int key;
    char pad1[0x10];
    ALERT *next;
};
extern "C" ALERT *B_003E145C;
extern "C" ALERT *PalertFind(int key)
{
    for (ALERT *alert = B_003E145C; alert; alert = alert->next) {
        if (alert->key == key)
            return alert;
    }
    return 0;
}
