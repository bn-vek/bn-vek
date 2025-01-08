#include <exception>
using namespace std;

class QueueEmptyException:public exception
{
	const char* s;
	public:
		QueueEmptyException(const char* ch):s(ch){}
		const char* what() const noexcept
		{
			return s;
		}	
};

template <class T>
class QueueADT
{
	public:
		virtual void enQueue(T elem) = 0;
		virtual void deQueue() throw(QueueEmptyException) = 0;
		virtual T front() const throw(QueueEmptyException) = 0;
		//Some helpers
		virtual int size() const = 0;
		virtual bool empty() const = 0;
};

template <class T>
struct node
{
	T val;
	node<T>* next;
	node(T elem):val(elem),next(nullptr){}
};

template <class T>
class Queue: public QueueADT<T>
{
	node<T>* f;
	node<T>* r;
	int sz;
	public:
		Queue():f(nullptr),r(nullptr),sz(0){}
		~Queue();
		void enQueue(T elem);
		void deQueue() throw(QueueEmptyException);
		T front() const  throw(QueueEmptyException);
		int size() const;
		bool empty() const;
};

template <class T>
void Queue<T>::enQueue(T elem)
{
	node<T>* p = new node<T>(elem);
	if(f)
	{
		r->next = p;
		r =p;
	}
	else
		f = r = p;
	
	sz++;
}

template <class T>
void Queue<T>::deQueue() throw(QueueEmptyException)
{
	if(!f)
	throw(QueueEmptyException("Queue Empty"));
	
	node<T>* p = f;
	f = f->next;
	delete p;

	if(!f)
		r =f;
	sz--;
}

template <class T>
T Queue<T>::front() const throw(QueueEmptyException)
{
	if(!f)
		throw(QueueEmptyException("Queue Empty"));

	return f->val;
}

template <class T>
int Queue<T>::size() const
{
	return sz;
}

template <class T>
bool Queue<T>::empty() const
{
	return sz ? false:true;
}

template <class T>
Queue<T>::~Queue()
{
	node<T>* p = f;
	while(p)
	{
		f = f->next;
		delete p;
		p =f;
	}
	sz = 0;
}
