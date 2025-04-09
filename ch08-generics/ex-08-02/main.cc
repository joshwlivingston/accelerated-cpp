#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "algorithms.h"

using std::back_insert_iterator;
using std::back_inserter;
using std::cin;
using std::cout;
using std::endl;
using std::isspace;
using std::string;
using std::vector;

bool is_j(const string &s)
{
    string::const_iterator begin = s.begin();
    return *begin == 'j' && ++begin == s.end();
}

int main()
{

    // equal(b, e, d)
    string x;
    vector<string> vec_1;
    vector<string> vec_2;
    cout << "equal() test. input first vector, "
            "then \"next\" to input next vector. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "next" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "Input second vector, then \"end\" to stop" << endl;
        while (cin >> x)
            if (x != "end")
                vec_2.push_back(x);
            else
                break;
        cout << ex0802::equal<
                    vector<string>::const_iterator,
                    vector<string>::const_iterator>(
                    vec_1.begin(), vec_1.end(), vec_2.begin())
             << endl;
    }

    // search(b, e, b2, e2)
    vec_1.clear();
    vec_2.clear();
    cout << "search() test. input first vector, "
            "then \"next\" to input search vector. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "next" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "Input search vector, then \"end\" to stop" << endl;
        while (cin >> x)
            if (x != "end")
                vec_2.push_back(x);
            else
                break;
        cout << *ex0802::search<
                    vector<string>::const_iterator,
                    vector<string>::const_iterator>(
                    vec_1.begin(), vec_1.end(), vec_2.begin(), vec_2.end())
             << endl;
    }

    // find(b, e, t)
    vec_1.clear();
    vec_2.clear();
    cout << "find() test. input first vector, "
            "then \"next\" to input match string. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "next" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "Input match string." << endl;
        cin >> x;
        const vector<string>::const_iterator res = ex0802::find<
            vector<string>::const_iterator, string>(
            vec_1.begin(), vec_1.end(), x);
        if (res != vec_1.end())
            cout << endl
                 << *res << endl;
    }

    // find_if(b, e, p)
    vec_1.clear();
    vec_2.clear();
    cout << "find_if() test. searching for j's. "
            "input vector, then \"end\" to stop. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "end" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "Searching for j's..." << endl;
        const vector<string>::const_iterator res = ex0802::find_if<
            vector<string>::const_iterator, string>(
            vec_1.begin(), vec_1.end(), is_j);
        if (res != vec_1.end())
            cout << "found one!" << endl;
        else
            cout << "No j's found ://" << endl;
    }

    // copy(b, e, d)
    vec_1.clear();
    vec_2.clear();
    cout << "copy() test. "
            "input vector, then \"end\" to stop. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "end" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "destination vector:" << endl;
        ex0802::copy<
            vector<string>::const_iterator, back_insert_iterator<vector<string>>>(
            vec_1.begin(), vec_1.end(), back_inserter(vec_2));
        vector<string>::const_iterator copied_entry = vec_2.begin();
        while (copied_entry != vec_2.end())
            cout << *copied_entry++ << endl;
    }

    // remove_copy(b, e, d, t)
    vec_1.clear();
    vec_2.clear();
    cout << "remove_copy() test. checking for j's "
            "input vector, then \"end\" to stop. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "end" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "destination vector:" << endl;
        ex0802::remove_copy<
            vector<string>::const_iterator,
            back_insert_iterator<vector<string>>,
            string>(
            vec_1.begin(), vec_1.end(), back_inserter(vec_2), "j");
        vector<string>::const_iterator copied_entry = vec_2.begin();
        while (copied_entry != vec_2.end())
            cout << *copied_entry++ << endl;
    }

    // remove_copy_if(b, e, d, p)
    vec_1.clear();
    vec_2.clear();
    cout << "remove_copy_if() test. checking for j's "
            "input vector, then \"end\" to stop. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "end" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "destination vector:" << endl;
        ex0802::remove_copy_if<
            vector<string>::const_iterator,
            back_insert_iterator<vector<string>>,
            string>(
            vec_1.begin(), vec_1.end(), back_inserter(vec_2), is_j);
        vector<string>::const_iterator copied_entry = vec_2.begin();
        while (copied_entry != vec_2.end())
            cout << *copied_entry++ << endl;
    }

    // remove(b, e, t)
    vec_1.clear();
    vec_2.clear();
    cout << "remove() test. checking for j's "
            "input vector, then \"end\" to stop. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "end" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "new vector:" << endl;
        vector<string>::iterator new_end = ex0802::remove<
            vector<string>::iterator, string>(
            vec_1.begin(), vec_1.end(), "j");
        vector<string>::iterator new_start = vec_1.begin();
        while (new_start != new_end)
            cout << *new_start++ << endl;
    }

    // transform(b, e, d, f)
    vec_1.clear();
    vec_2.clear();
    cout << "transform() test. checking for j's. "
            "input vector, then \"end\" to stop. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "end" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        vector<bool> vec_3;
        cout << "destination vector:" << endl;
        ex0802::transform<
            vector<string>::const_iterator,
            back_insert_iterator<vector<bool>>,
            string,
            bool>(
            vec_1.begin(), vec_1.end(), back_inserter(vec_3), is_j);
        vector<bool>::const_iterator copied_entry = vec_3.begin();
        while (copied_entry != vec_3.end())
            cout << *copied_entry++ << endl;
        vec_3.clear();
    }

    // partition(b, e, p)
    vec_1.clear();
    vec_2.clear();
    cout << "partition() test. sorting by j's "
            "input vector, then \"end\" to stop. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
        if (x != "end" && x != "pass")
            vec_1.push_back(x);
        else
            break;

    cout << endl;
    if (x != "pass")
    {
        cout << "partitioned vector:" << endl;
        ex0802::partition<vector<string>::iterator, string>(
            vec_1.begin(), vec_1.end(), is_j);
        vector<string>::iterator new_start = vec_1.begin();
        while (new_start != vec_1.end())
            cout << *new_start++ << endl;
    }

    // accumulate(b, e, t)
    vec_1.clear();
    vec_2.clear();
    cout << "accumulate() test. "
            "input vector, then \"end\" to stop. "
            "\"pass\" to skip."
         << endl;
    while (cin >> x)
    {
        if (x != "pass" && x != "end")
            vec_1.push_back(x);
        else
            break;
    }

    cout << endl
         << "Accumulated string:" << endl
         << ex0802::accumulate<
                vector<string>::const_iterator, string>(
                vec_1.begin(), vec_1.end(), "")
         << endl;
    return 0;
}
