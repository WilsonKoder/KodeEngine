#include "mesh.h"
#include <vector>

KodeEngine::Mesh::Mesh(Vertex* vertices, GLuint numVertices)
{
	m_drawCount = numVertices;
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);
	
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	positions.reserve(numVertices);
	texCoords.reserve(numVertices);

	for (GLuint i = 0; i < numVertices; i++)
	{
		positions.push_back(*vertices[i].getPos());
		texCoords.push_back(*vertices[i].getTexCoord());
	}
	
	//Verts
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); 
	// 0 : index, 3 : 3 verts per position, GL_FLOAT : type, GL_FALSE : normalized?, 0 : stride, 0 : pointer
	glBindVertexArray(0);

	//Texture
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	// 0 : index, 3 : 3 verts per position, GL_FLOAT : type, GL_FALSE : normalized?, 0 : stride, 0 : pointer
	glBindVertexArray(0);

}

KodeEngine::Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void KodeEngine::Mesh::draw()
{
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glBindVertexArray(0);
}