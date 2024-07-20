/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
       int num=n/2;
       int lower=1;
       int higher=n;
       while(guess(num)!=0){
        if(guess(num)==-1){
            higher=num-1;
        }else if(guess(num)==1){
            lower=num+1;
         }
       } 
       return num;
    }
};