#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void quick_sort(vector<int>& v,int low,int high);
int partition(vector<int>& v,int low,int high);

vector<int> peaks_and_valleys(vector<int>& v);

int main()
{
	/*  || \ */

	vector<int> v = {5,8,6,2,3,4,6};
	vector<int> p = peaks_and_valleys(v);
	for(int i = 0;i < p.size();i++){
		printf("%d ",p[i]);
	}



	return 0;
}


vector<int> peaks_and_valleys(vector<int>& v){

	quick_sort(v,0,v.size()-1);
	vector<int> final;

	int low = 0;
	int high = v.size()-1;

	while(true){

		int x = v[high];
		int y = v[low];

		if(high <= low){
			final.push_back(x);
			break;
		}
		final.push_back(x);
		final.push_back(y);
		low++;
		high--;
	}
	return final;
}

void quick_sort(vector<int>& v,int low,int high){

	int point = partition(v,low,high);

	if(point-1 > low){
		quick_sort(v,low,point-1);
	}
	if(point < high){
		quick_sort(v,point,high);
	}

}

int partition(vector<int>& v,int low,int high){

	int pivot = v[(low+high)/2];

	while(low <= high){

		while(v[low] < pivot){
			low++;
		}

		while(v[high] > pivot){
			high--;
		}
		if(low <= high){
			swap(v[low],v[high]);
			low++;
			high--;
		}
	}
	return low;
}
