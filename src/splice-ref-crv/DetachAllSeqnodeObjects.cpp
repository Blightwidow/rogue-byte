struct Seq { char pad[0xA4]; int count; int first[4]; int second[4]; int third[4]; };
extern "C" void DetachSeqnodeObject(Seq *, int, int, int);
extern "C" void DetachAllSeqnodeObjects(Seq *seq)
{
    while (seq->count) {
        int last = seq->count - 1;
        DetachSeqnodeObject(seq, seq->first[last], seq->second[last], seq->third[last]);
    }
}
