#include <cmath>
int* massbin(double max_value, int max_digit, int digit, double value) {
	// 20 - ����� �������� �������� � ARINC_BNR
	int* arr = new int[max_digit]();
	int last_i = 0;
	float sum = 0;
	for (int i = 0; i <= digit - 1; i++)
	{
		sum = sum + (max_value / pow(2, i));
		if (sum <= value) {
			arr[i] = 1;
		}
		else {
			arr[i] = 0;
			sum = sum - (max_value / pow(2, i));
		}
		last_i = i;
	}
	if (last_i < max_digit - 1)
		for (int i = last_i; i < max_digit; ++i)
			arr[i] = 0;
	return arr;
}

double bindec(double max_value, int max_digit, int digit, double value) {
	int* arr = massbin(max_value, max_digit, digit, value);
	double sum = 0;
	for (int i = 0; i < max_digit; ++i) {
		sum = sum + (arr[i] * pow(2, max_digit - (1 + i)));
	}
	return sum;
}

double* decbin(int dec, int max_digit) {
	double* bin = new double[max_digit]();
	for (int i = 0; dec > 0; i++)
	{
		bin[max_digit - (i + 1)] = (dec % 2);
		dec /= 2;
	}
	return bin;
}

double massdec(double max_value, int max_digit, int digit, int dec) {
	// 20 - ����� �������� �������� � ARINC_BNR
	double* arr = decbin(dec, max_digit);
	double sum = 0;
	for (int i = 0; i <= digit - 1; i++) {
		sum = sum + arr[i] * (max_value / pow(2, i));
	}
	return sum;



}
