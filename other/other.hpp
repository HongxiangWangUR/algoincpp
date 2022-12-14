#include <string>
#include <iostream>
#ifndef OTHER
#define OTHER
namespace other{
    class GameEntry{
        private:
        std::string name;
        int score;
        public:
        GameEntry(std::string name,int score);
        std::string getName();
        int getScore();
        std::string tostring();
    };

    class ScoreBoard{
        private:
        int capacity=0;
        GameEntry **board=nullptr;
        size_t length=0;
        public:
        ScoreBoard(int capacity);
        void add(GameEntry *e);
        ~ScoreBoard();
        std::string tostring();
        GameEntry* remove(int i);
    };

    void insertsort(int data[],int arraysize);

    class CaesarCipher{
        private:
        char encoder[26];
        char decoder[26];
        int rotate;
        std::string transform(std::string origin,char coder[]);
        public:
        CaesarCipher(int rotate);
        std::string encrypt(std::string message);
        std::string decrypt(std::string message);
    };
}
#endif