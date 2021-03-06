#ifndef __MY_BS_TREE__
	#define __MY_BS_TREE__

	#include "my_node.hpp"
	template <typename T>
	class MyBSTree {
		private:
			MyNode<T>* root_;

			void				delete_node(MyNode<T>*, MyNode<T>*, MyNode<T>*, bool = false);
			void				add_node(MyNode<T>*, MyNode<T>*);
			void				add_helper(T, MyNode<T>*);
			void				remove_helper(T, MyNode<T>*, MyNode<T>*);
			int					height_helper(MyNode<T>*);
			void				dfs_helper(MyNode<T>*);
			void				bfs_helper(MyNode<T>*);
			
		public:
			MyBSTree();
			~MyBSTree();
			void 	add(T);
			void 	remove(T);
			void	preorder(MyNode<T>* = NULL);
			void 	inorder(MyNode<T>* = NULL);
			void 	postorder(MyNode<T>* = NULL);
			void 	clear(MyNode<T>*  = NULL);
			bool 	exists(T, MyNode<T>* = NULL);
			int  	height();
			void	dfs();
			void 	bfs();
	};

	/////////////////////////////////
	template <typename T>
	void MyBSTree<T>::delete_node(MyNode<T>* node, MyNode<T>* prev_node, MyNode<T>* new_val, bool move_node) {
		MyNode<T>* temp;
		if(node == root_)
			root_ = new_val;
		else {
			//Set left side of parent to new child
			if(prev_node->getLeft() && prev_node->getLeft()->getData() == node->getData()) 
				prev_node->setLeft(new_val);

			//Set right side of parent to new child
			else if(prev_node->getRight() && prev_node->getRight()->getData() == node->getData()) 
				prev_node->setRight(new_val);
		}
		if(move_node) {
			temp = new_val->getRight();
			new_val->setRight(node->getRight());
			add_node(new_val, temp);
		}
		delete node;
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyBSTree<T>::add_node(MyNode<T>* parent, MyNode<T>* new_node) {
		if(parent && new_node) {
			//Left side
			if(new_node->getData() <= parent->getData()) {
				if(parent->getLeft())
					add_node(parent->getLeft(), new_node);
				else
					parent->setLeft(new_node);
			}
			//Right side
			else {
				if(parent->getRight())
					add_node(parent->getRight(), new_node);
				else
					parent->setRight(new_node);
			}
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template<typename T>
	void MyBSTree<T>::add_helper(T elem, MyNode<T>* pos) {

		if(root_ == NULL)
			root_ = new MyNode<T>(elem, NULL, NULL);
		else {

			//Left Branch
			if(elem <= pos->getData()) {
				//If left is null add
				if(pos->getLeft() == NULL) 
					pos->setLeft(new MyNode<T>(elem, NULL, NULL));
				//Keep Searching if not null
				else
					add_helper(elem, pos->getLeft());
			}

			//Right Branch
			else {
				//If right is null add
				if(pos->getRight() == NULL) 
					pos->setRight(new MyNode<T>(elem, NULL, NULL));
				//Keep Searching if not null
				else
					add_helper(elem, pos->getRight());	
			}
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template<typename T>
	void MyBSTree<T>::remove_helper(T elem, MyNode<T>* node, MyNode<T>* prev_node) {
		if(!node)
			return;
		
		//Found matching node
		if(node->getData() == elem) {
			//Has left and right children
			if(node->getLeft() && node->getRight()) 
				delete_node(node, prev_node, node->getLeft(), true);
			//Has left child
			else if(node->getLeft() && !node->getRight()) 
				delete_node(node, prev_node, node->getLeft());
			//Has right child
			else if(node->getRight() && !node->getLeft()) 
				delete_node(node, prev_node, node->getRight());
			//Has no children
			else if(!node->getRight() && !node->getLeft()) {
				delete_node(node, prev_node, NULL);
			}
		}
		else {
			if(elem <= node->getData())
				remove_helper(elem, node->getLeft(), node);
			if(elem > node->getData())
				remove_helper(elem, node->getRight(), node);
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	int MyBSTree<T>::height_helper(MyNode<T>* node) {
		if(node == NULL)
			return 0;
		else {
			int left = height_helper(node->getLeft());
			int right = height_helper(node->getRight());

			if(left >= right)
				return left + 1;
			else
				return right + 1;
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	MyBSTree<T>::MyBSTree() {
		root_ = NULL;
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	MyBSTree<T>::~MyBSTree() {
			clear();
	}
	/////////////////////////////////

	/////////////////////////////////
	using namespace std;
	#include <iostream>
	template <typename T>
	void MyBSTree<T>::add(T elem) {
		add_helper(elem, root_);
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	void MyBSTree<T>::remove(T elem) {
		remove_helper(elem, root_, NULL);
	}
	/////////////////////////////////
	
	/////////////////////////////////
	#include <iostream>
	template <typename T>
	void MyBSTree<T>::preorder(MyNode<T>* node) {
		if(root_) {
			if(!node)
				node = root_;
			
			std::cout << node->getData() << " ";	
			
			if(node->getLeft())
				preorder(node->getLeft());
			
			if(node->getRight())
				preorder(node->getRight());
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	#include <iostream>
	template <typename T>
	void MyBSTree<T>::inorder(MyNode<T>* node) {
		if(root_) {
			if(!node)
				node = root_;
			
			if(node->getLeft())
				inorder(node->getLeft());
				
			std::cout << node->getData() << " ";	
			
			if(node->getRight())
				inorder(node->getRight());
		}
	}
	/////////////////////////////////

	/////////////////////////////////
	#include <iostream>
	template <typename T>
	void MyBSTree<T>::postorder(MyNode<T>* node) {
		if(root_) {
			if(!node)
				node = root_;
			
			if(node->getLeft())
				postorder(node->getLeft());
			
			if(node->getRight())
				postorder(node->getRight());
			
			std::cout << node->getData() << " ";	
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyBSTree<T>::clear(MyNode<T>* node) {
		MyNode<T>* left;
		MyNode<T>* right;

		if(node == NULL)
			node = root_;

		if(node) {
			left = node->getLeft();
			right = node->getRight();
			if(left)
				clear(left);
			if(right)
				clear(right);
			if(node == root_)
				root_ = NULL;
			delete node;
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	bool MyBSTree<T>::exists(T elem, MyNode<T>* node) {
		if(!node)
			node = root_;

		if(node) {
			MyNode<T>* left = node->getLeft();
			MyNode<T>* right = node->getRight();

			if(node->getData() == elem)
				return true;
			else {
				if((left && exists(elem, left)) || (right && exists(elem, right)))
					return true;
			}
		}
		return false;
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	int MyBSTree<T>::height() {
		return height_helper(root_);
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyBSTree<T>::dfs() {
		dfs_helper(root_);
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyBSTree<T>::bfs() {
		bfs_helper(root_);
	}
	/////////////////////////////////
#endif
