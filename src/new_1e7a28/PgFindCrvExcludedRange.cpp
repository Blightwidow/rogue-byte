struct RANGE { float lo; float hi; };
struct CRVEX { char pad[0xC]; int crange; RANGE arange[1]; };
extern "C" RANGE *PgFindCrvExcludedRange(CRVEX *crv, float s)
{
    RANGE *arange = crv->arange;
    for (int irange = 0; irange < crv->crange; irange++) {
        RANGE *prange = &arange[irange];
        if (prange->lo <= s) {
            if (s <= prange->hi)
                return prange;
        }
    }
    return 0;
}
