int *func_00239558(int *start, int *end, int value)
{
    while (*start != value && start < end) {
        start++;
    }
    return start < end ? start : 0;
}
