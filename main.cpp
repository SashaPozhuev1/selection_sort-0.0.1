#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

void create(double * & mass, unsigned int &size, unsigned int &schet) {
	string stroka1, stroka2;
	getline(cin, stroka1);
	istringstream stream1(stroka1);

	stream1 >> size;

	getline(cin, stroka2);
	istringstream stream2(stroka2);

	mass = new double[size];
	for (int i = 0; i < size; i++) {
		if (stream2 >> mass[i]) {
			schet++;
		}
	}

}

void obmen(double * & mass, unsigned int size) {
	for (int i = 0; i < size; i++) {

		int j = i;
		for (int k = i + 1; k < size; k++) {
			if (mass[k] < mass[j]) {
				j = k;
			}
		}

		if (mass[i] > mass[j]) {
			swap(mass[i], mass[j]);
		}
	}
}

void write(double * mass, unsigned int size, unsigned int schet) {
	if (schet < size) {
		cout << "error";
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << mass[i] << " ";
		}
	}
}



double *mass;
unsigned int schet = 0;

int main()
{
	
	unsigned int size;

	bool prav;

	create(mass, size, schet);
	obmen(mass, size);

	write(mass, size, schet);

	cin.get();
    return 0;
}
