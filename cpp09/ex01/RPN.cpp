#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	this->num_stack = src.num_stack;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->num_stack = rhs.num_stack;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RPN const & i )
{
	o << "Value = " << &i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
std::stack<int> RPN::num_stack;

int	RPN::calculate(std::string s)
{
	int val = 0;
	std::stringstream	strstr(s);
	std::string	token;
	while (std::getline(strstr, token, ' '))
	{
		if (!token.empty())
		{
			if (isdigit(token.at(0)))
			{
				std::stringstream	toint(token);
				toint >> val;
				num_stack.push(val);
			}
			else
			{
				int val1 = 0, val2 = 0;
				if (num_stack.size() > 1)
				{
					val1 = num_stack.top();
					num_stack.pop();
					val2 = num_stack.top();
					num_stack.pop();
				}

				switch (token.at(0))
				{
					case '+':
						num_stack.push(val1+val2);
						break;
					case '-':
						num_stack.push(val2-val1);
						break;
					case '/':
						num_stack.push(val2/val1);
						break;
					case '*':
						num_stack.push(val1*val2);
						break;
					default:
						throw InvalidSymbolException();
						break;
				}
			}
		}
		else
		{
			std::cerr << "empty" << std::endl;
			return 0;
		}
	}
	return num_stack.top();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */