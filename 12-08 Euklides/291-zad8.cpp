#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//+/- 35min - problem z tworzeniem podciagow
void print(vector<string> data){
    for(auto i : data){
        cout << i << " ";
    }

    cout << endl;
}

vector<string> split(string s){
    vector<string> result;
    int size = s.size();
    for(int i = 0; i < size; i++){
        if(s[i] != ' ') continue;

        result.push_back(s.substr(0, i));
        s = s.substr(i + 1);
        i = 0;
        size = s.size();
    }

    result.push_back(s.substr(0));
    return result;
}

vector<vector<string>> allSubsets(vector<string> words){
    vector<vector<string>> allsets;
    int size = words.size();

    vector<string> set;
    int count = 1;
    while(true){
        for (int i = 0; i < words.size(); i++) {
            if (i + count > size) break;
            set.push_back(words[i]);
            for (int j = i + 1; j < i + count; j++) {
                set.push_back(words[j]);
            }
            allsets.push_back(set);
            set = {};
        }
        count++;
        if(count > size) break;
    }

//    for(auto i : allsets){
//        print(i);
//    }

    return allsets;
}

vector<string> compareSubsets(vector<vector<string>> first, vector<vector<string>> second){
    vector<string> subset;
    vector<string> temp;

    for(auto firstSet: first){
        for(auto secondSet: second){
            if(firstSet.size() <= subset.size() || secondSet.size() <= subset.size()) continue;

            for(int i = 0; i < min(firstSet.size(), secondSet.size()); i++){
                if(firstSet[i] == secondSet[i]) temp.push_back(firstSet[i]);
            }

            if(temp.size() > subset.size()) {
                subset = temp;
            }

            temp = {};
        }
    }

    return subset;
}

int main() {
    string first = "ALA MA KOTA I DWA PSY";
    string second = "OLA MA PSA I DWA KOTY";

    vector<string> wordsFirst = split(first);
    vector<string> wordsSecond = split(second);

    print(compareSubsets(allSubsets(wordsFirst), allSubsets(wordsSecond)));
}