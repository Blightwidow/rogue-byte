#define McTail(value, high, low) ((value) >= (low) ? 0x1F : (high))
extern "C" int McErrorFromResult(int a, int b)
{
    int r;
    switch (a) {
    case 1:
        switch (b) {
        case 0: return 0;
        case -1: return 9;
        case -2: return 10;
        case -5: return 11;
        }
        return McTail(b, 11, -9);
    case 2:
        switch (b) {
        case -2: return 12;
        case -3: return 1;
        case -4: return 13;
        case -5: return 6;
        case -7: return 25;
        }
        if (b >= 0) return 0;
        return McTail(b, 11, -9);
    case 3:
        switch (b) {
        case 0: return 0;
        case -2: return 12;
        case -4: return 16;
        }
        return McTail(b, 11, -9);
    case 4:
        switch (b) {
        case -2: return 12;
        case -4: return 16;
        }
        if (b >= 0) return 0;
        return McTail(b, 11, -9);
    case 5:
        switch (b) {
        case -2: return 12;
        case -4: return 16;
        case -5: return 17;
        }
        if (b >= 0) return 0;
        return McTail(b, 11, -9);
    case 6:
        switch (b) {
        case -2: return 12;
        case -3: return 1;
        case -4: return 16;
        case -5: return 18;
        case -8: return 26;
        }
        if (b >= 0) return 0;
        return McTail(b, 11, -9);
    case 10:
        switch (b) {
        case 0: return 0;
        case -2: return 12;
        case -4: return 16;
        }
        return McTail(b, 11, -9);
    case 11:
        switch (b) {
        case 0: return 0;
        case -2: return 12;
        case -3: return 1;
        case -4: return 24;
        }
        return McTail(b, 11, -9);
    case 12:
        switch (b) {
        case 0: return 0;
        case -2: return 12;
        case -4: return 21;
        }
        return McTail(b, 11, -9);
    case 13:
        switch (b) {
        case -2: return 12;
        case -4: return 21;
        }
        if (b >= 0) return 0;
        return McTail(b, 11, -9);
    case 14:
        switch (b) {
        case 0: return 0;
        case -2: return 12;
        case -4: return 22;
        }
        return McTail(b, 11, -9);
    case 15:
        switch (b) {
        case 0: return 0;
        case -2: return 12;
        case -4: return 14;
        case -5: return 19;
        case -6: return 23;
        }
        return McTail(b, 11, -9);
    case 16:
        r = 0;
        if (b != 0) return McTail(b, 4, 0);
        break;
    case 17:
        r = 0;
        if (b != 0) return McTail(b, 5, 0);
        break;
    case 18:
        switch (b) {
        case -2: return 12;
        }
        if (b >= 0) return 0;
        return McTail(b, 11, -9);
    case 19:
        switch (b) {
        case 0: return 0;
        case -2: return 12;
        case -4: return 22;
        }
        return McTail(b, 11, -9);
    case 20:
        switch (b) {
        case 0: return 0;
        case -403: return 35;
        }
        return 31;
    case 21:
        if (b >= 0) return 0;
        if ((unsigned)(b + 100) < 100) return 31;
        return McTail(b, 30, -99);
    default:
        r = 31;
        break;
    }
    return r;
}
