/*
Insertion Sort — This algorithm also maintains sorted and unsorted regions of
the array. In each iteration, the next unsorted element moves up to its appropriate
position in the sorted region:
Insertion sort is particularly significant as the algorithm which minimizes the
amount of data movement. An inversion in a permutation p is a pair of elements
which are out of order, i.e., an i, j such that i < j yet p[i] > p[j]. Each swap
in insertion sort erases exactly one inversion, and no element is otherwise moved,
so the number of swaps equals the number of inversions. Since an almost-sorted
permutation has few inversions, insertion sort can be very effective on such data.
*/
insertion_sort(int s[], int n)
{
int i,j; /* counters */
for (i=1; i<n; i++) {
j=i;
while ((j>0) && (s[j] < s[j-1])) {
swap(&s[j],&s[j-1]);
j = j-1;
}
}
}