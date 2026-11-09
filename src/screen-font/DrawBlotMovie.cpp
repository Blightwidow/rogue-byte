// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
struct DMAS_213300 { unsigned base; int pad4[2]; char *p; };
struct Ctx_213300 { int kind; int pad4; float z; int padC; float add[4]; float mul[4]; };
struct Node_213300 {
    u8 add[4]; u8 mul[4]; char pad8[8]; char matrix[0x20];
    void *character; int kind; char pad38[0x29]; u8 flag; char pad62[6];
    Node_213300 *next;
};
struct Blot_213300 { char pad0[0x84]; int field84; char pad88[0x74]; Node_213300 *head; };
extern "C" {
void func_001A5ED8(Blot_213300 *);
int FDrawBlotMovie(Blot_213300 *);
void func_002185D0(int);
void BuildBlotDmaHeader(Blot_213300 *);
void func_00217298(Blot_213300 *, int, float);
void DrawMovieCharacter(void *, void *, Ctx_213300 *, int);
void ClearSl(void *);
extern DMAS_213300 g_2dea28;
}
static inline void Pad64(DMAS_213300 *dmas) {
    while ((int)dmas->p & 0x3F) { *(int *)dmas->p = 0; dmas->p = dmas->p + 4; }
}
static inline void Uncache(DMAS_213300 *dmas) {
    Pad64(dmas);
    dmas->p = (char *)((unsigned)dmas->p | 0x30000000);
    dmas->base |= 0x30000000;
}
static inline void Recache(DMAS_213300 *dmas) {
    Pad64(dmas);
    dmas->p = (char *)((unsigned)dmas->p & 0x0FFFFFFF);
    dmas->base &= 0x0FFFFFFF;
}
static inline float Clamp(float value, float low, float high) {
    float result = value > high ? high : value;
    return result < low ? low : result;
}
static inline void FillColors(Ctx_213300 *ctx, Node_213300 *node) {
    float fr = (float)node->add[0] - 127.0f, fg = (float)node->add[1] - 127.0f;
    float fb = (float)node->add[2] - 127.0f, fa = (float)node->add[3] - 127.0f;
    ctx->add[0] = fr;
    ctx->add[1] = fg;
    ctx->add[2] = fb;
    ctx->add[3] = fa;
    int r, g, b, a;
    r = node->mul[0] - 0x7F; g = node->mul[1] - 0x7F; b = node->mul[2] - 0x7F; a = node->mul[3] - 0x7F;
    ctx->mul[0] = Clamp((float)r * 0.007874016f, -1.0f, 1.0f);
    ctx->mul[1] = Clamp((float)g * 0.007874016f, -1.0f, 1.0f);
    ctx->mul[2] = Clamp((float)b * 0.007874016f, -1.0f, 1.0f);
    ctx->mul[3] = Clamp((float)a * 0.007874016f, -1.0f, 1.0f);
}
extern "C" void DrawBlotMovie(Blot_213300 *self)
{
    func_001A5ED8(self);
    if (!FDrawBlotMovie(self)) return;
    float z = 16.0f;
    func_002185D0(self->field84);
    Uncache(&g_2dea28);
    BuildBlotDmaHeader(self);
    Node_213300 *prev = 0;
    Ctx_213300 ctx[2];
    for (Node_213300 *node = self->head; node; node = node->next, z += 1024.0f) {
        if (node->kind == 1) {
            ctx[0].add[0] = 0; ctx[0].add[1] = 0; ctx[0].add[2] = 0; ctx[0].add[3] = 0;
            ctx[0].mul[0] = 0; ctx[0].mul[1] = 0; ctx[0].mul[2] = 0; ctx[0].mul[3] = 0;
            ctx[0].z = z;
            ctx[0].kind = 1;
            prev = node;
            func_00217298(self, 1, z - 1.0f);
            DrawMovieCharacter(node->character, node->matrix, &ctx[0], node->flag);
            func_00217298(self, 3, ctx[0].z + 1.0f);
        } else if (node->kind == 4) {
            ctx[0].add[0] = 0; ctx[0].add[1] = 0; ctx[0].add[2] = 0; ctx[0].add[3] = 0;
            ctx[0].mul[0] = 0; ctx[0].mul[1] = 0; ctx[0].mul[2] = 0; ctx[0].mul[3] = 0;
            ctx[0].z = z;
            ctx[0].kind = 1;
            func_00217298(self, 2, z - 1.0f);
            DrawMovieCharacter(prev->character, prev->matrix, &ctx[0], prev->flag);
            prev = 0;
            func_00217298(self, 4, ctx[0].z + 1.0f);
            if (node->character) {
                FillColors(&ctx[1], node);
                z += 1024.0f;
                ctx[1].z = z;
                ctx[1].kind = 1;
                DrawMovieCharacter(node->character, node->matrix, &ctx[1], node->flag);
            }
        } else if (node->character) {
            FillColors(&ctx[0], node);
            ctx[0].z = z;
            ctx[0].kind = 1;
            DrawMovieCharacter(node->character, node->matrix, &ctx[0], node->flag);
        }
    }
    Recache(&g_2dea28);
    Node_213300 *node = self->head;
    while (node) {
        Node_213300 *cur = node;
        node = node->next;
        cur->next = 0;
    }
    ClearSl(&self->head);
}
