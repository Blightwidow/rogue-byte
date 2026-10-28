#include "sly2.h"
extern "C" {
void UpperizePchz__FPc(char *);
unsigned int strlen(const char *);
char *strcat(char *, const char *);
extern const char RO_STR_002A4F00[];
}

extern "C" int CpchzTokenizePath__FPc(char *pchzPath)
{
    UpperizePchz__FPc(pchzPath);
    int cch = strlen(pchzPath);
    if (cch != 0 && (unsigned char)pchzPath[cch - 1] != '\\' && (unsigned char)pchzPath[cch - 1] != '/') {
        strcat(pchzPath, RO_STR_002A4F00);
        cch = strlen(pchzPath);
    }
    unsigned char *pbEnd = (unsigned char *)pchzPath + cch;
    unsigned char *pbRead = (unsigned char *)pchzPath;
    char *pchWrite = pchzPath;
    int cComponent = 0;
    int cchComponent = 0;
    int cchMax = 8;
    while (pbRead < pbEnd) {
        unsigned char ch = *pbRead;
        if (ch == '/' || ch == '\\') {
            if (cchComponent != 0) {
                *pchWrite++ = 0;
                cchComponent = 0;
                cchMax = 8;
                cComponent++;
            }
            pbRead++;
            continue;
        }
        if (ch == '.') {
            if (cchComponent != 0 && cchMax == 8) {
                *pchWrite++ = '.';
                cchComponent = 0;
                cchMax = 3;
            }
            pbRead++;
            continue;
        }
        if (ch == ';' && cchComponent != 0 && pbRead == pbEnd - 2 && pbRead[1] == '1') {
            pchWrite[0] = (char)pbEnd[-2];
            pchWrite[1] = (char)pbEnd[-1];
            pchWrite += 2;
            cchComponent += 2;
            pbRead = pbEnd;
            continue;
        }
        if (cchComponent < cchMax) {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
                *pchWrite = (char)ch;
            else
                *pchWrite = '_';
            pchWrite++;
            cchComponent++;
        }
        pbRead++;
    }
    return cComponent;
}
