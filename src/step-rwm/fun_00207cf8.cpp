extern "C" {
int GrfsgsFromRef(void *);
void *PguardanimEnsure(void *, int);
void func_00207C48(void *, void *, int, int, int, int);
void BindAnimref(void *, void *);
}
void func_00207CF8(void *a, void *b, int c, int d, int e, int f)
{
    void *p = PguardanimEnsure(a, GrfsgsFromRef(b));
    func_00207C48(a, b, c, d, e, f);
    BindAnimref(p, a);
}
