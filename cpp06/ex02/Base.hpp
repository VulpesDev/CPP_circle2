#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <sys/syscall.h>
# include <unistd.h>
# include <stdint.h>

class	Base
{
	public:
		virtual ~Base();
		Base * generate(void);
		void identify(Base* p);
		void identify(Base& p);

		class FatalException : public std::exception {
			public :
				const char* what() const throw(){
					return "Some core function failed -_-";
				}
		};
	private:
		int	generateRdmN(int numbers);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif