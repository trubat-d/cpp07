#include "Array.hpp"

int main(void)
{
	try
	{
		Array<std::string> A(5);
		std::cout << "Value of A[0] : " << A[0] << std::endl;
		A[0] = "test";
		std::cout << "Value of A[0] : " << A[0] << std::endl;
		std::cout << "Size of A : " << A.size() << std::endl;
		std::cout << "Value of A[100] : " << A[100] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}