#include <iostream>
#include <time.h>

using namespace std;
void create(double*& mas, int n, double  A, double B)
{
	mas = new double[n];
	for (int i = 0; i < n; i++) {

		mas[i] = A + rand() * (B - A) / RAND_MAX;
	}

}
void print(double*& mas, int n)
{
	for (int i = 0; i < n; i++) {

		cout << mas[i] << ", ";
	}

}
double Suma(double*& mas, const int n) {
	double s = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0) {
			s += mas[i];
		}
	}
	return s;
}
void Found_Max(double*& mas, const int n, double& max_el, int& index_max) {
	int i = 0;
	max_el = mas[i];
	index_max = 0;
	for (i = 0; i < n; i++) {
		if (mas[i] > max_el) {
			max_el = mas[i];
			index_max = i;
		}
	}
}
void  Found_Min(double*& mas, const int n, double& min_el, int& index_min) {
	int i = 0;
	min_el = mas[i];
	for (i = 0; i < n; i++) {
		if (mas[i] < min_el) {
			min_el = mas[i];
			index_min = i;
		}
	}
}
double dob_prom(double*& mas, const int n, int& index_max, int& index_min) {
	int in1 = 0;
	int in2 = 0;
	double d = 1.;
	if (index_min < index_max) {
		in1 = index_min;
		in2 = index_max;
	}
	else {
		in2 = index_min;
		in1 = index_max;
	}
	for (int i = in1; i <= in2; i++) {

		d *= mas[i];
	}
	return d;
}
void sort(double*& mas, const int n) {
	for (int i = 0; i < n - 1; i++)
	{
		double min = mas[i];                  
		int imin = i;                  
		for (int j = i + 1; j < n; j++)
			if (min > mas[j])
			{
				min = mas[j];
				imin = j;
			}
		mas[imin] = mas[i];
		mas[i] = min;
	}

}
int main()
{
	srand((unsigned)time(NULL));
	int n = 10;
	double* a;
	int k;
	double* b;
	create(a, n, -20, 50);
	cout << "a = { ";
	print(a, n); cout << " }" << endl;
	cout << "suma = " << Suma(a, n) << endl;

	int index_max = 0;
	double max_el = 0;
	int index_min = 0;
	double min_el = 0;
	Found_Max(a, n, max_el, index_max);
	Found_Min(a, n, min_el, index_min);
	cout << "max_el " << max_el << "  index_max " << index_max << endl;
	cout << "min_el " << min_el << "  index_min " << index_min << endl;
	cout << "suma = " << dob_prom(a, n, index_max, index_min) << endl;

	cout << "k = "; cin >> k;
	create(b, k, -20, 50);
	cout << "b = { ";
	print(b, k); cout << " }" << endl;
	sort(b, k);
	cout << "sort b = { ";
	print(b, k); cout << " }" << endl;
	delete[]a;
	delete[]b;
	return 0;
}