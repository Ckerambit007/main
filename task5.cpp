#include <iostream>
using namespace std;

int main(){
	int decimals, units, amount = 1;
	for (int i = 10; i < 100; i++) {
		decimals = i / 10;
		units = i % 10;
		if (2 * (decimals + units) == decimals * units) {
			cout << amount << ". " << i << endl;
			amount++;
		}
	}
	return 0;
}