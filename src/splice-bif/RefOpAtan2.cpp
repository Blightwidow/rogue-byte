struct RefArg_1226B0 { int tag; union { int i; float f; } v; };
extern "C" {
float atan2f(float, float);
RefArg_1226B0 *RefOpAtan2(RefArg_1226B0 *out, int unused, RefArg_1226B0 *args) {
    float sp[2] __attribute__((aligned(16)));
    int i;
    for (i = 0; i < 2; i++) {
        if (args[i].tag == 0x16)
            sp[i] = args[i].v.f;
        else
            sp[i] = (float)args[i].v.i;
    }
    out->v.f = atan2f(sp[0], sp[1]);
    out->tag = 0x16;
    return out;
}
}
