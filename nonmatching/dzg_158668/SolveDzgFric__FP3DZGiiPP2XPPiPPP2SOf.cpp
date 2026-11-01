typedef int QW __attribute__((mode(TI)));
struct Dz158B20;
struct Row158B20 { QW row; };
struct Attached158B20 { char pad0[0x88]; float a88; char pad8C[0x44]; float aD0; };
struct Obj158B20 {
    char pad0[8];
    char *parent;
    char pad0C[0x74];
    QW axis;
    char pad90[4];
    float mass;
    char pad98[4];
    int kind;
    char padA0[0x10];
    QW velocity;
};
struct Dz158B20 {
    int kind;
    float negScale;
    float scaleLimit;
    float weight;
    float unk10;
    char pad14[8];
    Dz158B20 *link;
    char pad20[8];
};
struct Group158B20 {
    char pad0[0x40];
    QW direction;
    Obj158B20 *object;
    Row158B20 *rows;
    char pad58[8];
};
struct Dzg158B20 {
    char pad0[4];
    int dzCount;
    Dz158B20 *dz;
    char pad0C[0x44];
    int objectCount;
    Obj158B20 **objects;
    char pad58[8];
    Group158B20 *groups;
};
struct Frame158B20 {
    QW best;
    QW vec;
    QW scale;
};
struct Zero158B20 { float x, y, z; };
extern "C" {
void SolveDzg__FP3DZGiiPP2XPPiPPP2SO(Dzg158B20 *, int);
void AppendDzgDz__FP3DZGP2DZ(Dzg158B20 *, Dz158B20 *);
extern float g_2dded0[];
extern float D_002BDDE8;
void SolveDzgFric__FP3DZGiiPP2XPPiPPP2SOf(Dzg158B20 *dzg, int flags) {
    Frame158B20 frame;
    for (;;) {
        SolveDzg__FP3DZGiiPP2XPPiPPP2SO(dzg, flags);
        int bestIndex = -1;
        float bestSquared = 0.01f;
        Obj158B20 *bestObject = 0;
        Zero158B20 *bestZero = (Zero158B20 *)&frame.best;
        bestZero->z = 0.0f;
        bestZero->y = 0.0f;
        bestZero->x = 0.0f;
        for (int index = 0; index < dzg->objectCount; index++) {
            if (dzg->dz[index].link)
                continue;
            if (dzg->dz[index].weight < 0.0001f)
                continue;
            Obj158B20 *object = dzg->objects[index];
            if (object->mass < 0.0001f)
                continue;
            frame.vec = object->velocity;
            Dz158B20 *entry = dzg->dz;
            for (int pair = 0; pair < dzg->dzCount; pair++, entry++) {
                float weight = entry->weight;
                if (weight != 0.0f) {
                    Group158B20 *group = &dzg->groups[pair];
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(weight));
                    asm volatile("sqc2 vf3, %0" : "=m"(frame.scale));
                    asm volatile("lqc2 vf2, %0" : : "m"(frame.vec));
                    asm volatile("lqc2 vf1, %0" : : "m"(group->rows[index]));
                    asm volatile("vadda.xyzw ACC, vf2, vf0");
                    asm volatile("vmaddx.xyzw vf2, vf1, vf3x");
                    asm volatile("sqc2 vf2, %0" : "=m"(frame.vec));
                }
            }
            float squared;
            asm volatile("lqc2 vf1, %0" : : "m"(object->axis));
            asm volatile("lqc2 vf3, %0" : : "m"(frame.vec));
            asm volatile("vmul.xyz vf2, vf3, vf1");
            asm volatile("vaddw.x vf4, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf4, vf2z");
            asm volatile("vmulx.xyzw vf2, vf1, vf2x");
            asm volatile("vsub.xyzw vf2, vf3, vf2");
            asm volatile("vmul.xyz vf4, vf2, vf2");
            asm volatile("vaddw.x vf1, vf0, vf0w");
            asm volatile("vadday.x ACC, vf4, vf4y");
            asm volatile("vmaddz.x vf4, vf1, vf4z");
            asm volatile("sqc2 vf2, %0" : "=m"(frame.vec));
            asm volatile("qmfc2.ni %0, vf4" : "=r"(squared));
            if (bestSquared < squared) {
                asm volatile("sqc2 vf2, %0" : "=m"(frame.best));
                bestSquared = squared;
                bestIndex = index;
                bestObject = object;
            }
        }
        if (!bestObject)
            return;
        Dz158B20 *chosen = &dzg->dz[bestIndex];
        Dz158B20 *fresh = &dzg->dz[dzg->dzCount];
        Group158B20 *group = &dzg->groups[dzg->dzCount];
        fresh->link = chosen;
        chosen->link = fresh;
        float length = __builtin_sqrtf(bestSquared);
        fresh->unk10 = -length;
        group->object = bestObject;
        asm volatile("qmtc2.ni %0, vf2" : : "r"(*(int *)&fresh->unk10));
        asm volatile("lqc2 vf1, %0" : : "m"(frame.best));
        asm volatile("sqc2 vf2, %0" : "=m"(frame.vec));
        asm volatile("vdiv Q, vf0w, vf2x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf1, Q");
        asm volatile("sqc2 vf1, %0" : "=m"(group->direction));
        fresh->kind = 1;
        float limit;
        if (bestObject->kind == 0xE) {
            char *parent = bestObject->parent;
            Attached158B20 *attached = *(Attached158B20 **)(parent + 0xE8);
            if (flags & 1) {
                float a = -attached->a88 * attached->aD0;
                float c = a * g_2dded0[1];
                limit = bestObject->mass * (__builtin_fabsf(fresh->link->weight) > c ? __builtin_fabsf(fresh->link->weight) : c);
            } else {
                float c = attached->aD0 * D_002BDDE8;
                float d = bestObject->mass * __builtin_fabsf(fresh->link->weight);
                limit = c < d ? c : d;
            }
        } else {
            limit = __builtin_fabsf(fresh->link->weight) * bestObject->mass;
        }
        fresh->scaleLimit = limit;
        fresh->negScale = -fresh->scaleLimit;
        AppendDzgDz__FP3DZGP2DZ(dzg, fresh);
    }
}
}
