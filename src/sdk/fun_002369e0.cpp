extern "C" {
int func_00239450(void);
void func_002394A0(void);
int func_00235B08(void *, char *, unsigned int, char *, char *);
int func_002368A0();
}
void snd_FormatVarargs(char *format, ...) {
    char *args;
    int buf[4];
    int wasFlagged;
    buf[0] = 0;
    wasFlagged = func_00239450();
    args = (char *)__builtin_next_arg(format) - 56;
    func_00235B08((void *)func_002368A0, (char *)buf, 0xFFFFFFFF, format, args);
    if (wasFlagged) {
        func_002394A0();
    }
}
