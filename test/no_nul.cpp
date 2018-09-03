#include "univalue.h"
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    char buf[] = "___[1,2,3]___";
    UniValue val;
    //return val.read(buf + 3, 7) ? 0 : 1;
    cout << val.read(buf + 3, 7) << endl;
    cout << val.write() << endl;
}
