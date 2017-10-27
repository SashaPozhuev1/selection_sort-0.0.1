#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

void create(double * & mass, unsigned int &size, unsigned int &schet ) {
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	stream >> size;

	mass = new double [size];
	for (int i = 0; i < size; i++) {
		if (stream >> mass[i]) {
			schet++;
		}
	}
	
}

void obmen(double * & mass, unsigned int size) {
	for (int i = 0; i < size - 1; i++) {

		int j = i;
		for (int k = i + 1; k < size; k++) {
			if (mass[k] < mass[i]) {
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
