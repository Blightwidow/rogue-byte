// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CBinaryInputStream;
struct AllocRequest { int size; int alignment; };
struct PathVertex;
struct PathLink { PathVertex *vertex; int field4; };
struct PathVertex { VECTOR position; int linkCount; PathLink *links; int field18; int field1C; };
struct PathEdge { PathVertex *vertices[3]; };
struct PathPoint { float x; float y; float z; short field0C; short field0E; };
struct CPathZone {
    char field00[0x18];
    int kind;
    char field1C[0xE0 - 0x1C];
    int vertexCount;
    PathVertex *vertices;
    int edgeCount;
    PathEdge *edges;
    int pointCount;
    PathPoint *points;
    char fieldF8[0x114 - 0xF8];
    int serial;
};
struct GameWorld { char field0000[0x3D70]; int serial; char field3D74[0x45C8 - 0x3D74]; CPathZone *pathZone; };
extern "C" {
void LoadXfmFromBrx(void *, CBinaryInputStream *);
void *PvAllocSwClearImpl__Fi(AllocRequest *);
void *PvAllocSwImpl__Fi(AllocRequest *);
void ReadVector__18CBinaryInputStreamP6VECTOR(CBinaryInputStream *, VECTOR *);
float F32Read__18CBinaryInputStream(CBinaryInputStream *);
int U16Read__18CBinaryInputStream(CBinaryInputStream *);
int U8Read__18CBinaryInputStream(CBinaryInputStream *);
void HookupCg__FP2CG(void *);
extern GameWorld B_003DD490;
}
extern "C" void CPathZone_LoadFromBrx(CPathZone *zone, CBinaryInputStream *stream)
{
    AllocRequest request;
    int index;
    int linkIndex;
    int edgeIndex;
    LoadXfmFromBrx(zone, stream);
    zone->vertexCount = U16Read__18CBinaryInputStream(stream);
    request.size = zone->vertexCount * sizeof(PathVertex);
    request.alignment = 0x10;
    zone->vertices = (PathVertex *)PvAllocSwClearImpl__Fi(&request);
    zone->edgeCount = U16Read__18CBinaryInputStream(stream);
    request.size = zone->edgeCount * sizeof(PathEdge);
    request.alignment = 0x10;
    zone->edges = (PathEdge *)PvAllocSwClearImpl__Fi(&request);
    for (index = 0; index < zone->vertexCount; index++) {
        PathVertex *vertex = &zone->vertices[index];
        ReadVector__18CBinaryInputStreamP6VECTOR(stream, &vertex->position);
        vertex->linkCount = U8Read__18CBinaryInputStream(stream);
        request.size = vertex->linkCount * sizeof(PathLink) + sizeof(PathLink);
        request.alignment = 0x10;
        vertex->links = (PathLink *)PvAllocSwImpl__Fi(&request);
        for (linkIndex = 0; linkIndex < vertex->linkCount; linkIndex++) {
            PathLink *link = &vertex->links[linkIndex];
            link->vertex = &zone->vertices[U16Read__18CBinaryInputStream(stream)];
        }
    }
    for (edgeIndex = 0; edgeIndex < zone->edgeCount; edgeIndex++) {
        PathVertex **slot = zone->edges[edgeIndex].vertices;
        int remaining = 2;
        do {
            remaining--;
            *slot = &zone->vertices[U16Read__18CBinaryInputStream(stream)];
            slot++;
        } while (remaining >= 0);
    }
    zone->pointCount = U16Read__18CBinaryInputStream(stream);
    request.size = zone->pointCount * sizeof(PathPoint);
    request.alignment = 0x10;
    zone->points = (PathPoint *)PvAllocSwClearImpl__Fi(&request);
    for (index = 0; index < zone->pointCount; index++) {
        PathPoint *point = &zone->points[index];
        point->x = F32Read__18CBinaryInputStream(stream);
        point->y = F32Read__18CBinaryInputStream(stream);
        point->z = F32Read__18CBinaryInputStream(stream);
        point->field0C = U16Read__18CBinaryInputStream(stream);
        point->field0E = U16Read__18CBinaryInputStream(stream);
    }
    HookupCg__FP2CG(&zone->vertexCount);
    if (zone->kind == 0x2CA)
        B_003DD490.pathZone = zone;
    B_003DD490.serial++;
    zone->serial = B_003DD490.serial;
}
