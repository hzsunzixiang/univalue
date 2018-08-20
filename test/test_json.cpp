// Test program that can be called by the JSON test suite at
// https://github.com/nst/JSONTestSuite.
//
// It reads JSON input from stdin and exits with code 0 if it can be parsed
// successfully. It also pretty prints the parsed JSON value to stdout.

#include <iostream>
#include <string>
#include "univalue.h"

using namespace std;

int test_from_cin ()
{
    UniValue val;
    if (val.read(string(istreambuf_iterator<char>(cin),
                        istreambuf_iterator<char>()))) {
        cout << val.write(1 /* prettyIndent */, 4 /* indentLevel */) << endl;
        return 0;
    } else {
        cerr << "JSON Parse Error." << endl;
        return 1;
    }
}


int test_from_text ()
{
    UniValue val;
    if (val.read("{\"a\":\"b\",\"hello\":[1,2,3,4,5]}")) 
	{
        cout << val.write(1 /* prettyIndent */, 4 /* indentLevel */) << endl;
        return 0;
    } else {
        cerr << "JSON Parse Error." << endl;
        return 1;
    }
}

int test_from_text1 ()
{
    UniValue val;
    if (val.read("{\"a\":\"b\",\"hello\":[1,2,3,4,5]}")) 
	{
        //cout << val.write(1 /* prettyIndent */, 4 /* indentLevel */) << endl;
        cout << val.write(0,0) << endl;
        return 0;
    } else {
        cerr << "JSON Parse Error." << endl;
        return 1;
    }
}

int test_push_back()
{
	UniValue blockHashes(UniValue::VARR);
	blockHashes.push_back("abcdef");
	blockHashes.push_back("12345");
	blockHashes.push_back("789");
	blockHashes.push_back(12345);

	UniValue uniStr(UniValue::VSTR, "abcdef");
	//UniValue uniStr(UniValue::VARR);
	//uniStr.push_back("xyz");
	//uniStr.push_back(123456);
	cout << uniStr.write() << endl;

	blockHashes.push_back(uniStr);

	cout << uniStr.write() << endl;
	cout << blockHashes.write() << endl;
	cout << uniStr.isNum() << endl;
	cout << uniStr.isStr() << endl;
}

int test_pushKV()
{
	UniValue blockHashes(UniValue::VARR);
	blockHashes.push_back("abcdef");
	blockHashes.push_back("12345");
	blockHashes.push_back("789");
	blockHashes.push_back(12345);

	UniValue uniStr(UniValue::VOBJ);
	uniStr.pushKV("hello", "world");
	cout << uniStr.write() << endl;

	blockHashes.push_back(uniStr);

	cout << uniStr.write() << endl;
	cout << blockHashes.write() << endl;
}

int test_pushKV1()
{
	//UniValue blockHashes(UniValue::VARR);
	UniValue blockHashes1(UniValue::VOBJ);
	UniValue blockHashes(UniValue::VARR);
	blockHashes.push_back("abcdef");
	blockHashes.push_back("12345");
	blockHashes.push_back("789");
	blockHashes.push_back(12345);

	UniValue uniStr(UniValue::VOBJ);
	uniStr.pushKV("hello", "world");
	cout << uniStr.write() << endl;

	//blockHashes.push_back(uniStr);
	blockHashes1.pushKV("object", uniStr);
	blockHashes1.pushKV("object1", blockHashes);

	// 不生效
	//blockHashes1.push_back("789");

	cout << uniStr.write() << endl;
	cout << blockHashes1.write() << endl;
}

int test_num()
{
	UniValue uniNum(UniValue::VARR);
	uniNum.push_back(12345);
	cout << uniNum.write() << endl;

	//UniValue uniStr(UniValue::VSTR);
	UniValue uniStr(UniValue::VARR);
	uniStr.push_back("abcde");
	cout << uniStr.write() << endl;

}




int main (int argc, char *argv[])
{
	//test_from_cin();
	//test_from_text();
	//test_from_text1();
	//test_push_back();
	//test_pushKV1();
	test_num();
	return 0;
}
