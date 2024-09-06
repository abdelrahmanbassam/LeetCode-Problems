class SmallestInfiniteSet {
public:
    set<int> s;
    int cur = 1;

    SmallestInfiniteSet() {}

    int popSmallest() {
        int res;
        if (!s.empty() && *s.begin() < cur) {
            res = *s.begin();
            s.erase(s.begin());
        } else {
            res = cur;
            cur++;
        }
        return res;
    }

    void addBack(int num) {
        if (num < cur) {
            s.insert(num);
        }
    }
};
