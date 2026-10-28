class CBinaryInputStream { public: void Unknown1(); };
struct Xfm;
extern "C" void LoadXfmFromBrx(Xfm *, CBinaryInputStream *);
void func_00228720(Xfm *xfm, CBinaryInputStream *stream)
{
    LoadXfmFromBrx(xfm, stream);
    stream->Unknown1();
}
