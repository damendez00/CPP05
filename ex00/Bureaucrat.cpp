/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:38:19 by damendez          #+#    #+#             */
/*   Updated: 2024/08/10 12:30:27 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("undefined"), _grade(150) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
    std::cout << this->_name << " has been destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& old) {
    *this = old;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs) {
        this->_grade = rhs.getGrade();
    }
    return (*this);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

void    Bureaucrat::incrementGrade(void) {
    if (getGrade() > 1)
        this->_grade--;
    else
        throw GradeTooHighException();
}

void    Bureaucrat::decrementGrade(void) {
    if (getGrade() < 150)
        this->_grade++;
    else
        throw GradeTooLowException();
}

std::ostream&   operator<<(std::ostream& out, Bureaucrat& rhs) {
    out << "Name: " << rhs.getName() << std::endl << "Grade: " << rhs.getGrade() << std::endl;
    return (out);
}