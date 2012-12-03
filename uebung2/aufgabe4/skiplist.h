/*
 * skiplist.h
 *
 *  Created on: Nov 21, 2012
 *      Author: torghele
 */

#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include <iostream>
#include <stdlib.h>

template<typename K, typename V>
class SkipNode {
  public:
    SkipNode(K _key, V _value, int _level) : level(_level), key(_key), value(_value) {
		next = new SkipNode* [level+1];
		for (int i=0; i<=level; i++) next[i] = 0;
    }
    ~SkipNode() {
      delete [] next;
    }

  private:
    int level;
    K key;
    V value;
    SkipNode** next;
};

template<typename K, typename V>
class SkipList {
  public:
      SkipList(int _level) : level(_level) {
          root = new SkipNode<K,V>(0, 0, level);
      }

      SkipNode search(K key) const;
      void insert(K key, V value);
      void deleteNode(K key);

  private:
      int randomLevel(int maxlevel);

      SkipNode<K,V>* root;
      int level;
};

#endif /* SKIPLIST_H_ */
