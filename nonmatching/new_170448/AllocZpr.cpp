// SPDX-License-Identifier: GPL-3.0-or-later
// AllocZpr (0x170548): size-class allocator. iclass = ICeilLog2(count - 1) + 1; scan zpr->free[iclass..7] for a chunk,
// take count bytes from its start, unlink it when exhausted, else move it to free[ICeilLog2(end - start)] when that class
// differs; with no chunk, flush the page (FlushZprPage(zpr), retail passes s3 in a0) when cur..cur+count crosses 0x80, then
// bump-allocate from zpr->cur. Retail enters the scan with `b` to the bottom test and recomputes zpr+0xC each iteration
// (s6, reused for free[rest] across the second call): no loop notes, so the scan is a goto loop (for/while hoist and
// strength-reduce, 45). The rest block unlinks before relinking (*head = next; chunk->next = *prest; *prest = chunk).
// Still differs (score 21): global-alloc priority puts zpr (6 refs over 25 insns) ahead of head (4 over 18), so zpr/head
// take s2/s3 where retail has s3/s2; the search draft's 10 came from dropping FlushZprPage's argument (5 refs) and from
// storing *prest = chunk before reading it (a self-loop): both wrong behaviour. Also: the loop top emits zpr+0xC before
// iclass*4 (retail the shift first, stolen into the bnez slot) and the rest block puts the free[rest] add in the beq slot
// (retail the shift); prest inside the if gets that slot right but moves rest to v1 (24).
struct CHUNK { int start; int end; CHUNK *next; };
struct ZPR { char pad[4]; int cur; char pad2[4]; CHUNK *free[8]; };
extern "C" int ICeilLog2(int);
extern "C" void FlushZprPage(ZPR *zpr);
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
                    *head = chunk->next;
                    chunk->next = *prest;
                    *prest = chunk;
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
