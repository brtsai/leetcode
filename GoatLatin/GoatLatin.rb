# @param {String} s
# @return {String}
def to_goat_latin(s)
    s.split(" ").map.with_index { |word, index| single_to_goat_latin(word, index + 1) }.join(" ")
end

class String
    def startsWithVowel?
        return false if self.length < 1
        return true if ['a','e','i','o','u'].include?(self.chars.first.downcase)
        false
    end
end

def single_to_goat_latin(s, index)
    if s.startsWithVowel?
        toReturn = s + 'ma'
        index.times { toReturn += 'a' }
        return toReturn
    else
        toReturn = s[1..-1] + s[0] + 'ma'
        index.times { toReturn += 'a' }
        return toReturn
    end
end
