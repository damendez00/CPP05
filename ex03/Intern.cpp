/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:47:22 by damendez          #+#    #+#             */
/*   Updated: 2024/10/10 15:19:11 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    return *this;   
    (void)other;// Intern objects have no attributes to copy
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    AForm *form = NULL;
    
    std::string formNames[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
    AForm*    forms[] = {
        new RobotomyRequestForm( target ),
        new PresidentialPardonForm( target ),
        new ShrubberyCreationForm( target )
    };
    
    for ( int i(0); i < 3; i++ ) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
    }
    throw FormNonExistException();
    return form;
}
