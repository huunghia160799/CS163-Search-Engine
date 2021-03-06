#pragma once
#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef map<string, int> word_map;

const int MAX_FILE_COUNT=2268;
#define mp make_pair
#define ALP 39 //the number of words in the alphabet + 10 digits + '$' + '#' + "  '  "

//forward declaration
class Word_t;
class Trie_t;
class Word_t;
struct Article_t;

//represent a file
struct Node {
	int keyword_count, file_name, best_paragraph;
	Node(int x, int y, int z)
		:keyword_count(x), file_name(y), best_paragraph(z) {};
	Node(int x, int y)
		:keyword_count(x), file_name(y) {};
};

//represent a word in the Trie Tree
class Word_t {
public:
	friend Trie_t;
	vector<string>synonyms;
private:
	vector<Node>file_list, title_list;
	Word_t *link[ALP] = { NULL };
	bool is_end = false;
};

struct Article_t {
	int word_count, best_para_posi, best_para_word_count, word_count_title;
	bool is_intitle = false;
};

struct Para_t {
	int word_count, word_count_title;
	bool is_intitle = false;
};

class Trie_t {
public:
	Trie_t();
	Word_t* insert(string word);
	Word_t* search(string word);
	vector<Node> getKeywordData(string keyword, set<string> &highlightWords); // return data of a keyword
	//read the data into the Trie
	void inputFromFile(const string& folder_path);
	//add at most 3 symnonyms(if exist) to vector<string>symnonyms
	void inputSynonymFromFile();
	//add all the numbers found into set<ll>numbers
	void addAllNumbers(const string& word);
	vector<Node> getQueryData(string quiery, set<string> &highlightWords); // return ranking of a quiery and the words that need to be highlights in the text
private:
	Word_t * root = NULL;
	set<ll>numbers;
};

//auxilary functions
string itoXX(int number);
bool NodeMaxFirst(Node a, Node b);
int linkIndex(char x);

// vector functions
void operator+= (vector<Node> &v1, const vector<Node> &v2); // add two vectors
vector<Node> merge(const vector<Node> &v1, const vector<Node> &v2, int bonusPoint = 0); // return nodes in v1 or v2, there's a bonus point for nodes in both 2 vector
vector<Node> substract (const vector<Node> &v1, const vector<Node> &v2); // return nodes in v1 but not in v2
vector<Node> intersect(const vector<Node> &v1, const vector<Node> &v2); // return nodes in both v1 and v2

// string functions
vector<string> splitString(string inputStr); // split intputStr into tokens
vector<string> findExactValue(string keyword, const set<long long> &existValue); /* replace range in keyword by value in existValue array
	Precondition: existValue should be sorted*/
string getFileName(int fileName);
int countFreq(const string &pattern, const string &text, set<string> &highlightWords); // find frequency of pattern in text
bool wildCardMatch(string& input, string& pattern);

bool exist(vector<Node> v, int file_name);
void preprocessing(string& word, set<ll>& numbers_in_word);
void preprocessing(string& word);
vector<ll> numbersInString(const string& word);
bool checkStopWordUsingTrie_t (string word);
string indexToFilename(int index);

#endif // !_FUNCTION_H_
