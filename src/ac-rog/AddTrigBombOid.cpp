struct TrigBomb { char pad[0x238]; unsigned count; int oids[4]; };
void AddTrigBombOid(TrigBomb *self, int oid)
{
    unsigned count = self->count;
    if (count < 4) {
        self->oids[count] = oid;
        self->count = count + 1;
    }
}
