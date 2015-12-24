#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        mp_abbr.clear();
        for (int i=0; i<dictionary.size(); i++) {
            string abbr = getAbbr(dictionary[i]);
            auto iter = mp_abbr.find(abbr);
            if (iter == mp_abbr.end()) {
                mp_abbr.insert(std::make_pair(abbr, vector<string>(1, dictionary[i])));
            } else {
                vector<string> &word_list = iter->second;
                if (word_list.size() < 2 && word_list[0] != dictionary[i]) {
                    word_list.push_back(dictionary[i]);
                }
            }
        }
    }

    bool isUnique(string word) {
        auto iter = mp_abbr.find(getAbbr(word));
        if (iter == mp_abbr.end()) {
            return true;
        } else {
            const vector<string> &word_list = iter->second;
            return word_list.size() < 2 && word_list[0] == word;
        }
    }

private:
    unordered_map<string, vector<string> > mp_abbr;
    
    string getAbbr(const string word) {
        if (word.length() <= 2) {
            return word;
        } else {
            return word[0] + std::to_string(word.length() - 2) + word[word.length() - 1];
        }
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");

int main() {
    return 0;
}
