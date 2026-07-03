class Solution(object):
    def isSubsequence(self, s, t):
        abc=""
        #method finds s in the t , and then it writes on the abc string.
        for i in range(len(t)):
            for j in range(len(s)):
                if s[j]== t[i]:
                    abc += t[i]
                    break
        #if they are some , it will be true or if it has it ,it will be true "aba" -> "baba" like that.
        if abc == s  or abc.find(s)>0 :
            return True
        else:
            return False