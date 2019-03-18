#pragma once
#include <string>
#include <iostream>

using namespace std;

template<typename K,typename V>
class HashTable {

public:
	int Size;
	HashTable(int size) {
		Size = size;
		tablepointer = new Node*[size];
		//initialized all the items to null to help with debugging
		for (int i = 0; i < Size; i++)
		{
			tablepointer[i] = nullptr;

		}
	}
	void Insert(K key, V value) {
		int index = Hash(key);
		//if the spot in the array is open then we add the new node here
		if (tablepointer[index] == nullptr) {
			tablepointer[index] = new Node(key, value);
		}
		else {
			Node* temp = tablepointer[index];

			//needed to put this out side aswell so it checks if theres only one item in the list
			if (temp->key == key) {
				temp->value = value;
				return;
			}

			while (temp->Next != nullptr) {
				if (temp->key == key) {
					temp->value = value;
					return;
				}
				temp = temp->Next;
			}

			temp->Next = new Node(key, value);
		}
		
	}

	//returns the value of a certain key
	V Retrieve(K key) {
		int index = Hash(key);
		Node* temp = tablepointer[index];

		//cycles through all the nodes at that index and returns the key if it finds it
		while (temp != nullptr) {
			if (temp->key == key) {
				return temp->value;
			}
			temp = temp->Next;
		}
		return NULL;
	}


	void Display() {
		cout << "Hash Table Contains:" << endl;

		//for each spot in the array it prints all the nodes 
		for (int i = 0; i < Size; i++)
		{
			Node* temp = tablepointer[i];
			if (tablepointer[i] == nullptr) {
				cout << "Null" << endl;
			}
			else {
				while (temp != nullptr && temp != NULL) {
					cout << temp->key << " : " << temp->value << " ";
					temp = temp->Next;
				}
				cout << endl;
			}
		}
	}

	//testing to see if it makes it through diffrent cases without producing an error
	bool Diagnostics() {
		try {
			HashTable<string,int> testtable(1);
			testtable.Insert("test", 1);
			if (testtable.Retrieve("test") != 1) {
				cout << "iserted incorrectly" << endl;
				return false;
			}
			testtable.Insert("test", 2);
			if (testtable.Retrieve("test") != 2) {
				cout << "iserted duplicate incorrectly" << endl;
				return false;
			}
			testtable.Retrieve("nottest");

		}
		catch (...) {
			cout << "Error occured" << endl;
			return false;
		}
		return true;
	}
private:
	//nested node class to store the key and value together
	class Node
	{
	public:
		Node(K k, V v) {
			key = k;
			value = v;
		}
		Node* Next = nullptr;
		K key;
		V value;
	};

	//the hash is only used inside the hashtable class
	int Hash(K key) {
		// hash % table size
		hash<K> hasher;
		return hasher(key) % Size;

	}

	//pointer to the array
	Node** tablepointer;
};