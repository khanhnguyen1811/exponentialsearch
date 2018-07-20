//viet ham binary, min, exponential.
#include <iostream> 
using namespace std; 
int binarySearch(int arr[], int l, int r, int num){
	int mid ; 
	while (l <= r)
	{
		mid = l + (r - l) / 2; 
		if (arr[mid] == num)
		{
			return mid; 
		}
		else if (arr[mid] < num)
		{
			return binarySearch(arr, mid + 1, r, num);
		}
		else
		{
			return binarySearch(arr, l, mid - 1, num);
		}
	}
	return -1; 
}
int minimum(int a, int b){
	if (a < b){
		return a;
	}
	return b;
}
int ExponentialSearch(int arr[], int sopt, int num){
	int i; 
	if (arr[0] == num)
	{
		return 0; 
	}
	i = 1; 
	while (i < sopt && arr[i] < num)
	{
		i *= 2;
	}
	return binarySearch(arr, i / 2, minimum(i , sopt), num);
}
int main(){
	int arr[100], i, sopt; 
	cout << "Nhap so pt mang: "; cin >> sopt; 
	cout << "Nhap mang: " << "\n";
	for (i = 0; i < sopt; i++)
	{
		cin >> arr[i];
	}
	int x; 
	cout << "Nhap x: "; cin >> x; 
	int location = ExponentialSearch(arr, sopt, x); 
	if (location == -1)

	{
		cout << x << " khong thuoc arr" << "\n";
	}
	else
	{
		cout << x << " thuoc mang arr, co vi tri la: " << location << "\n";
	}
	return 0;
}