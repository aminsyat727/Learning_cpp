#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int WIDTH = 16;
const char SRC_NAME[] = "hello.txt";
const char DST_NAME[] = "hello2.txt";

const int BUF_SIZE = 1024;

int main(){
  fstream file;
  file.open("hello.txt", ios::in | ios::binary);
  if(! file.is_open()){
    return EXIT_FAILURE;
  }

  do {
    unsigned char buf[WIDTH];

    file.read((char*)buf, sizeof buf);

    for(int i=0, size = file.gcount(); i < size; ++i){
      printf("%02X ", buf[i]);
    }
    cout << endl;
  } while(! file.eof());
  file.close();

  fstream src;
  fstream dst;

  src.open(SRC_NAME, ios::in | ios::binary);
  if(! src.is_open()){
    return EXIT_FAILURE;
  }

  dst.open(DST_NAME, ios::out | ios::binary);
  if(! dst.is_open()){
    src.close();
    return EXIT_FAILURE;
  }

  do {
    char buf[BUF_SIZE];

    src.read(buf, sizeof buf);
    dst.write(buf, src.gcount());
  } while(! src.eof());

  dst.close();
  src.close();
  return 0;
}

