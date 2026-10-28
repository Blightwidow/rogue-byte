extern "C" float g_2dded0;
extern "C" void RemoveRip(void *);

struct B8 { char b[8]; };
struct OBJ { virtual void v0(); int pad; };
typedef void (OBJ::*PMF)(void *);

struct SMI { char pad[0x60]; B8 pmf; };
struct SMACK {
    char pad0[0x14];
    float created;
    float lifetime;
    char pad1[0xF0 - 0x1C];
    SMI *info;
    OBJ *target;
    void *arg;
};

void UpdateSmack(SMACK *smack, float dt)
{
    if (smack->lifetime < g_2dded0 - smack->created) {
        PMF pmf;
        *(B8 *)&pmf = smack->info->pmf;
        (smack->target->*pmf)(smack->arg);
        RemoveRip(smack);
    }
}
