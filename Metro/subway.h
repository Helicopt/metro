#pragma once
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define maxE 4096
#define inf (1<<30)
#define transfer "»»³Ë"

namespace subway {

	using namespace std;

	typedef long long LL;
	typedef std::pair<int, int> PA;

	typedef struct station {
		std::string nm;
		double sx, sy;
		std::vector<int> trs;
	}St;

	typedef struct tran {
		int id, g[2], l;
	}Tr;

	typedef struct edge {
		int a, nxt, r, t;
	}E;

	typedef struct line {
		std::string nm;
		std::vector<int> d;
		int status;
	}L;

	struct Exc {
		std::string info;
		Exc(std::string info) : info(info) {}
		Exc(char* info) : info(string(info)) {}
	};

	enum planMode { pm_Short, pm_convi };

	class subway {

	private:
		std::string dataPath;
		std::map<std::string, int> mp;
		std::vector<St*> Stations;
		std::vector<Tr*> Trans;
		std::vector<L*> lines;
		E e[maxE];
		int tot, idn;

		std::vector<int> ansq;
		std::vector<std::string> log;
		PA lastAns;

		void addE(int x, int y, int r, int t) {
			++(this->tot);
			this->e[tot].a = y;
			this->e[tot].nxt = this->Trans[x]->g[t];
			this->e[tot].r = r;
			this->e[tot].t = t;
			this->Trans[x]->g[t] = this->tot;
		}

		int create_station(std::string nm, double x, double y) {
			int id;
			if (this->mp.find(nm) == this->mp.end()) {
				id = (int)this->Stations.size();
				St *S = new St();
				S->nm = nm;
				S->sx = x;
				S->sy = y;
				S->trs.clear();
				this->Stations.push_back(S);
				this->mp[nm] = id;
				return id;
			}
			else return this->mp[nm];
		}

		int add_station(std::string nm, int lno = -1, bool add = true) {
			int id, tid;
			if (this->mp.find(nm) != this->mp.end())
				id = this->mp[nm];
			else return -1;
			if (add) {
				tid = (int)this->Trans.size();
				Tr *T = new Tr();
				T->id = id;
				T->l = lno;
				T->g[0] = T->g[1] = 0;
				int cnt = (int)this->Stations[id]->trs.size();
				this->Stations[id]->trs.push_back(tid);
				this->Trans.push_back(T);
				for (int i = 0; i < cnt; ++i) {
					this->addE(this->Stations[id]->trs[i], tid, tot + 2, 1);
					this->addE(tid, this->Stations[id]->trs[i], tot, 1);
				}
				return tid;
			}
			else {
				int cnt = (int)this->Stations[id]->trs.size();
				for (int i = 0; i < cnt; ++i) {
					tid = this->Stations[id]->trs[i];
					if (this->Trans[tid]->l == lno) {
						return tid;
					}
				}
				return -1;
			}
		}

