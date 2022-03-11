#include <iostream>
#include <fstream>
#include "avlTree.cpp"
using namespace std;
 AVL_TREE <string, int> counter (const string& fileName){
    ifstream file;
    AVL_TREE<string,int> a;
    file.open( fileName.c_str() );
    if( !file.good() )
         return a;
        string word;
        int counter = 0;
    while( true )
    {
        file>>word;
        //cout<<word << " ";
        if(a.CheckParameter(word)){
            a.GetInfo(word, counter);
            counter++;
            a.ChangeInfo(word,counter);
        }
        a.Insert(word,1);
        if( file.fail() )
             break;
    }
    //a.Visual_Print();
    return a;
};
void Test_1(){ // testing  printing
    cout<<"           Test 1 - printing test"<<endl;
    cout<<endl;
    int arr1[]= {16,8,24,4,12,28,2,6,10,14,18,22,26,30};
    AVL_TREE<int,char> a;
    for(int i =0; i<14;i++){
        a.Insert(arr1[i],'a');
    };
    a.Visual_Print();
    cout<<endl;
    a.Print(true);
    cout<<endl;
    a.Print(false);
    cout<<endl;
};
void Test_2(){ // right rotation
    cout<<"           Test 2 Insertion: Right rotation"<<endl;
    cout<<endl;
    AVL_TREE<int,char> a;
    a.Insert(4,'a');
    a.Insert(2,'a');
    a.Insert(5,'a');
    a.Insert(3,'a');
    a.Insert(1,'a');
    a.Visual_Print();
    a.Insert(0,'a');
    a.Visual_Print();
};
void Test_3(){
    cout<<"           Test 3 Insertion: Left rotation"<<endl;
    cout<<endl;
    AVL_TREE<int,char> a;
    a.Insert(3,'a');
    a.Insert(2,'a');
    a.Insert(5,'a');
    a.Insert(4,'a');
    a.Insert(6,'a');
    a.Visual_Print();
    a.Insert(8,'a');
    a.Visual_Print();
};
void Test_4(){
    cout<<"           Test 4 Insertion: Right - Left rotation"<<endl;
    cout<<endl;
    AVL_TREE<int,char> a;
    a.Insert(3,'a');
    a.Insert(2,'a');
    a.Insert(7,'a');
    a.Insert(5,'a');
    a.Insert(8,'a');
    a.Visual_Print();
    a.Insert(6,'a');
    a.Visual_Print();
};
void Test_5(){
    cout<<"           Test 5 Insertion: Left- Right rotation"<<endl;
    cout<<endl;
    AVL_TREE<int,char> a;
    a.Insert(5,'a');
    a.Insert(6,'a');
    a.Insert(2,'a');
    a.Insert(1,'a');
    a.Insert(3,'a');
    a.Visual_Print();
    a.Insert(4,'a');
    a.Visual_Print();
};
void Test_6(){ // right rotation
    cout<<"           Test 6 Deletion: Right rotation"<<endl;
    cout<<endl;
    AVL_TREE<int,char> a;
    a.Insert(4,'a');
    a.Insert(2,'a');
    a.Insert(5,'a');
    a.Insert(6,'a');
    a.Insert(3,'a');
    a.Insert(1,'a');
    a.Insert(0,'a');
    a.Visual_Print();
    a.Removal(6);
    a.Visual_Print();
};
void Test_7(){
    cout<<"           Test 7 Deletion: Left rotation"<<endl;
    cout<<endl;
    AVL_TREE<int,char> a;
    a.Insert(3,'a');
    a.Insert(2,'a');
    a.Insert(4,'a');
    a.Insert(1,'a');
    a.Insert(6,'a');
    a.Insert(5,'a');
    a.Insert(8,'a');
    a.Visual_Print();
    a.Removal(1);
    a.Visual_Print();
};
void Test_8(){
    cout<<"           Test 8 Deletion: Right - Left rotation"<<endl;
    cout<<endl;
    AVL_TREE<int,char> a;
    a.Insert(3,'a');
    a.Insert(2,'a');
    a.Insert(7,'a');
    a.Insert(1,'a');
    a.Insert(5,'a');
    a.Insert(8,'a');
    a.Insert(6,'a');
    a.Visual_Print();
    a.Removal(1);
    a.Visual_Print();
};
void Test_9(){
    cout<<"           Test 9 Deletion: Left- Right rotation"<<endl;
    cout<<endl;
    AVL_TREE<int,char> a;
    a.Insert(5,'a');
    a.Insert(6,'a');
    a.Insert(2,'a');
    a.Insert(7,'a');
    a.Insert(1,'a');
    a.Insert(3,'a');
    a.Insert(4,'a');
    a.Visual_Print();
    a.Removal(7);
    a.Visual_Print();
};
bool Test_10(){ // operator == test
    AVL_TREE<int,char> a;
    a.Insert(5,'a');
    a.Insert(6,'a');
    a.Insert(2,'a');
    a.Insert(7,'a');
    a.Insert(1,'a');
    a.Insert(3,'a');
    a.Insert(4,'a');
    AVL_TREE<int,char> b;
    b.Insert(5,'a');
    b.Insert(6,'a');
    b.Insert(2,'a');
    b.Insert(7,'a');
    b.Insert(1,'a');
    b.Insert(3,'a');
    b.Insert(4,'a');
    return a == b;
};
bool Test_11(){ // copy constuctor test
    AVL_TREE<int,char> a;
    a.Insert(5,'a');
    a.Insert(6,'a');
    a.Insert(2,'a');
    a.Insert(7,'a');
    a.Insert(1,'a');
    a.Insert(3,'a');
    a.Insert(4,'a');
    AVL_TREE<int,char> b = a;
    return a == b;
};
bool Test_12(){ // assigment operator test
    AVL_TREE<int,char> a;
    a.Insert(5,'a');
    a.Insert(6,'a');
    a.Insert(2,'a');
    a.Insert(7,'a');
    a.Insert(1,'a');
    a.Insert(3,'a');
    a.Insert(4,'a');
    AVL_TREE<int,char> b;
    a = b;
    return a == b;
};
bool Test_13(){
    AVL_TREE<int,char> a;
    a.Insert(5,'a');
    a.Insert(6,'a');
    a.Insert(2,'a');
    a.Insert(7,'a');
    a.Insert(1,'a');
    a.Insert(3,'a');
    a.Insert(4,'a');
    a.Removal(3);
    return (a.getcount() == 6);
};
bool Test_14(){ // getting and changing info
    AVL_TREE<int,char> a;
    a.Insert(5,'a');
    a.Insert(6,'a');
    a.Insert(2,'a');
    a.Insert(7,'a');
    a.Insert(1,'a');
    a.Insert(3,'a');
    a.Insert(4,'a');
    char info;
    bool flag = true;
    a.GetInfo(4,info);
    if( info != 'a' )
        flag =  false;
    info = 'b';
    a.ChangeInfo(4,info);
    a.GetInfo(4,info);
    if( info != 'b')
        flag = false;
    return flag;
};
int main()
{
    Test_1();
    Test_2();
    Test_3();
    Test_4();
    Test_5();
    Test_6();
    Test_7();
    Test_8();
    Test_9();
    if(Test_10() && Test_11() && Test_12() &&Test_13()  &&  Test_14() )
        cout<<"Works : )"<<endl;
    else
        cout<<"Doesn't work :("<<endl; 
        /*
        AVL_TREE<string,int> a = counter("dane.txt");
    if(a.CheckBalance())
        cout<<"Works : )"<<endl;
    else
        cout<<"Doesn't work :("<<endl;
       // a.Print(true);
        /*
        AVL_TREE<char,int>  a;
        a.Insert('y',1);
        a.Visual_Print();
        a.Insert('o',1);
        a.Visual_Print();
        a.Insert('u',1);
        a.Visual_Print();
        a.Insert('b',1);
        a.Insert('e',1);
        a.Insert('c',1);
        a.Insert('o',1);
        a.Insert('m',1);
        a.Insert('e',1);
        a.Insert('w',1);
        a.Insert('h',1);
        a.Insert('a',1);
        a.Visual_Print();
        a.Insert('t',1);
        a.Visual_Print();
        a.Insert('b',1);
        a.Visual_Print();
        a.Insert('e',1);
        a.Visual_Print();
        a.Insert('l',1);

        a.Insert('i',1);

        a.Insert('v',1);
        a.Insert('e',1);
                a.Visual_Print();
    return 0;

    AVL_TREE<string,int>  a;
        a.Insert("ha",3);
        a.Insert("ha",3);
        a.Insert("twoja",1);
        a.Insert("stara",8);
        a.Insert("e",11);
        a.Insert("c",1);
        a.Visual_Print(); */
}
