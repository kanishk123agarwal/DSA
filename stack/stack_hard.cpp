https://leetcode.com/problems/largest-rectangle-in-histogram/description/
Question 1: 84. Largest Rectangle in Histogram 
leetcode-84 number
class Solution {
public:

    vector<int> nextSmaller(vector<int> arr){
    vector<int> ans(arr.size());
    stack<int> st;
    // agar hum isme -1 push kr rhe hai to neeche hum array mai -1 access nhi kr skte hai isliye niche st.top() condition is mandatory
    st.push(-1);
// in this we traverse right to left direction 
    for(int i=arr.size()-1;i>=0;i--){
        int curr=arr[i];
        while(st.top()!=-1 && arr[st.top()]>=curr ){
            st.pop();
        }
        ans[i]=st.top();
        // in this we insert index not the value 
        st.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int> arr){
    stack<int> st;
    vector<int> ans(arr.size());
    st.push(-1);
// in this we have to traverse in left to right direction
    for(int i=0;i<arr.size();i++){
        int curr=arr[i];
        while(st.top()!=-1 && arr[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next=nextSmaller(heights);
        
        // in this some case are handle that it becomes the width is negative and we know that width is never negative 
        for(int i=0;i<heights.size();i++){
            if(next[i]==-1){
                next[i]=heights.size();
            }
        }
        vector<int> prev=prevSmaller(heights);

        vector<int> area(next.size());
        for(int i=0;i<next.size();i++){
            int width=next[i]-prev[i]-1;
            int length=heights[i];
            int currArea=width*length;
            area[i]=currArea;
        }
        int mini=INT_MIN;
        for(int i=0;i<area.size();i++){
            mini=max(mini,area[i]);
        }
        return mini;
    }
};

// Question 2: Infix to Postfix
int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
void infixToPostfix(string s) {
	stack<char> st;
	string result;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;
		else if (c == '(')
			st.push('(');
		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else {
			while (!st.empty()
				&& prec(s[i]) <= prec(st.top())) {
				result += st.top(); 
				st.pop();
			}
			st.push(c);
		}
	}
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}
	cout << result << endl;
}