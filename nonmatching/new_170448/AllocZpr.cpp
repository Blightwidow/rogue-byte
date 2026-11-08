// SPDX-License-Identifier: GPL-3.0-or-later
// AllocZpr (0x170548): size-class allocator. Retail enters the scan with `b` to the bottom test
// (sltiu, unsigned), recomputes zpr+0xC every iteration and keeps it in s6 across the second
// ICeilLog2 call: no loop notes, no hoisting or strength reduction, so the scan is a goto loop
// (for/while give a duplicated top test and a running pointer, 45-53). The 0x80-page mask is
// loaded into a0 before the loop: a local set after the first call. FlushZprPage takes the ZPR
// (retail passes s3 in a0; its own source is src/new_170448/FlushZprPage.cpp).
// Still differs (score 21): zpr/head take s2/s3 where retail has s3/s2 (global-alloc priority:
// zpr 6 refs over 25 insns beats head 4 refs over 18), the loop top emits addiu s6 before
// sll (retail sll first, into the bnez delay slot), and the rest block's registers.
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
