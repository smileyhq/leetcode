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

//solution3:  handle overflow in advance, ans is 'int', process as negative
class Solution {
public:
	//need to consider some special situation
	//1. leading blank spaces  --> just skip
	//2. positive or negative sign 
	//3. non digit character  --> return number before it
	//4. overflow
	//to deal with overflow:
	//process as negative: num = num*10 - (str[i] - '0')
	//check overflow in advance, if oveflow just return
	//why process as negative, because INT_MIN's absolute value is larger by 1 than INT_MAX
	int myAtoi(string str) {
		int i = 0;
		while(str[i] == ' ') i++;
		int flag = -1;
		if(str[i] == '+') 
			i++;
		else if(str[i] == '-') {
			flag = 1;
			i++;
		}
		int overflow = flag < 0 ? INT_MAX : INT_MIN, ret = 0;
		while('0' <= str[i] && str[i] <= '9') {
			int val = str[i] - '0';
			if(ret < INT_MIN/10) return overflow;
			ret = ret*10;
			if(ret < INT_MIN + val) return overflow;
			ret = ret - val;
			i++;
		}
		if(flag<0 && ret == INT_MIN) return overflow;
		return ret*flag; 
	}

	//test case: 
	//Input:"2147483648"
	//Output:-2147483648
	//Expected:2147483647
}
