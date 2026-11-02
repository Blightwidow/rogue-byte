/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct Word_21BD18 { char b[4]; };
struct Elem_21BD18 { char b[20]; };
struct Slot_21BD18 { int pad0; char *vtable; char rest[0x20]; };
struct Req_21BD18 { int size; int align; };
struct ReqQ_21BD18 { int size; int align; } __attribute__((aligned(16)));
struct First_21BD18 { Req_21BD18 req; QW buffer[0x7F]; };
union Frame_21BD18 { First_21BD18 first; QW buffer[0x80]; };
struct Sub_21BD18 { int count; int pad4; int pad8; char *src; int pad10; unsigned *ptrB; unsigned *ptrA; char *out; };
struct Node_21BD18 { int id; int count; Sub_21BD18 *subs; Node_21BD18 *next; };
struct Obj_21BD18 {
    char pad0[0x40]; unsigned *flags; char pad44[0x80 - 0x44]; char sub80[0x3C]; Elem_21BD18 *elems; Slot_21BD18 *slots; char pad0c4[0xDC - 0xC4];
    Node_21BD18 *nodes; char padE0[0x150 - 0xE0]; float time; int field154; int count; void *buffer; char pad160[8]; float scale; char pad16c[4]; QW vec;
};
extern "C" {
extern const float RO_FLT_002A9240;
extern const float RO_FLT_002A9244;
extern char D_002C44F0[];
void PostSoLoad();
void *PvAllocSwClearImpl__Fi(void);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
void func_0016EF00(void *, int);
void func_0021BC08(Obj_21BD18 *);

void func_0021BD18(Obj_21BD18 *self)
{
    Frame_21BD18 frame;
    ReqQ_21BD18 req2;
    PostSoLoad();
    if (self->count == 0) {
        if (self->time == 0.0f)
            self->time = 0.5f;
    }
    if (self->time != 0.0f)
        self->count = (int)(self->time * 60.0f + 0.5f) + 2;
    else
        self->time = (float)(self->count - 2) * 0.016666668f;
    float low, high;
    {
        Req_21BD18 *req = &frame.first.req;
        req->size = self->count * 0x50;
        req->align = 0x10;
        self->buffer = PvAllocSwClearImpl__Fi();
        low = 3.4028235e38f;
        high = -3.4028235e38f;
        for (Node_21BD18 *node = self->nodes; node != 0; node = node->next) {
            for (int index = 0; index < node->count; index++) {
                Sub_21BD18 *sub = node->subs + index;
                CopyAb__FPvT0Ui(frame.first.buffer, sub->src, sub->count * 0x10);
                int remaining = sub->count;
                if (remaining > 0) {
                    asm("lqc2 vf3, %0" : : "m" (self->vec));
                    QW *cursor = frame.first.buffer;
                    do {
                        float dist;
                        asm("lqc2 vf1, %1\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (dist) : "m" (*cursor));
                        if (high < dist) high = dist;
                        if (dist < low) low = dist;
                        remaining--;
                        cursor++;
                    } while (remaining != 0);
                }
            }
        }
    }
    for (Node_21BD18 *node = self->nodes; node != 0; node = node->next) {
        int slot = (Elem_21BD18 *)node->id - self->elems;
        Slot_21BD18 *target = self->slots + slot;
        target->vtable = D_002C44F0;
        func_0016EF00(self->sub80, slot);
        if (node->count > 0) {
            Req_21BD18 *request = (Req_21BD18 *)&req2;
            int index = 0;
            do {
                Sub_21BD18 *sub = node->subs + index;
                CopyAb__FPvT0Ui(frame.buffer, sub->src, sub->count * 0x10);
                request->size = sub->count << 5;
                request->align = 0x10;
                char *out = (char *)PvAllocSwClearImpl__Fi();
                sub->out = out;
                if (sub->count > 0) {
                    float range = high - low;
                    QW *cursor = frame.buffer;
                    int item = 0;
                    do {
                        float dist;
                        asm("lqc2 vf3, %1\n\tlqc2 vf4, %2\n\tvmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z\n\tqmfc2.ni %0, vf2" : "=r" (dist) : "m" (*cursor), "m" (self->vec));
                        float along = (self->scale - 1.0f) * dist;
                        asm("qmtc2.ni %0, vf1\n\tsqc2 vf1, %1\n\tvadda.xyzw ACC, vf3, vf0\n\tvmaddx.xyzw vf3, vf4, vf1x\n\tsqc2 vf3, %2" : : "r" (along), "m" (req2), "m" (*(QW *)out));
                        *(float *)(out + 0x10) = (dist - low) / range;
                        if (sub->ptrA)
                            *(Word_21BD18 *)(out + 0x14) = *(Word_21BD18 *)(sub->ptrA + item);
                        if (sub->ptrB)
                            *(Word_21BD18 *)(out + 0x18) = *(Word_21BD18 *)(sub->ptrB + item);
                        cursor++;
                        out += 0x20;
                        item++;
                    } while (item < sub->count);
                }
                index++;
            } while (index < node->count);
        }
    }
    func_0021BC08(self);
    if (self->field154 == 0) {
        unsigned *flags = self->flags;
        if (((unsigned)flags ^ 1) & 1) {
            *flags |= 2;
        } else {
            self->flags = (unsigned *)((unsigned)flags | 2);
        }
    }
}
}
