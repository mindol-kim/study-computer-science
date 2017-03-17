
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &DATA, int p, int r) {
    int x = DATA[r];
    int i = p - 1;
    
    for (int j=p; j<r; j++) {
        if (DATA[j] <= x) {
            int temp = DATA[++i];
            DATA[i] = DATA[j];
            DATA[j] = temp;
        }
    }
    
    int temp = DATA[++i];
    DATA[i] = DATA[r];
    DATA[r] = temp;
    
    return i;
}

void quicksort(vector<int> &DATA, int p, int r) {
    if (p < r) {
        int q = partition(DATA, p, r);
        quicksort(DATA, p, q-1);
        quicksort(DATA, q+1, r);
    }
}

int main(void) {
    vector<int> V = {
        22, 44, 12, 55, 9, 8, 15, 102, 13
    };
    
    quicksort(V, 0, V.size()-1);
    for (int elem : V)
        cout << elem << " ";
    
    cout << endl;
    return 0;
}
