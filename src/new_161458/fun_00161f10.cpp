struct Pair { int first; int second; };
int func_00161F10(int unused, Pair *items, int maximum, int *count, int first, int second)
{
    int n = *count; int next = n + 1; if (n < maximum) { *count = next; Pair *item = items + n; item->first = first; item->second = second; return 1; } return 0;
}
