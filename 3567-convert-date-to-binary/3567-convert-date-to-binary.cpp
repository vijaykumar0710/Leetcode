class Solution {
public:
void conversion(int num,string &binary){
    if(num>1){
        conversion(num/2,binary);
    }
    binary+=to_string(num%2);
}
    string convertDateToBinary(string date) {
        string year,month,day;
        conversion(stoi(date.substr(0,4)),year);
        conversion(stoi(date.substr(5,2)),month);
        conversion(stoi(date.substr(8,2)),day);

      return year+"-"+month+"-"+day;       
    }
};