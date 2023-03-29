#ifndef CPP_ARRAY_HPP
#define CPP_ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template<typename T=int>
class Array
{
public:
	Array(){
		this->content=NULL;
		this->_size = 0;
	};

	Array(unsigned int n)
	{
		this->content = new T[n];
		this->_size = n;
	};

	virtual ~Array()
	{
		delete[] this->content;
	};

	Array(const Array<T> & src)
	{
		this->content = new T[src._size];
		for(int i = 0; i < src._size; i++)
		{
			this->content[i] = src.content[i];
		}
		this->_size = src._size;
	};

	int	size(void) const {
		return this->_size;
	};

	Array<T> & operator=(const Array<T>& src)
	{
		if(this->content)
			delete[] this->content;
		this->content = new T[src._size];
		for(int i = 0; i < src._size; i++)
			this->content[i] = src.content[i];
		this->_size = src._size;
		return (*this);
	};

	class IndexException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Invalid index !");
		};
	};

	T& operator[](int const idx) const
	{
		if(idx < 0 || idx > static_cast<int>(_size) - 1)
		{
			throw IndexException();
		}
		return (this->content[idx]);
	};
private:
	T *content;
	unsigned int _size;
};

#endif //CPP_ARRAY_HPP
