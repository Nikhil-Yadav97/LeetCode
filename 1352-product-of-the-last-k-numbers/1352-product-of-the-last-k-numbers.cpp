class ProductOfNumbers {
public:
    vector<int> ans;
    int prod = 1;
    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            ans.clear();
            prod = 1;
        } else {
            prod *= num;
            ans.push_back(prod);
        }
    }

    int getProduct(int k) {
        if(k>ans.size())
        return 0;
        if (ans.size() == k)
            return ans.back();
        return ans.back() / ans[ans.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */