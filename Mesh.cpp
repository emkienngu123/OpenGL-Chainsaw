#include "Mesh.h"
#include <math.h>

#define PI			3.1415926
#define	COLORNUM		14


float	ColorArr[COLORNUM][3] = { {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, { 0.0,  0.0, 1.0},
								{1.0, 1.0,  0.0}, { 1.0, 0.0, 1.0},{ 0.0, 1.0, 1.0},
								 {0.3, 0.3, 0.3}, {0.5, 0.5, 0.5}, { 0.9,  0.9, 0.9},
								{1.0, 0.5,  0.5}, { 0.5, 1.0, 0.5},{ 0.5, 0.5, 1.0},
									{0.0, 0.0, 0.0}, {1.0, 1.0, 1.0} };







void Mesh::CreateCube(float	fSize)
{
	int i;

	numVerts = 8;
	pt = new Point3[numVerts];
	pt[0].set(-fSize + 1.0, fSize, fSize);
	pt[1].set(fSize + 1.0, fSize, fSize);
	pt[2].set(fSize + 1.0, fSize, -fSize);
	pt[3].set(-fSize + 1.0, fSize, -fSize);
	pt[4].set(-fSize + 1.0, -fSize, fSize);
	pt[5].set(fSize + 1.0, -fSize, fSize);
	pt[6].set(fSize + 1.0, -fSize, -fSize);
	pt[7].set(-fSize + 1.0, -fSize, -fSize);


	numFaces = 6;
	face = new Face[numFaces];

	//Left face
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 5;
	face[0].vert[2].vertIndex = 6;
	face[0].vert[3].vertIndex = 2;
	for (i = 0; i < face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	//Right face
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 3;
	face[1].vert[2].vertIndex = 7;
	face[1].vert[3].vertIndex = 4;
	for (i = 0; i < face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;

	//top face
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 2;
	face[2].vert[3].vertIndex = 3;
	for (i = 0; i < face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;

	//bottom face
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 5;
	face[3].vert[3].vertIndex = 4;
	for (i = 0; i < face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 4;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 1;
	face[4].vert[3].vertIndex = 0;
	for (i = 0; i < face[4].nVerts; i++)
	for (i = 0; i < face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 3;
	face[5].vert[1].vertIndex = 2;
	face[5].vert[2].vertIndex = 6;
	face[5].vert[3].vertIndex = 7;
	for (i = 0; i < face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 5;

}


void Mesh::CreateTetrahedron()
{
	int i;
	numVerts = 4;
	pt = new Point3[numVerts];
	pt[0].set(0, 0, 0);
	pt[1].set(1, 0, 0);
	pt[2].set(0, 1, 0);
	pt[3].set(0, 0, 1);

	numFaces = 4;
	face = new Face[numFaces];

	face[0].nVerts = 3;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 2;
	face[0].vert[2].vertIndex = 3;
	for (i = 0; i < face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;


	face[1].nVerts = 3;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 2;
	face[1].vert[2].vertIndex = 1;
	for (i = 0; i < face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;


	face[2].nVerts = 3;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 3;
	face[2].vert[2].vertIndex = 2;
	for (i = 0; i < face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;


	face[3].nVerts = 3;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 1;
	face[3].vert[1].vertIndex = 3;
	face[3].vert[2].vertIndex = 0;
	for (i = 0; i < face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;
}


void Mesh::DrawWireframe()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;

			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}

void Mesh::CreateCylinder(int nSegment, float fHeight, float fRadius) {
	this->numVerts = nSegment * 2 + 2; 
	this->pt = new Point3[this->numVerts];
	int i;
	int idx;
	float fAngle = 2 * PI / nSegment;
	float x, y, z;
	pt[0].set(0, fHeight / 2, 0);
	for (i = 0; i < nSegment; i++) {
		x = fRadius * cos(fAngle * i);
		z = fRadius * sin(fAngle * i);
		y = fHeight / 2;
		pt[i + 1].set(x, y, z);
		y = -fHeight / 2;
		pt[i + 1 + nSegment].set(x, y, z);
	}
	pt[numVerts - 1].set(0, -fHeight / 2, 0);

	this->numFaces = nSegment * 3;
	this->face = new Face[this->numFaces];
	idx = 0;
	int colorIdx = 0;
	for (i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 3;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = 0;
		if (i < nSegment - 1)
			this->face[idx].vert[1].vertIndex = i + 2;
		else
			this->face[idx].vert[1].vertIndex = 1;
		this->face[idx].vert[2].vertIndex = i + 1;
		idx++;
	}


	for (i = 0 ; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 1;
		if (i < nSegment - 1)
			this->face[idx].vert[1].vertIndex = i + 2;
		else
			this->face[idx].vert[1].vertIndex = 1;
		this->face[idx].vert[2].vertIndex = this->face[idx].vert[1].vertIndex + nSegment;
		this->face[idx].vert[3].vertIndex = this->face[idx].vert[0].vertIndex + nSegment;
		idx++;
	}

	for (i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 3;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = numVerts - 1;
		if (i < nSegment - 1)
			this->face[idx].vert[2].vertIndex = i + 2 + nSegment;
		else
			this->face[idx].vert[2].vertIndex = 1 + nSegment;
		this->face[idx].vert[1].vertIndex = i + 1 + nSegment;
		idx++;
	}

	for (i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
			colorIdx = (colorIdx + 1) % COLORNUM;
		}
	}

}


void Mesh::CreateCylinderWithHole(int nSegment, float fHeight, float fORadius, float fIRadius) {
	int idx = 0;
	float x, y, z;
	this->numVerts = nSegment * 4;
	this->pt = new Point3[this->numVerts];
	float fAngle = 2 * PI / nSegment;
	for (int i = 0 ; i < nSegment; i++) {
		x = fORadius * cos(fAngle * i);
		z = fORadius * sin(fAngle * i);
		y = fHeight / 2;
		pt[i].set(x, y, z);
		y = -fHeight / 2;
		pt[i + 2*nSegment].set(x, y, z);
		x = fIRadius * cos(fAngle * i);
		z = fIRadius * sin(fAngle * i);
		y = fHeight / 2;
		pt[i+nSegment].set(x, y, z);
		y = -fHeight / 2;
		pt[i + 3*nSegment].set(x, y, z);
	}


	this->numFaces = nSegment * 4;
	this->face = new Face[this->numFaces];
	idx = 0;
	int colorIdx = 0;
	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		if (i < nSegment - 1) {
			this->face[idx].vert[0].vertIndex = i;
			this->face[idx].vert[1].vertIndex = i + 1;
			this->face[idx].vert[2].vertIndex = i + 1 + nSegment;
			this->face[idx].vert[3].vertIndex = i + nSegment;
		}
		else {
			this->face[idx].vert[0].vertIndex = i;
			this->face[idx].vert[1].vertIndex = 0;
			this->face[idx].vert[2].vertIndex = nSegment;
			this->face[idx].vert[3].vertIndex = i + nSegment;
		}
		idx++;
	}

	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		if (i < nSegment - 1) {
			this->face[idx].vert[0].vertIndex = i + 2*nSegment;
			this->face[idx].vert[1].vertIndex = i + 1 + 2*nSegment;
			this->face[idx].vert[2].vertIndex = i + 1 + 3*nSegment;
			this->face[idx].vert[3].vertIndex = i + 3*nSegment;
		}
		else {
			this->face[idx].vert[0].vertIndex = i + 2*nSegment;
			this->face[idx].vert[1].vertIndex = 2*nSegment;
			this->face[idx].vert[2].vertIndex = 3*nSegment;
			this->face[idx].vert[3].vertIndex = i + 3*nSegment;
		}
		idx++;
	}


	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		if (i < nSegment - 1) {
			this->face[idx].vert[0].vertIndex = i;
			this->face[idx].vert[1].vertIndex = i + 1;
			this->face[idx].vert[2].vertIndex = i + 1 + 2*nSegment;
			this->face[idx].vert[3].vertIndex = i + 2*nSegment;
		}
		else {
			this->face[idx].vert[0].vertIndex = i;
			this->face[idx].vert[1].vertIndex = 0;
			this->face[idx].vert[2].vertIndex = 2*nSegment;
			this->face[idx].vert[3].vertIndex = i + 2*nSegment;
		}
		idx++;
	}

	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		if (i < nSegment - 1) {
			this->face[idx].vert[0].vertIndex = i + nSegment;
			this->face[idx].vert[1].vertIndex = i + 1 + nSegment;
			this->face[idx].vert[2].vertIndex = i + 1 + 3*nSegment;
			this->face[idx].vert[3].vertIndex = i + 3*nSegment;
		}
		else {
			this->face[idx].vert[0].vertIndex = i + nSegment;
			this->face[idx].vert[1].vertIndex = nSegment;
			this->face[idx].vert[2].vertIndex = 3*nSegment;
			this->face[idx].vert[3].vertIndex = i + 3*nSegment;
		}
		idx++;
	}

	for (int i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
			colorIdx = (colorIdx + 1) % COLORNUM;
		}
	}
}


void Mesh::CreateCuboid(float fSizeX, float fSizeY, float fSizeZ) {
	this->numVerts = 8;
	this->pt = new Point3[this->numVerts];
	pt[0].set(-fSizeX / 2 , 0.0 , 0.0);
	pt[1].set(-fSizeX / 2 , 0.0 , fSizeZ);
	pt[2].set(-fSizeX / 2 , fSizeY, fSizeZ);
	pt[3].set(-fSizeX / 2, fSizeY , 0.0);
	pt[4].set(fSizeX / 2, 0.0, 0.0);
	pt[5].set(fSizeX / 2, 0.0, fSizeZ);
	pt[6].set(fSizeX / 2, fSizeY, fSizeZ);
	pt[7].set(fSizeX / 2, fSizeY, 0.0);


	this->numFaces = 6;
	this->face = new Face[this->numFaces];
	this->face[0].nVerts = 4;
	this->face[0].vert = new VertexID[this->face[0].nVerts];
	this->face[0].vert[0].vertIndex  = 1 ;
	this->face[0].vert[1].vertIndex = 2;
	this->face[0].vert[2].vertIndex = 6;
	this->face[0].vert[3].vertIndex = 5;
	for (int i = 0; i < this->face[0].nVerts; i++) {
		this->face[0].vert[i].colorIndex = 0;
	}

	this->face[1].nVerts = 4;
	this->face[1].vert = new VertexID[this->face[1].nVerts];
	this->face[1].vert[0].vertIndex = 4;
	this->face[1].vert[1].vertIndex = 5;
	this->face[1].vert[2].vertIndex = 6;
	this->face[1].vert[3].vertIndex = 7;
	for (int i = 0; i < this->face[1].nVerts; i++) {
		this->face[1].vert[i].colorIndex = 1;
	}


	this->face[2].nVerts = 4;
	this->face[2].vert = new VertexID[this->face[2].nVerts];
	this->face[2].vert[0].vertIndex = 2;
	this->face[2].vert[1].vertIndex = 3;
	this->face[2].vert[2].vertIndex = 7;
	this->face[2].vert[3].vertIndex = 6;
	for (int i = 0; i < this->face[2].nVerts; i++) {
		this->face[2].vert[i].colorIndex = 2;
	}



	this->face[3].nVerts = 4;
	this->face[3].vert = new VertexID[this->face[3].nVerts];
	this->face[3].vert[0].vertIndex = 0;
	this->face[3].vert[1].vertIndex = 1;
	this->face[3].vert[2].vertIndex = 2;
	this->face[3].vert[3].vertIndex = 3;
	for (int i = 0; i < this->face[3].nVerts; i++) {
		this->face[3].vert[i].colorIndex = 3;
	}




	this->face[4].nVerts = 4;
	this->face[4].vert = new VertexID[this->face[4].nVerts];
	this->face[4].vert[0].vertIndex = 0;
	this->face[4].vert[1].vertIndex = 1;
	this->face[4].vert[2].vertIndex = 5;
	this->face[4].vert[3].vertIndex = 4;
	for (int i = 0; i < this->face[4].nVerts; i++) {
		this->face[4].vert[i].colorIndex = 4;
	}



	this->face[5].nVerts = 4;
	this->face[5].vert = new VertexID[this->face[5].nVerts];
	this->face[5].vert[0].vertIndex = 0;
	this->face[5].vert[1].vertIndex = 3;
	this->face[5].vert[2].vertIndex = 7;
	this->face[5].vert[3].vertIndex = 4;
	for (int i = 0; i < this->face[5].nVerts; i++) {
		this->face[5].vert[i].colorIndex = 5;
	}
}


void Mesh::Shape1(int nSegment, float fHeight, float fRadius1, float fRadius2){
	this->numVerts = 2 * nSegment + 2;
	float baseAngle = 45.0;
	this->pt = new Point3[this->numVerts];
	this->pt[0].set(0, fHeight / 2, 0);
	float x, y, z;
	for (int i =0 ; i < nSegment; i++) {
		float angle = baseAngle + (360.0 / nSegment) * i;
		if (angle <= 135) {
			x = fRadius1 * cos(angle * PI / 180.0);
			z = fRadius1 * sin(angle * PI / 180.0);
		}
		else {
			x = fRadius2 * cos(angle * PI / 180.0);
			z = fRadius2 * sin(angle * PI / 180.0);
		}
		y = fHeight / 2;
		this->pt[i + 1].set(x, y, z);
		y = -fHeight / 2;
		this->pt[i + 1 + nSegment].set(x, y, z);
	}
	pt[numVerts - 1].set(0, -fHeight / 2, 0);

	this->numFaces = nSegment * 3;
	this->face = new Face[this->numFaces];
	int idx = 0;
	int colorIdx = 0;
	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 3;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = 0;
		if (i < nSegment - 1)
			this->face[idx].vert[1].vertIndex = i + 2;
		else
			this->face[idx].vert[1].vertIndex = 1;
		this->face[idx].vert[2].vertIndex = i + 1;
		idx++;
	}


	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 1;
		if (i < nSegment - 1)
			this->face[idx].vert[1].vertIndex = i + 2;
		else
			this->face[idx].vert[1].vertIndex = 1;
		this->face[idx].vert[2].vertIndex = this->face[idx].vert[1].vertIndex + nSegment;
		this->face[idx].vert[3].vertIndex = this->face[idx].vert[0].vertIndex + nSegment;
		idx++;
	}

	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 3;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = numVerts - 1;
		if (i < nSegment - 1)
			this->face[idx].vert[2].vertIndex = i + 2 + nSegment;
		else
			this->face[idx].vert[2].vertIndex = 1 + nSegment;
		this->face[idx].vert[1].vertIndex = i + 1 + nSegment;
		idx++;
	}

	for (int i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
			colorIdx = (colorIdx + 1) % COLORNUM;
		}
	}

}


