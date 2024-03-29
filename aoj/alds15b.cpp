#include <bits/stdc++.h>
using namespace std;

#define SENTINEL 1000000005
#define MAX 500000

int L[MAX/2+ 2], R[MAX/2 + 2];
int cnt;

void merge(int A[], int n, int left, int mid, int right) {
    int nl = mid - left;
    int nr = right - mid;
    for (int i = 0; i < nl; i++) L[i] = A[left + i];
    for (int i = 0; i < nr; i++) R[i] = A[mid + i];
    L[nl] = SENTINEL;
    R[nr] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void merge_sort(int A[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, n, left, mid);
        merge_sort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main() {
    int A[MAX], n, i;
    cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    merge_sort(A, n, 0, n);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}