#include "sly2.h"
struct Slot_21C888 { short delta; short index; void *(*fn)(void *, int); };
struct Vt_21C888 { char pad[0x198]; Slot_21C888 slot; };
struct Act_21C888 { QW row[3]; char pad[0x70 - 0x30]; QW pos; };
struct Group_21C888;
struct Seg_21C888 { QW row[3]; QW start; QW end; char pad[0x60 - 0x50]; Group_21C888 *group; Act_21C888 *act; char pad2[0x70 - 0x68]; };
struct Group_21C888 { int count; Seg_21C888 *segs; int kind; float f0, f1, f2, f3; int pad1; QW vecA; QW vecB; };
struct Owner_21C888 { char pad0[0xC]; Vt_21C888 *vtable; };
struct Req_21C888 { int size; int align; };
struct Xf_21C888 { int kind; Owner_21C888 *owner; Act_21C888 *act; int slot; char pad[0x14 - 0x10]; int flags; void *vtable; Seg_21C888 *seg; };
extern "C" int S8Read__18CBinaryInputStream(void *);
extern "C" int S16Read__18CBinaryInputStream(void *);
extern "C" int U8Read__18CBinaryInputStream(void *);
extern "C" float F32Read__18CBinaryInputStream(void *);
extern "C" void ReadVector__18CBinaryInputStreamP6VECTOR(void *, void *);
extern "C" void *PvAllocSwClearImpl__Fi(Req_21C888 *);
extern "C" Xf_21C888 *PvAllocAct(int);
extern "C" void InsertXfAct(Owner_21C888 *, Act_21C888 *, Xf_21C888 *);
extern "C" QW ConvertXfPos(Act_21C888 *, Act_21C888 *, QW);
extern "C" QW ConvertXfVec(Act_21C888 *, Act_21C888 *, QW);
extern "C" char D_002DB338[];

void func_0021C888(Owner_21C888 *self, void *stream)
{
    Req_21C888 req;
    int i;
    int count = S8Read__18CBinaryInputStream(stream);
    for (i = 0; i < count; i++) {
        int j;
        req.size = 0x50;
        req.align = 0x10;
        Group_21C888 *group = (Group_21C888 *)PvAllocSwClearImpl__Fi(&req);
        group->kind = U8Read__18CBinaryInputStream(stream);
        group->f0 = F32Read__18CBinaryInputStream(stream);
        group->f1 = F32Read__18CBinaryInputStream(stream);
        group->f2 = F32Read__18CBinaryInputStream(stream);
        group->f3 = F32Read__18CBinaryInputStream(stream);
        ReadVector__18CBinaryInputStreamP6VECTOR(stream, &group->vecA);
        ReadVector__18CBinaryInputStreamP6VECTOR(stream, &group->vecB);
        group->count = S8Read__18CBinaryInputStream(stream);
        req.size = group->count * 0x70;
        req.align = 0x10;
        group->segs = (Seg_21C888 *)PvAllocSwClearImpl__Fi(&req);
        for (j = 0; j < group->count; j++) {
            Seg_21C888 *seg = &group->segs[j];
            seg->group = group;
            Vt_21C888 *vt = self->vtable;
            Slot_21C888 *slot = &vt->slot;
            char *owner = (char *)self + vt->slot.delta;
            Act_21C888 *act = (Act_21C888 *)slot->fn(owner, S16Read__18CBinaryInputStream(stream));
            seg->act = act;
            seg->row[0] = act->row[0];
            seg->row[1] = act->row[1];
            seg->row[2] = act->row[2];
            Xf_21C888 *xf = PvAllocAct(0x20);
            xf->kind = 3;
            xf->vtable = D_002DB338;
            xf->owner = self;
            xf->slot = -1;
            xf->act = seg->act;
            xf->seg = seg;
            xf->flags = 0x10;
            InsertXfAct(self, seg->act, xf);
            *(Seg_21C888 **)((char *)seg->act + 0xA8) = seg;
        }
        for (j = 0; j < group->count; j++) {
            Seg_21C888 *seg = &group->segs[j];
            QW value;
            if (j < group->count - 1) {
                value = ConvertXfPos(0, seg->act, seg[1].act->pos);
            } else if (j <= 0) {
                value = group->vecB;
            } else {
                value = ConvertXfVec(seg[-1].act, seg->act, seg[-1].start);
            }
            seg->start = value;
            seg->end = ConvertXfPos(seg->act, 0, seg->start);
        }
    }
}
