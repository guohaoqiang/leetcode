// https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/discuss/49598/A-simple-Java-code

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i<n){
            if (ptr==0){
               k = read4(buf4); 
            }
            if (k==0)   break;
            while (i<n && ptr<k){
                buf[i++] = buf4[ptr++];
            }
            if (ptr>=k) ptr = 0;
        }
        return i;
    }
    int ptr = 0;
    int k = 0;
    char buf4[4];
};
