/*
394. Decode String
Medium


Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

*/


class Solution {
public:
    string solve(string& s, int& i){
        
        string result;
        while(i<s.length() && s[i]!=']'){
            if(isdigit(s[i])){
                int k=0;
                while(i<s.length() && isdigit(s[i])){
                    k= k*10 + s[i]-'0';
                    i++;
                }
                i++;
                string res=solve(s, i);
                while(k>0){
                    result+=res;
                    k--;
                }
                i++;
            }else{
                result+=s[i];
                i++;
            }
        }
        return result;
    }
    
    string decodeString(string s){
        int i=0;
        return solve(s, i);
    }
};
