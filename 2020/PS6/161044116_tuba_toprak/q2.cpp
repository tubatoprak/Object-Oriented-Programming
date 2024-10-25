#include <iostream>
#include <cstdlib>
using namespace std;


class CharPair{
public:
   
    CharPair();
    CharPair(int sz);
    CharPair(int sz, char parameter_arr[]);

  
    int getSizeOfArray() const;

  
    char& operator [](const int index);
private:
    char arr[100];
    int size;
};

CharPair::CharPair(){
    size = 10;
    for(int i = 0; i<size; i++){
        arr[i] = '#';
    }
}
CharPair::CharPair(int sz){
    if(sz > 100){
        cout << "Size exceeded than maximum limit.";
        exit(1);
    }
    for(int i = 0; i<sz; i++){
        arr[i] = '#';
    }
}

CharPair::CharPair(int sz, char parameter_array[]){
    if(sz > 100){
        cout << "Size exceeded maximum limit.";
        exit(1);
    }
    for(int i = 0; i<sz; i++){
        arr[i] = parameter_array[i];
    }
}


int CharPair::getSizeOfArray() const{
    return size;
}
char& CharPair::operator [](int index){
    if(index >= 100){
        cout << "Not a valid array index.";
        exit(1);
    }
    else{
        return arr[index];
    }
}

int main(){
    
    cout<<"TEST 1: CharPair a"<<endl;
    CharPair a;
    for (int i = 0; i < 10; ++i)
    {
       cout<<a[i];
    }
    
    cout<<endl<<"TEST 2: CharPair c(2) "<<endl;
    CharPair c(2);
    for (int i = 0; i < 2; ++i)
    {
       cout<<c[i];
    }
    cout<<endl<<"TEST 3: "<<endl;
    CharPair d;
    d[1]='A';
    d[2]='B';
    cout << "d[1] and d[2] are:  "<<endl;
    cout<<d[1]<<d[2]<<endl;
    d[1]='C';
    d[2]='D';
    cout << "After"<<endl;
    cout << "d[1] and d[2] are:  "<<endl;
    cout<<d[1]<<d[2]<<endl;
   
    cout<<endl<<"TEST 4: CharPair c(3,arr)  "<<endl;
    char arr[3] = {'a', 'b', 'c'};
    CharPair b(3,arr);
    cout << b[0]<<endl;
    cout << b[1]<<endl;
    cout << b[2]<<endl;

   
    return 0;
}