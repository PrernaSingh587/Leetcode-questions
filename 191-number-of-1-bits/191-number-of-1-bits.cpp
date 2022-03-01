#define intt uint32_t
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        while(n) {
            c++;
            n=(n-1)&n;
        }
        return c;
    }
};