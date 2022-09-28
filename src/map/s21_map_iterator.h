#ifndef SRC_S21_MAP_ITERATOR_H
#define SRC_S21_MAP_ITERATOR_H

#include <utility>

template<typename Key, typename T>
class Node {
    public:
        Node* parent;
        Node* left;
        Node* right;
        std::pair<const Key, T> data;

        void add(Node *&obj, std::pair<const Key, T> data) {
            if (obj == NULL) {
                obj = new Node;
                obj->data = data;
            }
            else if (obj->data.first < data) {
                add(obj->right, data);
            }
            else if (obj->data.first > data) {
                add(obj->left, data);
            }
        }
 
        void CopyTree(Node *p, Node *copy) {
            if (p == NULL) {
                copy = NULL;
                return;
            }
            copy->data = p->data;
            CopyTree(p->left, (copy->left));
            CopyTree(p->right, (copy->right));
        }

        int sizeT(Node *tree, int count = 0) {
            if (tree == NULL)
                return count;
            count++;
            count = sizeT(tree->left, count);
            count = sizeT(tree->right, count);
            return count;
        }
};

template<typename Key, typename T>
class MapIterator {
    private:
        Node<Key, T> next;

    public:
        MapIterator(Node<Key, T> root) {
            next = root;
            if(next == null)
                return;

            while (next.left != null)
            next = next.left;
        }

        boolean hasNext(){
            return next != null;
        }

        Node<Key, T> next(){
            if(!hasNext()) throw new NoSuchElementException();
            Node<Key, T> r = next;

            // If you can walk right, walk right, then fully left.
            // otherwise, walk up until you come from left.
            if(next.right != nullptr) {
                next = next.right;
                while (next.left != nullptr)
                    next = next.left;
                return r;
            }

            while(true) {
                if(next.parent == nullptr) {
                    next = nullptr;
                    return r;
                }
                if(next.left == next) {
                    next = next.parent;
                return r;
                }
                next = next.parent;
            }
        }
};



#endif //  SRC_S21_MAP_ITERATOR_H