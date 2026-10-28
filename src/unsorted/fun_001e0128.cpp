struct KIND { int type; };
struct TARGET { char pad[0x18]; int value; char pad2[0x14]; KIND *kind; };
struct JSG { char pad[0x68]; TARGET *target; };
extern "C" int func_001E0128(JSG *jsg)
{
    TARGET *target = jsg->target;
    if (target == 0) return 0;
    if (target->kind->type == 9) return target->value;
    return 0;
}
