#include "sly2.h"
struct ENT { int id; int b; };
struct SHOP { char p0[0x4C]; ENT aent[1]; };
struct GADGET { char p[0x14]; int sid; char q[8]; };
extern char B_003DA150[];
extern GADGET D_002BCD00[];
extern char B_003DD490[];
extern "C" char *PchzStringFromId__FP2SWi(void *, int);
extern "C" char *strcpy(char *, const char *);
void GetShopRowName(char *out, int row)
{
    SHOP *shop = (SHOP *)B_003DA150;
    unsigned gadget = shop->aent[*(int *)(B_003DA150 + 0x250) + row].id;
    int sid = -1;
    if (gadget < 0x2B)
        sid = D_002BCD00[gadget].sid;
    if (sid != -1)
        strcpy(out, PchzStringFromId__FP2SWi(B_003DD490, sid));
    else
        out[0] = 0;
}
