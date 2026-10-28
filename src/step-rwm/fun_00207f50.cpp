#include "sly2.h"
struct ANIMREF { int kind; int pv; int pad0; int n; };
struct STEPGUARD;
extern "C" void ResetAnimref(ANIMREF *, STEPGUARD *);
extern "C" void BindAnimref(ANIMREF *, STEPGUARD *);
void func_00207F50(STEPGUARD *guard, unsigned grf, int oid, int n, ANIMREF *arr)
{ unsigned mask = 1; int i = 25; do { if (grf & mask) { ResetAnimref(arr, guard); arr->pv = oid; arr->n = n; BindAnimref(arr, guard); } mask <<= 1; arr++; } while (--i >= 0); }
