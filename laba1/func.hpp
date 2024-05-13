#pragma once

namespace mt
{
	struct dlini
	{
		float x_gran;
		float y_gran;
		float height;
	};

	class Parallelogramm
	{
		float m_square;
		float m_perim;
		dlini m_p;

	public:
		Parallelogramm(float x_gran, float y_gran, float height, float perim, float square);
		void Setup(float x_gran, float y_gran, float height, float perim, float square);
		void Print();
		~Parallelogramm();
		float SetHeight(float height, float y_gran);
		float GetR();
	};
}