#ifndef CPP_ITER_HPP
#define CPP_ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void print_content(T content)
{
	std::cout << "The content is : " << content << std::endl;
}

template<typename T, typename U>
void	iter(T *tab, U const size, void (*func)(T))
{
	for(U i = 0; i < size; i++)
	{
		func(tab[i]);
	}
}


#endif //CPP_ITER_HPP
