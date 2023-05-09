#include<iostream>
using namespace std;
int pil;

void loopfor(){
	for(int a=10;a>=3;a--){
		cout<<a<<endl;
	}
}
	
void tambah(){
	int a=10;
	int b=5;
	int c;
	c=a+b;
    cout<<c<<endl;
    	
}

void pilihan(){

	cout<<"0. Exit"<<endl;
    cout<<"1. Penjumlahan"<<endl;
    cout<<"2. loopfor"<<endl;
    cout<<"Pilihan :";
    cin>>pil;
    
    
}

int main(){
	pilihan();

    if(pil==0){
        cout<<"Thanks"<<endl;
        return 0;
    } else if (pil==1){
       tambah();
       pilihan();
    } else if(pil==2){
        loopfor();
        //goto pilihan;
        }

    else{
        cout<<"Pilihan Salah"<<endl;
        //goto pilihan;
    }
 }
