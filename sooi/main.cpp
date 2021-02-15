#include <iostream>
#include <string>
using namespace std;
#define ON

int rankCounter(string line){
    static int rank=0;
    
    if(!(line.find('{')==string::npos)) rank++;
    if(!(line.find('}')==string::npos)) rank--;
    
    return rank;
}

#if defined(ON)
void funclen(){
    string line, funcname;
    int prevRank=0, presRank=0, count=0;
    
    cout<<"input code"<<endl;
    
    while (getline(cin, line)) {
        presRank=rankCounter(line);
        
        if(presRank<prevRank && presRank==0) cout<<count-1<<' '<<funcname<<endl;
        else if(prevRank==0 && presRank>prevRank){
            count=0;
            funcname=line.substr(line.find(' '),line.find('(')-line.find(' '));
        }
        count++;
        prevRank=presRank;
    }
}
#endif

int main(){
    funclen();
}
