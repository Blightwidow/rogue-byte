struct SGG { char pad[0x84]; int count; int alarms[1]; };
extern "C" int FSggHasAlarm(SGG *sgg, int alarm)
{
    int index;
    for (index = 0; index < sgg->count; index++) {
        if (sgg->alarms[index] == alarm)
            return 1;
    }
    return 0;
}
