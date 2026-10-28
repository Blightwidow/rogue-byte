extern "C" int FSwBinocActive(void *);
extern "C" char B_003DD490;
int func_00209098(void *object)
{
    if (*(int *)((char *)object + 0xFC8) != 0) return 1;
    return FSwBinocActive(&B_003DD490);
}
