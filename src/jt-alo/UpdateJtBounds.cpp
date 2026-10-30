typedef int s128 __attribute__((mode(TI)));
struct JT { char pad[0x1880]; int c; char pad2[0xC]; s128 bounds[17]; char pad3[0x19AC - 0x1890 - 17*16]; float r; };
extern "C" {
void ExtendSoBounds(JT *, s128, float);
void UpdateSoBounds(JT *);
void UpdateJtBounds(JT *jt) {
    int i;
    UpdateSoBounds(jt);
    for (i = 0; i < jt->c; i++) {
        ExtendSoBounds(jt, jt->bounds[i], jt->r);
    }
}
}
