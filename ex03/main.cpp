/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:24 by damendez          #+#    #+#             */
/*   Updated: 2024/10/10 15:23:56 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern intern;

        AForm* form1 = intern.makeForm("shrubbery creation", "home");
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        AForm* form3 = intern.makeForm("presidential pardon", "Zaphod");
        AForm* form4 = intern.makeForm("unknown form", "error");

        Bureaucrat bureaucrat("Alice", 1);

        if (form1) {
            form1->beSigned(bureaucrat);
            form1->execute(bureaucrat);
            delete form1;
        }

        if (form2) {
            form2->beSigned(bureaucrat);
            form2->execute(bureaucrat);
            delete form2;
        }

        if (form3) {
            form3->beSigned(bureaucrat);
            form3->execute(bureaucrat);
            delete form3;
        }

        if (form4) {
            delete form4;
        }

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
