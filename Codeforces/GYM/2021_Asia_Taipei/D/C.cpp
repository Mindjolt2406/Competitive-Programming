// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

// 18:33

typedef struct Event {
    int time_id;
    string name;
    int type; // Query
    bool isStart;
} Event;

bool eventComparator(const Event &event1, const Event &event2) {
    return event1.time_id < event2.time_id;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<Event>> events(n);
    vector<bool> isTaken(q + 1);

    vector<int> queryEventIds;
    vector<string> ans(q + 1);
    vector<Event> eventMapper(q + 1);
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        string name;
        if (type == 1) {
            cin >> name;
        } else {
            queryEventIds.push_back(i + 1);
        }

        int l, r;
        cin >> l >> r;
        events[l].push_back({i + 1, name, type, true});
        events[r].push_back({i + 1, name, type, false});
        eventMapper[i + 1] = {i + 1, name, type, true};
    }

    set<int> setNames, setQueries;
    for (int i = 0; i < n; ++i) {
        vector<Event> currNameEvents;
        vector<Event> currQueryEvents;

        for (auto event : events[i]) {
            // Add events to sets.
            // Iterate through events to get answers
                // Each new query -> check in name set and vice versa
                // Once spotted, erase both and marked both as isTaken
            if (event.isStart) {
                if (event.type == 1) {
                    setNames.insert(event.time_id);
                    currNameEvents.push_back(event);
                } else { 
                    setQueries.insert(event.time_id);
                    currQueryEvents.push_back(event);
                }
            }
        }

        sort(currNameEvents.begin(), currNameEvents.end(), eventComparator);
        reverse(currNameEvents.begin(), currNameEvents.end());
        sort(currQueryEvents.begin(), currQueryEvents.end(), eventComparator);

        for (auto event : currNameEvents) {
            // Take the next query event if any and GTFO.
            auto it = setQueries.upper_bound(event.time_id);
            if (it != setQueries.end()) {
                Event queryEvent = eventMapper[*it];
                setNames.erase(event.time_id);
                setQueries.erase(it);
                t("answer", queryEvent.time_id, event.name);
                ans[queryEvent.time_id] = event.name;
            }
        }

        for (auto event : currQueryEvents) {
            // Take the previous query event if any or GTFO.
            auto it = setNames.upper_bound(event.time_id);
            if (it != setNames.begin()) {
                it--;
                Event nameEvent = eventMapper[*it];
                setQueries.erase(event.time_id);
                setNames.erase(it);
                t("answer", event.time_id, nameEvent.name);
                ans[event.time_id] = nameEvent.name;
            }
        }

        // Clean up ending events.
        for (auto event : events[i]) {
            if (!event.isStart) {
                if (event.type == 1) {
                    if (setNames.count(event.time_id))
                        setNames.erase(event.time_id);
                } else {
                    if (setQueries.count(event.time_id)) {
                        setQueries.erase(event.time_id);
                        ans[event.time_id] = ">_<";
                    }
                }
            }
        }
    }

    t(queryEventIds);
    for (auto id : queryEventIds) {
        cout << ans[id] << endl;
    }
}

int main() {
    __;
    solve();
    return 0;
}

/*
12 10
1 Jessica 5 10
1 Sara 4 7
1 Peter 7 9
2 3 5
2 3 7
1 Olivia 4 6
2 1 3
2 8 8
2 8 9
2 3 11

*/