#include "sly2.h"
struct AMB;
struct PROXY { char pad[0xE4]; int count; int pad2; AMB **slots; };
extern "C" void RemoveAloHierarchy(PROXY *);
extern "C" void StopAmb(AMB *, float);
extern "C" void VirtualRefPtr_Assign(AMB **, AMB *);

extern "C" void Proxy_RemoveAloHierarchy(PROXY *pproxy)
{
    RemoveAloHierarchy(pproxy);
    for (int index = 0; index < pproxy->count; index++) {
        AMB **pslot = (AMB **)(index * 4 + (int)pproxy->slots);
        if (pslot != 0 && *pslot != 0) {
            StopAmb(*pslot, 0.0f);
            VirtualRefPtr_Assign(pslot, 0);
        }
    }
}
