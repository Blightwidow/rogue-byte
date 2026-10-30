extern "C" int McErrorFromResult(int arg0, int arg1)
{
    switch (arg0) {
    case 1:
        if (arg1 == -2)
            return 0xA;
        if (arg1 < -1) {
            if (arg1 == -5)
                return 0xB;
            goto fallback;
        }
        if (arg1 == -1)
            return 9;
        goto zeroOrFallback;
    case 2:
        switch (arg1) {
        case -3: return 1;
        case -4: return 0xD;
        case -5: return 6;
        case -7: return 0x19;
        case -2: return 0xC;
        }
        goto nonNegativeOrFallback;
    case 4:
        if (arg1 == -4)
            return 0x10;
        if (arg1 == -2)
            return 0xC;
        goto nonNegativeOrFallback;
    case 5:
        if (arg1 == -4)
            return 0x10;
        if (arg1 == -5)
            return 0x11;
        goto nonNegativeOrFallback;
    case 6:
        switch (arg1) {
        case -3: return 1;
        case -4: return 0x10;
        case -5: return 0x12;
        case -8: return 0x1A;
        case -2: return 0xC;
        }
        goto zeroOrFallback;
    case 3:
    case 10:
        if (arg1 == -2)
            return 0xC;
        if (arg1 >= -1)
            goto zeroOrFallback;
        if (arg1 == -4)
            return 0x10;
        goto fallback;
    case 11:
        if (arg1 == -3)
            return 1;
        if (arg1 == -2)
            return 0xC;
        if (arg1 == -4)
            return 0x18;
        if (arg1 >= -1)
            goto nonNegativeOrFallback;
        goto fallback;
    case 12:
        if (arg1 == -2)
            return 0xC;
        if (arg1 < -1) {
            if (arg1 == -4)
                return 0x15;
            goto fallback;
        }
        goto zeroOrFallback;
    case 13:
        if (arg1 == -4)
            return 0x15;
        if (arg1 == -2)
            return 0xC;
        goto nonNegativeOrFallback;
    case 14:
        if (arg1 == -2)
            return 0xC;
        if (arg1 < -1) {
            if (arg1 == -4)
                return 0x16;
            goto fallback;
        }
        goto zeroOrFallback;
    case 15:
        switch (arg1) {
        case -4: return 0xE;
        case -5: return 0x13;
        case -6: return 0x17;
        case -2: return 0xC;
        }
        goto fallback;
    case 16:
        if (arg1 == 0)
            return 0;
        return arg1 < 0 ? 4 : 0x1F;
    case 17:
        if (arg1 == 0)
            return 0;
        return arg1 < 0 ? 5 : 0x1F;
    case 18:
        if (arg1 == -2)
            return 0xC;
        goto nonNegativeOrFallback;
    case 19:
        if (arg1 == -2)
            return 0xC;
        if (arg1 >= -1)
            goto zeroOrFallback;
        if (arg1 == -4)
            return 0x16;
        goto fallback;
    case 20:
        if (arg1 == -0x193)
            return 0x23;
        if (arg1 == 0)
            return 0;
        return 0x1F;
    case 21:
        if (arg1 < 0) {
            if ((unsigned)(arg1 + 0x64) < 0x64U)
                return 0x1F;
            return arg1 < -0x63 ? 0x1E : 0x1F;
        }
        return 0;
    default:
        return 0x1F;
    }
zeroOrFallback:
    if (arg1 == 0)
        return 0;
    goto fallback;
nonNegativeOrFallback:
    if (arg1 >= 0)
        return 0;
fallback:
    return arg1 < -9 ? 0xB : 0x1F;
}
