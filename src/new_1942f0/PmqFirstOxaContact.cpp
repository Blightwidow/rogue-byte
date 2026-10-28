struct Node { int value; Node *next; };
int PmqFirstOxaContact(char *self)
{
    int value = 0;
    for (Node *node = *(Node **)(self + 0x64); node; node = node->next) {
        value = node->value;
        if (value)
            return value;
    }
    return 0;
}
