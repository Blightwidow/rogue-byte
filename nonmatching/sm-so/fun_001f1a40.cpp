struct Pair_1F1A40 { int weight; int value; };
struct Row_1F1A40 { int min; int max; float chance; Pair_1F1A40 pairs[6]; };
struct Item_1F1A40 { int type; int a4; int a8; int count; };
struct Obj_1F1A40 {
    char pad[0x404]; Item_1F1A40 items[8]; int itemCount; char pad2[0x490 - 0x488]; int busy; int owner;
};
struct Target_1F1A40 { char pad[0x230]; int task; };
extern "C" void ClearPrizeSpewer(int);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int FTaskComplete(int);
extern "C" float GRandInRange(float, float);
extern "C" int IEpisodeCurrent();
extern "C" int NRandInRange(int, int);
extern "C" Target_1F1A40 *PloFindSwObject_thunk(void *, int, int, int);
extern "C" void *memset(void *, int, unsigned);
extern char B_003DD490[];
extern Row_1F1A40 D_002C3748[];
extern Row_1F1A40 D_002C3968[];
extern "C" void func_001F1A40(Obj_1F1A40 *self) {
    Item_1F1A40 saved;
    ClearPrizeSpewer(self->owner);
    if (self->busy == 0) {
        int episode = IEpisodeCurrent();
        int row_index = (~episode != 0) ? episode : 1;
        Row_1F1A40 *row;
        if (FIsBasicDerivedFrom(self, 0x3A) != 0) {
            row = D_002C3968 + row_index;
        } else {
            row = D_002C3748 + row_index;
        }
        memset(&saved, 0, 0x10);
        if (self->itemCount > 0) {
            Target_1F1A40 *target = PloFindSwObject_thunk(B_003DD490, 4, self->items[0].type, self->owner);
            if (target != 0 && FIsBasicDerivedFrom(target, 0x5C) != 0) {
                int task = target->task;
                if (task != 0 && FTaskComplete(task) != 0) {
                    self->itemCount = 0;
                }
            }
            if (self->itemCount > 0) {
                saved = self->items[0];
                self->itemCount = 0;
                goto distribute;
            }
        }
        {
            if (row->chance < GRandInRange(0.0f, 1.0f)) {
                saved.a8 = -1;
                saved.type = -1;
            } else {
                int total = 0;
                unsigned count = 0;
                Pair_1F1A40 *pair = row->pairs;
                do {
                    int weight = pair->weight;
                    count += 1;
                    pair += 1;
                    total += weight;
                } while (count < 6U);
                int roll = NRandInRange(0, total - 1);
                int weight = row->pairs[0].weight;
                unsigned index = 0;
                while (roll >= weight) {
                    index += 1;
                    roll -= weight;
                    if (index >= 6U) {
                        goto finished;
                    }
                    weight = row->pairs[index].weight;
                }
                saved.a8 = row->pairs[index].value;
            finished:
                saved.count = 1;
                saved.type = 0x2B5;
            }
        }
        self->itemCount = 0;
    distribute:
        int budget = NRandInRange(row->min, row->max);
        int pieces = NRandInRange(2, 3);
        if (pieces > 0) {
            int done = 0;
            int remaining = pieces;
            do {
                int count = self->itemCount;
                self->itemCount = count + 1;
                int share = budget / remaining;
                Item_1F1A40 *item = &self->items[count];
                item->type = 0x2B3;
                item->a4 = 0;
                int amount = (share > 0) ? share : 1;
                budget -= amount;
                item->count = amount;
                if (budget == 0) {
                    break;
                }
                done += 1;
                remaining = pieces - done;
            } while (done < pieces);
        }
        if (saved.count > 0) {
            int count = self->itemCount;
            self->items[count] = saved;
            self->itemCount = count + 1;
        }
    }
}
