extern "C" {
extern float RO_002BFB20;
extern float RO_002BFB24;

void AdjustJtZapNewXp(char *arg0, char *arg1) {
    float first;
    float second;

    switch (*(int *)(arg0 + 0x4)) {
    case 0:
    case 6:
    case 7:
        break;
    case 4:
    case 12:
        *(float *)(arg1 + 0x94) = RO_002BFB20;
        *(int *)(arg1 + 0x98) = 0;
        break;
    default:
        first = RO_002BFB20;
        second = RO_002BFB24;
        *(float *)(arg1 + 0x94) = first;
        *(float *)(arg1 + 0x98) = second;
        break;
    }
}
}
