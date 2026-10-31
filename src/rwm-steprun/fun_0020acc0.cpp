typedef int QW __attribute__((mode(TI)));
struct V_20ACC0 { char pad[0x30]; QW quad30; char pad1[0x60]; void *w; };
struct H_20ACC0 { char pad[0x90]; QW quad90; V_20ACC0 *v; };
struct Top_20ACC0 { char pad[0xF08]; H_20ACC0 *h; char *dest; void *arg10; char pad2[4]; QW quadF20; };
extern "C" {
void BuildRotateVectorsMatrix(void *, QW, QW);
QW ConvertXfPos(void *, void *, QW);
QW DecomposeRotateMatrixEuler(void *);

void func_0020ACC0(Top_20ACC0 *top) {
    char sp[0x30];
    QW pos = ConvertXfPos(top->arg10, top->h->v->w, top->quadF20);
    H_20ACC0 *h = top->h;
    V_20ACC0 *v = h->v;
    QW diff;
    int fence;
    asm("qmtc2.ni %1, vf2" : "=r" (fence) : "r" (pos));
    asm("lqc2 vf1, 0x30(%2)\n\tvsub.xyzw vf2, vf2, vf1\n\tqmfc2.ni %0, vf2" : "=r" (diff) : "r" (fence), "r" (v));
    BuildRotateVectorsMatrix(sp, h->quad90, diff);
    char *dest = top->dest;
    *(QW *)(dest + 0x20) = DecomposeRotateMatrixEuler(sp);
}
}
