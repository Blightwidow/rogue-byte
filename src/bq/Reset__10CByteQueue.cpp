struct CByteQueue {
 void *pv0; int cb4; int n8,nC,n10,n14,n18,n1C; void Reset();
};
void CByteQueue::Reset()
{
    n10 = cb4;
    n18 = 0;
    n14 = 0;
    nC = 0;
    n8 = 0;
    n1C = 0;
}
