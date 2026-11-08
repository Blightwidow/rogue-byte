int func_002345B8(int character);
int StricmpPchz(char *left, char *right)
{
    while (*left != 0 && func_002345B8(*left) == func_002345B8(*right)) {
        left++;
        right++;
    }
    return func_002345B8(*(unsigned char *)left) - func_002345B8(*(unsigned char *)right);
}
