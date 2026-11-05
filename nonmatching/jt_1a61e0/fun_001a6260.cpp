struct Link { int pad[1]; Link *next; int value; int pad2; char *owner; };
int func_001A6260(char *self)
{
    int result = -1;
    for (Link *link = *(Link **)(self + 0x3C); link && link->owner == self; link = link->next)
        result = link->value;
    return result;
}
