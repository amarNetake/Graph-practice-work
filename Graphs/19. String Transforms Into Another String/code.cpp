class Solution {
public:
    bool canConvert(string str1, string str2) {
        //Note : Here order of conversion matters.
        //Let we want to convert "aabcc" to "ccdee" then if we go with first converting a to c 
        //So it becomes ccbcc now we got more c's now if we try to convert c's to e's then it becomes "eebee"
        //So all the order really matters. Another thing is if there is already a mismatch that is
        //e.g. if we want to convert "abcbbd" to "pqcrrt" then it will never be possible as first b is willing
        //to convert into q and last 2 b's are willing to convert into r that is never gonna happen.
        
        unordered_map<char,char> ma;
        unordered_map<char,bool> track1;
        unordered_map<char,bool> track2;
        for(int i=0;i<str1.length();i++)  //Given both strings are of same length
        {
            char ch1=str1[i],ch2=str2[i];
            if(ma.find(ch1)!=ma.end() && ma[ch1]!=ch2) return false;
            ma[ch1]=ch2;
            track1[ch1]=true;
            track2[ch2]=true;
        }
        
        if(track1.size()==26 && track2.size()==26)
        {
            if(str1==str2) return true;
            return false;
        }
        return true;
    }
};