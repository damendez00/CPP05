/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:21 by damendez          #+#    #+#             */
/*   Updated: 2024/10/07 15:44:58 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        unsigned int        _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string type, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& old);
        Bureaucrat &operator=(const Bureaucrat& rhs);
        std::string getName(void) const;
        int         getGrade(void) const;
        void        incrementGrade(void);
        void        decrementGrade(void);
        void        signForm(Form& form);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Bureaucrat grade too high, out of range (1-150)";
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Bureaucrat grade too Low, out of range (1-150)";
                }
        };
};

std::ostream&   operator<<(std::ostream& out, Bureaucrat& rhs);
std::ostream&   operator<<(std::ostream& out, const Bureaucrat& rhs); 

#endif