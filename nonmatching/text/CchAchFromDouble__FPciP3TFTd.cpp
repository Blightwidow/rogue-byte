/* the double argument travels in a 64-bit register: the callees below are declared on its bits (long) */
extern "C" {
int ChDigitFromG__Fdii(long, int, int);
int ExpFirstFromG__Fd(long);
long __adddf3(long, long);
int __fixdfsi(long);
long __floatsidf(int);
long __muldf3(long, long);
long pow(long, long);
char *strcpy(char *, const char *);
unsigned strlen(const char *);
extern unsigned char D_002C40C8[];
struct Tft_21E1B0 { char pad0[0x14]; int flag14; char pad18[4]; int precision; char pad20[0xC]; unsigned char kind; };
int CchAchFromDouble__FPciP3TFTd(char *out, int unused, Tft_21E1B0 *tft, long bits) {
    long mask = 0x7FF0000000000000L;
    if ((bits & mask) == mask) {
        const char *text;
        if (bits & 0xFFFFFFFFFFFFFL) {
            text = "(nan)";
        } else {
            text = "(inf)";
        }
        strcpy(out, text);
        return strlen(out);
    }
    char *cursor = out;
    unsigned char kind = tft->kind;
    int exponent = ExpFirstFromG__Fd(bits);
    int scientific = kind == 'e';
    if (kind == 'g') {
        if (exponent < -4 || exponent >= tft->precision) {
            scientific = 1;
            tft->precision = tft->precision - 1;
        }
    }
    long rounded = __adddf3(bits, __muldf3(pow(0x4024000000000000L, __floatsidf((scientific != 0 ? exponent : 0) - tft->precision)), 0x3FE0000000000000L));
    int roundedExponent = ExpFirstFromG__Fd(rounded);
    int top = exponent < roundedExponent ? roundedExponent : exponent;
    int count;
    int digitExponent;
    if (scientific != 0) {
        count = 1;
        digitExponent = top;
    } else {
        digitExponent = top;
        if (top >= 0) {
            count = top + 1;
        } else {
            count = 1;
            digitExponent = 0;
        }
    }
    int remaining = count - 1;
    if (count > 0) {
        do {
            int place = digitExponent;
            digitExponent -= 1;
            *cursor = ChDigitFromG__Fdii(rounded, top, place);
            cursor += 1;
            remaining -= 1;
        } while (remaining > 0);
    }
    if (tft->flag14 == 0) {
        *cursor = '.';
        cursor += 1;
        int fraction = tft->precision;
        int left = fraction - 1;
        if (fraction > 0) {
            do {
                int place = digitExponent;
                digitExponent -= 1;
                *cursor = ChDigitFromG__Fdii(rounded, top, place);
                cursor += 1;
                left -= 1;
            } while (left > 0);
        }
        if (tft->kind == 'g') {
            while (out < cursor && cursor[-1] == '0') {
                cursor -= 1;
            }
            if (out < cursor && cursor[-1] == '.') {
                cursor -= 1;
            }
        }
    }
    if (scientific != 0) {
        cursor[0] = 'e';
        char sign;
        if (top < 0) {
            sign = '-';
            top = -top;
        } else {
            sign = '+';
        }
        cursor[1] = sign;
        cursor = cursor + 2;
        int divisor = __fixdfsi(pow(0x4024000000000000L, 0x4000000000000000L));
        int digits = 2;
        do {
            digits -= 1;
            unsigned char digit = D_002C40C8[top / divisor];
            top = (top % divisor) * 10;
            *cursor = digit;
            cursor += 1;
        } while (digits >= 0);
    }
    return cursor - out;
}
}
