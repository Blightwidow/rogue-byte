typedef int s32;
typedef float f32;

extern "C" {

struct ACT {
    /* 0x00 */ s32 kind;
    /* 0x04 */ s32 field4[5];
    /* 0x18 */ void *vtable;
};

void *PvAllocAct(s32 cb);
void *memset(void *destination, s32 value, unsigned int count);

extern s32 D_002CA6A0;
extern s32 D_002CA6E0;
extern s32 D_002CA720;
extern s32 D_002CA760;
extern s32 D_002CA7A0;
extern s32 D_002CA7E0;
extern s32 D_002CA820;
extern s32 D_002CAF08;
extern s32 D_002D2E58;
extern s32 D_002DB338;

/* PactNew: allocate an actuator of the given kind from the act slot heap, store its kind
 * at +0x0 and its vtable at +0x18, and initialise the per-kind fields (kind 1: +0x1C = 2;
 * kind 6: a 4x4 float matrix at +0x20 cleared then set to identity; kind 9: +0x14 = 0x14).
 * Retail keeps each case's new pointer in its own register ($v0, $s1 in case 6) and copies
 * it into a separate result register $a2 at the end of the case, so each case declares its
 * own local and assigns the result after its stores; with one shared pointer gcc keeps it in
 * $s1 for every case. Retail stores the identity diagonal as 0x14, 0x3C, 0x28, then +0x20
 * through the act pointer: gcc 2.95's scheduler emits these in that order from the source
 * order m[15], m[10], m[5], m[0]. */
ACT *PactNew(s32 kind) {
    ACT *pact;

    switch (kind) {
    case 0: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x2C);
            pactNew->kind = 0;
            pactNew->vtable = &D_002CAF08;
            pact = pactNew;
            break;
        }
    case 1: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x30);
            pactNew->vtable = &D_002CA820;
            pactNew->kind = 1;
            *(s32 *)((char *)pactNew + 0x1C) = 2;
            pact = pactNew;
            break;
        }
    case 2: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x80);
            pactNew->vtable = &D_002CA7E0;
            pactNew->kind = 2;
            pact = pactNew;
            break;
        }
    case 3: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x20);
            pactNew->vtable = &D_002DB338;
            pactNew->kind = 3;
            pact = pactNew;
            break;
        }
    case 4: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x28);
            pactNew->vtable = &D_002CA7A0;
            pactNew->kind = 4;
            pact = pactNew;
            break;
        }
    case 5: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x30);
            pactNew->vtable = &D_002CA760;
            pactNew->kind = 5;
            pact = pactNew;
            break;
        }
    case 6: {
            ACT *pactNew;
            f32 *matrix;
            pactNew = (ACT *)PvAllocAct(0x60);
            matrix = (f32 *)((char *)pactNew + 0x20);
            pactNew->vtable = &D_002CA720;
            pactNew->kind = 6;
            memset(matrix, 0, 0x40);
            matrix[15] = 1.0f;
            matrix[10] = 1.0f;
            matrix[5] = 1.0f;
            matrix[0] = 1.0f;
            pact = pactNew;
            break;
        }
    case 7: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x20);
            pactNew->vtable = &D_002D2E58;
            pactNew->kind = 7;
            pact = pactNew;
            break;
        }
    case 8: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x40);
            pactNew->vtable = &D_002CA6E0;
            pactNew->kind = 8;
            pact = pactNew;
            break;
        }
    case 9: {
            ACT *pactNew;
            pactNew = (ACT *)PvAllocAct(0x30);
            pactNew->vtable = &D_002CA6A0;
            pactNew->kind = 9;
            *(s32 *)((char *)pactNew + 0x14) = 0x14;
            pact = pactNew;
            break;
        }
    default:
        pact = 0;
        break;
    }
    return pact;
}
}
