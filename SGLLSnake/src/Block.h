#pragma once
#include <SGLL/Graphics/RawModel.h>

#include <glm/glm.hpp>

class Block
{
public:
	Block() = default;

	Block(int x, int y, int z);

	~Block();

	void render();

	inline int getX() const
	{
		return mX;
	}

	inline int getY() const
	{
		return mY;
	}

	inline int getZ() const
	{
		return mZ;
	}

	inline SGLL::RawModel getModel() const
	{
		return mModel;
	}

	inline bool operator==(const Block& block) const 
	{
		return glm::vec3(mX, mY, mZ) == glm::vec3(block.getX(), block.getY(), block.getZ());
	}
private:
	int mX, mY, mZ;
	SGLL::RawModel mModel;
};