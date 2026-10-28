#include "sly2.h"
struct B8 { char b[8]; };
struct B9 { char b[9]; };
extern "C" {
int MemcardMenu_KindOfState(void *);
const char *PchzStringFromId(void *, int);
char *strcat(char *, const char *);
extern char B_002E6550[];
extern char B_003DD490[];
extern const B8 RO_STR_002A6E98;
extern const B9 RO_STR_002A6EA0;
extern char RO_STR_002A6EB0[];
extern char RO_002A6EB8[];
}
extern "C" void FormatDialogButtons(char *pchz)
{
    int nKind = MemcardMenu_KindOfState(B_002E6550);
    switch (nKind) {
    case 1:
        *(B8 *)pchz = RO_STR_002A6E98;
        strcat(pchz, PchzStringFromId(B_003DD490, 0x38));
        break;
    case 2:
        *(B9 *)pchz = RO_STR_002A6EA0;
        strcat(pchz, PchzStringFromId(B_003DD490, 0x36));
        strcat(pchz, RO_STR_002A6EB0);
        strcat(pchz, PchzStringFromId(B_003DD490, 0x37));
        strcat(pchz, RO_002A6EB8);
        break;
    }
}
