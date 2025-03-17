#include "ladder.h"


void error(string word1, string word2, string msg) {
    cout << word1 << word2 << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();

    //can allow one character insertions or deletions so lengths don't have to be equal
    if(abs(len1-len2) > d) // more than 1 character difference
        return false;
    
    //iterate through both strings and count number of differences
    int diff_count = 0;
    int i = 0, j = 0;
    while(i < len1 && j < len2) {
        if(str1[i] != str2[j]){
            ++diff_count;
            if(diff_count > d) return false; //more than 1 char difference

            if(len1 > len2) ++i;
            else if(len2 > len1) ++j;
            else{
                ++i; ++j;
            }
        }
        else{ ++i; ++j; }
    }
    diff_count += (len1 - i) + (len2 - j);
    return diff_count <= d;


}
bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();

        string last_word = ladder.back();

        for(string word: word_list) {
            if(is_adjacent(last_word, word)){
                if(visited.find(word) == visited.end()) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word) return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return {};
}
void load_words(set<string> & word_list, const string& file_name) {
    ifstream inFile;
    inFile.open(file_name);
    string line = "";
    while(getline(inFile, line))
        word_list.insert(line);
    inFile.close();
}
void print_word_ladder(const vector<string>& ladder) {
    if(ladder.empty()) 
        return error("", "", "No word ladder found.");
    cout << "Word ladder found: ";
    for(string word : ladder) {
        cout << word << " ";
    }
    cout << endl;
}


//needs to be defined on same line
#define my_assert(e) { cout << #e << ((e) ? " passed" : " failed") << endl; }

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    //add my_assert tests
}