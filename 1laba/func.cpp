#include "func.hpp"
#include <iostream>

namespace mt
{
	Parallelogramm::Parallelogramm(float x_gran, float y_gran, float height, float perim, float square) {
		Setup(x_gran, y_gran, height, perim, square);
	}
	Parallelogramm::~Parallelogramm() {
	}

	void Parallelogramm::Setup(float x_gran, float y_gran, float height, float perim, float square)
	{
		m_p.x_gran = x_gran;
		m_p.y_gran = y_gran;
		m_p.height = height;
		m_square = m_p.x_gran * m_p.height;
		m_perim = 2 * m_p.x_gran + 2 * m_p.y_gran;
	}

	void Parallelogramm::Print()
	{
		std::cout << m_p.x_gran << " " << m_p.y_gran << " " << m_p.height << " " << m_square << " " << m_perim << std::endl;
	}
	

	float Parallelogramm::SetHeight(float height, float y_gran)
	{
		if (height >= y_gran)
		{
			std::cout << "Error height does not exist" << std::endl;
			return 0;
		}
		else
		{
			return m_p.height;
		}
	}
	float Parallelogramm::GetR()
	{
		return m_p.height;
	}
}
