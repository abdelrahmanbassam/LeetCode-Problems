# @param {Integer[]} nums
# @return {Integer}
def longest_subarray(nums)
    z, l, ans = 0, 0, 0 
    nums.each_with_index do |num, i|
        z += 1 if num == 0
        while z > 1
            z -= 1 if nums[l] == 0
            l += 1
        end
        ans = [ans, i - l].max
    end
    ans 
end
