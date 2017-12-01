#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int PatternCount(string text, string pattern){
	int count=0;
	int length1 = text.length();
	int length2 = pattern.length();
	int k = 0;
	int l;

	for (int i = 0; i < (length1 - length2 + 1); i++){
		int j = 0;
		l = i;
		k = 0;
		while (j < length2){
			if (text[l] == pattern[j]){
				k++;
			}
			l++;
			j++;
		}
		if (k == length2){
			count++;
		}
	}
	return count;
}

int main(){
	
	FILE* file;
	string* str1= new string[2];
	file = fopen("input.txt", "rb");
	if (getc(file) == EOF){
		cout << "empty file";
		fclose(file);
	}
	else
	{	fclose(file);
		ifstream my_file("input.txt", ios_base::in);

		for (int i = 0; i < 2; i++) {
			getline(my_file, str1[i]);
		}

		int result = PatternCount(str1[0], str1[1]);
		ofstream new_file("output.txt");
		new_file << result;
		new_file.close();

	}
	delete[] str1;
	return 0;
}
