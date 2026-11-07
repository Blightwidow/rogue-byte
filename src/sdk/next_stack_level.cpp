// SPDX-License-Identifier: GPL-3.0-or-later
struct StackFrame {
    int value;
    int field04;
    int offset;
    char field0C[0x28C];
    unsigned short registerIndex;
};
struct RegisterContext {
    int firstValue;
    char field04[0x298];
    signed char registerKinds[1];
};
extern "C" {
StackFrame* func_0023FE78(int, int);
long* get_reg_addr(unsigned short, RegisterContext*, int);
StackFrame* next_stack_level(int unusedFirst, RegisterContext* context, int third) {
    StackFrame* frame = func_0023FE78(unusedFirst, third);
    if (frame == 0) {
        return 0;
    }
    if (context->registerKinds[frame->registerIndex] != 0) {
        long registerValue = *get_reg_addr(frame->registerIndex, context, 0);
        frame->value = registerValue;
    } else {
        frame->value = context->firstValue;
    }
    frame->value = frame->value + frame->offset;
    return frame;
}
}
