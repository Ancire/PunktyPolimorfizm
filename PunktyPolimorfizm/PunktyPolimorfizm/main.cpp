#include "naglowek.h"

using namespace std;

int main()
{

	cout << "\n";
	vector<string> punkty;
	punkty = getRawData();
	cout << "Dane z pliku:\n";
	for (int i = 0; i < punkty.size(); i++)
	{
		cout << punkty[i] << endl;
	}

	
	
	system("pause");
	return 0;
}