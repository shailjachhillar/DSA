//Time Complexity O(N)
//Space Complexity O(N)


#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int stu[n];
	for(int i = 0; i < n; i++){
	    cin>>stu[i];
	}
	vector<int> left(n,1);
	vector<int> right(n,1);
	for(int i = 1; i < n; i++){
	    if(stu[i] > stu[i - 1]){
	        left[i] = left[i - 1] + 1;
	    }
	}
	for(int i = n - 2; i >= 0; i--){
	    if(stu[i] > stu[i + 1]){
	        right[i] = right[i + 1] + 1;
	    }
	}
	int candy = 0;
	for(int i = 0; i < n; i++){
	    candy += max(left[i],right[i]);
	}
	cout<<candy;
  return 0;
}
