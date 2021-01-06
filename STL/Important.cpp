#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << '=' << x << endl
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6 + 13, M = N;
//=======================
vi g[N];
int a[N];
int i, n, m, k;
//=======================

/**
 * @brief Some important functions you can 
 * directly add into your code
 * 
 */
ll Max = LLONG_MAX;

void Vectors()
{
    vi A;
    A = {1, 6, 8, 3, 9, 5}; // declaring a set of elements to the vctor

    fo(i, 10) A.push_back(i); // to add elements

    fo(i, 16) cout << A[i] << " ";

    for (auto i = A.begin(); i != A.end(); i++) // auto acts as an iterator
        cout << *i << " ";

    sort(A.begin(), A.end()); // O(NlogN) sorting the vector A

    sort(A.begin(), A.end(), greater<ll>()); //Sorting in decreasing order

    // prints the vector size
    cout << "\nSize : " << A.size();

    cout << "\nReference operator [g] : g1[2] = " << A[2];

    cout << "\nat : g1.at(4) = " << A.at(4);

    cout << "\nfront() : g1.front() = " << A.front();

    cout << "\nback() : g1.back() = " << A.back();

    cout << "\nOutput of begin and end: ";
    for (auto i = A.begin(); i != A.end(); i++)
    { // auto acts as an iterator

        cout << *i << " "; // printing out the elements of the iterator using *

        if (i == A.end() - 1)
            cout << endl; // new line after the vector ends..... You can also end the loop here using break
    }
    int sum1 = accumulate(A.begin(), A.end(), 0); // to get the sum of all elements in vector

    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = A.rbegin(); ir != A.rend(); ++ir)
        cout << *ir << " ";
    cout << endl;
    deb(i);

    bool present = binary_search(A.begin(), A.end(), 3); // true
    present = binary_search(A.begin(), A.end(), 45);     // false
    deb(present);
    fo(i, 2) A.push_back(9);

    auto it = lower_bound(A.begin(), A.end(), 9);
    auto it2 = upper_bound(A.begin(), A.end(), 9);
    cout << *it << " " << *it2 << endl;
    deb(it2 - it);

    cout << it - A.begin() << endl; // to print the value of an iterator you have to do an arithmatic operation

    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

void pairDemo()
{

    int a, b, i, j;
    cin >> n;
    vector<pair<int, int>> vect;
    fo(i, n)
    {
        cin >> a >> b;
        vect.push_back(make_pair(a, b));
    }
    // Using sort() function to sort by 1st  element
    // of pair
    sort(vect.begin(), vect.end());
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        Vectors();
    }

    return 0;
}
//=======================