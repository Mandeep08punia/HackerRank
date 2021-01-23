/*Author:Mandeep Punia*/
//Link:https://www.hackerrank.com/challenges/even-tree/problem
/*
The idea is to check the number of nodes returned by each dfs call and if returned number is a multiple of 2 then we can cut that edge (so increase our temporary answer)
and increase the answer by the temporary answer from where dfs call has initiated for that tree
*/
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int dfs(int node,vector<int> adj[],int *visited,int &temp_ans){
    visited[node]=true;
    int cnt=0;
    for(auto neigh:adj[node]){
        if(visited[neigh]==false){
            int temp=dfs(neigh,adj,visited,temp_ans);
            if(temp%2==0)
            temp_ans++;
            cnt+=temp;
        }
    }
    return cnt+1;
}
// Complete the evenForest function below.
int evenForest(int n, int t_edges, vector<int> u, vector<int> v) {
vector<int> adj[n];
int *visited=new int[n]{0};
int ans=0;
for(int i=0;i<t_edges;i++){
    adj[u[i]-1].push_back(v[i]-1);
    adj[v[i]-1].push_back(u[i]-1);
}
for(int i=0;i<n;i++){
    if(visited[i]==false){
        int temp_ans=0;
        dfs(i,adj,visited,temp_ans);
        ans+=temp_ans;
    }
}
free(visited);
return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