		int initialize(FILE *f) {
			char s[128];

			if (f == NULL) {
				throw new Exc("Map data cannot be loaded. (path: " + this->dataPath + ")");
				//fprintf_s(stderr,"map data cannot be loaded. (path: %s)\n",this->dataPath.c_str());
				//return 1;
			}
			int n;
			if (fscanf_s(f, "%d", &n) != 1) {
				throw new Exc("Bad File: excepted the number of stations in the beginning");
			}
			for (int i = 0; i < n; ++i) {
				if (fscanf_s(f, "%s", s, 64) != 1) {
					throw new Exc("Bad File: insufficient stations");
				}
				s[63] = '\0';
				this->create_station(std::string(s), 0, 0);
			}
			while (fscanf_s(f, "%s", s, 64) != EOF) {
				//fprintf_s(stderr, "dealing with %s\n", s);
				s[63] = '\0';
				L *aline = new L();
				aline->nm = std::string(s);
				aline->status = 0;
				aline->d.clear();
				int k;
				if (fscanf_s(f, "%d", &k) != 1) {
					throw new Exc(string("Bad File: excepted the number of stations of ") + s);
				}
				//fprintf_s(stderr, "loading %d stations\n", k);
				int tp = k < 0;
				k = abs(k);
				aline->status = tp;

				for (int i = 1; i <= k; ++i) {
					if (fscanf_s(f, "%s", s, 64) != 1) {
						throw new Exc(string("Bad File: lack stations of ") + s);
					}
					//fprintf_s(stderr, "dealing with %s\n", s);
					s[63] = '\0';
					bool ow = false;
					if (s[strlen(s) - 1] == '*') {
						s[strlen(s) - 1] = '\0';
						ow = true;
					}
					std::string tname(s);
					int id = this->add_station(s, (int)this->lines.size());
					if (id < 0) {
						throw new Exc(string("Can't find the station ") + tname);
					}
					aline->d.push_back(id);
					if (i > 1) {
						this->addE(aline->d[aline->d.size() - 2], aline->d[aline->d.size() - 1], ow ? 0 : (tot + 2), 0);
						if (ow == false)
							this->addE(aline->d[aline->d.size() - 1], aline->d[aline->d.size() - 2], tot, 0);
					}
				}
				if (tp) {
					if (fscanf_s(f, "%s", s, 64) != 1) {
						throw new Exc("Bad File: " + aline->nm + " is not a cycle");
					}
					s[63] = '\0';
					bool ow = false;
					if (s[strlen(s) - 1] == '*') {
						s[strlen(s) - 1] = '\0';
						ow = true;
					}
					int cyc = this->add_station(std::string(s), (int)this->lines.size(), false);
					if (cyc < 0) {
						throw new Exc("Bad File: " + aline->nm + " is not a cycle");
					}
					this->addE(aline->d.back(), cyc, ow ? 0 : (tot + 2), 0);
					if (ow == false)
						this->addE(cyc, aline->d.back(), tot, 0);
				}
				this->lines.push_back(aline);
			}
			return 0;
		}

		void print_plan(PA re) {
			this->lastAns = re;
			this->log.clear();
			int cnt = (int)this->ansq.size();
			int pre = -1;
			for (int i = 1; i <= cnt; ++i) {
				int t = this->ansq[cnt - i];
				std::string &nm = this->Stations[this->Trans[t]->id]->nm;
				std::string tmp(nm.c_str());
				//printf_s("%s", nm.c_str());
				if (pre >= 0) {
					int lno = this->Trans[t]->l;
					if (lno != this->Trans[pre]->l) {
						//printf_s("%s%s", transfer, this->lines[lno]->nm.c_str());
						tmp = std::string(transfer) + std::string(this->lines[lno]->nm.c_str());
					}
				}
				pre = t;
				//printf_s("\n");
				this->log.push_back(tmp);
			}
		}

