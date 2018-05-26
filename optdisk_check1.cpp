#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
typedef long long int file_id;

//#define cin fin
//#define cout fout

vector <file_id> disk;

inline void fill_disk (llint file_id, llint first_cluster, llint spanning_length)
{
    for (llint i = 1 ; i <= spanning_length ; i++)
    {
        disk[first_cluster + i - 1] = file_id;
    }
}

const char swap_directive = 'Z';
const char copy_directive = 'K';

int main()
{
    //fstream fin ("optdisk.inp");
    //fstream fout ("optdisk.out");

    llint capacity; cin >> capacity;
    llint fileCount; cin >> fileCount;

    disk.resize(capacity + 1);

    for (llint i = 1 ; i <= fileCount ; i++)
    {
        llint id, fragmentCount; cin >> id >> fragmentCount;
        
        for (llint i = 1 ; i <= fragmentCount ; i++)
        {
            llint first_cluster, spanning_length;
            cin >> first_cluster >> spanning_length;
            fill_disk(id, first_cluster, spanning_length);
        };
    }

    // input processing done!

    for (llint i = 1 ; i <= capacity ; i++)
    cout << disk[i] << " " << ((i % 10 == 0) ? "\n" : ""); cout << endl << endl << endl;

    // now checking answer

    //llint timing = 0;
    char directive; llint arg1, arg2, arg3;
    //while 
    (cin >> directive >> arg1 >> arg2 >> arg3);
    

    vector <file_id> buffer;
    for (llint i = 1 ; i <= arg3 ; i++) buffer.push_back(disk[arg1 + i - 1]);
    for (llint i = 1 ; i <= arg3 ; i++) disk[arg2 + i - 1] = buffer[i - 1];

    for (llint i = 1 ; i <= capacity ; i++)
    cout << disk[i] << " " << ((i % 10 == 0) ? "\n" : ""); cout << endl;
}