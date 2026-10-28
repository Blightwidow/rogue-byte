extern "C" {
void __main__Fv(void);
void StartupAll(void);
void func_001613A8(void);
void ExecuteSwLoadRequest(void *);
void UpdateSw(void *);
void func_0014D470(void *);
void func_001CDA80(void *);
void FlushRenderRecords(void *);
int FUpdateSwDuringWipe(void *);
void UpdateWipe(void *);
}
struct JOY; struct CLOCK; struct CGc { void UpdateRecyclable(); };
void UpdateJoy(JOY *);
void UpdateCd(void);
extern "C" void MarkClockTick__FP5CLOCK(CLOCK *, int);
extern "C" void CGc_Update(void *);
void OpenFrame(void);
void CloseFrame(void);
extern "C" {
extern int B_002E2050, B_002E2054, g_2be538;
extern void *g_2dd644;
extern char g_2dded0[], B_002DDF40[], B_002DFC00[], B_003DD490[], B_003D9E70[];
}
int main(int argc, int argv) {
    B_002E2050 = argc;
    B_002E2054 = argv;
    StartupAll();
    func_001613A8();
    for (;;) {
        ExecuteSwLoadRequest(B_003DD490);
        UpdateJoy((JOY *)B_002DFC00);
        UpdateCd();
        func_0014D470(B_002DDF40);
        MarkClockTick__FP5CLOCK((CLOCK *)g_2dded0, 0);
        UpdateSw(B_003DD490);
        CGc_Update(B_003D9E70);
        OpenFrame();
        if (g_2dd644 == 0 || FUpdateSwDuringWipe(g_2dd644)) {
            func_001CDA80(B_003DD490);
            FlushRenderRecords(B_003DD490);
            ((CGc *)B_003D9E70)->UpdateRecyclable();
        }
        if (g_2dd644) UpdateWipe(g_2dd644);
        CloseFrame();
        g_2be538++;
    }
}
