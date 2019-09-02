#ifndef TREE_INCLUDE
#define TREE_INCLUDE
#include <string>
#include <unordered_map>
class Node
{
private:
    std::unordered_map<char, Node *> child;
    bool isWordEnd;
    std::string value;
    friend class Trie;

public:
    Node()
    {
        isWordEnd = false;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie();
    std::string search(std::string key);
    void insert(std::string s, std::string val);
};
#endif