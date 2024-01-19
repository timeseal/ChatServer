#include "json.hpp"

using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

//json序列化示例1
string func1()
{
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    string sendBuf = js.dump();

    //cout << sendBuf << endl;//序列化语句
    return sendBuf;

}

//json序列化示例2
string func2()
{
    json js;

    //调加数组
    js["id"] = {1,2,3,4,5};

    //添加key-value
    js["name"] = "zhang san";


    // js["msg"]["zhang san"] = "hello world"; 
    // js["msg"]["li si"] = "hello world"; 
    //添加对象
    js["msg"] = {{"zhang san", "hello world"},{"li si","hello world"}};

    // cout << js << endl;
    return js.dump();
}

string func3()
{
    json js;
    
    //直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    //直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});

    js["path"] = m;

    string sendBuf = js.dump();
    return sendBuf;
    // cout << sendBuf << endl;//json数据对象 转成 序列化json字符串
}

int main()
{
    // string recvBuf = func1();//假设是网络发送过来的数据
    // string recvBuf = func2();
    string recvBuf = func3();

    //数据的反序列化，把json字符串反序列化成json数据对象(可看做容器，方便访问)
    json jsbuf = json::parse(recvBuf);
    // cout << jsbuf["msg_type"] << endl;
    // cout << jsbuf["from"] << endl;
    // cout << jsbuf["to"] << endl;
    // cout << jsbuf["msg"] << endl;

    // cout << jsbuf["id"] << endl;
    // auto arr = jsbuf["id"];
    // cout << arr[2] << endl;

    // auto jsmsg = jsbuf["msg"];
    // cout << jsmsg["zhang san"] << endl;
    // cout << jsmsg["li si"] << endl;

    vector<int> vec = jsbuf["list"];//js对象里面的数组类型，直接放入vector容器当中

    for(int &v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    map<int, string> mymap = jsbuf["path"];

    for(auto &p : mymap)
    {
        cout << p.first << " " << p.second << endl;
    }

    cout << endl;


    //func2();
    //func3();
    return 0;
}