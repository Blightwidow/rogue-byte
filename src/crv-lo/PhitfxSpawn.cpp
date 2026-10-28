extern "C" void PhitfxSpawn_156548(int, int, int, int *);
extern "C" int PhitfxSpawn(int a, int b, int c)
{
    int result;
    PhitfxSpawn_156548(a, b, c, &result);
    return result;
}
