#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <class T>
class	MutantStack : public std::stack<T>
{
	public: 
		MutantStack() {}
		~MutantStack() {}
		MutantStack(MutantStack const &t) { *this = t; }

		MutantStack &operator=(MutantStack const &t)
		{
			if (this == &t)
				return *this;
			this->c = t.c;
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin() { return this->c.begin(); }
		iterator	end() { return this->c.end(); }

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin() const { return this->c.begin(); }
		const_iterator	end() const { return this->c.end(); }

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin() { return this->c.rbegin(); }
		reverse_iterator	rend() { return this->c.rend(); }

		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator	rend() const { return this->c.rend(); }
};

#endif