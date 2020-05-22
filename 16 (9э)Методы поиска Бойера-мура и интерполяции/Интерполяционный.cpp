#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите длину массива:";
	cin >> n;
	
	int* mass = new int[n + 1];
	
	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % 51;
		cout << mass[i] << " ";
	}
	cout << endl;	
	const int k = 51;
	int c[k] = { 0 };
	for (int i = 0; i < n; i++) {
		c[mass[i]] = c[mass[i]] + 1;
	}
	int b = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < c[i]; j++) {
			mass[b] = i;
			b = b + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	int s, index;
	cin >> s;
	index = 0 + ((s - mass[0]) * (n - 0)) / (mass[n-1] - mass[0]);
	index--;
	cout << index<<endl;
	while (mass[index] != s) {
		if (mass[index < s]) index++;
		else index--;
	}
	cout << index+1;
}
