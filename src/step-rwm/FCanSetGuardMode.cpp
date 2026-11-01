extern "C" {
struct Guard206EB0;
struct Class206EB0 { char pad[0x4C]; int field4C; };
int FIsBasicDerivedFrom(Guard206EB0 *, int);
int FIsGuardInSgs(Guard206EB0 *, int);
int FIsGuardSpecialClass(Guard206EB0 *);
Class206EB0 *func_00205458(Guard206EB0 *, int);
int FCanSetGuardMode(Guard206EB0 *guard, int mode)
{
    int result;
    if (mode == -1) return 1;
    if (FIsGuardInSgs(guard, 7) != 0) return 0;
    Class206EB0 *entry = func_00205458(guard, 0xA9);
    if (entry != 0) {
        if (entry->field4C != 0) return 0;
    }
    switch (mode - 8) {
    case 0:
    case 5:
    case 6:
        return 1;
    case 13:
        result = 0;
        if (FIsBasicDerivedFrom(guard, 0x3E) != 0) goto done;
        if (FIsBasicDerivedFrom(guard, 0x42) != 0) goto done;
        result = FIsBasicDerivedFrom(guard, 0x43) == 0;
        goto done;
    case 26:
    case 29:
        return FIsGuardSpecialClass(guard) == 0;
    case 3:
        result = 0;
        if (FIsBasicDerivedFrom(guard, 0x3B) != 0) goto done;
        if (FIsBasicDerivedFrom(guard, 0x3D) != 0) goto done;
        if (FIsBasicDerivedFrom(guard, 0x40) != 0) goto done;
        if (FIsBasicDerivedFrom(guard, 0x3E) != 0) goto done;
        if (FIsBasicDerivedFrom(guard, 0x41) != 0) goto done;
        if (FIsBasicDerivedFrom(guard, 0x3F) != 0) goto done;
        if (FIsBasicDerivedFrom(guard, 0x3C) != 0) goto done;
        if (FIsBasicDerivedFrom(guard, 0x42) != 0) goto done;
        result = FIsBasicDerivedFrom(guard, 0x43) == 0;
    done:
        return result;
    default:
        return 0;
    }
}
}
