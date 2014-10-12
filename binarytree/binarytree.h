#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <stdexcept>

namespace restonce{
	template <class T>
	class BinaryTree{
	public :
		// constructor
		BinaryTree() ;			// construct a empty tree
		BinaryTree(const BinaryTree&);	// clone a exist tree
		BinaryTree(BinaryTree&& );	// move a tree to build self
		// destruct
		~BinaryTree() noexcept;
		void clear() noexcept;
		// operator =
		BinaryTree& operator= (const BinaryTree& ) noexcept;
		BinaryTree& operator= (BinaryTree&& ) noexcept;
		// read from istream
		void readFrom( std::istream&,const T& endFlag) ;
		// judge empty 
		bool empty() const noexcept;
		bool leftEmpty() const noexcept;
		bool rightEmpty() const noexcept;
		// get inner data at root node
		//  if empty , throw a runtime_error exception
		T& data() throw( std::runtime_error ) ;
	const   T& data() const throw( std::runtime_error );
		// clone function
		// if self is empty , throw a exception
		// if clone dest is empty , return an empty BinaryTree
		BinaryTree cloneLeftSubTree()  const throw( std::runtime_error );
		BinaryTree cloneRightSubTree() const throw( std::runtime_error );
		// reference of this tree
		// if self is empty or refrence dest is empty ,
		// 	throw a runtime_error
		BinaryTree& refrenceLeftSubTree() throw( std::runtime_error );
	const	BinaryTree& refrenceLeftSubTree() const throw( std::runtime_error );
		BinaryTree& refrenceRightSubTree() throw( std::runtime_error );
	const	BinaryTree& refrenceRightSubTree() const throw( std::runtime_error );
		// traverse
		// bool fun(T&) or bool fun(const T&) 
		template<class TraverseFunction>
		bool preTraverse(TraverseFunction fun) ;
		template<class TraverseFunction>
		bool preTraverse(TraverseFunction fun) const;
		template<class TraverseFunction>
		bool midTraverse(TraverseFunction fun) ;
		template<class TraverseFunction>
		bool midTraverse(TraverseFunction fun) const;
		template<class TraverseFunction>
		bool aftTraverse(TraverseFunction fun) ;
		template<class TraverseFunction>
		bool aftTraverse(TraverseFunction fun) const;
	private :
		T* _data;
		BinaryTree* left;
		BinaryTree* right;
	};
}

#include "binarytree.hpp"

#endif // _BINARYTREE_H_
