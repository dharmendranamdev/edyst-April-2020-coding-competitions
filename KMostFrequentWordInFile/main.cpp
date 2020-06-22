// A program to find k most frequent words in a file
#include <stdio.h>
#include <string.h>
#include <ctype.h>

# define MAX_CHARS 26
# define MAX_WORD_SIZE 30

// A Trie node
struct TrieNode
{
	bool isEnd; // indicates end of word
	unsigned frequency; // the number of occurrences of a word
	int indexMinHeap; // the index of the word in minHeap
	TrieNode* child[MAX_CHARS]; // represents 26 slots each for 'a' to 'z'.
};

// A Min Heap node
struct MinHeapNode
{
	TrieNode* root; // indicates the leaf node of TRIE
	unsigned frequency; // number of occurrences
	char* word; // the actual word stored
};

// A Min Heap
struct MinHeap
{
	unsigned capacity; // the total size a min heap
	int count; // indicates the number of slots filled.
	MinHeapNode* array; // represents the collection of minHeapNodes
};

// A utility function to create a new Trie node
TrieNode* newTrieNode()
{
	// Allocate memory for Trie Node
	TrieNode* trieNode = new TrieNode;

	// Initialize values for new node
	trieNode->isEnd = 0;
	trieNode->frequency = 0;
	trieNode->indexMinHeap = -1;
	for( int i = 0; i < MAX_CHARS; ++i )
		trieNode->child[i] = NULL;

	return trieNode;
}

// A utility function to create a Min Heap of given capacity
MinHeap* createMinHeap( int capacity )
{
	MinHeap* minHeap = new MinHeap;

	minHeap->capacity = capacity;
	minHeap->count = 0;

	// Allocate memory for array of min heap nodes
	minHeap->array = new MinHeapNode [ minHeap->capacity ];

	return minHeap;
}

// A utility function to swap two min heap nodes. This function
// is needed in minHeapify
void swapMinHeapNodes ( MinHeapNode* a, MinHeapNode* b )
{
	MinHeapNode temp = *a;
	*a = *b;
	*b = temp;
}

// This is the standard minHeapify function. It does one thing extra.
// It updates the minHapIndex in Trie when two nodes are swapped in
// in min heap
void minHeapify( MinHeap* minHeap, int idx )
{
	int left, right, smallest;

	left = 2 * idx + 1;
	right = 2 * idx + 2;
	smallest = idx;
	if ( left < minHeap->count &&
		minHeap->array[ left ]. frequency <
		minHeap->array[ smallest ]. frequency
	)
		smallest = left;

	if ( right < minHeap->count &&
		minHeap->array[ right ]. frequency <
		minHeap->array[ smallest ]. frequency
	)
		smallest = right;

	if( smallest != idx )
	{
		// Update the corresponding index in Trie node.
		minHeap->array[ smallest ]. root->indexMinHeap = idx;
		minHeap->array[ idx ]. root->indexMinHeap = smallest;

		// Swap nodes in min heap
		swapMinHeapNodes (&minHeap->array[ smallest ], &minHeap->array[ idx ]);

		minHeapify( minHeap, smallest );
	}
}

// A standard function to build a heap
void buildMinHeap( MinHeap* minHeap )
{
	int n, i;
	n = minHeap->count - 1;

	for( i = ( n - 1 ) / 2; i >= 0; --i )
		minHeapify( minHeap, i );
}

// Inserts a word to heap, the function handles the 3 cases explained above
void insertInMinHeap( MinHeap* minHeap, TrieNode** root, const char* word )
{
	// Case 1: the word is already present in minHeap
	if( (*root)->indexMinHeap != -1 )
	{
		++( minHeap->array[ (*root)->indexMinHeap ]. frequency );

		// percolate down
		minHeapify( minHeap, (*root)->indexMinHeap );
	}

	// Case 2: Word is not present and heap is not full
	else if( minHeap->count < minHeap->capacity )
	{
		int count = minHeap->count;
		minHeap->array[ count ]. frequency = (*root)->frequency;
		minHeap->array[ count ]. word = new char [strlen( word ) + 1];
		strcpy( minHeap->array[ count ]. word, word );

		minHeap->array[ count ]. root = *root;
		(*root)->indexMinHeap = minHeap->count;

		++( minHeap->count );
		buildMinHeap( minHeap );
	}

	// Case 3: Word is not present and heap is full. And frequency of word
	// is more than root. The root is the least frequent word in heap,
	// replace root with new word
	else if ( (*root)->frequency > minHeap->array[0]. frequency )
	{

		minHeap->array[ 0 ]. root->indexMinHeap = -1;
		minHeap->array[ 0 ]. root = *root;
		minHeap->array[ 0 ]. root->indexMinHeap = 0;
		minHeap->array[ 0 ]. frequency = (*root)->frequency;

		// delete previously allocated memoory and
		delete [] minHeap->array[ 0 ]. word;
		minHeap->array[ 0 ]. word = new char [strlen( word ) + 1];
		strcpy( minHeap->array[ 0 ]. word, word );

		minHeapify ( minHeap, 0 );
	}
}

// Inserts a new word to both Trie and Heap
void insertUtil ( TrieNode** root, MinHeap* minHeap,
						const char* word, const char* dupWord )
{
	// Base Case
	if ( *root == NULL )
		*root = newTrieNode();

	// There are still more characters in word
	if ( *word != '\0' )
		insertUtil ( &((*root)->child[ tolower( *word ) - 97 ]),
						minHeap, word + 1, dupWord );
	else // The complete word is processed
	{
		// word is already present, increase the frequency
		if ( (*root)->isEnd )
			++( (*root)->frequency );
		else
		{
			(*root)->isEnd = 1;
			(*root)->frequency = 1;
		}

		// Insert in min heap also
		insertInMinHeap( minHeap, root, dupWord );
	}
}


// add a word to Trie & min heap. A wrapper over the insertUtil
void insertTrieAndHeap(const char *word, TrieNode** root, MinHeap* minHeap)
{
	insertUtil( root, minHeap, word, word );
}

// A utility function to show results, The min heap
// contains k most frequent words so far, at any time
void displayMinHeap( MinHeap* minHeap )
{
	int i;

	// print top K word with frequency
	for( i = 0; i < minHeap->count; ++i )
	{
		printf( "%s : %d\n", minHeap->array[i].word,
							minHeap->array[i].frequency );
	}
}

// The main funtion that takes a file as input, add words to heap
// and Trie, finally shows result from heap
void printKMostFreq( FILE* fp, int k )
{
	// Create a Min Heap of Size k
	MinHeap* minHeap = createMinHeap( k );

	// Create an empty Trie
	TrieNode* root = NULL;

	// A buffer to store one word at a time
	char buffer[MAX_WORD_SIZE];

	// Read words one by one from file. Insert the word in Trie and Min Heap
	while( fscanf( fp, "%s", buffer ) != EOF )
		insertTrieAndHeap(buffer, &root, minHeap);

	// The Min Heap will have the k most frequent words, so print Min Heap nodes
	displayMinHeap( minHeap );
}

// Driver program to test above functions
int main()
{
	int k = 5;
	FILE *fp = fopen ("file.txt", "r");
	if (fp == NULL)
		printf ("File doesn't exist ");
	else
		printKMostFreq (fp, k);
	return 0;
}
