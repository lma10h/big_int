#include <iostream>
#include <vector>

class BigInt {
public:
    explicit BigInt(int value) {
        while (value > 0) {
            int digit=value%10;
            a.push_back(digit);
            value /= 10;
        }
    }
    
    BigInt(const BigInt &b) {
        a.resize(b.a.size());
        a = b.a;
    }
    
    BigInt& operator+(const BigInt &b) {
        int carry = 0;
        for (size_t i=0; i<max(a.size(),b.a.size()) || carry; ++i) {
        	if (i == a.size()) {
        		a.push_back (0);
        	}
        	a[i] += carry + (i < b.a.size() ? b.a[i] : 0);
        	carry = a[i] >= base;
        	if (carry) {
        	    a[i] -= base;
        	}
        }
        
        return *this;
    }
    
    BigInt& operator=(const BigInt &b) {
        a = b.a;
        return *this;
    }
    
    // TODO other operators    
    
    void print() const {
        printf("%d", a.empty() ? 0 : a.back());
        for (int i=(int)a.size()-2; i>=0; --i) {
	        printf ("%09d", a[i]);
        }
    }
    
private:
    typedef vector<int> lnum;
    lnum a;
    const int base = 1000*1000*1000;
};
