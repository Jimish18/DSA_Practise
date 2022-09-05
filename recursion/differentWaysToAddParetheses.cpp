/*
Question - Different Ways to Add Parentheses

Link - https://leetcode.com/problems/different-ways-to-add-parentheses/
*/

bool is_operator(char s){
    if(s=='*' or s=='+' or s=='-'){
        return true;
    }
    return false;
}

int calValue(int num1,int num2,char s){
    if(s=='*'){
        return num1*num2;
    }
    else if(s=='+'){
        return num1+num2;
    }
    else{
        return num1-num2;
    }
}

int number(string s,int l,int r){
    int ans=0;
    for(int i=l;i<=r;++i){
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}


vector<int> solve(string &s,int i,int j){
    
    vector<int> pvals;
    
    for(int k=i+1;k<j;++k){
        if(is_operator(s[k])){
            vector<int> left=solve(s,i,k-1);
            vector<int> right=solve(s,k+1,j);
            for(int l:left){
                for(int r:right){
                    pvals.push_back(calValue(l,r,s[k]));
                }
            }
        }
    }
    
    if(pvals.empty()){
        pvals.push_back(number(s,i,j));
    }
    
    return pvals;
}

    
    
vector<int> diffWaysToCompute(string expression) {
    // similar to mcm
    int n=expression.size();
    return solve(expression,0,n-1);
}