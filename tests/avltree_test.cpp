#include "../my_avltree.hpp"
#include <iostream>
using namespace std;

int main() {
	MyAVLTree<int> tree;
	tree.add(50);
	tree.add(20);
	tree.add(70);
	tree.add(5);
	tree.add(30);
	tree.add(60);
	tree.add(80);
	tree.add(17);
	tree.add(29);
	tree.add(31);
	tree.add(75);
	tree.add(90);
	tree.add(3);
	tree.preorder();
	cout << "\n";
	tree.inorder();
	cout << "\n";
	tree.postorder();
	cout << "\n";

	//Find height of tree
	cout << "The height of the tree is " << tree.height() << "\n";

	//Remove a node with no children
	cout << "Removing 3\n";
	tree.remove(3);
	tree.inorder();
	cout << "\n";
	tree.add(3);

	//Remove a node with only left child
	cout << "Adding 55\n";
	tree.add(55);
	tree.inorder();
	cout << "\nRemoving 55\n";
	tree.remove(55);
	tree.inorder();
	cout << "\n";

	//Remove a node with only right child
	cout << "Adding 65\n";
	tree.add(65);
	tree.inorder();
	cout << "\nRemoving 65\n";
	tree.remove(65);
	tree.inorder();
	cout << "\n";

	//Remove a node with two children
	cout << "Removing 70\n";
	tree.remove(70);
	tree.inorder();
	cout << "\n";

	//Find root
	cout << "Finding 50\n";
	cout << "50 exists? ";
	cout << tree.exists(50);
	cout << "\n";
	
	//Find value on right side
	cout << "Finding 75\n";
	cout << "75 exists? ";
	cout << tree.exists(75);
	cout << "\n";
	
	//Find value on left side
	cout << "Finding 17\n";
	cout << "17 exists? ";
	cout << tree.exists(17);
	cout << "\n";
	
	//Find non existant value
	cout << "Finding 100\n";
	cout << "100 exists? ";
	cout << tree.exists(100);
	cout << "\n";

	//Clear all nodes
	cout << "Removing all nodes\n";
	tree.clear();
	tree.inorder();
}
