#!/usr/bin/env python3
# SPDX-License-Identifier: AGPL-3.0-or-later
# Tool of this project; it reads sly1-decomp sources, so the file keeps the AGPL header.
"""sly1_seed_run.py unmatched|matched [N]: compiles each paired Sly 1 file (its own flags from sly1's config/cflags.tsv, ASM_FUNC lines stripped) and scores the paired function against Sly 2's retail words (relocations masked, no link check). Pairs: config/recovered/matches.tsv. Output: work/matching/sly1seed/result-MODE.tsv (sly2, sly1, pair score, method, size, status, our best, outcome, words differing)."""
import json, os, re, subprocess, sys, csv, concurrent.futures
sys.path.insert(0,'scripts/build')
import compile_unit
bodies=json.load(open('work/matching/sly1seed/bodies.json'))
fn={int(r['address'],16):r for r in csv.DictReader(open('data/matching/functions.tsv'),delimiter='\t')}
pairs=list(csv.DictReader(open('config/recovered/matches.tsv'),delimiter='\t'))
mode=sys.argv[1]  # unmatched | matched
limit=int(sys.argv[2]) if len(sys.argv)>2 else 10**9
sel=[]
for r in pairs:
    s2=int(r['sly2_entry'],16); s1=hex(int(r['sly1_entry'],16))
    if s1 not in bodies or s2 not in fn: continue
    st=fn[s2]['status']
    if (mode=='unmatched' and st in ('tried','todo','asm')) or (mode=='matched' and st=='matched'):
        sel.append((s2,s1,float(r['score']),r['method'],int(fn[s2]['size']),st,fn[s2]['best']))
sel=sel[:limit]
os.makedirs('work/matching/sly1seed/drafts',exist_ok=True)
INC=os.path.abspath('work/sly1-decomp/include')
STRIP=re.compile(r'^\s*(INCLUDE_ASM|ASM_FUNC|LINKER_REMNANT|LINKER_REMNANT_AFTER_INIT|INCLUDE_DATA|INCLUDE_RODATA|INCLUDE_BSS)\s*\(.*$',re.M)
objs={}
CF={}
for line in open('work/sly1-decomp/config/cflags.tsv'):
    if line.startswith('#') or not line.strip(): continue
    cols=line.rstrip('\n').split('\t')
    if len(cols)>=2: CF[cols[0]]=(cols[1].split(), cols[2] if len(cols)>2 else '')
def flags_for(rel):
    flags,compiler=CF.get('src/'+rel[4:] if rel.startswith('src/') else rel) or CF['default']
    return tuple(f for f in flags if f not in ('-O2','-G0','-fno-exceptions','-ffast-math')),compiler
def compile_file(rel):
    if rel in objs: return objs[rel]
    text=STRIP.sub('',open('work/sly1-decomp/'+rel,errors='replace').read())
    path='work/matching/sly1seed/drafts/'+rel.replace('/','_')
    open(path,'w').write(text)
    obj=path.rsplit('.',1)[0]+'.o'
    fl,compiler=flags_for(rel)
    ok,msg=compile_unit.compile_object('c++',path,obj,include=INC,localize=False,flags=fl)
    objs[rel]=(obj,None) if ok else (None,(msg or '').strip().split('\n')[0][:110])
    return objs[rel]
def one(c):
    s2,s1,score,method,size,st,best=c
    b=bodies[s1]
    obj,msg=compile_file(b['file'])
    if obj is None: return (s2,s1,score,method,size,st,best,'compile',None,msg)
    best_score=None
    for sym in ('func_%08X'%int(s1,16), b['name']):
        r=subprocess.run(['.venv/bin/python','scripts/matching/compare.py',obj,hex(s2),'--elf','work/elf/SCUS_973.16','--size',str(size),'--symbol',sym,'--quiet'],capture_output=True,text=True)
        m=re.match(r'score (\d+)',r.stdout)
        if m: best_score=int(m.group(1)); break
    return (s2,s1,score,method,size,st,best,'ok' if best_score is not None else 'nosym',best_score,'')
# compile each file once up front (in parallel), then score
files=sorted({bodies[c[1]]['file'] for c in sel})
with concurrent.futures.ThreadPoolExecutor(8) as pool:
    list(pool.map(compile_file,files))
with concurrent.futures.ThreadPoolExecutor(8) as pool:
    res=list(pool.map(one,sel))
out='work/matching/sly1seed/result-%s.tsv'%mode
with open(out,'w') as f:
    for r in res: f.write('\t'.join('' if x is None else str(x) for x in r)+'\n')
print(len(res),'candidates',len(files),'files ->',out, 'files compiled:',sum(1 for v in objs.values() if v[0]))
