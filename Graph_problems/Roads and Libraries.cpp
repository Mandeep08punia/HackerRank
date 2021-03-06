/*Author:Mandeep Punia*/
//Link:https://www.hackerrank.com/challenges/torque-and-development/problem
/* In order to minimise the cost ,the idea is to count the number of cities(let's say count) connected to a particular city and then checking whether the option to 
build the libraries for all those cities is a good idea or build one library and count-1 roads for them is a good idea,based upon which we will calculate our
minimum total cost.
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
void dfs(int node,vector<int>adj[],int *visited,int &count){
    visited[node]=true;
    count++;
    for(auto neigh:adj[node]){
        if(visited[neigh]==false){
            dfs(neigh,adj,visited,count);
        }
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
vector<int> adj[n];
long total_cost=0;
int *visited=new int[n]{0};
for(int i=0;i<cities.size();i++){
    int u=cities[i][0];
    int v=cities[i][1];
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}
for(int i=0;i<n;i++){
    if(visited[i]==false){
        int count=0;
        dfs(i,adj,visited,count);
        total_cost+=min((count-1)*c_road+c_lib,c_lib*count);
    }
}
free(visited);
return total_cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
