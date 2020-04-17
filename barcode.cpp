// Interleaved 2of5
// Caleb Rudder
// This programs reads in integers and returns the string version of a barcode
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void convertToText(string&, string&);
void interleave(string&, string&);

void main() {
	ifstream fin("barcode.in");
	if (fin.is_open()) {
		ofstream fout("barcode.out");

		string barcodeIn;
		string startSequence = "NnNn";
		string endSequence = "WnN";

		fin >> barcodeIn;

		while (barcodeIn != "0") {

			string barcodeText;
			string barcodeOut = "";

			convertToText(barcodeIn, barcodeText);
			interleave(barcodeText, barcodeOut);

			fout << startSequence << barcodeOut << endSequence << endl;

			//cout << "Number: " << barcodeIn << " barcode text: " << barcodeText << " Interleaved: " << barcodeOut << endl;

			fin >> barcodeIn;
		}

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}

void convertToText(string &barcodeIn, string &barcodeText) {

	string zero = "nnwwn";
	string one = "wnnnw";
	string two = "nwnnw";
	string three = "wwnnn";
	string four = "nnwnw";
	string five = "wnwnn";
	string six = "nwwnn";
	string seven = "nnnww";
	string eight = "wnnwn";
	string nine = "nwnwn";

	if (barcodeIn.size() % 2 != 0) {
		barcodeText = zero;
	}

	for (int i = 0; i < barcodeIn.size(); i++) {
		
			if (barcodeIn[i] == '0') {
				barcodeText = barcodeText + zero;
			}
			if (barcodeIn[i] == '1') {
				barcodeText = barcodeText + one;
			}
			if (barcodeIn[i] == '2') {
				barcodeText = barcodeText + two;
			}
			if (barcodeIn[i] == '3') {
				barcodeText = barcodeText + three;
			}
			if (barcodeIn[i] == '4') {
				barcodeText = barcodeText + four;
			}
			if (barcodeIn[i] == '5') {
				barcodeText = barcodeText + five;
			}
			if (barcodeIn[i] == '6') {
				barcodeText = barcodeText + six;
			}
			if (barcodeIn[i] == '7') {
				barcodeText = barcodeText + seven;
			}
			if (barcodeIn[i] == '8') {
				barcodeText = barcodeText + eight;
			}
			if (barcodeIn[i] == '9') {
				barcodeText = barcodeText + nine;
			}
	}
}

void interleave(string &barcodeText, string &barcodeOut) {



	for (int i = 0; i < barcodeText.size(); i += 10) {

		string str1 = barcodeText.substr(i, 5);
		string str2 = barcodeText.substr((i + 5), 5);


			for (int j = 0; j < 10; j++) {

				if (j % 2 == 0) {

					barcodeOut = barcodeOut + str1[j/2];

				}
				else {
					int k = (j / 2) + .5;
					barcodeOut = barcodeOut + str2[k];
				}

			}
	}

	for (int i = 0; i < barcodeOut.size(); i++) {

		if (i % 2 == 0) {

			barcodeOut[i] = barcodeOut[i] -32;

		}

	}
}
