#include "naglowek.h"

using namespace std;

int main()
{


	const string filePath = "C:/Users/grimb/source/repos/NewRepo/PunktyPolimorfizm/PunktyPolimorfizm/wektory.txt";
	cout << "\n";
	vector<string> punkty;
	vector<string> poprawne_punkty;

	punkty = getRawData(filePath);
	cout << "Dane z pliku:\n";
	for (int i = 0; i < punkty.size(); i++)
	{
		cout << punkty[i] << endl;
	}

	poprawne_punkty = correctData(punkty);

	//cout << "size " << poprawne_punkty.size() << endl;
	for (int i = 0; i < poprawne_punkty.size(); i++) {
		cout << poprawne_punkty[i] << endl;
	}

	//writeData();

	
	
	system("pause");
	return 0;
}