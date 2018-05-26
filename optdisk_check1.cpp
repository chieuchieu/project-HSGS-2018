#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
typedef long long int file_id;

#define cin fin

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
    fstream fin ("optdisk.inp");
    fstream fout ("optdisk.out");

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

    // for (llint n = 1 ; n <= capacity ; n++)
    // cout << ((n % 10 == 1) ? to_string(n) : string ()) + " " << disk[n] << " " << ((n % 10 == 0) ? "\n" : ""); cout << endl;

    // now checking answer

    llint timing = 0;
    char directive; llint arg1, arg2, arg3;
    llint iteration = 0;
    while (fout >> directive >> arg1 >> arg2 >> arg3)
    {
    	// cin >> directive >> arg1 >> arg2 >> arg3;
    	// char directive; llint arg1, arg2, arg3;
    	// sscanf(str.c_str(), &directive, &arg1, &arg2, &arg3);
        if (directive == copy_directive)
        {
        	vector <file_id> buffer;
	        for (llint i = 1 ; i <= arg3 ; i++)
	        {
	            buffer.push_back(disk[arg1 + i - 1]);
	            disk[arg1 + i - 1] = 0;
	        }
	        for (llint i = 1 ; i <= arg3 ; i++) disk[arg2 + i - 1] = buffer[i - 1];
	        timing += arg3;
        }
    	if (directive == swap_directive)
    	{
    		vector <file_id> buffer;
    		for (llint i = 1 ; i <= arg3 ; i++) buffer.push_back(disk[arg1 + i - 1]);
    		for (llint i = 1 ; i <= arg3 ; i++) swap(buffer[i - 1], disk[arg2 + i - 1]);
    		for (llint i = 1 ; i <= arg3 ; i++) disk[arg1 + i - 1] = buffer[i - 1];
    		timing += (arg3 << 1);
    	}
    	// cout << "Iteration " << ++iteration << endl;
    	// for (llint n = 1 ; n <= capacity ; n++)
    	// cout << ((n % 10 == 1) ? to_string(n) : string ()) + " " << disk[n] << " " << ((n % 10 == 0) ? "\n" : ""); cout << endl;
    }

    bool out = true;
    unordered_set <llint> st;
    vector <llint> sorted;
    for (llint i = 1 ; i <= capacity; i++)
    {
    	if (!disk[i])
    	{
    		break;
    	}
    	else
    	{
    		if (!st.count(disk[i]))
    		{
    			sorted.push_back(disk[i]);
    			st.insert(disk[i]);
    		}
    	}
    }

    // for (llint i = 1 ; i <= capacity ; i++)
    // cout << disk[i] << " " << ((i % 10 == 0) ? "\n" : ""); cout << endl;

    if (st.size() == fileCount && is_sorted(sorted.begin(), sorted.end())) cout << "Ok, correct answer!\n1.0\n"; else cout << "Wrong answer\n0.0\n";
}
