#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>

template <class T>
class	MutantStack : public std::stack<T>
{
	public: 
		// MutantStack() {}
		// ~MutantStack() {}
		// class iterator : public std::iterator<std::input_iterator_tag, T>
		// {
		// 	private:
		// 		T*	p;
		// 	public:
		// 		iterator(T* x) : p(x){}
		// 		iterator(const iterator& mit) : p(mit.p) {}
		// 		iterator&	operator++() {++p;return *this;}
		// 		iterator	operator++(T) {iterator tmp(*this); operator++(); return tmp;}
		// 		iterator&	operator--() {--p;return *this;}
		// 		iterator	operator--(T) {iterator tmp(*this); operator--(); return tmp;}
		// 		bool	operator==(const iterator& rhs) const {return p==rhs.p;}
		// 		bool	operator!=(const iterator& rhs) const {return p!=rhs.p;}
		// 		T&	operator*() {return *p;}
		// };
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin() { return this->c.begin(); };
		iterator	end() { return this->c.end(); };
};

#endif