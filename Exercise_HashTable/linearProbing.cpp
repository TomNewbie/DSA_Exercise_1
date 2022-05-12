#include <cmath>
#include <iostream>
#include <list>
#include <string>
using namespace std;

struct phoneData {
    string name;
    string phoneNumber;
    phoneData(string name, string phoneNumber)
        : name{name}, phoneNumber{phoneNumber} {}
};
template <int N>
class HashMap {
private:
    // phoneData data;
    phoneData *phoneBook[N];
    int Hash(string name)
    {
        int sum = 0;
        for (int i = 0; i < name.length(); i++) {
            sum += (int)name[i] % N;
        }
        return sum % N;
    }

public:
    HashMap()
    {
        for (int i = 0; i < N; i++) {
            phoneBook[i] = nullptr;
        }
    }
    void Insert(string key, string phoneNumber)
    {
        phoneData *data = new phoneData(key, phoneNumber);
        int hashData = Hash(key);
        int i = 0;
        while (i < N) {
            i++;
            if (phoneBook[hashData] == nullptr) {
                phoneBook[hashData] = data;
                return;
            }
            else {
                hashData = (hashData + 1) % N;
            }
        }
        cout << "Data is full please allocate more memory!" << endl;
    }
    void Search(string key)
    {
        int hashData = Hash(key);
        int i = 0;
        while (i < N) {
            i++;
            if (phoneBook[hashData] == nullptr)
                break;
            if (phoneBook[hashData]->name == key) {
                cout << "Data found: " << endl;
                cout << "Name: " << phoneBook[hashData]->name << "  Phone number: " << phoneBook[hashData]->phoneNumber << endl;
                cout << "-------------------\n";
                return;
            }
            else {
                hashData = (hashData + 1) % N;
            }
        }
        cout << "Data " << key << " not found!" << endl;
        cout << "-------------------\n";
    }
    void DeleteKey(string key)
    {
        int hashData = Hash(key);
        int i = 0;
        while (i < N) {
            i++;
            if (phoneBook[hashData] == nullptr)
                break;
            if (phoneBook[hashData]->name == key) {
                phoneBook[hashData] = nullptr;
                cout << "Data deleted successfully!" << endl;
                return;
            }
            else {
                hashData = (hashData + 1) % N;
            }
        }
        cout << "Data not found to delete!" << endl;
    }
    void Display()
    {
        for (int i = 0; i < N; i++) {
            cout << "Data " << i << ": ";
            if (phoneBook[i] == nullptr) {
                cout << endl;
                continue;
            }
            cout << phoneBook[i]->name << " " << phoneBook[i]->phoneNumber;
            cout << endl;
        }
        cout << endl
             << "--------------- \n";
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

    thobook.Search("thanh ga");
    thobook.Search("th");
    thobook.Display();
    thobook.DeleteKey("Somi");
    thobook.Display();
    cout << "finish";
    return 0;
}