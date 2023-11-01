#include <stdio.h>
#include <stdlib.h>
int merge(int A[], int lb, int ub, int mid)
{
 int *B = (int *)malloc((ub - lb + 1) * sizeof(int)); //dynamically memory alloted
 int i, j, k;
 int l;
 i = lb;
 j = mid + 1;
 k = lb;
 while (i <= mid && j <= ub) // Compare and merge elements from the leY and right subarrays
 {
 if (A[i] <= A[j]) // Copy the smaller element from the leY subarray to B
 
 {
 B[k] = A[i];
 i++;
 }
 else
 {
 B[k] = A[j]; // Copy the smaller element from the right subarray to B
 j++;
 }
 k++;
 }
 while (i <= mid)
 {
 B[k] = A[i]; // Copy any remaining elements from the leY subarray to B
 i++;
 k++;
 }
 while (j <= ub) // Copy any remaining elements from the right subarray to B
 {
 B[k] = A[j];
 j++;
 k++;
 }
 for (l = lb; l <= ub; l++) // Correct the indexing here
 {

 A[l] = B[l];
 }
 free(B);
}
int mergeSort(int A[], int lb, int ub)
{
 int mid, l;
 if (lb < ub)
 {
 mid = (lb + ub) / 2; //dividing the array into two halves
 mergeSort(A, lb, mid); //recursively dividing the 1st half
 mergeSort(A, mid + 1, ub); //recursively dividing the 2nd half
 merge(A, lb, ub, mid); //joing the two halves aYer checking if they are sorted
 }
}

int main() {
 int n, i, choice, lb, ub;
 int *A;
 printf("Enter number of elements in the array : ");
 scanf("%d", &n);
 A = (int *)malloc(n * sizeof(int));
 for (i = 0; i < n; i++)
 {
 printf("Enter element %d : ", i + 1);
 scanf("%d", &A[i]);
 }
 lb = 0;
 ub = n - 1;
 printf("1. Merge sort\n");
 printf("Enter your choice : ");
 scanf("%d", &choice);//asking user how he wants to sort
 switch (choice)
 {
 case 1:
 printf("Sorted Array (Using Merge Sort) :\n");
 mergeSort(A, lb, ub);//calling merge sort as user choice is 1
 // Print the sorted array aYer sor]ng
 for (i = 0; i < n; i++)
 {
 printf("%d ", A[i]);
 }
 default:
 printf("Invalid choice entered");//choice other than 1&2 entered
 }
 // Free the dynamically allocated memory for A
 free(A);
 return 0;
}