#ifndef _BINARYTREE_HPP_
#define _BINARYTREE_HPP_

#include "binarytree.h"

template <class T>
restonce::BinaryTree<T>::BinaryTree() 
	: _data(nullptr), left(nullptr), right(nullptr) { }

template <class T>
restonce::BinaryTree<T>::BinaryTree(const BinaryTree& rhs) : BinaryTree() {
	if ( !rhs.empty() ) {
		_data = new T(*rhs._data);
		if ( !rhs.leftEmpty() ) {
			left = new BinaryTree( *(rhs.left) );
		}
		if ( !rhs.rightEmpty() ) {
			right = new BinaryTree( *(rhs.right) );
		}
	}
}

template <class T>
restonce::BinaryTree<T>::BinaryTree(BinaryTree&& rhs) : BinaryTree(){
	_data = rhs._data;
	left  = rhs.left;
	right = rhs.right;
	rhs._data = nullptr;
	rhs.left = nullptr;
	rhs.right = nullptr;
}

template <class T>
restonce::BinaryTree<T>::~BinaryTree() noexcept{
	clear();
}

template <class T>
void restonce::BinaryTree<T>::clear() noexcept{
	delete _data;
	delete left;
	delete right;

	_data = nullptr;
	left  = nullptr;
	right = nullptr;
}

template <class T>
restonce::BinaryTree<T>& restonce::BinaryTree<T>::operator=(const BinaryTree& rhs) noexcept{
	if ( this != &rhs) {
		this -> clear();
		_data = new T( *(rhs._data) );
		left  = new BinaryTree<T>( rhs.cloneLeftSubTree()  );
		right = new BinaryTree<T>( rhs.cloneRightSubTree() );
	}
	return *this;
}
template <class T>
restonce::BinaryTree<T>& restonce::BinaryTree<T>::operator=(BinaryTree&& rhs) noexcept{
	if ( this != &rhs) {
		this->clear();
		_data = rhs._data;
		left  = rhs.left;
		right = rhs.right;

		rhs._data = nullptr;
		rhs.left  = nullptr;
		rhs.right = nullptr;
	}
	return *this;
}

template <class T>
void restonce::BinaryTree<T>::readFrom(std::istream& in, const T& endFlag) {
	if ( in ) {
		clear();
		T input ;

		in >> input;
		if (in && input!=endFlag) {
			_data = new T(input);
			left = new BinaryTree();
			left->readFrom(in, endFlag);
			right = new BinaryTree();
			right->readFrom(in, endFlag);
		}
	}
}

template <class T>
bool restonce::BinaryTree<T>::empty() const noexcept{
	return _data == nullptr;
}

template <class T>
bool restonce::BinaryTree<T>::leftEmpty() const noexcept{
	return left==nullptr || left->empty();
}
template <class T>
bool restonce::BinaryTree<T>::rightEmpty() const noexcept{
	return right==nullptr || right->empty();
}

template <class T>
T& restonce::BinaryTree<T>::data() throw( std::runtime_error ) {
	if ( empty() ) {
		throw std::runtime_error("Empty binary tree !");
	}
	return *_data;
}
template <class T>
const T& restonce::BinaryTree<T>::data() const throw( std::runtime_error ) {
	if ( empty() ) {
		throw std::runtime_error("Empty binary tree !");
	}
	return *_data;
}

template<class T>
restonce::BinaryTree<T> restonce::BinaryTree<T>::cloneLeftSubTree() const throw( std::runtime_error ) {
	if ( empty() ) {
		throw std::runtime_error("Self binary tree is empty !");
	}
	if ( leftEmpty() ) {
		return BinaryTree();
	}
	return BinaryTree( *left );
}

template<class T>
restonce::BinaryTree<T> restonce::BinaryTree<T>::cloneRightSubTree() const throw( std::runtime_error ) {
	if ( empty() ) {
		throw std::runtime_error("Self binary tree is empty !");
	}
	if ( rightEmpty() ) {
		return BinaryTree();
	}
	return BinaryTree( *right );
}
// reference of this tree
// if self is empty or refrence dest is empty ,
// 	throw a runtime_error
/*	BinaryTree& refrenceLeftSubTree() throw( std::runtime_error );
const	BinaryTree& refrenceLeftSubTree() const throw( std::runtime_error );
	BinaryTree& refrenceRightSubTree() throw( std::runtime_error );
const	BinaryTree& refrenceRightSubTree() const throw( std::runtime_error );
*/
template <class T>
restonce::BinaryTree<T>& restonce::BinaryTree<T>::refrenceLeftSubTree() throw( std::runtime_error ) {
	if (empty() ) {
		throw std::runtime_error("Self binary tree is empty !");
	}
	if ( leftEmpty() ) {
		throw std::runtime_error("Reference left tree is empty !");
	}
	return *left;
}

