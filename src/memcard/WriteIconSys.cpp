// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SAVE;
// The memory card's icon.sys image (0x3C4 bytes), as WriteIconSys fills it.
struct ICONSYS {
    char achHead[4];
    unsigned short reserved1;
    unsigned short offsLf;
    unsigned int reserved2;
    unsigned int transRate;
    int bgColor[4][4];
    float lightDir[3][4];
    float lightColor[3][4];
    float ambient[4];
    unsigned short title[34];
    char fnameView[64];
    char fnameCopy[64];
    char fnameDel[64];
    char reserved3[512];
};
extern "C" {
void ConvertAsciiToSjis(const char *src, unsigned short *dest);
char *strcpy(char *, const char *);
int sprintf(char *, const char *, ...);
}
int WriteMemcardFile(SAVE *psave, const char *pchzPath, void *pvBuffer, int cb);
int WriteIconSys(SAVE *psave, const char *pchzDir, const char *pchzTitle)
{
    ICONSYS icon;
    char achPath[0x50];
    memset(&icon, 0, sizeof(icon));
    strcpy(icon.achHead, "PS2D");
    icon.offsLf = 0x20;
    icon.transRate = 0x60;
    icon.bgColor[0][0] = 0;
    icon.bgColor[0][1] = 0x87;
    icon.bgColor[0][2] = 0xFF;
    icon.bgColor[1][0] = 0;
    icon.bgColor[1][1] = 0x29;
    icon.bgColor[1][2] = 0x6F;
    icon.bgColor[2][0] = 0;
    icon.bgColor[2][1] = 0x29;
    icon.bgColor[2][2] = 0x6F;
    icon.bgColor[3][0] = 0;
    icon.bgColor[3][1] = 0x87;
    icon.bgColor[3][2] = 0xFF;
    icon.lightDir[0][0] = 0.0f;
    icon.lightDir[0][1] = 0.5f;
    icon.lightDir[0][2] = -0.5f;
    icon.lightDir[1][0] = 0.5f;
    icon.lightDir[1][1] = -0.4f;
    icon.lightDir[1][2] = 0.1f;
    icon.lightDir[2][0] = -0.5f;
    icon.lightDir[2][1] = 0.5f;
    icon.lightDir[2][2] = 0.5f;
    icon.lightColor[0][0] = 0.14f;
    icon.lightColor[0][1] = 0.03f;
    icon.lightColor[0][2] = 0.48f;
    icon.lightColor[1][0] = 0.33f;
    icon.lightColor[1][1] = 0.0f;
    icon.lightColor[1][2] = 0.33f;
    icon.lightColor[2][0] = 0.14f;
    icon.lightColor[2][1] = 0.14f;
    icon.lightColor[2][2] = 0.38f;
    icon.ambient[0] = 0.5f;
    icon.ambient[1] = 0.5f;
    icon.ambient[2] = 0.5f;
    ConvertAsciiToSjis(pchzTitle, icon.title);
    strcpy(icon.fnameView, "memcard_icon.ico");
    strcpy(icon.fnameCopy, "memcard_icon.ico");
    strcpy(icon.fnameDel, "memcard_icon.ico");
    sprintf(achPath, "%s/%s", pchzDir, "icon.sys");
    return WriteMemcardFile(psave, achPath, &icon, sizeof(icon));
}
