#include "Stack.hpp"
#include <cstdlib>

int main(void) {
	Stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	st.print();
	cout << "TOP: " << st.top() << '\n';
	st.pop();
	cout << "TOP after pop: " << st.top() << '\n';
	st.pop();
	st.print();
	while (!st.empty()) {
		cout << st.top() << '\n';
		st.pop();
	}
	cout << st.size();
	system("leaks a.out");
}