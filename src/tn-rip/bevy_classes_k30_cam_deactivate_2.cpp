struct AMB;
struct CPZ { char pad[0x10]; int a; int b; float goal; char pad1[0x24]; int keyed; char pad2[0x7C]; AMB *pambZoom; AMB *pambBinoc; };
extern "C" {
extern char B_002DDF40;
void StopAmb(AMB *, float);
void VirtualRefPtr_Assign(AMB **, AMB *);
void SetResetFlag__FP2CM(void *);
void DeactivateCplcy(void *, void *, void *);
void bevy_classes_k30_cam_deactivate_2(CPZ *pcpz, void *pso, void *pv)
{
    if (&pcpz->pambZoom) {
        if (pcpz->pambZoom) {
            StopAmb(pcpz->pambZoom, 0.0f);
            VirtualRefPtr_Assign(&pcpz->pambZoom, 0);
        }
    }
    if (&pcpz->pambBinoc) {
        if (pcpz->pambBinoc) {
            StopAmb(pcpz->pambBinoc, 0.5f);
            VirtualRefPtr_Assign(&pcpz->pambBinoc, 0);
        }
    }
    pcpz->a = 0;
    pcpz->b = 0;
    pcpz->keyed = 0;
    pcpz->goal = -1.0f;
    SetResetFlag__FP2CM(&B_002DDF40);
    DeactivateCplcy(pcpz, pso, pv);
}
}
