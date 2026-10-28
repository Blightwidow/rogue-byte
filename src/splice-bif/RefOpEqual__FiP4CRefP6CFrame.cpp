struct CRef { int tagk; int n; CRef(const CRef &); ~CRef(); };
struct CFrame;
extern "C" CRef bevy_splice_bif_ref_equal(CRef *, CRef *);
CRef RefOpEqual__FiP4CRefP6CFrame(int cref, CRef *aref, CFrame *pframe)
{
    return bevy_splice_bif_ref_equal(aref, aref + 1);
}
