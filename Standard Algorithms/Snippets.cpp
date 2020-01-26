// Hashing pairs

// If you're using unordered set and need to hash anything. Here is the example for a pair
// Only for pairs of std::hash-able types for simplicity.
// You can of course template this struct to allow other hash functions
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

---------------------------------------------------------------------------------------------------------------------------------

// If there's data you wanna frequetly wanna access, then use a vector! If you don't care about the order, use an unordered_map
// before you use a normal map. Maps can give you timeouts if you aren't careflul

---------------------------------------------------------------------------------------------------------------------------------

// Hashing strings - Rabin Karp rolling hash

---------------------------------------------------------------------------------------------------------------------------------

