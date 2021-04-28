
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

