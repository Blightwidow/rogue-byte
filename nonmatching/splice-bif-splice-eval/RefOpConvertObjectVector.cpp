typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; void *pv; };
extern "C" {
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
QW bevy_camera_follow_track_heading_weight(void *, void *, QW);
CRef *RefOpConvertObjectVector(CRef *result, int count, CRef *args)
{
    CRef temp;
    SetTag__4CRef4TAGK(&temp, 0x1A);
    QW *dest = (QW *)temp.pv;
    *dest = bevy_camera_follow_track_heading_weight(args[0].pv, args[1].pv, *(QW *)args[2].pv);
    CRef_CopyConstruct(result, &temp);
    CRef_Destruct(&temp);
    return result;
}
}
