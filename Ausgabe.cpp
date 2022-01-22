#include <iostream>
#include <string>
/*
Muss geändert werden für nucleo...

*/


using namespace std;

class Ausgaben {

public:
	void strausgeben(string A) {
		cout << A;
	}
	void intausgeben(int A) {
		cout << A;
	}
	void boolausgeben(bool A) {
		cout << A;
	}
	void doubout(double A) {
		cout << A;
	}
	int intein() {
		int ein;
		cin >> ein;
		return ein;
	}
	double doubin() {
		string in;
		cin >> in;
		double ind = stod(in);
		return ind;
	}
};
