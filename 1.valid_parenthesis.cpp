class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        if(s[i]==')' || s[i]=='}' || s[i]==']'){
            return false;
        }
        while(s[i]!='\0'){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                i++;
                continue;
            }
            if(s[i]==')' || s[i]=='}' || s[i]==']'){

                    if(st.empty()){
                        return false;
                    }
                    if(st.top()=='(' && s[i]!=')')
                        return false;
                    else if(st.top()=='{' && s[i]!='}')
                        return false;
                    else if(st.top()=='[' && s[i]!=']')
                        return false;
                    else{
                        st.pop();
                        i++;
                    }
                
                // else{
                //     st.pop();
                //     i++;
                // }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};