#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iostream>
# include <string>
# include <vector>
# include <cmath>
# include <climits>

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		void	insert(unsigned int value);
		void	insert(std::string value);
		void	print();
		void	sort();

		class OutOfRangeException : public std::exception {
			public :
				const char* what() const throw(){
					return "OutOfRange";
				}
		};

	private:
		std::vector<unsigned int>	data;

};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */