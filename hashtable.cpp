#include <istream>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 30000; //Size of hashtable

unsigned long hash_func(char* str) {
	unsigned long i = 0;
	for (size_t k = 0; str[k]; ++k) {
		i += str[k];
	}
	return i % CAPACITY;
}


typedef struct { //one element
	char* key;
	char* value;
} Hash_table_item;


typedef struct { //count of elements in table
	Hash_table_item** items;
	int size;
	int count;
} Hashtable;


Hash_table_item* create_item(char* key, char* value) {
	//poiter on new hash table element
	Hash_table_item* item = (Hash_table_item*) malloc (sizeof(Hash_table_item));
	item -> key = (char*) malloc (strlen(key) + 1);
	item -> value = (char*) malloc (strlen(value) + 1);

	strcpy(item -> key, key);
	strcpy(item -> value, value);

	return item;
}


Hashtable* create_table(int size) {
	Hashtable* table = (Hashtable*) malloc (sizeof(Hashtable));
	table -> size = size;
	table -> count = 0;
	table -> items = (Hash_table_item**) calloc (table -> size, sizeof(Hash_table_item*));
	for (size_t k = 0; k < table -> size; ++k) {
		table -> items[k] = NULL;
	}
	return table;
}


void clear_item(Hash_table_item* item) {
	free(item -> key);
	free(item -> value);
	free(item);
}


void clear_table(Hashtable* table) {
	for (size_t k = 0; k < table -> size; ++k) {
		Hash_table_item* item = table -> items[k];
		if (item != NULL) {
			clear_item(item);
		}
	}
	free(table -> items);
	free(table);
}


/*void hash_table_insert(Hashtable* table, char* key, char* value) {
	Hash_table_item* item = create_item(key, value);
	unsigned long index = hash_func(key);
	Hash_table_item* current_item = table -> items[index];

	if (current_item == NULL) {
		if (table -> count == table -> size) {
			cout << "Insert Erroe: Hash table is full \n";
			clear_item(item);
			return;
		}
		table -> items[index] = item;
		table -> count++;
	}
	else {
		if (srtcmp(current_item -> key, key) == 0) {
			strcpy(table -> items[index] -> value, value);
			return;
		}
		else {

		}
	}
}*/


int main(int argc, char const *argv[])
{
	
	return 0;
}