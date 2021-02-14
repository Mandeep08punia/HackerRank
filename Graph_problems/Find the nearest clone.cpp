/*Author:Mandeep Punia*/
//Link:https://www.hackerrank.com/challenges/find-the-nearest-clone/problem
/* The idea is to apply bfs on the first node of the given color of the test case  and at each level whenever we find a node of the required color we will push the level
into the vector and then if same color is occuring at the same level then it is not possible(this is
because bfs is returning us the node of those two parallel branches ) so we consider next possible level and take the difference and try to minimise it
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
vector<int> v;

 void bfs(int i,vector<int> adj[],int color,vector<long> &ids,int n){
     queue<int> q;
     q.push(i);
     int level=0;
     bool *visited=new bool[n]{0};
     visited[i]=true;
     while(!q.empty()){
         int n1=q.size();
         level++;
         while(n1--){
         int node=q.front();
         q.pop();
         for(auto neigh:adj[node]){
             if(visited[neigh]==false){
             if(ids[neigh]==color)
             v.push_back(level);
             q.push(neigh);
             visited[neigh]=true;
            }
           }
         }
     }
 }
 
int findShortest(int n, vector<int> from, vector<int> to, vector<long> ids, int val) {
    vector<int> adj[n];
    int mini=INT_MAX;
    for(int i=0;i<to.size();i++){
        adj[from[i]-1].push_back(to[i]-1);
        adj[to[i]-1].push_back(from[i]-1);
    }
    for(int i=0;i<ids.size();i++){
        if(ids[i]==val){
            v.push_back(0);
            bfs(i,adj,val,ids,n);
            break;
        }
    }
    /*for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;*/
    if(v.size()<=1){
        return -1;
    }
    else{
        for(int i=0;i<v.size()-1;i++){
            if(v[i]!=v[i+1])
            mini=min(mini,v[i+1]-v[i]);
        }
    }
    return mini;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

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
