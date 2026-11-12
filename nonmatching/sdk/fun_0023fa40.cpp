// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct UnalignedWord_23FA40 { int value __attribute__((packed)); };
struct Context_23FA40 { int field0; int field4; int scaleA; int scaleB; };
struct Machine_23FA40 {
    long pad0;
    long valueA;
    long valueB;
    long registers[32];
    char pad118[0x298 - 0x118 - 8 + 8];
    unsigned short count;
    char pad29A[2];
    char kinds[0x44];
    long pad2E0[2];
    Machine_23FA40 *saved;
    int pad2F4;
};
unsigned char *func_0023F240(unsigned char *, int *);
void func_00240328(void);
void *malloc(unsigned int);
void free(void *);

unsigned char *func_0023FA40(unsigned char *code, Machine_23FA40 *machine, Context_23FA40 *context, int *accumulator)
{
    int values[3];
    unsigned int opcode = *code++;
    unsigned int index = opcode & 0x3F;
    int delta;

    if (opcode & 0x40) {
        delta = index * context->scaleA;
        goto add;
    }
    if (opcode & 0x80) {
        values[1] = index;
        code = func_0023F240(code, &values[0]);
        goto store;
    }
    if (opcode & 0xC0) {
        values[1] = index;
        machine->kinds[values[1]] = 0;
        return code;
    }
    switch (opcode) {
    case 1:
        *accumulator = ((UnalignedWord_23FA40 *)code)->value;
        code += 4;
        break;
    case 2:
        delta = *code++;
        goto add;
    case 3:
        delta = (unsigned short)(code[1] << 8 | code[0]);
        code += 2;
        goto add;
    case 4:
        delta = ((UnalignedWord_23FA40 *)code)->value;
        code += 4;
    add:
        *accumulator = *accumulator + delta;
        break;
    case 5:
        code = func_0023F240(code, &values[1]);
        code = func_0023F240(code, &values[0]);
    store:
        values[0] = values[0] * context->scaleB;
        machine->kinds[values[1]] = 1;
        machine->registers[values[1]] = values[0];
        break;
    case 6:
        code = func_0023F240(code, &values[1]);
        machine->kinds[values[1]] = 0;
        break;
    case 9:
        code = func_0023F240(code, &values[1]);
        code = func_0023F240(code, &values[2]);
        machine->kinds[values[1]] = 2;
        machine->registers[values[1]] = (unsigned int)values[2];
        break;
    case 12:
        code = func_0023F240(code, &values[1]);
        code = func_0023F240(code, &values[0]);
        machine->count = values[1];
        machine->valueA = values[0];
        break;
    case 13:
        code = func_0023F240(code, &values[1]);
        machine->count = values[1];
        break;
    case 14:
        code = func_0023F240(code, &values[0]);
        machine->valueA = values[0];
        break;
    case 10: {
        Machine_23FA40 *copy = (Machine_23FA40 *)malloc(0x2F8);
        *copy = *machine;
        machine->saved = copy;
        break;
    }
    case 11: {
        Machine_23FA40 *copy = machine->saved;
        *machine = *copy;
        free(copy);
        return code;
    }
    case 45:
        for (values[1] = 16; (unsigned int)values[1] < 32; ) {
            int index = values[1];
            machine->kinds[index] = 1;
            values[1] = index + 1;
            machine->registers[index] = (unsigned int)((index - 16) * 4);
        }
        return code;
    case 46:
        code = func_0023F240(code, &values[0]);
        machine->valueB = values[0];
        break;
    case 0:
    case 7:
    case 8:
        break;
    default:
        func_00240328();
        break;
    }
    return code;
}
}
