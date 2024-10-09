/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:53:49 by damendez          #+#    #+#             */
/*   Updated: 2024/10/09 16:16:00 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"  // Include the Bureaucrat class for reference

class Bureaucrat;

class Form {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    // Orthodox Canonical Form constructors and operator
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    
    // Getters
    const std::string&  getName() const;
    bool                isSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;

    // Method to sign the form
    void                beSigned(const Bureaucrat& bureaucrat);
    
    // Custom exceptions for invalid grades
    class GradeTooHighException : public std::exception {
        const char* what() const throw() {
            return "Form grade is too high!";
        }
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw() {
            return "Form grade is too low!";
        }
    };
    
    // Output stream operator overload
    friend std::ostream& operator<<(std::ostream& os, const Form& form);
};

#endif
