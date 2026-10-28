extern "C" int sprintf(char *, const char *, ...);
struct TXT { char pad[0x4764]; int cur; int max; };
extern TXT B_003DD490;
void BindTextCounts(char *text)
{
    sprintf(text, "%d/%d", B_003DD490.cur, B_003DD490.max);
}
