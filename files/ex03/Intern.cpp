/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:45:03 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/26 16:48:39 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &rhs)
	{}
	return (*this);
}

AForm *Intern::createPPForm(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::createRRForm(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::createSCForm(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    FormCreator forms[] = {&Intern::createPPForm, &Intern::createRRForm, &Intern::createSCForm};

    for (int i = 0; i < 3; i++)
    {
        AForm* form = (this->*forms[i])(target);
        if (formName == form->getName())
        {
			std::cout << "Intern creates " << formName << std::endl;
            return (form);
        }
    }

    std::cout << "Intern cannot find the form requested" << std::endl;
    return (NULL);
}
