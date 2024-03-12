#include <iostream>
using namespace std;

class Overlay{
public:
    int a,b,c,d;

    bool isOverlay(int a,int b,int c,int d){
        if(b>c && d>a){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    Overlay Segment;
    int a,b,c,d;
    int temp;
    cin>>a>>b>>c>>d;

    if(a>b){
        temp=a;
        a=b;
        b=temp;
    }

    if(c>d){
        temp=c;
        c=d;
        d=temp;
    }

    if(Segment.isOverlay(a,b,c,d)){
        cout<<"overlay";
    }

    else{
        cout<<"no overlay";
    }

    return 0;
}