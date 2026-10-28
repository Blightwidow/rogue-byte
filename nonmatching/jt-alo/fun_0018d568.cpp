typedef struct { char pad[0x18]; } JT;

void SetJtState(JT *pjt, int state, int arg);
void func_0018D598(JT *jt, int state, int arg);

typedef void (*JtThunk)(JT *, int);
extern "C" JtThunk jtbl_002A5D00[9];

void SetJtStateFromKind(JT *pjt, unsigned int nKind)
{
    if (nKind < 9) {
        JtThunk t = jtbl_002A5D00[nKind];
        t(pjt, -1);
    }
}
