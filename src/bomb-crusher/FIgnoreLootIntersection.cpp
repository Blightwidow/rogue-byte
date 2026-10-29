extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int FIgnoreSoIntersection(void *, void *);

int FIgnoreLootIntersection(char *arg0, char *arg1) {
    if (*(int *)(arg0 + 0x184) == 5) {
        if (FIsBasicDerivedFrom(*(void **)*(char **)(arg1 + 0x14), 0x34)) {
            return 3;
        }
    }
    return FIgnoreSoIntersection(arg0, arg1);
}
