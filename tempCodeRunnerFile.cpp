#include <iostream>
#include <cmath>

int main()
{
	int i;

	float P1[3] = {-0.5		,	-0.5 * float(sqrt(3)) / 3,		0.0};
	float P2[3] = { 0.5		,	-0.5 * float(sqrt(3)) / 3,		0.0};
	float P3[3] = { 0.0		,	 0.5 * float(sqrt(3)) / 2,		0.0};
	float P4[3] = {-0.5 / 2	,	 0.5 * float(sqrt(3)) / 6,		0.0};
	float P5[3] = { 0.5 / 2	,	 0.5 * float(sqrt(3)) / 6,		0.0};
	float P6[3] = { 0.0		,	-0.5 * float(sqrt(3)) / 3,		0.0};

	for (i = 0; i < 3; i++)
	{
		std::cout << P1[i] << "	";
	}
	std::cout << "\n" << std::endl;
	for (i = 0; i < 3; i++)
	{
		std::cout << P2[i] << "	";
	}
	std::cout << "\n" << std::endl;
	for (i = 0; i < 3; i++)
	{
		std::cout << P3[i] << "	";
	}
	std::cout << "\n" << std::endl;
	for (i = 0; i < 3; i++)
	{
		std::cout << P4[i] << "	";
	}
	std::cout << "\n" << std::endl;
	for (i = 0; i < 3; i++)
	{
		std::cout << P5[i] << "	";
	}
	std::cout << "\n" << std::endl;
	for (i = 0; i < 3; i++)
	{
		std::cout << P6[i] << "	";
	}
	std::cout << "\n" << std::endl;
}