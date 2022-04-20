#include <iostream>
#include <fstream>
#include <string>
#include <csignal>
using namespace std;

int main (int ac, char **av) {
	string		line;
	string		s;

	if (ac == 1)
	{
		ifstream	myfile (av[1]);
		while (1)
		{
			cin >> s;
			if (s == "SIGINT")
				exit(0);
			cout << s << endl;
		}
		
	}
	else if (ac > 1)
	{
		int	gg = ac;
		int i = 1;
		while (i < ac)
		{
			ifstream	myfile (av[i]);
			if (myfile.is_open())
			{
				while ( getline (myfile,line) )
				{
					if (myfile.eof())
						cout << line;
					else
						cout << line << '\n';
				}
				myfile.close();
			}
			else
			{
				cout << "Error opening file";
				exit(1);
			}
			i++;
		}
	}
	else
		cout << "No such file or directory";
	return 0;
}