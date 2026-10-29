struct CRef { int tagk; union { int n; float *pg; void *pv; }; int operator==(const CRef &);  };
int memcmp(const void *, const void *, unsigned int);
int CRef::operator==(const CRef &other)
{
    float *a;
    float *b;
    int result;
    float x;
    float y;
    if (tagk != other.tagk)
        return 0;
    switch (tagk) {
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
        return n == other.n;
    case 0x1B:
        return memcmp(pv, other.pv, 0x40) == 0;
    case 0x1D:
        a = pg;
        b = other.pg;
        result = 0;
        if (a[0] == b[0]) {
            x = a[1];
            y = b[1];
            if (x == y)
                result = 1;
        }
        return result;
    case 0x1A:
    case 0x1C:
    case 0x1E:
        a = pg;
        b = other.pg;
        result = 0;
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                x = a[2];
                y = b[2];
            check:
                if (x == y)
                    result = 1;
            }
        }
        return result;
    default:
        return 1;
    }
}
