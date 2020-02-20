// 44.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool isMatch(string s, string p)
{
	// ? 可以匹配单个字符
	// * 可以匹配任何长度字符串
	// s 为内容
	// p 为规则

	/*
	1.找出非特殊符号，如果 s中有非特殊，那么p中一定也存在，不存在则返回false
	2.找到 p 串中 第一个非 * 非 ？ 的 字母，然后计算该字符前面?的个数n_l,和字符后面的?个数n_l，从 p.begin+n_l
	  到 p.end()-n_r开始search 可能位置，并且尝试。如果没有合法位置直接返回false
	3.开始匹配
	*/
	if (p.empty() && s.empty()) return 1;
	if (p.empty()) return 0;
	if (s.empty()) return (p.find_first_not_of('*') == string::npos);


	if (p.find_first_not_of('?') == string::npos && p.size() == s.size()) return 1;
	if (p.find_first_not_of('?') == string::npos && p.size() != s.size()) return 0;

	int qm = 0;

	int pos = p.find_first_not_of("?*");
	if (pos == string::npos)
	{
		if (p.find_first_not_of('*') == string::npos) return 1;
		for (auto a : p)
			if (a == '?') qm++;
		if (s.size() < qm) return 0;
	}


	int flag = 0; // 如果为1说明有一个*
	int l_qm = 0; // * 之前的 ?
	int r_qm = 0; // * 之后的 ?
	int s_rank = 0; // 从0开始比对

	vector<int> v_qm;   // 先push l_qm 后 r_qm
	vector<int> v_flag;
	vector<int> v_rank;
	vector<int> v_i;

	int i = 0;



	for ( ; i <= p.size(); i++)
	{
		// "ab*cd?i*de"
		// "a befcd giesc dfimde"
		if (i < p.size())
		{
			if (s_rank >= s.size())
			{
				// s_rank 最终等于 size()
				// 大于则非法
				pos = p.find_first_not_of('*',i);
				if (pos == string::npos);
				else s_rank = -10;

				if (p[i] == '*')flag = 1;

				i = p.size()-1;
				
				continue;
			}
			if (p[i] == '?')
			{
				if (!flag)
				{
					l_qm++;
					s_rank++;
				}
				else r_qm++;
				continue;
			}
			else if (p[i] == '*')
			{
				flag = 1;
				continue;
			}
			else if (flag)
			{
				// 是字母 且有 *

				int pos = s.find_first_of(p[i], s_rank);
				qm = r_qm ? r_qm : l_qm;

				// ?*?
				//  s
				// 移动距离大于 问号数量，所以不合法
				if (pos == string::npos || (qm && (pos - s_rank) != qm))
				{
					i = p.size();
					s_rank = -10;
				}
				else
				{
					// 下一个位置
					qm = r_qm ? r_qm : l_qm;
					int temp_pos = s.find_first_of(p[i], pos + 1);
					if (temp_pos != string::npos && (!qm || (temp_pos - s_rank) == qm))
					{
						//a befcd giesc dfimd e
						v_qm.push_back(l_qm);
						v_qm.push_back(r_qm);
						v_flag.push_back(flag);
						v_rank.push_back(temp_pos);
						v_i.push_back(i - 1);
					}
				}

				s_rank = pos + 1;
				flag = 0;
				l_qm = 0;
				r_qm = 0;
			}
			else
			{
				if (p[i] != s[s_rank])
				{
					i = p.size();
					s_rank = -10;
				}
				else
				{
					// 字母，而且 不存在flag
					s_rank++;
					flag = 0;
					l_qm = 0;
					r_qm = 0;
				}
			}
		}
		
		if (i == p.size())
		{
			// 尝试下一个位置
			if (v_qm.empty()) break;

			r_qm = v_qm.back();
			v_qm.pop_back();
			l_qm = v_qm.back();
			v_qm.pop_back();

			i = v_i.back();
			flag = v_flag.back();
			s_rank = v_rank.back();

			v_i.pop_back();
			v_flag.pop_back();
			v_rank.pop_back();

			continue;
		}
	}

	if (s_rank < 0) return 0;

	// 合法情况
	if (flag)
	{
		// 结尾存在*未处理
		// s_rank <== s.size()-r_qm;
		if (s_rank <= (s.size() - r_qm)&&i==p.size()) return 1;
	}
	else
	{
		// 结尾未存在* 那么rank + l_qm == s.size()
		if (s_rank + l_qm == s.size()&& i == p.size()) return 1;
	}
	return 0;

}

int main()
{
	string s("a");
	string p("?*");

	cout << isMatch(s, p);
	system("pause");
}


