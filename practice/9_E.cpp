#include <cstdio>
#include <ctime>
#include <bits/stdc++.h>

int quick_select(int a[], int l, int r, int k) {
    int p = rand() % (r - l + 1) + l;
    int x = a[p];
    {int t = a[p]; a[p] = a[r]; a[r] = t;}
    int i = l, j = r;
    while(i < j) {
        while(i < j && a[i] < x) i++;
        if(i < j) {
            a[j] = a[i];
            j--;
        }
        while(i < j && a[j] > x) j--;
        if(i < j) {
            a[i] = a[j];
            i++;
        }
    }
    a[i] = x;
    p = i;
    if(i - l + 1 == k) return a[i];
    if(i - l + 1 < k) return quick_select(a, i+1, r, k-i-1); //МоїХ
    else return quick_select(a, l, i - 1, k);
}

int main()
{
    int a[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("%d\n", quick_select(a, 0, n-1, 5));
    return 0;
}
