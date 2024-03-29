#include "Bureaucrat.hpp"
#include <iostream>

int main ()
{
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "WILLEM GRADE 15, IS VALID" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat willem("Willem", 15);
        std::cout << willem << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "SARAH GRADE 151, IS INVALID" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    try
    {
        Bureaucrat sarah("Sarah", 151);
        std::cout << sarah << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Walter starts with grade 150 but decrements with 1 " << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;

    Bureaucrat walter("Walter", 150);
    std::cout << walter << std::endl;
    try
    {
        walter.DecrementGrade();
        std::cout << walter << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Pick Your Own Number" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    
    std::string index;
    std::cout << "Grade is: ";
	std::getline(std::cin, index);
	int i = atoi(index.c_str());

    try
    {
        Bureaucrat evaluator("The Evaluator", i);
        std::cout << evaluator << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "---------------------------------------------------" << std::endl;
    return EXIT_SUCCESS;
}