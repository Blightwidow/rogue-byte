#include "sly2.h"
#include "vu0inline.h"
struct V3_1681F8 { float x, y, z; };
struct PACKET_1681F8 { int word; int pad4[3]; V3_1681F8 pos; float scale; MATRIX4 matrix; };
struct FRAME_1681F8 { PACKET_1681F8 packet; MATRIX4 local; MATRIX4 product; };
struct DMAS_1681F8 { char pad[0xC]; int *cursor; };
struct SLOT_1681F8 { int zero0; int zero4; int *tag; int value; };
struct ENTRYA_1681F8 { char pad0[8]; int value; char pad[8]; };
struct ENTRYB_1681F8 {
    char pad0[4];
    char *source;
    MATRIX4 *parent;
    unsigned flags;
    char *shared;
    int word;
    char pad18[0xC];
    V3_1681F8 *fixed;
    char pad28[0];
};
struct OWNER_1681F8 {
    char pad0[0x38];
    int count;
    char *entriesA;
    char *entriesB;
    char *points;
    char pad48[4];
    int result;
};
extern "C" {
void CopyAb__FPvT0Ui(void *, void *, unsigned);
float GMaxAxisScale(MATRIX4 *);
void *__ml__FRC7MATRIX4T0(MATRIX4 *, MATRIX4 *, MATRIX4 *);
void *memcpy(void *, void *, unsigned);
SLOT_1681F8 *OnGameLoad__FP4GAME(void);
extern DMAS_1681F8 g_2dea28;
extern char B_003DD490[];
}
extern "C" void func_001681F8(OWNER_1681F8 *self)
{
    FRAME_1681F8 frame;
    int index;
    for (index = 0; index < self->count; index++) {
        ENTRYA_1681F8 *entryA = (ENTRYA_1681F8 *)(self->entriesA + index * 0x14);
        ENTRYB_1681F8 *entryB = (ENTRYB_1681F8 *)(self->entriesB + index * 0x28);
        if (entryA->value != 0) {
            frame.packet.word = entryB->word;
            if (entryB->flags & 0x1000) {
                CopyAb__FPvT0Ui(&frame.packet.matrix, entryB->shared + 0x14, 0x40);
            } else {
                MATRIX4 *parent = entryB->parent;
                memcpy(&frame.local, entryB->source + 0x40, 0x40);
                if (parent != 0) {
                    __ml__FRC7MATRIX4T0(&frame.product, &frame.local, parent);
                    memcpy(&frame.local, &frame.product, 0x40);
                }
                frame.packet.matrix = frame.local;
            }
            if (entryB->fixed != 0) {
                frame.packet.pos = *entryB->fixed;
                frame.packet.scale = ((float *)entryB->fixed)[3];
            } else {
                char *point = self->points + index * 0x18;
                CopyAb__FPvT0Ui(&frame.local, point, 0xC);
                QW position = TransformPoint(*(QW *)&frame.local, frame.packet.matrix.row[0], frame.packet.matrix.row[1], frame.packet.matrix.row[2], frame.packet.matrix.row[3]);
                *(QW *)&frame.packet.pos = position;
                frame.packet.scale = GMaxAxisScale(&frame.packet.matrix) * *(float *)(point + 0xC);
            }
            int *tag = g_2dea28.cursor;
            *(long *)tag = 0x10000000;
            g_2dea28.cursor = g_2dea28.cursor + 4;
            *g_2dea28.cursor = 0x6C06C301;
            g_2dea28.cursor = g_2dea28.cursor + 1;
            *(PACKET_1681F8 *)g_2dea28.cursor = frame.packet;
            g_2dea28.cursor = (int *)((char *)g_2dea28.cursor + 0x60);
            if (((int)g_2dea28.cursor & 0xF) != 0) {
                do {
                    *g_2dea28.cursor = 0;
                    g_2dea28.cursor = g_2dea28.cursor + 1;
                } while (((int)g_2dea28.cursor & 0xF) != 0);
            }
            *tag |= (((int)g_2dea28.cursor - (int)tag) >> 4) - 1;
            *(long *)g_2dea28.cursor = 0x60000000;
            g_2dea28.cursor = g_2dea28.cursor + 4;
            SLOT_1681F8 *slot = OnGameLoad__FP4GAME();
            slot->tag = tag;
            slot->zero0 = 0;
            slot->zero4 = 0;
            slot->value = entryA->value;
        }
    }
    self->result = *(int *)(B_003DD490 + 0x3D5C);
}
