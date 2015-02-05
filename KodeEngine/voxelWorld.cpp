#include "voxelWorld.h"

VoxelWorld::World::World(GLuint chunkSize, GLuint worldSizeX, GLuint worldSizeY, GLuint worldSizeZ)
{
	this->chunkSize = chunkSize;
	this->sizeX = worldSizeX;
	this->sizeY = worldSizeY;
	this->sizeZ = worldSizeZ;

	for (GLuint x = 0; x < 64; x += 2.5)
	{
		for (GLuint y = 0; y < 64; y += 2.5)
		{
			for (GLuint z = 0; z < 64; z += 2.5)
			{
				KodeEngine::Cube cube(x, y, z);
				KodeEngine::Vertex* verts = cube.cubeVerts.data();
				KodeEngine::Mesh cubeMesh(verts, 36);
				meshes.push_back(cubeMesh);
			}
		}
	}
}

void VoxelWorld::World::draw()
{
	for (auto &object : meshes)
	{
		object.draw();
	}
}