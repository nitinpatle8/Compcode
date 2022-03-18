#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (ll i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	ll x1 = b[0] - a[0], op2 = 0;
	ll res1 = 0, res2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (x1 + op2 < b[i] - a[i])
		{
			op2 += ((b[i] - a[i]) - x1 - op2);
		}
		else if (x1 + op2 > b[i] - a[i])
		{
			x1 -= (x1 + op2 - (b[i] - a[i]));
		}

		if (x1 < 0 || op2 > (b[n - 1] - a[n - 1]))
		{
			res1 = -1;
			res2 = 0;
			break;
		}

		res1 = max(res1, x1);
		res2 = max(res2, op2);
	}

	ll res = res1 + res2;

	cout << res << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}