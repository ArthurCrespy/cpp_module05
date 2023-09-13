/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:07:19 by acrespy           #+#    #+#             */
/*   Updated: 2023/09/13 10:07:20 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "Form name constructor called" << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src): _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

void Form::setSigned(bool sign)
{
	this->_signed = sign;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	else
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signs " << this->_name << std::endl;
	}
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, Form *a)
{
	o << "Form name : " << a->getName() << std::endl;
	o << "Form signed : " << a->getSigned() << std::endl;
	o << "Form grade to sign : " << a->getGradeSign() << std::endl;
	o << "Form grade to exec : " << a->getGradeExec() << std::endl;

	return (o);
}



