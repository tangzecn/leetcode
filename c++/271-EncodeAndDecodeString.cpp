#include<string>
#include<vector>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (int i=0; i<strs.size(); i++) {
            encoded.append(std::to_string(strs[i].length()));
            encoded.append(1, SEPERATOR);
            encoded.append(strs[i]);
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int ptr = 0;
        while (ptr < s.length()) {
            int new_ptr = ptr;
            while (new_ptr < s.length() && s[new_ptr] != SEPERATOR) new_ptr++;
            if (new_ptr != ptr && new_ptr < s.length()) {
                int len = std::stoi(s.substr(ptr, new_ptr - ptr));
                if (new_ptr + len > s.length()) {
                    // invalid encoded string, should not reach here
                    return vector<string>();    
                } else {
                    res.push_back(s.substr(new_ptr + 1, len));
                    ptr = new_ptr + 1 + len;
                }
            } else {
                // invalid encoded string, should not reach here
                return vector<string>();
            }
        }
        return res;
    }
    
private:
    static const char SEPERATOR;
};

const char Codec::SEPERATOR = '#';

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
    return 0;
}
