struct Owner { int unk0; char pad[0x8C]; int unk0x90; float unk0x94; float unk0x98; };
void func_0020B840(Owner *owner, int first, int second)
{
owner->unk0 = first;
owner->unk0x90 = second;
owner->unk0x98 = 1.0f;
owner->unk0x94 = 0.6f;
}
