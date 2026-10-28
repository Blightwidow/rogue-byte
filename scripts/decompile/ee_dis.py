#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""ee_dis.py - disassembles an address range of Sly 2 with what llvm-objdump can't decode on the EE.

  python3 scripts/decompile/ee_dis.py <start hex> <end hex>      (from the lab root)

llvm-objdump (mips64el) for the base instructions, decoded here: lq/sq, lqc2/sqc2, qmfc2/qmtc2/cfc2/ctc2 and the COP2
macro ops with their lane masks (vmul.xy...), MMI words flagged.
"""
import struct,sys,subprocess,re
ELF='work/elf/SCUS_973.16'
f=open(ELF,'rb').read()
phoff=struct.unpack_from('<I',f,0x1c)[0];phentsize,phnum=struct.unpack_from('<HH',f,0x2a)
segs=[]
for i in range(phnum):
    t,off,va,pa,fs,ms,fl,al=struct.unpack_from('<8I',f,phoff+i*phentsize)
    if t==1:segs.append((va,off,fs))
def rd(va):
    for v,o,s in segs:
        if v<=va<v+s:return struct.unpack_from('<I',f,o+va-v)[0]
def rdf(va): return struct.unpack('<f',struct.pack('<I',rd(va)))[0]
bc='xyzw'
S1={0x1c:'vmulq',0x1d:'vmaxi',0x1e:'vmuli',0x1f:'vminii',0x20:'vaddq',0x21:'vmaddq',0x22:'vaddi',0x23:'vmaddi',0x24:'vsubq',0x25:'vmsubq',0x26:'vsubi',0x27:'vmsubi',0x28:'vadd',0x29:'vmadd',0x2a:'vmul',0x2b:'vmax',0x2c:'vsub',0x2d:'vmsub',0x2e:'vopmsub',0x2f:'vmini',0x30:'viadd',0x31:'visub',0x32:'viaddi',0x34:'viand',0x35:'vior',0x38:'vcallms',0x39:'vcallmsr'}
S2={0x10:'vitof0',0x11:'vitof4',0x12:'vitof12',0x13:'vitof15',0x14:'vftoi0',0x15:'vftoi4',0x16:'vftoi12',0x17:'vftoi15',0x1c:'vmulaq',0x1d:'vabs',0x1e:'vmulai',0x1f:'vclipw',0x20:'vaddaq',0x21:'vmaddaq',0x22:'vaddai',0x23:'vmaddai',0x24:'vsubaq',0x25:'vmsubaq',0x26:'vsubai',0x27:'vmsubai',0x28:'vadda',0x29:'vmadda',0x2a:'vmula',0x2c:'vsuba',0x2d:'vmsuba',0x2e:'vopmula',0x2f:'vnop',0x30:'vmove',0x31:'vmr32',0x38:'vdiv',0x39:'vsqrt',0x3a:'vrsqrt',0x3b:'vwaitq',0x3c:'vmtir',0x3d:'vmfir'}
R=['zero','at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7','s0','s1','s2','s3','s4','s5','s6','s7','t8','t9','k0','k1','gp','sp','fp','ra']
def cop2(w):
    dest=(w>>21)&0xf; m=''.join(c for i,c in enumerate('xyzw') if dest&(8>>i))
    ft=(w>>16)&31; fs=(w>>11)&31; fd=(w>>6)&31; fn=w&0x3f
    if fn<0x3c:
        if fn<0x1c:
            nm=['vadd','vsub','vmadd','vmsub','vmax','vmini','vmul'][fn>>2]+bc[fn&3]
            return '%s.%s vf%d, vf%d, vf%d%s'%(nm,m,fd,fs,ft,bc[fn&3])
        nm=S1.get(fn,'s1_%02x'%fn)
        if nm in('vcallms',): return 'vcallms %#x'%(((w>>6)&0x7fff)*8)
        return '%s.%s vf%d, vf%d, vf%d'%(nm,m,fd,fs,ft)
    idx=(fd<<2)|(fn&3)
    if idx<0x10:
        nm=['vadda','vsuba','vmadda','vmsuba'][idx>>2]+bc[idx&3]
        return '%s.%s ACC, vf%d, vf%d%s'%(nm,m,fs,ft,bc[idx&3])
    if 0x18<=idx<0x1c:
        return 'vmula%s.%s ACC, vf%d, vf%d%s'%(bc[idx&3],m,fs,ft,bc[idx&3])
    nm=S2.get(idx,'s2_%02x'%idx)
    if nm=='vdiv': return 'vdiv Q, vf%d%s, vf%d%s'%(fs,bc[(w>>21)&3],ft,bc[(w>>23)&3])
    if nm in('vsqrt','vrsqrt'):
        if nm=='vsqrt': return 'vsqrt Q, vf%d%s'%(ft,bc[(w>>23)&3])
        return 'vrsqrt Q, vf%d%s, vf%d%s'%(fs,bc[(w>>21)&3],ft,bc[(w>>23)&3])
    if nm=='vwaitq': return 'vwaitq'
    return '%s.%s vf%d, vf%d'%(nm,m,ft,fs)
a=int(sys.argv[1],16);b=int(sys.argv[2],16)
out=subprocess.run(['/opt/homebrew/opt/llvm/bin/llvm-objdump','-d','--no-show-raw-insn','--triple=mips64el','--start-address=0x%x'%a,'--stop-address=0x%x'%b,ELF],capture_output=True,text=True).stdout
ins={}
for l in out.split('\n'):
    mm=re.match(r'\s*([0-9a-f]+):\s+(.*)',l)
    if mm: ins[int(mm.group(1),16)]=mm.group(2).strip()
for va in range(a,b,4):
    w=rd(va); t=ins.get(va,'?')
    op=w>>26; rs=(w>>21)&31; rt=(w>>16)&31; rdd=(w>>11)&31; imm=w&0xffff
    if imm>=0x8000: imm-=0x10000
    if op==0x1e: t='lq %s, %d(%s)'%(R[rt],imm,R[rs])
    elif op==0x1f: t='sq %s, %d(%s)'%(R[rt],imm,R[rs])
    elif op==0x36: t='lqc2 vf%d, %d(%s)'%(rt,imm,R[rs])
    elif op==0x3e: t='sqc2 vf%d, %d(%s)'%(rt,imm,R[rs])
    elif op==0x12:
        if rs&0x10: t=cop2(w)
        else: t={1:'qmfc2',2:'cfc2',5:'qmtc2',6:'ctc2'}.get(rs,'cop2?%d'%rs)+' %s, vf%d'%(R[rt],rdd)
    elif op==0x1c: t='MMI fn=%#x sa=%#x %s,%s,%s ; %s'%(w&63,(w>>6)&31,R[rdd],R[rs],R[rt],t)
    print('%X: %08x  %s'%(va,w,t))
