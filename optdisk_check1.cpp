#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;

class cluster
{
    public:
    llint file_id = 0;
};

//#define cin fin
//#define cout fout

vector <cluster> disk;

void fill_disk (llint file_id, llint first_cluster, llint spanning_length)
{
    for (llint i = 1 ; i <= spanning_length ; i++)
    {
        disk[first_cluster + i - 1].file_id = file_id;
    }
}

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

    // now checking answer

    
}