/*
Word Ladder II Total Accepted: 11578 Total Submissions: 101373 My Submissions
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

*/ 
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
public:
    bool isLadder(string a, string b) {
        int co = 0;
        int i;
        for (i=0; i<a.size(); ++i) {
            if (a[i] != b[i]) {
                co++;
            }
        }
        if (co>1) {
            return false;
        }
        return true;
    }
    
    struct Data {
    	string str;
    	stack<string> strSeq;
    	Data(string a):str(a) {
    		strSeq.push(a);
    	}
    };
    vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
        vector<vector<string> > res;
        vector<string> per;
        if (isLadder(start, end)) {
            per.push_back(start);
            per.push_back(end);
            res.push_back(per);
            return res;
        }
        Data dEnd(end);
        queue<Data> pre, back;
        back.push(dEnd);
        int i,j;
        
        while (!back.empty()) {
        	while (!pre.empty()) {
        		pre.pop();
        	}
        	bool flag = false;
        	while (!back.empty()) {
        		Data top = back.front();
        		back.pop();
        		for (i=0; i<top.str.size(); ++i) {
        			for (j=0; j<26; ++j) {
        				string tmp = top.str;
        				tmp[i] = 'a' + j;
        				if ((tmp!=top.str) && (dict.find(tmp)!=dict.end())) {
        					Data dTmp(tmp);
        					dTmp.strSeq = top.strSeq;
        					dTmp.strSeq.push(tmp);
        					pre.push(dTmp);
        					if (isLadder(tmp, start)) {
        						flag = true;
        					}
        				}
        			}
        		}
        	}
        	back = pre;
        	if (flag) {
        		break;
        	}
        }
        while (!back.empty()) {
        	Data top = back.front();
        	back.pop();
    		vector<string> vStr;
    		set<string> sStr;
    		vStr.push_back(start);
    		while (!top.strSeq.empty()) {
    			string cmp = top.strSeq.top();
    			top.strSeq.pop();
    			vStr.push_back(cmp);
    			if (sStr.find(cmp) != sStr.end()) {
    				break;
    			}
    			sStr.insert(cmp);
    		}
    		if (sStr.size() == vStr.size()-1) {
    			res.push_back(vStr);
        	}
        }
        /*for (i=0; i<res.size(); ++i) {
        	for (j=0; j<res[i].size(); ++j) {
        		cout << res[i][j] << " ";
        	}
        	cout << endl;
        }*/
        return res;
    }
};
int main(int argc, char** argv) {
	set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");
	Solution tmp;
	tmp.findLadders("red","tax",dict);
	system("pause");
	return 0;
}
