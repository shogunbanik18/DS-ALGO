class Solution{   
public:

    string ones[20]={"","one ", "two ","three ","four ", "five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "}; 
    string tens[10] = {"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
    
    string numtoword(int n,string s)
    {
        string str="";
        if(n>19)
        {
            str+=tens[n/10]+ones[n%10];
        }
        else
        {
            str+=ones[n];
        }
        if(n)
        {
            str+=s;
        }
        return str;
    }
    
    string convertToWords(long n)
    {
        string res;
        res +=numtoword((n/10000000),"crore ");
        res += numtoword((n/100000)%100,"lakh ");
        res += numtoword((n/1000)%100,"thousand ");
        res += numtoword((n/100)%10,"hundred ");
        if(n>100 and n%100)
        {
            res+="and ";
        }
        res += numtoword((n%100),"");
        return res;
        // code here
    }
};
