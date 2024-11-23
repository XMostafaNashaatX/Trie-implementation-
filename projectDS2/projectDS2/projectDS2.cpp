#include <iostream>
using namespace std;

struct Node {
    Node* links[26];
    int cntPrefix = 0;
    int cntEndWith = 0;
    bool flag = false;

    bool contains(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void End() {
        flag = true;
        cntEndWith++;
    }

    bool wordEnd() {
        return flag;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    void increasePrefix() {
        cntPrefix++;
    }   

    void increaseEnd() {
        cntEndWith++;
    }

    void deleteEnd() {
        cntEndWith--;
        flag = false;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->contains(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->End();
    }

    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->contains(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->wordEnd();
    }
    void multisearch(int n) {
        for (int i = 0; i < n; ++i) {
            string word;
            cout << "please enter your word:"<<endl;
            cin >> word;
            cout<<search(word)<<endl;
        }
    }

    void del(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->contains(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else {
                return;
            }
        }
        node->deleteEnd();
    }

    void printWords(Node* node = nullptr, string word = "") {
        if (!node) node = root;

        if (node->wordEnd()) {
            cout << word << endl;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (node->contains(ch)) {
                printWords(node->get(ch), word + ch);
            }
        }
    }

    string endsWith(string suffix) {
        string result = "";
        endsWithHelper(root, "", suffix, result);
        return result;
    }

    void endsWithHelper(Node* node, string currentWord, string suffix, string result) {
        if (!node) 
            return;

        if (node->wordEnd() && currentWord.size() >= suffix.size()) {
            bool match = true;
            int suffixIdx = suffix.size() - 1;
            int wordIdx = currentWord.size() - 1;
            while (suffixIdx >= 0) {
                if (suffix[suffixIdx] != currentWord[wordIdx]) {
                    match = false;
                    break;
                }
                suffixIdx--;
                wordIdx--;
            }
            if (match) {
                result += currentWord+" ";
            }
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (node->contains(ch)) {
                endsWithHelper(node->get(ch), currentWord + ch, suffix, result);
            }
        }
    }

    string fuzzySearch(string pattern) {
        if (pattern.empty()) 
            return 0;

        if (pattern[0] == '?') {
            string suffix;
            for (int i = 1; i < pattern.size(); ++i) {
                suffix += pattern[i];
            }
            return endsWith(suffix);
        }
        else if (pattern[pattern.size()-1] == '?') {
            string prefix;
            for (int i = 0; i < pattern.size() - 1; ++i) {
                prefix += pattern[i];
            }
            return startsWith(prefix);
        }
   
    }
    string startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->contains(ch)) {
                return "No words found with the prefix '" + prefix + "'";
            }
            node = node->get(ch);
        }

        string result;
        string currentWord = prefix;
        collectWords(node, currentWord, result);
        return result;
    }
    void collectWords(Node* node, string currentWord, string& result) {
        if (node->wordEnd()) {
            result += currentWord +" ";
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (node->contains(ch)) {
                collectWords(node->get(ch), currentWord + ch, result);
            }
        }
    }
    string searchMisspelled(string word) {
        int tolerance = 4 ;
        Node* node = root;
        int depth = 0;
        int mismatches = 0;
        string possibleWord;

        while (depth+1 <= word.size() && mismatches <= tolerance) {
            char ch = word[depth];
            if (node->contains(ch)) {
                possibleWord += ch;
                node = node->get(ch);
            }
            else {
                mismatches++;
                if (mismatches > tolerance) {
                    return ""; 
                }
                depth++;
                continue;
            }
            depth++;
        }

        if (node->wordEnd()) {
            return possibleWord;
        }
        else {

            return startsWith(possibleWord); 
        }
    }



};

int main() {
    Trie trie;
    trie.insert("kareem");
    trie.insert("apple");
    trie.insert("application");
    trie.insert("apps");
    trie.insert("append");
    trie.insert("banana");
    trie.insert("bat");
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");
    trie.insert("duck");
    trie.insert("elephant");
    trie.insert("eleven");
    trie.insert("zoo");
    trie.insert("low");
    trie.insert("lower");
    string word;
    cout << "enter a word to search for:";
    cin >> word;
    if (trie.search(word) == 1) {
        cout << "the word was found" << endl;
        if (word == "karim") {
            cout << "karim is amazing" << endl;
        }
    }
    else cout << "the word was not found" << endl;
    cout << "enter a preffix to search for:";
    cin >> word;
    cout<<trie.startsWith(word)<<endl;
    cout << "enter a suffix to search for:";
    cin >> word;
    cout << trie.endsWith(word) << endl;
    cout << "enter a fuzzysearch to search for:";
    cin >> word;
    cout << trie.fuzzySearch(word) << endl;
    cout << "enter a misspelled word to search for:";
    cin >> word;
    cout << trie.searchMisspelled(word)<<endl;
    cout << "___________________________"<<endl;
    trie.printWords();
    cout << "enter a  word to delete :";
    cin >> word;
    trie.del(word);
    cout << "______________" << endl;
    trie.printWords();
    int n;
    cout << "how many words do you want to search for:";
    cin >> n;
    trie.multisearch(n);
    return 0;
}