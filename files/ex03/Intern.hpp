/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:45:03 by acrespy           #+#    #+#             */
/*   Updated: 2024/03/26 16:45:12 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern &operator=(const Intern &rhs);

		AForm *createPPForm(std::string const &target);
		AForm *createRRForm(std::string const &target);
		AForm *createSCForm(std::string const &target);

		AForm *makeForm(std::string const &formName, std::string const &target);
};

typedef AForm *(Intern::*FormCreator)(std::string const &);

#endif

