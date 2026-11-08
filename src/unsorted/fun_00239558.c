// Word search over [start, end], returning the first word equal to value only if it is below end (else 0). Both exits (found, or past end)
// share one final `start < end ? start : 0`: the loop breaks out and does not return 0 early, which is what gives retail's single shared
// `movz` tail (an early `return 0` scored 13 to 16).
int *func_00239558(int *start, int *end, int value)
{
    while (*start != value && start < end) {
        start++;
    }
    return start < end ? start : 0;
}
