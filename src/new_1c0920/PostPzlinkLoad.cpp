/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int QW __attribute__((mode(TI)));
struct PZLINK_1C2170 { char pad[0x50]; int index; char pad2[0x124 - 0x54]; void *pathzoneA; void *pathzoneB; char pad3[4]; QW posA; QW posB; };
extern "C" void PostLoLoad(PZLINK_1C2170 *);
extern "C" void *PpathzoneFindPos(QW, int);
extern "C" QW func_001C1F28(void *);
extern "C" void PostPzlinkLoad(PZLINK_1C2170 *link) {
    PostLoLoad(link);
    QW pos = func_001C1F28((char *)link + 0x60);
    link->posA = pos;
    link->pathzoneA = PpathzoneFindPos(pos, 0);
    pos = func_001C1F28((char *)((link->index << 5) + (int)link + 0x40));
    link->posB = pos;
    link->pathzoneB = PpathzoneFindPos(pos, 0);
}
