class Solution:
    def isValid(self, s: str) -> bool:
        st=[]
        for i in range(len(s)):
            if s[i]=='(' or s[i]=="{" or s[i]=='[':
                st.append(s[i])
            else:
                if st:
                    top=st[-1]
                    if(s[i]==')' and top=='(' or s[i]=='}' and top=='{' or s[i]==']' and top=='['):
                        st.pop()
                    else: return False
                else: return False
        if not st: return True
        return False