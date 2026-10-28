struct Please { int a, b; int c; };
extern "C" Please *PleaseFromPlo();
void UnlockLeaseOfPlo() {
    Please *please = PleaseFromPlo();
    if (please) please->c = 0;
}
