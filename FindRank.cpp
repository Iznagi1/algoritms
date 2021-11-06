int getDeter(vector<vector<int>> a, int pos) {
	if (a.size() == 0)
		return 0;
	assert(a.size() == a[0].size());

	if (a.size() == 1)
		return a[0][0];

	vector<vector<int>> kek = a;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		kek.erase(kek.begin());
		for (int j = 0; j < kek.size(); j++) {
			kek[j].erase(kek[j].begin() + i);
		}
		ans += a[0][i] * ((i) % 2 == 1 ? (-1) : 1) * getDeter(kek, pos+1);
		kek = a;
	}

	return ans;
}

int getRank(vector<vector<int>> a) {
	vector<vector<int>> checkIt;
	int ans = 0;
	for (int i = 0; i < (1 << ((int)a.size())); i++) {
		for (int j = 0; j < (1 << ((int)a[0].size())); j++) {
			if (__builtin_popcount(i) != __builtin_popcount(j))
				continue;

			int fir = i, sec = j;
			int r = 0;
			while (fir != 0) {
				if (fir % 2 == 1) {
					sec = j;
					vector<int> k;
					int p = 0;
					while (sec != 0) {
						if (sec % 2 == 1)
							k.pb(a[r][p]);
						sec /= 2;
						p++;
					}
					checkIt.pb(k);
				}
				r++;
				fir /= 2;
			}

			int kekos = checkIt.size();
			if (getDeter(checkIt, 0) != 0)
				ans = max(ans, kekos);
			checkIt = {};
		}
	}

	return ans;
}
