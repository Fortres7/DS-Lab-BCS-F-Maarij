#include <iostream>
using  namespace std;

int binarySearch(int *arr,int right,int left,int key);
int main(){
	
	int Rollnum = 50;
	
	int arr[10] = {1,2,3,30,40,10,50,6,7,8};
	
	int left=0;
	int right=9;
	int temp =	binarySearch(arr,right,left,Rollnum);
	
	if (temp!=-1){
	cout <<"Roll number found at Index: "<<temp<<endl;
	}
	else{
		int pos;
		for (int i=0;i<10;i++){
			if (Rollnum<arr[i]){
				pos=i;
				break;
			}
		}
		
		for (int i=11;i>pos;i--){
			arr[i] = arr[i-1];
		}
		arr[pos] = Rollnum;
	
	}
	cout << "[ ";
	for (int i=0;i<11;i++){
		cout <<arr[i]<<", ";
	}
	cout << "]";
	
}
int binarySearch(int *arr,int right,int left,int key){

	while (left <= right) {
		int mid = left + (right +left) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
		right = mid - 1;
		}
	}
	return -1;

	}
