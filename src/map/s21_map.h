#ifndef SRC_S21_MAP_H
#define SRC_S21_MAP_H



template<typename Key, typename T>
class S21Map {
    public:
        S21Map();
        S21Map(std::initializer_list<value_type> const &items);
        S21Map(const S21Map &m);
        S21Map(S21Map &&m);
        ~S21Map();
        operator=(S21Map &&m);

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
        void swap(S21Map& other);
        void merge(S21Map& other);

        bool contains(const Key& key);

    private:
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const key_type, mapped_type>;
        using reference = value_type&;
        using const_reference = const value_type&;
        using iterator = MapIterator<Key, T>;
        using const_iterator = MapConstIterator<Key, T>;
        using size_type = size_t;

        // key_type key;
        // mapped_type mapped;

        mapped_type& operator[key_type&];
};

#endif //  SRC_S21_MAP_H