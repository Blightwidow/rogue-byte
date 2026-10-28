void Chaser_SetStateAnim(char *self, unsigned index, int first, int second)
{
    if (index < 5) {
        char *firstBase = self + 0x220;
        char *secondBase = self + 0x22C;
        *(int *)(firstBase + index * 16) = first;
        *(int *)(secondBase + index * 16) = second;
    }
}
