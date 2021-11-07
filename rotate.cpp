#include <vector>
#include <string>

void rotate(vector<string> &t) {
    int n = t.size();
    vector<string> res(n);
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            res[i] += t[j][i];
        }
    }
    swap(t, res);
}