/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:07:24 by acrespy           #+#    #+#             */
/*   Updated: 2023/09/13 10:07:35 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat = Bureaucrat("Bob", 1);
	std::cout << &bureaucrat << std::endl;

	ShrubberyCreationForm shrubbery = ShrubberyCreationForm("home");
	std::cout << &shrubbery << std::endl;

	RobotomyRequestForm robotomy = RobotomyRequestForm("bot");
	std::cout << &robotomy << std::endl;

	PresidentialPardonForm presidential = PresidentialPardonForm("James");
	std::cout << &presidential << std::endl;

	try
	{
		shrubbery.beSigned(bureaucrat);
		shrubbery.execute(bureaucrat);
		robotomy.beSigned(bureaucrat);
		robotomy.execute(bureaucrat);
		presidential.beSigned(bureaucrat);
		presidential.execute(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Intern someRandomIntern;
	AForm *rrf;

	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if (rrf)
	{
		std::cout << rrf << std::endl;
		delete (rrf);
	}

	return (0);
}
