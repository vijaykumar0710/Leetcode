class Solution {
public:
    string convertDateToBinary(string date) {
     
        string result=""; 
        string year=date.substr(0,4);
        string month=date.substr(5,2);
        string day=date.substr(8,2);

        int y=stoi(year);
        int m=stoi(month);
        int d=stoi(day);

        bitset<16> binaryYear(y);
        bitset<8> binaryMonth(m);
        bitset<8> binaryDay(d);

       string fY=binaryYear.to_string();
         int i=0;
         while(fY[i]!='1'){
            i++; 
         }
          result+=fY.substr(i)+"-";

       string fM=binaryMonth.to_string();
       int j=0;
         while(fM[j]!='1'){
            j++;
         }
          result+=fM.substr(j)+"-";

          string fD=binaryDay.to_string();
          int k=0;
         while(fD[k]!='1'){
            k++;
         }
          result+=fD.substr(k);

        return result;
    }
};