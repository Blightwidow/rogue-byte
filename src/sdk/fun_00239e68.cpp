typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
extern "C" {
struct SortNode_239E68 { SortNode_239E68 *next; SortNode_239E68 *prev; s32 pad[2]; u64 a; u64 b; u64 c; };
struct SortList_2C5A30 { char pad[0x18]; SortNode_239E68 *head; };
extern SortList_2C5A30 D_002C5A30;
void func_00239E68(SortNode_239E68 *node) {
    SortNode_239E68 *prev = 0;
    SortNode_239E68 *cur = D_002C5A30.head;
    u64 key = node->c + node->a - node->b;
    while (cur != 0 && key >= cur->c + cur->a - cur->b) {
        prev = cur;
        cur = prev->next;
    }
    node->prev = prev;
    node->next = cur;
    if (cur != 0) {
        cur->prev = node;
    }
    if (prev != 0) {
        prev->next = node;
        return;
    }
    D_002C5A30.head = node;
}
}
