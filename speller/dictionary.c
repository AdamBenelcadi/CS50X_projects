// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Loads dictionary into memory, returning true if successful, else false

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

node *head;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int sum;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    node *cursor = table[hash(word)];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hash_value = 0;
    int X = strlen(word);
    for (int i = 0; i < X; i++)
    {
        hash_value += (int) toupper(word[i]);
    }
    unsigned int index = hash_value % 26;
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    sum = 0;
    FILE *p = fopen(dictionary, "r");
    if (p != NULL)
    {
        char word[LENGTH + 1];
        while (fscanf(p, "%s", word) != EOF)
        {
            node *pt = malloc(sizeof(node));
            if (pt == NULL)
            {
                return false;
            }
            strcpy(pt->word, word);
            int index = hash(word);
            pt->next = table[index];
            table[index] = pt;
            sum++;
        }
        fclose(p);
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return sum;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++) // N should be the size of your hash table
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
