#include <iostream>
#include <string>

using namespace std;

class Clock{
   public:
        int hour;
        int min;
        int sec;
        string ti;
        
    
        Clock(int x,int y,int z,string f){
            hour=x;
            min=y;
            sec=z;
            ti=f;
        }
        void print_time(){
            cout<<hour<<":"<<min<<":"<<sec<<" ";
        }
        void display(){
            print_time();
            cout<<ti<<endl;
        }
        
};
class StandardClock : Clock{
  private:
    int flag;
    
  public:
    StandardClock(int x,int y,int z,string f):Clock(x,y,z,f){
        if(ti=="AM"){
           flag=0;
        }else{
           flag=1;
        }
    }
    
   void print_time(){
        cout<<hour<<":"<<min<<":"<<sec<<endl;
    }
    void display(){
        if(!flag){
        cout<<"上午"<<" ";
        }else{
        cout<<"下午"<<" ";    
        }
        print_time();
        
    }
};
class MilitaryClock : Clock{
  private:
    int flag;
  public:
    MilitaryClock(int x,int y,int z,string f):Clock(x,y,z,f){
     if(ti=="AM"){
           flag=0;
        }else{
           flag=1;
        }
    }
    void print_time(int flag){
        if(flag){
            cout<<hour+12<<":";
        }else{
            cout<<hour<<":";
        }
    }
    void display(){
        print_time(flag);
        cout<<min<<":"<<sec<<endl;
    }
};
int main(){
   Clock cc(10,25,43,"AM");
   StandardClock sc(10,25,43,"AM");
   MilitaryClock mc(10,25,43,"AM");
   cc.display();
   sc.display();
   mc.display();
    return 0;
}