void Mesh::CreateCone(float fR, float fHeight, int nSlices) {
	this->numVerts = nSlices + 2;
	this->pt = new Point3[this->numVerts];
	float alpha = 2 * PI / nSlices;



	for (int i = 0; i < nSlices; i++) {
		pt[i].y = 0;
		pt[i].x = fR * cos(i * alpha);
		pt[i].z = fR * sin(i * alpha);
	}


	this->pt[nSlices].set(0, fHeight, 0);
	this->pt[nSlices + 1].set(0, 0, 0);

	this->numFaces = nSlices*2;
	this->face = new Face[this->numFaces];
	int idx = 0;
	for (int i = 0; i < nSlices; i++) {
		this->face[idx].nVerts = 3;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i;
		if (i < nSlices - 1)
			this->face[idx].vert[1].vertIndex = i + 1;
		else
			this->face[idx].vert[1].vertIndex = 0;
		this->face[idx].vert[2].vertIndex = nSlices;
		idx++;

		this->face[idx].nVerts = 3;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i;
		if (i < nSlices - 1)
			this->face[idx].vert[1].vertIndex = i + 1;
		else
			this->face[idx].vert[1].vertIndex = 0;
		this->face[idx].vert[2].vertIndex = nSlices + 1;
		idx++;
	}
	int colorIdx = 0;
	for (int i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
			colorIdx = (colorIdx + 1) % COLORNUM;
		}
	}

}


