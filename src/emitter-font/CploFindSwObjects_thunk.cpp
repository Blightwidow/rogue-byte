extern "C" void CploFindSwObjects(int, int, int, int, int, int, int);
extern "C" void CploFindSwObjects_thunk(int a, int b, int c, int d, int e, int f)
{
    CploFindSwObjects(a, b, c, d, 0, e, f);
}
