typedef int s32; typedef unsigned int u32; typedef float f32;
typedef int QW __attribute__((mode(TI)));
extern "C" {
struct Sub20BAD8 { char pad[8]; f32 *field8; };
struct Mid20BAD8 { char pad[0xD0]; Sub20BAD8 *fieldD0; };
struct Obj20BAD8 { char pad[4]; Mid20BAD8 *field4; char pad8[8]; f32 rows[1]; };
extern int g_2a2dd0;
s32 CalculateBlrunV(Obj20BAD8 *obj) {
    QW scratch;
    f32 divisor = obj->field4->fieldD0->field8[1];
    f32 *p = obj->rows;
    asm volatile("lqc2 vf3, (%0)" : : "r"(&g_2a2dd0));
    u32 i = 0;
    do {
        i += 1;
        f32 a = p[0];
        f32 b = p[9] / divisor;
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(p));
        p += 0x10;
        asm volatile("qmtc2.ni %0, vf1" : : "r"(a * b));
        asm volatile("vadda.xyzw ACC, vf3, vf0");
        asm volatile("vmaddx.xyzw vf3, vf2, vf1x");
        asm volatile("sqc2 vf1, %0" : "=m"(scratch));
    } while (i < 2U);
    s32 result;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(result));
    return result;
}
}
