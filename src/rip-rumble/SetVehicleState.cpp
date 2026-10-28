struct VT { char pad[0x18]; short d18; short i18; void (*f18)(char *, int, int, int, int, int);
 char pad2[0x188 - 0x20]; short d188; short i188; void (*f188)(char *, int); short d190; short i190; void (*f190)(char *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct VEH {
    char pad0[0xC]; VT *vt;
    char pad1[0x180 - 0x10];
    int state; float tState;
    char pad2[0x568 - 0x188];
    OBJ *pblot;
    char pad3[0x570 - 0x56C];
    void *psma;
    char pad4[0x598 - 0x574];
    void *pamb; int sfxid;
};
extern "C" {
void func_00213B00(OBJ *, int);
void UpdateVehicleHpBlot(VEH *);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, VEH *);
void VirtualRefPtr_Assign(void *, void *);
void SetAmbRange(void *, float, float);
void PauseAmb(void *);
void StopAmb(void *, float);
void SetVehicleAiState(VEH *, int);
void SetSmaGoalIfReachable(void *, int);
extern int D_002C2208[];
extern float g_2dded0;
}

void SetVehicleState(VEH *veh, int state)
{
    if (state == veh->state)
        return;
    switch (veh->state) {
    case 0:
        if (veh->pblot != 0) {
            OBJ *blot = veh->pblot;
            blot->vt->f188((char *)blot + blot->vt->d188, -1);
            func_00213B00(veh->pblot, 0x34F);
            UpdateVehicleHpBlot(veh);
        }
        if (veh->sfxid != -1) {
            void *pamb = NewEmitter(veh->sfxid);
            SetEmitterUnpositioned(pamb, veh);
            VirtualRefPtr_Assign(&veh->pamb, pamb);
            SetAmbRange(veh->pamb, 500.0f, 1500.0f);
            PauseAmb(veh->pamb);
        }
        veh->state = state;
        break;
    case 1:
        SetVehicleAiState(veh, -1);
        veh->state = state;
        break;
    default:
        veh->state = state;
        break;
    }
    veh->tState = g_2dded0;
    void **ppamb;
    switch (state) {
    case 0:
        if (veh->pblot != 0) {
            OBJ *blot = veh->pblot;
            blot->vt->f190((char *)blot + blot->vt->d190);
        }
        ppamb = &veh->pamb;
        if (*ppamb != 0) {
            StopAmb(*ppamb, 0.0f);
            VirtualRefPtr_Assign(ppamb, 0);
        }
        break;
    case 1:
        SetVehicleAiState(veh, 0);
        break;
    case 3:
        veh->vt->f18((char *)veh + veh->vt->d18, 5, 0, 0, 0, 0);
        break;
    }
    if (veh->psma != 0 && veh->state != -1)
        SetSmaGoalIfReachable(veh->psma, D_002C2208[veh->state]);
}
