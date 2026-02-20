#ifndef HASH_MAP_H
#define HASH_MAP_H
#define HASH_CODE_MAX 10000
#include <string>

#include "list.h"

namespace mystl {

    int hash(std::string key) {
        int code = 0;
        for (const char &c : key) {
            code += static_cast<int>((c - 'a') + 1);
        }
        return code % HASH_CODE_MAX;
    }

    template<typename K, typename V>
    struct pair {
        K key;
        V value;
    };

    template<typename K, typename V>
    class hash_map {
    private:
        using bucket = list<pair<K, V>>;
        bucket *buckets;
        size_t _size;
    public:
        explicit hash_map() {
            // 用用智能指针
            buckets = std::make_unique<bucket[]>(HASH_CODE_MAX);
        }

        ~hash_map() = default;

        void put(K key, V value) {
            pair<K, V> p(key, value);
            int hash_code = hash(key);
            buckets[hash_code].push_back(p);
        }

        bool contains(K key) {
            return buckets[hash(key)].size() > 0;
        }

        void remove(K key) {
            if (contains(key)) {
                if (buckets[hash(key)].size() > 1) {
                    buckets[hash(key)].remove(key);
                } else {
                    buckets[hash(key)].pop_back();
                }
            }
        }

        void find(K key) {

        }

        void clear() {

        }

        void size() {

        }

    };
}

#endif //HASH_MAP_H
