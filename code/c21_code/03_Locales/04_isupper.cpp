import <iostream>;
import <locale>;

using namespace std;

int main()
{
	bool result{ isupper('�', locale{ "fr-FR" }) };
	cout << result << endl;
}
