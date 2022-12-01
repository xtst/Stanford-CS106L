#include <iostream>		 // for cout, cin
#include <fstream>		 // for ifstream
#include <sstream>		 // for stringstream
#include <filesystem>	 // making inputting files easier
#include <unordered_set> // containers for the wikiscraper
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h" // wikiscraper methods

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::priority_queue;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::unordered_set;
using std::vector;

int main() {
	// a quick working directory fix to allow for easier filename inputs
	auto path = std::filesystem::current_path() / "res/";
	std::filesystem::current_path(path);
	std::string filenames = "Available input files: ";
	for (const auto &entry : std::filesystem::directory_iterator(path)) {
		std::string filename = entry.path().string();
		filename = filename.substr(filename.rfind("/") + 1);
		filenames += filename + ", ";
	}
	// omit last ", ".
	cout << filenames.substr(0, filenames.size() - 2) << "." << endl;

	/* Container to store the found ladders in */
	vector<vector<string>> outputLadders;

	cout << "Enter a file name: ";
	string filename;
	getline(cin, filename);

	ifstream file(filename);
	if (!file) {
		cout << "File not found." << endl;
		return 1;
	}
	int word_pair_num;
	file >> word_pair_num;
	for (int i = 1; i <= word_pair_num; i++) {
		string start_page, end_page;
		file >> start_page >> end_page;
		findWikiLadder(start_page, end_page);
		outputLadders.emplace_back(vector<string> s{start_page, end_page});
	}

	for (auto &it : outputLadders) {
		cout << it[0] << " " << it[1] << endl;
	}
	/*
		TODO: Create a filestream from the filename.
		For each pair {start_page, end_page} in the input file,
		retrieve the result of findWikiLadder(start_page, end_page)
		and append that vector to outputLadders.
	*/
	// Write code here

	/*
	 * Print out all ladders in outputLadders.
	 * We've already implemented this for you!
	 */
	// Write code here

	return 0;
}
