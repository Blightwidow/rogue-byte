extern "C" const unsigned short g_2a4fd0;
extern "C" const char RO_002A4FD8[];
extern "C" const char RO_002A4FE0[];
extern "C" const char RO_002A4FE8[];
extern "C" char *strcat(char *, const char *);
extern "C" unsigned strlen(const char *);
extern "C" int sprintf(char *, const char *, ...);
int CpchzTokenizePath__FPc(char *);
void CdPath__FPcT0i(char *out, char *path, int cdrom)
{
    char buf[256];
    int index = 1;
    *(unsigned short *)buf = g_2a4fd0;
    strcat(buf, path);
    int count = CpchzTokenizePath__FPc(buf);
    char *cursor = buf;
    for (; index < count; index++) {
        cursor[strlen(cursor)] = '\\';
    }
    const char *format = RO_002A4FD8;
    const char *prefix;
    if (cdrom) prefix = RO_002A4FE0; else prefix = RO_002A4FE8;
    sprintf(out, format, prefix, buf);
}
