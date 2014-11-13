/* Write a C implementation of a trie to store names and Student ID's */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHAR_IDX(ch) ((int)ch - (int)'a')

typedef struct trie_node {
    int val;
    struct trie_node *children[26];
}node;

typedef struct trie {
    node *root;
    int count;
}trie;

node* getNewNode()
{
    node *temp = (node *)malloc(sizeof(node));
    
    temp->val = -1;

    for (int i = 0; i < 26; i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
    //temp->children = (node *)calloc(
}

void init(trie *wtrie)
{
    wtrie->root = getNewNode();
    wtrie->count = 0;
}

void insert(trie *wtrie, char *key, int val)
{
    int len = strlen(key);
    node *tempTrie = wtrie->root;
    for (int i = 0; i < len; i++)
    {
        if (tempTrie->children[CHAR_IDX(key[i])] == NULL)
        {
//            printf("New Node Inserted.\t");
            tempTrie->children[CHAR_IDX(key[i])] = getNewNode();
        }
        tempTrie = tempTrie->children[CHAR_IDX(key[i])];
    }
    tempTrie->val = val;
    wtrie->count++;
    printf("\nTrie Inserted new Name : %d\n", val);
}

int search(trie wtrie, char *key)
{
    int len = strlen(key);
    node *tempTrie = wtrie.root;
    for (int i = 0; i < len; i++)
    {
        if (tempTrie->children[CHAR_IDX(key[i])] == NULL)
        {
//            printf("New Node Inserted.\t");
            return -1;
        }
        tempTrie = tempTrie->children[CHAR_IDX(key[i])];
    }
    return tempTrie->val;
    //printf("\nTrie Inserted new Name : %d\n", val);
}


int main()
{
    trie wtrie;
    init(&wtrie);
    
    insert(&wtrie, "Sohil", 892);
    insert(&wtrie, "Aniket",245);
    insert(&wtrie, "Sohail", 123);
 
    int ret;
    char key[7] = "Sohail\0";
    if ((ret = search(wtrie, key)) == -1)
        printf("\nName \"%s\" not found\n", key);
    else
        printf("\nSearch for %s id %d\n", key, ret);
    
    return 0;
}
