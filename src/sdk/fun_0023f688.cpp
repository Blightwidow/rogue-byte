// SPDX-License-Identifier: GPL-3.0-or-later
struct Block_23F688 {
    int offsetToNext;
    int used;
    unsigned start;
    unsigned size;
};
struct BlockList_23F688 {
    Block_23F688 **blocks;
    int count;
};
extern "C" void func_0023F688(Block_23F688 *block, BlockList_23F688 *list, unsigned *lowest, unsigned *highest)
{
    unsigned low = *lowest;
    unsigned high = *highest;
    if (block->offsetToNext != 0) {
        do {
            if (block->used != 0 && block->start != 0) {
                int index = list->count;
                list->blocks[index] = block;
                list->count = index + 1;
                unsigned start = block->start;
                unsigned end = start + block->size;
                low = start < low ? start : low;
                high = high < end ? end : high;
            }
            block = (Block_23F688 *)((char *)block + block->offsetToNext + 4);
        } while (block->offsetToNext != 0);
    }
    *lowest = low;
    *highest = high;
}
