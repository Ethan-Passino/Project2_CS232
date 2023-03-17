/* File: indexPage.c */
/* Author: Britton Wolfe */
/* Date: September 3rd, 2010 */

/* This program indexes a web page, printing out the counts of words on that page */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ALPHA_SIZE (26)

/* TODO: structure definitions */
struct TrieNode
{
  char data;
  struct TrieNode* nextNode[ALPHA_SIZE];

  // If this is an end of a word, this boolean is true
  int leaf;
};

/* NOTE: int return values can be used to indicate errors (typically non-zero)
   or success (typically zero return value) */

/* TODO: change this return type */
struct TrieNode* indexPage(const char* url);

int addWordOccurrence(const char* word, struct TrieNode* root);

void printTrieContents(struct TrieNode* root);

int freeTrieMemory(struct TrieNode* root);

int getText(const char* srcAddr, char* buffer, const int bufSize);

int main(int argc, char** argv){
  /* TODO: write the (simple) main function
  argv[1] will be the URL to index, if argc > 1 */
if(argc <= 1) {
  printf("You need to input a link. Execute like\n./indexPage <url>");
  exit(-1);
}

  struct TrieNode *root = indexPage(argv[1]);
  
  printTrieContents(root);
  
  freeTrieMemory(root);

  return 0;
}

/* TODO: define the functions corresponding to the above prototypes */


/* Creates a TrieNode with the given data*/
struct TrieNode *create_node(char data) {
  struct TrieNode* node = malloc(sizeof(struct TrieNode));
  for(int i= 0; i < ALPHA_SIZE; i++) {
    node->nextNode[i] = NULL;
  }
  node->leaf = 0; // sets to false
  node->data = data;

  return node;
}


/* TODO: change this return type */
struct TrieNode *indexPage(const char* url) 
{
  /* This is where we create the TrieNode
    Since we create it in the heap memory, 
    as long as we pass the memory address,
    we can access this node
  */

  // Fetching data
  char buffer[100000];
  if(!(getText(url, buffer, 100000))) {
    // If it failed to read, we need to exit
    printf("Failed to get text");
    exit(-1);
  }


  if(buffer[0] == '\0') {
    printf("Had zero words fetched.");
    exit(-1);
  }

  // Create root node
  struct TrieNode *root = create_node(buffer[0]);
  
  // addWordOccurrence somehow???

  printf(buffer);

  return root;
}

int addWordOccurrence(const char* word, struct TrieNode *root)
{

  // This add multiple nodes

  if(*word == '\0') {
    root->leaf = 1;
    return 0;
  }

  int ind = *word - 'a';
  if(root->nextNode[ind] == NULL) {
    root->nextNode[ind] = create_node(word[0]);
  }
  
  addWordOccurrence(word + 1, root->nextNode[ind]);
  return 0;
}

void printTrieContents(struct TrieNode *root)
{
  if(root == NULL) {
    return;
  }

  // Print current nodes character
  printf("%c", root->data);

  if(root->leaf) {
    // Printing new line if it is the end of a word.
    printf("\n");
  }

  // Print child nodes (recursion)
  for( int i = 0; i < ALPHA_SIZE; i++) {
    printTrieContents(root->nextNode[i]);
  }
}

int freeTrieMemory(struct TrieNode *root)
{
  // Null node return
  if(root == NULL) {
    return 0;
  }

  // Recursion free child nodes

  for(int i = 0; i < ALPHA_SIZE; i++) {
    freeTrieMemory(root->nextNode[i]);
  }

  free(root);

  return 0;
}

/* You should not need to modify this function */
int getText(const char* srcAddr, char* buffer, const int bufSize){
  FILE *pipe;
  int bytesRead;

  snprintf(buffer, bufSize, "curl -s \"%s\" | python getText.py", srcAddr);
  
  pipe = popen(buffer, "r");
  if(pipe == NULL) {
    fprintf(stderr, "ERROR: could not open the pipe for command %s\n",
	    buffer);
    return 0;
  }

  bytesRead = fread(buffer, sizeof(char), bufSize-1, pipe);
  buffer[bytesRead] = '\0';

  pclose(pipe);

  return bytesRead;
}
