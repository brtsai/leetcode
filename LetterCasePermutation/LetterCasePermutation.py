class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        permutations = []
        self.recPermutations("", S, permutations)
        return permutations

    def recPermutations(self, processed, remainder, permutations):
        if (remainder == ""):
            permutations.append(processed)
        elif (remainder[0].isalpha()):
            self.recPermutations(processed + remainder[0].lower(), remainder[1:], permutations)
            self.recPermutations(processed + remainder[0].upper(), remainder[1:], permutations)
        else:
            self.recPermutations(processed + remainder[0], remainder[1:], permutations)


