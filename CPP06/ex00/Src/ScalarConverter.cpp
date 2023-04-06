#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cctype>
#include <cstdlib>

ScalarConverter::ScalarConverter(std::string input) : input(input)
{
        //std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &old_obj)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = old_obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &old_obj)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    (void) old_obj;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    //std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert()
{
    this->InputType = parseType();

    if (InputType == CHAR)
        this->castChar();
    else if (InputType == INT)
        this->castInt();
    else if (InputType == DOUBLE)
        this->castDouble();
    else if (InputType == FLOAT)
        this->castFloat();

    if (InputType != ERROR)
        this->printConvert();
    else
         std::cout << "ERROR: INCORRECT INPUT || TRY AGAIN" << std::endl;
}

int ScalarConverter::parseType()
{
    char*	end;
    
    if (input.length() == 1 && (input.find_first_not_of("-0123456789") != std::string::npos))
        return (CHAR);
    std::strtol(input.c_str(), &end, 10);
    if (*end == '\0')
        return (INT);
    std::strtof(input.c_str(), &end);
    if (*end == '\0')
        return (DOUBLE);
    std::strtof(input.c_str(), &end);
    if ((*end == 'f' && end[input.length() + 1] == '\0') || \
            input.compare("-inff") == 0 || input.compare("inff") == 0 || input.compare("nanf") == 0)
        return (FLOAT);
    return (ERROR);
}

void	ScalarConverter::printConvert()
{
    printChar();
    printInt();
    printFloat();
    printDouble();
}

// CASTING
void	ScalarConverter::castChar()
{   
    this->c = static_cast<char>(this->input[0]);
	this->i = static_cast<long int>(c);
	this->flo = static_cast<float>(c);
    this->doub = static_cast<double>(c);
}

void	ScalarConverter::castInt()
{   
   
	this->i = static_cast<long int>(atol(this->input.c_str()));
    this->c = static_cast<char>(i);
	this->flo = static_cast<float>(i);
    this->doub = static_cast<double>(i);
}

void	ScalarConverter::castDouble()
{   
   
	this->doub = static_cast<float>(atof(this->input.c_str()));
    this->c = static_cast<char>(doub);
    this->i = static_cast<long int>(doub);
	this->flo = static_cast<float>(doub);
}

void	ScalarConverter::castFloat()
{   
	this->flo = static_cast<float>(atof(this->input.c_str()));
    this->i = static_cast<long int>(flo);
    this->c = static_cast<char>(flo);
    this->doub = static_cast<double>(flo);
}

//PRINTING
void	ScalarConverter::printChar()
{
    std::cout << "char: ";
    if (isprint(this->c) && (this->i <= INT_MAX && this->i >= INT_MIN))
        std::cout << this->c << std::endl;
    else if (isascii(this->c) && (this->i <= INT_MAX && this->i >= INT_MIN))
        std::cout << "Non displayable" << std::endl;
    else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::printInt()
{
    std::cout << "int: ";
    if (this->i <= INT_MAX && this->i >= INT_MIN)
    {
        this->print_i = static_cast<int>(this->i);
		std::cout<< this->i << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void	ScalarConverter::printFloat()
{
    std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << "float: ";
    std::cout << this->flo << "f" << std::endl;
}

void	ScalarConverter::printDouble()
{
    std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << "double: ";
    std::cout << this->doub << std::endl;
}

//Fixed: write floating-point values in fixed-point notation
//setpreciosion: correct to 1 decemal number