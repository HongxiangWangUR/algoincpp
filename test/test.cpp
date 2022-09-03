#include "test.hpp"

void testother(){
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
}