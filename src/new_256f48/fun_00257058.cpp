void func_00257058(unsigned int** a0, unsigned int* a1)
{
    if (a1 != 0) {
        unsigned int v0 = *(unsigned int*)a1;
        v0 = v0 + 1;
        *(unsigned int*)a1 = v0;
    }
    *a0 = a1;
}
