//Giuseppe Ferrara
#include "massaggio.h"
#include "bad_data.h"

using namespace BAD_DATA;
using namespace SPA;
int main() {
	massaggio a, b;
	cin >> a;
	b=a;
	cout << b << endl << a;
	
	a.stampafile("test.txt");
	
	return 0;
}
