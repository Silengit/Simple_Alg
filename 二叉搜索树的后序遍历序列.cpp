class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0)
            return false;
        else return rec_proc(sequence);
    }
    
    bool rec_proc(vector<int> sequence) {
        if(sequence.size() <= 2)
            return true;
        int right = -1;
        for(int i = 0; i < sequence.size() - 1; i++){
            if(right == -1 && sequence[i] > sequence.back())
                right = i;
            else if(right != -1 && sequence[i] < sequence.back())
                return false;
        }
        vector<int> l_seq, r_seq;
        l_seq.assign(sequence[0],sequence[right]);
        r_seq.assign(sequence[right],sequence[sequence.size()-1]);
        return rec_proc(l_seq)&&rec_proc(r_seq);
    }
};