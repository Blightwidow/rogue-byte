extern "C" int FMurrayOnFoot(char *self)
{
 int s = *(int *)(self + 0x13D0);
 switch (s) { case 0: case 1: case 9: case 10: return 1; } return 0;
}
