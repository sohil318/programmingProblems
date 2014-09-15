#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

int main() {
    std::locale loc;
    int i = 0, count, c1, out;
    ifstream myReadFile;
    myReadFile.open("text.txt");
    string search, *output;
    if (myReadFile.is_open()) {
        if (!myReadFile.eof())
        {
            myReadFile >> search;
            for (int k=0; k<search.length(); ++k)
                search[k] = tolower(search[k],loc);
            cout << "Search String : " << search << "\n"; 
        }
        while (!myReadFile.eof()) {
            myReadFile >> output[i];
            i++;
            cout<<output[i];
            //cout << "My endl" << endl;
        }
    }
    myReadFile.close();
    count = 0;
    for ( int j = 0; j < i; j++)
    {
        size_t found = output[j].find(search);
        if (found != -1)
        {
            //cout << output[j] << endl;
            count++;
            if (output[j].compare(search) == 0)
                c1++;
            if (count == 1)
                out = j;
        }
    }
    cout << c1 << ";" << count << ";" << output[out];
    return 0;
}