		PA bfs(int s, int t, planMode mode = planMode::pm_Short) {
			int *dis[2];
			dis[0] = (int*)malloc(sizeof(int)*(this->Trans.size() + 1));
			memset(dis[0], 0x3e, sizeof(int)*(this->Trans.size() + 1));
			dis[1] = (int*)malloc(sizeof(int)*(this->Trans.size() + 1));
			memset(dis[1], 0x3e, sizeof(int)*(this->Trans.size() + 1));
			int * fa = (int*)malloc(sizeof(int)*(this->Trans.size() + 1));
			memset(fa, -1, sizeof(int)*(this->Trans.size() + 1));
			bool *iq = (bool*)malloc(sizeof(bool)*(this->Trans.size() + 1));
			memset(iq, false, sizeof(bool)*(this->Trans.size() + 1));
			std::queue<int> *q = new std::queue<int>();
			while (!q->empty()) q->pop();
			int cnt = (int)this->Stations[s]->trs.size();
			std::vector<int> &u = this->Stations[s]->trs;
			for (int i = 0; i < cnt; ++i) {
				q->push(u[i]);
				dis[0][u[i]] = 0;
				dis[1][u[i]] = 0;
				iq[u[i]] = true;
				fa[u[i]] = -1;
			}

			while (!q->empty()) {
				int x = q->front();
				q->pop();
				iq[x] = false;
				Tr *uu = this->Trans[x];
				for (int md = 0; md < 2; ++md) {
					for (int p = uu->g[md]; p; p = e[p].nxt) {
						int y = e[p].a;
						int flag = 0;
						int o[2];
						o[0] = dis[0][x] + (md == 0);
						o[1] = dis[1][x] + (md == 1);
						if (mode == planMode::pm_Short) {
							if (dis[0][y] > o[0] || o[0] == dis[0][y] && o[1] < dis[1][y]) flag = 1;
						}
						else if (mode == planMode::pm_convi) {
							if (dis[1][y] > o[1] || o[0] < dis[0][y] && o[1] == dis[1][y]) flag = 1;
						}
						if (flag) {
							dis[0][y] = o[0];
							dis[1][y] = o[1];
							fa[y] = x;
							if (!iq[y]) {
								q->push(y);
								iq[y] = true;
							}
						}
					}
				}
			}
			int ss = inf, tt = inf, mi = 0;
			cnt = (int)this->Stations[t]->trs.size();
			std::vector<int> &u2 = this->Stations[t]->trs;
			for (int i = 0; i < cnt; ++i) {
				int flag = 0;
				int y = u2[i];
				if (mode == planMode::pm_Short) {
					if (dis[0][y] < ss || ss == dis[0][y] && tt > dis[1][y]) flag = 1;
				}
				else if (mode == planMode::pm_convi) {
					if (dis[1][y] < tt || ss > dis[0][y] && tt == dis[1][y]) flag = 1;
				}
				if (flag) {
					ss = dis[0][y];
					tt = dis[1][y];
					mi = y;
				}
			}
			this->ansq.clear();
			this->ansq.push_back(mi);
			while (fa[mi] >= 0) {
				mi = fa[mi];
				this->ansq.push_back(mi);
			}
			return PA(ss, tt);
		}

	protected:
		~subway() {
			delete &Stations;
			delete &mp;
			delete &Trans;
			delete &lines;
			//delete[] e;
		}

	public:
		subway(std::string DataPath) {
			this->dataPath = DataPath;
			this->mp.clear();
			this->Stations.clear();
			this->Trans.clear();
			this->lines.clear();
			this->ansq.clear();
			this->log.clear();
			this->tot = 0;
			this->idn = 0;
			FILE *f;
			try
			{
				fopen_s(&f, this->dataPath.c_str(), "r");
				this->initialize(f);
			}
			catch (const Exc* E)
			{
				fprintf_s(stderr, "%s\n", E->info.c_str());
				if (f != NULL) {
					fclose(f);
				}
				exit(1);
			}
			fclose(f);
			/*if (this->initialize()) {
			exit(1);
			}*/
		}

		int do_b(std::string s, std::string t) {
			if (this->mp.find(s) == this->mp.end() || this->mp.find(t) == this->mp.end()) return 1;
			int src = this->mp[s];
			int tar = this->mp[t];
			PA &tmp = this->bfs(src, tar, planMode::pm_Short);
			this->print_plan(tmp);
			return 0;
		}

		int do_c(std::string s, std::string t) {
			if (this->mp.find(s) == this->mp.end() || this->mp.find(t) == this->mp.end()) return 1;
			int src = this->mp[s];
			int tar = this->mp[t];
			PA &tmp = this->bfs(src, tar, planMode::pm_convi);
			this->print_plan(tmp);
			return 0;
		}

		std::string getStep(int id) {
			if (id < 0 || id >= this->log.size()) return std::string("");
			return this->log[id];
		}

		int getCount() {
			return (int)this->log.size();
		}

		PA getPlanNums() {
			return this->lastAns;
		}

	};
}
