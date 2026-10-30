/* SPDX-License-Identifier: GPL-3.0-or-later */
/* SPDX-License-Identifier: GPL-3.0-or-later */
struct MEMCARD_1AB128 { int unused; };
struct SAVE_1AB128 {
    int a; int b; int c; int d; float e; float f; int g; int h; int i;
    char pad[0xFD5C - 0x24];
    MEMCARD_1AB128 memcard;
};
extern "C" void InitMemcard__FP7MEMCARD(MEMCARD_1AB128 *);
extern "C" void sceMcInit();
extern "C" void InitSave(SAVE_1AB128 *save, int a, int b) {
    sceMcInit();
    InitMemcard__FP7MEMCARD(&save->memcard);
    save->a = a;
    save->b = b;
    save->c = -1;
    save->d = 0;
    save->e = save->f = 0.0f;
    save->g = 0;
    save->h = 0;
    save->i = 0;
}
