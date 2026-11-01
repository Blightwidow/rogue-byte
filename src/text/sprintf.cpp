typedef char *va_list;
extern "C" {
int vsprintf(char *, const char *, va_list);
int sprintf(char *buffer, const char *format, ...) {
    va_list args = (va_list)__builtin_next_arg(format) - 48;
    return vsprintf(buffer, format, args);
}
}
