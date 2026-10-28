extern "C" int FMurrayOnFoot(char *self)
{
 int s = *(int *)(self + 0x13D0);
 if (s >= 0) { if (s < 2 || (s < 0xB && s > 8)) return 1; } return 0;
}
