extern "C" {
int S32Read__18CBinaryInputStream(int);
extern int B_003E1C30;
extern int B_003E1C54;
extern int B_003E1C58;

void func_0020F5D0(int flag, int stream) {
    int first = S32Read__18CBinaryInputStream(stream);
    int second = S32Read__18CBinaryInputStream(stream);
    B_003E1C30 = first;
    if (second != B_003E1C58) flag = 1;
    B_003E1C54 = flag;
    B_003E1C58 = second;
}
}
