// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D7468-0X2D77D8 (piece data/rip_1cde70_2d7468), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void FBounceFlying__FP6FLYINGP2SOP6VECTORT2();
extern "C" void FBounceLeaf__FP4LEAFP2SOP6VECTORT2();
extern "C" void FBounceRip__FP3RIPP2SOP6VECTORT2();
extern "C" void FBounceShrapnel();
extern "C" void InitBublet__FP6BUBLETP6VECTORfP2SO();
extern "C" void InitDroplet__FP7DROPLETP6VECTORfP2SO();
extern "C" void InitGlint__FP5GLINTP6VECTORfP2SO();
extern "C" void InitMatch__FP5MATCHP6VECTORfP2SO();
extern "C" void InitRip__FP3RIPP6VECTORfP2SO();
extern "C" void InitSmack__FP5SMACKP6VECTORfP2SO();
extern "C" void OnRipRemoveNop();
extern "C" void PostDropletEmit();
extern "C" void PostFlyingEmit();
extern "C" void PostLeafEmit__FP4LEAFP5EMITB();
extern "C" void PostRemitEmit__FP5REMITP5EMITB();
extern "C" void PostShrapnelEmit__FP8SHRAPNELP5EMITB();
extern "C" void ProjectBubletTransform__FP6BUBLETf();
extern "C" void ProjectGlintTransform();
extern "C" void ProjectLeafTransform__FP4LEAFf();
extern "C" void ProjectMatchTransform__FP5MATCHf();
extern "C" void ProjectRipTransform__FP3RIPf();
extern "C" void ProjectSmackTransform__FP5SMACKf();
extern "C" void RenderFlying__FP6FLYINGP2CM();
extern "C" void RenderGlint__FP5GLINTP2CM();
extern "C" void RenderMatch__FP5MATCHP2CM();
extern "C" void RenderOrbit__FP5ORBITP2CM();
extern "C" void RenderRip();
extern "C" void RenderSmack();
extern "C" void RenderStuck__FP5STUCKP2CM();
extern "C" void TouchBublet__FP6BUBLETi();
extern "C" void TouchDroplet__FP7DROPLETi();
extern "C" void TouchRip__FP3RIPi();
extern "C" void UpdateMatch__FP5MATCHf();
extern "C" void UpdateRemit__FP5REMITf();
extern "C" void UpdateRip__FP3RIPf();
extern "C" void UpdateSmack();
extern "C" void UpdateStuck__FP5STUCKf();
extern "C" void func_001CE9B8();

// data-ok: retail's bytes at 0X2D7468
void *D_002D7468[20] = {0, 0, 0, (void *)InitRip__FP3RIPP6VECTORfP2SO, 0, (void *)PostRemitEmit__FP5REMITP5EMITB, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectRipTransform__FP3RIPf, 0, (void *)UpdateRemit__FP5REMITf, 0, (void *)RenderRip, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceRip__FP3RIPP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D74B8
void *D_002D74B8[20] = {0, 0, 0, (void *)InitRip__FP3RIPP6VECTORfP2SO, 0, (void *)PostLeafEmit__FP4LEAFP5EMITB, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectLeafTransform__FP4LEAFf, 0, (void *)UpdateRip__FP3RIPf, 0, (void *)RenderRip, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceLeaf__FP4LEAFP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D7508
void *D_002D7508[20] = {0, 0, 0, (void *)InitBublet__FP6BUBLETP6VECTORfP2SO, 0, (void *)func_001CE9B8, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectBubletTransform__FP6BUBLETf, 0, (void *)UpdateRip__FP3RIPf, 0, (void *)RenderRip, 0, (void *)TouchBublet__FP6BUBLETi, 0, (void *)FBounceRip__FP3RIPP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D7558
void *D_002D7558[20] = {0, 0, 0, (void *)InitDroplet__FP7DROPLETP6VECTORfP2SO, 0, (void *)PostDropletEmit, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectRipTransform__FP3RIPf, 0, (void *)UpdateRip__FP3RIPf, 0, (void *)RenderRip, 0, (void *)TouchDroplet__FP7DROPLETi, 0, (void *)FBounceRip__FP3RIPP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D75A8
void *D_002D75A8[20] = {0, 0, 0, (void *)InitSmack__FP5SMACKP6VECTORfP2SO, 0, (void *)func_001CE9B8, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectSmackTransform__FP5SMACKf, 0, (void *)UpdateSmack, 0, (void *)RenderSmack, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceRip__FP3RIPP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D75F8
void *D_002D75F8[20] = {0, 0, 0, (void *)InitGlint__FP5GLINTP6VECTORfP2SO, 0, (void *)func_001CE9B8, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectGlintTransform, 0, (void *)UpdateRip__FP3RIPf, 0, (void *)RenderGlint__FP5GLINTP2CM, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceRip__FP3RIPP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D7648
void *D_002D7648[20] = {0, 0, 0, (void *)InitMatch__FP5MATCHP6VECTORfP2SO, 0, (void *)func_001CE9B8, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectMatchTransform__FP5MATCHf, 0, (void *)UpdateMatch__FP5MATCHf, 0, (void *)RenderMatch__FP5MATCHP2CM, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceRip__FP3RIPP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D7698
void *D_002D7698[20] = {0, 0, 0, (void *)InitRip__FP3RIPP6VECTORfP2SO, 0, (void *)PostShrapnelEmit__FP8SHRAPNELP5EMITB, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectRipTransform__FP3RIPf, 0, (void *)UpdateRip__FP3RIPf, 0, (void *)RenderOrbit__FP5ORBITP2CM, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceShrapnel, 0, 0};

// data-ok: retail's bytes at 0X2D76E8
void *D_002D76E8[20] = {0, 0, 0, (void *)InitRip__FP3RIPP6VECTORfP2SO, 0, (void *)func_001CE9B8, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectRipTransform__FP3RIPf, 0, (void *)UpdateStuck__FP5STUCKf, 0, (void *)RenderStuck__FP5STUCKP2CM, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceRip__FP3RIPP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D7738
void *D_002D7738[20] = {0, 0, 0, (void *)InitRip__FP3RIPP6VECTORfP2SO, 0, (void *)PostFlyingEmit, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectRipTransform__FP3RIPf, 0, (void *)UpdateRip__FP3RIPf, 0, (void *)RenderFlying__FP6FLYINGP2CM, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceFlying__FP6FLYINGP2SOP6VECTORT2, 0, 0};

// data-ok: retail's bytes at 0X2D7788
void *D_002D7788[20] = {0, 0, 0, (void *)InitRip__FP3RIPP6VECTORfP2SO, 0, (void *)func_001CE9B8, 0, (void *)OnRipRemoveNop, 0, (void *)ProjectRipTransform__FP3RIPf, 0, (void *)UpdateRip__FP3RIPf, 0, (void *)RenderRip, 0, (void *)TouchRip__FP3RIPi, 0, (void *)FBounceRip__FP3RIPP2SOP6VECTORT2, 0, 0};
