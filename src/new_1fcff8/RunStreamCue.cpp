struct SMA;
struct ALO;
struct Cue_1FE0E8 { short pad0; short kind; union { int oid; float closed; }; };
struct Stream_1FE0E8 { char pad[0x22C]; SMA *asma[4]; };
extern "C" void SetAloEyesClosed(ALO *, float);
void SetSmaGoal__FP3SMA3OID(SMA *, int);
extern "C" void RunStreamCue(Stream_1FE0E8 *stream, Cue_1FE0E8 *cue)
{
    int kind = cue->kind;
    if (kind != -1) {
        SMA *sma = stream->asma[kind];
        if (sma != 0) {
            if (kind == 3) {
                SetAloEyesClosed((ALO *)stream->asma[3], cue->closed);
            } else if (cue->oid != -1) {
                SetSmaGoal__FP3SMA3OID(sma, cue->oid);
            }
        }
    }
}
