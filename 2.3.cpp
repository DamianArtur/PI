#include <stdio.h>
#include <stdlib.h>

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
	int m = 0;
	int n = 0;
	int *T1;
	int *T2;
	int *T3;
	scanf("%d", &m);
	scanf("%d", &n);
	T1 = (int*) malloc(m *sizeof (int));
	T2 = (int*) malloc(n *sizeof (int));
	T3 = (int*) malloc(m+n *sizeof (int)); 
	for(int i = 0; i < m; i++) {
		scanf("%d", &T1[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", & T2[i]);
	}
	
	mergeSort(T1, 0, m-1);
	mergeSort(T2, 0, n-1);
	
	int i = 0;
	int j = 0;
	int k = 0;
	int last = -2000000000;
	while(i < m && j < n) {
		if(T1[i] < T2[j]) {
			if(T1[i] != last) {
				T3[k] = T1[i];
				k++;
				last = T1[i];	
			}
			i++;
		} else {
			if(T2[j] != last) {
				T3[k] = T2[j];
				k++;
				last = T2[j];
			}
			j++;
		}
	}
	while(i < m) {
		if(T1[i] != last) {
			T3[k] = T1[i];
			k++;
			last = T1[i];
		}
		i++;
	}
	while(j < n) {
		if(T2[j] != last) {
			T3[k] = T2[j];
			k++;
			last = T2[j];
		}
		j++;
	}
	
	for(int i = 0; i < k; i++) {
		printf("%d\n", T3[i]);
	}
	
	free(T1);
	free(T2);
	
	return 0;
}
