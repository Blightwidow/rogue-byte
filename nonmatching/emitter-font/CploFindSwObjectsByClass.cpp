typedef unsigned char u8; typedef int s32; typedef unsigned int u32; typedef unsigned long u64;
struct Sw {
    char pad0[0x10]; Sw *next10; char pad14[0xC]; Sw *next20; Sw *next24; u64 bits28;
};
struct Owner {
    char pad0[0x10]; Sw *head10; char pad14[0x50]; Sw *head64; char pad68[0x8]; Sw *end70;
};
extern "C" {
s32 FIsBasicDerivedFrom(Sw *, s32);
s32 FIsCidDerivedFrom(s32, s32);
s32 MatchSwObject(void *, Sw *, s32, u32, Owner *, s32, s32, s32 *, Sw **, s32 *);
Sw **PdlFromSwCid(void *, s32);
}
static inline s32 BitSet(Sw *sw) { return (s32)(sw->bits28 >> 60) & 1; }
static inline void SetIndex(Sw *sw, s32 value) { ((u8 *)sw)[0x2C] = (u8)value; }
static inline void Store(Sw **out, s32 index, Sw *sw) { out[index] = sw; }
extern "C" s32 CploFindSwObjectsByClass(void *world, u32 flags, s32 cid, Owner *owner, s32 max, Sw **out) {
    struct { s32 unused; s32 count; s32 limit; Sw *list; s32 keep; } st;
    Sw *sw;
    if (cid == -1) return 0;
    s32 kind = flags & 0xFF;
    if (owner == 0 && kind != 5) return 0;
    st.count = 0;
    switch (kind) {
    case 3:
        {
            sw = owner->head10;
            st.keep = flags & 0x200;
            if (sw != 0) {
                do {
                    if (FIsBasicDerivedFrom(sw, cid) != 0 && (!(flags & 0x100) || BitSet(sw))) {
                        if (st.count < max) Store(out, st.count, sw);
                        st.count++;
                    }
                    sw = sw->next10;
                } while (sw != 0);
            }
        }
        break;
    case 2:
        {
            Sw *end = 0;
            if (flags & 0x100) end = owner->end70;
            sw = owner->head64;
            st.keep = flags & 0x200;
            if (sw != end) {
                do {
                    if (FIsBasicDerivedFrom(sw, cid) != 0) {
                        if (st.count < max) Store(out, st.count, sw);
                        st.count++;
                    }
                    sw = sw->next24;
                } while (sw != end);
            }
        }
        break;
    case 5:
        st.keep = flags & 0x200;
        for (s32 index = cid; index < 0xC7 && FIsCidDerivedFrom(index, cid) != 0; index++) {
            PdlFromSwCid(world, index);
            sw = *PdlFromSwCid(world, index);
            if (sw != 0) {
                s32 n = st.count;
                do {
                    if (!(flags & 0x100) || BitSet(sw)) {
                        if (n < max) Store(out, n, sw);
                        n++;
                    }
                    sw = sw->next20;
                } while (sw != 0);
                st.count = n;
            }
        }
        break;
    default:
        if (kind == 1 || (kind != 0 && kind < 6 && kind >= 3)) {
            s32 number = 0;
            sw = (Sw *)owner;
            st.list = sw;
            for (; sw != 0; sw = sw->next10) {
                number++;
                SetIndex(sw, number);
            }
            st.keep = flags & 0x200;
            st.limit = 0x7FFFFFFF;
        } else {
            st.list = 0;
            st.keep = flags & 0x200;
        }
        for (s32 index = cid; index < 0xC7 && FIsCidDerivedFrom(index, cid) != 0; index++) {
            PdlFromSwCid(world, index);
            sw = *PdlFromSwCid(world, index);
            while (sw != 0) {
                MatchSwObject(world, sw, 0, flags | 0x400, owner, 0, max, &st.count, out, &st.limit);
                sw = sw->next20;
            }
        }
        sw = st.list;
        if (sw != 0) {
            do {
                SetIndex(sw, 0);
                sw = sw->next10;
            } while (sw != 0);
        }
        break;
    }
    if (st.keep == 0) {
        if (max < st.count) st.count = max;
    }
    return st.count;
}
