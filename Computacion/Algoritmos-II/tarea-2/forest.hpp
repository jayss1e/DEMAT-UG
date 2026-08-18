#include <string>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Tree {
    private:
    
    const int id;
    const int h;
    const int price;
    const string type;

    public:

    Tree (int id, int h, int price, string type) : id(id), h(h), type(type), price(price) { }

    const int get_id() { return id; }
    const int get_h() { return h; }
    const int get_price() { return price; }
    const string get_type() { return type; }

    int medlars (int k) const {
        return max(0, h - k);
    }

    int coins (int k) const {
        return medlars(k)*price;
    }
};

class Forest {
    private:

    int n = 0;
    int types_cnt = 0;
    set<string> types;
    unordered_map<string, vector<Tree>> trees;
    unordered_map<string, int> type_n;

    public:

    int get_size() { return n; }

    void insert(Tree t) {
        n++;

        if (types.find(t.get_type()) == end(types)) {
            types_cnt++;
            types.insert(t.get_type());
        }

        trees[t.get_type()].push_back(t);
        type_n[t.get_type()]++;
    }

    int quote (int k) {
        if (k == -1)
            return (1 << 30);
        
        int sum = 0;
        for (const pair<string, vector<Tree>> &v : trees) {
            for (const Tree &t : v.second)
                sum += t.coins(k);
        }
        return sum;
    }
    int quote (int k, string s) {
        if (k == -1)
            return (1 << 30);

        if (types.find(s) == end(types))
            return 0u;

        int sum = 0u;
        for (const Tree &t : trees[s])
            sum += t.coins(k);
        return sum;
    }

    int max_height(int t) {
        int l = -1, r = (1 << 30);

        while (l < r) {
            int m = (l+r)>>1;
            
            if (quote(m) >= t)
                l = m+1;
            else r = m;
        }

        return l-1;
    }

    int max_height(int t, string s) {
        int l = -1, r = (1 << 30);

        while (l < r) {
            int m = (l+r)>>1;
            
            if (quote(m, s) >= t)
                l = m+1;
            else r = m;
        }

        return l-1;
    }

    string type_mode() {
        string ans = ""; int ans_cnt = 0;

        for (const pair<string, int> &it : type_n) {
            if (
                it.second > ans_cnt ||
                (it.second == ans_cnt && it.first > ans)
            ) {
                ans = it.first;
                ans_cnt = it.second;
            }
        }

        return ans;
    }

    string lex_smallest_type () {
        return *begin(types);
    }
    string lex_greatest_type(){
        return *rbegin(types);
    }
};