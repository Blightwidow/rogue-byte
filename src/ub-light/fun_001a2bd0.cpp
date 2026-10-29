// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
void func_001A2C48(void *, int **);
extern int B_002E1E54;
}

struct Stack_1A2BD0 { char abOut[4]; int *pValue; char abPad[8]; };

extern "C" void func_001A2BD0(int iArg)
{
    if (iArg == -1) {
        Stack_1A2BD0 stack;
        func_001A2C48(&stack, &stack.pValue);
        B_002E1E54 = *stack.pValue;
    } else {
        B_002E1E54 = iArg;
    }
}
