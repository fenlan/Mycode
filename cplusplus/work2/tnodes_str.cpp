/* Author: fenlan
 * Date: 2017.4.25
 * ---------------------------------------
 *  	Write a function for entering new
 * words into a tree of Tnodes. Write a
 * function to write out a tree of Tnodes.
 * Write a function to write out a tree of
 * Tnodes with the words in alphabetical
 * order.
 * ---------------------------------------
 *  input:
 *  	one two three ;
 *  output:
 *  	one three two
 * ---------------------------------------
 */

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct Tnode {
    string word;
    int count;
    Tnode* left;
    Tnode* right;
}*Tree;

void create(Tree &root);
void insert(Tree &root, string word);
void middle_order(Tree &root);

int main()
{
    string word;
    Tree tree;
    Tnode root;
    tree = &root;

    create(tree);
    while(true) {
        cin >> word;
        if (word == ";")    break;
        insert(tree, word);
    }

    middle_order(tree);
    return 0;
}

void create(Tree &root)
{
    string word;
    Tree newnode;

    cin >> word;
    newnode = (Tree)malloc(sizeof(Tnode));
    newnode->word = word;
    newnode->count = 1;
    newnode->left = newnode->right = NULL;
    root = newnode;
}

void insert(Tree &root, string word)
{
    if (root == NULL) {
        Tree newnode;

        newnode = (Tree)malloc(sizeof(Tnode));
        newnode->word = word;
        newnode->count = 1;
        newnode->left = newnode->right = NULL;
        root = newnode;
    }
    else if (root->word > word)      insert(root->left, word);
    else if (root->word < word)      insert(root->right, word);
}

void middle_order(Tree &root) {
	if (root != NULL) {
		middle_order(root->left);
		cout << root->word << " ";
        free(root);
		middle_order(root->right);
	}
}
