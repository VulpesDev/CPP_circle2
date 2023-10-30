#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iostream>
# include <string>
# include <vector>
# include <deque>
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
		void	sort_vec();
		void	sort_deque();
		size_t	size();

		std::vector<unsigned int> GetData() const;
		std::deque<unsigned int> GetData2() const;

		class OutOfRangeException : public std::exception {
			public :
				const char* what() const throw(){
					return "OutOfRange";
				}
		};

	private:
		std::vector<unsigned int>	data;
		std::deque<unsigned int>	data2;

};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */