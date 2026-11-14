#!/usr/bin/env python3
# SPDX-License-Identifier: AGPL-3.0-or-later
# Tool of this project; it reads sly1-decomp sources, so the file keeps the AGPL header.
"""sly1_seed_extract.py: the C body of each Sly 1 function by US address, from a local checkout of OpenThievius/sly1-decomp in work/sly1-decomp (AGPL-3.0, same maintainers). Writes work/matching/sly1seed/bodies.json."""
import re, glob, json, os
S1='work/sly1-decomp'
alias={}  # readable name -> address, address -> readable
for line in open(S1+'/include/names.h'):
    m=re.match(r'#define\s+(\w+)\s+func_([0-9A-Fa-f]{8})\b',line)
    if m: alias.setdefault(int(m.group(2),16),[]).append(m.group(1))
def body_end(t,i):
    d=0
    while i<len(t):
        c=t[i]
        if c=='{': d+=1
        elif c=='}':
            d-=1
            if d==0: return i+1
        i+=1
    return -1
out={}
for p in sorted(glob.glob(S1+'/src/**/*.cpp',recursive=True)+glob.glob(S1+'/src/**/*.c',recursive=True)):
    t=open(p,errors='replace').read()
    head='\n'.join(l for l in t.split('\n') if l.startswith('#include'))
    for m in re.finditer(r'^([A-Za-z_][^\n;{}()]*?)\b(\w+)\s*\(([^;{}]*)\)\s*(const\s*)?\n?\{',t,re.M):
        name=m.group(2)
        a=None
        mm=re.fullmatch(r'func_([0-9A-Fa-f]{8})',name)
        if mm: a=int(mm.group(1),16)
        else:
            for ad,names in alias.items():
                if name in names: a=ad; break
        if a is None or a in out: continue
        s=m.start(); e=body_end(t,m.end()-1)
        if e<0: continue
        out[a]=dict(file=os.path.relpath(p,S1),name=name,text=t[s:e],head=head)
json.dump({hex(a):v for a,v in out.items()},open('work/matching/sly1seed/bodies.json','w'))
print(len(out),'sly1 C bodies;',len(alias),'aliases')
