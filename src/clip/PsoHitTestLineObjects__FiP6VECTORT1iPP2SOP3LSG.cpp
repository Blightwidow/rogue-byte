#include "sly2.h"
struct Lsg { QW head[4]; float key; int pad[3]; QW tail; };
struct Obj;
extern "C" int ClsgClipEdgeToObject(Obj *, QW, QW, int, Lsg *);
extern "C" float g_bestKeyInit;
extern "C" Obj *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int flags, QW start, QW end, int count, Obj **list, Lsg *out)
{
    float bestKey = 3.4028235e38f;
    Obj *best = 0;
    Lsg buffer[2];
    for (int index = 0; index < count; index++) {
        Obj *object = list[index];
        int hits = ClsgClipEdgeToObject(object, start, end, 2, buffer);
        int first = 0;
        if (hits > 0 && buffer[0].key == 0.0f) {
            if (flags & 1)
                first = 1;
        }
        if (first < hits && buffer[first].key < bestKey) {
            bestKey = buffer[first].key;
            best = object;
            if (out != 0)
                *out = buffer[first];
        }
    }
    return best;
}
