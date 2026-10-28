#include "sly2.h"
struct Node { int pad; unsigned low : 31; unsigned mark : 1; };
struct Stack { int count; Node **array; };
struct Gc { int gen; int pad4; int pad8; Stack procs; Stack pairs; };
struct Ref { int tagk; Node *pv; };
extern int g_2dd598;
void CGc_MarkRef(Gc *gc, Ref *ref)
{
    switch (ref->tagk) {
    case 0x1F: {
        Node *node = ref->pv;
        if (node->mark != g_2dd598) {
            node->mark = g_2dd598;
            int count = gc->procs.count;
            Node **array = gc->procs.array;
            array[count] = node;
            gc->procs.count = count + 1;
        }
        break;
    }
    case 0x20: {
        Node *node = ref->pv;
        if (node->mark != g_2dd598) {
            node->mark = g_2dd598;
            int count = gc->pairs.count;
            Node **array = gc->pairs.array;
            array[count] = node;
            gc->pairs.count = count + 1;
        }
        break;
    }
    case 0x22:
        ref->pv->mark = g_2dd598;
        break;
    }
}
