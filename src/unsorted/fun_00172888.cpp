#include "sly2.h"
struct OBJ { char pad[0x10]; float key; };
int func_00172888(OBJ *a, OBJ *b)
{
    return a->key < b->key;
}
