extern "C" { void SetAlertState(char *, int); extern float g_2dded0; }
struct Alert_20A730 { float f0; char pad[0x24]; int count; int guards[8]; };
extern "C" void AddAlertGuard(Alert_20A730 *alert, int guard) {
    if (alert->count == 0) { alert->f0 = g_2dded0; SetAlertState((char *)alert, 0); }
    int n = alert->count;
    alert->guards[n] = guard;
    alert->count = n + 1;
}
