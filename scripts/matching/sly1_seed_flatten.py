#!/usr/bin/env python3
# SPDX-License-Identifier: AGPL-3.0-or-later
# Tool of this project; it reads sly1-decomp sources, so the file keeps the AGPL header.
"""sly1_seed_flatten.py: flattens each non-zero Sly 1 seed within 16 words (result-unmatched.tsv of sly1_seed_run.py) into one standalone source for Sly 2's scorer: preprocess with sly1's headers, drop every other function of its file, rename the target to Sly 2's name. Search with SCORER_NO_LINK=1 (callees keep Sly 1 names). Output: work/matching/sly1seed/flat/ADDRESS.cpp and made.json."""
import json, os, re, subprocess, sys, csv
sys.path.insert(0,'scripts/build')
import compile_unit as c
bodies=json.load(open('work/matching/sly1seed/bodies.json'))
fn={int(r['address'],16):r for r in csv.DictReader(open('data/matching/functions.tsv'),delimiter='\t')}
INC=os.path.abspath('work/sly1-decomp/include')
sys.argv=[sys.argv[0]]+sys.argv[1:]
rows=[l.rstrip('\n').split('\t') for l in open('work/matching/sly1seed/result-unmatched.tsv')]
cands=[r for r in rows if r[7]=='ok' and 0<int(r[8])<=16]
out_dir='work/matching/sly1seed/flat'; os.makedirs(out_dir,exist_ok=True)
CF={}
for line in open('work/sly1-decomp/config/cflags.tsv'):
    if line.startswith('#') or not line.strip(): continue
    cols=line.rstrip('\n').split('\t')
    if len(cols)>=2: CF[cols[0]]=cols[1].split()
def flags(rel):
    f=CF.get(rel) or CF['default']
    return [x for x in f if x not in ('-O2','-G0','-fno-exceptions','-ffast-math')]
def brace_end(t,i):
    d=0
    while i<len(t):
        if t[i]=='{': d+=1
        elif t[i]=='}':
            d-=1
            if d==0: return i+1
        i+=1
    return -1
made=[]
for r in cands:
    s2=int(r[0]); s1=r[1]; b=bodies[s1]
    draft='work/matching/sly1seed/drafts/'+b['file'].replace('/','_')
    d=c.compiler_directory(); v=os.listdir(os.path.join(d,'lib','gcc-lib','ee'))[0]
    ii=os.path.join(out_dir,'%X.ii'%s2)
    res=subprocess.run([c.WIBO,os.path.join(d,'bin','ee-gcc.exe'),'-x','c++',f'-B{os.path.join(d,"lib","gcc-lib","ee",v)}/',f'-I{INC}',*c.FLAGS,*flags(b['file']),'-E',os.path.abspath(draft),'-o',os.path.abspath(ii)],capture_output=True,text=True)
    if res.returncode: print(hex(s2),'preprocess failed',res.stderr[:100]); continue
    text=open(ii,errors='replace').read()
    target='func_%08X'%int(s1,16)
    # drop # line markers, split main-file regions
    lines=text.split('\n'); cur=''; kept=[]
    for l in lines:
        m=re.match(r'#\s+\d+\s+"([^"]*)"',l)
        if m: cur=m.group(1); continue
        if l.startswith('#'): continue
        kept.append((cur,l))
    main=os.path.abspath(draft)
    out=[]; buf=[]
    def flush():
        pass
    # rebuild by region: header regions verbatim, main region with other functions removed
    regions=[]; last=None
    for cur,l in kept:
        is_main=cur.endswith(os.path.basename(draft))
        if regions and regions[-1][0]==is_main: regions[-1][1].append(l)
        else: regions.append([is_main,[l]])
    text_out=[]
    for is_main,ls in regions:
        t='\n'.join(ls)
        if is_main:
            res_t=''; pos=0
            for m in re.finditer(r'^([A-Za-z_][^\n;{}()]*?)\b(\w+)\s*\(([^;{}]*)\)\s*(const\s*)?\n?\{',t,re.M):
                if m.start()<pos: continue
                e=brace_end(t,m.end()-1)
                if e<0: continue
                if m.group(2)==target: continue
                res_t+=t[pos:m.start()]; pos=e
            res_t+=t[pos:]
            t=res_t
        text_out.append(t)
    flat='\n'.join(text_out)
    if target not in flat: print(hex(s2),'target lost'); continue
    base=re.sub(r'__F.*$','',fn[s2]['name'])
    flat=re.sub(r'\b%s\b'%target,base,flat)
    flat='// SPDX-License-Identifier: GPL-3.0-or-later\n// source:sly1-decomp (flattened, a search draft only)\n'+flat
    path=os.path.join(out_dir,'%X.cpp'%s2); open(path,'w').write(flat)
    made.append((s2,path,fn[s2]['name'],int(r[8])))
json.dump(made,open(os.path.join(out_dir,'made.json'),'w'))
print(len(made),'flattened of',len(cands))
