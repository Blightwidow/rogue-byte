struct Item { char pad[8]; float key; };
int func_00194F48(Item *left, Item *right)
{
    float leftKey = left->key;
    float rightKey = right->key;
    if (leftKey < rightKey)
        return -1;
    return 1;
}
