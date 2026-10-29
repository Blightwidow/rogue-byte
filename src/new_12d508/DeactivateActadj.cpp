struct ACTADJ_VT_12D890 { char pad[0x10]; short nOffset; char pad2[0x2]; void (*pfnApply)(void *); };
struct ACTADJ_OBJ_12D890 { char pad[0x18]; struct ACTADJ_VT_12D890 *pVt; };
struct ACTADJ_12D890 { char pad[0x1C]; struct ACTADJ_OBJ_12D890 *pTarget; };

extern "C" void DeactivateActadj(struct ACTADJ_12D890 *pActadj)
{
    struct ACTADJ_OBJ_12D890 *pTarget = pActadj->pTarget;
    if (pTarget != 0) {
        pTarget->pVt->pfnApply((char *)pTarget + pTarget->pVt->nOffset);
        pActadj->pTarget = 0;
    }
}
