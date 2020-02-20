// 68.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
	int wid = maxWidth;
	int rank = 0;
	vector<string> resault;

	while (rank<words.size())
	{

		int line_len = 0;
		vector<string> line;
		string word;

		// 直到满超过一行
		while (line_len + (line.empty() ? 0 :line.size()-1) < wid)
		{
			if (rank >= words.size())
			{
				if (!line.empty())
				{
					stringstream ss;
					int nop_num = 1;
					int lack = wid - line_len- (line.size()-1);

					/*if (line.size() < 2)
						nop_num = 0;*/
					
					for (int i = 0; i < line.size(); i++)
					{
						ss << line[i];
						if(i!=line.size()-1) ss << string(nop_num, ' ');
					}
						
				
					ss << string(lack, ' ');

					resault.push_back(ss.str());
					line_len = 0;
					break;
				}
			}

			word = words[rank];
			line.push_back(word);
			line_len += word.size();
			rank++;
		}

		if (rank >= words.size()&&line_len==0) break;

		if (line_len+ line.size()-1 == wid)
		{
			stringstream ss;
			for (int i = 0; i < line.size(); i++)
			{
				ss << line[i];
				if (i != line.size() - 1) ss << " ";
			}
			resault.push_back(ss.str());
		}
		else
		{
			rank--;
			line_len -= line[line.size() - 1].size();
			line.pop_back();

			int nop_num = 1;
			int lack = wid - line_len - (line.size()-1) ;
			if (line.size() == 1)
			{
				nop_num = 0;
			}
			else
			{
				nop_num += lack / (line.size() - 1); // 其他单词之间的空格
				lack = lack % (line.size() - 1); // 第一个单词后面 额外的空格
			}

			stringstream ss;
			for (int i = 0; i < line.size(); i++)
			{
				ss << line[i];
				if ((i != line.size() - 1))
				{
					ss << string(nop_num, ' ');
					if (lack-- > 0) ss << ' ';
				}
			}
			if (line.size() == 1) ss << string(lack, ' ');
			cout << ss.str().size() << endl;
			resault.push_back(ss.str());
		}
	}

	return resault;

}

int main()
{
	vector<string> s{ "What","must","be","acknowledgment","shall","be"
	};

	auto r = fullJustify(s,16);
	
	for (auto a : r)
	{
		cout << a.size() << " : ";
		cout << a << endl;
	}
		
	cout << endl;
	system("pause");
}
