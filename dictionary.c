// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

int number_words = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536; //1

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) //source https://cs50.stackexchange.com/questions/37209/pset5-speller-hash-function in 06/09/2020
{

    unsigned int hash_value = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
         hash_value = (hash_value << 2) ^ word[i];
    }
    return (int)((hash >> 16) ^ (hash & 0xffff));    //hash % N; N is size of hashtable

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    //open file //verifica se abriu // if return value is NULL, return false, senão continua
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open the file");
        return FALSE;
    }


    char buffer[LENGTH + 1];
    int index = 0;



    while (buffer != EOF)
    {
        fscanf(file, "%s", buffer);

        node *newnode = malloc(sizeof(node)); //aloca espaço para criar novo node
        if (newnode == NULL)
        {
            return FALSE;
        }

        strcpy(newnode->word, buffer); //coloca word dentro do campo 'word' do node indicado por n

        newnode->next = NULL; //zera ponteiro novo

        index = hash(buffer); //chama função hash para pegar numero index


        //inserir o node dentro da hash table.
        newnode->next = table[index];

        table[index] = newnode; //acho que tá errado!!!! talvez  table[index].next ???

        number_words++;

    }


    // close the file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return number_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}


// ------------ FUNÇÃO LOAD

//ler strings desse arquivo  uma a uma

//fscanf(file, "%s", word)
//file: ponteiro para o arquivo
// %s quer dizer que vc quer ler uma string
//word ARRAY DE CARACTERES que vai guardar a palavra lida

//repetir até:
//fscanf vai retornar EOF qundo chegar no final do arquivo


//criar um node para cada palavra
//usar malloc e checar se return value is NULL
//copiar word into node usando strcpy

//agora inserir o node dentro da hash table.. como?
//hash word para obter um hash value
//usar a função hash, definida em dic..c, que pega uma string e retorna um index, um numero que pode ser usado para index na lista


//inserir node na hash table do lugar dado pela hash function
//novo ponteiro deve apontar para o começo da lista, depois o primeiro ponteiro "head" aponta para ele


//// Hash table
//node *table[N];

//node *n = malloc()sizeof(node); //aloca espaço para criar novo node

//strcpy(n->word, "hello"); //coloca hello dentro do campo 'word' do node indicado por n

// n->next = NULL; //n aponta para