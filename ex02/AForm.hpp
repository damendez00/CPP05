/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:11:20 by damendez          #+#    #+#             */
/*   Updated: 2024/10/09 16:44:37 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    // Constructor and destructor
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();                    // Virtual destructor

    // Getters
    const std::string&  getName() const;
    bool                isSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;

    // Virtual methods
    virtual void        execute(const Bureaucrat& executor) const = 0; // Pure virtual method
    void                beSigned(const Bureaucrat& bureaucrat);

    // Custom exceptions for invalid grades
    class GradeTooHighException : public std::exception {
        const char* what() const throw() {
            return "AForm grade is too high!";
        }
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw() {
            return "AForm grade is too low!";
        }
    };

    // Output stream operator overload
    friend std::ostream& operator<<(std::ostream& os, const AForm& form);
};

#endif