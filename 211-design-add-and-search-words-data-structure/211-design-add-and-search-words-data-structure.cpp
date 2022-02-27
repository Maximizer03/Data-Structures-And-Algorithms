struct Node {
	Node * links[26];
	bool flg = false;
	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch, Node * node) {
		links[ch - 'a'] = node;
	}
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	void setEnd() {
		flg = true;
	}
	bool getEnd() {
		return flg;
	}
};

class WordDictionary {
private:
	Node * root;
public:
	WordDictionary() {
		root = new Node();
	}
	void addWord(string word) {
		Node * node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				node->put(word[i], new Node());
			}
			node = node->get(word[i]);
		}
		node->setEnd();
	}
	bool calc(string &word, Node* node) {
		for (int i = 0; word[i] && node; i++) {
			if (word[i] != '.') {
				node = node -> links[word[i] - 'a'];
			} 
            else {
				Node* tmp = node;
				for (int j = 0; j < 26; j++) {
					node = tmp -> links[j];
					string sub = word.substr(i + 1);
					if (calc(sub, node)) {
						return true;
					}
				}
                return false;
			}
		}
		return node && node->getEnd();
	}
	bool search(string word) {
		Node * node = root;
		return calc(word, node);
	}
};
