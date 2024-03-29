#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
		Dog();
		Dog(const Dog &old_obj);
		Dog &operator=(const Dog &old_obj);
		~Dog();

		//Public Member Functions
		void makeSound() const;

	private:
	Brain	*brain;
};

#endif