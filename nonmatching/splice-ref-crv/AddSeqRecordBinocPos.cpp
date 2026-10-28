typedef int QW __attribute__((mode(TI)));
struct JSG;
struct ITEM { char pad[0x10]; QW pos; float rot[3]; char pad2[4]; float extra; };
extern "C" ITEM *PjsgeAllocJsg(JSG *, int, int);
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float LaneY(QW q) { QW t; float f; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline float LaneZ(QW q) { QW t; float f; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
extern "C" void AddSeqRecordBinocPos(JSG *jsg, QW pos, QW rot, float extra)
{
    ITEM *item = PjsgeAllocJsg(jsg, 0x3F, 1);
    float x = LaneX(rot) * 0.017453294f;
    float y = LaneY(rot) * 0.017453294f;
    float z = LaneZ(rot) * 0.017453294f;
    item->extra = extra;
    item->pos = pos;
    item->rot[0] = x;
    item->rot[1] = y;
    item->rot[2] = z;
}
