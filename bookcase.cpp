#define max(a,b) ((a) > (b)) ? (a) : (b)
#define min(a,b) ((a) < (b)) ? (a) : (b)
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        map<int,int> cache = map<int,int>{};
        return dp(0, books, cache, shelf_width);
    }
    
    int dp(int position, vector<vector<int>>& books, map<int,int>& cache, int shelf_width) {
        if (position >= books.size()) // base case no suffixes
            return 0;
        if (cache.find(position) != cache.end()) // if previous result memoized
            return cache[position];
        int result, maxheight, width;
        maxheight=width=0;
        result = INT_MAX;
        for (int i = position; i < (int) books.size(); i++) {
            // for each position, if it has a viable width
            if (width + books[i][0] <= shelf_width) {
                // add that to the current cumulative width
                width += books[i][0];
                // adjust the height to the tallest one
                maxheight = max(maxheight, books[i][1]);
                // and recursively find if this is the best height position for the book
                result = min(result, maxheight+dp(i+1, books, cache, shelf_width));
            } else
                break;
        }
        cache[position] = result;
        return result;
    }
};
