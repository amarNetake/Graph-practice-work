vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> ma;
        
        for(auto x: tickets)
        {
            ma[x[0]].insert(x[1]);
        }
        
        vector<string> result;
        stack<string> st;
        
        st.push("JFK");         //JFK is our fixed starting point
        
        while(st.empty()==false)
        {
            string source=st.top();
            if(ma[source].size()==0)    //No further travel possible
            {
                result.push_back(source);
                st.pop();
                
            }
            else
            {
                auto city=ma[source].begin();
                st.push(*city);
                ma[source].erase(city);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }