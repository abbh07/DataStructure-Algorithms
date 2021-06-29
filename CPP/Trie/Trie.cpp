#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Trie
{
	unordered_map<char, Trie *> children;
	bool end_of_word;
};

Trie *root = new Trie();

void insert(string word)
{
	Trie *current = root;
	for (int i = 0; i < word.size(); i++)
	{
		char ch = word[i];
		int val = current->children.count(ch); //Returns 1 if ch is found else 0
		Trie *node;
		if (val == 0)
		{
			node = new Trie();
			node->end_of_word = false;
			current->children.insert(make_pair(ch, node));
		}
		else
		{
			node = current->children[ch];
		}
		current = node;
	}
	current->end_of_word = true;
}

//Whole word search
bool search(string word)
{
	Trie *current = root;
	for (int i = 0; i < word.size(); i++)
	{
		char ch = word[i];
		int val = current->children.count(ch);
		Trie *node;
		if (val == 0)
		{
			return false;
		}
		else
		{
			node = current->children[ch];
		}
		current = node;
	}
	return current->end_of_word;
}

bool delete_word(Trie *current, string word, int index)
{
	if (index == word.size())
	{
		if (current->end_of_word == false)
		{
			return false;
		}
		current->end_of_word = false;

		if (current->children.size() == 0)
		{
			delete current;
			return true;
		}
		else
		{
			return false;
		}
	}
	char ch = word[index];
	Trie *node = current->children[ch];
	if (node == NULL)
	{
		return false;
	}

	bool should_delete_current_node = delete_word(node, word, index + 1);

	if (should_delete_current_node)
	{
		current->children.erase(ch);

		if (current->children.size() == 0)
		{
			delete current;
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

int main()
{

	root->end_of_word = false;
	insert("abcd");
	insert("abcde");
	insert("xyz");
	cout << "Searching abcd: " << search("abcd") << endl;
	cout << "Searching abcde: " << search("abcde") << endl;
	cout << "Searching abc: " << search("abc") << endl;
	cout << "Searching xyz: " << search("xyz") << endl;

	Trie *current = root;
	cout << "Deleting abcd" << endl;
	delete_word(current, "abcd", 0);
	cout << "Searching abcd: " << search("abcd") << endl;
	cout << "Deleting abcde" << endl;
	delete_word(current, "abcde", 0);
	cout << "Searching abcde: " << search("abcde") << endl;
	return 0;
}