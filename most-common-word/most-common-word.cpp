class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map <string,int> mp;
        string res,st="";
        int mx=0;
        for (int i=0;i<banned.size();i++)
            for (int j=0;j<banned[i].length();j++)
                if (banned[i][j]>='A' && banned[i][j]<='Z')
                    banned[i][j]=char(banned[i][j]-'A'+'a');
                
        for (auto x:banned) mp[x]=-1001;
        for (auto x:paragraph)
          if ( (x>='a' && x<='z') ) 
            st += x;
        else if (x>='A' && x<='Z')
            st +=char(x-'A'+'a') ;
        else
        if (st[0]>='a' && st[0]<='z')
        {
            
            mp[st]++;
            if (mp[st]>mx) 
            {
                res=st;
                mx=mp[st];
            }
            st="";    
         }

        mp[st]++;
        //return to_string(mx);
        if (mp[st]>mx) 
        {
            res=st;
            mx=mp[st];
        }
        return res;
    }
};