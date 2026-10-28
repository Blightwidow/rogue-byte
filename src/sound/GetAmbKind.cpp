struct AMB { char pad[0x60]; int sfxid; };
struct E { int kind; };
extern "C" char B_003DD040;
extern "C" E *func_001FD028(void *, int);
extern "C" int GetAmbKind(AMB *pamb)
{
    E *e = func_001FD028(&B_003DD040, pamb->sfxid);
    int kind = -1;
    if (e) kind = e->kind;
    return kind;
}
