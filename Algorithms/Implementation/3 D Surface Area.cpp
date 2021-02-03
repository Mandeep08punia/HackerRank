/*Author:Mandeep Punia*/
//Link:https://www.hackerrank.com/challenges/3d-surface-area/problem
/* The idea is to first initialise our answer with 2 rectangles area (for top and bottom) and for boundary sides we can calculate by simply running 4 for loops 
and for adjacent sides we will take absolute difference of adjacent elements
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

int surfaceArea(vector<vector<int>> a) {
int ans=0;
int n=a.size();
int m=a[0].size();
ans=2*n*m;//for top and bottom
//for adjacent sides(which will contribute in our area)
for(int i=0;i<n;i++){
    for(int  j=0;j<m;j++){
        if(i+1<n){
            ans+=abs(a[i+1][j]-a[i][j]);
        }
        if(j+1<m){
            ans+=abs(a[i][j+1]-a[i][j]);
        }
    }
}
//boundary sides
for(int i=0;i<n;i++){
    ans+=a[i][0];
}
for(int j=0;j<m;j++){
    ans+=a[0][j];
}
for(int i=0;i<n;i++){
    ans+=a[i][m-1];
}
for(int j=0;j<m;j++){
    ans+=a[n-1][j];
}
return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
