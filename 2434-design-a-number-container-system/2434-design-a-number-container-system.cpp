class NumberContainers {
public:
    unordered_map<int, set<int>> numToInd;
    unordered_map<int, int> indToNum;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (indToNum.find(index) != indToNum.end()) {
            int prev = indToNum[index];
            numToInd[prev].erase(index);
            if (numToInd[prev].empty()) 
                numToInd.erase(prev);
            
        }
        indToNum[index] = number;
        numToInd[number].insert(index);
    }
    
    int find(int number) {
        if (numToInd.find(number) != numToInd.end()) 
            return *numToInd[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */