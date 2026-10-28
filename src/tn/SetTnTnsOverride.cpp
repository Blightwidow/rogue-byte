struct Tn { char pad[0x13C]; int override; };
extern "C" void UpdateTnCallback(Tn *, int);
void SetTnTnsOverride(Tn *tn, int value)
{
    if (value != tn->override) {
        tn->override = value;
        UpdateTnCallback(tn, 0);
    }
}
