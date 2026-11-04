#include "sly2.h"
struct Lo { char pad[0x28]; unsigned long grfo; };
struct Geom { char pad[0x10]; unsigned long grf; };
struct Brain { char pad[0x9E0]; };
extern "C" void RemoveSafePoints(Brain *, Lo *, Geom *);
extern Brain *g_2e1e40;
extern Brain *g_2dd5bc;
extern Brain *g_2f7900;

extern "C" void RemoveSafePointsOfLo(void *sw, Lo *lo, Geom *geom)
{
    if (g_2e1e40 != 0)
        RemoveSafePoints(g_2e1e40 + 1, lo, geom);
    if (g_2dd5bc != 0)
        RemoveSafePoints(g_2dd5bc + 1, lo, geom);
    if (g_2f7900 != 0)
        RemoveSafePoints(g_2f7900 + 1, lo, geom);
    if (lo != 0)
        lo->grfo &= (~0UL ^ (1UL << 59));
    if (geom != 0)
        geom->grf &= (~0UL ^ (1UL << 51));
}
