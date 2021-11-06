#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

class el{
public:
	int num, idx;
	el(int num, int idx): num(num), idx(idx) {}
	friend bool operator<(el &a, el &b){
		return a.num < b.num;
	}
};

int calc_moves(vector<el> &elements, int pos){
	int res = 0;
	if((size_t)pos != 0 && elements[pos].idx < elements[pos-1].idx)
		res++;
	if((size_t)pos != elements.size() - 1 && elements[pos].idx > elements[pos+1].idx)
		res++;
	return res;
}

int calc_moves_wide(vector<el> &elements, int pos){
	int res = 0;
	if((size_t)pos != 0 && elements[pos].idx < elements[pos-1].idx)
		res++;
	if( elements[pos].idx > elements[pos+1].idx)
		res++;
	if((size_t)(pos + 1) != elements.size() - 1 && elements[pos+1].idx > elements[pos+2].idx)
		res++;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<el> elements;
	vector<int> orig;
	for(int i = 0 ; i < n; i++){
		int t; cin >> t; t--;
		elements.push_back({t, i});
		orig.push_back(t);
	}
	sort(elements.begin(), elements.end());
	
	int total_moves = 1;
	for(unsigned int i = 1; i < elements.size(); i++)
		if(elements[i].idx < elements[i-1].idx)
			total_moves++;
	
	for(int i = 0; i < m; i++){
		int t_1, t_2;
		cin >> t_1 >> t_2;
		if(t_1 > t_2)
			swap(t_1, t_2);
			
		t_1--; t_2--;
		int from = orig[t_1];
		int to = orig[t_2];
		orig[t_1] = to; orig[t_2] = from;
		
		int m_1, m_2, m_1n, m_2n;

		if(abs(from - to) > 1){
			m_1 = calc_moves(elements, from);
			m_2 = calc_moves(elements, to);
			elements[from].idx = t_2;
			elements[to].idx = t_1;
			
			m_1n = calc_moves(elements, from);
			m_2n = calc_moves(elements, to);
			total_moves += m_1n - m_1;
			total_moves += m_2n - m_2;
		}else{
			m_1 = calc_moves_wide(elements, min(from, to));
			elements[from].idx = t_2;
			elements[to].idx = t_1;
			
			m_1n = calc_moves_wide(elements, min(from, to));
			total_moves += m_1n - m_1;
		}
		cout << total_moves << endl;
	}
	return 0;
}
