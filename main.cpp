#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// Function to generate a random 12-digit integer
int generateRandomUid() {
    return rand() % 1000000000000 + 1000000000000;
}

int main(int argc, char* argv[]) {
    // Check if the count and output file name arguments are provided
    if (argc != 3) {
        std::cerr << "Usage: ./ldif_generator <count> <output_file>" << std::endl;
        return 1;
    }

    int count = std::atoi(argv[1]);
    std::string outputFileName = argv[2];

    // Seed the random number generator
    srand(time(nullptr));

    // Open the output file
    std::ofstream outfile(outputFileName);

    // Check if the file opened successfully
    if (!outfile) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // Generate the specified number of entries
    for (int i = 1; i <= count; i++) {
        int uid = generateRandomUid();

        outfile << "dn: uid=user" << i << ",ou=users,dc=example,dc=com" << std::endl;
        outfile << "cn: User" << i << std::endl;
        outfile << "sn: User" << i << std::endl;
        outfile << "uid: " << uid << std::endl;
        outfile << "userPassword: mysecretpassword" << std::endl;
        outfile << "mail: user" << i << "@example.com" << std::endl;
        outfile << "objectClass: inetOrgPerson" << std::endl;
        outfile << std::endl; // Add a blank line between entries

        std::cout << "Entry " << i << " written." << std::endl;
    }

    // Close the file
    outfile.close();

    std::cout << "Sample LDIF file with " << count << " entries generated successfully." << std::endl;

    return 0;
}
