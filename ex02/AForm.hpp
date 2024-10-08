/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:11:20 by damendez          #+#    #+#             */
/*   Updated: 2024/10/08 18:11:20 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        AForm();
        AForm( const Form& src );
        AForm&   operator=(const Form& rhs);
        virtual ~AForm();
        AForm( const std::string& name, int gradeToSign, int gradeToExecute );
        
        std::string getName() const;
        bool        getSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        // signs form if bureaucrats grade is high enough
        void            beSigned(Bureaucrat const & bureaucrat);
        virtual void    execute(Bureaucrat const & bureaucrat) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() { return "Grade too high"; }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() { return "Grade too low"; }
        };
        class AlreadySignedException : public std::exception {
            public:
                virtual const char* what() const throw() { return "Form already signed"; }
        };
        class NotSignedException : public std::exception {
        public:
            virtual const char* what() const throw() { return "Form not signed"; }
        };
};

std::ostream&   operator<<( std::ostream& out, const Form& rhs );

#endif