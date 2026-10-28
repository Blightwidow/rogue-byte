#include "sly2.h"
struct OWNER { virtual void f0(void *); void g(void *); };
typedef void (OWNER::*PMF)(void *);
struct ARGS { int oid; PMF pmf; };
extern "C" void *PloFindSwObject_thunk(void *, int, int, void *);
extern char B_003DD490[];
void DcbCallOptionPlo(OWNER *owner, ARGS *args)
{
    void *plo = PloFindSwObject_thunk(B_003DD490, 4, args->oid, owner);
    (owner->*(args->pmf))(plo);
}
