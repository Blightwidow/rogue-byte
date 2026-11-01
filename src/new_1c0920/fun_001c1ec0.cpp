typedef int QW __attribute__((mode(TI)));
struct TGT { void *crv; void *plo; int pad8[2]; QW vec; };
extern "C" {
extern char B_003DD020[];
void FindCrvClosestPointAll(void *, int, char *, QW *, int, int, int);
QW PosLoWorld(void *);
QW func_001C1EC0(TGT *target, int arg1) {
    QW result;
    if (target->crv) {
        FindCrvClosestPointAll(target->crv, arg1, B_003DD020, &result, 0, 0, 0);
    } else if (target->plo) {
        result = PosLoWorld(target->plo);
    } else {
        result = target->vec;
    }
    return result;
}
}
