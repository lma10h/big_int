#include <iostream>
#include <vector>

using namespace std;

class BigInt {
public:
    explicit BigInt(int value) {
        string s = to_string(value);
        for (int i=(int)s.length(); i>0; i-=9) {
        if (i < 9) {
		a.push_back (atoi (s.substr (0, i).c_str()));
	}
	else {
		a.push_back (atoi (s.substr (i-9, 9).c_str()));
        }
    }
    
    BigInt() = default;
    BigInt(const BigInt &b) {
        a.clear();
        a.resize(b.a.size());
        copy(b.a.begin(), b.a.end(), a.begin());
    }

    BigInt& operator=(const BigInt &b) {
        a.clear();
        a.resize(b.a.size());
        copy(b.a.begin(), b.a.end(), a.begin());
	return *this;
    }
    
    BigInt operator+(const BigInt &b) {
        BigInt c;
        c.a.resize(a.size());

        int carry = 0;
        for (size_t i=0; i<max(a.size(),b.a.size()) || carry; ++i) {
        	if (i == a.size()) {
			c.a.push_back(0);
        	}
		c.a[i] = a[i] + carry + (i < b.a.size() ? b.a[i] : 0);
        	carry = a[i] >= base;
        	if (carry) {
        	    a[i] -= base;
        	}
        }
        
        return c;
    }
    
    BigInt operator*(const BigInt &b) {
        BigInt c;
        c.a.resize(a.size()+b.a.size());

        for (size_t i=0; i<a.size(); ++i) {
            for (int j=0, carry=0; j<(int)b.a.size() || carry; ++j) {
                long long cur = c.a[i+j] + a[i] * 1ll * (j < (int)b.a.size() ? b.a[j] : 0) + carry;
                c.a[i+j] = int (cur % base);
                carry = int (cur / base);
            }
        }
        while (c.a.size() > 1 && c.a.back() == 0) {
            c.a.pop_back();
        }

        return c;
    }
    
    // TODO other operators    
    
    void print() const {
        printf("%d", a.empty() ? 0 : a.back());
        for (int i=(int)a.size()-2; i>=0; --i) {
	        printf ("%09d", a[i]);
        }
        printf("\n");
    }
    
private:
    typedef vector<int> lnum;
    lnum a;
    const int base = 1000*1000*1000;
};
