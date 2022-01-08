/*You have to complete this function*/
void print(string input,int index,string output,vector<string>&v)
{
    if(index==input.size())
    {
        v.push_back(output);
        return;
    }
    // dont pick
    print(input,index+1,output+input[index],v);
    
    // pick 
    print(input,index+1,output+" "+input[index],v);
    
}


vector<string>  spaceString(char str[])
{
    string input =str;
    vector<string>v;
    string output="";
    output+=input[0];
    print(input,1,output,v);
    return v;
//Your code here
}
