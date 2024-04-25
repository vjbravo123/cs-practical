#include <iostream>
    #include <string>
    
    using namespace std;
    
    string xor1(const string& a, const string& b) {
        string result = "";
        for (size_t i = 1; i < b.size(); ++i) {
            result += (a[i] == b[i] ? '0' : '1');
        }
        return result;
    }
    
    string mod2div(const string& dividend, const string& divisor) {
        size_t pick = divisor.size();
        string tmp = dividend.substr(0, pick);
        size_t n = dividend.size();
    
        while (pick < n) {
            if (tmp[0] == '1')
                tmp = xor1(divisor, tmp) + dividend[pick];
            else
                tmp = string(pick, '0') + dividend[pick];
            pick += 1;
        }
    
        return (tmp[0] == '1') ? xor1(divisor, tmp) : string(pick, '0');
    }
    
    string encodeData(const string& data, const string& key) {
        string appended_data = data + string(key.size() - 1, '0');
        string remainder = mod2div(appended_data, key);
        return data + remainder;
    }
    
    int main() {
        string data = "1011001";
        string key = "1101";
        string codeword = encodeData(data, key);
        cout << "Encoded data with CRC: " << codeword << endl;
        return 0;
    }