struct CByteQueue {
    void *pv0;
    int cb4;
    int n8, nC, p10, n14, n18, n1C;
    void Init(int cb, void *pv);
    void Reset();
};
void CByteQueue::Init(int cb, void *pv)
{
    cb4 = cb;
    pv0 = pv;
    Reset();
}
