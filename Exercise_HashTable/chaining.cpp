#include <cmath>
#include <iostream>
#include <list>
#include <string>
using namespace std;

struct phoneData {
    string name;
    string phoneNumber;
    phoneData(string name, string phoneNumber) : name{name}, phoneNumber{phoneNumber} {}
};
template <int N>
class HashMap {
private:
    // phoneData data;
    list<phoneData *> phoneBook[N];
    int Hash(string name)
    {
        int sum = 0;
        for (int i = 0; i < name.length(); i++) {
            sum += (int)name[i] % N;
        }
        return sum % N;
    }

public:
    void Insert(string key, string phoneNumber)
    {
        phoneData *data = new phoneData(key, phoneNumber);
        int hashData = Hash(key);
        phoneBook[hashData].push_front(data);
    }
    void Search(string key)
    {
        int hashData = Hash(key);
        for (auto data : phoneBook[hashData]) {
            if (data->name == key) {
                cout << "Data found: " << endl;
                cout << "Name: " << data->name << "  Phone number: " << data->phoneNumber << endl;
                return;
            }
        }
        cout << "Data " << key << " not found!" << endl;
    }
    void DeleteKey(string key)
    {
        int hashData = Hash(key);
        for (auto data : phoneBook[hashData]) {
            if (data->name == key) {
                phoneBook[hashData].remove(data);
                cout << "Delete data " << key << " succesfully!" << endl;
                return;
            }
        }
        cout << "Data not found to delete!" << endl;
    }
    void Display()
    {
        for (int i = 0; i < N; i++) {
            cout << "bucket " << i << " ---> ";
            for (auto data : phoneBook[i]) {
                cout << data->name << ": " << data->phoneNumber;
                if (data != phoneBook[i].back()) {
                    cout << " ---> ";
                }
            }
            cout << endl;
        }
        cout << "--------------" << endl;
    }
};

int main()
{
    HashMap<10> thobook;
    thobook.Insert("Tho", "090312231");
    thobook.Insert("thanh ga", "021321312");
    thobook.Insert("Quan gar", "21321321");
    thobook.Insert("Somi", "21321321");
    thobook.Insert("Nam", "69696321");
    thobook.Insert("Nghi", "1234521");
    thobook.Display();
    thobook.Search("thanh ga");
    thobook.Search("th");
    thobook.Display();
    thobook.DeleteKey("Somi");
    thobook.Display();
    cout << "finish";
    return 0;
}