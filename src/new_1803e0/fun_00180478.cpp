// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;

struct FilterOwner {
    char pad0[0x60];
    void *activeObject;
};

struct FilterObject {
    char pad0[0xEC];
    FilterOwner *owner;
    char padF0[0x1C0 - 0xF0];
    float result;
    float fraction;
    s32 mode;
};

extern "C" {
void RecalcSwOxfFilterForObject(char *, FilterObject *);
extern char B_003DD490[];
extern float g_2a5654;
extern float g_2dded0;
}

extern "C" void func_00180478(FilterObject *object, s32 mode)
{
    if (mode != object->mode) {
        object->mode = mode;
        FilterOwner *owner = object->owner;
        if (owner->activeObject == object) {
            RecalcSwOxfFilterForObject(B_003DD490, object);
        }
    }
    float fraction = object->fraction;
    float result;
    if (fraction != 0.0f) {
        result = g_2dded0 + fraction;
    } else {
        result = g_2a5654;
    }
    object->result = result;
}