template <class T>
const restonce::BinaryTree<T>& restonce::BinaryTree<T>::refrenceLeftSubTree() const throw( std::runtime_error ) {
	if (empty() ) {
		throw std::runtime_error("Self binary tree is empty !");
	}
	if ( leftEmpty() ) {
		throw std::runtime_error("Reference left tree is empty !");
	}
	return *left;
}
template <class T>
restonce::BinaryTree<T>& restonce::BinaryTree<T>::refrenceRightSubTree() throw( std::runtime_error ) {
	if (empty() ) {
		throw std::runtime_error("Self binary tree is empty !");
	}
	if ( rightEmpty() ) {
		throw std::runtime_error("Reference right tree is empty !");
	}
	return *right;
}
template <class T>
const restonce::BinaryTree<T>& restonce::BinaryTree<T>::refrenceRightSubTree() const throw( std::runtime_error ) {
	if (empty() ) {
		throw std::runtime_error("Self binary tree is empty !");
	}
	if ( rightEmpty() ) {
		throw std::runtime_error("Reference right tree is empty !");
	}
	return *right;
}
/*
 *
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
 * */

template<class T>
template <class TraverseFunction>
bool restonce::BinaryTree<T>::preTraverse(TraverseFunction fun) {
	
	if ( empty() == false) {
		if ( fun(*_data) == false) {
			return false;
		}

		if (leftEmpty() ==false ) {
			if ( left->preTraverse(fun) == false) {
				return false;
			}
		}
		if (rightEmpty() ==false ) {
			if ( right->preTraverse(fun) == false) {
				return false;
			}
		}
	}

	return true;
}

template<class T>
template <class TraverseFunction>
bool restonce::BinaryTree<T>::preTraverse(TraverseFunction fun) const {
	
	if ( empty() == false) {
		if ( fun(*_data) == false) {
			return false;
		}

		if (leftEmpty() ==false ) {
			if ( left->preTraverse(fun) == false) {
				return false;
			}
		}
		if (rightEmpty() ==false ) {
			if ( right->preTraverse(fun) == false) {
				return false;
			}
		}
	}

	return true;
}


template<class T>
template <class TraverseFunction>
bool restonce::BinaryTree<T>::midTraverse(TraverseFunction fun) {
	
	if ( empty() == false) {

		if (leftEmpty() ==false ) {
			if ( left->midTraverse(fun) == false) {
				return false;
			}
		}
		if ( fun(*_data) == false) {
			return false;
		}

		if (rightEmpty() ==false ) {
			if ( right->midTraverse(fun) == false) {
				return false;
			}
		}
	}

	return true;
}

template<class T>
template <class TraverseFunction>
bool restonce::BinaryTree<T>::midTraverse(TraverseFunction fun) const {
	
	if ( empty() == false) {

		if (leftEmpty() ==false ) {
			if ( left->midTraverse(fun) == false) {
				return false;
			}
		}
		if ( fun(*_data) == false) {
			return false;
		}

		if (rightEmpty() ==false ) {
			if ( right->midTraverse(fun) == false) {
				return false;
			}
		}
	}

	return true;
}

template<class T>
template <class TraverseFunction>
bool restonce::BinaryTree<T>::aftTraverse(TraverseFunction fun) {
	
	if ( empty() == false) {

		if (leftEmpty() ==false ) {
			if ( left->aftTraverse(fun) == false) {
				return false;
			}
		}

		if (rightEmpty() ==false ) {
			if ( right->aftTraverse(fun) == false) {
				return false;
			}
		}
		if ( fun(*_data) == false) {
			return false;
		}
	}

	return true;
}
template<class T>
template <class TraverseFunction>
bool restonce::BinaryTree<T>::aftTraverse(TraverseFunction fun) const {
	
	if ( empty() == false) {

		if (leftEmpty() ==false ) {
			if ( left->preTraverse(fun) == false) {
				return false;
			}
		}

		if (rightEmpty() ==false ) {
			if ( right->preTraverse(fun) == false) {
				return false;
			}
		}
		if ( fun(*_data) == false) {
			return false;
		}
	}

	return true;
}


#endif
