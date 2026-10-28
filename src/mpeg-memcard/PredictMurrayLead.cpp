#include "sly2.h"
extern QW g_2a2dd0;
extern "C" void PredictLoLead(void *, void *);
extern "C" void PredictMurrayLead(char *self, char *out)
{
    PredictLoLead(self, out);
    switch (*(unsigned *)(self + 0x13D0)) {
    case 11:
        *(int *)out = 1;
        *(QW *)(out + 0x10) = *(QW *)(self + 0x1830);
        *(QW *)(out + 0x20) = g_2a2dd0;
        break;
    case 0: case 1: case 9: case 10:
        *(int *)out = 1;
        break;
    default:
        break;
    }
    *(float *)(out + 4) = 200.0f;
}
