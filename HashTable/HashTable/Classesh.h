#pragma once
#include <string>
#include <iostream>

using namespace std;

template<typename K,typename V>
class HashTable {
public:
	HashTable() {}
	void Insert(K key, V value) {

	}
	V Retieve(K key) {

	}
	void Delete(K key) {

	}
	int Hash(K key) {
		//however im doin the hash % table size
	}
	void Display() {

	}
private:
	//dont really want to use a array of linked lists need to research how else to do it
	class Node {
		public:
			Node(K k, V v) {
				key = k;
				value = v;
			}

			K GetKey() { return key; }
			void SetKey(K k) { key = k; }

			V GetValue() { return value; }
			void SetValue(V v) { value = v; }
		private:
			K key;
			V value

	};
	Node Table[];
};