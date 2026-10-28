struct TFT { int fLeft; int pad4; int pad8; int padC; int fZero; int fPrecZero; int cchWidth; int cchPrecision; };
struct OSTRM { int CbWrite(void *pv, int cb); };
extern "C" unsigned int strlen(const char *);
extern "C" const char RO_STR_002A9370[];

static inline void WriteRepeat(OSTRM *postrm, char ch, int count)
{
    unsigned char buffer[16];
    buffer[0] = ch;
    while (count-- > 0) {
        if (postrm->CbWrite(buffer, 1) != 1)
            break;
    }
}

void WriteTftPchz(TFT *ptft, OSTRM *postrm, char *pchz)
{
    if (pchz == 0)
        pchz = (char *)RO_STR_002A9370;

    int padRight = 0;
    int length = strlen(pchz);
    int written = length;
    if (ptft->cchPrecision != 0 && ptft->cchPrecision < length) {
        written = ptft->cchPrecision;
    } else {
        if (ptft->fPrecZero != 0)
            written = 0;
    }

    int padLeft = 0;
    char pad = 0;
    if (written < ptft->cchWidth) {
        pad = ptft->fZero == 0 ? ' ' : '0';
        int total = ptft->cchWidth - written;
        if (ptft->fLeft != 0)
            padRight = total;
        else
            padLeft = total;
    }
    WriteRepeat(postrm, pad, padLeft);
    postrm->CbWrite(pchz, written);
    WriteRepeat(postrm, ' ', padRight);
}
