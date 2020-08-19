// C++ implementation of the approach 
#include <bits/stdc++.h> 
#define MAX 10000002 

using namespace std; 


// Driver code 
int main() 
{ 
	sieve(); 
	vector<int> arr= { 3, 5, 7 }; 
	int n = arr.size(); 
	cout << numberOfDivisorsOfProduct(arr, n); 
	return 0; 
} 
