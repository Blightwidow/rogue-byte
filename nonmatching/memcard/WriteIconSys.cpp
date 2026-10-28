#include "sly2.h"
struct B17 { char b[17]; };
struct ICON {
    int magic; short pad4; short nl;
    char pad8[4]; int trans;
    int bg[4][4];
    float dir[3][4];
    float col[3][4];
    float amb[4];
    char title[0x44];
    B17 view; char padv[0x40 - 17];
    B17 copy; char padc[0x40 - 17];
    B17 del; char padd[0x3C4 - 0x184 - 17];
};
struct SAVE;
extern "C" {
extern const char RO_002A6C98[];
extern const B17 RO_002A6CA0;
extern const char RO_002A6CB8[];
extern const char RO_STR_002A6CC0[];
void ConvertAsciiToSjis(const char *, char *);
int sprintf(char *, const char *, ...);
int WriteMemcardFile(SAVE *, char *, void *, int);
}
int WriteIconSys(SAVE *psave, const char *pchzDir, const char *pchzTitle)
{
    ICON icon;
    char path[0x50];
    memset(&icon, 0, 0x3C4);
    icon.col[0][2] = 0.48f;
    icon.magic = *(const int *)RO_002A6C98;
    *((char *)&icon.magic + 4) = RO_002A6C98[4];
    icon.dir[2][2] = 0.5f;
    icon.trans = 0x60;
    icon.bg[0][1] = 0x87;
    icon.bg[3][1] = 0x87;
    icon.bg[1][1] = 0x29;
    icon.nl = 0x20;
    icon.bg[1][2] = 0x6F;
    icon.bg[2][1] = 0x29;
    icon.bg[2][2] = 0x6F;
    icon.bg[1][0] = 0;
    icon.bg[3][2] = 0xFF;
    icon.bg[2][0] = 0;
    icon.bg[3][0] = 0;
    icon.dir[0][0] = 0.0f;
    icon.bg[0][2] = 0xFF;
    icon.dir[0][1] = 0.5f;
    icon.dir[1][1] = -0.4f;
    icon.dir[0][2] = -0.5f;
    icon.dir[1][0] = 0.5f;
    icon.dir[1][2] = 0.1f;
    icon.dir[2][0] = -0.5f;
    icon.dir[2][1] = 0.5f;
    icon.bg[0][0] = 0;
    icon.col[0][0] = 0.14f;
    icon.col[0][1] = 0.03f;
    icon.col[1][0] = 0.33f;
    icon.col[1][1] = 0.0f;
    icon.col[1][2] = 0.33f;
    icon.col[2][0] = 0.14f;
    icon.col[2][1] = 0.14f;
    icon.col[2][2] = 0.38f;
    icon.amb[0] = 0.5f;
    icon.amb[1] = 0.5f;
    icon.amb[2] = 0.5f;
    ConvertAsciiToSjis(pchzTitle, icon.title);
    icon.view = RO_002A6CA0;
    icon.copy = RO_002A6CA0;
    icon.del = RO_002A6CA0;
    sprintf(path, RO_002A6CB8, pchzDir, RO_STR_002A6CC0);
    return WriteMemcardFile(psave, path, &icon, 0x3C4);
}
