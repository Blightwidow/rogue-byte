typedef char *va_list;
extern "C" {
int vprintf(const char *, va_list);
int printf(const char *format, ...) {
    va_list args = (va_list)__builtin_next_arg(format) - 56;
    return vprintf(format, args);
}
}
