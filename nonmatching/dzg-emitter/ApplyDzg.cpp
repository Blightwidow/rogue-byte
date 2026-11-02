typedef int QW __attribute__((mode(TI)));
extern "C" {
struct Req158E20 { int size; int align; };
struct Body158E20 { char pad0[0xF0]; QW linear; QW angular; };
struct Contact158E20 { int pad0; int pad4; Body158E20 *body; };
struct Pair158E20 { char pad0[0xC]; float scale; char pad10[0x18]; };
static inline int Bits158E20(Pair158E20 *pair) { return *(int *)&pair->scale; }
struct Row158E20 { QW pad0[2]; };
struct Group158E20 { Row158E20 row[2]; char pad40[0x10]; Contact158E20 *list; char pad54[0xC]; };
struct Dzg158E20 {
    int pad0;
    int pairCount;
    Pair158E20 *pairs;
    char pad0C[0x4C];
    int bodyCount;
    Body158E20 **bodies;
    Group158E20 *groups;
};
void CStackFrame_Construct(char *);
void CStackFrame_Destructor(char *, int);
void *PvAllocStackImpl__Fi(Req158E20 *);
QW LimitVectorLength__FP6VECTORfT0(QW, float);
void ApplyDzg(Dzg158E20 *dzg, float limitLinear, float limitAngular) {
    char frame[0x10] __attribute__((aligned(16)));
    Req158E20 req;
    Body158E20 *body;
    CStackFrame_Construct(frame);
    Req158E20 *preq = &req;
    preq->size = dzg->bodyCount << 5;
    preq->align = 0x10;
    PvAllocStackImpl__Fi(preq);
    for (int pairIndex = 0; pairIndex < dzg->pairCount; pairIndex++) {
        Pair158E20 *pair = &dzg->pairs[pairIndex];
        if (pair->scale != 0.0f) {
            Group158E20 *group = &dzg->groups[pairIndex];
            for (int side = 0; side < 2; side++) {
                body = *(Body158E20 **)((char *)group->list + (side << 6) + 8);
                if (body != 0) {
                    int scale = Bits158E20(pair);
                    char *row = (char *)group + side * 0x20;
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(scale));
                    asm volatile("lqc2 vf3, 0xf0(%0)" : : "r"(body));
                    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(frame) : "memory");
                    asm volatile("lqc2 vf1, 0(%0)" : : "r"(row));
                    asm volatile("vadda.xyzw ACC, vf3, vf0");
                    asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
                    asm volatile("lqc2 vf4, 0x100(%0)" : : "r"(body));
                    asm volatile("sqc2 vf3, 0xf0(%0)" : : "r"(body) : "memory");
                    asm volatile("qmtc2.ni %0, vf2" : : "r"(Bits158E20(pair)));
                    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(frame) : "memory");
                    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(row));
                    asm volatile("vadda.xyzw ACC, vf4, vf0");
                    asm volatile("vmaddx.xyzw vf4, vf1, vf2x");
                    asm volatile("sqc2 vf4, 0x100(%0)" : : "r"(body) : "memory");
                }
            }
        }
    }
    for (int bodyIndex = 0; bodyIndex < dzg->bodyCount; bodyIndex++) {
        body = dzg->bodies[bodyIndex];
        body->linear = LimitVectorLength__FP6VECTORfT0(body->linear, limitLinear);
        body->angular = LimitVectorLength__FP6VECTORfT0(body->angular, limitAngular);
    }
    CStackFrame_Destructor(frame, 2);
}
}
