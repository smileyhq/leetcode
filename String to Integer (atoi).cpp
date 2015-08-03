//solution1:Handle overflow before adding new char; ans is "int",
class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        while(i<str.length() && str[i] == ' ') i++;
        int ans = 0; bool negative = false;
        if(i<str.length() && (str[i]=='-'|| str[i] == '+')){
            negative = str[i] == '-'?true:false;
            i++;
        }
        while(i<str.length()){
            if(str[i]<'0' || str[i] > '9'){
                break;
            }
            if(ans > 214748364){
                return negative?INT_MIN:INT_MAX;
            }else if(ans == 214748364 && str[i] >= '8'){
                 return negative?INT_MIN:INT_MAX;
            }
            ans = ans*10 + str[i] - '0';
            
            i++;
        }
        return negative?-ans:ans;
        
    }
};

//solution2:  Handle overflow after adding new char; ans is "long long"
class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        while(i<str.length() && str[i] == ' ') i++;
        long long ans = 0; bool negative = false;
        if(i<str.length() && (str[i]=='-'|| str[i] == '+')){
            negative = str[i] == '-'?true:false;
            i++;
        }
        while(i<str.length()){
            if(str[i]<'0' || str[i] > '9'){
                break;
            }
            ans = ans*10 + str[i] - '0';
            if(ans >= INT_MAX && !negative){
                return INT_MAX;
            }
            if(ans > INT_MAX && negative){
                return INT_MIN;
            }
            i++;
        }
        return negative?-ans:ans;
        
    }
};
