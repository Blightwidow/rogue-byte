struct UL_1ACCC8 { unsigned long v; } __attribute__((packed));
struct SAVE_1ACCC8 { char pad0[0xFD58]; int field_FD58; char pad1[0xFD6C - 0xFD5C]; int field_FD6C; };
extern "C" {
void CreateMemcardThread__FP7MEMCARDii(void *, long);
int FJoyButtonPressed(int, int);
int FMemcardThreadValid__FP7MEMCARD(void *);
int FSwLoadBusy(void *);
void MemcardMenu_ClearState(void *);
int MemcardMenu_KindOfState(void *);
void MemcardMenu_SetState(void *, int);
void PauseMenu_Close(void *);
void RestartBootQueue(int);
void func_001ACFE0(void *);
void func_001AD168(void *);
extern SAVE_1ACCC8 B_002E65E0;
extern int B_002E65E8;
extern char B_002F633C[];
extern char B_003D9ED0[];
extern char B_003DD490[];
extern const UL_1ACCC8 RO_002A6D88;
extern float g_2ddf0c;
}
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

extern "C" void MemcardMenu_Update(void *self)
{
    void *owner = F(void *, self, 0x24);
    if (owner != 0 && F(int, owner, 0x58) == 2 && F(int, owner, 0x64) == 2 && FSwLoadBusy(B_003DD490) == 0
        && !((g_2ddf0c - F(float, F(void *, self, 0x24), 0x5C)) <= 0.1f)) {
        int kind = MemcardMenu_KindOfState(self);
        int button;
        if (kind == 1) {
            button = 0x80;
            if (F(int, self, 0x10) != 0)
                goto pressed;
            goto dispatch;
        }
        if (kind == 2 && F(int, self, 0x10) != 0) {
            if (FJoyButtonPressed(F(int, self, 0x10), 0x80) == 0) {
                button = 0x10;
                if (F(int, self, 0x10) != 0) {
                pressed:
                    if (FJoyButtonPressed(F(int, self, 0x10), button) != 0)
                        func_001ACFE0(self);
                    else
                        goto dispatch;
                } else {
                    goto dispatch;
                }
            } else {
                func_001AD168(self);
            }
            return;
        }
    dispatch:
        switch (F(int, self, 0x40)) {
        case 32:
        case 34:
            if (F(int, self, 0x44) != 1)
                MemcardMenu_ClearState(self);
            break;
        case 17:
        case 18:
        case 21:
        case 24:
        case 46:
            if (B_002E65E8 == 6)
                MemcardMenu_ClearState(self);
            break;
        case 19:
            if (FMemcardThreadValid__FP7MEMCARD(B_002F633C) == 0) {
                if (B_002E65E0.field_FD6C == 0) {
                    CreateMemcardThread__FP7MEMCARDii(B_002F633C, RO_002A6D88.v);
                    MemcardMenu_SetState(self, 0x16);
                } else {
                    MemcardMenu_SetState(self, 0x14);
                }
            }
            break;
        case 22:
            if (FMemcardThreadValid__FP7MEMCARD(B_002F633C) == 0) {
                if (B_002E65E0.field_FD6C != 0)
                    MemcardMenu_SetState(self, 0x17);
                else
                    MemcardMenu_ClearState(self);
            }
            break;
        case 26:
            if (FMemcardThreadValid__FP7MEMCARD(B_002F633C) == 0) {
                if (B_002E65E0.field_FD6C != 0) {
                    if (F(int, self, 0x4C) == 3)
                        MemcardMenu_SetState(self, 0x23);
                    else
                        MemcardMenu_SetState(self, 0x1D);
                } else {
                    MemcardMenu_ClearState(self);
                    int next = F(int, self, 0x4C);
                    switch (next) {
                    case 1:
                        RestartBootQueue(next);
                        break;
                    case 2:
                        PauseMenu_Close(B_003D9ED0);
                        break;
                    }
                }
            }
            break;
        case 33:
            if (FMemcardThreadValid__FP7MEMCARD(B_002F633C) == 0) {
                B_002E65E0.field_FD58 = 0;
                if (B_002E65E0.field_FD6C == 0)
                    MemcardMenu_ClearState(self);
                else
                    MemcardMenu_SetState(self, 0x1D);
            }
            break;
        }
    }
}
