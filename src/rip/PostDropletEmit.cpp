extern "C" {
struct PDE_1D0CE8_Source { char pad[0x8]; struct PDE_1D0CE8_Info *pInfo; };
struct PDE_1D0CE8_Info { char pad[0xC]; int nValue; };
struct PDE_1D0CE8_Droplet { char pad[0xF4]; int nValue; };

void func_001CE9B8(void *pDroplet, void *pSource);

void PostDropletEmit(struct PDE_1D0CE8_Droplet *pDroplet, struct PDE_1D0CE8_Source *pSource)
{
    func_001CE9B8(pDroplet, pSource);
    pDroplet->nValue = pSource->pInfo->nValue;
}
}
