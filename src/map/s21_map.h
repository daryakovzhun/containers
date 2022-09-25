#ifndef SRC_S21_MAP_H
#define SRC_S21_MAP_H

template<typename Key, typename T>
class s21_map {
    public:
        map();
        map(std::initializer_list<value_type> const &items);
        map(const map &m);
        map(map &&m);
        ~map();
        operator=(map &&m);

        T& at(const Key& key);
        T& operator[](const Key& key);

        iterator begin();
        iterator end();

        bool empty();
        size_type size();
        size_type max_size();

        void clear();
        std::pair<iterator, bool> insert(const value_type& value);
        std::pair<iterator, bool> insert(const Key& key, const T& obj);
        std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);;
        void erase(iterator pos);
        void swap(map& other);
        void merge(map& other);

        bool contains(const Key& key);

    private:
        Key key_type;
        T  mapped_type;
        std::pair<const key_type,mapped_type> value_type;
        value_type& reference;
        const value_type& const_reference;
        MapIterator<Key, T> iterator;
        MapConstIterator<Key, T> const_iterator;
        size_t size_type;
};

#endif //  SRC_S21_MAP_H
