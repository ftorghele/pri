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
		forward = new SkipNode* [level+1];
		for (int i=0; i<=level; i++) forward[i] = 0;
    }
    ~SkipNode() {
      delete [] forward;
    }

  private:
    int level;
    K key;
    V value;
    SkipNode** forward;
};

template<typename K, typename V>
class SkipList {
  public:
      SkipList(int _level) : level(_level) {
          root = new SkipNode(-1, level);
      }

      SkipNode search(K key) const;
      void insert(K key, V value);
      void deleteNode(K key);

  private:
      int randomLevel(int maxlevel);

      SkipNode<V>* root;
      int level;
};

#endif /* SKIPLIST_H_ */
