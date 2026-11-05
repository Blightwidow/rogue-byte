extern "C" {
extern char B_003DD490[];
}
extern "C" void RemovePathzoneEndpoints(int, void *, int);

struct SW { char pad[0x3D70]; int stamp; };
extern SW B_003DD490_sw;
static inline int NextStamp(SW *sw) { return ++sw->stamp; }

struct PZ {
    char pad0[0xF8];
    int cobstacle;
    int cslot;
    int cep;
    void *aepX;
    void *aepY;
    int *aslot;
    int unk110;
    int stamp;
};

void RemovePathzoneObstacle(PZ *pz, int obstacle)
{
    int islot = 0;
    while (islot < pz->cslot && pz->aslot[islot] != obstacle)
        islot++;
    pz->aslot[islot] = 0;
    RemovePathzoneEndpoints(pz->cep, pz->aepX, islot);
    RemovePathzoneEndpoints(pz->cep, pz->aepY, islot);
    pz->cobstacle--;
    pz->cep -= 2;
    pz->stamp = NextStamp((SW *)B_003DD490);
}
