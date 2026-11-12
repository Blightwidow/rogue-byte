typedef unsigned int u32;
typedef struct Unit {
    char pad0[0xE8];
    int fieldE8;
    char padEC[0x174 - 0xEC];
    int field174;
    int field178;
    int field17C;
    int field180;
    int field184;
    int field188;
    int field18C;
    int field190;
    int field194;
    int field198;
} Unit;
extern int func_00252148(Unit *unit, int bitCount);
#define HW_REGISTER (*(u32 *)0x10002010)
#define HW_VOLATILE (*(volatile u32 *)0x10002010)
int func_002540B0(Unit *unit) {
    int value;
    unit->field174 = func_00252148(unit, 4);
    unit->field178 = func_00252148(unit, 4);
    unit->field17C = func_00252148(unit, 4);
    unit->field180 = func_00252148(unit, 4);
    HW_REGISTER = (HW_REGISTER & 0xFFFCFFFF) | (func_00252148(unit, 2) << 16);
    value = func_00252148(unit, 2);
    unit->field184 = value;
    if (unit->fieldE8 == 0)
        unit->fieldE8 = value;
    unit->field188 = func_00252148(unit, 1);
    unit->field18C = func_00252148(unit, 1);
    unit->field190 = func_00252148(unit, 1);
    HW_VOLATILE = (HW_VOLATILE & 0xFFBFFFFF) | (func_00252148(unit, 1) << 22);
    HW_VOLATILE = (HW_VOLATILE & 0xFFDFFFFF) | (func_00252148(unit, 1) << 21);
    HW_VOLATILE = (HW_VOLATILE & 0xFFEFFFFF) | (func_00252148(unit, 1) << 20);
    unit->field194 = func_00252148(unit, 1);
    func_00252148(unit, 1);
    unit->field198 = func_00252148(unit, 1);
    if (func_00252148(unit, 1) != 0) {
        func_00252148(unit, 1);
        func_00252148(unit, 3);
        func_00252148(unit, 1);
        func_00252148(unit, 7);
        func_00252148(unit, 8);
    }
}
