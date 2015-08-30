/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        int n = intervals.size();
        if(n==0) 
        {
            vector<Interval> result;
            result.push_back(newInterval);
            return result;
        }
        
        intervals.push_back(newInterval);
        
        return merge(intervals);
        
    }
    
    static bool cmp(const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) 
    {
        vector<Interval> ret;
        Interval tmp;

        if (intervals.empty())
        {
            return ret;
        }

        sort(intervals.begin(), intervals.end(), cmp);

        tmp.start = intervals[0].start;
        tmp.end = intervals[0].end;

        for (auto it = intervals.begin()+1; it != intervals.end(); it++)
        {
            if (it->start <= tmp.end)
            {
                if (it->end > tmp.end)
                {
                    tmp.end = it->end;
                }
            }
            else
            {
                ret.push_back(tmp);

                //update the tmp start/end
                tmp.start = it->start;
                tmp.end = it->end;
            }
        }

        ret.push_back(tmp);

        return ret;
    }
};
