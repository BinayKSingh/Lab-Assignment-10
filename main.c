#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct Trie {
    int count;
    struct Trie* children[ALPHABET_SIZE];
};

void insert(struct Trie **ppTrie, char *word) {
    int LCV = 0;                //Loop control variable
    int index = 0;
    char* p = word;
    
    if (*ppTrie == NULL) {
        *ppTrie = (struct Trie*) malloc(sizeof(struct Trie));
        (*ppTrie)->count = 0;
        for (LCV = 0; LCV < ALPHABET_SIZE; LCV++) {
            (*ppTrie)->children[i] = NULL;
        }
    }
    struct Trie* pTrie = *ppTrie;
    for (p = word; *p != '\0'; p++) {
        index = *p - 'a';
        if (pTrie->children[index] == NULL) {
            pTrie->children[index] = (struct Trie*) malloc(sizeof(struct Trie));
            pTrie->children[index]->count = 0;
            for (LCV = 0; LCV < ALPHABET_SIZE; LCV++) {
                pTrie->children[index]->children[LCV] = NULL;
            }
        }
        pTrie = pTrie->children[index];
    }
    pTrie->count++;
}

int numberOfOccurances(struct Trie *pTrie, char *word) {
    int index = 0;
    char* p = word;

    if (pTrie == NULL) {
        return 0;
    }
    for (p = word; *p != '\0'; p++) {
        index = *p - 'a';
        if (pTrie->children[index] == NULL) {
            return 0;
        }
        pTrie = pTrie->children[index];
    }
    return pTrie->count;
}

struct Trie *deallocateTrie(struct Trie *pTrie) {
    if (pTrie == NULL) {
        return NULL;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pTrie->children[i] = deallocateTrie(pTrie->children[i]);
    }
    free(pTrie);
    return NULL;
}

int main(void) {
    struct Trie *trie = NULL;
    int numWords;
    int LCV = 0;
    char word[100];
    char** pp = pWords;

    // read the number of the words in the dictionary
    scanf("%d", &numWords);

    // parse line by line, and insert each word to the trie data structure
    for (LCV = 0; LCV < numWords; lCV++) {
        scanf("%s", word);
        insert(&trie, word);
    }

    // test the trie data structure
    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (pp = pWords; *pp != NULL; pp++) {
        printf("\t%s : %d\n", *pp, numberOfOccurances(trie, *pp));
    }

    trie = deallocateTrie(trie);
    if (trie != NULL) {
        printf("There is an error in this program\n");
    }

    return 0;
}
