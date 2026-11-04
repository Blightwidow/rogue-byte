struct CFontBrx;

class CRichText {
public:
    char pad[8];
    CFontBrx *font;
    void Reset();
    char ChNext();
    float DxMaxLine();
};

class CFontBrx {
public:
    float DxFromCh(char ch);
};

float CRichText::DxMaxLine() {
    float dxMax = 0.0f;
    float dxLine = 0.0f;
    char ch;
    this->Reset();
    while ((ch = this->ChNext()) != 0) {
        if (ch == '\n') {
            dxMax = (dxMax > dxLine) ? dxMax : dxLine;
            dxLine = 0.0f;
        } else {
            dxLine = dxLine + ((CFontBrx *)this->font)->DxFromCh(ch);
        }
    }
    dxMax = (dxMax > dxLine) ? dxMax : dxLine;
    return dxMax;
}
