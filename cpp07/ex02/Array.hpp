#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>


template <class T>
class Array
{
	public:

		Array() : len(0), arr(NULL) {}
		Array(unsigned int n) : len(n) { arr = new T[n](); }
		Array( Array const & src )
		{
			len = src.len;
			arr = new T[len];
			for (size_t i = 0; i < len; i++)
			{
				arr[i] = src.arr[i];
			}
		}
		~Array() { delete[] arr; }

		unsigned int	size() const {return len;}

		Array &		operator=( Array const & rhs )
		{
			if ( this != &rhs )
			{
				len = rhs.len;
				this->arr = new T[len];
				for (size_t i = 0; i < len; i++)
				{
					this->arr[i] = rhs.arr[i];
				}
			}
			return *this;
		}

		T &			operator[](unsigned int index)
		{
			if (index < 0 || index >= len)
				throw OutOfBoundException();
			return arr[index];
		}

		class	OutOfBoundException : public std::exception{
			public :
				const char* what() const throw(){
					return "Out Of Bound";
				}
		};

	private:
		T	*arr;
		unsigned int 	len;
};

// std::ostream &			operator<<( std::ostream & o, Array<T> const & i );

#endif /* *********************************************************** ARRAY_H */