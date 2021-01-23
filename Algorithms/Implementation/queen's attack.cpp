/*Author:Mandeep Punia*/
// Link:https://www.hackerrank.com/challenges/queens-attack-2/problem
/* In this problem i simply stored the coordinates of blocks as a pair in a map and in each dfs call(in queens attack function) i will check whether that coordinates
is present in my map or not . As soon as i will found the coordinates i will stop counting the empty cells on which queen can attack 
In this solution the two main functions are queensattack and dfs function (rest of the code is by default provided by hackerrank code editor)
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
int dx[8]={0,0,1,-1,1,-1,-1,1};
int dy[8]={1,-1,0,0,1,1,-1,-1};

int dfs(int i,int j,int n,int dir_x,int dir_y,map<pair<int,int>, int>&mp){
    int cnt=0;
    while(i+dir_x>0 and j+dir_y>0 and i+dir_x<=n and j+dir_y<=n ){
        if(mp.find(make_pair(i+dir_x,j+dir_y))==mp.end()){
            cnt++;
            i=i+dir_x;
            j=j+dir_y;
        }
        else{
            break;
        }
    }
    
    return cnt;
}

int queensAttack(int n, int k, int rq, int cq, vector<vector<int>> arr) {
map<pair<int,int>,int> mp;
int dir_x,dir_y,ans=0;
for(int i=0;i<k;i++){
    mp.insert(make_pair(make_pair(arr[i][0],arr[i][1]),0));
}
for(int i=0;i<8;i++){
    dir_x=dx[i];
    dir_y=dy[i];
    ans+=dfs(rq,cq,n,dir_x,dir_y,mp);
}
return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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

