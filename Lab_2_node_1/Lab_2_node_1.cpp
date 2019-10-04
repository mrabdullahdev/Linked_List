// this function is for the manipulation
// of the linked list

#include <iostream>
#include "List.h"	// List class file added
#include "Node.h"	// node class file added

using namespace std;



int main()	// Main function started********************************************************************
{
	List myLinkList;	// Creating object of class List
	// Inserting 5 Nodes to the List
	myLinkList.insert(10);
	myLinkList.insert(36);
	myLinkList.insert(96);
	myLinkList.insert(250);
	myLinkList.insert(58);
	// Displaying List after Inserting 5 Nodes
	cout << "\nDisplaying List after adding 5 Nodes:\n";
	myLinkList.displayList();

	// Inserting Node in the beginning
	myLinkList.insertAtBegin(5);
	// Displaying List after Inserting Node in the beginning
	cout << "\nDisplaying List after adding Node in the beginning:\n";
	myLinkList.displayList();

	// Inserting Node at specific index
	myLinkList.insertTo(12, 2);
	// Displaying List after inserting Node at specific index
	cout << "\nDisplaying List after inserting Node at 2nd index:\n";
	myLinkList.displayList();

	// Inserting Node at the end
	myLinkList.insertAtEnd(20);
	// Displaying List after Inserting Node at the end
	cout << "\nDisplaying List after Inserting Node at the end:\n";
	myLinkList.displayList();

	// Deleting specific Node from the List
	if (myLinkList.deleteNode(12))
	{
		// Displaying List after Deleting Node having value of 12 from the List
		cout << "\nDisplaying List after Deleting Node having value of 12 from the List:\n";
		myLinkList.displayList();
	}
	else
	{
		cout << "\nThe Node is previously not present in the List.\n";
	}

	// Deleting Node with specific index from the List
	if (myLinkList.deleteIndex(3))
	{
		// Displaying List after Deleting 3rd Node from the List
		cout << "\nDisplaying List after Deleting 2rd Node from the List:\n";
		myLinkList.displayList();
	}
	else
	{
		cout << "\nIndex is out of bound.\n";
	}
	
	// Updating specific Node from the List
	if (myLinkList.updateValue(250, 44))
	{
		// Displaying List after updating specific Node from 250 to 44
		cout << "\nDisplaying List after updating Node from 250 to 44:\n";
		myLinkList.displayList();
	}
	else
	{
		cout << "\nValue you entered does not match with the Nodes in the List.\n";
	}

	// Updating specific Index from the List
	if (myLinkList.updateIndex(67, 4))
	{
		// Displaying List after updating 4th Node from the List
		cout << "\nDisplaying List after updating 4th Node from the List:\n";
		myLinkList.displayList();
	}
	else
	{
		cout << "\nIndex is out of bound.\n";
	}

	// Searching value from the List
	cout << "\nChecking if 67 is present in the List.";
	if(myLinkList.searchValue(67))
	{
		cout << "\nGiven value is present in the List.\n";
	}
	else
	{
		cout << "\nGiven value is not present in the List.\n";
	}

	// Manipulating Current Node ***************************

	// Displaying Current Node
	cout << "Displaying current Node;\n";
	cout << myLinkList.get() << endl;

	// Moving current Node to the start
	myLinkList.start();
	cout << "\nAfter Moving current Node to the start:\n";
	cout << myLinkList.get() << endl;

	// Moving current Node
	myLinkList.move();
	cout << "\nAfter Moving current Node:\n";
	cout << myLinkList.get() << endl;
	//******************************************************

	// Inserting Node after a certain Node
	cout << "\nInserting Node with value 70 after Node with value 58.\n";
	myLinkList.insertAfter(70, 58);
	cout << "\nDisplaying List after adding new Node.\n";
	myLinkList.displayList();
	// Displaying total Number of Nodes
	cout << "\nDisplaying total Number of Nodes:\n";
	cout << myLinkList.getSize() << endl;

	// Adding Nodes of the List
	cout << "\nDisplaying sum of the Nodes of the List.\n";
	cout << myLinkList.sumOfNodesofList() << endl;



	return 0;
}	// Main function Ended ******************************************************************************
