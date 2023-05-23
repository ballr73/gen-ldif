#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const string APP_VERSION = "v0.0.4";

// Function to generate a random 12-digit integer
int generateRandomUid() {
    return rand() % 1000000000000 + 1000000000000;
}

int main(int argc, char* argv[]) {
    if (argc != 2 && argc != 3) {
        cerr << "Usage: ./ldif_generator <count> <output_file>" << endl;
        return 1;
    }
    string arg1 = argv[1];
    // Check if the count and output file name arguments are provided
    if(argc == 2 && arg1 == "-v") {
        cout << "gen-ldif version " << APP_VERSION << "" << endl;
        return 1;
    }

    int count = atoi(argv[1]);
    string outputFileName = argv[2];

    // Seed the random number generator
    srand(time(nullptr));

    // Open the output file
    ofstream outfile(outputFileName);

    // Check if the file opened successfully
    if (!outfile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Generate the specified number of entries
    for (int i = 1; i <= count; i++) {
        int uid = generateRandomUid();

        outfile << "dn: uid=user" << i << ",ou=users,dc=example,dc=com" << endl;
        outfile << "cn: User" << i << endl;
        outfile << "sn: User" << i << endl;
        outfile << "uid: " << uid << endl;
        outfile << "userPassword: mysecretpassword" << endl;
        outfile << "mail: user" << i << "@example.com" << endl;
        outfile << "objectClass: inetOrgPerson" << endl;
        outfile << endl; // Add a blank line between entries

        cout << "Entry " << i << " written." << endl;
    }

    // Close the file
    outfile.close();

    cout << "Sample LDIF file with " << count << " entries generated successfully." << endl;

    return 0;
}
