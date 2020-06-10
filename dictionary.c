// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"


// Defines struct for a node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];



// Returns true if word is in dictionary else false
bool check(const char *word)
{

    int n = strlen(word);

    char buffer[LENGTH + 1];

    for (int i = 0; i < n; i++)
    {
        buffer[i] = tolower(word[i]);
    }

    buffer[n] = '\0';


    int index = hash(buffer);

    node *cursor = table[index];



    while (cursor != NULL)
    {

        if (strcasecmp(cursor->word, buffer) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}



// Hashes word to a number
//source https://cs50.stackexchange.com/questions/37209/pset5-speller-hash-function in 06/09/2020
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash_value = (hash_value << 2) ^ word[i];
    }
    return hash_value % N;
}



// Number of words
int word_count = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    // Opens dictionary
    FILE *file = fopen(dictionary, "r");


    if (file == NULL)
    {
        return false;
    }



    char buffer[LENGTH + 1];


    while (fscanf(file, "%s", buffer) != EOF)
    {

        node *new_node = malloc(sizeof(node)); //aloca espaço para criar novo node


        if (new_node == NULL)
        {
            return false;
        }


        strcpy(new_node->word, buffer);

        int index = hash(new_node->word); //chama função hash para pegar numero index


        node *head = table[index];

        //inserir o node no começo  da hash table.
        if (head == NULL)
        {
            table[index] = new_node;
            word_count++;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
            word_count++;
        }

    }


    fclose(file);
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}


// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = NULL;

    for (int i = 0; i < N; i++)
    {


        cursor = table[i];


        if (cursor != NULL)
        {
            node *temp = NULL;

            temp = cursor;

            cursor = cursor->next;

            free(temp);
        }


    }

    return true;
}