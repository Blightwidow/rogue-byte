extern "C" int PrefFindBinding__6CFrameUii(int, unsigned int, int);
extern "C" void __as__4CRefRC4CRef(int, int);
int FFindBinding__6CFrameUiiP4CRef(int a0, unsigned int a1, int a2, int a3)
{
    int v0;
    v0 = PrefFindBinding__6CFrameUii(a0, a1, a2);
    if (v0 == 0) {
        return 0;
    }
    if (a3 != 0) {
        __as__4CRefRC4CRef(a3, v0);
    }
    return 1;
}
