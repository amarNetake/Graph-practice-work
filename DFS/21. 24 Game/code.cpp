class Solution {
public:
    vector<double> compute(double x,double y)
    {
        vector<double> temp;
        temp.push_back(x+y);
        temp.push_back(x-y);
        temp.push_back(y-x);
        temp.push_back(x*y);
        temp.push_back(x/y);
        temp.push_back(y/x);
        return temp;
    }
    
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums={(double)cards[0],(double)cards[1],(double)cards[2],(double)cards[3]};
        return helper(nums);
    }
    
    bool helper(vector<double>& a)
    {
        if(a.size()==1)
        {
            return abs(a[0]-24)<0.001?true:false;
        }
        for(int i=0;i<a.size();i++)
        {
            for(int j=i+1;j<a.size();j++)
            {
                vector<double> b(a.size()-1);
                for(int k=0,index=0;k<a.size();k++)
                {
                    if(k!=i && k!=j) b[index++]=a[k];
                }
                for(auto x:compute(a[i],a[j]))
                {
                    b[b.size()-1]=x;
                    if(helper(b)==true) return true;
                }
            }
        }
        return false;
    }
};