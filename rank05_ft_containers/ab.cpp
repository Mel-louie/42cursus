class iterators
	{
		private:
			T*	_ptr;
		public:
			iterators(T* x ): _ptr(x) {}
			iterators	(const iterators &cpy) { _ptr = cpy.getPtr(); }
			~iterators() {}
			iterators&	operator=(const iterators &x)
			{
				if (this != x._ptr)
					this = x._ptr;
				return (*this);
			}
			T*	getPtr() const { return (_ptr); }
			T&	operator*() const { return (*_ptr); }
			T*	operator->() const { return (_ptr); }

			bool operator==(const iterators &it) { return (it._ptr == this->_ptr); }
			bool operator!=(const iterators &it) { return (it._ptr == this->_ptr); }
			bool operator<=(const iterators &it) { return (it._ptr >= this->_ptr); }
			bool operator>=(const iterators &it) { return (it._ptr <= this->_ptr); }
			bool operator<(const iterators &it) { return (it._ptr > this->_ptr); }
			bool operator>(const iterators &it) { return (it._ptr < this->_ptr); }
			
			iterators&	operator++() { _ptr++; return (*this); }									// prefix increment operator: --it
			iterators	operator++(int) { iterators tmp(this->_ptr); this->_ptr++; return (tmp); }	// postfix increment operator: it--
			iterators&	operator--() { _ptr--; return (*this); }									// prefix decrement operator: --it
			iterators	operator--(int) { iterators tmp(this->_ptr); this->_ptr--; return (tmp); }	// postfix decrement operator: it--
			
			iterators&	operator+=(const iterators &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this);
			}
			
			iterators&	operator-=(const iterators &y)
			{
				this->_ptr = this->_ptr + y._ptr;
				return (*this); 
			}

			/*			Non-members operators overloads			*/
			friend iterators	operator+(int nb, const iterators &x)
			{
				iterators newIt(x);
				return (newIt += nb);
			}
			
			friend iterators	operator-(int nb, const iterators &x)
			{
				iterators newIt(x);
				return (newIt -= nb);
			}
		};