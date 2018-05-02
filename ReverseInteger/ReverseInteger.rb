# @param {Integer} x
# @return {Integer}
def reverse(x)
    int_max = (2**(31) -1)
    int_min = -(2**(31))
    reversed = x >= 0 ? String(x).reverse.to_i : -String(x).reverse.to_i
    return reversed if reversed >= int_min && reversed <= int_max
    0
    
end
