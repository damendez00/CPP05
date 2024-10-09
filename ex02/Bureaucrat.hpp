/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:21 by damendez          #+#    #+#             */
/*   Updated: 2024/10/09 17:27:38 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat {
private:
    const std::string   _name;
    int                 _grade;

public:
    // Orthodox Canonical Form constructors and operator
    Bureaucrat();
    Bureaucrat(const std::string& _name, int _grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string&  getName() const;
    int                 getGrade() const;

    // Methods to modify the _grade
    void                incrementGrade();
    void                decrementGrade();

    // Method to sign the form
    void                signForm(AForm& form) const;
    void                executeForm(AForm const & form);
    
    // exceptions for invalid _grades
    class GradeTooHighException : public std::exception {
        const char* what() const throw() {
            return "Grade is too high!";
        }
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw() {
            return "Grade is too low!";
        }
    };

    friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
};

#endif
