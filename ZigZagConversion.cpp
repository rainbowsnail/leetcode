class Solution {
public:
    string convert(string s, int numRows) {      
        if(numRows==1)
            return s;
        string str="";
        int lengthOfGroup=2*numRows-2;
        for(int row=0;row<numRows;row++){
            if(row==0||row==numRows-1){
                for(int currentRow=row;currentRow<s.length();currentRow+=lengthOfGroup){
                    str+=s[currentRow];
                }
            }
            else{
                int currentRow=row;
                bool flag=true;
                int childLenOfGroup1=2*(numRows-1-row);
                int childLenOfGroup2=lengthOfGroup-childLenOfGroup1;
                while(currentRow<s.length()){
                    str+=s[currentRow];
                    if(flag)
                        currentRow+=childLenOfGroup1;
                    else
                        currentRow+=childLenOfGroup2;
                    flag=!flag;
                }
            }
        }
        return str;   
    }
    string reverse_convert(string s, int numRows) {
        //cout << "s = " << s <<endl;
        int ssize = s.size();
        //cout << ssize << endl;
        int numsInTwoCols = numRows + numRows/2;
        //cout << "numsInTwoCols = " << numsInTwoCols << endl;
        int col = ssize/numsInTwoCols * 2 + ceil(float(ssize%numsInTwoCols)/numRows);
        // + (ssize%numRows != 0)
        //int col = (ssize + numRows - 1) / numRows;
        //cout << "col = " <<col << endl;
        
        
        if(ssize == 0) return "";
        if(numRows == 1) return s;
        
        string result = "";
        vector<int> index;
        int single_line = (col + 1)/2;
        int double_line = col;
        int lastCol;
        
        if (col % 2 == 0){
            lastCol = ssize - (col / 2 - 1) * numsInTwoCols - numRows;
            //cout << "lastcol = " << lastCol << endl;
        }else if (col % 2 == 1){
            lastCol = ssize - (col / 2) * numsInTwoCols;
            lastCol = lastCol * 2 - 1;
            //cout << "lastcol = " << lastCol << endl;
        }
        
        for(int i = 0; i < lastCol; ++i){
            if(numRows % 2 == 1){
                if(i % 2 == 0){
                    index.push_back(i/2*(single_line+double_line));
                }else{
                    index.push_back(i/2*(single_line+double_line) + single_line);
                }
            }else{
                if(i % 2 == 0){
                    index.push_back(i/2*(single_line+double_line));
                }else{
                    index.push_back(i/2*(single_line+double_line) + double_line);
                }
            }
        }
        
        for(int i = lastCol; i < numRows; ++i){
            if(numRows % 2 == 1){
                if(i % 2==0){
                    index.push_back(i/2*(single_line+double_line) - ((i - lastCol) / 2) );
                }else{
                    index.push_back(i/2*(single_line+double_line) + single_line - (numRows - lastCol));
                }
            }else{
                if(i % 2==0){
                    index.push_back(i/2*(single_line+double_line) - ((i - lastCol) / 2) );
                }else{
                    if(col % 2 == 0)
                    index.push_back(i/2*(single_line+double_line) + double_line - (i - lastCol) / 2);
                    else 
                    index.push_back(i/2*(single_line+double_line) + double_line - (i - lastCol));
                }
            }
        }
        
        int curCol=0;
        while(curCol < col){
            if(curCol % 2 == 0){
                for(int i = 0; i < numRows; ++i){
                    if(ssize - 1 < index[i])break;
                    result += s[index[i]];
                    index[i] += 1;
                }
            }else{
                int i = 0;
                if (numRows % 2 == 1) i = 1;
                for(; i < numRows; i += 2){
                    if(ssize - 1 < index[i])break;
                    result += s[index[i]];
                    index[i] += 1;
                }
            }
            curCol++;
        }
        
            
        return result;
    }
};

