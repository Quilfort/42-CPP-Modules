#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
    std::cout << std::endl << "EXAMPLE IN SUBJECT SHEET" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << ++a << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << a << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << a++ << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << a << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << b << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}
