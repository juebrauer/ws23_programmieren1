#include <iostream>
#include <vector>
#include <string>

using namespace std;

void show_vector(string title, vector<int> v) 
{
    cout << title << " - ";
    
    /*
    for (long unsigned int i=0; i<v.size(); i++)
        cout << i << ":" << v[i] << "   ";
    
    for (auto it=v.begin();
         it != v.end();
         ++it)
    {
        cout << *it << "   ";
    }
    cout << endl;
    */

    for (auto& element : v) {
        cout << element << " ";
    }
    cout << endl;

}


auto foo(auto a, auto b)
{
    return 2*a+b*b;
}

int main()
{   
  

    cout << "foo(4,9)=" << foo(4,9) << endl;
    cout << "foo(4.2,9.3)=" << foo(4.2, 9.3) << endl;

   
    vector<int> v1 = {11,22,33,44};
    vector<int> v2;
    v2 = v1;

    v1.push_back()
    v1.push_back(55);
    v1.push_back( 66 );

    v2.pop_back();
    v2.resize(10, -1);
    v2.clear();

    cout << "Ist v2 leer? --> " << v2.empty() << endl;

    show_vector("v1", v1);
    show_vector("v2", v2);

    
    cout << endl;

}