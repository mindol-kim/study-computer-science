
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &DATA, int p, int q, int r) {
    vector<int> temp(r-p+1);
    int index = 0;
    int left = p, right = q+1;
    
    while (left <= q && right <= r) {
        if (DATA[left] < DATA[right]) {
            temp[index] = DATA[left];
            left++;
        } else {
            temp[index] = DATA[right];
            right++;
        }
        
        index++;
    }
    
    for (int i=left; i<=q; i++)
        temp[index++] = DATA[i];
    for (int i=right; i<=r; i++)
        temp[index++] = DATA[i];
    
    for (int i=0; i<index; i++)
        DATA[p+i] = temp[i];
}

void mergesort(vector<int> &DATA, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; // middle position
        mergesort(DATA, p, q);
        mergesort(DATA, q+1, r);
        merge(DATA, p, q, r);
    }
}

int main(void) {
    vector<int> V = {
      12, 8, 13, 22, 44, 15, 55, 102, 9, 1
    };
    mergesort(V, 0, V.size()-1);
    
    for (int elem : V)
        cout << elem << " ";
    
    cout << endl;
    return 0;
}
