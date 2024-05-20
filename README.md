# Trie Data Structure Implementation in C++ 
Overview 
This repository contains an implementation of a Trie (prefix tree) data structure in C++. The Trie supports various operations such as insertion, searching, prefix search, suffix search, fuzzy search, and deletion. 
# Node Structure 
Description 
The Node structure represents each node in the Trie. It has: 
•	links[26]: An array of pointers to child nodes, corresponding to each letter of the English alphabet. 
•	cntPrefix: A counter tracking the number of words that share the same prefix. 
•	cntEndWith: A counter tracking the number of words ending at this node. 
•	flag: A boolean indicating if this node marks the end of a word. 
# Functions 
•	contains(char ch): Checks if a node contains a link for a given character. 
•	*put(char ch, Node node)**: Adds a link to a given character. 
•	get(char ch): Retrieves the link to the next node for a given character. 
•	End(): Marks the end of a word at this node. 
•	wordEnd(): Checks if this node marks the end of a word. 
•	reducePrefix(): Decreases the prefix counter. 
•	increasePrefix(): Increases the prefix counter. 
•	increaseEnd(): Increases the end counter. 
•	deleteEnd(): Decreases the end counter and unmarks the end of the word. 
# Trie Class 
# Description 
The Trie class manages the root node and provides methods to manipulate the Trie. 
Constructor 
•	Trie(): Initializes the root node. 
# Member Functions 
•	insert(string word): Inserts a word into the Trie. 
•	search(string word): Searches for a word in the Trie and returns true if found, otherwise false. 
•	multisearch(int n): Allows multiple word searches based on user input. 
•	del(string word): Deletes a word from the Trie. 
•	*printWords(Node node = nullptr, string word = "")**: Prints all words stored in the Trie. 
•	endsWith(string suffix): Finds and returns words ending with a given suffix. 
•	fuzzySearch(string pattern): Performs a fuzzy search based on a pattern containing '?'. 
•	startsWith(string prefix): Finds and returns words starting with a given prefix. 
•	*collectWords(Node node, string currentWord, string& result)**: Helper function to collect words with a given prefix. 
•	searchMisspelled(string word): Searches for a word with some tolerance for misspelling. 
# Usage Examples 
Insertion 
To insert words into the Trie: 
1.	Create an instance of the Trie. 
2.	Call the insert function with the word you want to insert. 
Searching 
To search for a word: 
3.	Call the search function with the word you want to search for. 
4.	The function returns true if the word is found, otherwise false. 
Prefix Search 
To find words starting with a given prefix: 
5.	Call the startsWith function with the prefix. 
6.	The function returns words that start with the given prefix. 
Suffix Search 
To find words ending with a given suffix: 
7.	Call the endsWith function with the suffix. 
8.	The function returns words that end with the given suffix. 
Fuzzy Search 
To perform a fuzzy search: 
9.	Call the fuzzySearch function with a pattern containing '?'. 
10.	The function returns words matching the pattern. 
Misspelled Word Search 
To search for a misspelled word with tolerance: 
11.	Call the searchMisspelled function with the misspelled word. 
12.	The function returns possible words that match the misspelled word within a certain tolerance. 
Deletion 
To delete a word from the Trie: 
13.	Call the del function with the word you want to delete. 
Print All Words 
To print all words stored in the Trie: 
14.	Call the printWords function. 
Multiple Search 
To search for multiple words based on user input: 
15.	Call the multisearch function with the number of words you want to search for. 
16.	Enter the words when prompted. 
Example Main Function 
The main function demonstrates how to use the Trie class and its functions: 
17.	Create an instance of the Trie. 
18.	Insert multiple words. 
19.	Perform various search operations. 
20.	Print all words. 
21.	Delete words. 
22.	Perform multiple word searches based on user input. 
# Conclusion 
This implementation of a Trie in C++ provides a comprehensive set of operations to manage and query a collection of words efficiently. It can be used as a basis for applications requiring fast word searches, autocomplete systems, spell checkers, and more. 
 

