/*Author:Mandeep Punia*/
//Link:https://www.hackerrank.com/challenges/minimum-loss/problem
/* The idea is to sort the array and then take differnces of two consecutive elements and keep checking that the minimum element among those two
should have appeared later in the original array */
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

long long minimumLoss(vector<long> price) {
int n=price.size();
pair<long long,int> arr[n];
long long ans=INT_MAX;
for(int i=0;i<n;i++){
    arr[i].first=price[i];
    arr[i].second=i;
}
sort(arr,arr+n);
for(int i=0;i<n-1;i++){
    if(arr[i].second>arr[i+1].second){
        ans=min(ans,arr[i+1].first-arr[i].first);
    }
}
return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split_string(price_temp_temp);

    vector<long> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    int result = minimumLoss(price);

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
