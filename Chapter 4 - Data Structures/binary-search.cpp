#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

void setVSUnorderedSet();
void mapStructure();
void iterators();
void sets();
void queuesAndStack();

int main() {

    setVSUnorderedSet();
    mapStructure();
    iterators();
    sets();
    queuesAndStack();

    return 0;
}

// NOTE: Multiset and Unordered multiset behave like set and UnorderedSet respectively but can contain duplicates
void setVSUnorderedSet() {

    // Set is oredered (asc) sequence of unique keys, implemented as Balanced Binary Tree and it's operations work in O(log n) time complexity
    // Set is more appropriate for applying binary search on its elements
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(4232);
    s.insert(6);

    cout << "\nSet: ";
    for(auto x : s) {
        cout << x << " ";
    }

    // Function count() checks if value is present in set
    s.count(4232) ? cout << "Value is present in a set" : cout << "Value is not present in a set\n";

    // Unordered set is unordered sequence of unique keys, implemented through hashes and it's operations work in O(1) time complexity, but it lacks some 
    // Insert, Search and Delete are operated in O(1) time complexity

    cout << "\nUnordered Set: ";
    unordered_set<int> us;
    us.insert(1);
    us.insert(3);
    us.insert(4232);
    us.insert(6);
    
    for(auto x : us) {
        cout << x << " ";
    }

    cout << "\n";
}


void mapStructure() {
    // Map in C++ is based on Balanced Binary Tree and accessing it's elements takes O(log n) time
    cout << "------------------\n";
    map<string, string> nations;
    nations["Serbia"] = "Belgrade";
    nations["Croatia"] = "Zagreb";
    nations["BiH"] = "Sarajevo";
    nations["Bulgaria"] = "Sofia";

    for(auto x : nations) {
        cout << x.first << ":" << x.second << endl;
    }

    // Function count() checks if key exists in a map
    cout << "------------------\n";
    nations.count("Serbiaa") ? cout << "Key exists \n" : cout << "Key does not exist \n";
    

    // Unordered_map is based on hashes and accessing it's elements takes O(1) time
    cout << "------------------\n";
    unordered_map<string, string> nations2;
    nations2["Netherlands"] = "Amsterdam";
    nations2["Denmark"] = "Copenhagen";
    nations2["France"] = "Paris";
    nations2["Italy"] = "Rome";

    for(auto x : nations2) {
        cout << x.first << ":" << x.second << endl;
    }

    nations2.erase("Italy");
}

void iterators() {
    // .begin() - Points to the first element in data structure
    // .end() - Points AFTER last element in data structure, thus range defined by iterator is half-open
    vector<int> v = {1, 404, 79, 14, 102, 46, 57, 68, 1, 25};
    cout << "Vector: ";

    for(auto x : v)
        cout << x << " ";

    cout << "\n------------------\n";

    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for(auto x : v)
        cout << x << " ";

    reverse(v.begin(), v.end());
    cout << "\n------------------\nReversed: ";
    for(auto x : v)
        cout << x << " ";

    random_shuffle(v.begin(), v.end());
    cout << "\n------------------\nRadnom Shuffle: ";
    for(auto x : v)
        cout << x << " ";
}

void sets() {
    // Iterators are used to point at elements in a set, for instance
    set<int> s = {2, 3, 5, 1, 0, -10, 50, 75};
    set<int>::iterator it = s.begin();
    
    cout << "\n" << *it << endl;

    // largest element in a set
    auto it2 = s.end();
    it2--;
    cout << "\n" << *it2 << endl;

    // Function find(X) returns an iterator that points to an element whose value is X
    // if value is not presend, iterator will have value .end()
    auto itFinder = s.find(50);
    cout << "\n" << *itFinder << endl;


    // Bitset - Set that contains either 0 or 1
    // Improves memory efficiency when manipulated using bit operators
    // Reads value from right to left. If non existing element is referenced, it returns 0 as default value 
    
    bitset<5> bs(string("01011"));
    cout << bs[0];
    cout << bs[1];
    cout << bs[2];
    cout << bs[3];
    cout << bs[4];

    bitset<5> a(string("01011"));
    bitset<5> b(string("11001"));

    cout << "\na AND b: " << (a&b) << endl;
    cout << "\na OR b: " << (a|b) << endl;
    cout << "\na XOR b: " << (a^b) << endl;
}

void queuesAndStack() {
    // Dequeue - Its size can be effiently changed at both ends
    // Unlike vector that supports only push_back() && pop_back()
    // Dequeue supports push_front() && pop_front()
    cout << "\n------------------" << endl;
    deque<int> d = {10, 11, 12, 13, 14, 15};
    d.push_front(9);
    d.push_front(8);
    d.push_front(7);

    d.pop_front();

    for(auto x : d)
        cout << x << " ";


    // Stack - O(1) time complexion
    // Can only access elements an it's top by either adding element or removing elment
    // LIFO structure
    cout << "\n------------------" << endl;

    stack<int> st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);

    cout << "\n" << st.top() << endl;
    st.pop(); 
    cout << st.top() << endl;

    // Queue - O(1) time complexion
    // Can only access first element by popping it and last element in queue by adding a new element
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop(); // pops 1
    q.push(6);

    cout << "\nFirst element in the queue: " << q.front() << endl;
    cout << "Last element in the queue: " << q.back() << endl;

    // Priority Queue: Maintains a set of elements. In C++ priority is implemented in descending order, meaning that biggest value will be highest priority
    // Inserting and removing element: O(log n)
    // Fetching elment: O(1)
    priority_queue<int> pq;
    pq.push(4);
    pq.push(7);
    pq.push(1);
    pq.push(2);
    pq.push(3);

    // pq contains values: {1, 2, 3, 4, 7} as of now
    pq.pop();

    // now 4 is highest priority
    pq.push(6);

    cout << "\nHighest priority: " << pq.top() << endl; // 6
} 
