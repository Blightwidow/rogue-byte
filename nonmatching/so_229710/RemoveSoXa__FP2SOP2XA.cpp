typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64;
#define NULL 0
struct XA_229738 { char pad[8]; XA_229738 *next; };
struct SO_229738 { char pad[0x138]; XA_229738 *head; };
extern "C" {
void func_001F5078(SO_229738 *, XA_229738 *);
void RemoveSoXa__FP2SOP2XA(SO_229738 *so, XA_229738 *xa) {
    XA_229738 **link = &so->head;
    XA_229738 *node = *link;
    XA_229738 *prev;
    if (node != NULL) {
        if (node == xa) {
            so->head = xa->next;
            xa->next = NULL;
        } else {
            for (;;) {
                prev = *link;
                link = &prev->next;
                node = *link;
                if (node == NULL) break;
                if (node != xa) continue;
                prev->next = xa->next;
                xa->next = NULL;
                break;
            }
        }
    }
    func_001F5078(so, xa);
}
}
