#include "test.hpp"

void testother(){
    std::cout<<">> --- >> testing game board"<<std::endl;
    other::GameEntry *e1=new other::GameEntry("test1",1);
    other::GameEntry *e2=new other::GameEntry("test2",2);
    other::GameEntry *e3=new other::GameEntry("test3",3);
    other::ScoreBoard board(10);
    board.add(e1);board.add(e2);board.add(e3);
    std::cout<<board.tostring()<<std::endl;
    board.remove(4);
    board.remove(1);
    std::cout<<board.tostring()<<std::endl;
    board.remove(1);
    std::cout<<board.tostring()<<std::endl;
    delete e1;delete e2;delete e3;
    std::cout<<">> --- >> testing insert sort"<<std::endl;
    int num[]={5,3,1,6,9,1};
    int arraysize=sizeof(num)/sizeof(int);
    std::cout<<"array size: "<<arraysize<<std::endl;
    std::cout<<"before"<<std::endl;
    for(size_t i=0;i<arraysize;i++){
        std::cout<<num[i]<<" ";
    }
    std::cout<<std::endl;
    other::insertsort(num,arraysize);
    std::cout<<"after"<<std::endl;
    for(size_t i=0;i<arraysize;i++){
        std::cout<<num[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<">> ----- >> testing CaesarCipher"<<std::endl;
    std::string message="hello world";
    other::CaesarCipher *cipher=new other::CaesarCipher(4);
    std::string encoded=cipher->encrypt(message);
    std::string decoded=cipher->decrypt(encoded);
    std::cout<<"encoded string :"<<encoded<<std::endl;
    std::cout<<"decoded string :"<<decoded<<std::endl;
}

void testlist(){
    list::SinglyLinkedList<int> lis;
    int *result=lis.first();
    std::cout<<*result<<std::endl;
}