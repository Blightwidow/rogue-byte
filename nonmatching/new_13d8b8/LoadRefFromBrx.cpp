extern "C" {
struct Ref_13E690 { int type; int value; };
void CRef_ConstructClq(Ref_13E690 *, float *);
void CRef_ConstructLm(Ref_13E690 *, float *);
void CRef_ConstructVector(Ref_13E690 *, float *);
float F32Read__18CBinaryInputStream(int);
int S16Read__18CBinaryInputStream(int);
int S32Read__18CBinaryInputStream(int);
void SetTag__4CRef4TAGK(Ref_13E690 *, int);
unsigned int U32Read__18CBinaryInputStream(int);
int U8Read__18CBinaryInputStream(int);
Ref_13E690 *LoadRefFromBrx(Ref_13E690 *ref, unsigned int kind, int stream) {
    float values[4];
    int index;
    int flag;
    float *cursor;
    switch (kind) {
    case 0:
        flag = U8Read__18CBinaryInputStream(stream) != 0;
        ref->type = 0x17;
        ref->value = flag;
        break;
    case 5:
    case 6:
        ref->value = S32Read__18CBinaryInputStream(stream);
        ref->type = 0x15;
        break;
    case 1:
        *(float *)&ref->value = F32Read__18CBinaryInputStream(stream);
        ref->type = 0x16;
        break;
    case 7: case 14: case 15: case 16: case 17: case 19: case 20: case 21: case 23:
        ref->value = S16Read__18CBinaryInputStream(stream);
        ref->type = 0x15;
        break;
    case 9:
        cursor = values;
        index = 2;
        do {
            index -= 1;
            *cursor = F32Read__18CBinaryInputStream(stream);
            cursor += 1;
        } while (index >= 0);
        CRef_ConstructClq(ref, values);
        break;
    case 10:
        values[0] = F32Read__18CBinaryInputStream(stream);
        values[1] = F32Read__18CBinaryInputStream(stream);
        CRef_ConstructLm(ref, values);
        break;
    case 2:
        cursor = values;
        index = 2;
        do {
            index -= 1;
            *cursor = F32Read__18CBinaryInputStream(stream);
            cursor += 1;
        } while (index >= 0);
        CRef_ConstructVector(ref, values);
        break;
    default:
        if (((int)(kind & 0xFFFF7FFF) >> 0xC) == 1) {
            ref->value = U32Read__18CBinaryInputStream(stream);
            ref->type = 0x15;
            break;
        }
        SetTag__4CRef4TAGK(ref, 0x24);
        break;
    }
    return ref;
}
}
