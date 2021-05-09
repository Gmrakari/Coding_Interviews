
/*
 * Date:2021-04-28 21:22
 * filename:242.Valid Anagram 有效的字母的异位词
 * 
 */

/*
 *
242. 有效的字母异位词

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

/*
 * 方法一:
 * 判断两个字符串是否相等，如果不相等，直接返回false;
 * 对两个字符串进行排序
 * 然后判断他们是否相等，如果相等 返回true;否则返回false;
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
		if(s.length() != t.length())
			return false;

		sort(s.begin(),s.end());
		sort(t.begin(),t.end());

		if(s == t)
			return true;
    }
};

/*
 * Hash
 */

class Solution2
{
public:
	bool isAnagram(string s,string t)
	{
		if(s.length() != t.length())
			return false;
		
		vector<int> table(26,0);
		for(auto& ch:s)
		{
			table[ch - 'a']++;
		}
		for(auto& ch : t)
		{
			table[ch - 'a']--;
			if(table[ch - 'a'] < 0){
				return false;
			} 
		}
		return true;
	}
};

/*
 * unordered_map
 */

class Solution3
{
public:
	bool isAnagram(string s,string t)
	{
		unordered_map<int,int> m1,m2;
		for(char c : s)
		{
			m1[c - 'a']++;
		}
		for(char c : t)
		{
			m2[c - 'a']++;
		}
		for(int i = 0; i < 26;i++)
		{
			if(m1[i] != m2[i])
			{
				return false;
			}
		}
		return true;
	}
};
