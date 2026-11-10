#include "sly.h"
extern "C" {
void ExtendSoBounds(SLY *, s128, float);
void UpdateSoBounds(SLY *);
void UpdateJtBounds(SLY *jt) {
    int i;
    UpdateSoBounds(jt);
    for (i = 0; i < jt->cbounds; i++) {
        ExtendSoBounds(jt, jt->abounds[i], jt->rBounds);
    }
}
}
