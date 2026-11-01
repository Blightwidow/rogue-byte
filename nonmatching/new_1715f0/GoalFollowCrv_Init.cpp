struct GOAL { char pad[0x34]; float f34; char pad1[0x10]; float f48; int f4C; char pad2[0x08]; int f58; char pad3[0x08]; float f64; float f68; float f6C; char pad4[0x30]; int fA0; };
extern "C" void func_001EEF68();
extern float D_FLT_002BE624, D_FLT_002BE628, D_FLT_002BE62C;
extern "C" void GoalFollowCrv_Init(GOAL *goal)
{
    func_001EEF68();
    goal->f64 = D_FLT_002BE62C;
    goal->f68 = D_FLT_002BE624;
    goal->f6C = D_FLT_002BE628;
    goal->f58 = 0;
    goal->f4C = -1;
    goal->f34 = -1.0f;
    goal->f48 = -1.0f;
    goal->fA0 = 1;
}
