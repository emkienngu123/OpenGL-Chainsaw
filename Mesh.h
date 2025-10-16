#if !defined (_MESH_CLASS)
#define _MESH_CLASS

#include "supportClass.h"


class VertexID
{
public:
	int		vertIndex;
	int		colorIndex;
};

class Face
{
public:
	int		nVerts;
	VertexID* vert;

	Face()
	{
		nVerts = 0;
		vert = NULL;
	}
	~Face()
	{
		if (vert != NULL)
		{
			delete[] vert;
			vert = NULL;
		}
		nVerts = 0;
	}
};

class Mesh
{
public:
	int		numVerts;
	Point3* pt;

	int		numFaces;
	Face* face;
public:
	Mesh()
	{
		numVerts = 0;
		pt = NULL;
		numFaces = 0;
		face = NULL;
	}
	~Mesh()
	{
		if (pt != NULL)
		{
			delete[] pt;
		}
		if (face != NULL)
		{
			delete[] face;
		}
		numVerts = 0;
		numFaces = 0;
	}
	void DrawWireframe();
	void DrawColor();

	void CreateTetrahedron();
	void CreateCube(float	fSize);
	void CreateCuboid(float fSizeX, float fSizeY, float fSizeZ);
	void CreateCylinderWithHole(int nSegment, float fHeight, float fORadius, float fIRadius);
	void CreateCylinder(int nSegment, float fHeight, float fRadius);
	void Shape1(int nSegment, float fHeight, float fRadius1 , float fRadius2);
	void Shape2(int nSegment, float fIRadius1, float fIRadius2, float fORadius1, float fORadius2, float fHeight1, float fHeight2);
	void Shape3(float fHeight, float fSize, float fAngle);
	void Shape4(float fHeight1, float fHeight2, float fSize1, float fSize2);
	void Shape5(float fHeightHigh, float fHeightLow, float fSizeBig , float fSizeSmall);
	void CreateCone(float fR, float fHeight, int nSlices);
	void SetColor(int colorIdx);
};

#endif