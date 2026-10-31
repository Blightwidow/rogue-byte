struct Record_1E4530 { int kind; int skip; char pad[8]; union { int id; float value; } a; union { int sub; float value; } b; int state; };
struct Node_1E4530 { char pad[0x18]; int owner; };
struct Seq_1E4530 { char pad[0x74]; float a74; float a78; char pad2[0x80 - 0x7C]; float c0; float c1; float c2; char pad3[0x90 - 0x8C]; float low; float high; };
extern "C" float DtSmaReachState(int, int);
extern "C" float FFindLevel(void *, int, Node_1E4530 *);
extern "C" float GetSuck(void *);
extern "C" Seq_1E4530 *PloFindSeqnodeObject(Node_1E4530 *, int);
extern "C" int PloFindSwObject_thunk(void *, int, int, int);
extern "C" int PsmaFindAlo(int, int);
extern char B_002DE578[];
extern char B_003DD040[];
extern char B_003DD490[];
extern float RO_002BD850;
extern "C" float DtSeqnodeRecord(Node_1E4530 *node, Record_1E4530 *record) {
    float result = 0.0f;
    if (record->skip == 0) {
        switch (record->kind) {
        case 0xA: {
            Seq_1E4530 *seq = PloFindSeqnodeObject(node, record->a.id);
            if (seq != 0) {
                float suck = GetSuck(B_002DE578);
                float *coefficient = &seq->c0;
                float low = seq->low;
                float high = seq->high;
                float curve = coefficient[0] + suck * (coefficient[1] + suck * coefficient[2]);
                if (curve < low) {
                    curve = low;
                } else if (high < curve) {
                    curve = high;
                }
                result = seq->a74 / (seq->a78 * curve);
            }
            break;
        }
        case 0xD:
            if (record->state != -1) {
                int object = PloFindSwObject_thunk(B_003DD490, 4, record->a.id, node->owner);
                if (object != 0) {
                    int alo = PsmaFindAlo(object, record->b.sub);
                    if (alo != 0) {
                        result = DtSmaReachState(alo, record->state);
                    }
                }
            }
            break;
        case 0x32:
            result = RO_002BD850;
            break;
        case 0x23:
        case 0x33:
            result = record->a.value;
            break;
        case 0x45:
            result = FFindLevel(B_003DD040, record->a.id, node);
            break;
        case 0x2C:
        case 0x2D:
        case 0x53:
            result = record->b.value;
            break;
        }
    }
    return result;
}
