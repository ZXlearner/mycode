#include<iostream>
#include<vector>
using namespace std;

void quick_sort(vector<int> &q, int l, int r) {
    if (l >= r) return;
    int x = q[(l + r )/2], i = l - 1, j = r + 1;
    while (i < j) {
    do i++; while(q[i] < x);
    do j--; while(q[j] > x);
    if (i < j) std::swap(q[i], q[j]);
    }   
    quick_sort(q, l , j);
    quick_sort(q, j + 1, r);
}


int main(){
    vector<int> a = {34,66,2,5,95,4,46,27};
    quick_sort(a, 0, a.size() - 1);
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] <<endl;
    }
    return 0;
}