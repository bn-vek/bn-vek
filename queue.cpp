#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
	Queue<int> q;
	q.enQueue(7);
	q.enQueue(11);
	cout<<"Front element is " << q.front() <<"\n";
	cout<<"Size is " << q.size() <<"\n";
	q.deQueue();
	cout<<boolalpha << "Queue is Empty " << q.empty() << "\n";
	q.deQueue();
	q.deQueue();
	return 0;
}
