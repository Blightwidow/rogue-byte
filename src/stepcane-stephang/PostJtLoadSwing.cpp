// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
void EnsureAsegBlendDynamic(void *, int, int, void *, int, const int *, const int *, void *);
}

extern "C" void PostJtLoadSwing(void *pOwner, void *pArg1, void **ppOut)
{
    void *pAseg;
    EnsureAsegBlendDynamic(pOwner, 0xC, 3, pArg1, 0, 0, 0, &pAseg);
    if (ppOut != 0) *ppOut = pAseg;
}
