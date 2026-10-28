extern "C" int strlen(const char *);
extern "C" unsigned SjisFromAsciiChar(unsigned);
extern "C" void ConvertAsciiToSjis(const char *src, unsigned short *dest)
{
int ich = 0; int cch = strlen(src); for (; ich < cch; ich++) { unsigned w = SjisFromAsciiChar((unsigned char)src[ich]); unsigned lo = (w & 0xFF) << 8; dest[ich] = ((w >> 8) & 0xFF) | lo; } dest[ich] = 0;
}
