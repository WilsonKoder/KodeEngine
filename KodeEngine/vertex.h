namespace KodeEngine {
	class Vertex {
	public:
		Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
		{
			this->position = pos;
			this->texCoord = texCoord;
		}

		inline glm::vec3* getPos() { return &position; };
		inline glm::vec2* getTexCoord() { return &texCoord; };

	private:
		glm::vec3 position;
		glm::vec2 texCoord;
	};
}