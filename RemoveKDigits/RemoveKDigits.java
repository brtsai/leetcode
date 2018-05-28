class Solution {
    public String removeKdigits(String num, int k) {
        if (k < 1) return num;
        
        int digitsRemoved = 0;
        String toReturn = num;
        boolean inOrder = false;
        
        // Remove digits that break increasing order
        while (!inOrder) {
            inOrder = true;
            int numLength = toReturn.length();
            for (int i = 0; i < numLength - 1; i++) {
                if (toReturn.charAt(i) > toReturn.charAt(i+1) && digitsRemoved < k) {
                    digitsRemoved += 1;
                    toReturn = toReturn.substring(0, i) + toReturn.substring(i+1, numLength);
                    inOrder = false;
                    break;
                }
            }
        }
        System.out.println(toReturn);
        // remove highest digits if you haven't yet removed k digits
        toReturn = removeKHighestDigits(toReturn, k - digitsRemoved);
        
        // remove leading zeroes
        toReturn = removeLeadingZeroes(toReturn);
        
        if (toReturn.length() == 0) return "0";
        return toReturn;
    }
    
    String removeKHighestDigits(String num, int k) {
        int numLength = num.length();
        if (k < 1 || numLength < 1) return num;
        int greatest = num.charAt(0);
        int greatestIndex = 0;
        String toReturn;
        for (int i = 1; i < numLength; i++) {
            if (num.charAt(i) > greatest) {
                greatest = num.charAt(i);
                greatestIndex = i;
            }
        }
        toReturn = num.substring(0, greatestIndex) + num.substring(greatestIndex+1, numLength);
        
        return removeKHighestDigits(toReturn, k-1);
    }
    
    String removeLeadingZeroes(String num) {
        int numLength = num.length();
        String toReturn = "";
        boolean isTrailingZero = true;
        int i = 0;
        for (; i < numLength; i++) {
            if (num.charAt(i) != '0') break;
        }
        
        return num.substring(i, numLength);
    }
}
