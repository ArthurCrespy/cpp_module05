/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:07:21 by acrespy           #+#    #+#             */
/*   Updated: 2023/09/13 10:07:22 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		AForm(void);
		AForm(std::string const name, int gradeSign, int gradeExec);
		AForm(AForm const &src);
		~AForm(void);

		AForm &operator=(AForm const &rhs);

		std::string getName(void) const;
		bool        getSigned(void) const;
		int         getGradeSign(void) const;
		int         getGradeExec(void) const;

		void setSigned(bool sign);

		void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm *a);

#endif
