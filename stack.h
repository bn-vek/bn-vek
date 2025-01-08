#include <exception>
using namespace std;

//Need to go through exception class 

class stackEmptyException: public exception {
	public:
		const char* what() const noexcept { //can I pass a value to what function?
			return "Stack Empty";
		}	
};

template <class T>
struct node {
	T val;
	node<T>* next;

	node(T elem):val(elem),next(nullptr){}
};

template <class T>
class stackADT {
	public:
		virtual void push(T val) = 0;
		virtual void pop() throw(stackEmptyException)  = 0;
		virtual T top() const throw(stackEmptyException) = 0;
		virtual int size() const = 0;
		virtual bool empty() const = 0;
};

template <class T>
class stack:public stackADT<T> {
	int sz;
	node<T>* t;
	public:
		stack():t(nullptr),sz(0){}
		~stack();
		void push(T elem);
		void pop() throw(stackEmptyException);
		T top() const throw(stackEmptyException);
		int size() const;
		bool empty() const;
};

template <class T>
void stack<T>::push(T elem) {
	node<T>* p = new node<T>(elem);
	p->next = t;
	t = p;
	sz++;
}

template <class T>
void stack<T>::pop() throw(stackEmptyException)
{
	if(!t)
	throw stackEmptyException();
	node<T>* p = t;
	t =t->next;
	delete p;
	sz--;
}

template <class T>
T stack<T>::top() const throw(stackEmptyException)
{
	if(!t)
		throw stackEmptyException();
	return t->val;
}

template <class T>
int stack<T>::size() const
{
  return sz;
}

template <class T>
bool stack<T>::empty() const
{
  return sz ? false: true;
}

template <class T>
stack<T>::~stack()
{
	sz = 0;
	node<T>* p = t;
	while(p)
	{
		t = t->next;
		delete p;
		p = t;
	}	
}
