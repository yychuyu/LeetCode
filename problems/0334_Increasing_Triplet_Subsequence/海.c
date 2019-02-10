class Solution
{
public :
	bool increaseTriplet(vector<int>& nums)
	{
		int m1 = INT_MAX, m2 = INT_MAX;
		for(auto a : nums)
		{
			if(m1 > a) m1 = a;
			else if(m2 >= a) m2 = a;
			else return true;
		}
		return false;
	}
}
