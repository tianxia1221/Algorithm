
vector<int> cellCompete(int* states, int days)
{
	vector<int> t(10, 0);
	vector<int> t1(10, 0);
	vector<int> *pt = &t;
	vector<int> *pt1 = &t1;
	vector<int> *tmp;
	vector<int> ret(8);
	for (int i = 0; i < 8; i++) {
		t[i + 1] = states[i];
		t1[i + 1] = states[i];
	}

	for (int j = 0; j < days; j++) {
		for (int i = 1; i < 9; i++) {
			(*pt1)[i] = (*pt)[i - 1] ^ (*pt)[i + 1];
		}
		tmp = pt;
		pt = pt1;
		pt1 = tmp;
	}

	for (int i = 0; i < 8; i++) {
		ret[i] = (*pt)[i + 1];
	}

	return ret;

}
