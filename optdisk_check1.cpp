#include <bits/stdc++.h>
using namespace std;

typedef long long int llint;
typedef long long int file_id;

vector <file_id> disk;

inline void fill_disk (llint file_id, llint first_cluster, llint spanning_length)
{
    for (llint i = 1 ; i <= spanning_length ; i++)
    {
        disk[first_cluster + i - 1] = file_id;
    }
}

inline void doNothing()
{
	return;
}

const char swap_directive = 'Z';
const char copy_directive = 'K';

int main()
{
    // fstream fin ("optdisk.inp");
    // fstream fout ("optdisk.out");

    string testDirectory;
    getline(cin, testDirectory);
    
    string outDirectory;
    getline(cin, outDirectory);

    fstream fin (testDirectory + "optdisk.inp");
    fstream fout (outDirectory + "optdisk.out");
    fstream answer (testDirectory + "optdisk.ans");


    llint capacity; fin >> capacity;
    llint fileCount; fin >> fileCount;

    disk.resize(capacity + 1);

    for (llint i = 1 ; i <= fileCount ; i++)
    {
        llint id, fragmentCount; fin >> id >> fragmentCount;
        
        for (llint i = 1 ; i <= fragmentCount ; i++)
        {
            llint first_cluster, spanning_length;
            fin >> first_cluster >> spanning_length;
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
    	// fin >> directive >> arg1 >> arg2 >> arg3;
    	// char directive; llint arg1, arg2, arg3;
    	// sscanf(str.c_str(), &directive, &arg1, &arg2, &arg3);
    	if (arg1 + arg3 - 1 > capacity || arg2 + arg3 - 1 > capacity)
    		return (printf("Wrong answer :: Output error: Out of bounds\n0.0\n") && 0);

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
        else
    	if (directive == swap_directive)
    	{
    		vector <file_id> buffer;
    		for (llint i = 1 ; i <= arg3 ; i++) buffer.push_back(disk[arg1 + i - 1]);
    		for (llint i = 1 ; i <= arg3 ; i++) swap(buffer[i - 1], disk[arg2 + i - 1]);
    		for (llint i = 1 ; i <= arg3 ; i++) disk[arg1 + i - 1] = buffer[i - 1];
    		timing += (arg3 << 1);
    	}
    	else return (printf("Wrong answer :: Output is in invalid format\n0.0\n") && 0);
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

    if (st.size() == fileCount && is_sorted(sorted.begin(), sorted.end())) 
    	doNothing();
    else 
    	return (printf("Wrong answer :: Disk is not optimal\n0.0\n") && 0);

    // checking answer from judge's answer

    char ans_directive; llint aarg1, aarg2, aarg3;

    // reset contestant's answer stream
    // fout.close();
    // fout.open(outDirectory + "optdisk.out");

    llint ans_timing = 0;
    while (answer >> ans_directive >> aarg1 >> aarg2 >> aarg3)
    {
    	if (ans_directive == copy_directive) ans_timing += aarg3;
    	if (ans_directive == swap_directive) ans_timing += (aarg3 << 1);
    }

    if (ans_timing == timing) cout << "Ok, right answer!\n1.0\n";
    else cout << "Wrong answer :: Total execution time is not optimal\n0.0\n";
}
