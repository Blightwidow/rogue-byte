extern char B_00448D50[];
extern int D_002C49EC;
void func_0023AA40(char *text);
void func_002357B8(int character)
{
    int index = D_002C49EC;
    if (index >= 0x7E) {
        D_002C49EC = 0;
        B_00448D50[0x7F] = 0;
        func_0023AA40(B_00448D50);
        index = D_002C49EC;
    }
    if (character == 0xA) {
        D_002C49EC = 0;
        B_00448D50[index] = character;
        B_00448D50[index + 1] = 0;
        func_0023AA40(B_00448D50);
        return;
    }
    D_002C49EC = index + 1;
    B_00448D50[index] = character;
}
