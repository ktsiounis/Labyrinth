#include <iostream>

using namespace std;

class Cell {

  public:
    int i,j; char c; 
    Cell() {i=0;j=0;c=' ';};     
    Cell (int x, int y, char a) {i=x;j=y;c=a;};
    void seti (int x) {i=x;};
    int geti () {return i;};
    void setj (int y) {j=y;};
    int getj () {return j;}; 
    void setc (char a) {c=a;};
    void changec(char a) {c=a;};
    char getc () {return c;};    
};
