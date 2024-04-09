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

#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string const name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "Form name constructor called" << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src) : _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm(void)
{
	std::cout << "Form destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

void AForm::setSigned(bool sign)
{
	this->_signed = sign;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	else
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signs " << this->_name << std::endl;
	}
}

int AForm::checkSign(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	if (this->_signed)
		throw AForm::AlreadySignedException();
	return (1);
}

int AForm::checkExec(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	if (!this->_signed)
		throw AForm::NotSignedException();
	return (1);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form already signed");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form not signed");
}

std::ostream &operator<<(std::ostream &o, AForm *a)
{
	o << "Form name : " << a->getName() << std::endl;
	o << "Form signed : " << a->getSigned() << std::endl;
	o << "Form grade to sign : " << a->getGradeSign() << std::endl;
	o << "Form grade to exec : " << a->getGradeExec() << std::endl;

	return (o);
}



