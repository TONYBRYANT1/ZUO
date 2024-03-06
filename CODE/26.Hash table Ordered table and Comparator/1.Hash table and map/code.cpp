#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Student 
{
public:
    int age;
    string name;

    Student(int a, string b) : age(a), name(b) {}
    
    // 重载哈希函数和相等比较函数
    bool operator==(const Student& other) const 
    {
        return age == other.age && name == other.name;
    }
};

// 自定义哈希函数模板
template <>
struct hash<Student> {
    size_t operator()(const Student& s) const 
    {
        size_t age_hash = hash<int>()(s.age);
        size_t name_hash = hash<string>()(s.name);
        // 结合 age 和 name 的哈希值
        return age_hash ^ (name_hash << 1);
    }
};

int main() 
{
    string str1 = "Hello";
    string str2 = "Hello";

    // false，因为不同的内存地址
    cout << (str1 == str2) << endl;
    // true，因为它们的值是相同的
    cout << (str1 == str2) << endl;

    unordered_set<string> set;
    set.insert(str1);
    cout << set.count("Hello") << endl;
    cout << set.count(str2) << endl;
    set.insert(str2);
    cout << set.size() << endl;
    set.erase(str1);
    set.clear();
    cout << set.empty() << endl;

    cout << "===========" << endl;

    unordered_map<string, string> map1;
    map1[str1] = "World";
    cout << map1.count("Hello") << endl;
    cout << map1.count(str2) << endl;
    cout << map1[str2] << endl;
    cout << (map1.find("你好") == map1.end()) << endl;
    map1.erase("Hello");
    cout << map1.size() << endl;
    map1.clear();
    cout << map1.empty() << endl;

    cout << "===========" << endl;

    // 一般在笔试中，未必需要申请哈希表
    unordered_map<int, int> map2;
    map2[56] = 7285;
    map2[34] = 3671263;
    map2[17] = 716311;
    map2[24] = 1263161;
    // 上面的map2行为，可以被如下数组的行为替代
    int arr[100] = {0};
    arr[56] = 7285;
    arr[34] = 3671263;
    arr[17] = 716311;
    arr[24] = 1263161;
    // 哈希表的增、删、改、查，都可以被数组替代，前提是key的范围是固定的、可控的
    cout << "在笔试场合中哈希表往往会被数组替代" << endl;

    cout << "===========" << endl;

    Student s1(17, "张三");
    Student s2(17, "张三");
    unordered_map<Student, string> map3;
    map3[s1] = "这是张三";
    cout << map3.count(s1) << endl;
    cout << map3.count(s2) << endl;
    map3[s2] = "这是另一个张三";
    cout << map3.size() << endl;
    cout << map3[s1] << endl;
    cout << map3[s2] << endl;

    return 0;
}
