#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Metro/subway.h"
#include <iostream>
#include <ctime>
#define FOR(i, l, r) for (int i = int(l), __border_right##i = int(r); i < __border_right##i; i++)
#define MAXN 1013
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(MyTest)
	{
	private:
		string line[MAXN];
		map<string, int> l2i;
		map<string, int> st2i;
		string name[MAXN];
		bool mark[MAXN];
		char buf[MAXN];
		int ty[MAXN];
		int prel = -1;
		bool del(char *buf)
		{
			char tmp[100] = "»»³Ë";
			int m = strlen(tmp);
			int n = strlen(buf);
			FOR(i, 0, n - m) {
				char c = buf[i + m];
				buf[i + m] = 0;
				if (strcmp(tmp, buf + i)) {
					buf[i + m] = c;
					continue;
				}
				buf[i + m] = c;
				string l(buf + i + m);
				if (l2i.find(l) == l2i.end()) {
					return false;
					/*cout << buf << endl;
					while (1);*/
				}
				prel = l2i[l];
				buf[i] = 0;
				return true;
			}
			return false;
		}
		bool fd(const string&s, const string& t, int l)
		{
			if (l != -1) {
				FOR(i, 0, st[l].size() - 1) {
					if ((s == st[l][i] && t == st[l][i + 1]) || (ty[l] != 2 && s == st[l][i + 1] && t == st[l][i])) {
						return true;
					}
				}
			}
			else {
				FOR(l, 0, ls) {
					FOR(i, 0, st[l].size() - 1) {
						if ((s == st[l][i] && t == st[l][i + 1]) || (ty[l] != 2 && s == st[l][i + 1] && t == st[l][i])) {
							return true;
						}
					}
				}
			}
			return false;
		}
	public:
		vector<string> st[MAXN];
		int ln[MAXN];
		int ls = 0;
		MyTest(string path)
		{
			FILE* fin;
			fopen_s(&fin, path.c_str(), "r");
			while (fscanf(fin, " %s %d", buf, ln + ls) == 2) {
				if (ln[ls] < 0) {
					ty[ls] = 1;
					ln[ls] = -ln[ls];
				}
				if (buf[0] == '*') {
					ty[ls] = 2;
					line[ls] = string(buf + 1);
				}
				else {
					line[ls] = string(buf);
				}
				l2i[line[ls]] = ls;
				for (int i = 0; i < ln[ls]; i++) {
					fscanf(fin, "%s", buf);
					string tmp(buf);
					st[ls].push_back(tmp);
					if (st2i.find(tmp) == st2i.end()) {
						st2i[tmp] = st2i.size();
						name[st2i.size()] = tmp;
					}
				}
				if (ty[ls] == 1) {
					fscanf(fin, "%s", buf);
					st[ls].push_back(string(buf));
				}
				ls++;
			}
		}
		bool chkroute(vector<string>& log, const string&s, const string& t, int &n, int &tr, bool cyc = false)
		{
			strcpy(buf, log[0].c_str());
			prel = -1;
			del(buf);
			string pre(buf);
			if (pre != s) {
				return false;
			}
			n = 0;
			tr = 0;
			FOR(i, 1, log.size()) {
				strcpy(buf, log[i].c_str());
				int tmp = prel;
				if (del(buf)) {
					tr++;
					continue;
				}
				n++;
				string nex(buf);
				if (!fd(pre, nex, tmp)) {
					//cout << pre << " !!!! " << nex << endl;
					return false;
				}
				pre = nex;
			}
			if (pre != (cyc ? s : t)) {
				return false;
			}
			FOR(i, 1, st2i.size() + 1) {
				if (!mark[i]) {
					//cout << "!!!!!!!" << i << " " << name[i] << endl;
					return false;
				}
			}
			return true;
		}
	};


	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestInitial)
		{
			system("dir > yictmp");
			subway::subway* a = new subway::subway(string("../../Metro/beijing-subway.txt"));
			//Assert::AreEqual(a->initialize(), false);
			free(a);
		}

		TEST_METHOD(TestEmpty)
		{
			try {
				subway::subway* a = new subway::subway(string("test"));
				free(a);
			}
			catch (const subway::Exc* e) {
				return;
			}
			Assert::AreEqual(true, false);
		}

		TEST_METHOD(TestBadFile)
		{
			subway::subway* a = NULL;
			try {
				a = new subway::subway(string("../../UnitTest1/TestFile/-1"));
				if (a != NULL) free(a);
				Assert::Fail();
			}
			catch (const subway::Exc* e) {}
			try {
				a = new subway::subway(string("../../UnitTest1/TestFile/0"));
				if (a != NULL) free(a);
				Assert::Fail();
			}
			catch (const subway::Exc* e) {}
			try {
				a = new subway::subway(string("../../UnitTest1/TestFile/1"));
				if (a != NULL) free(a);
				Assert::Fail();
			}
			catch (const subway::Exc* e) {}
			try {
				a = new subway::subway(string("../../UnitTest1/TestFile/2"));
				if (a != NULL) free(a);
				Assert::Fail();
			}
			catch (const subway::Exc* e) {}
			try {
				a = new subway::subway(string("../../UnitTest1/TestFile/3"));
				if (a != NULL) free(a);
				Assert::Fail();
			}
			catch (const subway::Exc* e) {}
			try {
				a = new subway::subway(string("../../UnitTest1/TestFile/4"));
				if (a != NULL) free(a);
				Assert::Fail();
			}
			catch (const subway::Exc* e) {}
		}

		void testBC(string path1, string path2, string path3)
		{
			subway::subway* sub = new subway::subway(path1);
			MyTest *mt = new MyTest(path2);
			char buf[MAXN];
			FILE *cases;
			fopen_s(&cases, path3.c_str(), "r");
			int casen;
			fscanf(cases, "%d", &casen);
			for (int i = 0; i < casen; i++) {
				fscanf(cases, "%s", buf);
				string s(buf);
				fscanf(cases, "%s", buf);
				string t(buf);
				int n1, t2, n2;
				fscanf(cases, "%d%d%d", &n1, &t2, &n2);
				int n, tr;
				sub->do_b(s, t);
				Assert::AreEqual(mt->chkroute(sub->getLog(), s, t, n, tr), true);
				Assert::AreEqual(n, sub->getPlanNums().first);
				Assert::AreEqual(tr, sub->getPlanNums().second);
				Assert::AreEqual(n, n1);
				sub->do_c(s, t);
				Assert::AreEqual(mt->chkroute(sub->getLog(), s, t, n, tr), true);
				Assert::AreEqual(n, sub->getPlanNums().first);
				Assert::AreEqual(tr, sub->getPlanNums().second);
				Assert::AreEqual(n, n2);
				Assert::AreEqual(tr, t2);
			}
		}
		void testA(string path1, string path2)
		{
			subway::subway* sub = new subway::subway(path1);
			MyTest *mt = new MyTest(path2);
			bool mark[MAXN];
			memset(mark, 0, sizeof(mark));
			char buf[MAXN];
			srand(time(0));
			for (int i = 0; i < 10; i++) {
				int l = rand() % mt->ls;
				string s = mt->st[l][rand() % mt->ln[l]];
				sub->do_a(s);
				int n, tr;
				Assert::AreEqual(mt->chkroute(sub->getLog(), s, s, n, tr, true), true);
				Assert::AreEqual(n, sub->getPlanNums().first);
				Assert::AreEqual(tr, sub->getPlanNums().second);
			}
		}
		TEST_METHOD(TestFunctionBC0) {
			testBC(string("../../Metro/beijing-subway.txt"), string("../../UnitTest1/TestFile/beijing-subway-for-test.txt"), string("../../UnitTest1/TestFile/beijing-subway-cases.txt"));
		}

		TEST_METHOD(TestFunctionBC1) {
			testBC(string("../../UnitTest1/TestFile/map2.txt"), string("../../UnitTest1/TestFile/map2-for-test.txt"), string("../../UnitTest1/TestFile/map2-cases.txt"));
		}

		TEST_METHOD(TestFunctionA0)
		{
			testA(string("../../Metro/beijing-subway.txt"), string("../../UnitTest1/TestFile/beijing-subway-for-test.txt"));
		}

		TEST_METHOD(TestFunctionA1)
		{
			testA(string("../../UnitTest1/TestFile/map2.txt"), string("../../UnitTest1/TestFile/map2-for-test.txt"));
		}

	};
}