#include "sly2.h"
struct TFT { char pad[0x40]; };
struct OSTRM { char pad[0x10]; int cbTotal; int CbWrite(void *, int); };
extern "C" char *strchr(const char *, int);
extern "C" unsigned strlen(const char *);
int CchParsePchzTft(char *, TFT *, char **);
void WriteTft(TFT *, OSTRM *, char **, char *, int);

int CchOstrmPrintf(OSTRM *postrm, char *format, char *va)
{
    TFT tft;
    char *pva = va;
    if (*(unsigned char *)format != 0) {
        do {
            char *percent = strchr(format, '%');
            int literal = percent - format;
            if (percent == 0) {
                literal = strlen(format);
                percent = format + literal;
            }
            if (literal != 0) {
                int written = postrm->CbWrite(format, literal);
                format = percent;
                if (written < literal)
                    break;
            }
            if (*(unsigned char *)format == '%') {
                int spec = CchParsePchzTft(format, &tft, &pva);
                WriteTft(&tft, postrm, &pva, format, spec);
                format += spec;
            }
        } while (*(unsigned char *)format != 0);
    }
    return postrm->cbTotal;
}
