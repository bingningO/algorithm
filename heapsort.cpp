/*堆排序，小根堆*/
#include <iostream>
using namespace std;
void HeapSift(int A[], int k, int n) {
	int i = k, j = 2*i;
	while (j <= n) {
		if (j<n && A[j]>A[j+1]) { //筛选的节点 
		 ++j;
	}
	if (A[i] < A[j]) { //符号小根堆的条件，结束 
		break;
	}
	else {
		swap(A[i], A[j]);
		i = j;
		j = 2*i;	
	}
  }
}

int main() {
	int i;
	int n;
	cin >> n;
	int *f = new int[n+1];
	for (i=1; i<=n; ++i) {
		cin>>f[i];
	}
	for (i=n/2; i>=1; --i) { //建堆 
		HeapSift(f, i, n);
	}
	for (i=1; i<n; ++i) {
		cout << f[1] << " ";
		swap(f[1], f[n-i+1]);
		HeapSift(f, 1, n-i);
	}
	cout << f[1];
	cout << endl; 
	return 0;
} 
