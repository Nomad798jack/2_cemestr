#include <iostream>
#include "func.hpp"

int main()
{
	float x;
	std::cin >> x;
	float y;
	std::cin >> y;
	float h;
	std::cin >> h;
	float p = 0.0;
	float s = 0.0;
	mt::Parallelogramm p1(x, y, h, p, s);
	if (p1.SetHeight(h, y))
	{
		p1.Print();
	}

}

