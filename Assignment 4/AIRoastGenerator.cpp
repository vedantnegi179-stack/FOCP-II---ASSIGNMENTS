/*
 * AI Roast Generator
 * FOCP II - Assignment 4 (Vibe Coding)
 * 
 * This program takes a user's name and generates a funny roast
 * by randomly selecting from a list of roast templates.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include <algorithm> // for find()

using namespace std;

// Function to replace {name} placeholder with the actual name
string replaceName(string roastTemplate, string name) {
    string placeholder = "{name}";
    
    // Find where {name} appears in the template
    size_t position = roastTemplate.find(placeholder);
    
    // Keep replacing until no more {name} found
    while (position != string::npos) {
        roastTemplate.replace(position, placeholder.length(), name);
        position = roastTemplate.find(placeholder);
    }
    
    return roastTemplate;
}

int main() {
    // Seed random number generator with current time
    // This ensures different results each run (BUG FIX: without this, same roast every time)
    srand(time(0));

    // Store all roast templates in a vector
    vector<string> roastTemplates = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} submitted their assignment so late, the professor thought it was next semester's work.",
        "Scientists confirmed that {name}'s Wi-Fi disconnects automatically whenever an assignment is due.",
        "{name}'s compiler throws errors out of sympathy, not because of actual mistakes.",
        "{name} types so slowly that their 'Hello World' program took three coffee breaks to write.",
        "The only loop {name} understands is the one between their bed and the fridge.",
        "{name} once spent 2 hours debugging, only to realize the code wasn't even saved."
    };

    string name;

    cout << "========================================" << endl;
    cout << "       Welcome to AI Roast Generator    " << endl;
    cout << "========================================" << endl;
    cout << "Enter your name: ";
    getline(cin, name);  // getline handles names with spaces

    // Input validation - check if name is empty (BUG FIX: prevents crash on empty input)
    if (name.empty()) {
        cout << "You didn't even enter your name. That's the biggest roast of all." << endl;
        return 0;
    }

    // Pick a random roast template
    int randomIndex = rand() % roastTemplates.size();

    // Replace {name} with the actual name entered by user
    string finalRoast = replaceName(roastTemplates[randomIndex], name);

    // Display the roast
    cout << "\n🔥 Here's your roast, " << name << ":\n" << endl;
    cout << "\"" << finalRoast << "\"" << endl;
    cout << "\n========================================" << endl;
    cout << "        No offense, just vibes :)       " << endl;
    cout << "========================================" << endl;

    return 0;
}
