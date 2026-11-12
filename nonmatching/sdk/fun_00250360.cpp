typedef unsigned int u32;
extern "C" {
struct Table { int base; char pad4[0xC]; int stride; };
struct Slot {
    int target;
    int pad4;
    int selected;
    int forced;
    int done;
    char pad14[0x140 - 0x14];
};
struct Context {
    char pad0[0x12C];
    int failed;
    char pad130[0xC];
    int divisor;
    char pad140[0x44];
    int mode;
    char pad188[0x48];
    Table *tableC;
    char pad1D4[0xC];
    Table *tableD;
    char pad1E4[0xC];
    Table *tableE;
    char pad1F4[0x6C8 - 0x1F4];
    Slot slots[1];
    char pad808[0x820 - 0x6C8 - 0x140];
    int current;
};
void func_0024FA90(Context *context, const char *format, ...);
void func_0024FC58(Context *context, int a1, int a2, u32 a3);
void func_00252608(Context *context);
int func_00250360(Context *context, int index, int enable, u32 flags, int type) {
    int quotient = index / context->divisor;
    int remainder = index % context->divisor;
    Table *table;
    if ((flags & 1) != 0) {
        while ((*(volatile u32 *)0x1000D400 >> 8) & 1) {
        }
        context->slots[context->current].done = 0;
    } else {
        if ((u32)(type - 1) >= 3) {
            func_0024FA90(context, "Invalid modion type -- ignored(%d)", type);
            context->failed = 1;
            return 0;
        }
        func_0024FC58(context, remainder << 4, quotient << 4, flags);
        while ((*(volatile u32 *)0x1000D400 >> 8) & 1) {
        }
        func_00252608(context);
        context->slots[context->current].done = 1;
    }
    if (enable == 1 && (flags & 2) != 0) {
        context->slots[context->current].forced = enable;
    } else {
        context->slots[context->current].forced = 0;
    }
    context->slots[context->current].selected = flags & 1;
    if (context->mode == 3) {
        table = context->tableC;
    } else if (context->mode == 2) {
        table = context->tableE;
    } else {
        table = context->tableD;
    }
    context->slots[context->current].target = table->base + (remainder * table->stride + quotient) * 0x180;
    return 1;
}
}
