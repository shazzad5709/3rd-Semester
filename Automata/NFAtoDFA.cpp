#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// Input Variable
vector<vector<string>> tt;
vector<string> states;
vector<string> alphabets;
string startState;

// Output Variables
vector<pair<string, vector<string>>> dfa;
vector<pair<string, bool>> completed;

// Function Prototype
void input();
void printOutput();
void createStateTransitions(string state);
string unite(vector<string> storeState);
string fetch(char c, int alphabet);
bool isCompleted(string state);
void printDFA();

int main()
{
    input();
    printOutput();
    createStateTransitions(startState);
    printDFA();
    return 0;
}

void input()
{
    int statesNo, alphabetNo;
    string state;

    cout << "Number of states: ";
    cin >> statesNo;
    cout << "Enter states: ";

    for (int i = 0; i < statesNo; i++)
    {
        cin >> state;
        states.push_back(state);
    }

    cout << "Number of alphabets: ";
    cin >> alphabetNo;
    cout << "Enter alphabets: ";
    string alphabet;

    for (int i = 0; i < alphabetNo; i++)
    {
        cin >> alphabet;
        alphabets.push_back(alphabet);
    }

    cout << "Enter NFA transition table:(NO COMMA ALLOWED!)\n";
    for (int i = 0; i < states.size(); i++)
    {
        vector<string> rowStates;
        for (int j = 0; j < alphabets.size(); j++)
        {

            cin >> state;
            rowStates.push_back(state);
        }
        tt.push_back(rowStates);
    }

    cout << "Enter start state: ";
    cin >> startState;
}

void printOutput()
{
    cout << "States are: ";
    for (int i = 0; i < states.size(); i++)
        cout << states[i] << " ";
    cout << endl;
    cout << "Alphabets are: ";
    for (int i = 0; i < alphabets.size(); i++)
        cout << alphabets[i] << " ";
    cout << endl;

    cout << "Transition table is:" << endl;
    for (int i = 0; i < states.size(); i++)
    {
        cout << states[i] << ": ";
        for (int j = 0; j < alphabets.size(); j++)
        {
            cout << tt[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Start state: " << startState;
    cout << endl;
}
bool isCompleted(string state)
{
    for (int i = 0; i < completed.size(); i++)
    {
        if (completed[i].first == state)
            return completed[i].second;
    }
    return false; // the state has not been created yet.
}

string fetch(char c, int alphabet)
{
    string s(1, c);
    int stateIndex = 0;
    for (int i = 0; i < states.size(); i++)
        if (states[i] == s)
        {
            stateIndex = i;
            break;
        }

    return tt[stateIndex][alphabet];
}

string unite(vector<string> storeState)
{
    // Splitting all combined states into characters
    set<char> splitStates;
    for (int i = 0; i < storeState.size(); i++)
    {
        if (storeState[i] == "NULL")
            continue;
        for (int j = 0; j < storeState[i].size(); j++)
        {
            splitStates.insert(storeState[i][j]);
        }
    }

    // Building the new state
    string newState = "";
    for (auto element : splitStates)
        newState += element;
    return newState;
}

void createStateTransitions(string state)
{
    if (isCompleted(state))
        return;

    vector<string> dfaRow;
    for (int a = 0; a < alphabets.size(); a++)
    {
        vector<string> storeState;
        for (int w = 0; w < state.size(); w++)
        {
            storeState.push_back(fetch(state[w], a));
        }
        string newState = unite(storeState);
        dfaRow.push_back(newState);
    }

    dfa.push_back(make_pair(state, dfaRow));
    completed.push_back(make_pair(state, true));

    // Now recursively call new states
    for (int i = 0; i < dfaRow.size(); i++)
        if (dfaRow[i] != "NULL")
            createStateTransitions(dfaRow[i]);
}

void printDFA()
{
    cout << "DFA transition table:\n";
    for (int i = 0; i < dfa.size(); i++)
    {
        cout << dfa[i].first << ": ";
        for (int j = 0; j < dfa[i].second.size(); j++)
        {
            cout << dfa[i].second[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}