void Mesh::Shape2(int nSegment, float fIRadius1, float fIRadius2, float fORadius1, float fORadius2, float fHeight1, float fHeight2) {
	int idx = 0;
	float x, y, z;
	int smallerSegment = nSegment / 5;
	this->numVerts = (2 * nSegment + 2) * 4 + (2*smallerSegment + 2)*4;
	this->pt = new Point3[this->numVerts];
	float curveAngle = 180.0;
	float fAngle = (curveAngle / 360.0) * 2 * PI / nSegment;
	for (int i = 0; i <= nSegment; i++) {
		x = fORadius1 * cos(fAngle * i);
		z = fORadius1 * sin(fAngle * i);
		y = fHeight1 / 2;
		pt[i].set(x, y, z);
		y = -fHeight1 / 2;
		pt[i + 2 * ( nSegment + 1)].set(x, y, z);
		x = fIRadius1 * cos(fAngle * i);
		z = fIRadius1 * sin(fAngle * i);
		y = fHeight1 / 2;
		pt[i + nSegment + 1].set(x, y, z);
		y = -fHeight1 / 2;
		pt[i + 3 *(nSegment+1)].set(x, y, z);

		x = fORadius2 * cos(fAngle * i);
		z = fORadius2 * sin(fAngle * i);
		y = fHeight1 / 2;
		pt[i + 4 * (nSegment+1)].set(x, y, z);
		y = -fHeight1 / 2;
		pt[i + 6 * (nSegment + 1)].set(x, y, z);
		x = fIRadius2 * cos(fAngle * i);
		z = fIRadius2 * sin(fAngle * i);
		y = fHeight1 / 2;
		pt[i + 5 * (nSegment + 1)].set(x, y, z);
		y = -fHeight1 / 2;
		pt[i + 7 * (nSegment + 1)].set(x, y, z);
	}

	for (int i = 0; i <= smallerSegment; i++) {
		x = fORadius1 * cos(fAngle * i);
		z = fORadius1 * sin(fAngle * i);
		y = fHeight2  - fHeight1 / 2;
		pt[i + 8 * (nSegment+1)].set(x, y, z);
		y = -fHeight1 / 2;
		pt[i + 8 * (nSegment+1) + 2*(smallerSegment+1)].set(x, y, z);
		x = fIRadius2 * cos(fAngle * i);
		z = fIRadius2 * sin(fAngle * i);
		y = fHeight2 - fHeight1 / 2;
		pt[i + 8*(nSegment+1) + smallerSegment + 1].set(x, y, z);
		y = -fHeight1 / 2;
		pt[i + 8 * (nSegment+1) + 3*(smallerSegment+1)].set(x, y, z);

		

		x = fORadius1 * cos(curveAngle * PI / 180 - fAngle * i);
		z = fORadius1 * sin(curveAngle * PI / 180 - fAngle * i);
		y = fHeight2 - fHeight1 / 2;
		pt[smallerSegment - i + 8 * (nSegment+1) + (smallerSegment+1) * 4].set(x, y, z);
		y = -fHeight1 / 2;
		pt[smallerSegment -  i + 8 * (nSegment+1) + 2 * (smallerSegment+1) + (1+smallerSegment) * 4].set(x, y, z);
		x = fIRadius2 * cos(curveAngle * PI / 180 -  fAngle * i);
		z = fIRadius2 * sin(curveAngle * PI / 180 - fAngle * i);
		y = fHeight2 - fHeight1 / 2;
		pt[smallerSegment  - i + 8 * (nSegment+1) + (smallerSegment+1) + (smallerSegment+1) * 4].set(x, y, z);
		y = -fHeight1 / 2;
		pt[smallerSegment  - i + 8 * (nSegment+1) + 3 * (smallerSegment+1) + (smallerSegment + 1) * 4].set(x, y, z);
	}


	this->numFaces = 2*(4*nSegment + 2) + 2*(4*smallerSegment+2);
	this->face = new Face[this->numFaces];
	idx = 0;
	int colorIdx = 0;
	for (int i = 0; i < nSegment ; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i;
		this->face[idx].vert[1].vertIndex = i + 1;
		this->face[idx].vert[2].vertIndex = i + 1 + (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + (nSegment+1);
		idx++;
	}

	for (int i = 0; i < nSegment ; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 2 * (nSegment+1);
		this->face[idx].vert[1].vertIndex = i + 1 + 2 * (nSegment+1);
		this->face[idx].vert[2].vertIndex = i + 1 + 3 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + 3 * (nSegment+1);
		idx++;
	}


	for (int i = 0; i < nSegment ; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i;
		this->face[idx].vert[1].vertIndex = i + 1;
		this->face[idx].vert[2].vertIndex = i + 1 + 2 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + 2 * (nSegment+1);
		idx++;
	}

	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + nSegment + 1;
		this->face[idx].vert[1].vertIndex = i + 1 + nSegment + 1;
		this->face[idx].vert[2].vertIndex = i + 1 + 3 * (nSegment + 1);
		this->face[idx].vert[3].vertIndex = i + 3 * (nSegment + 1);
		idx++;
	}


	// TEST
	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 4*(nSegment+1);
		this->face[idx].vert[1].vertIndex = i + 1 + 4 * (nSegment+1);
		this->face[idx].vert[2].vertIndex = i + 1 + (nSegment+1) +  4 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + (nSegment+1) + 4 * (nSegment+1);
		idx++;
	}

	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 2 * (nSegment+1) + 4 * (nSegment+1);
		this->face[idx].vert[1].vertIndex = i + 1 + 2 * (nSegment+1) + 4 * (nSegment+1);
		this->face[idx].vert[2].vertIndex = i + 1 + 3 * (nSegment+1) + 4 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + 3 * (nSegment+1) + 4 * (nSegment+1);
		idx++;
	}


	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 4 * (nSegment+1);
		this->face[idx].vert[1].vertIndex = i + 1 + 4 * (nSegment+1);
		this->face[idx].vert[2].vertIndex = i + 1 + 2 * (nSegment+1) + 4 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + 2 * (nSegment+1) + 4 * (nSegment+1);
		idx++;
	}

	for (int i = 0; i < nSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + (nSegment+1) + 4 * (nSegment+1);
		this->face[idx].vert[1].vertIndex = i + 1 + nSegment + 1 + 4 * (nSegment+1) ;
		this->face[idx].vert[2].vertIndex = i + 1 + 3 * (nSegment+1) + 4 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + 3 * (nSegment+1) + 4 * (nSegment+1);
		idx++;
	}




	this->face[idx].nVerts = 4;
	this->face[idx].vert = new VertexID[this->face[idx].nVerts];
	this->face[idx].vert[0].vertIndex = 0;
	this->face[idx].vert[1].vertIndex = nSegment + 1;
	this->face[idx].vert[2].vertIndex = 3 * (nSegment + 1);
	this->face[idx].vert[3].vertIndex = 2 * (nSegment + 1);
	idx++;

	this->face[idx].nVerts = 4;
	this->face[idx].vert = new VertexID[this->face[idx].nVerts];
	this->face[idx].vert[0].vertIndex = nSegment;
	this->face[idx].vert[1].vertIndex = 2*nSegment + 1;
	this->face[idx].vert[2].vertIndex = 4*nSegment + 3;
	this->face[idx].vert[3].vertIndex = 3*nSegment + 2;
	idx++;


	this->face[idx].nVerts = 4;
	this->face[idx].vert = new VertexID[this->face[idx].nVerts];
	this->face[idx].vert[0].vertIndex = 4*(nSegment+1);
	this->face[idx].vert[1].vertIndex = 5*(nSegment + 1);
	this->face[idx].vert[2].vertIndex = 7 * (nSegment + 1);
	this->face[idx].vert[3].vertIndex = 6 * (nSegment + 1);
	idx++;


	this->face[idx].nVerts = 4;
	this->face[idx].vert = new VertexID[this->face[idx].nVerts];
	this->face[idx].vert[0].vertIndex = 5*nSegment + 4;
	this->face[idx].vert[1].vertIndex = 6*nSegment + 5;
	this->face[idx].vert[2].vertIndex = 8*nSegment + 7;
	this->face[idx].vert[3].vertIndex = 7*nSegment + 6;
	idx++;



	


	//TEST 2
	for (int i = 0; i < smallerSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 8*(nSegment+1);
		this->face[idx].vert[1].vertIndex = i + 1 + 8 * (nSegment+1);
		this->face[idx].vert[2].vertIndex = i + 1 + (smallerSegment+1) + 8 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + (smallerSegment+1) + 8 * (nSegment+1);
		idx++;
	}

	for (int i = 0; i < smallerSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 2 * (smallerSegment+1) +8 * (nSegment + 1);
		this->face[idx].vert[1].vertIndex = i + 1 + 2 * (smallerSegment+1) + 8 * (nSegment+1);
		this->face[idx].vert[2].vertIndex = i + 1 + 3 * (smallerSegment+1) + 8 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + 3 * (smallerSegment+1) + 8 * (nSegment+1);
		idx++;
	}


	for (int i = 0; i < smallerSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i;
		this->face[idx].vert[1].vertIndex = i + 1;
		this->face[idx].vert[2].vertIndex = i + 1 + 2 * (smallerSegment+1) + 8 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + 2 * (smallerSegment+1) + 8 * (nSegment+1);
		idx++;
	}

	for (int i = 0; i < smallerSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + (smallerSegment+1) + 8 * (nSegment+1);
		this->face[idx].vert[1].vertIndex = i + 1 + (smallerSegment+1) + 8 * (nSegment+1);
		this->face[idx].vert[2].vertIndex = i + 1 + 3 * (smallerSegment+1) + 8 * (nSegment+1);
		this->face[idx].vert[3].vertIndex = i + 3 * (smallerSegment+1) + 8 * (nSegment+1);
		idx++;
	}


	//TEST3
	for (int i = 0; i < smallerSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[1].vertIndex = i + 1 + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[2].vertIndex = i + 1 + (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[3].vertIndex = i + (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		idx++;
	}

	for (int i = 0; i < smallerSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + 2 * (smallerSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[1].vertIndex = i + 1 + 2 * (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[2].vertIndex = i + 1 + 3 * (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[3].vertIndex = i + 3 * (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		idx++;
	}


	for (int i = 0; i < smallerSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + (smallerSegment+1) * 4 + 8 * (nSegment + 1);
		this->face[idx].vert[1].vertIndex = i + 1 + (smallerSegment+1) * 4 + 8 * (nSegment + 1);
		this->face[idx].vert[2].vertIndex = i + 1 + 2 * (smallerSegment+1) + 8 * (nSegment+1) + (1+smallerSegment) * 4;
		this->face[idx].vert[3].vertIndex = i + 2 * (1+smallerSegment) + 8 * (1+nSegment) + (1+smallerSegment) * 4;
		idx++;
	}

	for (int i = 0; i < smallerSegment; i++) {
		this->face[idx].nVerts = 4;
		this->face[idx].vert = new VertexID[this->face[idx].nVerts];
		this->face[idx].vert[0].vertIndex = i + (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[1].vertIndex = i + 1 + (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[2].vertIndex = i + 1 + 3 * (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		this->face[idx].vert[3].vertIndex = i + 3 * (smallerSegment+1) + 8 * (nSegment+1) + (smallerSegment+1) * 4;
		idx++;
	}


	this->face[idx].nVerts = 4;
	this->face[idx].vert = new VertexID[this->face[idx].nVerts];
	this->face[idx].vert[0].vertIndex = 0;
	this->face[idx].vert[1].vertIndex = 8*(nSegment + 1) + 2*(smallerSegment+1);
	this->face[idx].vert[2].vertIndex = 8 * (nSegment + 1) + 3 * (smallerSegment + 1);
	this->face[idx].vert[3].vertIndex = 8 * (nSegment + 1)  + (smallerSegment + 1);
	idx++;

	this->face[idx].nVerts = 4;
	this->face[idx].vert = new VertexID[this->face[idx].nVerts];
	this->face[idx].vert[0].vertIndex = smallerSegment;
	this->face[idx].vert[1].vertIndex = 8 * (nSegment + 1) + 2 * (smallerSegment + 1) + smallerSegment;
	this->face[idx].vert[2].vertIndex = 8 * (nSegment + 1) + 3 * (smallerSegment + 1) + smallerSegment;
	this->face[idx].vert[3].vertIndex = 8 * (nSegment + 1) + (smallerSegment + 1) + smallerSegment;
	idx++;


	this->face[idx].nVerts = 4;
	this->face[idx].vert = new VertexID[this->face[idx].nVerts];
	this->face[idx].vert[0].vertIndex = 4 * (smallerSegment + 1) + 8 * (nSegment + 1);
	this->face[idx].vert[1].vertIndex = 5 * (smallerSegment + 1) + 8 * (nSegment + 1);
	this->face[idx].vert[2].vertIndex = 7 * (smallerSegment + 1) + 8 * (nSegment + 1);
	this->face[idx].vert[3].vertIndex = 6 * (smallerSegment + 1) + 8 * (nSegment + 1);
	idx++;


	this->face[idx].nVerts = 4;
	this->face[idx].vert = new VertexID[this->face[idx].nVerts];
	this->face[idx].vert[0].vertIndex = 4 * (smallerSegment + 1) + 8 * (nSegment + 1) + smallerSegment;
	this->face[idx].vert[1].vertIndex = 5 * (smallerSegment + 1) + 8 * (nSegment + 1) + smallerSegment;
	this->face[idx].vert[2].vertIndex = 7 * (smallerSegment + 1) + 8 * (nSegment + 1) + smallerSegment;
	this->face[idx].vert[3].vertIndex = 6 * (smallerSegment + 1) + 8 * (nSegment + 1) + smallerSegment;
	idx++;






	for (int i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
			colorIdx = (colorIdx + 1) % COLORNUM;
		}
	}
}


void Mesh::Shape3(float fHeight, float fSize, float fAngle) {
	this->numVerts = 16;
	this->pt = new Point3[this->numVerts];
	this->pt[0].set(fSize/2, fHeight / 2, tan(fAngle * PI / 180.0) * fSize / 2);
	this->pt[1].set(tan(fAngle * PI / 180.0) * fSize / 2, fHeight / 2, fSize / 2);
	this->pt[2].set(-tan(fAngle * PI / 180.0) * fSize / 2, fHeight / 2, fSize / 2);
	this->pt[3].set(-fSize / 2, fHeight / 2, tan(fAngle * PI / 180.0) * fSize / 2);
	this->pt[4].set(-fSize / 2, fHeight / 2, -tan(fAngle * PI / 180.0) * fSize / 2);
	this->pt[5].set(-tan(fAngle * PI / 180.0) * fSize / 2, fHeight / 2, -fSize / 2);
	this->pt[6].set(tan(fAngle * PI / 180.0) * fSize / 2, fHeight / 2, -fSize / 2);
	this->pt[7].set(fSize / 2, fHeight / 2, -tan(fAngle * PI / 180.0) * fSize / 2);
	this->pt[8].set(fSize / 2, -fHeight / 2, tan(fAngle * PI / 180.0) * fSize / 2);
	this->pt[9].set(tan(fAngle * PI / 180.0) * fSize / 2, -fHeight / 2, fSize / 2);
	this->pt[10].set(-tan(fAngle * PI / 180.0) * fSize / 2, -fHeight / 2, fSize / 2);
	this->pt[11].set(-fSize / 2, -fHeight / 2, tan(fAngle * PI / 180.0) * fSize / 2);
	this->pt[12].set(-fSize / 2, -fHeight / 2, -tan(fAngle * PI / 180.0) * fSize / 2);
	this->pt[13].set(-tan(fAngle * PI / 180.0) * fSize / 2, -fHeight / 2, -fSize / 2);
	this->pt[14].set(tan(fAngle * PI / 180.0) * fSize / 2, -fHeight / 2, -fSize / 2);
	this->pt[15].set(fSize / 2, -fHeight / 2, -tan(fAngle * PI / 180.0) * fSize / 2);

	this->numFaces = 10;
	this->face = new Face[this->numFaces];

	this->face[0].nVerts = 8;
	this->face[0].vert = new VertexID[this->face[0].nVerts];
	this->face[0].vert[0].vertIndex = 0;
	this->face[0].vert[1].vertIndex = 1;
	this->face[0].vert[2].vertIndex = 2;
	this->face[0].vert[3].vertIndex = 3;
	this->face[0].vert[4].vertIndex = 4;
	this->face[0].vert[5].vertIndex = 5;
	this->face[0].vert[6].vertIndex = 6;
	this->face[0].vert[7].vertIndex = 7;

	this->face[1].nVerts = 8;
	this->face[1].vert = new VertexID[this->face[1].nVerts];
	this->face[1].vert[0].vertIndex = 8;
	this->face[1].vert[1].vertIndex = 9;
	this->face[1].vert[2].vertIndex = 10;
	this->face[1].vert[3].vertIndex = 11;
	this->face[1].vert[4].vertIndex = 12;
	this->face[1].vert[5].vertIndex = 13;
	this->face[1].vert[6].vertIndex = 14;
	this->face[1].vert[7].vertIndex = 15;


	this->face[2].nVerts = 4;
	this->face[2].vert = new VertexID[this->face[2].nVerts];
	this->face[2].vert[0].vertIndex = 0;
	this->face[2].vert[1].vertIndex = 1;
	this->face[2].vert[2].vertIndex = 9;
	this->face[2].vert[3].vertIndex = 8;

	this->face[3].nVerts = 4;
	this->face[3].vert = new VertexID[this->face[3].nVerts];
	this->face[3].vert[0].vertIndex = 1;
	this->face[3].vert[1].vertIndex = 2;
	this->face[3].vert[2].vertIndex = 10;
	this->face[3].vert[3].vertIndex = 9;

	this->face[4].nVerts = 4;
	this->face[4].vert = new VertexID[this->face[4].nVerts];
	this->face[4].vert[0].vertIndex = 2;
	this->face[4].vert[1].vertIndex = 3;
	this->face[4].vert[2].vertIndex = 11;
	this->face[4].vert[3].vertIndex = 10;

	this->face[5].nVerts = 4;
	this->face[5].vert = new VertexID[this->face[5].nVerts];
	this->face[5].vert[0].vertIndex = 3;
	this->face[5].vert[1].vertIndex = 4;
	this->face[5].vert[2].vertIndex = 12;
	this->face[5].vert[3].vertIndex = 11;

	this->face[6].nVerts = 4;
	this->face[6].vert = new VertexID[this->face[6].nVerts];
	this->face[6].vert[0].vertIndex = 4;
	this->face[6].vert[1].vertIndex = 5;
	this->face[6].vert[2].vertIndex = 13;
	this->face[6].vert[3].vertIndex = 12;

	this->face[7].nVerts = 4;
	this->face[7].vert = new VertexID[this->face[7].nVerts];
	this->face[7].vert[0].vertIndex = 5;
	this->face[7].vert[1].vertIndex = 6;
	this->face[7].vert[2].vertIndex = 14;
	this->face[7].vert[3].vertIndex = 13;

	this->face[8].nVerts = 4;
	this->face[8].vert = new VertexID[this->face[8].nVerts];
	this->face[8].vert[0].vertIndex = 6;
	this->face[8].vert[1].vertIndex = 7;
	this->face[8].vert[2].vertIndex = 15;
	this->face[8].vert[3].vertIndex = 14;

	this->face[9].nVerts = 4;
	this->face[9].vert = new VertexID[this->face[9].nVerts];
	this->face[9].vert[0].vertIndex = 7;
	this->face[9].vert[1].vertIndex = 0;
	this->face[9].vert[2].vertIndex = 8;
	this->face[9].vert[3].vertIndex = 15;

	int colorIdx = 0;
	for (int i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
			colorIdx = (colorIdx + 1) % COLORNUM;
		}
	}

}


void Mesh::Shape4(float fHeight1, float fHeight2, float fSize1, float fSize2) {
	this->numVerts = 16;
	this->pt = new Point3[this->numVerts];

	//HIGHER SMALL SQUARE
	this->pt[0].set(fSize1 / 2, fHeight1 / 2, fSize1/2);
	this->pt[1].set(-fSize1 / 2, fHeight1 / 2, fSize1 / 2);
	this->pt[2].set(-fSize1 / 2, fHeight1 / 2, -fSize1 / 2);	
	this->pt[3].set(fSize1 / 2, fHeight1 / 2, -fSize1 / 2);

	//HIGHER BIG SQUARE
	this->pt[4].set(fSize2 / 2, fHeight2 / 2, fSize2 / 2);
	this->pt[5].set(-fSize2 / 2, fHeight2 / 2, fSize2 / 2);
	this->pt[6].set(-fSize2 / 2, fHeight2 / 2, -fSize2 / 2);
	this->pt[7].set(fSize2 / 2, fHeight2 / 2, -fSize2 / 2);


	//LOWER BIG SQUARE
	this->pt[8].set(fSize2 / 2, -fHeight2 / 2, fSize2 / 2);
	this->pt[9].set(-fSize2 / 2, -fHeight2 / 2, fSize2 / 2);
	this->pt[10].set(-fSize2 / 2, -fHeight2 / 2, -fSize2 / 2);
	this->pt[11].set(fSize2 / 2, -fHeight2 / 2, -fSize2 / 2);

	//LOWER SMALL SQUARE
	this->pt[12].set(fSize1 / 2, -fHeight1 / 2, fSize1 / 2);
	this->pt[13].set(-fSize1 / 2, -fHeight1 / 2, fSize1 / 2);
	this->pt[14].set(-fSize1 / 2, -fHeight1 / 2, -fSize1 / 2);
	this->pt[15].set(fSize1 / 2, -fHeight1 / 2, -fSize1 / 2);

	this->numFaces = 12;
	this->face = new Face[this->numFaces];

	this->face[0].nVerts = 4;
	this->face[0].vert = new VertexID[this->face[0].nVerts];
	this->face[0].vert[0].vertIndex = 0;
	this->face[0].vert[1].vertIndex = 1;
	this->face[0].vert[2].vertIndex = 5;
	this->face[0].vert[3].vertIndex = 4;

	this->face[1].nVerts = 4;
	this->face[1].vert = new VertexID[this->face[1].nVerts];
	this->face[1].vert[0].vertIndex = 1;
	this->face[1].vert[1].vertIndex = 2;
	this->face[1].vert[2].vertIndex = 6;
	this->face[1].vert[3].vertIndex = 5;

	this->face[2].nVerts = 4;
	this->face[2].vert = new VertexID[this->face[2].nVerts];
	this->face[2].vert[0].vertIndex = 2;
	this->face[2].vert[1].vertIndex = 3;
	this->face[2].vert[2].vertIndex = 7;
	this->face[2].vert[3].vertIndex = 6;

	this->face[3].nVerts = 4;
	this->face[3].vert = new VertexID[this->face[3].nVerts];	
	this->face[3].vert[0].vertIndex = 3;
	this->face[3].vert[1].vertIndex = 0;
	this->face[3].vert[2].vertIndex = 4;
	this->face[3].vert[3].vertIndex = 7;

	this->face[4].nVerts = 4;
	this->face[4].vert = new VertexID[this->face[4].nVerts];
	this->face[4].vert[0].vertIndex = 4;
	this->face[4].vert[1].vertIndex = 5;
	this->face[4].vert[2].vertIndex = 9;
	this->face[4].vert[3].vertIndex = 8;

	this->face[5].nVerts = 4;
	this->face[5].vert = new VertexID[this->face[5].nVerts];
	this->face[5].vert[0].vertIndex = 5;
	this->face[5].vert[1].vertIndex = 6;
	this->face[5].vert[2].vertIndex = 10;
	this->face[5].vert[3].vertIndex = 9;

	this->face[6].nVerts = 4;
	this->face[6].vert = new VertexID[this->face[6].nVerts];
	this->face[6].vert[0].vertIndex = 6;
	this->face[6].vert[1].vertIndex = 7;
	this->face[6].vert[2].vertIndex = 11;
	this->face[6].vert[3].vertIndex = 10;

	this->face[7].nVerts = 4;
	this->face[7].vert = new VertexID[this->face[7].nVerts];
	this->face[7].vert[0].vertIndex = 7;
	this->face[7].vert[1].vertIndex = 4;
	this->face[7].vert[2].vertIndex = 8;
	this->face[7].vert[3].vertIndex = 11;


	this->face[8].nVerts = 4;
	this->face[8].vert = new VertexID[this->face[8].nVerts];
	this->face[8].vert[0].vertIndex = 8;
	this->face[8].vert[1].vertIndex = 9;
	this->face[8].vert[2].vertIndex = 13;
	this->face[8].vert[3].vertIndex = 12;

	this->face[9].nVerts = 4;
	this->face[9].vert = new VertexID[this->face[9].nVerts];
	this->face[9].vert[0].vertIndex = 9;
	this->face[9].vert[1].vertIndex = 10;
	this->face[9].vert[2].vertIndex = 14;
	this->face[9].vert[3].vertIndex = 13;

	this->face[10].nVerts = 4;
	this->face[10].vert = new VertexID[this->face[10].nVerts];
	this->face[10].vert[0].vertIndex = 10;
	this->face[10].vert[1].vertIndex = 11;
	this->face[10].vert[2].vertIndex = 15;
	this->face[10].vert[3].vertIndex = 14;


	this->face[11].nVerts = 4;
	this->face[11].vert = new VertexID[this->face[11].nVerts];
	this->face[11].vert[0].vertIndex = 11;
	this->face[11].vert[1].vertIndex = 8;
	this->face[11].vert[2].vertIndex = 12;
	this->face[11].vert[3].vertIndex = 15;

	int colorIdx = 0;
	for (int i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
			colorIdx = (colorIdx + 1) % COLORNUM;
		}
	}

}


void Mesh::Shape5(float fHeightHigh, float fHeightLow, float fSizeBig, float fSizeSmall) {
	this->numVerts = 10;
	this->pt = new Point3[this->numVerts];
	this->pt[0].set(-fSizeSmall / 2, fHeightLow / 2, fSizeBig / 2);
	this->pt[1].set(fSizeSmall / 2, fHeightLow / 2, fSizeBig / 2);
	this->pt[2].set(fSizeSmall / 2, fHeightHigh / 2, 0);
	this->pt[3].set(fSizeSmall / 2, fHeightHigh / 2, -fSizeBig / 2);
	this->pt[4].set(-fSizeSmall / 2, fHeightHigh / 2, -fSizeBig / 2);
	this->pt[5].set(-fSizeSmall / 2, fHeightHigh / 2, 0);


	this->pt[6].set(-fSizeSmall / 2, -fHeightHigh / 2, fSizeBig / 2);
	this->pt[7].set(fSizeSmall / 2, -fHeightHigh / 2, fSizeBig / 2);
	this->pt[8].set(fSizeSmall / 2, -fHeightHigh / 2, -fSizeBig / 2);
	this->pt[9].set(-fSizeSmall / 2, -fHeightHigh / 2, -fSizeBig / 2);


	this->numFaces = 7;
	this->face = new Face[this->numFaces];

	this->face[0].nVerts = 4;
	this->face[0].vert = new VertexID[this->face[0].nVerts];
	this->face[0].vert[0].vertIndex = 0;
	this->face[0].vert[1].vertIndex = 1;
	this->face[0].vert[2].vertIndex = 2;
	this->face[0].vert[3].vertIndex = 5;

	this->face[1].nVerts = 4;
	this->face[1].vert = new VertexID[this->face[1].nVerts];
	this->face[1].vert[0].vertIndex = 2;
	this->face[1].vert[1].vertIndex = 3;
	this->face[1].vert[2].vertIndex = 4;
	this->face[1].vert[3].vertIndex = 5;

	this->face[2].nVerts = 4;
	this->face[2].vert = new VertexID[this->face[2].nVerts];
	this->face[2].vert[0].vertIndex = 0;
	this->face[2].vert[1].vertIndex = 1;
	this->face[2].vert[2].vertIndex = 7;
	this->face[2].vert[3].vertIndex = 6;

	this->face[3].nVerts = 4;
	this->face[3].vert = new VertexID[this->face[3].nVerts];
	this->face[3].vert[0].vertIndex = 3;
	this->face[3].vert[1].vertIndex = 4;
	this->face[3].vert[2].vertIndex = 9;
	this->face[3].vert[3].vertIndex = 8;

	this->face[4].nVerts = 4;
	this->face[4].vert = new VertexID[this->face[4].nVerts];
	this->face[4].vert[0].vertIndex = 6;
	this->face[4].vert[1].vertIndex = 7;
	this->face[4].vert[2].vertIndex = 8;
	this->face[4].vert[3].vertIndex = 9;


	this->face[5].nVerts = 5;
	this->face[5].vert = new VertexID[this->face[5].nVerts];
	this->face[5].vert[0].vertIndex = 0;
	this->face[5].vert[1].vertIndex = 5;
	this->face[5].vert[2].vertIndex = 4;
	this->face[5].vert[3].vertIndex = 9;
	this->face[5].vert[4].vertIndex = 6;

	this->face[6].nVerts = 5;
	this->face[6].vert = new VertexID[this->face[6].nVerts];
	this->face[6].vert[0].vertIndex = 1;
	this->face[6].vert[1].vertIndex = 2;
	this->face[6].vert[2].vertIndex = 3;
	this->face[6].vert[3].vertIndex = 8;
	this->face[6].vert[4].vertIndex = 7;

	int colorIdx = 0;
	for (int i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
			colorIdx = (colorIdx + 1) % COLORNUM;
		}
	}
}


void Mesh::SetColor(int colorIdx)
{
	for (int i = 0; i < this->numFaces; i++) {
		for (int j = 0; j < this->face[i].nVerts; j++) {
			this->face[i].vert[j].colorIndex = colorIdx;
		}
	}
}



void Mesh::DrawColor()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;
			int		ic = face[f].vert[v].colorIndex;

			//ic = f % COLORNUM;

			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]);
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
}



