/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:53:49 by damendez          #+#    #+#             */
/*   Updated: 2024/10/07 15:41:34 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        Form();
        Form( const Form& src );
        Form&   operator=(const Form& rhs);
        ~Form();

        Form( const std::string& name, int gradeToSign, int gradeToExecute );
        std::string getName() const;
        bool        getSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        // signs form if bureaucrats grade is high enough
        void        beSigned( const Bureaucrat& bureaucrat );

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() { return "Grade too high"; }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() { return "Grade too low"; }
        };
};

std::ostream&   operator<<(std::ostream& out, Form& rhs);

#endif