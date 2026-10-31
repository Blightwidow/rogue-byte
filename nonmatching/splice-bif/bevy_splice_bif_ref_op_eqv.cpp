struct RefOp_120548 { int tag; int val; };
extern "C" {
RefOp_120548 *bevy_splice_bif_ref_op_eqv(RefOp_120548 *out, int unused, RefOp_120548 *args, int flag) {
    RefOp_120548 *second = args + 1;
    unsigned tag = args->tag;
    if (tag != second->tag) {
        flag = 0;
    } else {
        switch (tag) {
        case 21: case 23: case 24: case 25: case 31: case 32: case 33: case 34:
            flag = args->val == second->val;
            break;
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
        case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 20: case 36:
            flag = 1;
            break;
        }
    }
    out->val = flag;
    out->tag = 0x17;
    return out;
}
}
