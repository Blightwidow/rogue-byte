struct World_3DD490 { char pad[0x3D60]; int stamp; };
extern World_3DD490 B_003DD490;
extern "C" void func_001A4478(World_3DD490 *, int, void *);
extern "C" void func_001F3C10(char *self)
{
    char *node = *(char **)(self + 0x134);
    if (node != 0 && *(int *)(node + 0xC) != B_003DD490.stamp) {
        func_001A4478(&B_003DD490, 0, node);
        *(int *)(*(char **)(self + 0x134) + 0xC) = B_003DD490.stamp;
    }
}
