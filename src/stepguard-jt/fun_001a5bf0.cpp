extern "C" int FIsBasicDerivedFrom(char *, int);
char *func_001A5BF0(char *self)
{
    if (FIsBasicDerivedFrom(self, 0x30))
        return self;
    return *(char **)(self + 0x10);
}
