#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;


clock_t timer;

double algo1(int a[],int count){
	int maxSum = 0;
	
	timer = clock();
		
	for(int i = 0; i < count; ++i)
		for(int j = i; j < count; ++j){
			int thisSum = 0;
			
			for( int k = i; k<= j; ++k)
				thisSum += a[k];
			
			if(thisSum > maxSum)
				maxSum = thisSum;
		}
		
		timer = clock() - timer;
		timer = ((double)timer/CLOCKS_PER_SEC) * 1000000;
		
		cout << "Algorithm 1 " << maxSum << endl << endl;
		return timer;
}

double algo2(int a[], int count){
	int maxSum = 0;
	
	timer = clock();
		
	for(int i = 0; i < count; ++i){
		int thisSum = 0;
		
		for(int j = i; j < count; ++j){
				thisSum += a[j];
			
			if(thisSum > maxSum)
				maxSum = thisSum;
		}
	}
		timer = clock() - timer;
		timer = ((double)timer/CLOCKS_PER_SEC) * 1000000;
		
		cout << "Algorithm 2 " << maxSum << endl << endl;
		return timer;
}


int algo3Rec (int a[], int left, int right){
	if(left == right){
		 //base case
		if(a[left] > 0)
			return a[left];
		else
			return 0;
	}
	
		int center = (left + right) / 2;
		int maxLeftSum = algo3Rec(a,left,center);
		int maxRightSum = algo3Rec(a, center+1,right);
		
		int maxLeftBorderSum = 0;
		int leftBorderSum = 0;
		for(int i = center; i >= left; --i){
			leftBorderSum += a[i];
			if(leftBorderSum > maxLeftBorderSum)
				maxLeftBorderSum = leftBorderSum;
		}
		
		int maxRightBorderSum = 0;
		int rightBorderSum = 0;
		for( int j = center + 1; j <= right; ++j){
			rightBorderSum += a[j];
			if( rightBorderSum > maxRightBorderSum)
				maxRightBorderSum = rightBorderSum;
		}
		int partialMax = max(maxRightSum, maxLeftBorderSum + maxRightBorderSum);
		return max( maxLeftSum, partialMax);
		
}

double algo3(int a[],int count){
	timer = clock();
	
	int maxSum = algo3Rec(a, 0 , count -1);
	
	timer = clock() - timer;
	timer = ((double)timer/CLOCKS_PER_SEC) * 1000000;
	
	cout << "Algorithm 3 " << maxSum << endl << endl;
	return timer;
	
}

double algo4(int a[],int count){
	timer = clock();
	
	int maxSum = 0;
	int thisSum = 0;
	
	for( int j = 0; j< count; ++j){
		thisSum += a[j];
		if(thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0 )
			thisSum = 0;
	}
	
	timer = clock() - timer;
	timer = ((double)timer/CLOCKS_PER_SEC) * 1000000;

	cout << "Algorithm 4 " << maxSum << endl << endl;
	return timer;
}
	
int main () {
	
	
	
	int array[2500];
	int index = 0;
	int count = 0;
	cout << "Please enter sequence integers: "<< endl << endl ;
	
	while (cin >> array[index])
	{
	count++;	
	index++;
	}
	
	
    int time1 = algo1(array,count);
	int time2 = algo2(array,count);
	int time3 = algo3(array,count);
	int time4 = algo4(array,count);
	
	cout << "Final Results" <<endl;

	cout << "    Algorithm 1 O(n^3)   : " << time1 << " ms" <<endl;  
	cout << "    Algorithm 2 O(n^2)   : " << time2 << " ms" <<endl;
	cout << "    Algorithm 3 O(n lg n): " << time3 << " ms" <<endl;  
	cout << "    Algorithm 4 O(n)     : " << time4 << " ms" <<endl;  

	//for ( int c =0; count>0; count--)
	//{
	//cout << array[c] << " ";
	//c++;
	//}
	
	return 0;
}
