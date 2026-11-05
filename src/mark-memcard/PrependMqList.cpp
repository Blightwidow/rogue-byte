extern "C" {
struct MQ_1A9FE0 { char pad[0xAC]; struct MQ_1A9FE0 *pNext; };

void PrependMqList(void *unused, struct MQ_1A9FE0 *pList, struct MQ_1A9FE0 **ppHead)
{
    if (pList != 0) {
        struct MQ_1A9FE0 *pTail = pList;
        while (pTail->pNext != 0) {
            pTail = pTail->pNext;
        }
        pTail->pNext = *ppHead;
        *ppHead = pList;
    }
}
}
