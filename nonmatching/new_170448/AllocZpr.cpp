struct CHUNK { int start; int end; CHUNK *next; };
struct ZPR { char pad[4]; int cur; char pad2[4]; CHUNK *free[8]; };
extern "C" int ICeilLog2(int);
extern "C" void FlushZprPage(ZPR *);
extern "C" int AllocZpr(ZPR *zpr, int count)
{
    int alloc;
    unsigned iclass = ICeilLog2(count - 1) + 1;
    int mask = -0x80;
    goto test;
loop:
    {
        CHUNK **afree = zpr->free;
        CHUNK **head = &afree[iclass];
        CHUNK *chunk = *head;
        if (chunk != 0) {
            alloc = chunk->start;
            chunk->start = alloc + count;
            if (chunk->start == chunk->end) {
                *head = chunk->next;
            } else {
                int rest = ICeilLog2(chunk->end - chunk->start);
                CHUNK **prest = &afree[rest];
                if (rest != iclass) {
                    *prest = chunk;
                    *head = chunk->next;
                    chunk->next = *prest;
                }
            }
            goto done;
        }
    }
    iclass++;
test:
    if (iclass < 8)
        goto loop;
    if (((zpr->cur + count) & mask) != (zpr->cur & mask))
        FlushZprPage(zpr);
    alloc = zpr->cur;
    zpr->cur = alloc + count;
done:
    return alloc;
}
