#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PmergeMe::sort()
{
	std::vector<unsigned int> small, big;
	std::vector<std::vector<unsigned int>>	vecOfVecs;
	for (std::vector<unsigned int>::iterator k = data.begin(); k != data.end(); ++k)
	{
		std::vector<unsigned int>::iterator i = k;
		++i;
		std::vector<unsigned int>	pairedVec;
		pairedVec.push_back(*k);
		if (i != data.end())
			pairedVec.push_back(*i);
		vecOfVecs.push_back(pairedVec);
		k++;
		if (k == data.end())
			break;
	}
	for (std::vector<std::vector<unsigned int>>::iterator i = vecOfVecs.begin(); i != vecOfVecs.end(); i++)
	{
		if (i->begin() != --i->end() && *i->begin() > *--i->end())
		{
			int	temp = *i->begin();
			*i->begin() = *--i->end();
			*--i->end() = temp;
		}
		small.push_back(*i->begin());
		big.push_back(*--i->end());
	}
	std::sort(small.begin(), small.end());
	for (std::vector<unsigned int>::iterator i = big.begin(); i != big.end(); i++)
	{
		std::vector<unsigned int>::iterator lowerBound = std::lower_bound(small.begin(), small.end(), *i);
		small.insert(lowerBound, *i);
	}
	data = small;
}

void	PmergeMe::insert(unsigned int value)
{
	data.push_back(value);
}
void	PmergeMe::print()
{
	for (std::vector<unsigned int>::iterator i = data.begin(); i != data.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */