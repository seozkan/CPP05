#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& toCopy);
		Intern& operator=(const Intern& toCopy);

		AForm*	makeForm(std::string formName, std::string target);
		AForm*	makePresidentialPardonForm(std::string target);
		AForm*	makeRobotomyRequestForm(std::string target);
		AForm*	makeShruberyCreationForm(std::string target);

	private:
		std::string _forms[3];
		AForm*	(Intern::*_makeForm[3])(std::string target);
};
#endif