// SPDX-License-Identifier: GPL-3.0-or-later
struct Object { char pad0[0x11C]; float field11C; float field120; float field124; };
void InitXfm();
void func_001BEA40(struct Object *object) {
    InitXfm();
    object->field11C = 1.0f;
    object->field120 = 4.0f;
    object->field124 = 1000.0f;
}
