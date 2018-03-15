#include <iostream>

using namespace std;


int main()
{

	int x = 0;
	for (int i = 0; i <8; ++i) {
		cout << ((64 >> i) & 1);
	}
	cout << endl;
	cin >> x;

}