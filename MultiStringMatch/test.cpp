// Rocky 2011-05-05 11:09:19
//#include "test.h"
//namespace TEST_SPACE
//{
//}// end of TEST_SPACE
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define _DEBUG 1

#if _DEBUG
#define Debug(format, args...)   printf("%s:%d : " format "\n", __FILE__, __LINE__, ##args)
#else
#define Debug
#endif

#include "MultiStringMatch.h"


int main(int argc, char *argv[])
{
    const string opt = argv[1]?:"";

    if(argc < 4)
    {
        Debug("Usage: ./test -选项 主串 子串1 [子串2 ...]");
        return 1;
    }

    const string str = argv[2];
    string sub = "";
    vector<string> key;
    int i;
    for(i=3; i<argc; i++)
    {
        key.push_back(argv[i]);
        sub += "[";
        sub += argv[i];
        sub += "] ";
    }

    int ret;
    MultiStringMatch *p;

    Debug("--------------------------------------------");

    // 分大小写查找
    if(opt == "-1")
    {
        static MultiStringMatch s(key); 
        Debug("分大小写查找");
        p = &s;
    }
    else if(opt == "-2")
    {
        static MultiStringMatch s(key, true); 
        Debug("分大小写查找");
        p = &s;
    }
    else
    {
        Debug("Usage: ./test -选项 主串 子串1 [子串2 ...]");
        return 1;
    }

    Debug("主串：%s", str.c_str());
    Debug("子串: %s", sub.c_str());

    Debug("----匹配一个----");
    ret = p->MatchOneKey(str);
    Debug("%s", ret?"ok":"error");

    Debug("----匹配所有----");
    ret = p->MatchAllKey(str);
    Debug("%s", ret?"ok":"error");

    return 0;
}




 
