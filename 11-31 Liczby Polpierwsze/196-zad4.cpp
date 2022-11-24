#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
    Program wypisujący liczby półpierwsze nie większe od n, 2 <= n <= 1000. Wypisywane liczby nie muszą być
    uporządkowane. W rozwiązaniu wykorzystaj algorytm sita Eratostenesa.
    Uwaga: Liczba półpierwsza to liczba będąca iloczynem dwóch liczb pierwszych.
    Liczbami półpierwszymi są np.: 4,6,9,10,14,15.
*/

//20min +/-
using namespace std;

vector<int> sito(int start, int end){
	vector<int> numbers;
	for(int i = start; i <= end; i++){
		numbers.push_back(i);
	}
	
	int p;
	//tablica to [2,3,4,5,6,7,,,end]
	for(int i = 0; i < numbers.size()-1; i++){
		p = numbers[i];
		
		for(int j = i + 1; j < numbers.size(); j++){
			if(numbers[j]%p == 0) numbers.erase(numbers.begin() + j);
		}
	}
	return numbers;
}

int main(){
	vector<int> primes = sito(2,1000);
	
	vector<int> semiprimes;
	
	for(int i = 0; i < 10; i++){
		cout << primes[i] << endl;
	}
	
	cout << "-----" << endl;
	
	int limit = 10;
	for(int i = 0; i < limit; i++){
		for(int j = i; j < limit; j++){
			semiprimes.push_back(primes[i] * primes[j]);
			cout << primes[i] << "*" << primes[j] << "=" <<  primes[i] * primes[j] << endl;
		}
	}
}