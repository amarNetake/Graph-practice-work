class Solution {
public:
    int j=-1;  //Global variable to keep track of uptill where the string is traversed.
    string decodeString(string str) {
        string result="";
        int num=0;
        
        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];
            if(ch-'0'<10)   num=num*10 + (ch-'0');
            else if(ch>='a' && ch<='z')
            {
                result.insert(result.end(),ch);
            }
            else if(ch=='[')
            {
                string temp=decodeString(str.substr(i+1));
                while(num--)result.append(temp);
                i=i+j+1;  //Since we are sending the substring from index i+1 so it would be relative indexing
                j=-1;
                num=0;
            }

            //The control will not reach here if it is parent
            else if(ch==']') //The control will reach here only if the current function is called through recursion
            {
                j=i;
                return result;
            }
        }
        return result;
    }
};