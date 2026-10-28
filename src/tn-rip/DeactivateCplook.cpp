struct CPLOOK {
    int *psoFocus;
    char pad4[0x10 - 4];
    float radPan;
    float radTilt;
    char pad18[0x34 - 0x18];
    int pambZoom;
    int pambBinoc;
    char pad3C[0x4C - 0x3C];
    float radPanSaved;
    float radTiltSaved;
};
extern "C" {
extern char B_002DDF40;
void StopAmb(int, float);
void VirtualRefPtr_Assign(void *, void *);
int FIsBasicDerivedFrom(int *, int);
void bevy_camera_cm_14d8d8(void *, float, float);
void DeactivateCplcy(void *, void *, void *);
}

void DeactivateCplook(CPLOOK *look, void *soFocus, void *pv)
{
    int *zoom = &look->pambZoom;
    if (zoom) {
        if (*zoom) {
            StopAmb(*zoom, 0.0f);
            VirtualRefPtr_Assign(zoom, 0);
        }
    }
    int *binoc = &look->pambBinoc;
    if (binoc) {
        if (*binoc) {
            StopAmb(*binoc, 0.5f);
            VirtualRefPtr_Assign(binoc, 0);
        }
    }
    if (FIsBasicDerivedFrom(look->psoFocus, 0x34))
        bevy_camera_cm_14d8d8(&B_002DDF40, look->radPan + 3.14159274f, -look->radTilt);
    else
        bevy_camera_cm_14d8d8(&B_002DDF40, look->radPanSaved + 3.14159274f, -look->radTiltSaved);
    DeactivateCplcy(look, soFocus, pv);
}
