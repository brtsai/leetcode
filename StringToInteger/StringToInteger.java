public class Solution {
    public int myAtoi(String str) {
        int toReturn = 0;
        String trimmed = str.trim();
        boolean neg = false;
        for(int i = 0; i < trimmed.length(); i++) {
            int converted = trimmed.charAt(i) - '0';
            if(converted == '-' - '0' && i == 0) {
                neg = true;
                continue;
            }
            if(converted == '+' - '0' && i == 0) {
                continue;
            }
            if(converted < 0 || converted > 9) {
                break;
            }
            if (Integer.toString(toReturn).length() == Integer.toString(Integer.MAX_VALUE).length() || toReturn * 10 + converted < toReturn) {
                return neg ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            toReturn *= 10;
            toReturn += converted;
        }
        if(neg) {
            return -toReturn;
        }
        return toReturn;
    }
}
