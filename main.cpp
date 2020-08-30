#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

void num(const string& s,int& index,int tab){
    int num=0;
    if(!(((s[index]>='0')&&(s[index]<='9'))&&(index<static_cast<int>(s.length())))){throw index;}
    while(((s[index]>='0')&&(s[index]<='9'))&&(index<static_cast<int>(s.length()))){num=num*10+s[index]-'0';index++;}
    for(int i=0;i<tab;i++)cout<<"\t";
    cout<<"NUM: "<<num<<"\n";
}

void term(const string& s,int& index,int tab){
    for(int i=0;i<tab;i++)cout<<"\t";
    cout<<"TERM:(\n";
    num(s,index,tab+1);
    if((s[index]=='*'||s[index]=='/')&&(index<static_cast<int>(s.length()))){
        for(int i=0;i<tab+1;i++)cout<<"\t";
        cout<<"OPERATOR: "<<s[index]<<"\n";
        index++;
        term(s,index,tab+1);
    }
    for(int i=0;i<tab;i++)cout<<"\t";
    cout<<")\n";
}

void expr(const string& s){
    int index=0;
    try{
        cout<<"EXPR:(\n";
        term(s,index,1);
        while((s[index]=='+'||s[index]=='-')&&(index<static_cast<int>(s.length()))){
            cout<<"\t"<<"OPERATOR: "<<s[index]<<"\n";
            index++;
            term(s,index,1);
        }
        cout<<")";
    }catch(const int& c){
        cout<<"\n"<<s<<"\n"<<index+1<<":不正な文字>>\" "<<s[index]<<" \"\n";
        exit(1);
    }
}

int main(void){
    string s;
    cin>>s;
    expr(s);
    return 0;
}
