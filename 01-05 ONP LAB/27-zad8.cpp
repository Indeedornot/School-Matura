#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

//+/- 35min bez testow
using namespace std;

struct Brace {
    char opening, closing;
};

struct Braces {
    Brace outer, middle, inside;
};

const Braces braces = {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'}
};


bool isBrace(Brace a, Brace b) {
    return a.closing == b.closing && a.opening == b.opening;
}

bool containsBrace(string s, Brace a) {
    return s.find(a.closing) != string::npos && s.find(a.opening) != string::npos;
}

bool containsCorrect(string s, Brace brace) {
    if (isBrace(brace, braces.inside)) {
        if (containsBrace(s, braces.outer) ||
            containsBrace(s, braces.middle) ||
            containsBrace(s, braces.inside)) {
            return false;
        }
    }
    else if (isBrace(brace, braces.middle)) {
        if (containsBrace(s, braces.outer) || containsBrace(s, braces.middle)) {
            return false;
        }
    }
    else if (isBrace(brace, braces.outer)) {
        if(containsBrace(s, braces.outer)) {
            return false;
        }
    }
}

Brace braceFromStart(char start){
    if (braces.inside.opening == start) return braces.inside;
    else if (braces.middle.opening == start) return braces.middle;
    else return braces.outer;
}
bool CheckBraces(string s) {
    if(s.empty()) return true;
    if(s.size() == 1) return false;

    char start = s[0];
    Brace brace = braceFromStart(start);

    int end = s.find(brace.closing);
    if (end == string::npos) return false;

    //wnetrze
    string toCheck = s.substr(1,end - 1);

    //sprawdzamy czy zawiera tylko poprawne
    containsCorrect(toCheck, brace);

    //sprawdzamy wnetrze
    if(!CheckBraces(toCheck)){
        return false;
    }

    //sprawdzamy reszte
    if(end + 1 < s.size() && !CheckBraces(s.substr(end + 1))){
        return false;
    }

    return true;
}

int main() {
    vector<pair<string, bool>> tests = {
            {"{[()]}", true},
            {"[{()}]", false},
            {"([{}])", false},
            {"{(})", false},
            {"[)](", false},
            {"[()()]", true},
            {"{()[]()}", true}
    };

    for(auto const& test : tests){
        cout << test.first << " should be " << test.second << " is " << CheckBraces(test.first) << endl;
    }
}