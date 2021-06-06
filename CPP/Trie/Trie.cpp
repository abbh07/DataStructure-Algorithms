#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Trie
{
	map<char,Trie*> children;
	bool end_of_word;
};

Trie *root = new Trie();

void insert(string word)
{
	Trie *current = root;
	for(int i=0;i<word.size();i++)
	{
		char ch = word[i];
		int val  = current->children.count(ch);//Returns 1 if ch is found else 0
		Trie *node;
		if(val == 0)
		{
			node = new Trie();
			node->end_of_word = false;
			current->children.insert(make_pair(ch,node));
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
	for(int i=0;i<word.size();i++)
	{
		char ch = word[i];
		int val = current->children.count(ch);
		Trie *node;
		if(val == 0)
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

int main()
{
	
	root->end_of_word = false;
	insert("abcd");
	insert("abcde");
	insert("xyz");
	cout<<search("abcd")<<endl;
	cout<<search("abcde")<<endl;
	cout<<search("abc")<<endl;
	cout<<search("xyz")<<endl;
	return 0;
}