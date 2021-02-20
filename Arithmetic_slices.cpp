/*A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7
 
A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of the array A is called arithmetic if the sequence:
A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.

 
Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself

Soln: Maintain a curr_diff , stores diff between curr and next element
	  Maintain a prev_diff stores diff between prev_ele and curr_ele in array
	  if(prev_diff == curr_diff)
	  	cnt = cnt + 1
	  else
	  	calculate total consecutive seqs of length >= 3 possile till this point
	  	as total_cnt += n - (n-1) + n - (n-2) + n - (n-3)
	  	return total_cnt
*/


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int prev_diff = INT_MIN;
        int curr_diff = INT_MIN;
        int t_c = 0 , cnt = 0;
        int l = a.size();
        for(int i = 0; i < l ; i++)
        {
            if(i != l - 1)
            {
                curr_diff = a[i+1] - a[i];
                if(prev_diff == INT_MIN)
                {
                    prev_diff = curr_diff;
                    cnt++;
                }
                else if(prev_diff == curr_diff)
                    cnt++;
                //cout<<" prev_diff "<<prev_diff<<" curr_diff "<<curr_diff<<endl;
            }
            
            if(prev_diff != curr_diff or i == l-1)
            {
                if(cnt >= 2)
                {
                    int sum = ((cnt)*(cnt + 1) / 2) - 1;
                    t_c += ((cnt + 1) * (cnt - 1)) - sum;   
                }
                cnt = 1;
                prev_diff = curr_diff;
            }
            //cout<<" total_cnt "<<t_c<<" "<<cnt<<" for "<<a[i]<<endl;
        }
        return t_c;
    }
};