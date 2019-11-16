// Doubly-Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.cpp"
using namespace std;

int main()
{
	List<int> l1;
	l1.add(5);
	l1.add(6);
	l1.add(7);
	l1.previous();
	l1.remove();
	l1.add(8);
	l1.start();
	while (l1.next())
	{
		cout << l1.get() << endl;
	}
	while (l1.previous())
	{
		cout << l1.get() << endl;
	}
	cout << l1.length() << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
