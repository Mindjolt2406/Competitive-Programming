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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


---------------------------------------------------------------------------------------------------------------------------------

// If there's data you wanna frequetly wanna access, then use a vector! If you don't care about the order, use an unordered_map
// before you use a normal map. Maps can give you timeouts if you aren't careflul

---------------------------------------------------------------------------------------------------------------------------------

// Hashing strings - Rabin Karp rolling hash

---------------------------------------------------------------------------------------------------------------------------------
// Nice random stuff
// How would you add the sequence 1,2,3, ... , n at some index i of some array? i.e. arr[i] += 1; arr[i+1] += 2 ; .... ;
// Use a BIT!
// Here's the code

void increasing(int n, int i,  BIT &bit)
{
  bit.inc(i,1);
  bit.inc(n+i,-1);
  bit.inc(n+i,-n);
  bit.inc(n+1+i,n);
}

void remove_increasing(int n,int i, BIT &bit)
{
  bit.inc(i,-1);
  bit.inc(n+i,1);
  bit.inc(n+i,n);
  bit.inc(n+1+i,-n);
}

void decreasing(int n,int i,BIT &bit)
{
  bit.inc(i,n);
  bit.inc(i+1,-n);
  bit.inc(i+1,-1);
  bit.inc(n+i+1,1);
}

void remove_decreasing(int n,int i,BIT &bit)
{
  bit.inc(i,-n);
  bit.inc(i+1,n);
  bit.inc(i+1,1);
  bit.inc(n+i+1,-1);
}

// ----------------------------------------------------------------------------------------------
