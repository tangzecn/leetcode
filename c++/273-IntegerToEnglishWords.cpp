#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        static const vector<string> groupName = {"", " Thousand", " Million", " Billion"};
        string res = "";
        int i = 0;
        while (num > 0) {
            string groupWords = getGroupWords(num % 1000);
            num /= 1000;
            if (groupWords.length() > 0) {
                groupWords.append(groupName[i]);
                res = groupWords + res;
            }
            i++;
        }
        return res.substr(1);
    }
    
private:
    string getGroupWords(int num) {
        static const vector<string> less_ten = 
            {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        static const vector<string> less_twenty =  {" Ten", " Eleven", " Twelve", " Thirteen", 
            " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        static const vector<string> ten_prefix = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", 
            " Seventy", " Eighty", " Ninety"};
            
        string words = "";
        int hundred = num / 100;
        num %= 100;
        if (hundred > 0) {
            words.append(less_ten[hundred]);
            words.append(" Hundred");
        }
        if (num < 10) {
            words.append(less_ten[num]);
        } else if (num < 20) {
            words.append(less_twenty[num - 10]);
        } else {
            words.append(ten_prefix[num / 10]);
            words.append(less_ten[num % 10]);
        }
        return words;
    }
};

int main() {
    return 0;
}
