extern "C" {
extern char B_003DD490[];
extern float g_2dded0;
int func_001C4BD8(void *, int, void *);
int func_001C5B20(void *, void *);
int FIsBasicDerivedFrom(void *, int);
}

struct VT { char pad[0x260]; short delta; short index; void (*fn)(void *, int); };

struct DP {
    char pad0[0xC];
    VT *vt;
    char pad1[0x1C8 - 0x10];
    int collectable;
    float expire;
};

void CheckDprizeCollect(DP *dp)
{
    if (dp->collectable == 0)
        return;
    if (dp->expire < g_2dded0) {
        VT *vt = dp->vt;
        vt->fn((char *)dp + vt->delta, 1);
        return;
    }
    void *apmagnet[16];
    int count = func_001C4BD8(B_003DD490, 16, apmagnet);
    void **slot = apmagnet;
    for (int index = 0; index < count; slot++, index++) {
        if (index > 0) {
            if (FIsBasicDerivedFrom(dp, 0x5B) == 0)
                break;
        }
        if (func_001C5B20(dp, *slot) == 0)
            continue;
        break;
    }
}
