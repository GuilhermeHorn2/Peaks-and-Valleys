#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void peaks_and_valleys(vector<int>& v);
void make_peak(vector<int>& v,int i);

int main()
{
	/*  || \ */


	vector<int> v = {5,8,6,2,3,4,6};

	peaks_and_valleys(v);



	for(int  i = 0;i < v.size();i++){
		printf("%d ",v[i]);
	}


	return 0;
}

void make_peak(vector<int>& v,int i){

	//I want the biggest value to be in the center

	if(i-1 < 0){
		if(v[i+1] > v[i]){
			swap(v[i],v[i+1]);
		}
		return;
	}
	if(i+1 >= v.size()){
		if(v[i-1] > v[i]){
			swap(v[i],v[i-1]);
		}
		return;
	}

	int k = 0;
	int max = 0;
	for(int j = i-1;j <= i+1;j++){//O(1),because the number of iterations is allways 3
		if(v[j] >= max){
			max = v[j];
			k = j;
		}
	}

	//Now that i now the max value,i can just swap this value to the center
	swap(v[i],v[k]);

}

void peaks_and_valleys(vector<int>& v){

	//If i and i+2 are peaks,i+1 will be a valley

	for(int i = 0;i < v.size();i+=2){
		make_peak(v,i);
	}

}

