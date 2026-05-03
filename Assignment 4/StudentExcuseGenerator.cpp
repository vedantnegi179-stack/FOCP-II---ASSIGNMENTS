/*
 * Student Excuse Generator
 * FOCP II - Assignment 4 (Vibe Coding)
 *
 * This program takes a student's name and generates a creative excuse
 * for missing homework by randomly picking from a list of templates.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

// Function to replace all occurrences of {name} with the actual student name
string replaceName(string excuseTemplate, string name) {
    string placeholder = "{name}";

    // Find and replace {name} in the template
    size_t position = excuseTemplate.find(placeholder);

    // Loop until no more {name} placeholders are found (BUG FIX: replaces ALL occurrences)
    while (position != string::npos) {
        excuseTemplate.replace(position, placeholder.length(), name);
        position = excuseTemplate.find(placeholder);
    }

    return excuseTemplate;
}

int main() {
    // Seed the random number generator using current time
    // (BUG FIX: without srand(time(0)), the same excuse repeats every run)
    srand(time(0));

    // Store all excuse templates in a vector
    vector<string> excuseTemplates = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} tried finishing the homework, but the internet stopped working at exactly 11:59 PM.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name} couldn't finish the assignment because the laptop decided to install updates for six hours.",
        "{name} was about to complete the homework when the Wi-Fi mysteriously vanished.",
        "{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.",
        "{name}'s dog ate the USB drive — and yes, the code was only saved there.",
        "{name} completed the assignment, but accidentally submitted last semester's file.",
        "{name} was about to submit when a power cut struck the entire neighborhood for 3 hours.",
        "{name} spent all night debugging the assignment, fixed it at 4 AM, and then accidentally closed without saving.",
        "{name} couldn't find the assignment portal — it kept logging out every 30 seconds.",
        "{name} had the assignment ready but the PDF corrupted itself during export, which is totally not {name}'s fault."
    };

    string name;

    cout << "============================================" << endl;
    cout << "      Welcome to Student Excuse Generator   " << endl;
    cout << "============================================" << endl;
    cout << "Enter your name: ";
    getline(cin, name);  // getline handles names with spaces

    // Input validation - handle empty name (BUG FIX: prevents weird output on empty input)
    if (name.empty()) {
        cout << "\nYou didn't enter a name. Even your identity is missing, just like your assignment." << endl;
        return 0;
    }

    // Select a random excuse
    int randomIndex = rand() % excuseTemplates.size();

    // Replace {name} placeholder with actual name
    string finalExcuse = replaceName(excuseTemplates[randomIndex], name);

    // Display the generated excuse
    cout << "\n📋 Excuse generated for " << name << ":\n" << endl;
    cout << "\"" << finalExcuse << "\"" << endl;
    cout << "\n============================================" << endl;
    cout << "    Good luck convincing your professor :)  " << endl;
    cout << "============================================" << endl;

    return 0;
}
