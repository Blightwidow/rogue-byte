// SPDX-License-Identifier: GPL-3.0-or-later
extern unsigned char RO_002AA6A1[];

long func_00234350(int *perrno, const char *nptr, char **endptr, int base)
{
    const char *s = nptr;
    unsigned long acc;
    unsigned long cutoff;
    int c;
    int neg = 0;
    int any;
    int cutlim;

    do {
        c = *s++;
    } while (RO_002AA6A1[c] & 8);
    if (c == '-') {
        c = *s;
        neg = 1;
        s++;
    } else if (c == '+') {
        c = *s++;
    }
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        base = 16;
        s += 2;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = neg ? (-1L << 63) : ((unsigned long)-1 >> 1);
    cutlim = cutoff % (unsigned long)base;
    cutoff /= (unsigned long)base;
    any = 0;
    acc = 0;
    for (;; c = *s++) {
        if (RO_002AA6A1[c] & 4)
            c -= '0';
        else if (RO_002AA6A1[c] & 3)
            c -= (RO_002AA6A1[c] & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? (-1L << 63) : ((unsigned long)-1 >> 1);
        *perrno = 0x22;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char *)(any ? s - 1 : nptr);
    return acc;
}
