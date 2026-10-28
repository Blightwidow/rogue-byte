extern "C" void *memset(void *, int, unsigned int);
struct CFileLocation {
    int a, b;
    int kind;
    char flag;
    void Clear();
};
void CFileLocation::Clear()
{
    memset(this, 0, 8);
    flag = 0;
    kind = -1;
}
