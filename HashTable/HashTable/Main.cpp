#include "Classesh.h"

void main()
{
	HashTable<string,int> hashtable(5);

	
	int Quit = 0;

	do {
		
		int input;
		hashtable.Display();
		cout << "Press (1) to Add a Name and Number to Table" << endl;
		cout << "Press (2) to Run Diagnostics" << endl;
		cout << "Press (3) to Retrive a value" << endl;
		cout << "Press (0) to Quit" << endl;
		cin >> input;

		switch (input)
		{
			case 1: {
				int AddNum;
				string AddName;
				cout << "Enter a Name to Add: ";
				cin >> AddName;
				cout << "Enter a Number to Add: ";
				cin >> AddNum;
				hashtable.Insert(AddName, AddNum);
				system("CLS");
			}
				break;
			case 2:
				system("CLS");
				if (!hashtable.Diagnostics()) {

					cout <<"test Failed" << endl;
				}
				else {
					cout << "test succeded" << endl;
				}
					
				system("pause");
				system("CLS");
				break;
			case 3: {
				string key;
				cout << "Enter a key to retrieve from: ";
				cin >> key;
				int returntest = hashtable.Retrieve(key);
				cout << key << " :" << returntest  << endl;
				system("pause");
				system("CLS");

			}
				break;
			case 0: {
				Quit = 1;	
			}	
				break;

			default: {

			}
				break;
		}
	} while (Quit == 0);
}