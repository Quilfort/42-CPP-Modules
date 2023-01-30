#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    public:
      	Form(const std::string &input_name, const int gradeSign, const int gradeExecute);
	    Form(const Form &old_obj);
	    Form &operator=(const Form &old_obj);
	    ~Form();

      	//Getters
      	std::string getName() const;
      	int getGradeSign() const;
      	int getGradeExecute() const;
		bool isSigned() const;

		//Public Member Functions
   		void beSigned(const Bureaucrat &bureaucrat);
		void signForm(const Bureaucrat &bureaucrat) const;

  	class GradeTooLowException : std::exception
	{
		public:
			const char *what() const throw ();
	};

	class GradeTooHighException : std::exception
	{
		public:
			const char *what() const throw ();
	};

    private:
        const std::string name;
        bool _signed;
        const int gradeSign;
        const int gradeExecute;
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif