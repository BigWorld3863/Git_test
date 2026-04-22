#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>

using namespace std;

int main()
{
    //vector
    {
        vector<int> v;
        vector<int> x(5, 32);
        auto z = x.empty();

        v.push_back(3);
        v.push_back(5);

        int t1 = v[1];
        int s1 = (int)v.size(); // unsigned

        for (int &x : v)
        {
            x++;
        }

        v.insert(v.begin() + 1, 29);
        // v.erase(v.begin() + 2);
        // v.pop_back();
        v.push_back(42);
        v.push_back(7);
        v.push_back(6);
        sort(v.begin() + 1, v.end());
        sort(v.begin(), v.end(), greater<int>());

        // 이차원 벡터 - 그래프, dfs, bfs에서 사용
        vector<vector<int>> qwe(5);
        qwe[2].push_back(4);
        qwe.push_back({1, 2, 3, 4});
        int t5 = qwe[5][1];
    }
    //map
    {
        //사용하는 곳: 빈도수 카운팅 등
        map<string, int> m;
        m["apple"] = 3;
        m["apple"]++;
        m["chicken"] = 7;
        m["tank"] = 120;

        auto it = m.find("apple");
        string str = it->first;
        int x = it->second;

        it = m.find("banana");
        if (it == m.end())
            cout << "There is no banana\n";

        for (auto&p : m)
            cout << p.first << " " << p.second << " " << endl;
        unordered_map<int, int> um;
    }
    //pair
    {
        //벡터랑 같이 많이 씀 first, second 둘다 기준으로 정렬 가능 (값, 인덱스) 저장 이후 정렬 등
        vector<pair<int, int>> v;
        v.push_back({3,5});
        v.push_back({2,1});
        v.push_back({3, 1});
        sort(v.begin(), v.end()); //first 기준, first 값 같으면 second
        
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        }); //second 기준 정렬
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        }); //second 내림차순

        sort(v.begin(), v.end(), [](auto& a, auto& b){
            if (a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });

        int arr[5] = {10, 20, 30, 40, 50};
        //인덱스+값 저장
        vector<pair<int,int>> vec;
        for (int i= 0; i < sizeof(arr) / sizeof(int); i++)
            vec.push_back({i, arr[i]});

        sort(vec.begin(), vec.end(), [](auto& a, auto&b) {
            return a.first > b.first;
        });
        

    }
    //우선순위큐
    {
        priority_queue<int> pq;
        //최소힙(작은값 먼저 나오게)
        priority_queue<int, vector<int>, greater<int>> pq2;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq3;
        pq3.push({5,4});
        pq3.push({3,2});
        
        pair<int,int> x = pq3.top();
        pq3.pop();
        x = pq3.top();
        pq3.pop();

    }
    //셋
    {
        //중복 없고, 정렬되는 컨테이너 unordered set은 중복없고 정렬안되는 컨테이너
        set<int> s;
        s.insert(3);
        s.insert(1);
        s.insert(3);
        //s.erase(1);
        s.insert(54);
        s.insert(6);

        if (s.find(3) != s.end())
            cout << "3 is 존재\n";
        for (auto x : s)
            cout << x << "\n"; //항상 정렬되어있다

        //사용 패턴: 중복 제거, 정렬+유니크
        vector<int> v;
        v.push_back(3);
        v.push_back(3);
        v.push_back(3);
        v.push_back(3);
        v.push_back(2);
        v.push_back(3);
        v.push_back(1);
        v.push_back(2);
        v.push_back(2);
        set<int> s2(v.begin(), v.end()); //중복제거하고 정렬까지
    }
    //스트링
    {
        string str = "1003403204201203210231";
        str = "abcdefghiaaaaa";
        str[2] = 'x';
        str[3] = 'y';
        //특정 문자 제거
        str.erase(remove(str.begin(), str.end(), 'a'), str.end());
        int x = str[5];

        //int->string
        int t = 325;
        string str2 = to_string(t);
        str2 = str2 + "12";
        int t2 = stoi(str2);
    
    }   

    int z= -13;
    z = z>>3;
    char ct = 0b10000001;
    ct = ct << 1;

    // int arr[3][4] = {{1,2},{3,4,5,6},7,8}; //2차원 배열 초기화 {1,2,0,0,3,4,5,6,7,8};
    // int* ptr = arr[0]; //포인터로 연속적으로 배열 접근
    // ptr++;
    // ptr++;
    // ptr++;
    // ptr++;

    // //int *ptr2 = arr; //type error: int(*)[4] -> int*
    // int (*ptr3)[4] = arr;
    // int d = **ptr3+1;
    // d = ptr3[1][2];

    // //int **ptr4 = arr; //type error: int(*)[4] -> int**
    return 0;
}