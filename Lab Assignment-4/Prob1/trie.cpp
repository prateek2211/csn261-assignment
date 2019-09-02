#include "trie.h"
void Trie::insert(std::string key, std::string val)
{
    Node *node = root;
    for (const char &c : key)
    {
        if (node->child[c - 'a'] == nullptr)
            node->child[c - 'a'] = new Node();
        node = node->child[c - 'a'];
    }
    node->value = val;
    node->isWordEnd = true;
}
std::string Trie::search(std::string key)
{
    Node *node = root;
    for (const char &c : key)
    {
        if (node->child[c - 'a'] == nullptr)
            return "";
        node = node->child[c - 'a'];
    }
    if (node->isWordEnd)
        return node->value;
    return "";
}
Trie::Trie()
{
    root = new Node();
}
