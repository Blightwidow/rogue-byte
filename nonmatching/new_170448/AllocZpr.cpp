struct CHUNK { int start; int end; CHUNK *next; };
struct ZPR { char pad[4]; int cur; char pad2[4]; CHUNK *free[8]; };
extern "C" int ICeilLog2(int);
extern "C" void FlushZprPage(ZPR *);
extern "C" int AllocZpr(ZPR *zpr, int count)
{
    int alloc;
    int mask = -0x80;
    unsigned iclass;
    for (iclass = ICeilLog2(count - 1) + 1; iclass < 8; iclass++) {
        CHUNK **head = &zpr->free[iclass];
        CHUNK *chunk = *head;
        if (chunk != 0) {
            alloc = chunk->start;
            chunk->start = alloc + count;
            if (chunk->start == chunk->end) {
                *head = chunk->next;
            } else {
                int rest = ICeilLog2(chunk->end - chunk->start);
                if (rest != iclass) {
                    *head = chunk->next;
                    chunk->next = zpr->free[rest];
                    zpr->free[rest] = chunk;
                }
            }
            goto done;
        }
    }
    if (((zpr->cur + count) & mask) != (zpr->cur & mask))
        FlushZprPage(zpr);
    alloc = zpr->cur;
    zpr->cur = alloc + count;
done:
    return alloc;
}
