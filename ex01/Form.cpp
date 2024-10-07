/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:53:53 by damendez          #+#    #+#             */
/*   Updated: 2024/10/07 15:32:41 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(const Form& src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form& rhs) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs) {
        _signed = rhs.getSigned();
    }
    return *this;
}

Form::~Form() {
    std::cout << "Destructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Parametric constructor called" << std::endl;
}

std::string Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

std::ostream&   operator<<( std::ostream& o, const Form& rhs ) {
    o << "------------- Form Info -------------" << std::endl;
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeToSign() << std::endl
      << "Grade to execute: " << rhs.getGradeToExecute();
    return o;
}