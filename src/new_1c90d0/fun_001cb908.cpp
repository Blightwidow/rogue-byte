struct CRV { char pad[0x1C0]; float field1C0; float field1C4; };
extern "C" {
void InitCrv(CRV *);
void bevy_player_p6_182c70(void *);
}
void func_001CB908(CRV *crv)
{
    InitCrv(crv);
    bevy_player_p6_182c70((char *)crv + 0x190);
    crv->field1C4 = 1.0f;
    crv->field1C0 = 1000.0f;
}
