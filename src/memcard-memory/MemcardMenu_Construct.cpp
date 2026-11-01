extern "C" {
int Menu_Construct(void *);
void Menu_ResetState(void *);
extern int D_002D3750;

void *MemcardMenu_Construct(void *self) {
    Menu_Construct(self);
    *(int **)((char *)self + 0xC) = &D_002D3750;
    *(int *)((char *)self + 0x20) = 0x52C;
    *(int *)((char *)self + 0x40) = -1;
    Menu_ResetState(self);
    return self;
}

}
