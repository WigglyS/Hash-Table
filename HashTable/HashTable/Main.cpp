#include "Classesh.h"

void main()
{
	HashTable<string,int> hashtable;

	
	int Quit = 0;

	do {
		
		int input;
		hashtable.Display();
		cout << "Press (1) to Add a Name and Number to Table" << endl;
		cout << "Press (2) to Remove A Entry From the Table" << endl;
		cout << "Press (3) to Run Diagnostics" << endl;
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
			case 2:{
				string RemoveKey;
				cout << "Enter a Number to Remove: ";
				cin >> RemoveKey;
				hashtable.Delete(RemoveKey);
				system("CLS");
			}
			
				break;
			case 3:
				system("CLS");
				//hashtable.Diagnostics();
				break;
			case 0:
				Quit = 1;
				break;
		}

	} while (Quit == 0);
	
}