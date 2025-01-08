#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
	stack<int> st;
	st.push(3);
	st.push(9);
	st.push(1);
	cout<<"Top element " << st.top()<< "\n";
	st.pop();
	cout<<"Stack size is " <<st.size()<<"\n";
	cout<<boolalpha<<"Stack is empty " << st.empty()<<"\n";
	st.pop();
	st.pop();
	st.pop();
	return 0;
}
