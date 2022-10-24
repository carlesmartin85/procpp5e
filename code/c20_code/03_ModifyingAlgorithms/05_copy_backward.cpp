import <algorithm>;
import <vector>;
import <iostream>;

using namespace std;

// Function template to populate a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
	while (true) {
		cout << "Enter a number (0 to quit): ";
		int value;
		cin >> value;
		if (value == 0) {
			break;
		}
		cont.push_back(value);
	}
}

int main()
{
	vector<int> vec1, vec2;

	populateContainer(vec1);

	vec2.resize(size(vec1));

	copy_backward(cbegin(vec1), cend(vec1), end(vec2));

	for (const auto& i : vec2) { cout << i << " "; }
}
