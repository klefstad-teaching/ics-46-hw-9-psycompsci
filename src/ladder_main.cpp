#include "ladder.h"

int main() {

    string begin = "", end = "";
    set<string> word_list;
    load_words(word_list, "words.txt");

    cout << "enter first word: " << endl;
    cin >> begin;

    cout << "enter second word (target/destination): " << endl;
    cin >> end;

    vector<string> ladder = generate_word_ladder(begin, end, word_list);
    print_word_ladder(ladder);
    cout << endl;

    return 0;
}