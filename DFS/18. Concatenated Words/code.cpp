class Solution {
public:

    bool canForm(string& word,unordered_map<string,bool>& ma,int curr,int combinationCount)
    {
        if(curr==word.length())
        {
            if(combinationCount>1) return true;
            return false;
        }
        string temp="";
        for(int i=curr;i<word.length();i++)
        {
            temp.insert(temp.end(),word[i]);
            if(ma.find(temp)!=ma.end())
            {
                bool found=canForm(word,ma,i+1,combinationCount+1);
                if(found==true) return true;
            }
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        unordered_map<string,bool> ma;
        unordered_map<string,bool> visited; //As same word my repeat many times
        for(auto word: words)
        {
            ma[word]=true;
        }
        for(auto word: words)
        {
            if(visited[word]==false && canForm(word,ma,0,0)==true)
            {
                result.push_back(word);
            }
            visited[word]=true; 
        }
        return result;
    }
};