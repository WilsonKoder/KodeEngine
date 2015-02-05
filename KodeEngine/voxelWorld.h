
#include "cube.h"
#include "mesh.h"

namespace VoxelWorld {
	class World {
	public:
		World(GLuint chunkSize, GLuint worldSizeX, GLuint worldSizeY, GLuint worldSizeZ);
		inline std::vector<KodeEngine::Mesh> getMeshes() { return meshes; };
		void draw();
	private:
		std::vector<KodeEngine::Cube> cubes;
		std::vector<KodeEngine::Mesh> meshes;

		GLuint chunkSize;
		GLuint sizeX;
		GLuint sizeY;
		GLuint sizeZ;
	};
}