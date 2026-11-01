// SPDX-License-Identifier: GPL-3.0-or-later
struct AloOidList1F81E0 {
    char pad0[0xAC];
    int count;
    int *oids;
    int selected;
};
extern "C" void SetAloSelectedOid(AloOidList1F81E0 *alo, int oid)
{
    if (oid == -1) { alo->selected = 0; return; }
    int index = 0;
    while (index < alo->count) {
        if (oid == alo->oids[index]) {
            alo->selected = -(index + 3);
            return;
        }
        index++;
    }
    alo->selected = 0;
}
