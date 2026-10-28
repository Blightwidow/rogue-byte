extern "C" int ReadMemcardDirectory(int, int, int, int, int *);
int FindMemcardFile(int first, int second, int third)
{
    int found;
    int result = ReadMemcardDirectory(first, second, 1, third, &found);
    if (result)
        return result;
    return found == 1 ? 0 : 0xE;
}
