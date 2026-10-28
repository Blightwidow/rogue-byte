void func_001816C0(char *self, unsigned index, int first, int second)
{
    if (index < 3) {
        char *firstBase = self + 0x1D0;
        char *secondBase = self + 0x1DC;
        *(int *)(firstBase + index * 16) = first;
        *(int *)(secondBase + index * 16) = second;
    }
}
