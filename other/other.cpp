#include "other.hpp"

other::GameEntry::GameEntry(std::string name,int score):name(name),score(score){

} 

std::string other::GameEntry::getName(){
            return name;
}

int other::GameEntry::getScore(){
    return score;
}

std::string other::GameEntry::tostring(){
    return "( "+name+", "+std::to_string(score)+" )";
}

other::ScoreBoard::ScoreBoard(int capacity):capacity(capacity),board(new GameEntry*[capacity]){
    
}

void other::ScoreBoard::add(other::GameEntry *e){
    if(length<capacity){
        length++;
    }
    if(length < capacity || e->getScore() > board[capacity-1]->getScore()){
        size_t ptr=length-1;
        while(ptr>0 && board[ptr-1]->getScore()<e->getScore()){
            board[ptr]=board[ptr-1];
            ptr--;
        }
        board[ptr]=e;
    }    
}

other::ScoreBoard::~ScoreBoard(){
    std::cout<<"销毁ScoreBoard"<<std::endl;
    delete [] board;
}


std::string other::ScoreBoard::tostring(){
    std::string result("[ ");
    for(size_t i=0;i<length;i++){
        result+=board[i]->tostring();
    }
    result+=" ]";
    return result;
}

other::GameEntry* other::ScoreBoard::remove(int i){
    if(i<0 || i>=length){
        std::cout<<"remove移除位置非法"<<std::endl;
        return nullptr;
    }
    GameEntry* result=board[i];
    for(int p=i;p<length;p++){
        board[p]=board[p+1];
    }
    length--;
    board[length]=nullptr;
    return result;
}

void other::insertsort(int array[],int arraysize){
    if(array == nullptr){
        return;
    }
    if(arraysize == 0){
        return;
    }
    for(int i=1;i<arraysize;i++){
        int curvalue=array[i];
        int ptr=i-1;
        while(ptr>=0 && array[ptr]>curvalue){
            array[ptr+1]=array[ptr];
            ptr--;
        }
        array[ptr+1]=curvalue;
    }
}

other::CaesarCipher::CaesarCipher(int rotate):rotate(rotate){
    for(int i=0;i<26;i++){
        encoder[i]='a'+(i+rotate)%26;
        decoder[i]='a'+(i-rotate+26)%26;
    }
}

std::string other::CaesarCipher::transform(std::string origin,char coder[]){
    std::string result(origin.size(),' ');
    for(int i=0;i<origin.size();i++){
        if(isalpha(origin[i])){
            int pos=origin[i]-'a';
            result[i]=coder[pos];
        }else{
            result[i]=origin[i];
        }
    }
    return result;
}

std::string other::CaesarCipher::encrypt(std::string message){
    return transform(message,encoder);
}

std::string other::CaesarCipher::decrypt(std::string message){
    return transform(message,decoder);
}