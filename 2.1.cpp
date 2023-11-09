#define N 1200
#include <stdio.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i = 0, j = 0, k = 0; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 

int main() {
	int n = 0;
	int T1[N];
	int T2[N];
	int T3[N];
	for (int i = 0; i < N; i++) {
		T1[i] = 0;
		T2[i] = 0;
		T3[i] = 0;
	}
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &T1[i]);
	}
	
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		if (T1[i] % 2 == 0) {
			T2[a] = T1[i];
			a++;
		} else {
			T3[b] = T1[i];
			b++;
		}
	}
	
	mergeSort(T2, 0, a-1);
	mergeSort(T3, 0, b-1);
	
	printf("%d %d\n", a, b);
	
	for (int i = 0; i < a; i++) {
		printf("%d\n", T2[i]);
	}
	for (int i = 0; i < b; i++) {
		printf("%d\n", T3[i]);
	}
}
