class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    set<int> s;  // To keep track of elements in the priority queue
    int cur = 1;

    SmallestInfiniteSet() {}

    int popSmallest() {
        int res;
        if (!q.empty() && q.top() < cur) {
            res = q.top();
            q.pop();
            s.erase(res);
        } else {
            res = cur;
            cur++;
        }
        return res;
    }

    void addBack(int num) {
        if (num < cur && s.find(num) == s.end()) {
            q.push(num);
            s.insert(num);
        }
    }
};
