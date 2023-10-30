#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
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
	if ( this != &rhs )
	{
		this->data = rhs.GetData();
		this->data2 = rhs.GetData2();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	std::vector<unsigned int> data = i.GetData();
	std::deque<unsigned int> data2 = i.GetData2();
	for (std::vector<unsigned int>::const_iterator it = data.begin(); it != data.end(); it++)
	{
		o << *it << " ";
	}
	o << std::endl;
	for (std::deque<unsigned int>::const_iterator it = data2.begin(); it != data2.end(); it++)
	{
		o << *it << " ";
	}
	o << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PmergeMe::sort_vec()
{
	std::vector<unsigned int> small, big;
	std::vector< std::vector<unsigned int> >	vecOfVecs;
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
	for (std::vector< std::vector<unsigned int> >::iterator i = vecOfVecs.begin(); i != vecOfVecs.end(); i++)
	{
		if (i->begin() != --i->end() && *i->begin() > *--i->end())
		{
			int	temp = *i->begin();
			*i->begin() = *--i->end();
			*--i->end() = temp;
		}
		small.push_back(*i->begin());
		if (i->begin() != --i->end())
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

void	PmergeMe::sort_deque()
{
	std::deque<unsigned int> small, big;
	std::deque< std::deque<unsigned int> >	vecOfVecs;
	for (std::deque<unsigned int>::iterator k = data2.begin(); k != data2.end(); ++k)
	{
		std::deque<unsigned int>::iterator i = k;
		++i;
		std::deque<unsigned int>	pairedVec;
		pairedVec.push_back(*k);
		if (i != data2.end())
			pairedVec.push_back(*i);
		vecOfVecs.push_back(pairedVec);
		k++;
		if (k == data2.end())
			break;
	}
	for (std::deque< std::deque<unsigned int> >::iterator i = vecOfVecs.begin(); i != vecOfVecs.end(); i++)
	{
		if (i->begin() != --i->end() && *i->begin() > *--i->end())
		{
			int	temp = *i->begin();
			*i->begin() = *--i->end();
			*--i->end() = temp;
		}
		small.push_back(*i->begin());
		if (i->begin() != --i->end())
			big.push_back(*--i->end());
	}
	std::sort(small.begin(), small.end());
	for (std::deque<unsigned int>::iterator i = big.begin(); i != big.end(); i++)
	{
		std::deque<unsigned int>::iterator lowerBound = std::lower_bound(small.begin(), small.end(), *i);
		small.insert(lowerBound, *i);
	}
	data2 = small;
}

void	PmergeMe::insert(unsigned int value)
{
	data.push_back(value);
	data2.push_back(value);
}

void	PmergeMe::insert(std::string value)
{
	long long	v = std::atoll(value.c_str());
	unsigned int	val = std::atol(value.c_str());
	if ((v < 0) || (value.length() > 10 || v > UINT_MAX))
		throw OutOfRangeException();
	data.push_back(val);
	data2.push_back(val);
}

void	PmergeMe::print()
{
	for (std::vector<unsigned int>::iterator i = data.begin(); i != data.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	for (std::deque<unsigned int>::iterator i = data2.begin(); i != data2.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

size_t	PmergeMe::size()
{
	return data.size();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<unsigned int> PmergeMe::GetData() const
{
	return data;
}

std::deque<unsigned int> PmergeMe::GetData2() const
{
	return data2;
}

/* ************************************************************************** */