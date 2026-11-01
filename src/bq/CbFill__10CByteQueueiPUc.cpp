struct INPUT_13D7D0 { void *vt; unsigned char *pb; int cb; int pos; int cbLeft; };
struct CQueueInput;
extern char D_002CBE20[];
struct CByteQueue {
    char pad[0x20];
    int CbFill(int cbMax, CQueueInput *pinput);
    int CbFill(int cb, unsigned char *pb);
};
int CByteQueue::CbFill(int cb, unsigned char *pb)
{
    int result;
    if (cb == 0)
        result = 0;
    else {
        INPUT_13D7D0 input;
        input.vt = D_002CBE20;
        input.pb = pb;
        input.cbLeft = cb;
        input.cb = cb;
        input.pos = 0;
        result = CbFill(cb, (CQueueInput *)&input);
    }
    return result;
}