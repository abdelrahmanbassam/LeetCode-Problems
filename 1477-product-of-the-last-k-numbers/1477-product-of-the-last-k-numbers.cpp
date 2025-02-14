class ProductOfNumbers {
public:
    vector<int> prefixProduct ={1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
           prefixProduct = {1}; 
        }
        else{
            int sz =  prefixProduct.size() - 1;
            prefixProduct.push_back(prefixProduct[sz] * num);
        }

    }
    
    int getProduct(int k) {
        int sz =  prefixProduct.size() - 1;
        if(k > sz)
            return 0;
        return prefixProduct[sz] / prefixProduct[sz - k];

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */