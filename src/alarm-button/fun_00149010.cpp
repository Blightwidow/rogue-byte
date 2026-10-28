extern "C" {
extern float g_2dded0;
int FIsBasicDerivedFrom(void *, int);
void SetButtonButtons(void *, int);
}
struct Other { char pad[0x2C4]; int state; char pad2[0x2DC - 0x2C8]; int kind; float time; };
struct Button { char pad[0x2F8]; Other *target; };
void func_00149010(Button *button)
{
    if (FIsBasicDerivedFrom(button->target, 0x34)) {
        Other *other = button->target;
        if (other->kind == 0x11)
            goto clear;
        if (other->state == 3) {
            if (g_2dded0 - other->time < 0.15f) {
clear:
                button->target = 0;
                return;
            }
        }
    }
    SetButtonButtons(button, 1);
}
