#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstdio>

template<typename T>

class Array
{
	public:
	    Array();
        Array(unsigned int size);
        Array(const Array &obj);
        Array &operator=(const Array &obj);
        ~Array();

        size_t  size() const;
        T&	    operator[] (size_t i) const;
        void    print(std::ostream& out) const;

        class IndexOutOfBounds : public std::exception
	    {
            public:
                const char *what() const throw ();
	    };

    private:
        T       *array;
        size_t  len;
};

template<typename T>
std::ostream& operator << (std::ostream &o, const Array<T> &a);

#include "../Src/Array.tpp"

#endif