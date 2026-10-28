extern "C" void func_0017F1A0(void *, void *, int);
extern "C" void func_0017F5B0(void *, void *);
extern "C" int FIsBasicDerivedFrom(void *, int);

struct Obj { char pad[0x1CC]; int flag; };
struct Entry { char pad[0xC]; void *other; char pad2[0x30]; };
struct Contact { Entry e[2]; char pad[0x18]; float f; };

void func_001803E0(Obj *pso, Contact *pcontact, int iside)
{
    func_0017F1A0(pso, pcontact, iside);
    void *other = pcontact->e[1 - iside].other;
    if (FIsBasicDerivedFrom(other, 0x47) == 0 && pso->flag != 0)
        goto set;
    func_0017F5B0(pso, other);
    if (pso->flag != 0) {
set:
        { float one; asm volatile(".set noat\n\tlui $1, 0x3F80\n\tmtc1 $1, %0\n\tnop\n\t.set at" : "=f" (one)); pcontact->f = one; }
    }
}
