extern "C" void ClearGuardAimObjects(char *guard) {
    *(int *)(guard + 0xED8) = 0;
    *(int *)(guard + 0xEFC) = 0;
}
